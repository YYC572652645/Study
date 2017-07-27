#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QMessageBox>
#include<QTimer>
using namespace std;
const static int posMinX=0;
const static int posMaxX=20000;
const static int posMinY=0;
const static int posMaxY=40;
static int   wheelCount=5;
static float testData=0;
static float testDataTwo=0;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setMinimumSize(880,620);     //设置最小显示宽高
    ui->setupUi(this);                 //安装界面元素
    setPalette(QPalette(Qt::darkCyan));//设置背景色
    setAutoFillBackground(true);
    this->timer=NULL;
    ui->customPlot->installEventFilter(this);

    dataX.resize(1);
    dataY.resize(1);

    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏

    int width=this->width();
    maxNormal=false;

    minButton=new QToolButton(this);     //最小化按钮
    maxButton=new QToolButton(this);     //最大化按钮
    closeButton=new QToolButton(this);   //关闭按钮
    openCom=new QToolButton(this);       //打开串口
    comClose=new QToolButton(this);      //关闭串口
    openComTwo=new QToolButton(this);       //打开串口
    comCloseTwo=new QToolButton(this);      //关闭串口
    actionSave=new QToolButton(this);    //保存按钮
    actionDelete=new QToolButton(this);  //清空按钮
    iconLabel=new QLabel(this);
    labelTitle=new QLabel(this);


    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));        //最小化按钮
    connect(maxButton,SIGNAL(clicked(bool)),SLOT(actionMax()));        //最大化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));    //关闭按钮
    connect(openCom,SIGNAL(clicked(bool)),this,SLOT(connCom()));       //连接串口
    connect(comClose,SIGNAL(clicked()),this,SLOT(closeCom()));         //读取串口数据
    connect(openComTwo,SIGNAL(clicked(bool)),this,SLOT(connComTwo())); //连接串口
    connect(comCloseTwo,SIGNAL(clicked()),this,SLOT(closeComTwo()));   //读取串口数据
    connect(actionSave,SIGNAL(clicked()),this,SLOT(saveFile()));       //保存文件
    connect(actionDelete,SIGNAL(clicked()),this,SLOT(clearMessage())); //清空信息



    /*************************************加载图标********************************/
    QPixmap closePix=style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(closePix);


    maxPix=style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
    maxButton->setIcon(maxPix);


    QPixmap minPix =style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPix);

    normalPix =style()->standardPixmap(QStyle::SP_TitleBarNormalButton);




    /*************************************加载位置********************************/

    iconLabel->setGeometry(10,7,22,22);
    labelTitle->setGeometry(34,4,120,30);
    minButton->setGeometry(width-90,0,30,30);
    maxButton->setGeometry(width-60,0,30,30);
    closeButton->setGeometry(width-30,0,30,30);
    openCom->setGeometry(100,30,100,30);          //打开串口
    comClose->setGeometry(220,30,100,30);         //关闭串口
    openComTwo->setGeometry(340,30,100,30);       //打开串口
    comCloseTwo->setGeometry(460,30,100,30);      //关闭串口
    actionSave->setGeometry(580,30,100,30);       //保存按钮
    actionDelete->setGeometry(700,30,100,30);     //清空按钮


    /*************************************提示信息********************************/
    openCom->setToolTip(tr("打开串口"));
    comClose->setToolTip(tr("关闭串口"));
    openComTwo->setToolTip(tr("打开串口"));
    comCloseTwo->setToolTip(tr("关闭串口"));
    actionSave->setToolTip(tr("保存信息"));
    actionDelete->setToolTip(tr("清空信息"));
    openCom->setText(tr("打开串口一"));
    comClose->setText(tr("关闭串口一"));
    openComTwo->setText(tr("打开串口二"));
    comCloseTwo->setText(tr("关闭串口二"));
    actionSave->setText(tr("保存信息"));
    actionDelete->setText(tr("清空信息"));
    labelTitle->setText(tr("高度计"));


    /*************************************添加背景颜色******************************/

    minButton->setStyleSheet("background-color:transparent");
    maxButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");
    openCom->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    openComTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    comCloseTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    iconLabel->setStyleSheet("QLabel{border-image:url(:/images/tc.ico)}");


    ok=false;                 //初始值为false
    okTwo=false;              //初始值为false
    fileOk=false;             //初始值为false
    fileOkTwo=false;          //初始值为false
    fileOkThree=false;        //初始值为false
    Q=0.025;                  //卡尔曼滤波初始化
    R=0.9;                    //卡尔曼滤波初始化
    pknow=10;                 //卡尔曼滤波初始化
    hknow=0;                  //卡尔曼滤波初始化
    remeberData=0;            //记忆数据
    temphkNow=0;              //记忆数据、
    s1=0;                     //实际距离
    s2=0;                     //实际距离
    s3=0;                     //预估距离
    predictLeft=0;            //左预估值
    predictRight=0;           //右预估值
    nCount=0;                 //计数器
    vrel = 0;                 //速度


    QTwo=0.025;               //卡尔曼滤波初始化
    RTwo=0.9;                 //卡尔曼滤波初始化
    pknowTwo=10;              //卡尔曼滤波初始化
    hknowTwo=0;               //卡尔曼滤波初始化
    remeberDataTwo=0;         //记忆数据
    temphkNowTwo=0;           //记忆数据、
    s1Two=0;                  //实际距离
    s2Two=0;                  //实际距离
    s3Two=0;                  //预估距离
    predictLeftTwo=0;         //左预估值
    predictRightTwo=0;        //右预估值
    nCountTwo=0;              //计数器
    vrelTwo = 0;              //速度


    ui->comboBoxPort->setCurrentIndex(1);                                    //默认为COM2接口
    comClose->setEnabled(false);
    comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    comCloseTwo->setEnabled(false);
    comCloseTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    QFont font("ZYSong",12);
    ui->textEditRead->setFont(font);
    QFont font1("ZYSong",11);
    labelTitle->setFont(font1);

    //自动加载串口信息
    int portCount=0;
    foreach(const QSerialPortInfo&info,QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPort->addItem(info.portName());
        portCount++;
    }
    if(portCount==0)
    {
        for(int i=0;i<20;i++)
        {
            ui->comboBoxPort->addItem(tr("COM%1").arg(i));
        }
    }

    portCount=0;
    foreach(const QSerialPortInfo&info,QSerialPortInfo::availablePorts())
    {
        ui->comboBoxPortTwo->addItem(info.portName());
        portCount++;
    }
    if(portCount==0)
    {
        for(int i=0;i<20;i++)
        {
            ui->comboBoxPortTwo->addItem(tr("COM%1").arg(i));
        }
    }


    //设置坐标轴显示范围
    ui->customPlot->xAxis->setRange(-5.5,5.5);
    ui->customPlot->yAxis->setRange(0,5.1);
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);//设置线风格
    ui->customPlot->graph(0)->setPen(QColor(255,10,0));      //设置画笔颜色
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc,20));
    ui->customPlot->graph(0)->addData(0.9,0);  //雷达位置
    ui->customPlot->graph(0)->addData(-0.9,0); //雷达位置
}

