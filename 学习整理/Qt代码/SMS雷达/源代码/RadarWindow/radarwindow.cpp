#include "radarwindow.h"
#include "ui_radarwindow.h"


/********************鼠标作用域******************/
const static int posMinX=0;
const static int posMaxX=20000;
const static int posMinY=0;
const static int posMaxY=50;
static float vdataResolttion=30;
static float hdataResolttion=17.5;


/********************构造函数******************/
RadarWindow::RadarWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RadarWindow)
{

    /*************************************添加控件********************************/
    ui->setupUi(this);                 //安装界面元素
    minButton=new QToolButton(this);   //最小化按钮
    maxButton=new QToolButton(this);   //最大化按钮
    closeButton=new QToolButton(this); //关闭按钮
    iconLabel=new QLabel(this);        //图标按钮
    labelTitle=new QLabel(this);       //软件标题
    this->setMinimumSize(900,700);     //设置最小窗口
    this->resize(QSize(900,700));      //初始化窗口显示大小
    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏
    QDesktopWidget *desktop=QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);  //程序显示在屏幕中间
    QHeaderView *headerView=ui->tableWidgetData->horizontalHeader();                      //设置列表控件等宽显示
    headerView->setSectionResizeMode(QHeaderView::Stretch);                               //设置列表控件等宽显示
    ui->tableWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);              //设置为不可编辑
    headerView=ui->tableWidgetData->verticalHeader();                                     //纵向
    headerView->setHidden(true);


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


    /*************************************提示信息********************************/
    minButton->setToolTip(tr("最小化"));
    maxButton->setToolTip(tr("最大化"));
    closeButton->setToolTip(tr("关闭"));
    ui->actionConn->setToolTip(tr("打开串口"));
    labelTitle->setText(tr("SMS雷达上位机软件"));


    /*************************************添加背景颜色*****************************/
    iconLabel->setStyleSheet("QLabel{border-image:url(:/new/prefix1/RES/tc.ico)}");
    setWindowIcon(QIcon(":/new/prefix1/RES/radar.png"));


    /*************************************初始化数据******************************/
    ok=false;             //初始值为false
    fileOk=false;         //初始值为false
    indexTarget=0;        //目标指针
    nCount=0;             //计数器
    fileOk=false;         //自动保存
    maxNormal=false;      //是否最大化
    isMousePressed=false; //鼠标是否被按下
    ui->tableWidgetData->setShowGrid(true);


    /*************************************信号与槽连接******************************/
    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));          //最小化按钮
    connect(maxButton,SIGNAL(clicked(bool)),SLOT(actionMax()));          //最大化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));      //关闭按钮
    connect(ui->actionConn,SIGNAL(clicked(bool)),this,SLOT(connCom()));  //连接串口
    ui->comboBoxPort->setCurrentIndex(2);                                //默认为COM2接口
    for(int i=0;i<6;i++)
    {
        XTarget[i]=0;     //X坐标
        YTarget[i]=0;     //Y坐标
        XSpeedTarget[i]=0;//X方向速度
        YSpeedTarget[i]=0;//Y方向速度
    }

    ui->widget->installEventFilter(this); //注册为监视对象
    QFont font("ZYSong",9);               //字体大小为宋体11号字体
    labelTitle->setFont(font);            //设置字体
    setPalette(QPalette(Qt::DownArrow));  //设置背景色
    setAutoFillBackground(true);          //设置背景色

    //slider设置初始值
    ui->labelH->setText("17.5");
    ui->labelV->setText("30");
    ui->horizontalSlider->setValue(300);
    ui->horizontalSlider_2->setValue(175);

    //设置类型选择器ID
    ui->label->setObjectName("label1");
    ui->label_2->setObjectName("label2");
    ui->label_3->setObjectName("label3");
    ui->label_4->setObjectName("label4");
    ui->label_5->setObjectName("label5");
    ui->widget->setObjectName("myWidget");

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


/********************析构函数******************/
RadarWindow::~RadarWindow()
{
    delete ui;
}


