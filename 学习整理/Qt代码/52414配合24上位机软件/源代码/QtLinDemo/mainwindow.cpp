#include "mainwindow.h"
#include "ui_mainwindow.h"

static float dataABY=0;
static float dataBCY=0;
static float dataCDY=0;
static bool  beepFinish=false;
static bool  handClick=false;

/*************************构造函数*********************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ok=false;        //打开串口标志位
    handShake=false; //握手连接标志位
    this->showFullScreen();   //全屏显示
    int width=this->width();  //获取界面宽度
    this->setWindowFlags(Qt::FramelessWindowHint);//标题框隐藏
    ui->progressBarABX->setObjectName("progressBarABX");
    ui->progressBarBCX->setObjectName("progressBarBCX");
    ui->progressBarCDX->setObjectName("progressBarCDX");

    ui->progressBarABY->setObjectName("progressBarABY");
    ui->progressBarBCY->setObjectName("progressBarBCY");
    ui->progressBarCDY->setObjectName("progressBarCDY");


    //加载图标
    QPixmap closePix=style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    QToolButton *closeButton=new QToolButton(this);
    closeButton->setIcon(closePix);
    closeButton->setGeometry(width-32,0,30,30);

    QToolButton *minButton=new QToolButton(this);
    QPixmap minPix =style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPix);
    minButton->setGeometry(width-64,0,30,30);


    //设置标题
    titleLabel=new QLabel(this);
    QFont font=titleLabel->font();
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setGeometry(5,0,width-80,30);
    titleLabel->setFont(QFont("ZYSong",14));
    titleLabel->setStyleSheet("color: rgb(60, 170, 150);");
    titleLabel->setText("倒车雷达上位机软件");


    //连接信号与槽
    connect(closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));      //关闭按钮
    connect(minButton,SIGNAL(clicked(bool)),this,SLOT(showMinimized()));//关闭按钮

    //注册监听事件
    ui->widgetData->installEventFilter(this);
    //默认设置信息
    ui->comboBoxBaud->setCurrentText(tr("57600"));
    ui->comboBoxBaud_2->setCurrentText(tr("19200"));
    ui->comboBoxPort->setCurrentText(tr("COM12"));
    ui->comboBoxDeal->setCurrentText(tr("Lin2.x"));
    ui->comboBoxPort->setCurrentText(tr("COM12"));
    this->setWindowTitle(tr("52424上位机软件"));

    //设置控件是否可用
    ui->pushButtonConn->setEnabled(false);
    ui->comboBoxBaud_2->setEnabled(false);
    ui->comboBoxDeal->setEnabled(false);
    ui->comboBoxGallery->setEnabled(false);
    ui->checkBoxImp->setEnabled(false);
    ui->checkBoxSleep->setEnabled(false);
    ui->checkBoxWake->setEnabled(false);
    comUpdate();  //更新串口
    readConfig(); //读取配置信息
    //设置定时器
    this->timerCom=new QTimer(this);                                    //定义一个定时器
    connect(timerCom,SIGNAL(timeout()),this,SLOT(comUpdate()));         //设置
    timerCom->start(2000);                                              //2秒调用一次
}

/*************************析构函数***********************/
MainWindow::~MainWindow()
{
    delete ui;
}