MainWindow::~MainWindow()
{
    delete ui;
}


/****************定义槽函数连接串口**************/
void MainWindow::connCom()
{
    QString portName=ui->comboBoxPort->currentText();

    myCom=new Win_QextSerialPort(portName,QextSerialBase::EventDriven);//定义串口对象，并传递参数对其进行初始化

    if(myCom->isOpen())                       //如果串口已经打开，返回
    {
        return;
    }
    else
    {
        ok=myCom->open(QIODevice::ReadOnly);  //以可读可写方式打开串口

        /*************************设置比特率*************************/
        if(ui->comboBoxBaudRate->currentText()==tr("9600"))
        {
            myCom->setBaudRate(BAUD9600);

        }
        else if(ui->comboBoxBaudRate->currentText()==tr("115200"))
        {
            myCom->setBaudRate(BAUD115200);
        }

        /*************************设置数据位*************************/
        if(ui->comboBoxData->currentText()==tr("8"))
        {
            myCom->setDataBits(DATA_8);
        }
        else if(ui->comboBoxData->currentText()==tr("7"))
        {
            myCom->setDataBits(DATA_7);
        }


        /*************************设置奇偶校验位*************************/
        if(ui->comboBoxCheck->currentText()==tr("无"))
        {
            myCom->setParity(PAR_NONE);
        }
        else if(ui->comboBoxCheck->currentText()==tr("奇"))
        {
            myCom->setParity(PAR_ODD);
        }
        else if(ui->comboBoxCheck->currentText()==tr("偶"))
        {
            myCom->setParity(PAR_EVEN);
        }

        /*************************设置停止位*************************/
        if(ui->comboBoxStop->currentText()==tr("1"))
        {
            myCom->setStopBits(STOP_1);
        }
        else if(ui->comboBoxStop->currentText()==tr("2"))
        {
            myCom->setStopBits(STOP_2);
        }
        if(this->timer==NULL)
        {
            this->timer=new QTimer(this);                                    //定义一个定时器
            connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
            timer->start(30);                                                //0.05秒调用一次
        }
        else if(!this->timer->isActive())        //判断定时器是否开着
        {
            timer->start(30);
        }

    }
    if(!ok)
    {
        QMessageBox::warning(this,"系统提示","打开失败");
        return;
    }
    else
    {
        //将控件设置为不可用
        ui->comboBoxPort->setEnabled(false);
        ui->comboBoxBaudRate->setEnabled(false);
        ui->comboBoxCheck->setEnabled(false);
        ui->comboBoxData->setEnabled(false);
        ui->comboBoxStop->setEnabled(false);
        actionSave->setEnabled(false);
        actionDelete->setEnabled(false);
        openCom->setEnabled(false);
        comClose->setEnabled(true);
        actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        openCom->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    }

}