/********************连接串口******************/
void RadarWindow::connCom()
{
    if(ui->actionConn->text()==tr("关闭串口"))
    {
        //将控件设置为可用
        ui->comboBoxPort->setEnabled(true);
        ui->comboBoxBaud->setEnabled(true);
        ui->comboBoxCheck->setEnabled(true);
        ui->comboBoxData->setEnabled(true);
        ui->comboBoxStop->setEnabled(true);
        ui->actionConn->setEnabled(true);
        ui->actionConn->setText(tr("打开串口"));
        ui->pushButtonSave->setText(tr("保存"));
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

            ok=false;
        }
        else
        {
            return;
        }
    }
    else
    {
        QString portName=ui->comboBoxPort->currentText();

        myCom=new QextSerialPort(portName);//定义串口对象，并传递参数对其进行初始化

        if(myCom->isOpen())                       //如果串口已经打开，返回
        {
            return;
        }
        else
        {
            ok=myCom->open(QIODevice::ReadWrite);  //以可读可写方式打开串口
            /*************************设置比特率*************************/
            if(ui->comboBoxBaud->currentText()==tr("9600"))
            {
                myCom->setBaudRate(BAUD9600);

            }
            else if(ui->comboBoxBaud->currentText()==tr("115200"))
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
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("打开失败"),QPixmap(":/new/prefix1/RES/ok.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
        else
        {
            //将控件设置为不可用
            ui->actionConn->setText(tr("关闭串口"));
            ui->comboBoxPort->setEnabled(false);
            ui->comboBoxBaud->setEnabled(false);
            ui->comboBoxCheck->setEnabled(false);
            ui->comboBoxData->setEnabled(false);
            ui->comboBoxStop->setEnabled(false);
        }
    }
}


/********************读取数据******************/
void RadarWindow::readCom()
{
    QByteArray temp=myCom->readAll(); //读取串口数据

    for(int i=0;i<temp.size();)
    {
        if(temp[i]==0XAA&&temp[i+1]==0XAA&&temp[i+19]==0X55&&temp[i+20]==0X55)
        {
            if(temp[i+2]==0X10&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[0]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[0]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[0]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[0]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }
            if(temp[i+2]==0X11&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[1]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[1]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[1]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[1]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }
            if(temp[i+2]==0X12&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[2]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[2]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[2]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[2]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }
            if(temp[i+2]==0X13&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[3]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[3]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[3]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[3]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }
            if(temp[i+2]==0X14&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[4]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[4]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[4]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[4]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }
            if(temp[i+2]==0X15&&temp[i+3]==0X05&&temp[i+13]==0x00)
            {
                XTarget[5]=((BYTE)(temp[i+7]&0X1F)*256+(BYTE)temp[i+6])*0.032;                               //X坐标
                YTarget[5]=((((BYTE)temp[i+9]&0X0F)*1024+(BYTE)temp[i+8]*4+(BYTE)(temp[i+7])/64)-8192)*0.016;//Y坐标
                XSpeedTarget[5]=(((BYTE)(temp[i+10]&0X7F)*16+(BYTE)(temp[i+9])/16)-1024)*0.1;                //X方向速度
                YSpeedTarget[5]=(((BYTE)(temp[i+12]&0X03)*512+(BYTE)(temp[i+11])*2+(BYTE)(temp[i+10])/128)-1024)*0.1; //Y方向速度
            }

            if(temp[i+2]==0X01&&temp[i+3]==0X05)
            {
                indexTarget=BYTE(temp[i+6]);//目标数目
            }

            ui->tableWidgetData->setRowCount(indexTarget);
            //写到控件中
            for(int i=0;i<indexTarget;i++)
            {
                ui->tableWidgetData->setItem(i,0,new QTableWidgetItem(QString("%1").arg(i+1)));
                ui->tableWidgetData->setItem(i,1,new QTableWidgetItem(QString::number(XTarget[i],'f','1')));
                ui->tableWidgetData->setItem(i,2,new QTableWidgetItem(QString::number(YTarget[i],'f',1)));
                ui->tableWidgetData->setItem(i,3,new QTableWidgetItem(QString::number(XSpeedTarget[i],'f',1)));
                ui->tableWidgetData->setItem(i,4,new QTableWidgetItem(QString::number(YSpeedTarget[i],'f',1)));
            }

            QByteArray tempTemp=temp.mid(i,21);
            i+=21;
            QString str;
            QTime time;
            str.prepend(tempTemp.toHex());              //转16进制变成字符串
            if(ui->pushButtonSave->text()=="停止保存"&&fileOk==false)
            {
                fileSave=new QFile("look"+time.currentTime().toString("hhmmss")+".txt");  //保存到桌面
                fileOk=fileSave->open(QIODevice::WriteOnly|QFile::Text);         //以只写方式打开
            }
            str.append("\r\n"); //加入换行符
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
        }
        else
        {
            i++;
        }
    }
}


/********************定时器*******************/
void RadarWindow::timeUpdate()
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


/********************重写函数*****************/
bool RadarWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->widget&&event->type()==QEvent::Paint)
    {
        paintImage();
    }
    return QWidget::eventFilter(watched,event);
}


