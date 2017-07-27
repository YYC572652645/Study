#include "mainwindow.h"
#include "ui_mainwindow.h"

/********************构造函数******************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->widgetPaint->installEventFilter(this);
    this->setMinimumSize(700,600);
    this->setWindowTitle(tr("上位机测试软件"));
    setWindowIcon(QIcon(":/new/prefix1/images/qcom.ICO"));
    setWindowIconText(tr("上位机测试软件"));
    ui->actionClearPort->setEnabled(false);
    ui->actionClosePort->setEnabled(false);
    ui->actionAutoSave->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    ui->checkBoxSendHex->setEnabled(false);
    ui->lineEditSend->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->checkBoxSendCon->setEnabled(false);
    ui->spinBox->setValue(200);
    this->setIconSize(QSize(30,30));
    ok=false;
    fileOk=false;

}


/********************析构函数******************/
MainWindow::~MainWindow()
{
    delete ui;
}


/********************重写函数******************/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->widgetPaint&&event->type()==QEvent::Paint)
    {
        paintImage();
    }
    if(watched==ui->widgetPaint&&event->type()==QEvent::MouseButtonDblClick)
    {
        mouseDoubleClick();
    }
    return QWidget::eventFilter(watched,event);
}


/********************画图函数********************/
void MainWindow::paintImage()
{
    QImage img;
    img.load(":/new/prefix1/car/car3.png"); //加载图片
    QPainter painter(ui->widgetPaint);      //在widget上绘制
    painter.setBrush(Qt::black);            //设置画刷
    painter.drawRect(0,0,ui->widgetPaint->width(),ui->widgetPaint->height()); //画一个矩形域，与控件大小相同
    int pointX=ui->widgetPaint->width()*0.5-0.55*img.width();                 //汽车图片的横坐标
    int pointY=ui->widgetPaint->height()*0.5-0.6*img.height();                //汽车图片纵坐标
    painter.translate(pointX+0.45*img.width()+10,pointY+0.34*img.height()-10);//将该点变为直角坐标系的原点


    /*********************************************************包络图第一层******************************************************/

    /*****************************设置参数********************************/
    int valueX=-150;
    int valueY=-150;
    int valueArea=300;
    int startAngle=60;
    int rangeAngle=60;


    QRadialGradient radiaGradient(0,0,150,0,0);
    radiaGradient.setColorAt(0.1,QColor(200,0,0,100));
    radiaGradient.setColorAt(0.7,QColor(200,200,0,100));
    radiaGradient.setColorAt(0.9,QColor(30,144,255,100));
    painter.setBrush(radiaGradient);
    painter.setPen(QColor(30,144,255,125));

    /*****************************画车前方包络图********************************/
    QRect rectLeft(valueX,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerLeft(0,0);                          //圆弧的圆心坐标
    QPainterPath myPathLeft;                          //设置路径
    myPathLeft.moveTo(centerLeft);                    //将点移动到圆心
    myPathLeft.arcTo(rectLeft,startAngle+15,60);      //从圆心画圆弧
    painter.drawPath(myPathLeft);                     //画出图形


    radiaGradient.setCenter(30,-9);
    radiaGradient.setFocalPoint(30,-9);
    painter.setBrush(radiaGradient);
    painter.setBrush(radiaGradient);        //设置画刷
    QRect rectLeftCenter(valueX+30,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerLeftCenter(30,-9);                           //圆弧的圆心坐标
    QPainterPath myPathLeftCenter;                             //设置路径
    myPathLeftCenter.moveTo(centerLeftCenter);                 //将点移动到圆心
    myPathLeftCenter.arcTo(rectLeftCenter,startAngle,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathLeftCenter);                          //画出图形


    radiaGradient.setCenter(60,-9);
    radiaGradient.setFocalPoint(60,-9);
    painter.setBrush(radiaGradient);
    QRect rectRightCenter(valueX+60,valueY,valueArea,valueArea);   //画一个矩形域
    QPointF centerRightCenter(60,-9);                              //圆弧的圆心坐标
    QPainterPath myPathRightCenter;                                //设置路径
    myPathRightCenter.moveTo(centerRightCenter);                   //将点移动到圆心
    myPathRightCenter.arcTo(rectRightCenter,startAngle,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathRightCenter);                           //画出图形


    radiaGradient.setCenter(88,1);
    radiaGradient.setFocalPoint(88,1);
    painter.setBrush(radiaGradient);
    QRect rectRight(valueX+88,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerRight(88,1);                            //圆弧的圆心坐标
    QPainterPath myPathRight;                             //设置路径
    myPathRight.moveTo(centerRight);                      //将点移动到圆心
    myPathRight.arcTo(rectRight,startAngle-15,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathRight);





    /*****************************设置参数********************************/
    valueX=-150;
    valueY=-150;
    valueArea=300;



    /*****************************画车后方包络图********************************/
    QPainter painterTail(ui->widgetPaint);
    painterTail.translate(pointX+0.45*img.width()+10,pointY+0.9*img.height()-10);
    painterTail.setPen(QColor(30,144,255,125));


    radiaGradient.setCenter(0,0);
    radiaGradient.setFocalPoint(0,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRight(valueX,valueY,valueArea,valueArea);         //画一个矩形域
    QPointF centerTailRight(0,0);                                   //圆弧的圆心坐标
    QPainterPath myPathTailRight;                                   //设置路径
    myPathTailRight.moveTo(centerTailRight);                        //将点移动到圆心
    myPathTailRight.arcTo(rectTailRight,180+startAngle,rangeAngle); //从圆心画圆弧
    painterTail.drawPath(myPathTailRight);                          //画出图形


    radiaGradient.setCenter(30,0);
    radiaGradient.setFocalPoint(30,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailLeftCenter(valueX+30,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailLeftCenter(30,0);                                       //圆弧的圆心坐标
    QPainterPath myPathTailLeftCenter;                                        //设置路径
    myPathTailLeftCenter.moveTo(centerTailLeftCenter);                        //将点移动到圆心
    myPathTailLeftCenter.arcTo(rectTailLeftCenter,180+startAngle,rangeAngle); //从圆心画圆弧
    painterTail.drawPath(myPathTailLeftCenter);                               //画出图形


    radiaGradient.setCenter(60,0);
    radiaGradient.setFocalPoint(60,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRightCenter(valueX+60,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailRightCenter(60,0);                                       //圆弧的圆心坐标
    QPainterPath myPathTailRightCenter;                                        //设置路径
    myPathTailRightCenter.moveTo(centerTailRightCenter);                       //将点移动到圆心
    myPathTailRightCenter.arcTo(rectTailRightCenter,180+startAngle,rangeAngle);//从圆心画圆弧
    painterTail.drawPath(myPathTailRightCenter);                               //画出图形


    radiaGradient.setCenter(90,0);
    radiaGradient.setFocalPoint(90,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailLeft(valueX+90,valueY,valueArea,valueArea);        //画一个矩形域
    QPointF centerTailLeft(90,0);                                    //圆弧的圆心坐标
    QPainterPath myPathTailLeft;                                     //设置路径
    myPathTailLeft.moveTo(centerTailLeft);                           //将点移动到圆心
    myPathTailLeft.arcTo(rectTailLeft,180+startAngle,rangeAngle);    //从圆心画圆弧
    painterTail.drawPath(myPathTailLeft);                            //画出图形






    /*****************************设置参数********************************/
    valueX=-200;
    valueY=-200;
    valueArea=400;
    startAngle=60;
    rangeAngle=60;


    /*****************************画车左方包络图********************************/
    QPainter painterLeft(ui->widgetPaint);
    painterLeft.translate(pointX+0.44*img.width()+6,pointY+0.45*img.height()-10);
    painterLeft.setPen(QColor(30,144,255,125));

    radiaGradient.setCenter(0,-30);
    radiaGradient.setFocalPoint(0,-30);
    painterLeft.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarLeft(valueX,valueY-30,valueArea,valueArea);          //画一个矩形域
    QPointF centerCarLeft(0,-30);                                     //圆弧的圆心坐标
    QPainterPath myPathCarLeft;                                       //设置路径
    myPathCarLeft.moveTo(centerCarLeft);                              //将点移动到圆心
    myPathCarLeft.arcTo(rectCarLeft,90+startAngle,rangeAngle);        //从圆心画圆弧
    painterLeft.drawPath(myPathCarLeft);                              //画出图形


    radiaGradient.setCenter(0,180);
    radiaGradient.setFocalPoint(0,180);
    painterLeft.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarLeftLast(valueX,valueY+180,valueArea,valueArea);     //画一个矩形域
    QPointF centerCarLeftLast(0,180);                                 //圆弧的圆心坐标
    QPainterPath myPathCarLeftLast;                                   //设置路径
    myPathCarLeftLast.moveTo(centerCarLeftLast);                      //将点移动到圆心
    myPathCarLeftLast.arcTo(rectCarLeftLast,90+startAngle,rangeAngle);//从圆心画圆弧
    painterLeft.drawPath(myPathCarLeftLast);                          //画出图形




    /*****************************设置参数********************************/
    valueX=-200;
    valueY=-200;
    valueArea=400;

    /*****************************画车右方包络图********************************/
    QPainter painterRight(ui->widgetPaint);
    painterRight.translate(pointX+0.61*img.width()+6,pointY+0.45*img.height()-10);
    painterRight.setPen(QColor(30,144,255,125));


    radiaGradient.setCenter(0,-30);
    radiaGradient.setFocalPoint(0,-30);
    painterRight.setBrush(radiaGradient);                               //设置画刷
    QRect rectCarRight(valueX,valueY-30,valueArea,valueArea);           //画一个矩形域
    QPointF centerCarRight(0,-30);                                      //圆弧的圆心坐标
    QPainterPath myPathCarRight;                                        //设置路径
    myPathCarRight.moveTo(centerCarRight);                              //将点移动到圆心
    myPathCarRight.arcTo(rectCarRight,270+startAngle,rangeAngle);       //从圆心画圆弧
    painterRight.drawPath(myPathCarRight);                              //画出图形


    radiaGradient.setCenter(0,180);
    radiaGradient.setFocalPoint(0,180);
    painterRight.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarRightLast(valueX,valueY+180,valueArea,valueArea);       //画一个矩形域
    QPointF centerCarRightLast(0,180);                                   //圆弧的圆心坐标
    QPainterPath myPathCarRightLast;                                     //设置路径
    myPathCarRightLast.moveTo(centerCarRightLast);                       //将点移动到圆心
    myPathCarRightLast.arcTo(rectCarRightLast,270+startAngle,rangeAngle);//从圆心画圆弧
    painterRight.drawPath(myPathCarRightLast);                           //画出图形


    QPainter painterLast(ui->widgetPaint);                            //在widget上绘制
    painterLast.drawImage(pointX,pointY,img);                         //将图片加载到界面上
    update();
}


/********************双击鼠标********************/
void MainWindow::mouseDoubleClick()
{
    PaintWidget *paint=new PaintWidget();
    paint->showFullScreen();
}


/********************发送数据******************/
void MainWindow::sengMessage()
{
    QByteArray buf;
    if(ui->checkBoxSendHex->isChecked())
    {
        QString str;
        bool sendOK;
        char data;
        QStringList list;
        str = ui->lineEditSend->text();
        list = str.split(" ");
        for(int i = 0; i < list.count(); i++)
        {
            if(list.at(i) == " ")
            {
                continue;
            }
            if(list.at(i).isEmpty())
            {
                continue;
            }
            data = (char)list.at(i).toInt(&sendOK, 16);
            if(!sendOK)
            {
                ui->statusBar->showMessage(tr(""));
                if(this->sendTimer->isActive())
                {
                    this->sendTimer->stop();
                }
                QMessageBox::information(this, tr("提示消息"), tr("输入的数据格式有错误！"), QMessageBox::Ok);
                return;
            }
            buf.append(data);
        }
    }
    else
    {
#if QT_VERSION < 0x050000
        buf = ui->lineEditSend->text().toAscii();
#else
        buf = ui->lineEditSend->text().toLocal8Bit();
#endif
    }
    //发送数据
    myCom->write(buf);
    ui->statusBar->showMessage(tr("发送数据成功"));
}


/********************连接串口******************/
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


        myCom->setFlowControl(FLOW_OFF); //设置数据流控制
        myCom->setTimeout(TIME_OUT);     //设置延时


        if(!ok)
        {
            ui->statusBar->showMessage(tr("打开失败"),3000);
            return;
        }
        else
        {
            //将控件设置为可用
            ui->actionAutoSave->setEnabled(true);
            ui->actionClosePort->setEnabled(true);
            ui->actionClearPort->setEnabled(true);
            ui->pushButtonSend->setEnabled(true);
            ui->checkBoxSendHex->setEnabled(true);
            ui->lineEditSend->setEnabled(true);
            ui->checkBoxSendCon->setEnabled(true);

            //将控件设置为不可用
            ui->actionAddPort->setEnabled(false);
            ui->actionOpenPort->setEnabled(false);
            ui->comboBoxPort->setEnabled(false);
            ui->comboBoxBaud->setEnabled(false);
            ui->comboBoxCheck->setEnabled(false);
            ui->comboBoxData->setEnabled(false);
            ui->comboBoxStop->setEnabled(false);

            ui->statusBar->showMessage(tr("打开串口成功"),3000);
        }

        this->timer=new QTimer(this);                                    //定义一个定时器
        connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
        timer->start(50);                                                //0.05秒调用一次
    }
}


/********************读取数据******************/
void MainWindow::readCom()
{
    QByteArray temp=myCom->readAll(); //读取串口数据

    for(int i=0;i<temp.size();)
    {

        if(temp[i]==0XAA&&temp[i+1]==0XAA&&temp[i+12]==0X55&&temp[i+13]==0X55)   //判断出障碍高度的信息
        {
            QByteArray tempTemp=temp.mid(i,14);
            i+=14;
            QString str;
            QTime time;
            str.prepend(tempTemp.toHex());              //转16进制变成字符串
            if(ui->actionAutoSave->text()=="停止保存"&&fileOk==false)
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


/********************定时器********************/
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


/********************自动保存********************/
void MainWindow::on_actionAutoSave_triggered()
{
    if(!ok)
    {
        return;
    }
    if(ui->actionAutoSave->text()==tr("停止保存"))
    {
        ui->actionAutoSave->setText(tr("自动保存"));

        if(fileOk)
        {
            fileSave->close();
            delete fileSave;
            fileOk=false;

        }
    }
    else if (ui->actionAutoSave->text()==tr("自动保存"))
    {
        ui->actionAutoSave->setText(tr("停止保存"));
    }
}


/********************打开串口********************/
void MainWindow::on_actionOpenPort_triggered()
{
    connCom();
}


/********************关闭串口********************/
void MainWindow::on_actionClosePort_triggered()
{
    //将控件设置为可用
    ui->comboBoxPort->setEnabled(true);
    ui->comboBoxBaud->setEnabled(true);
    ui->comboBoxCheck->setEnabled(true);
    ui->comboBoxData->setEnabled(true);
    ui->comboBoxStop->setEnabled(true);
    ui->actionOpenPort->setEnabled(true);
    ui->pushButtonSend->setEnabled(false);
    ui->checkBoxSendHex->setEnabled(false);
    ui->lineEditSend->setEnabled(false);
    ui->actionAddPort->setEnabled(true);
    ui->actionClearPort->setEnabled(false);
    ui->actionClosePort->setEnabled(false);
    ui->actionAutoSave->setEnabled(false);
    ui->pushButtonSend->setEnabled(false);
    ui->checkBoxSendHex->setEnabled(false);
    ui->lineEditSend->setEnabled(false);
    ui->spinBox->setEnabled(false);
    ui->checkBoxSendCon->setEnabled(false);
    ui->actionAutoSave->setText(tr("自动保存"));


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
        delete myCom;
        myCom = NULL;
        ui->statusBar->showMessage(tr("关闭成功"),3000);
        ok=false;
    }
    else
    {
        return;
    }
}


/********************退出程序********************/
void MainWindow::on_actionExit_triggered()
{
    this->close();
}


/********************清空串口********************/
void MainWindow::on_actionClearPort_triggered()
{
    myCom->flush();
}


/********************添加串口********************/
void MainWindow::on_actionAddPort_triggered()
{
    bool addOk = false;
    QString portName;

    portName = QInputDialog::getText(this, tr("添加串口"), tr("端口名称"), QLineEdit::Normal, 0, &addOk);
    if(addOk && !portName.isEmpty())
    {
        ui->comboBoxPort->addItem(portName);
        ui->statusBar->showMessage(tr("添加成功"),3000);
    }
}


/********************发送数据********************/
void MainWindow::on_pushButtonSend_clicked()
{

    if(ui->pushButtonSend->text()=="停止发送")
    {
        ui->pushButtonSend->setText(tr("发送指令"));
        if(this->sendTimer->isActive())
        {
            this->sendTimer->stop();
        }
    }
    else
    {
        if(ui->checkBoxSendCon->isChecked())
        {
            this->sendTimer=new QTimer(this);                                    //定义一个定时器
            connect(sendTimer,SIGNAL(timeout()),this,SLOT(sengMessage()));       //设置
            sendTimer->start(ui->spinBox->value());
            ui->pushButtonSend->setText(tr("停止发送"));
            return;
        }
        else
        {
            sengMessage();
        }
        ui->pushButtonSend->setText(tr("发送指令"));

    }

}


/********************连续发送数据********************/
void MainWindow::on_checkBoxSendCon_clicked()
{
    if(ui->checkBoxSendCon->isChecked())
    {
        ui->spinBox->setEnabled(true);
        ui->statusBar->showMessage(tr("启用连续发送"),3000);//检查是否有数据，如有则启动定时器
    }
    else
    {
        ui->spinBox->setEnabled(false);
        ui->statusBar->showMessage(tr("停止连续发送"),3000);//若定时器已经启动则关闭它
    }
}