/****************定义槽函数连接串口**************/
void MainWindow::connComTwo()
{
    QString portName=ui->comboBoxPortTwo->currentText();

    myComTwo=new Win_QextSerialPort(portName,QextSerialBase::EventDriven);//定义串口对象，并传递参数对其进行初始化

    if(myComTwo->isOpen())                       //如果串口已经打开，返回
    {
        return;
    }
    else
    {
        okTwo=myComTwo->open(QIODevice::ReadOnly);  //以可读可写方式打开串口


        /*************************设置比特率*************************/
        if(ui->comboBoxBaudRate->currentText()==tr("9600"))
        {
            myComTwo->setBaudRate(BAUD9600);

        }
        else if(ui->comboBoxBaudRate->currentText()==tr("115200"))
        {
            myComTwo->setBaudRate(BAUD115200);
        }

        /*************************设置数据位*************************/
        if(ui->comboBoxData->currentText()==tr("8"))
        {
            myComTwo->setDataBits(DATA_8);
        }
        else if(ui->comboBoxData->currentText()==tr("7"))
        {
            myComTwo->setDataBits(DATA_7);
        }


        /*************************设置奇偶校验位*************************/
        if(ui->comboBoxCheck->currentText()==tr("无"))
        {
            myComTwo->setParity(PAR_NONE);
        }
        else if(ui->comboBoxCheck->currentText()==tr("奇"))
        {
            myComTwo->setParity(PAR_ODD);
        }
        else if(ui->comboBoxCheck->currentText()==tr("偶"))
        {
            myComTwo->setParity(PAR_EVEN);
        }

        /*************************设置停止位*************************/
        if(ui->comboBoxStop->currentText()==tr("1"))
        {
            myComTwo->setStopBits(STOP_1);
        }
        else if(ui->comboBoxStop->currentText()==tr("2"))
        {
            myComTwo->setStopBits(STOP_2);
        }

        if(this->timer==NULL)
        {
            this->timer=new QTimer(this);                                    //定义一个定时器
            connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
            timer->start(30);                                                //0.05秒调用一次
        }
        else if(!this->timer->isActive())        //判断定时器是否开着
        {
            timer->start(30);
        }

    }
    if(!okTwo)
    {
        QMessageBox::warning(this,"系统提示","打开失败");
        return;
    }
    else
    {
        //将控件设置为不可用
        ui->comboBoxPortTwo->setEnabled(false);
        ui->comboBoxBaudRate->setEnabled(false);
        ui->comboBoxCheck->setEnabled(false);
        ui->comboBoxData->setEnabled(false);
        ui->comboBoxStop->setEnabled(false);
        actionSave->setEnabled(false);
        actionDelete->setEnabled(false);
        openComTwo->setEnabled(false);
        comCloseTwo->setEnabled(true);
        actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        openComTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
        comCloseTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    }

}