/********************重写画图函数**************/
void RadarWindow::paintEvent(QPaintEvent *event)
{
    int width=this->width();
    /*************************************加载位置********************************/
    minButton->setGeometry(width-100,6,30,30);
    maxButton->setGeometry(width-68,6,30,30);
    closeButton->setGeometry(width-36,6,30,30);
    QPainter painterOne(this);
    //设置画笔为灰色
    QPen pen(Qt::gray,5,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painterOne.setPen(pen);
    painterOne.drawLine(0,0,0,this->height());
    painterOne.drawLine(0,this->height(),this->width(),this->height());
    painterOne.drawLine(0,0,this->width(),0);
    painterOne.drawLine(this->width(),0,this->width(),this->height());
}


/********************绘图函数*****************/
void RadarWindow::paintImage()
{
    QPainter painter(ui->widget);
    QPen pener(Qt::white,1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(pener);
    painter.setRenderHint(QPainter::Antialiasing,true);       //将坐标系的该点变成原点坐标
    painter.translate(0.5*ui->widget->width(),ui->widget->height());
    float Total=ui->widget->height();
    float totalWidth=ui->widget->width();

    //画左边直线
    painter.drawLine(-80,0,-80,-Total);


    //画右边直线
    painter.drawLine(80,0,80,-Total);


    //画左边直线
    painter.drawLine(-240,0,-240,-Total);


    //画右边直线
    painter.drawLine(240,0,240,-Total);

    //填充图形
    QPolygon polyGon;
    polyGon.clear();
    polyGon<<QPoint(-80,0);
    polyGon<<QPoint(80,0);
    polyGon<<QPoint(80,-Total);
    polyGon<<QPoint(-80,-Total);
    painter.setBrush(Qt::darkGray);
    painter.drawConvexPolygon(polyGon);

    polyGon.clear();
    polyGon<<QPoint(-80,0);
    polyGon<<QPoint(-240,0);
    polyGon<<QPoint(-240,-Total);
    polyGon<<QPoint(-80,-Total);
    painter.setBrush(Qt::darkGray);
    painter.drawConvexPolygon(polyGon);

    polyGon.clear();
    polyGon<<QPoint(80,0);
    polyGon<<QPoint(240,0);
    polyGon<<QPoint(240,-Total);
    polyGon<<QPoint(80,-Total);
    painter.setBrush(Qt::darkGray);
    painter.drawConvexPolygon(polyGon);

    if(maxNormal)
    {
        //画左边直线
        painter.drawLine(-400,0,-400,-Total);

        //画右边直线
        painter.drawLine(400,0,400,-Total);

        polyGon.clear();
        polyGon<<QPoint(240,0);
        polyGon<<QPoint(400,0);
        polyGon<<QPoint(400,-Total);
        polyGon<<QPoint(240,-Total);
        painter.setBrush(Qt::darkGray);
        painter.drawConvexPolygon(polyGon);

        polyGon.clear();
        polyGon<<QPoint(-240,0);
        polyGon<<QPoint(-400,0);
        polyGon<<QPoint(-400,-Total);
        polyGon<<QPoint(-240,-Total);
        painter.setBrush(Qt::darkGray);
        painter.drawConvexPolygon(polyGon);
    }


    QMatrix matrix;
    matrix.scale(0.5,0.5);
    imgOther.load(":/new/prefix1/RES/car/car20.png");
    imgOther=imgOther.transformed(matrix);
    painter.drawImage(-170,-215,imgOther);
    imgFrond.load(":/new/prefix1/RES/car/car22.png");
    imgFrond=imgFrond.transformed(matrix);

    //加载图像
    if(indexTarget!=0)
    {
        if(indexTarget==1)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }
        }
        if(indexTarget==2)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }
            if(YSpeedTarget[1]>0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[1]<0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgFrond);
            }
        }
        if(indexTarget==3)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[1]>0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[1]<0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[2]>0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[2]<0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgFrond);
            }
        }

        if(indexTarget==4)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[1]>0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[1]<0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[2]>0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[2]<0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[3]>0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[3]<0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgFrond);
            }
        }
        if(indexTarget==5)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }
            if(YSpeedTarget[1]>0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[1]<0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgFrond);
            }
            if(YSpeedTarget[2]>0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[2]<0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgFrond);
            }
            if(YSpeedTarget[3]>0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[3]<0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgFrond);
            }
            if(YSpeedTarget[4]>0)
            {
                painter.drawImage(-170+YTarget[4]*totalWidth/hdataResolttion,-360-XTarget[4]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[4]<0)
            {
                painter.drawImage(-170+YTarget[4]*totalWidth/hdataResolttion,-360-XTarget[4]*Total/vdataResolttion,imgFrond);
            }

        }
        if(indexTarget==6)
        {
            if(YSpeedTarget[0]>0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[0]<0)
            {
                painter.drawImage(-170+YTarget[0]*totalWidth/hdataResolttion,-360-XTarget[0]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[1]>0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[1]<0)
            {
                painter.drawImage(-170+YTarget[1]*totalWidth/hdataResolttion,-360-XTarget[1]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[2]>0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[2]<0)
            {
                painter.drawImage(-170+YTarget[2]*totalWidth/hdataResolttion,-360-XTarget[2]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[3]>0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[3]<0)
            {
                painter.drawImage(-170+YTarget[3]*totalWidth/hdataResolttion,-360-XTarget[3]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[4]>0)
            {
                painter.drawImage(-170+YTarget[4]*totalWidth/hdataResolttion,-360-XTarget[4]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[4]<0)
            {
                painter.drawImage(-170+YTarget[4]*totalWidth/hdataResolttion,-360-XTarget[4]*Total/vdataResolttion,imgFrond);
            }

            if(YSpeedTarget[5]>0)
            {
                painter.drawImage(-170+YTarget[5]*totalWidth/hdataResolttion,-360-XTarget[5]*Total/vdataResolttion,imgOther);
            }
            else if(YSpeedTarget[5]<0)
            {
                painter.drawImage(-170+YTarget[5]*totalWidth/hdataResolttion,-360-XTarget[5]*Total/vdataResolttion,imgFrond);
            }
        }
    }
    update();
}


/***************最小化************************/
void RadarWindow::actionMin()
{
    showMinimized();
}


/***************最大化************************/
void RadarWindow::actionMax()
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
        //maxButton->setIcon(QIcon(":/new/prefix1/RES/maxMin.png"));
        maxButton->setIcon(normalPix);
    }
}


/***************关闭**************************/
void RadarWindow::actionClose()
{
    close();    //关闭

}


/***************鼠标移动**********************/
void RadarWindow::mouseMoveEvent(QMouseEvent *event)
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


/***************鼠标点击**********************/
void RadarWindow::mousePressEvent(QMouseEvent *event)
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


/***************鼠标释放**********************/
void RadarWindow::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressed=false;
}


/***************自动保存**********************/
void RadarWindow::on_pushButtonSave_clicked()
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


/***************纵向像素移动*******************/
void RadarWindow::on_horizontalSlider_sliderMoved(int position)
{
    vdataResolttion=position/10.;
    ui->labelV->setText(tr("%1").arg(position/10.));
}


/***************横向像素移动********************/
void RadarWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    hdataResolttion=position/10.;
    ui->labelH->setText(tr("%1").arg(position/10.));
}


/***************纵向像素值改变******************/
void RadarWindow::on_horizontalSlider_valueChanged(int value)
{
    vdataResolttion=value/10.;
    ui->labelV->setText(tr("%1").arg(vdataResolttion));
}


/***************横向像素值改变******************/
void RadarWindow::on_horizontalSlider_2_valueChanged(int value)
{
    hdataResolttion=value/10.;
    ui->labelH->setText(tr("%1").arg(hdataResolttion));
}
