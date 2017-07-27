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
static float valueSlider=30;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setMinimumSize(880,620);     //设置最小显示宽高
    ui->setupUi(this);                 //安装界面元素
    setPalette(QPalette(Qt::darkCyan));//设置背景色
    setAutoFillBackground(true);


    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏

    int width=this->width();
    maxNormal=false;

    minButton=new QToolButton(this);     //最小化按钮
    maxButton=new QToolButton(this);     //最大化按钮
    closeButton=new QToolButton(this);   //关闭按钮
    openCom=new QToolButton(this);       //打开串口
    comClose=new QToolButton(this);      //关闭串口
    actionSave=new QToolButton(this);    //保存按钮
    actionDelete=new QToolButton(this);  //清空按钮
    iconLabel=new QLabel(this);
    labelTitle=new QLabel(this);


    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));        //最小化按钮
    connect(maxButton,SIGNAL(clicked(bool)),SLOT(actionMax()));        //最大化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));    //关闭按钮
    connect(openCom,SIGNAL(clicked(bool)),this,SLOT(connCom()));       //连接串口
    connect(comClose,SIGNAL(clicked()),this,SLOT(closeCom()));         //读取串口数据
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
    openCom->setGeometry(100,30,120,30);          //打开串口
    comClose->setGeometry(240,30,120,30);         //关闭串口
    actionSave->setGeometry(380,30,120,30);       //保存按钮
    actionDelete->setGeometry(520,30,120,30);     //清空按钮


    /*************************************提示信息********************************/
    openCom->setToolTip(tr("打开串口"));
    comClose->setToolTip(tr("关闭串口"));
    actionSave->setToolTip(tr("保存信息"));
    actionDelete->setToolTip(tr("清空信息"));
    openCom->setText(tr("打开串口"));
    comClose->setText(tr("关闭串口"));
    actionSave->setText(tr("保存信息"));
    actionDelete->setText(tr("清空信息"));
    labelTitle->setText(tr("高度计"));


    /*************************************添加背景颜色******************************/

    minButton->setStyleSheet("background-color:transparent");
    maxButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");
    openCom->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionSave->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    actionDelete->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:white;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
    iconLabel->setStyleSheet("QLabel{border-image:url(:/images/tc.ico)}");


    ok=false;                 //初始值为false
    fileOk=false;             //初始值为false
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
    comClose->setEnabled(false);
    comClose->setStyleSheet("QToolButton{border:2px groove cyan;border-radius:10px;color:gray;}QToolButton:hover{background-color:rgb(0,130,150);}QToolButton:pressed{background-color:rgb(85,170,255);}");
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

        this->timer=new QTimer(this);                                    //定义一个定时器
        connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
        timer->start(50);                                                //0.05秒调用一次


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


/****************定义槽函数读取串口数据***********/
void MainWindow::readCom()
{
    QByteArray temp=myCom->readAll(); //读取串口数据


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


                ui->lcdNumberY->display(hknow);         //设置纵坐标

            }

            QByteArray tempTemp=temp.mid(i,14);
            i+=14;
            QString str;
            QTime time;
            str.prepend(tempTemp.toHex());              //转16进制变成字符串
            if(ui->pushButtonSave->text()=="停止保存"&&fileOk==false)
            {
                fileSave=new QFile("look.txt"+time.currentTime().toString("hh:mm:ss:zzz"));  //保存到桌面
                fileOk=fileSave->open(QIODevice::WriteOnly|QFile::Text);         //以只写方式打开
            }


            str.append("   "+time.currentTime().toString("hh:mm:ss:zzz")+"\r\n"); //加入换行符
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



    ui->lcdNumberX->display(0);                      //设置横坐标


}