/****************定义槽函数读取串口数据***********/
void MainWindow::readCom()
{
    QByteArray temp,tempTwo;
    if(ok)
    {
        if(myCom->bytesAvailable()>0)
        {
            temp=myCom->readAll(); //读取串口数据
        }
    }
    if(okTwo)
    {
        if(myComTwo->bytesAvailable()>0)
        {
            tempTwo=myComTwo->readAll(); //读取串口数据
        }
    }

    /***************************串口一读取数据*************************/
    for(int i=0;i<temp.size();)
    {
        if(temp[i]==0XAA&&temp[i+1]==0XAA&&temp[i+12]==0X55&&temp[i+13]==0X55)   //判断出障碍高度的信息
        {

            /*************************************距离处理***********************************/
            if(temp[i+2]==0X0C&&temp[i+3]==0X07)
            {
                temphkNow=hknow;   //记忆数据
                hk=hknow;          //卡尔曼滤波上次数据
                remeberData=(((BYTE)temp[i+6])*16*16+(BYTE)temp[i+7])*0.01;  //将信息提取出来
                testData=remeberData;
                listFloat<<remeberData;
                if(listFloat.size()==1)
                {
                    hk=remeberData;
                }
                else if(listFloat.size()==2||listFloat.size()==3)
                {
                    /*******************卡尔曼滤波算法***********************/
                    pk=pknow+Q;
                    kg=pk/(pk+R);
                    hknow=hk+kg*(remeberData-hk);
                    pknow=(1-kg)*pk;

                }
                else if(listFloat.size()>3)
                {

                    if((listFloat[3]>35)||(listFloat[3]<0.5))
                    {
                        remeberData=listFloat[0];
                    }
                    else
                    {
                        s1=listFloat[1]-listFloat[0];     //实际距离
                        s2=listFloat[2]-listFloat[1];     //实际距离
                        s3=1.5*s2-0.5*s1;                 //预测距离
                        predictLeft=listFloat[2]+s3-0.5;  //左预测值
                        predictRight=listFloat[2]+s3+0.5; //右预测值

                        vrel = (listFloat[3]-listFloat[2])/0.05;  //速度

                        //判断取到值是否在可控区间内
                        if(((listFloat[3]>predictLeft) && (listFloat[3]<predictRight) && (vrel>-4) && (vrel<5) )||(nCount==7))
                        {
                            //remeberData=listFloat[3];
                            nCount=0;
                        }
                        else
                        {
                            remeberData=listFloat[2];
                            nCount++;
                        }

                        //将数组往前移动一位
                        for(int j=0;j<3;j++)
                        {
                            listFloat[j]=listFloat[j+1];
                        }

                    }


                    /*******************卡尔曼滤波算法***********************/
                    pk=pknow+Q;
                    kg=pk/(pk+R);
                    hknow=hk+kg*(remeberData-hk);
                    pknow=(1-kg)*pk;
                    listFloat.removeLast();         //去掉数组最后一个

                }
                ui->lcdNumberX->display(hknow);         //设置纵坐标
            }

            QByteArray tempTemp=temp.mid(i,14);
            i+=14;
            QString str;
            QTime time;
            str.prepend(tempTemp.toHex());              //转16进制变成字符串
            if(ui->pushButtonSave->text()=="停止保存"&&fileOk==false)
            {
                fileSave=new QFile("lookOne"+time.currentTime().toString("hhmmss")+".txt");  //保存到桌面
                fileOk=fileSave->open(QIODevice::WriteOnly|QFile::Text);         //以只写方式打开
            }

            str.append(/*"   "+time.currentTime().toString("hh:mm:ss:zzz")+*/"\r\n"); //加入换行符
            ui->textEditRead->insertPlainText(str);  //写入信息
            QTextCursor cursor=ui->textEditRead->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->textEditRead->setTextCursor(cursor);
            if(fileOk)
            {
                QTextStream out(fileSave);
                for(int j=0;j<str.size();j+=2)
                {
                    QString str1=str.mid(j,2);          //每28个字符为一行

                    if(str1.startsWith("\n")||str1.endsWith("\n"))
                    {
                        j--;
                        out<<"\r\n";
                        continue;

                    }

                    str1.append(" ");
                    out<<str1;                       //写入文件
                }


            }

            if(ui->textEditRead->document()->lineCount()>1000)
            {
                ui->textEditRead->clear();
            }

        }
        else
        {
            i++;
        }


    }

    /***************************串口二读取数据*************************/
    for(int i=0;i<tempTwo.size();)
    {
        if(tempTwo[i]==0XAA&&tempTwo[i+1]==0XAA&&tempTwo[i+12]==0X55&&tempTwo[i+13]==0X55)   //判断出障碍高度的信息
        {
            /*************************************距离处理***********************************/
            if(tempTwo[i+2]==0X0C&&tempTwo[i+3]==0X07)
            {
                temphkNowTwo=hknowTwo;   //记忆数据
                hkTwo=hknowTwo;          //卡尔曼滤波上次数据
                remeberDataTwo=(((BYTE)tempTwo[i+6])*16*16+(BYTE)tempTwo[i+7])*0.01;  //将信息提取出来
                testDataTwo=remeberDataTwo;
                listFloatTwo<<remeberDataTwo;
                if(listFloatTwo.size()==1)
                {
                    hkTwo=remeberDataTwo;
                }
                else if(listFloatTwo.size()==2||listFloatTwo.size()==3)
                {
                    /*******************卡尔曼滤波算法***********************/
                    pkTwo=pknowTwo+QTwo;
                    kgTwo=pkTwo/(pkTwo+RTwo);
                    hknowTwo=hkTwo+kgTwo*(remeberDataTwo-hkTwo);
                    pknowTwo=(1-kgTwo)*pkTwo;

                }
                else if(listFloatTwo.size()>3)
                {

                    if((listFloatTwo[3]>35)||(listFloatTwo[3]<0.5))
                    {
                        remeberDataTwo=listFloatTwo[0];
                    }
                    else
                    {
                        s1Two=listFloatTwo[1]-listFloatTwo[0];     //实际距离
                        s2Two=listFloatTwo[2]-listFloatTwo[1];     //实际距离
                        s3Two=1.5*s2Two-0.5*s1Two;                 //预测距离
                        predictLeftTwo=listFloatTwo[2]+s3Two-0.5;  //左预测值
                        predictRightTwo=listFloatTwo[2]+s3Two+0.5; //右预测值

                        vrelTwo=(listFloatTwo[3]-listFloatTwo[2])/0.05;  //速度

                        //判断取到值是否在可控区间内
                        if(((listFloatTwo[3]>predictLeftTwo) && (listFloatTwo[3]<predictRightTwo) && (vrelTwo>-4) && (vrelTwo<5) )||(nCountTwo==7))
                        {
                            //remeberData=listFloat[3];
                            nCountTwo=0;
                        }
                        else
                        {
                            remeberDataTwo=listFloatTwo[2];
                            nCountTwo++;
                        }

                        //将数组往前移动一位
                        for(int j=0;j<3;j++)
                        {
                            listFloatTwo[j]=listFloatTwo[j+1];
                        }

                    }


                    /*******************卡尔曼滤波算法***********************/
                    pkTwo=pknowTwo+QTwo;
                    kgTwo=pkTwo/(pkTwo+RTwo);
                    hknowTwo=hkTwo+kgTwo*(remeberDataTwo-hkTwo);
                    pknowTwo=(1-kgTwo)*pkTwo;
                    listFloatTwo.removeLast();         //去掉数组最后一个

                }
                ui->lcdNumberY->display(hknowTwo);         //设置纵坐标
            }

            QByteArray tempTemp=tempTwo.mid(i,14);
            i+=14;
            QString str;
            QTime time;
            str.prepend(tempTemp.toHex());              //转16进制变成字符串
            if(ui->pushButtonSave->text()=="停止保存"&&fileOkTwo==false)
            {
                fileSaveTwo=new QFile("lookTwo"+time.currentTime().toString("hhmmss")+".txt");  //保存到桌面
                fileOkTwo=fileSaveTwo->open(QIODevice::WriteOnly|QFile::Text);         //以只写方式打开
            }

            str.append(/*"   "+time.currentTime().toString("hh:mm:ss:zzz")+*/"\r\n"); //加入换行符
            ui->textEditRead->insertPlainText(str);  //写入信息
            QTextCursor cursor=ui->textEditRead->textCursor();
            cursor.movePosition(QTextCursor::End);
            ui->textEditRead->setTextCursor(cursor);
            if(fileOkTwo)
            {
                QTextStream out(fileSaveTwo);
                for(int j=0;j<str.size();j+=2)
                {
                    QString str1=str.mid(j,2);          //每28个字符为一行

                    if(str1.startsWith("\n")||str1.endsWith("\n"))
                    {
                        j--;
                        out<<"\r\n";
                        continue;
                    }

                    str1.append(" ");
                    out<<str1;                       //写入文件
                }
            }

            if(ui->textEditRead->document()->lineCount()>1000)
            {
                ui->textEditRead->clear();
            }
        }
        else
        {
            i++;
        }
    }

    if(ok&&okTwo)
    {
        if(testData!=0&&testDataTwo!=0)
        {
            //判断是否组成了三角形
            if(hknowTwo+DIS>hknow||hknow+DIS>hknowTwo||hknowTwo+hknow>DIS)
            {
                float cosB=(hknowTwo*hknowTwo+DIS*DIS-hknow*hknow)/(2*DIS*hknowTwo);
                if(cosB>1||cosB<-1)
                {
                    return;
                }

                float X=hknowTwo*cosB; //得到最终距离
                float Y=hknowTwo*sqrt(1-cosB*cosB); //得到最终距离
                X=DIS/2-X;
                dataX[0]=X;
                dataY[0]=Y;
                ui->lcdNumberX_2->display(X);
                ui->lcdNumberY_2->display(Y);
                if(ui->pushButtonSave->text()=="停止保存"&&fileOkThree==false)
                {
                    fileSaveThree=new QFile("lookThree"+time.currentTime().toString("hhmmss")+".txt");  //保存到桌面
                    fileOkThree=fileSaveThree->open(QIODevice::WriteOnly|QFile::Text);         //以只写方式打开
                }
                if(fileOkThree)
                {
                    QTextStream out(fileSaveThree);
                    out<<QString::number(hknow,'f',3)<<"      "<<QString::number(hknowTwo,'f',3)<<"      "<<QString::number(dataX[0],'f',3)<<"      "<<QString::number(dataY[0],'f',3)<<"\r\n";
                }

                ui->customPlot->graph(0)->setData(dataX,dataY);
                ui->customPlot->graph(0)->addData(0.9,0);  //雷达位置
                ui->customPlot->graph(0)->addData(-0.9,0); //雷达位置
                ui->customPlot->replot();
            }
        }
        else
        {
            ui->customPlot->replot();
        }
    }
}