/*************************连接串口*********************/
void MainWindow::connCom()
{
    if(ui->pushButtonOpen->text()==tr("打开串口"))
    {
        QString portName=ui->comboBoxPort->currentText();

        myCom=new QextSerialPort(portName);//定义串口对象，并传递参数对其进行初始化
        if(myCom->isOpen())                       //如果串口已经打开，返回
        {
            return;
        }
        else
        {
            /*************************设置比特率*************************/
            if(ui->comboBoxBaud->currentText()==tr("9600"))
            {
                myCom->setBaudRate(BAUD9600);

            }
            else if(ui->comboBoxBaud->currentText()==tr("115200"))
            {
                myCom->setBaudRate(BAUD115200);
            }

            /*************************设置比特率*************************/
            if(ui->comboBoxBaud->currentText()==tr("57600"))
            {
                myCom->setBaudRate(BAUD57600);

            }
            else if(ui->comboBoxBaud->currentText()==tr("57600"))
            {
                myCom->setBaudRate(BAUD57600);
            }
            else if(ui->comboBoxBaud->currentText()==tr("19200"))
            {
                myCom->setBaudRate(BAUD19200);
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

            myCom->setFlowControl(FLOW_OFF);     //设置数据流控制
            myCom->setTimeout(TIME_OUT);         //设置延时
            ok=myCom->open(QIODevice::ReadWrite);//以可读可写方式打开串口
            if(!ok)
            {

                ui->statusBar->showMessage(tr("打开失败"),3000);
                return;
            }
            else
            {
                ui->pushButtonOpen->setText("关闭串口");
                ui->statusBar->showMessage(tr("打开串口成功"),3000);
            }

            //设置控件是否可用
            ui->comboBoxBaud->setEnabled(false);
            ui->comboBoxData->setEnabled(false);
            ui->comboBoxPort->setEnabled(false);
            ui->comboBoxCheck->setEnabled(false);
            ui->comboBoxStop->setEnabled(false);
            ui->pushButtonConn->setEnabled(true);
            ui->comboBoxBaud_2->setEnabled(true);
            ui->comboBoxDeal->setEnabled(true);
            ui->comboBoxGallery->setEnabled(true);
            ui->checkBoxImp->setEnabled(true);
            ui->checkBoxSleep->setEnabled(true);
            ui->checkBoxWake->setEnabled(true);

            //设置定时器
            this->timer=new QTimer(this);                                    //定义一个定时器
            connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
            timer->start(50);                                               //0.05秒调用一次

            //设置定时器
            this->timerBeep=new QTimer(this);                                    //定义一个定时器
            connect(timerBeep,SIGNAL(timeout()),this,SLOT(beepUpdate()));        //设置
        }
    }
    else if(ui->pushButtonOpen->text()==tr("关闭串口"))
    {
        if(ok)
        {
            //设置控件是否可用
            ui->comboBoxBaud->setEnabled(true);
            ui->comboBoxData->setEnabled(true);
            ui->comboBoxPort->setEnabled(true);
            ui->comboBoxCheck->setEnabled(true);
            ui->comboBoxStop->setEnabled(true);
            ui->pushButtonConn->setEnabled(false);
            ui->comboBoxBaud_2->setEnabled(false);
            ui->comboBoxDeal->setEnabled(false);
            ui->comboBoxGallery->setEnabled(false);
            ui->checkBoxImp->setEnabled(false);
            ui->checkBoxSleep->setEnabled(false);
            ui->checkBoxWake->setEnabled(false);

            if(timer->isActive())        //判断定时器是否开着
            {
                timer->stop();           //关闭定时器
            }
            if(timerBeep->isActive())    //判断定时器是否开着
            {
                timerBeep->stop();       //关闭定时器
            }

            myCom->close();
            delete myCom;
            myCom = NULL;
            ok=false;
            handShake=false;
            ui->pushButtonOpen->setText("打开串口");
            ui->statusBar->showMessage(tr("关闭串口成功"),3000);
            ui->pushButtonConn->setText(tr("连接"));
        }
        else
        {
            return;
        }
    }
}


/*************************读取数据*********************/
void MainWindow::readCom()
{
    QByteArray temp=myCom->readAll(); //读取串口数据
    if(!temp.isEmpty())
    {
        readConn(temp);
        if(handShake)
        {
            readMessage(temp);//读取探头信息
        }
    }
}


/*************************探头数据*********************/
void MainWindow::readMessage(QByteArray temp)
{
    /****************读取数据*************/
    for(int j=0;j<temp.size();j++)
    {
        if(temp[j+3]==0x90 &&temp[j+10]==0X09&&temp[j+11]==0x08)
        {
            tempData.clear();
            float dataBCX;
            float minXData;
            //读取数据位
            for(int i=j;i<j+8;i++)
            {
                tempData[i-j] = temp[i+12];
            }

            float dataABX=((BYTE)(tempData[0]&0X7F))*0.01; //AB区域X坐标
            dataABY=((BYTE)tempData[1])*0.01;              //AB区域Y坐标
            QList<float>countAB;
            countAB<<dataABY;
            if(countAB.count()>=3)
            {
                if(countAB[0]==0&&countAB[1]==0&&countAB[2]==0)
                {
                    countAB.clear();
                    dataABY=0;
                }
            }

            if(((BYTE)tempData[2])/128==0)
            {
                dataBCX=((BYTE)(tempData[2]&0X7F))*0.01;       //BC区域X坐标
            }
            else
            {
                dataBCX=-1*((BYTE)(tempData[2]&0X7F))*0.01;    //BC区域X坐标
            }

            dataBCY=((BYTE)tempData[3])*0.01;             //BC区域Y坐标
            QList<float>countBC;
            countBC<<dataBCY;
            if(countBC.count()>=3)
            {
                if(countBC[0]==0&&countBC[1]==0&&countBC[2]==0)
                {
                    countBC.clear();
                    dataBCY=0;
                }
            }


            float dataCDX=-1*((BYTE)(tempData[4]&0X7F))*0.01;  //CD区域X坐标

            dataCDY=((BYTE)tempData[5])*0.01;              //CD区域Y坐标
            QList<float>countCD;
            countCD<<dataCDY;
            if(countCD.count()>=3)
            {
                if(countCD[0]==0&&countCD[1]==0&&countCD[2]==0)
                {
                    countCD.clear();
                    dataCDY=0;
                }
            }


            if(dataCDY==0)
            {
                ui->progressBarCDY->setValue(2);
                ui->labelCDY->setText(tr("--"));
            }
            else
            {
                ui->progressBarCDY->setValue(dataCDY*100);
                ui->labelCDY->setText(tr("%1m").arg(dataCDY));
            }
            if(dataABX==0)
            {
                ui->progressBarABX->setValue(2);
                ui->labelABX->setText(tr("--"));
            }
            else
            {
                ui->progressBarABX->setValue(dataABX*100);
                ui->labelABX->setText(tr("%1m").arg(dataABX));
            }


            if(dataBCX==0)
            {
                ui->progressBarBCX->setValue(2);
                ui->labelBCX->setText(tr("--"));
            }
            else
            {
                ui->progressBarBCX->setValue(dataBCX*100);
                ui->labelBCX->setText(tr("%1m").arg(dataBCX));
            }

            if(dataCDX==0)
            {
                ui->labelCDX->setText(tr("--"));
                ui->progressBarCDX->setValue(2);
            }
            else
            {
                ui->progressBarCDX->setValue(dataCDX*100);
                ui->labelCDX->setText(tr("%1m").arg(dataCDX));
            }

            if(dataABY==0)
            {
                ui->progressBarABY->setValue(2);
                ui->labelABY->setText(tr("--"));
            }
            else
            {
                ui->progressBarABY->setValue(dataABY*100);
                ui->labelABY->setText(tr("%1m").arg(dataABY));
            }


            if(dataBCY==0)
            {
                ui->progressBarBCY->setValue(2);
                ui->labelBCY->setText(tr("--"));
            }
            else
            {
                ui->progressBarBCY->setValue(dataBCY*100);
                ui->labelBCY->setText(tr("%1m").arg(dataBCY));
            }

            if(((BYTE)tempData[6])/128==0)
            {
                minXData=((BYTE)(tempData[6]&0X7F))*0.01;      //三个区域最小值
            }
            else
            {
                minXData=-1*((BYTE)(tempData[6]&0X7F))*0.01;   //三个区域最小值
            }
            float minYData=(BYTE)(tempData[7])*0.01;           //三个区域最小值
            if(minYData>0)
            {
                if(minYData>1.6&&minYData<=2)
                {
                    beepTime(1000);
                }
                else if(minYData>1.2&&minYData<=1.6)
                {
                    beepTime(800);
                }
                else if(minYData>0.8&&minYData<=1.2)
                {
                    beepTime(600);
                }
                else if(minYData>0.6&&minYData<=0.8)
                {
                    beepTime(400);
                }
                else if(minYData>0.4&&minYData<=0.6)
                {
                    beepTime(300);
                }
                else if(minYData>0.3&&minYData<=0.4)
                {
                    beepTime(200);
                }
                else if(minYData>0.2&&minYData<=0.3)
                {
                    beepTime(100);
                }
                else
                {
                    beepTime(40);
                }
            }
            else
            {
                if(timerBeep->isActive())
                {
                    timerBeep->stop();
                }
            }
            /*************加空格输出接收的指令***********/
            insertFlage(false,tempData);
        }
    }
}


/*************************蜂鸣器声音*********************/
void MainWindow::beepUpdate()
{
    Beep(0X7FF,200);
    beepFinish=true;

}


/*************************串口更新*********************/
void MainWindow::comUpdate()
{
    if(!ok)
    {
        //自动加载串口信息
        foreach(const QSerialPortInfo&info,QSerialPortInfo::availablePorts())
        {
            int portCount=0;
            for(int i=0;i<ui->comboBoxPort->count();i++)
            {
                if(ui->comboBoxPort->itemText(i)==info.portName())
                {
                    portCount++;
                }
            }
            if(portCount==0)
            {
                ui->comboBoxPort->addItem(info.portName());
            }

        }
    }
}


/*************************握手数据*********************/
void MainWindow::readConn(QByteArray temp)
{
    QTextCursor cursor=ui->textEdit->textCursor();//在光标处添加
    cursor.movePosition(QTextCursor::End);        //在光标处添加
    ui->textEdit->setTextCursor(cursor);          //在光标处添加

    if(temp[4]=='U'&&temp[5]=='2'&&temp[6]=='L')
    {
        handShake=true;
        ui->pushButtonConn->setText("已连接");
        //设置通道主从模式等
        setupFrame(Channel);

        //设置波特率
        setupFrame(Baud);

        //初始化设置，设置长度
        setupFrame(Length);

    }
    else
    {
        if(handClick)
        {
            setupFrame(Conn);
            handClick=false;
        }
    }
}


/*************************去空格***********************/
void MainWindow::deBlank(QString &str)
{
    str.replace(QRegExp("\\s{1,}"),"");
}


/*************************定时器***********************/
void MainWindow::timeUpdate()
{
    if(ok)         //如果串口已经打开，则读取数据
    {
        readCom(); //读取数据
    }
}


/*************************连接串口*********************/
void MainWindow::on_pushButtonOpen_clicked()
{
    connCom();
}


/*************************握手连接*********************/
void MainWindow::on_pushButtonConn_clicked()
{
    if(ok)
    {
        handClick=true;
        setupFrame(Conn);
    }
}


/*************************设置通道*********************/
void MainWindow::on_comboBoxGallery_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Channel);
}