/****************实时刷新数据的定时器*************/
void MainWindow::timeUpdate()
{
    if(ok)         //如果串口已经打开，则读取数据
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

        if(this->timer->isActive())        //判断定时器是否开着
        {
            this->timer->stop();           //关闭定时器
        }

        if(fileOk)
        {
            fileSave->close();
            delete fileSave;
            fileOk=false;


        }



        myCom->close();
        QMessageBox::information(this,"系统提示","关闭成功");
        ok=false;
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
    openCom->setGeometry(width*0.15,30,120,30);          //打开串口
    comClose->setGeometry(width*0.35,30,120,30);         //关闭串口
    actionSave->setGeometry(width*0.55,30,120,30);       //保存按钮
    actionDelete->setGeometry(width*0.75,30,120,30);     //清空按钮

    QPoint pointLeft,pointRight;                  //声明一个point
    float remeberLeft,remeberRight, x1,y1,x2,y2;  //记忆数据，横纵坐标

    float sliderHigh=(-1)*(this->height()-4*30)+40;     //控件高度
    QPainter painter(this);




    /**************************************************画矩形域******************************************************/
    //将坐标系的该点变成原点坐标
    painter.translate(this->width()-ui->textEditRead->width()+0.4*ui->groupBox_2->width(),this->height()-2.2*10-40);
    //设置画笔为灰色
    QPen pen(Qt::white,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen);

    //画下面直线
    painter.drawLine(0,0,60,0);

    //画左边直线
    painter.drawLine(0,0,0,sliderHigh);

    //画右边直线
    painter.drawLine(60,0,60,sliderHigh);

    //画上面直线线
    painter.drawLine(0,sliderHigh,60,sliderHigh);


    //设置第二个画笔
    QPen pen2(Qt::white,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pen2);

    //画左边刻度线
    painter.drawLine(-10,0,-10,sliderHigh);

    //画右边刻度线
    painter.drawLine(70,0,70,sliderHigh);

    //画三角形,填充颜色
    painter.drawLine(0,sliderHigh-5,30,sliderHigh-20);
    painter.drawLine(30,sliderHigh-20,60,sliderHigh-5);
    painter.drawLine(0,sliderHigh-5,60,sliderHigh-5);


    //画三角形,填充颜色
    painter.drawLine(0,5,30,20);
    painter.drawLine(30,20,60,5);
    painter.drawLine(0,5,60,5);


    polyGon.clear();
    polyGon<<QPoint(60,0);
    polyGon<<QPoint(60,sliderHigh);
    polyGon<<QPoint(0,sliderHigh);
    polyGon<<QPoint(0,0);
    painter.setBrush(Qt::white);
    painter.drawConvexPolygon(polyGon);



    polyGon.clear();
    polyGon<<QPoint(60,0);
    polyGon<<QPoint(60,sliderHigh);
    polyGon<<QPoint(0,sliderHigh);
    polyGon<<QPoint(0,0);
    painter.setBrush(Qt::white);
    painter.drawConvexPolygon(polyGon);

    //如果向下，将三角形换色填充
    if(temphkNow>hknow)
    {
        polyGon.clear();
        polyGon<<QPoint(0,5);
        polyGon<<QPoint(30,20);
        polyGon<<QPoint(60,5);
        painter.setBrush(Qt::darkRed);
        painter.drawConvexPolygon(polyGon);




        polyGon.clear();
        polyGon<<QPoint(0,sliderHigh-5);
        polyGon<<QPoint(30,sliderHigh-20);
        polyGon<<QPoint(60,sliderHigh-5);
        painter.setBrush(Qt::gray);
        painter.drawConvexPolygon(polyGon);

    }
    //如果向上，将三角形换色填充
    else if(temphkNow<hknow)
    {
        polyGon.clear();
        polyGon<<QPoint(0,sliderHigh-5);
        polyGon<<QPoint(30,sliderHigh-20);
        polyGon<<QPoint(60,sliderHigh-5);
        painter.setBrush(Qt::darkRed);
        painter.drawConvexPolygon(polyGon);



        polyGon.clear();
        polyGon<<QPoint(0,5);
        polyGon<<QPoint(30,20);
        polyGon<<QPoint(60,5);
        painter.setBrush(Qt::gray);
        painter.drawConvexPolygon(polyGon);

    }
    else
    {
        polyGon.clear();
        polyGon<<QPoint(0,sliderHigh-5);
        polyGon<<QPoint(30,sliderHigh-20);
        polyGon<<QPoint(60,sliderHigh-5);
        painter.setBrush(Qt::gray);
        painter.drawConvexPolygon(polyGon);



        polyGon.clear();
        polyGon<<QPoint(0,5);
        polyGon<<QPoint(30,20);
        polyGon<<QPoint(60,5);
        painter.setBrush(Qt::gray);
        painter.drawConvexPolygon(polyGon);
    }


    /**************************************************画刻度线******************************************************/
    for(BYTE num=0;num<=valueSlider;num++)
    {
        /**************滑动条的值小于30***********/
        if(valueSlider<30)
        {
            y1=sliderHigh/valueSlider*num;
            y2=sliderHigh/valueSlider*num;
            //以二为单位，只要是二的倍数，线画长一些，不是二的倍数线画短一些
            if(num%2==0)
            {
                x1=-20;
                x2=80;
                pointLeft.setX(x1-28);
                pointLeft.setY(y1+5);
                pointRight.setX(x2+28);
                pointRight.setY(y2+5);
                painter.drawText(pointLeft,QString::number(num));   //写刻度线数字
                painter.drawText(pointRight,QString::number(num));  //写刻度线数字
            }
            else
            {
                x1=-15;
                x2=75;
            }
            remeberLeft=y1;
            remeberRight=y2;
            painter.drawLine(-10,y1,x1,y1);                      //画刻度线
            painter.drawLine(70,y2,x2,y2);                       //画刻度线

        }
        /**************滑动条的值大于30***********/
        else
        {
            if(num<=10)
            {
                y1=sliderHigh*0.05*num;
                y2=sliderHigh*0.05*num;
                if(num%2==0)
                {
                    x1=-20;
                    x2=80;
                    pointLeft.setX(x1-28);
                    pointLeft.setY(y1+5);
                    pointRight.setX(x2+28);
                    pointRight.setY(y2+5);
                    painter.drawText(pointLeft,QString::number(num));   //写刻度线数字
                    painter.drawText(pointRight,QString::number(num));  //写刻度线数字
                }
                else
                {
                    x1=-15;
                    x2=75;
                }
                remeberLeft=y1;
                remeberRight=y2;
                painter.drawLine(-10,y1,x1,y1);                      //画刻度线
                painter.drawLine(70,y2,x2,y2);                       //画刻度线
            }

            if(num>10&&num<=20)
            {
                y1=remeberLeft+sliderHigh/3*0.1;
                y2=remeberRight+sliderHigh/3*0.1;
                if(num%2==0)
                {
                    x1=-20;
                    x2=80;
                    pointLeft.setX(x1-28);
                    pointLeft.setY(y1+7);
                    pointRight.setX(x2+28);
                    pointRight.setY(y2+7);
                    painter.drawText(pointLeft,QString::number(num));   //写刻度线数字
                    painter.drawText(pointRight,QString::number(num));  //写刻度线数字
                }
                else
                {
                    x1=-15;
                    x2=75;
                }
                remeberLeft=y1;
                remeberRight=y2;
                painter.drawLine(-10,y1,x1,y1);                      //画刻度线
                painter.drawLine(70,y2,x2,y2);                       //画刻度线
            }

            if(num>20)
            {
                y1=remeberLeft+sliderHigh/6*0.1;
                y2=remeberRight+sliderHigh/6*0.1;
                if(num%2==0)
                {
                    x1=-20;
                    x2=80;
                    pointLeft.setX(x1-28);
                    pointLeft.setY(y1+7);
                    pointRight.setX(x2+28);
                    pointRight.setY(y2+7);
                    painter.drawText(pointLeft,QString::number(num));   //写刻度线数字
                    painter.drawText(pointRight,QString::number(num));  //写刻度线数字
                }
                else
                {
                    x1=-15;
                    x2=75;
                }
                remeberLeft=y1;
                remeberRight=y2;
                painter.drawLine(-10,y1,x1,y1);                      //画刻度线
                painter.drawLine(70,y2,x2,y2);                       //画刻度线
            }
        }

    }



    /**************************************************设置渐变******************************************************/
    QLinearGradient linerGradient=QLinearGradient(0,0,0,sliderHigh*30/valueSlider);
    linerGradient.setColorAt(0.0,Qt::cyan);
    linerGradient.setColorAt(0.3,Qt::green);
    linerGradient.setColorAt(0.7,Qt::yellow);
    linerGradient.setColorAt(1.0,Qt::red);

    QBrush qsh(linerGradient);
    painter.setBrush(qsh);
    QPen pen3(Qt::red,3,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);


    /**************************************************在画的矩形域中显示值******************************************************/
    if(valueSlider<30)
    {
        if(hknow==0&&valueSlider==0)
        {
            return;
        }
        if(valueSlider<hknow)
        {
            painter.setPen(pen);
            painter.drawRect(0, 0, 60, sliderHigh);

        }
        else if(valueSlider>=hknow&&hknow!=0)
        {
            painter.setPen(pen);
            painter.drawRect(0, 0, 60, hknow*(sliderHigh/valueSlider));
            painter.setPen(pen3);
            //画直线
            painter.drawLine(-20,hknow*(sliderHigh/valueSlider),80,hknow*(sliderHigh/valueSlider));
            painter.drawLine(-20,hknow*(sliderHigh/valueSlider),-20,hknow*(sliderHigh/valueSlider)+10);
            painter.drawLine(80,hknow*(sliderHigh/valueSlider),80,hknow*(sliderHigh/valueSlider)+10);
        }
    }
    else
    {
        if(hknow>0&&hknow<=10)
        {
            painter.setPen(pen);
            painter.drawRect(0, 0, 60, hknow*(sliderHigh*0.05));
            //画标线
            painter.setPen(pen3);
            painter.drawLine(-20,hknow*(sliderHigh*0.05),80,hknow*(sliderHigh*0.05));
            painter.drawLine(-20,hknow*(sliderHigh*0.05),-20,hknow*(sliderHigh*0.05)+10);
            painter.drawLine(80,hknow*(sliderHigh*0.05),80,hknow*(sliderHigh*0.05)+10);
        }
        else if(hknow>10&&hknow<=20)
        {
            painter.setPen(pen);
            painter.drawRect(0, 0, 60, 10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1));

            //画标线
            painter.setPen(pen3);
            painter.drawLine(-20,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1),80,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1));
            painter.drawLine(-20,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1),-20,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1)+10);
            painter.drawLine(80,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1),80,10*(sliderHigh*0.05)+(hknow-10)*(sliderHigh/3*0.1)+10);
        }
        else if(hknow>20&&hknow<=30)
        {
            painter.setPen(pen);
            painter.drawRect(0, 0, 60, 10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1));

            //画标线
            painter.setPen(pen3);
            painter.drawLine(-20,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1),80,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1));
            painter.drawLine(-20,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1),-20,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1)+10);
            painter.drawLine(80,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1),80,10*(sliderHigh*0.05)+10*(sliderHigh/3*0.1)+(hknow-20)*(sliderHigh/6*0.1)+10);
        }
        else if(hknow>30)
        {

            painter.drawRect(0, 0, 60, sliderHigh);
        }

    }

    update();  //刷新
}


/***************自动保存************************/
void MainWindow::on_pushButtonSave_clicked()
{

    if(!ok)
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

void MainWindow::wheelEvent(QWheelEvent*event )
{
    if(event->delta()>0)
    {
        if(valueSlider>=30)
        {
            return;
        }
        valueSlider+=0.2;
    }
    else
    {
        if(valueSlider<=0)
        {
            return;
        }
        valueSlider-=0.2;
    }
}