/****************实时刷新数据的定时器*************/
void MainWindow::timeUpdate()
{
    if(ok||okTwo)         //如果串口已经打开，则读取数据
    {
        readCom(); //读取数据
    }
    else
    {
        return;
    }
}


/****************关闭串口***********************/
void MainWindow::closeCom()
{
    //将控件设置为可用
    ui->comboBoxPort->setEnabled(true);
    ui->comboBoxBaudRate->setEnabled(true);
    ui->comboBoxCheck->setEnabled(true);
    ui->comboBoxData->setEnabled(true);
    ui->comboBoxStop->setEnabled(true);
    actionSave->setEnabled(true);
    actionDelete->setEnabled(true);
    openCom->setEnabled(true);
    comClose->setEnabled(false);
    comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    openCom->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    if(ok)   //如果处于打开状态，则关闭
    {

        if(!okTwo)
        {
            if(this->timer->isActive())        //判断定时器是否开着
            {
                this->timer->stop();           //关闭定时器
            }
        }

        if(fileOk)
        {
            fileSave->close();
            delete fileSave;
            fileOk=false;
        }
        if(fileOkTwo)
        {
            fileSaveTwo->close();
            delete fileSaveTwo;
            fileOkTwo=false;
        }
        if(fileOkThree)
        {
            fileSaveThree->close();
            delete fileSaveThree;
            fileOkThree=false;
        }

        myCom->close();
        ui->statusBar->showMessage("关闭成功",3000);
        ok=false;
    }
    else
    {

        return;
    }
}