/*************************设置波特率*******************/
void MainWindow::on_comboBoxBaud_2_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Baud);
}


/*************************设置主从模式********************/
void MainWindow::on_checkBoxImp_clicked()
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Imp);
}


/*************************设置协议************************/
void MainWindow::on_comboBoxDeal_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Deal);
}


/*************************事件过滤函数*********************/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->widgetData&&event->type()==QEvent::Paint)
    {
        paintPix();
    }
}


/*************************画图***************************/
void MainWindow::paintPix()
{
    QImage img;
    img.load(":/image/car.png");            //加载图片
    QPainter painter(ui->widgetData);       //在widget上绘制
    painter.setBrush(Qt::black);            //设置画刷
    painter.drawRect(0,0,ui->widgetData->width(),ui->widgetData->height()); //画一个矩形域，与控件大小相同
    int pointX=ui->widgetData->width()*0.5-0.95*img.width()+10;              //汽车图片的横坐标
    int pointY=ui->widgetData->height()*0.5-1.1*img.height()+heightCar;             //汽车图片纵坐标
    painter.translate(pointX+0.45*img.width()+10,pointY+0.34*img.height()-30);//将该点变为直角坐标系的原点

    /*****************************设置参数********************************/
    int valueX=(-300/2)*(0.4+dataABY);
    int valueY=valueX;
    int valueArea=-2*valueX;
    int startAngle=40;
    int rangeAngle=40;

    QRadialGradient radiaGradient(0,0,300,0,0);
    radiaGradient.setColorAt(0.3,QColor(200,0,0,100));
    radiaGradient.setColorAt(0.7,QColor(200,200,0,100));
    radiaGradient.setColorAt(0.9,QColor(30,144,255,100));
    painter.setBrush(radiaGradient);

    /*****************************画车后方包络图********************************/
    QPainter painterTail(ui->widgetData);
    painterTail.translate(pointX+0.45*img.width()+10,pointY+0.9*img.height()-65);
    painterTail.setPen(QPen(QColor(0,0,0,100),2));

    radiaGradient.setCenter(45,0);
    radiaGradient.setFocalPoint(45,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRight(valueX+45,valueY,valueArea,valueArea);      //画一个矩形域
    QPointF centerTailRight(45,0);                                  //圆弧的圆心坐标
    QPainterPath myPathTailRight;                                   //设置路径
    myPathTailRight.moveTo(centerTailRight);                        //将点移动到圆心
    myPathTailRight.arcTo(rectTailRight,180+startAngle,rangeAngle); //从圆心画圆弧
    painterTail.drawPath(myPathTailRight);                          //画出图形
    painterTail.setPen(QPen(Qt::darkRed,2));
    rectTailRight.setRect(valueX+45,valueY,valueArea,valueArea);
    painterTail.drawArc(rectTailRight,(180+startAngle)*16,rangeAngle*16);


    valueX=(-300/2)*(0.4+dataBCY);
    valueY=valueX;
    valueArea=-2*valueX;
    startAngle=80;
    rangeAngle=20;
    painterTail.setPen(QPen(QColor(0,0,0,100),2));
    radiaGradient.setCenter(45,0);
    radiaGradient.setFocalPoint(45,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRightCenter(valueX+45,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailRightCenter(45,0);                                       //圆弧的圆心坐标
    QPainterPath myPathTailRightCenter;                                        //设置路径
    myPathTailRightCenter.moveTo(centerTailRightCenter);                       //将点移动到圆心
    myPathTailRightCenter.arcTo(rectTailRightCenter,180+startAngle,rangeAngle);//从圆心画圆弧
    painterTail.drawPath(myPathTailRightCenter);                               //画出图形
    painterTail.setPen(QPen(Qt::darkRed,2));
    rectTailRight.setRect(valueX+45,valueY,valueArea,valueArea);
    painterTail.drawArc(rectTailRight,(180+startAngle)*16,rangeAngle*16);



    valueX=(-300/2)*(0.4+dataCDY);
    valueY=valueX;
    valueArea=-2*valueX;
    startAngle=100;
    rangeAngle=40;
    painterTail.setPen(QPen(QColor(0,0,0,100),2));
    radiaGradient.setCenter(45,0);
    radiaGradient.setFocalPoint(45,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailLeft(valueX+45,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailLeft(45,0);                                    //圆弧的圆心坐标
    QPainterPath myPathTailLeft;                                     //设置路径
    myPathTailLeft.moveTo(centerTailLeft);                           //将点移动到圆心
    myPathTailLeft.arcTo(rectTailLeft,180+startAngle,rangeAngle);    //从圆心画圆弧
    painterTail.drawPath(myPathTailLeft);                            //画出图形
    painterTail.setPen(QPen(Qt::darkRed,2));
    rectTailRight.setRect(valueX+45,valueY,valueArea,valueArea);
    painterTail.drawArc(rectTailRight,(180+startAngle)*16,rangeAngle*16);


    QPainter painterLast(ui->widgetData);                            //在widget上绘制
    painterLast.drawImage(pointX,pointY,img);                         //将图片加载到界面上
    update();
}


/*************************清空信息*************************/
void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEdit->clear();
}


/*************************读取信息函数**********************/
void MainWindow::readConfig()
{
    QReadWriteIni::getInstance()->readIni();
    ui->comboBoxBaud->setCurrentText(QReadWriteIni::getInstance()->strBaud);
    ui->comboBoxBaud_2->setCurrentText(QReadWriteIni::getInstance()->strLinBaud);
    ui->comboBoxPort->setCurrentText(QReadWriteIni::getInstance()->strPort);
    ui->comboBoxDeal->setCurrentText(QReadWriteIni::getInstance()->strLinPact);
    if(QReadWriteIni::getInstance()->strCheck=="0")
    {
        ui->comboBoxCheck->setCurrentText("无");
    }
    else if(QReadWriteIni::getInstance()->strCheck=="1")
    {
        ui->comboBoxCheck->setCurrentText("奇");
    }
    else if(QReadWriteIni::getInstance()->strCheck=="2")
    {
        ui->comboBoxCheck->setCurrentText("偶");
    }
    ui->comboBoxStop->setCurrentText(QReadWriteIni::getInstance()->strStop);
    ui->comboBoxData->setCurrentText(QReadWriteIni::getInstance()->strData);
    ui->comboBoxGallery->setCurrentText(QReadWriteIni::getInstance()->strLinChannel);

    if(QReadWriteIni::getInstance()->strLinImp=="1")
    {
        ui->checkBoxImp->setChecked(true);
    }
    else
    {
        ui->checkBoxImp->setChecked(false);
    }

    if(QReadWriteIni::getInstance()->strLinSleep=="1")
    {
        ui->checkBoxSleep->setChecked(true);
    }
    else
    {
        ui->checkBoxSleep->setChecked(false);
    }

    if(QReadWriteIni::getInstance()->strLinWake=="1")
    {
        ui->checkBoxWake->setChecked(true);
    }
    else
    {
        ui->checkBoxWake->setChecked(false);
    }
    heightCar=QReadWriteIni::getInstance()->heightCar;
}


/**********************蜂鸣器定时响应*******************/
void MainWindow::beepTime(int time)
{
    if(!timerBeep->isActive())
    {
        timerBeep->start(time);
    }
    else
    {
        if(beepFinish)
        {
            timerBeep->start(time);
            beepFinish=false;
        }
    }
}


/*************************插入数据***********************/
void MainWindow::insertFlage(BYTE flage,QByteArray &array)
{
    QString strMessage;
    QString strTemp;
    if(flage)
    {
        strMessage.append("T:");
    }
    else
    {
        strMessage.append("R:");
    }
    strMessage.append(array.toHex());
    for(int i=0;i<strMessage.count();i+=2)
    {
        strTemp+=strMessage.mid(i,2);
        strTemp.append(" ");
    }
    strTemp.append("\r\n");                    //加入换行符
    ui->textEdit->insertPlainText(strTemp);    //写入信息
}


/*************************设置帧*************************/
void MainWindow::setupFrame(Frame ID)
{
    int tempData=0;      //临时数据
    QByteArray array;    //帧数组
    array[0]=LINMSGHEAD; //帧头
    int baudInt;         //波特率

    //根据不同数据选择控制信息码
    switch(ID)
    {
    case Conn:      array[1]=0X02;   array[3]=0X41; array[4]=0X6C;   break;      //握手连接
    case Baud:      array[1]=0X06;   array[3]=0XD6;     break;      //波特率
    case Channel:   array[1]=0X03;   array[3]=0X53;     break;      //通道
    case Imp:       array[1]=0X03;   array[3]=0X53;     break;      //主从模式
    case Length:    array[1]=0X42;   array[3]=0X55;     break;      //长度
    case Load:      array[1]=0X02;   array[3]=0X41;     break;      //加载
    case Deal:      array[1]=0X03;   array[3]=0X53;     break;      //协议
    }

    //初始化设置，写控制字
    array[2]=0X00;

    //判断如果模式为更改通道，主从，协议
    if(ID==Channel||ID==Deal||ID==Imp)
    {
        if(ui->comboBoxGallery->currentText()=="0")
        {
            array[4]=0X00;
        }
        else
        {
            array[4]=0X01;
        }

        if(ui->checkBoxImp->isChecked())
        {
            if(ui->comboBoxDeal->currentText()=="Lin1.x")
            {
                array[5]=0X01;
            }
            else if(ui->comboBoxDeal->currentText()=="Lin2.x")
            {
                array[5]=0X05;
            }
            else if(ui->comboBoxDeal->currentText()=="Auto")
            {
                array[5]=0X09;
            }
            else if(ui->comboBoxDeal->currentText()=="K-Lin")
            {
                array[5]=0X0D;
            }
        }
        else
        {
            if(ui->comboBoxDeal->currentText()=="Lin1.x")
            {
                array[5]=0X00;
            }
            else if(ui->comboBoxDeal->currentText()=="Lin2.x")
            {
                array[5]=0X04;
            }
            else if(ui->comboBoxDeal->currentText()=="Auto")
            {
                array[5]=0X08;
            }
            else if(ui->comboBoxDeal->currentText()=="K-Lin")
            {
                array[5]=0X0C;
            }
        }
    }

    //判断如果模式为更改波特率
    else if(ID==Baud)
    {
        array[4]=0X00;
        baudInt=ui->comboBoxBaud_2->currentText().toInt();//得到当前波特率
        if(baudInt>20000)
        {
            ui->statusBar->showMessage("波特率不能超过2000",3000);
            return;
        }
        array[5]=baudInt&0X00FF;//取低八位
        array[6]=baudInt>>8;    //取高八位
        array[7]=0X00;
        array[8]=0X00;
    }
    if(ID==Length)
    {
        if(ui->comboBoxGallery->currentText()=="0")
        {
            array[4]=0X00;
        }
        else
        {
            array[4]=0X01;
        }
        for(int i=5;i<69;i++)
        {
            if(i==14)
            {
                array[i]=0X08;
            }
            else
            {
                array[i]=0X00;
            }
        }
        for(int i=0;i<69;i++)
        {
            tempData+=static_cast<char>(array[i]);
        }
        array[69]=tempData&0XFF;
        array[70]=LINMSGTAIL;
    }
    else
    {
        for(int i=0;i<(BYTE)array[1]+3;i++)
        {
            tempData+=static_cast<char>(array[i]);
        }
        array[(BYTE)array[1]+3]=tempData&0XFF;
        array[(BYTE)array[1]+4]=LINMSGTAIL;
    }

    //写命令
    myCom->write(array);
    insertFlage(true,array);
}


/*************************保存数据*************************/
void MainWindow::on_pushButtonSave_clicked()
{
    Beep(0X7FF,200);
}


/*************************窗口关闭函数************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveConfig();
}


/*************************保存信息函数**********************/
void MainWindow::saveConfig()
{
    QReadWriteIni::getInstance()->strBaud=ui->comboBoxBaud->currentText();
    QReadWriteIni::getInstance()->strLinBaud=ui->comboBoxBaud_2->currentText();
    QReadWriteIni::getInstance()->strPort=ui->comboBoxPort->currentText();
    QReadWriteIni::getInstance()->strLinPact=ui->comboBoxDeal->currentText();
    if(ui->comboBoxCheck->currentText()=="无")
    {
        QReadWriteIni::getInstance()->strCheck="0";
    }
    else if(ui->comboBoxCheck->currentText()=="奇")
    {
        QReadWriteIni::getInstance()->strCheck="1";
    }
    else if(ui->comboBoxCheck->currentText()=="偶")
    {
        QReadWriteIni::getInstance()->strCheck="2";
    }
    QReadWriteIni::getInstance()->strStop=ui->comboBoxStop->currentText();
    QReadWriteIni::getInstance()->strData= ui->comboBoxData->currentText();
    QReadWriteIni::getInstance()->strLinChannel=ui->comboBoxGallery->currentText();

    if(ui->checkBoxImp->isChecked())
    {
        QReadWriteIni::getInstance()->strLinImp="1";
    }
    else
    {
        QReadWriteIni::getInstance()->strLinImp="0";
    }

    if(ui->checkBoxSleep->isChecked())
    {
        QReadWriteIni::getInstance()->strLinSleep="1";
    }
    else
    {
        QReadWriteIni::getInstance()->strLinSleep="0";
    }

    if(ui->checkBoxWake->isChecked())
    {
        QReadWriteIni::getInstance()->strLinWake="1";
    }
    else
    {
        QReadWriteIni::getInstance()->strLinWake="0";
    }
    QReadWriteIni::getInstance()->writeIni();
}