/****************关闭串口***********************/
void MainWindow::closeComTwo()
{
    //将控件设置为可用
    ui->comboBoxPortTwo->setEnabled(true);
    ui->comboBoxBaudRate->setEnabled(true);
    ui->comboBoxCheck->setEnabled(true);
    ui->comboBoxData->setEnabled(true);
    ui->comboBoxStop->setEnabled(true);
    actionSave->setEnabled(true);
    actionDelete->setEnabled(true);
    openComTwo->setEnabled(true);
    comCloseTwo->setEnabled(false);
    comCloseTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    openComTwo->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    if(okTwo)   //如果处于打开状态，则关闭
    {
        if(!ok)
        {
            if(this->timer->isActive())        //判断定时器是否开着
            {
                this->timer->stop();           //关闭定时器
            }
        }
        if(fileOk)
        {
            fileSave->close();
            delete fileSave;
            fileOk=false;
        }
        if(fileOkTwo)
        {
            fileSaveTwo->close();
            delete fileSaveTwo;
            fileOkTwo=false;
        }
        if(fileOkThree)
        {
            fileSaveThree->close();
            delete fileSaveThree;
            fileOkThree=false;
        }

        myComTwo->close();
        ui->statusBar->showMessage("关闭成功",3000);
        okTwo=false;
    }
    else
    {
        return;
    }
}



/****************保存文本信息********************/
void MainWindow::saveFile()
{
    
    QString fileName=QFileDialog::getSaveFileName(this,tr("保存"),"未命名.txt",tr("text(*.txt)"));
    
    if(fileName.isEmpty())
    {
        return;
    }
    QFile*file=new QFile;
    file->setFileName(fileName);
    
    bool fileOk=file->open(QIODevice::WriteOnly|QFile::Text);   //以只写方式打开
    
    if(fileOk)
    {
        QTextStream out(file);
        QString strTemp=ui->textEditRead->toPlainText();
        QString str;

        for(int i=0;i<strTemp.size();i+=2)
        {
            str=strTemp.mid(i,2);          //每28个字符为一行

            if(str.startsWith("\n")||str.endsWith("\n"))
            {
                i--;
                out<<"\r\n";
                continue;
            }

            str.append(" ");
            out<<str;                       //写入文件
        }

        file->close();
        delete file;
        QMessageBox::information(this,tr("系统提示"),tr("保存成功"));
    }
    else
    {
        QMessageBox::warning(this,tr("系统提示"),tr("保存失败"));
    }
}


/****************清空信息***********************/
void MainWindow::clearMessage()
{
    ui->textEditRead->clear();                 //清空文本信息
    ui->lcdNumberX->display(0);                //横坐标为0
    ui->lcdNumberY->display(0);                //纵坐标为0
}


/***************画图函数************************/
void MainWindow::paintEvent(QPaintEvent *)
{
    QBitmap objBitmap(size());                      //生成一张位图
    QPainter painterBit(&objBitmap);                //在位图上绘画
    painterBit.fillRect(rect(),Qt::white);          //填充位图矩形框
    painterBit.setBrush(QColor(0,0,0));             //位图上画圆角矩形
    painterBit.drawRoundedRect(this->rect(),10,10);
    setMask(objBitmap);                             //使用setMark过滤即可
    int width=this->width();

    /*************************************加载位置********************************/
    minButton->setGeometry(width-90,0,30,30);
    maxButton->setGeometry(width-60,0,30,30);
    closeButton->setGeometry(width-30,0,30,30);
    openCom->setGeometry(width*0.05,30,120,30);          //打开串口
    comClose->setGeometry(width*0.20,30,120,30);         //关闭串口
    openComTwo->setGeometry(width*0.35,30,120,30);       //打开串口
    comCloseTwo->setGeometry(width*0.50,30,120,30);      //关闭串口
    actionSave->setGeometry(width*0.65,30,120,30);       //保存按钮
    actionDelete->setGeometry(width*0.80,30,120,30);     //清空按钮
    update();  //刷新
}


/***************自动保存************************/
void MainWindow::on_pushButtonSave_clicked()
{

    if(!ok&&!okTwo)
    {
        return;
    }
    if(ui->pushButtonSave->text()==tr("停止保存"))
    {
        ui->pushButtonSave->setText(tr("保存"));

        if(fileOk)
        {
            fileSave->close();
            delete fileSave;
            fileOk=false;
        }
        if(fileOkTwo)
        {
            fileSaveTwo->close();
            delete fileSaveTwo;
            fileOkTwo=false;
        }
        if(fileOkThree)
        {
            fileSaveThree->close();
            delete fileSaveThree;
            fileOkThree=false;
        }
    }
    else if (ui->pushButtonSave->text()==tr("保存"))
    {
        ui->pushButtonSave->setText(tr("停止保存"));
    }
}


/***************最小化************************/
void MainWindow::actionMin()
{
    showMinimized();
}


/***************最大化************************/
void MainWindow::actionMax()
{
    if(maxNormal)
    {
        this->showNormal();
        maxNormal=!maxNormal;
        maxButton->setIcon(maxPix);
    }
    else
    {
        this->showMaximized();
        maxNormal=!maxNormal;
        maxButton->setIcon(normalPix);
    }
}


/***************关闭************************/
void MainWindow::actionClose()
{
    close();    //关闭
}


/***************鼠标移动************************/
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(maxNormal)
    {
        return;
    }
    if(isMousePressed==true)
    {
        QPoint movePot=event->globalPos()-mousePosition;
        move(movePot);
    }
}


/***************鼠标点击************************/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mousePosition=event->pos();  //当鼠标单击窗体准备拖动时，初始化鼠标在窗体中的相对位置
    //只对标题栏范围内的鼠标事件进行处理
    if(mousePosition.x()<=posMinX)
    {
        return;
    }
    if(mousePosition.x()>=posMaxX)
    {
        return;
    }
    if(mousePosition.y()<=posMinY)
    {
        return;
    }
    if(mousePosition.y()>=posMaxY)
    {
        return;
    }
    isMousePressed=true;
}


/***************鼠标释放************************/
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressed=false;
}
/***************事件过滤************************/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->customPlot&&event->type()==QEvent::Wheel)
    {
        QWheelEvent* e=static_cast<QWheelEvent*>(event);
        if(e->delta()>0)
        {
            if(wheelCount<=30)
            {
                ui->customPlot->yAxis->setRange(0,wheelCount++);
                ui->customPlot->replot();
            }
        }
        else
        {
            if(wheelCount>=3)
            {
                ui->customPlot->yAxis->setRange(0,wheelCount--);
                ui->customPlot->replot();
            }
        }
    }

    return QWidget::eventFilter(watched,event);
}







