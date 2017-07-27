/***************************************************
 *
 *  名称：--------------------------------------------
 *  串口设置
 *
 *
 *  功能：--------------------------------------------
 *  1.使用UartAny Lin转串口调试工具对52414自动分配地址
 *  2.通过发送指令获取ID为5，6，7，8的探头数据
 *  3.通过计算出的AS，BS，CS，DS的数据来查表，查处XY坐标位置
 *  4.将获取到的数据显示在表格中，ID，LEN，DATA
 *
 *
 *  目的：---------------------------------------------
 *  能够灵活的发送指令，并且能够自动分配地址，并且能够查出XY坐标
 *
 * **************************************************/


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <memory>
using namespace std;

static int  countData=0;     //计数器
static int  countRow=0;      //计数器
static float AS=0;           //5号探头距离
static float BS=0;           //6号探头距离
static float CS=0;           //7号探头距离
static float DS=0;           //8号探头距离
static bool recvFive=false;  //接收数据标志位
static bool recvSix=false;   //接收数据标志位
static bool recvSeven=false; //接收数据标志位
static bool recvEight=false; //接收数据标志位

/*************************构造函数*********************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ok=false;        //打开串口标志位
    handShake=false; //握手连接标志位
    sendFlage=false; //发送标志位
    ui->tabWidget->setCurrentIndex(0);

    //把表头上面去掉
    ui->tableWidgetMtask->horizontalHeader()->setVisible(false);
    ui->tableWidgetMtask->verticalHeader()->setVisible(false);
    ui->tableWidgetData->setShowGrid(false);

    //把表头上面去掉
    ui->tableWidgetData->verticalHeader()->setVisible(false);

    //设置列表控件等宽显示
    QHeaderView *headerView=ui->tableWidgetMtask->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置列表控件等高显示
    headerView=ui->tableWidgetMtask->verticalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置无边框
    ui->tableWidgetMtask->setFrameShape(QFrame::NoFrame);

    //设置单行选中
    ui->tableWidgetData->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetData->setSelectionMode(QAbstractItemView::SingleSelection);

    //控件循环添加
    for(int i=0;i<ui->tableWidgetMtask->rowCount();i++)
    {
        widgetMessage[i]=new QWidget(this);
        hboxLayoutMessage[i]=new QHBoxLayout();
        checkBoxMessage[i]=new QCheckBox(this);  //指令
        lineEditMessage[i]=new QLineEdit(this);
        lineEditNumber[i]=new QLineEdit(this);
        lineEditCount[i]=new QLineEdit(this);
        hboxLayoutMessage[i]->addWidget(checkBoxMessage[i]);
        hboxLayoutMessage[i]->addWidget(lineEditNumber[i]);
        hboxLayoutMessage[i]->addWidget(lineEditMessage[i]);
        hboxLayoutMessage[i]->addWidget(lineEditCount[i]);
        hboxLayoutMessage[i]->setAlignment(widgetMessage[i],Qt::AlignCenter);
        widgetMessage[i]->setLayout(hboxLayoutMessage[i]);
        ui->tableWidgetMtask->setCellWidget(i,0,widgetMessage[i]);
    }

    //把表头上面去掉
    ui->tableWidgetStask->horizontalHeader()->setVisible(false);
    ui->tableWidgetStask->verticalHeader()->setVisible(false);

    //设置列表控件等宽显示
    headerView=ui->tableWidgetStask->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置列表控件等高显示
    headerView=ui->tableWidgetStask->verticalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置列表控件等宽显示
    headerView=ui->tableWidgetData->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);

    //设置无边框
    ui->tableWidgetStask->setFrameShape(QFrame::NoFrame);

    //控件循环添加
    for(int i=0;i<ui->tableWidgetStask->rowCount();i++)
    {
        widgetSMessage[i]=new QWidget(this);
        hboxLayoutSMessage[i]=new QHBoxLayout();
        checkBoxSMessage[i]=new QCheckBox(this);
        lineEditSMessage[i]=new QLineEdit(this);
        lineEditSNumber[i]=new QLineEdit(this);
        hboxLayoutSMessage[i]->addWidget(checkBoxSMessage[i]);
        hboxLayoutSMessage[i]->addWidget(lineEditSNumber[i]);
        hboxLayoutSMessage[i]->addWidget(lineEditSMessage[i]);
        hboxLayoutSMessage[i]->setAlignment(widgetSMessage[i],Qt::AlignCenter);
        widgetSMessage[i]->setLayout(hboxLayoutSMessage[i]);
        ui->tableWidgetStask->setCellWidget(i,0,widgetSMessage[i]);
    }

    //为复选框添加信号与槽
    for(int i=0;i<8;i++)
    {
        connect(checkBoxSMessage[i],SIGNAL(clicked(bool)),this,SLOT(on_checkBoxCheck_clicked()));
    }

    //设置控件是否可用
    ui->pushButtonConn->setEnabled(false);
    ui->comboBoxBaud_2->setEnabled(false);
    ui->comboBoxDeal->setEnabled(false);
    ui->comboBoxGallery->setEnabled(false);
    ui->checkBoxImp->setEnabled(false);
    ui->checkBoxSleep->setEnabled(false);
    ui->checkBoxWake->setEnabled(false);
    ui->checkBoxCheck->setEnabled(false);
    ui->tableWidgetMtask->setEnabled(false);
    ui->tableWidgetStask->setEnabled(false);
    ui->pushButtonStart->setEnabled(false);
    ui->checkBoxLength->setEnabled(false);
    ui->spinBoxTime->setEnabled(false);
    ui->checkBoxImp->setChecked(true);
    ui->pushButtonAddress->setEnabled(false);
    ui->pushButtonRead->setEnabled(false);
    ui->lineEditEight->setEnabled(false);
    ui->lineEditSeven->setEnabled(false);
    ui->lineEditSix->setEnabled(false);
    ui->lineEditFive->setEnabled(false);
    ui->comboBoxNumber->setEnabled(false);

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

    mainThread=new MainThread(this);
    xmlData=new QtXml();
    xmlThread=new XmlThread(xmlData);
    xmlThread->run();
    xmlData->readXML();
    ui->comboBoxBaud->setCurrentText(xmlData->strBaud);
    ui->comboBoxBaud_2->setCurrentText(xmlData->strLinBaud);
    ui->comboBoxPort->setCurrentText(xmlData->strPort);
    ui->comboBoxDeal->setCurrentText(xmlData->strLinPact);
    if(xmlData->strCheck==STRINGZERO)
    {
        ui->comboBoxCheck->setCurrentText(NOCHECK);
    }
    else if(xmlData->strCheck==STRINGONE)
    {
        ui->comboBoxCheck->setCurrentText(ODDCHECK);
    }
    else if(xmlData->strCheck==STRINGTWO)
    {
        ui->comboBoxCheck->setCurrentText(EVENCHECK);
    }
    ui->comboBoxStop->setCurrentText(xmlData->strStop);
    ui->comboBoxData->setCurrentText(xmlData->strData);
    ui->comboBoxGallery->setCurrentText(xmlData->strLinChannel);
    if(xmlData->strLinImp==STRINGONE)
    {
        ui->checkBoxImp->setChecked(true);
    }
    else
    {
        ui->checkBoxImp->setChecked(false);
    }
    if(xmlData->strLinSleep==STRINGONE)
    {
        ui->checkBoxSleep->setChecked(true);
    }
    else
    {
        ui->checkBoxSleep->setChecked(false);
    }
    if(xmlData->strLinWake==STRINGONE)
    {
        ui->checkBoxWake->setChecked(true);
    }
    else
    {
        ui->checkBoxWake->setChecked(false);
    }
    for(int i=0;i<8;i++)
    {
        lineEditCount[i]->setText(xmlData->strLinMCount[i]);
        lineEditMessage[i]->setText(xmlData->strLinMData[i]);
        lineEditNumber[i]->setText(xmlData->strLinMID[i]);
        lineEditSMessage[i]->setText(xmlData->strLinSData[i]);
        lineEditSNumber[i]->setText(xmlData->strLinSID[i]);
        if(xmlData->strLinMCheck[i]==STRINGONE)
        {
            checkBoxMessage[i]->setChecked(true);
        }
        else
        {
            checkBoxMessage[i]->setChecked(false);
        }

        if(xmlData->strLinSCheck[i]==STRINGONE)
        {
            checkBoxSMessage[i]->setChecked(true);
        }
        else
        {
            checkBoxSMessage[i]->setChecked(false);
        }
    }
    this->setWindowTitle(tr("52424上位机软件"));

    //添加其他页
    widgetTab=new addWidgetTab(this);
    ui->tabWidget->addTab(widgetTab,QIcon(":/image/color.png"),tr("     参数设置     "));
    connect(widgetTab,SIGNAL(readInfo()),this,SLOT(readInfoMessage()));
    plotTab=new  customPlotTab(this);
    ui->tabWidget->addTab(plotTab,QIcon(":/image/rad.ico"),tr("     显示曲线     "));
    connect(plotTab,SIGNAL(readInfo()),this,SLOT(readInfoMessage()));
    plotThread=new CustomPlotThread(plotTab);
    for(int i=0;i<6;i++)
    {
        dataTarget[i]=0;
    }
}

/*************************析构函数*********************/
MainWindow::~MainWindow()
{
    delete xmlData;  //删除掉new出来的指针
    delete ui;       //删除掉new出来的指针
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
            if(ui->comboBoxBaud->currentText()==STRING9600)
            {
                myCom->setBaudRate(BAUD9600);
            }
            else if(ui->comboBoxBaud->currentText()==STRING115200)
            {
                myCom->setBaudRate(BAUD115200);
            }
            else if(ui->comboBoxBaud->currentText()==STRING57600)
            {
                myCom->setBaudRate(BAUD57600);
            }

            /*************************设置数据位*************************/
            if(ui->comboBoxData->currentText()==STRINGEIGHT)
            {
                myCom->setDataBits(DATA_8);
            }
            else if(ui->comboBoxData->currentText()==STRINGSEVEN)
            {
                myCom->setDataBits(DATA_7);
            }

            /*************************设置奇偶校验位*************************/
            if(ui->comboBoxCheck->currentText()==NOCHECK)
            {
                myCom->setParity(PAR_NONE);
            }
            else if(ui->comboBoxCheck->currentText()==ODDCHECK)
            {
                myCom->setParity(PAR_ODD);
            }
            else if(ui->comboBoxCheck->currentText()==EVENCHECK)
            {
                myCom->setParity(PAR_EVEN);
            }

            /*************************设置停止位*************************/
            if(ui->comboBoxStop->currentText()==STRINGONE)
            {
                myCom->setStopBits(STOP_1);
            }
            else if(ui->comboBoxStop->currentText()==STRINGTWO)
            {
                myCom->setStopBits(STOP_2);
            }

            myCom->setFlowControl(FLOW_OFF);     //设置数据流控制
            myCom->setTimeout(TIMEOUT);
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
            ui->checkBoxCheck->setEnabled(true);
            ui->tableWidgetMtask->setEnabled(true);
            ui->tableWidgetStask->setEnabled(true);
            ui->pushButtonStart->setEnabled(true);
            ui->spinBoxTime->setEnabled(true);
            ui->checkBoxLength->setEnabled(true);
            ui->pushButtonAddress->setEnabled(true);
            ui->pushButtonRead->setEnabled(true);
            ui->lineEditEight->setEnabled(true);
            ui->lineEditSeven->setEnabled(true);
            ui->lineEditSix->setEnabled(true);
            ui->lineEditFive->setEnabled(true);
            ui->comboBoxNumber->setEnabled(true);

            //设置定时器
            this->timer=new QTimer(this);                                    //定义一个定时器
            connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));        //设置
            timer->start(20);                                                //0.05秒调用一次
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
            ui->checkBoxCheck->setEnabled(false);
            ui->tableWidgetMtask->setEnabled(false);
            ui->tableWidgetStask->setEnabled(false);
            ui->pushButtonStart->setEnabled(false);
            ui->spinBoxTime->setEnabled(false);
            ui->checkBoxLength->setEnabled(false);
            ui->pushButtonAddress->setEnabled(false);
            ui->pushButtonRead->setEnabled(false);
            ui->lineEditEight->setEnabled(false);
            ui->lineEditSeven->setEnabled(false);
            ui->lineEditSix->setEnabled(false);
            ui->lineEditFive->setEnabled(false);
            ui->comboBoxNumber->setEnabled(false);

            if(this->timer->isActive())        //判断定时器是否开着
            {
                this->timer->stop();           //关闭定时器
            }

            myCom->close();
            delete myCom;
            myCom = NULL;
            ok=false;
            handShake=false;
            ui->pushButtonOpen->setText("打开串口");
            ui->statusBar->showMessage(tr("关闭串口成功"),3000);
            ui->pushButtonConn->setText("连接");
        }
    }
}

/*************************读取数据*********************/
void MainWindow::readCom()
{
    QByteArray temp=myCom->readAll(); //读取串口数据
    if(!temp.isEmpty())
    {
        readConn(temp);   //握手连接
        readMessage(temp);//读取探头信息
    }
}

/*************************探头数据*********************/
void MainWindow::readMessage(QByteArray temp)
{
    QList<float>listTempData;
    QByteArray tempData;            //临时变量

    /*******************读取探头5-8数据*********************/
    for(int j=0;j<temp.size();j++)
    {
        if(temp[j]==LINMSGHEAD&&temp[j+3]==LINMSG90)
        {
            tempData.clear();
            //读取数据位
            for(int i=j;i<j+(BYTE)temp[j+11];i++)
            {
                tempData[i-j] = temp[i+12];
            }
            ui->tableWidgetData->setRowCount(countRow+1);
            countRow++;
            if((BYTE)temp[j+10]<16)
            {
                ui->tableWidgetData->setItem(countRow-1,0,new QTableWidgetItem(tr("0X0%1").arg(QString::number((BYTE)temp[j+10],16))));    //ID
            }
            else
            {
                ui->tableWidgetData->setItem(countRow-1,0,new QTableWidgetItem(tr("0X%1").arg(QString::number((BYTE)temp[j+10],16))));    //ID
            }
            ui->tableWidgetData->setItem(countRow-1,1,new QTableWidgetItem(tr("%1").arg((BYTE)temp[j+11])));          //LEN
            ui->tableWidgetData->setItem(countRow-1,2,new QTableWidgetItem(QString(tempData.toHex())));               //DATA
            ui->tableWidgetData->scrollToBottom();
            ui->tableWidgetData->item(countRow-1,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetData->item(countRow-1,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidgetData->item(countRow-1,2)->setTextAlignment(Qt::AlignCenter);
            if(temp[j+10]==LINMSG3A)
            {
                ui->statusBar->showMessage("自动分配地址成功",3000);
            }
        }

        //读取测量数据LINMSG05
        if(temp[j+3]==LINMSG90 &&temp[j+10]==LINMSG05&&temp[j+11]==LINMSG08)
        {
            tempDataFive.clear();
            //读取数据位
            for(int i=j;i<j+8;i++)
            {
                tempDataFive[i-j] = temp[i+12];
            }
            recvFive=true;
            if((BYTE)listModel[4]==2)
            {
                AS=(((BYTE)tempDataFive[1]&LINMSG03)*256+(BYTE)tempDataFive[0])*0.064*0.17;
                ui->lineEditAS->setText(QString::number(AS,'f',3));
                aDistance=2*AS;
                aRingTime=((BYTE)tempDataFive[6]&LINMSG3F)*0.064;
                widgetTab->lineEditFive[0]->setText(QString::number((((BYTE)tempDataFive[1]&LINMSG03)*256+(BYTE)tempDataFive[0])*0.064*0.17,'f',3));
                widgetTab->lineEditFive[1]->setText(QString::number((((BYTE)tempDataFive[1])/4),'f',3));
                widgetTab->lineEditFive[2]->setText(QString::number((((BYTE)tempDataFive[3]&LINMSG03)*256+(BYTE)tempDataFive[2])*0.064*0.17,'f',3));
                widgetTab->lineEditFive[3]->setText(QString::number((((BYTE)tempDataFive[3])/4),'f',3));
            }
            else
            {
                aDistance=2*AS;
            }
        }

        //读取测量数据LINMSG06
        if(temp[j+3]==LINMSG90 &&temp[j+10]==LINMSG06&&temp[j+11]==LINMSG08)
        {
            tempDataSix.clear();
            //读取数据位
            for(int i=j;i<j+8;i++)
            {
                tempDataSix[i-j] = temp[i+12];
            }
            recvSix=true;
            if((BYTE)listModel[5]==2)
            {
                BS=(((BYTE)tempDataSix[1]&LINMSG03)*256+(BYTE)tempDataSix[0])*0.064*0.17;
                bRingTime=((BYTE)tempDataSix[6]&LINMSG3F)*0.064;
                ui->lineEditBS->setText(QString::number(BS,'f',3));
                widgetTab->lineEditSix[0]->setText(QString::number((((BYTE)tempDataSix[1]&LINMSG03)*256+(BYTE)tempDataSix[0])*0.064*0.17,'f',3));
                widgetTab->lineEditSix[1]->setText(QString::number((((BYTE)tempDataSix[1])/4),'f',3));
                widgetTab->lineEditSix[2]->setText(QString::number((((BYTE)tempDataSix[3]&LINMSG03)*256+(BYTE)tempDataSix[2])*0.064*0.17,'f',3));
                widgetTab->lineEditSix[3]->setText(QString::number((((BYTE)tempDataSix[3])/4),'f',3));
            }
        }

        //读取测量数据LINMSG07
        if(temp[j+3]==LINMSG90 &&temp[j+10]==LINMSG07&&temp[j+11]==LINMSG08)
        {
            tempDataSeven.clear();
            //读取数据位
            for(int i=j;i<j+8;i++)
            {
                tempDataSeven[i-j] = temp[i+12];
            }
            recvSeven=true;
            if((BYTE)listModel[6]==2)
            {
                CS=(((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.17;
                ui->lineEditCS->setText(QString::number(CS,'f',3));
                dataTarget[4]=(((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.17;
                dataTarget[5]=(((BYTE)tempDataSeven[3]&LINMSG03)*256+(BYTE)tempDataSeven[2])*0.064*0.17;
                widgetTab->lineEditSeven[0]->setText(QString::number((((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.17,'f',3));
                widgetTab->lineEditSeven[1]->setText(QString::number((((BYTE)tempDataSeven[1])/4),'f',3));
                widgetTab->lineEditSeven[2]->setText(QString::number((((BYTE)tempDataSeven[3]&LINMSG03)*256+(BYTE)tempDataSeven[2])*0.064*0.17,'f',3));
                widgetTab->lineEditSeven[3]->setText(QString::number((((BYTE)tempDataSeven[3])/4),'f',3));
            }
        }

        //读取测量数据LINMSG08
        if(temp[j+3]==LINMSG90 &&temp[j+10]==LINMSG08&&temp[j+11]==LINMSG08)
        {
            tempDataEight.clear();
            //读取数据位
            for(int i=j;i<j+8;i++)
            {
                tempDataEight[i-j] = temp[i+12];
            }
            recvEight=true;
            if((BYTE)listModel[7]==2)
            {
                DS=(((BYTE)tempDataEight[1]&LINMSG03)*256+(BYTE)tempDataEight[0])*0.064*0.17;
                ui->lineEditDS->setText(QString::number(DS,'f',3));
                dataTarget[0]=(((BYTE)tempDataEight[1]&LINMSG03)*256+(BYTE)tempDataEight[0])*0.064*0.17;
                dataTarget[1]=(((BYTE)tempDataEight[3]&LINMSG03)*256+(BYTE)tempDataEight[2])*0.064*0.17;
                widgetTab->lineEditEight[0]->setText(QString::number((((BYTE)tempDataEight[1]&LINMSG03)*256+(BYTE)tempDataEight[0])*0.064*0.17,'f',3));
                widgetTab->lineEditEight[1]->setText(QString::number((((BYTE)tempDataEight[1])/4),'f',3));
                widgetTab->lineEditEight[2]->setText(QString::number((((BYTE)tempDataEight[3]&LINMSG03)*256+(BYTE)tempDataEight[2])*0.064*0.17,'f',3));
                widgetTab->lineEditEight[3]->setText(QString::number((((BYTE)tempDataEight[3])/4),'f',3));
            }
        }
        for(int i=0;i<8;i++)
        {
            if((BYTE)listModel[i]==2)
            {
                switch(i)
                {
                case 4:
                    listTempData.clear();
                    listTempData<<widgetTab->lineEditFive[0]->text().toFloat();
                    listTempData<<widgetTab->lineEditFive[2]->text().toFloat();
                    break;
                case 5:
                    listTempData.clear();
                    listTempData<<widgetTab->lineEditSix[0]->text().toFloat();
                    listTempData<<widgetTab->lineEditSix[2]->text().toFloat();
                    break;
                case 6:
                    listTempData.clear();
                    listTempData<<widgetTab->lineEditSeven[0]->text().toFloat();
                    listTempData<<widgetTab->lineEditSeven[2]->text().toFloat();
                    break;
                case 7:
                    listTempData.clear();
                    listTempData<<widgetTab->lineEditEight[0]->text().toFloat();
                    listTempData<<widgetTab->lineEditEight[2]->text().toFloat();
                    break;
                }
            }
        }

        if(listTempData.size()==2&&sendFlage==true&&recvSix==true&&recvFive==true)
        {
            for(int countModel=0;countModel<8;countModel++)
            {
                if(1==(BYTE)listModel[countModel])
                {
                    switch (countModel)
                    {
                    case 4:
                        AS=(((BYTE)tempDataFive[1]&LINMSG03)*256+(BYTE)tempDataFive[0])*0.064*0.34-listTempData[0];
                        widgetTab->lineEditFive[0]->setText(QString::number((((BYTE)tempDataFive[1]&LINMSG03)*256+(BYTE)tempDataFive[0])*0.064*0.34-listTempData[0],'f',3));
                        widgetTab->lineEditFive[1]->setText(QString::number((((BYTE)tempDataFive[1])/4),'f',3));
                        widgetTab->lineEditFive[2]->setText(QString::number((((BYTE)tempDataFive[3]&LINMSG03)*256+(BYTE)tempDataFive[2])*0.064*0.34-listTempData[1],'f',3));
                        widgetTab->lineEditFive[3]->setText(QString::number((((BYTE)tempDataFive[3])/4),'f',3));
                        break;
                    case 5:
                        BS=(((BYTE)tempDataSix[1]&LINMSG03)*256+(BYTE)tempDataSix[0])*0.064*0.34-listTempData[0];
                        bDistance=(((BYTE)tempDataSix[1]&LINMSG03)*256+(BYTE)tempDataSix[0])*0.064*0.34;
                        widgetTab->lineEditSix[0]->setText(QString::number((((BYTE)tempDataSix[1]&LINMSG03)*256+(BYTE)tempDataSix[0])*0.064*0.34-listTempData[0],'f',3));
                        widgetTab->lineEditSix[1]->setText(QString::number((((BYTE)tempDataSix[1])/4),'f',3));
                        widgetTab->lineEditSix[2]->setText(QString::number((((BYTE)tempDataSix[3]&LINMSG03)*256+(BYTE)tempDataSix[2])*0.064*0.34-listTempData[1],'f',3));
                        widgetTab->lineEditSix[3]->setText(QString::number((((BYTE)tempDataSix[3])/4),'f',3));
                        break;
                    case 6:
                        CS=(((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.34-listTempData[0];
                        dataTarget[2]=(((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.34;
                        dataTarget[3]=(((BYTE)tempDataSeven[3]&LINMSG03)*256+(BYTE)tempDataSeven[2])*0.064*0.34;
                        widgetTab->lineEditSeven[0]->setText(QString::number((((BYTE)tempDataSeven[1]&LINMSG03)*256+(BYTE)tempDataSeven[0])*0.064*0.34-listTempData[0],'f',3));
                        widgetTab->lineEditSeven[1]->setText(QString::number((((BYTE)tempDataSeven[1])/4),'f',3));
                        widgetTab->lineEditSeven[2]->setText(QString::number((((BYTE)tempDataSeven[3]&LINMSG03)*256+(BYTE)tempDataSeven[2])*0.064*0.34-listTempData[1],'f',3));
                        widgetTab->lineEditSeven[3]->setText(QString::number((((BYTE)tempDataSeven[3])/4),'f',3));
                        break;
                    case 7:
                        DS=(((BYTE)tempDataEight[1]&LINMSG03)*256+(BYTE)tempDataEight[0])*0.064*0.34-listTempData[0];
                        widgetTab->lineEditEight[0]->setText(QString::number((((BYTE)tempDataEight[1]&LINMSG03)*256+(BYTE)tempDataEight[0])*0.064*0.34-listTempData[0],'f',3));
                        widgetTab->lineEditEight[1]->setText(QString::number((((BYTE)tempDataEight[1])/4),'f',3));
                        widgetTab->lineEditEight[2]->setText(QString::number((((BYTE)tempDataEight[3]&LINMSG03)*256+(BYTE)tempDataEight[2])*0.064*0.34-listTempData[1],'f',3));
                        widgetTab->lineEditEight[3]->setText(QString::number((((BYTE)tempDataEight[3])/4),'f',3));
                        break;
                    }
                }
            }
            ui->lineEditAS->setText(QString::number(AS,'f',3));
            ui->lineEditBS->setText(QString::number(BS,'f',3));
            ui->lineEditCS->setText(QString::number(CS,'f',3));
            ui->lineEditDS->setText(QString::number(DS,'f',3));

            getXY();  //得到XY坐标
            sendFlage=false;
            recvFive=false;
            recvSix=false;
            recvSeven=false;
            recvEight=false;

        }
        if(temp[j+3]==LINMSG90 &&temp[j+10]==LINMSG1D&&temp[j+11]==LINMSG08) //读取测量数据LINMSG1D
        {
            tempData.clear();

            //读取数据位
            for(int i=j;i<j+7;i++)
            {
                tempData[i-j] = temp[i+13];
            }

            if(TYID==5)
            {
                for(int i=0;i<tempData.count();i++)
                {
                    plotTab->dataPlot[0].dataX[countData]=countData*0.32;
                    plotTab->dataPlot[0].dataY[countData]=(BYTE)tempData[i];
                    countData++;
                }
                if(countData>=63)
                {
                    setupFrame(Load1C,LINMSG06,LINMSG00);
                    mainThread->run();
                    countData=0;
                }
            }
            else if(TYID==6)
            {
                for(int i=0;i<tempData.count();i++)
                {
                    plotTab->dataPlot[1].dataX[countData]=countData*0.32;
                    plotTab->dataPlot[1].dataY[countData]=(BYTE)tempData[i];
                    countData++;
                }
                if(countData>=63)
                {
                    setupFrame(Load1C,LINMSG07,LINMSG00);
                    mainThread->run();
                    countData=0;
                }
            }
            else if(TYID==7)
            {
                for(int i=0;i<tempData.count();i++)
                {
                    plotTab->dataPlot[2].dataX[countData]=countData*0.32;
                    plotTab->dataPlot[2].dataY[countData]=(BYTE)tempData[i];
                    countData++;
                }
                if(countData>=63)
                {
                    setupFrame(Load1C,LINMSG08,LINMSG00);
                    mainThread->run();
                    countData=0;
                }
            }
            else if(TYID==8)
            {
                for(int i=0;i<tempData.count();i++)
                {
                    plotTab->dataPlot[3].dataX[countData]=countData*0.32;
                    plotTab->dataPlot[3].dataY[countData]=(BYTE)tempData[i];
                    countData++;
                }
                if(countData>=63)
                {
                    plotThread->run();
                    setupFrame(Load1C,LINMSG05,LINMSG00);
                    countData=0;
                }
            }
        }
    }
}

/*************************握手数据*********************/
void MainWindow::readConn(QByteArray temp)
{
    if(temp[4]=='U'&&temp[5]=='2'&&temp[6]=='L')
    {
        handShake=true;
        ui->pushButtonConn->setText("已连接");
        //设置通道主从模式等
        setupFrame(Channel,LINMSG0F,LINMSG0F);

        //设置波特率
        setupFrame(Baud,LINMSG0F,LINMSG0F);

        //初始化设置，设置长度
        setupFrame(Length,LINMSG0F,LINMSG0F);
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

/*************************连续发送命令******************/
void MainWindow::on_pushButtonStart_clicked()
{
    if(ui->pushButtonStart->text()=="停止")
    {
        this->sendTimer->stop();           //关闭定时器
        ui->pushButtonStart->setText(tr("开始"));
        return;
    }

    if(ui->spinBoxTime->value()==0)
    {
        readInfoMessage();
    }
    else
    {
        ui->pushButtonStart->setText(tr("停止"));
        this->sendTimer=new QTimer(this);                                                //定义一个定时器
        connect(sendTimer,SIGNAL(timeout()),this,SLOT(readInfoMessage()));       //设置
        sendTimer->start(ui->spinBoxTime->value());
    }
}

/*************************握手连接*********************/
void MainWindow::on_pushButtonConn_clicked()
{
    if(ok)
    {
        setupFrame(Conn,LINMSG0F,LINMSG0F);
    }
}

/*************************设置通道*********************/
void MainWindow::on_comboBoxGallery_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Channel,LINMSG0F,LINMSG0F);
}

/*************************设置波特率*******************/
void MainWindow::on_comboBoxBaud_2_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Baud,LINMSG0F,LINMSG0F);
}

/*************************设置主从模式*****************/
void MainWindow::on_checkBoxImp_clicked()
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Imp,LINMSG0F,LINMSG0F);
}

/*************************设置协议********************/
void MainWindow::on_comboBoxDeal_activated(const QString &arg1)
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Deal,LINMSG0F,LINMSG0F);
}

/*************************设置长度********************/
void MainWindow::on_checkBoxLength_clicked()
{
    setupFlxbFrame(FlxLen);
}

/*************************发送帧头********************/
void MainWindow::sendFrameHead()
{
    setupFlxbFrame(Send);
}

/*************************加载***********************/
void MainWindow::on_checkBoxCheck_clicked()
{
    setupFlxbFrame(Load);
}

/*************************读取数据********************/
void MainWindow::readInfoMessage()
{
    if(!handShake)
    {
        return;
    }
    countData=0;
    sendFlage=true;
    mainThread->run();

}

/*************************保存信息函数*****************/
void MainWindow::saveConfig()
{
    xmlData->strBaud=ui->comboBoxBaud->currentText();
    xmlData->strLinBaud=ui->comboBoxBaud_2->currentText();
    xmlData->strPort=ui->comboBoxPort->currentText();
    xmlData->strLinPact=ui->comboBoxDeal->currentText();
    if(ui->comboBoxCheck->currentText()==NOCHECK)
    {
        xmlData->strCheck=STRINGZERO;
    }
    else if(ui->comboBoxCheck->currentText()==ODDCHECK)
    {
        xmlData->strCheck=STRINGONE;
    }
    else if(ui->comboBoxCheck->currentText()==EVENCHECK)
    {
        xmlData->strCheck=STRINGTWO;
    }
    xmlData->strStop=ui->comboBoxStop->currentText();
    xmlData->strData= ui->comboBoxData->currentText();
    xmlData->strLinChannel=ui->comboBoxGallery->currentText();

    if(ui->checkBoxImp->isChecked())
    {
        xmlData->strLinImp=STRINGONE;
    }
    else
    {
        xmlData->strLinImp=STRINGZERO;
    }

    if(ui->checkBoxSleep->isChecked())
    {
        xmlData->strLinSleep=STRINGONE;
    }
    else
    {
        xmlData->strLinSleep=STRINGZERO;
    }

    if(ui->checkBoxWake->isChecked())
    {
        xmlData->strLinWake=STRINGONE;
    }
    else
    {
        xmlData->strLinWake=STRINGZERO;
    }

    for(int i=0;i<8;i++)
    {
        xmlData->strLinMCount[i]=lineEditCount[i]->text();
        xmlData->strLinMData[i]=lineEditMessage[i]->text();
        xmlData->strLinMID[i]=lineEditNumber[i]->text();
        xmlData->strLinSData[i]=lineEditSMessage[i]->text();
        xmlData->strLinSID[i]=lineEditSNumber[i]->text();
        if(checkBoxMessage[i]->isChecked())
        {
            xmlData->strLinMCheck[i]=STRINGONE;
        }
        else
        {
            xmlData->strLinMCheck[i]=STRINGZERO;
        }

        if(checkBoxSMessage[i]->isChecked())
        {
            xmlData->strLinSCheck[i]=STRINGONE;
        }
        else
        {
            xmlData->strLinSCheck[i]=STRINGZERO;
        }

    }

    xmlData->updateXml();
}

/*************************窗口关闭函数*****************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    saveConfig();
}

/**************************得到XY坐标*****************/
void MainWindow::getXY()
{
    dataI.clear();

    if((BYTE)listModel[4]==2)
    {
        float cosB=(AB*AB+BS*BS-AS*AS)/(2*AB*BS);  //根据余弦公式算出角度
        float Y=BS*qSqrt(1-cosB*cosB);             //算出距离车的距离
        float BM=BS*cosB;                          //求出BM的值
        float X=BM+OB;                             //求出X坐标
        ui->lineEditX->setText(QString::number(X,'f',3));
        ui->lineEditY->setText(QString::number(Y,'f',3));
        qDebug()<<"余震"<<aRingTime;

        //正常查表
        for(int i=0;i<233;i++)
        {
            if(qAbs(AS-dataABSec[i].ASData)<0.05&&qAbs(BS-dataABSec[i].BSData)<0.05)
            {
                dataI<<i;
            }
        }
        if(dataI.count()>0)
        {
            int i=minGet(1);
            float y=dataABSec[dataI[i]].yData.toFloat();
            if((BS-AS<=(sqrt(0.9*0.9+(y-0.1)*(y-0.1))-sqrt(0.5*0.5+(y-0.05)*(y-0.05))))&&(AS-BS<sqrt(0.4*0.4+(y-0.05)*(y-0.05))-y+0.1))
            {
                ui->lineEditXTab->setText(dataABSec[dataI[i]].xData);
                ui->lineEditYTab->setText(dataABSec[dataI[i]].yData);
            }
            else
            {
                ui->lineEditXTab->setText(STRINGZERO);
                ui->lineEditYTab->setText(STRINGZERO);
            }

            int dataCount=0;
            if(dataBCSec[dataI[i]].xData=="0.000"&&dataBCSec[dataI[i]].yData=="0.200")
            {
                dataCount++;
            }
            else  if(dataBCSec[dataI[i]].xData=="0.200"&&dataBCSec[dataI[i]].yData=="0.150")
            {
                dataCount++;
            }


        }
        else
        {
            aDistance=AS*2;
            bDistance=AS+BS;
            qDebug()<<"b波程"<<bDistance<<"c波程"<<cDistance;
            if((aDistance>0.82||aDistance==0)&&bDistance<0.82&&bDistance!=0)
            {
                if(bDistance>0.75)
                {
                    ui->lineEditXTab->setText("FF");
                    ui->lineEditYTab->setText(QString::number(bDistance/3.5,'f',3));
                }
                else if(bDistance<0.75)
                {
                    ui->lineEditXTab->setText("FF");
                    ui->lineEditYTab->setText(QString::number(bDistance/4,'f',3));
                }
            }
            else if(bDistance>0.82&&aDistance<1.1&&aDistance!=0)
            {
                ui->lineEditXTab->setText("FF");
                ui->lineEditYTab->setText(QString::number(aDistance/4,'f',3));
            }
            else
            {
                ui->lineEditXTab->setText(STRINGZERO);
                ui->lineEditYTab->setText(STRINGZERO);
            }
        }
    }
    else if(((BYTE)listModel[5]==2)||((BYTE)listModel[6]==2))
    {
        float cosB=(AB*AB+CS*CS-BS*BS)/(2*AB*CS);  //根据余弦公式算出角度
        float Y=CS*qSqrt(1-cosB*cosB);             //算出距离车的距离
        float CM=CS*cosB;                          //求出BM的值
        float X=CM-OB;                             //求出X坐标
        ui->lineEditX->setText(QString::number(X,'f',3));
        ui->lineEditY->setText(QString::number(Y,'f',3));

        for(int i=0;i<78;i++)
        {
            if(BS<=CS)
            {
                if((qAbs(BS-dataBCSec[i].ASData)<0.05&&qAbs(CS-dataBCSec[i].BSData)<0.05))
                {
                    dataI<<i;
                }
            }
            else
            {
                if((qAbs(CS-dataBCSec[i].ASData)<0.05&&qAbs(BS-dataBCSec[i].BSData)<0.05))
                {
                    dataI<<i;
                }
            }
        }

        if(dataI.count()>0)
        {
            int i=minGet(2);
            float y=dataBCSec[dataI[i]].yData.toFloat();
            if(BS<=CS)
            {
                if((CS-BS<=(sqrt(0.9*0.9+(y-0.1)*(y-0.1))-sqrt(0.5*0.5+(y-0.05)*(y-0.05))))&&(CS-BS<sqrt(0.4*0.4+(y-0.05)*(y-0.05))-y+0.1))
                {
                    ui->lineEditXTab->setText(dataBCSec[dataI[i]].xData);
                    ui->lineEditYTab->setText(dataBCSec[dataI[i]].yData);
                }
                else
                {
                    ui->lineEditXTab->setText(STRINGZERO);
                    ui->lineEditYTab->setText(STRINGZERO);
                }
            }
            else
            {
                if((BS-CS<=(sqrt(0.9*0.9+(y-0.1)*(y-0.1))-sqrt(0.5*0.5+(y-0.05)*(y-0.05))))&&(BS-CS<sqrt(0.4*0.4+(y-0.05)*(y-0.05))-y+0.1))
                {
                    ui->lineEditXTab->setText(tr("-%1").arg(dataBCSec[dataI[i]].xData));
                    ui->lineEditYTab->setText(dataBCSec[dataI[i]].yData);

                }
                else
                {
                    ui->lineEditXTab->setText(STRINGZERO);
                    ui->lineEditYTab->setText(STRINGZERO);
                }
            }
            int dataCount=0;
            if(dataBCSec[dataI[i]].xData=="0.000"&&dataBCSec[dataI[i]].yData=="0.200")
            {
                dataCount++;
            }
            else  if(dataBCSec[dataI[i]].xData=="0.200"&&dataBCSec[dataI[i]].yData=="0.150")
            {
                dataCount++;
            }

            qDebug()<<"余震"<<bRingTime<<dataCount;
            if(dataCount!=0)
            {
                if(bRingTime>1.4)
                {
                    qDebug()<<"余震";
                    ui->lineEditXTab->setText("0.200");
                    ui->lineEditYTab->setText("0.150");
                }
                else
                {
                    ui->lineEditXTab->setText("0.000");
                    ui->lineEditYTab->setText("0.200");
                }
            }

        }
        else
        {
            bDistance=BS*2;
            cDistance=CS+BS;
            qDebug()<<"b波程"<<bDistance<<"c波程"<<cDistance;
            if(bDistance>0.93&&cDistance>0.8)
            {
                ui->lineEditXTab->setText(STRINGZERO);
                ui->lineEditYTab->setText(STRINGZERO);
            }
            else if((bDistance>0.93||bDistance==0)&&cDistance<0.80&&cDistance!=0)
            {
                ui->lineEditXTab->setText("FF");
                ui->lineEditYTab->setText(QString::number(cDistance/4,'f',3));
            }
        }
    }
    else if((BYTE)listModel[7]==2)
    {
        float cosB=(AB*AB+CS*CS-DS*DS)/(2*AB*CS);  //根据余弦公式算出角度
        if(cosB>=1||cosB<=-1)
        {
            return;
        }
        float Y=CS*qSqrt(1-cosB*cosB);             //算出距离车的距离
        float DM=CS*cosB;                          //求出BM的值
        float X=-DM-OB;                            //求出X坐标
        ui->lineEditX->setText(QString::number(X,'f',3));
        ui->lineEditY->setText(QString::number(Y,'f',3));
        //正常查表
        for(int i=0;i<212;i++)
        {
            if(qAbs(DS-dataABSec[i].ASData)<0.05&&qAbs(CS-dataABSec[i].BSData)<0.05)
            {
                dataI<<i;
            }
        }
        if(dataI.count()>0)
        {
            int i=minGet(3);
            float y=dataABSec[dataI[i]].yData.toFloat();
            if((CS-DS<=(sqrt(0.9*0.9+(y-0.1)*(y-0.1))-sqrt(0.5*0.5+(y-0.05)*(y-0.05))))&&(DS-CS<sqrt(0.4*0.4+(y-0.05)*(y-0.05))-y+0.1))
            {
                ui->lineEditXTab->setText(tr("-%1").arg(dataABSec[dataI[i]].xData));
                ui->lineEditYTab->setText(dataABSec[dataI[i]].yData);
            }
            else
            {
                ui->lineEditXTab->setText(STRINGZERO);
                ui->lineEditYTab->setText(STRINGZERO);
            }
        }
        else
        {
            ui->lineEditXTab->setText(STRINGZERO);
            ui->lineEditYTab->setText(STRINGZERO);
        }
    }
    AS=0;
    BS=0;
    CS=0;
    DS=0;
}

/**************************求最小值*******************/
int MainWindow::minGet(BYTE flage)
{
    int countI=0;
    QList<float>dataTemp;
    for(int i=0;i<dataI.count();i++)
    {
        if(flage==1)
        {
            dataTemp<<qSqrt((BS-dataABSec[dataI[i]].BSData)*(BS-dataABSec[dataI[i]].BSData)+(AS-dataABSec[dataI[i]].ASData)*(AS-dataABSec[dataI[i]].ASData));
        }
        else if(flage==2)
        {
            if(BS<=CS)
            {
                dataTemp<<qSqrt((CS-dataBCSec[dataI[i]].BSData)*(CS-dataBCSec[dataI[i]].BSData)+(BS-dataBCSec[dataI[i]].ASData)*(BS-dataBCSec[dataI[i]].ASData));
            }
            else
            {
                dataTemp<<qSqrt((BS-dataBCSec[dataI[i]].BSData)*(BS-dataBCSec[dataI[i]].BSData)+(CS-dataBCSec[dataI[i]].ASData)*(CS-dataBCSec[dataI[i]].ASData));
            }
        }
        else
        {
            dataTemp<<qSqrt((DS-dataABSec[dataI[i]].ASData)*(DS-dataABSec[dataI[i]].ASData)+(CS-dataABSec[dataI[i]].BSData)*(CS-dataABSec[dataI[i]].BSData));
        }
    }
    if(dataTemp.count()>1)
    {
        float min=dataTemp[0];
        for(int i=1;i<dataTemp.count();i++)
        {
            if(dataTemp[i]<min)
            {
                min=dataTemp[i];
                countI=i;
            }
        }
    }
    return countI;
}

/**************************设置帧*********************/
void MainWindow::setupFrame(Frame Model, BYTE ID,BYTE Par)
{
    int tempData=0;      //临时数据
    QByteArray array;    //帧数组
    array[0]=LINMSGHEAD; //帧头
    int baudInt;         //波特率

    switch(Model)    //根据不同数据选择控制信息码
    {
    case Conn:      array[1]=LINMSG02;   array[3]=LINMSG41; array[4]=LINMSG6C;   break;      //握手连接
    case Baud:      array[1]=LINMSG06;   array[3]=LINMSGD6;                      break;      //波特率
    case Channel:   array[1]=LINMSG03;   array[3]=LINMSG53;                      break;      //通道
    case Imp:       array[1]=LINMSG03;   array[3]=LINMSG53;                      break;      //主从模式
    case Length:    array[1]=LINMSG42;   array[3]=LINMSG55;                      break;      //长度
    case Deal:      array[1]=LINMSG03;   array[3]=LINMSG53;                      break;      //协议
    case Send:      array[1]=LINMSG04;   array[3]=LINMSG11;                      break;      //发送帧头
    }

    array[2]=LINMSG00;
    if(Model==Channel||Model==Deal||Model==Imp)  //如果模式为更改通道，主从，协议
    {
        if(ui->comboBoxGallery->currentText()==STRINGZERO)
        {
            array[4]=LINMSG00;
        }
        else
        {
            array[4]=LINMSG01;
        }

        if(ui->checkBoxImp->isChecked())
        {
            if(ui->comboBoxDeal->currentText()==LINONEX)
            {
                array[5]=LINMSG01;
            }
            else if(ui->comboBoxDeal->currentText()==LINTWOX)
            {
                array[5]=LINMSG05;
            }
            else if(ui->comboBoxDeal->currentText()==AUTO)
            {
                array[5]=LINMSG09;
            }
            else if(ui->comboBoxDeal->currentText()==KLIN)
            {
                array[5]=LINMSG0D;
            }
        }
        else
        {
            if(ui->comboBoxDeal->currentText()==LINONEX)
            {
                array[5]=LINMSG00;
            }
            else if(ui->comboBoxDeal->currentText()==LINTWOX)
            {
                array[5]=LINMSG04;
            }
            else if(ui->comboBoxDeal->currentText()==AUTO)
            {
                array[5]=LINMSG08;
            }
            else if(ui->comboBoxDeal->currentText()==KLIN)
            {
                array[5]=LINMSG0C;
            }
        }
    }

    //如果模式为更改波特率
    else if(Model==Baud)
    {
        array[4]=LINMSG00;
        baudInt=ui->comboBoxBaud_2->currentText().toInt();//得到当前波特率
        if(baudInt>20000)
        {
            ui->statusBar->showMessage("波特率不能超过2000",3000);
            return;
        }
        array[5]=baudInt&LINMSGFF;//取低八位
        array[6]=baudInt>>8;      //取高八位
        array[7]=LINMSG00;
        array[8]=LINMSG00;
    }

    //如果模式为加载
    else if(Model==Load3C||Model==Load1C||Model==Load)
    {
        array[1]=LINMSG07;
        array[3]=LINMSG52;
        if(ui->comboBoxGallery->currentText()==STRINGZERO)
        {
            array[4]=LINMSG00;
        }
        else
        {
            array[4]=LINMSG01;
        }

        switch(ID)
        {
        case LINMSG05:  array[5]=LINMSG01;  array[6]=LINMSG1C;  array[7]=LINMSG02;  array[8]=LINMSG05;  TYID=LINMSG05;  array[9]=Par;                                              break;
        case LINMSG06:  array[5]=LINMSG01;  array[6]=LINMSG1C;  array[7]=LINMSG02;  array[8]=LINMSG06;  TYID=LINMSG06;  array[9]=Par;                                              break;
        case LINMSG07:  array[5]=LINMSG01;  array[6]=LINMSG1C;  array[7]=LINMSG02;  array[8]=LINMSG07;  TYID=LINMSG07;  array[9]=Par;                                              break;
        case LINMSG08:  array[5]=LINMSG01;  array[6]=LINMSG1C;  array[7]=LINMSG02;  array[8]=LINMSG08;  TYID=LINMSG08;  array[9]=Par;                                              break;
        case LINMSG38:  array[5]=LINMSG01;  array[6]=LINMSG38;  array[7]=LINMSG02;  array[8]=LINMSG0F;                  array[9]=LINMSG00;                                         break;
        case LINMSG1A:  array[5]=LINMSG01;  array[6]=LINMSG1A;  array[7]=LINMSG04;  array[8]=LINMSGFF;                  array[9]=LINMSGFC;  array[10]=LINMSG01; array[9]=LINMSGE0; break;
        case LINMSG00:  array[5]=LINMSG01;  array[6]=LINMSG00;  array[7]=LINMSG03;  array[8]=LINMSG00;                  array[9]=Par;       array[10]=LINMSGC0;                    break;
        }
        if(Model==Load3C)
        {
            bool ok;
            array[5]=LINMSG07;
            array[6]=LINMSG3C;
            array[7]=LINMSG08;
            array[8]=LINMSG7F;
            array[9]=LINMSG06;
            array[10]=LINMSGB5;
            array[11]=LINMSGFF;
            array[12]=LINMSG7F;
            if(ID==LINMSG01)
            {
                array[13]=LINMSG01;
                array[14]=LINMSG02;
                array[15]=LINMSG00;
            }

            else if(ID==LINMSG02)
            {
                array[13]=LINMSG02;
                array[14]=LINMSG02;
                array[15]=ui->lineEditEight->text().toInt(&ok,16);
            }
            else if(ID==LINMSG03)
            {
                array[13]=LINMSG02;
                array[14]=LINMSG02;
                array[15]=ui->lineEditSeven->text().toInt(&ok,16);
            }
            else if(ID==LINMSG04)
            {
                array[13]=LINMSG02;
                array[14]=LINMSG02;
                array[15]=ui->lineEditSix->text().toInt(&ok,16);
            }
            else if(ID==LINMSG05)
            {
                array[13]=LINMSG02;
                array[14]=LINMSG02;
                array[15]=ui->lineEditFive->text().toInt(&ok,16);
            }
            else if(ID==LINMSG06)
            {
                array[13]=LINMSG03;
                array[14]=LINMSG02;
                array[15]=LINMSG00;
            }
            else if(ID==LINMSG07)
            {
                array[13]=LINMSG04;
                array[14]=LINMSG02;
                array[15]=LINMSG00;
            }
            array[1]=0X0D;
        }
    }

    //如果模式为发送帧头
    else if(Model==Send)
    {
        if(ui->comboBoxGallery->currentText()==STRINGZERO)
        {
            array[4]=LINMSG00;
        }
        else
        {
            array[4]=LINMSG01;
        }
        array[5]=LINMSG0E;
        array[6]=ID;
    }

    //判断如果模式为设置长度
    if(Model==Length)
    {
        if(ui->comboBoxGallery->currentText()==STRINGZERO)
        {
            array[4]=LINMSG00;
        }
        else
        {
            array[4]=LINMSG01;
        }
        for(int i=5;i<69;i++)
        {
            array[i]=LINMSG00;
        }
        array[ID+5]=Par;
        for(int i=0;i<69;i++)
        {
            tempData+=static_cast<char>(array[i]);
        }
        array[69]=tempData&LINMSGFF;
        array[70]=LINMSGTAIL;
    }
    else
    {
        for(int i=0;i<(BYTE)array[1]+3;i++)
        {
            tempData+=static_cast<char>(array[i]);
        }
        array[(BYTE)array[1]+3]=tempData&LINMSGFF;
        array[(BYTE)array[1]+4]=LINMSGTAIL;
    }
    myCom->write(array);//写命令
    if(array[6]==LINMSG00)
    {
        Sleep(60);
    }
    else
    {
        Sleep(10);
    }

    qDebug()<<array.toHex();
}

/**************************设置灵活的帧****************/
void MainWindow::setupFlxbFrame(Frame ID)
{
    //判断是否握手连接成功
    if(!handShake)
    {
        return;
    }
    QByteArray array;     //发送数组
    QList<int>listNumber; //发送次数
    QList<int>listID;     //ID
    array[0]=LINMSGHEAD;  //帧头
    switch(ID)
    {
    case Load:                           array[3]=LINMSG52;    break;      //加载
    case Send:      array[1]=LINMSG04;   array[3]=LINMSG11;    break;      //发送帧头
    case FlxLen:    array[1]=LINMSG42;   array[3]=LINMSG55;    break;      //设置长度
    }
    array[2]=LINMSG00;    //字节数前八位
    if(ui->comboBoxGallery->currentText()==STRINGZERO)
    {
        array[4]=LINMSG00;
    }
    else
    {
        array[4]=LINMSG01;
    }
    if(ID==Load)
    {
        bool flage;             //标志位
        int Count=0;            //计数器

        QList<QString>listText; //定义存储字符串
        if(!ui->checkBoxCheck->isChecked())//判断选中复选框是否选中
        {
            return;
        }
        for(int i=0;i<8;i++)    //判断复选框被选中
        {
            if(checkBoxSMessage[i]->isChecked())
            {
                listNumber<<i;
            }
        }
        //根据复选框选中来找出对应的ID和长度
        for(int i=0;i<listNumber.count();i++)
        {
            listID<<lineEditSNumber[listNumber[i]]->text().toInt(&ok, 16);
            QString strTemp=lineEditSMessage[listNumber[i]]->text();
            deBlank(strTemp);
            listText<<strTemp;
        }
        int tempData=3;
        for(int i=0;i<listText.count();i++)
        {
            tempData+=listText[i].length()/2+2;
        }
        array[1]=tempData;
        array[5]=listText.count();

        //将加载上的字节添加到数组中
        for(int i=0;i<tempData-3;)
        {
            array[i+6]=listID[Count];
            array[i+7]=listText[Count].length()/2;
            for(int j=i;j<i+listText[Count].length()/2;j++)
            {
                array[j+8]=listText[Count].mid((j-i)*2,2).toInt(&flage,16);
            }
            if(array[i+6]==LINMSG00)
            {
                listModel.clear();      //清空探头模式
                listModel<<(BYTE)(array[i+8]&LINMSG03);    //1号探头模式
                listModel<<(BYTE)(array[i+8]&LINMSG0C)/4;  //2号探头模式
                listModel<<(BYTE)(array[i+8]&LINMSG30)/16; //3号探头模式
                listModel<<(BYTE)(array[i+8]&LINMSGC0)/64; //4号探头模式
                listModel<<(BYTE)(array[i+9]&LINMSG03);    //5号探头模式
                listModel<<(BYTE)(array[i+9]&LINMSG0C)/4;  //6号探头模式
                listModel<<(BYTE)(array[i+9]&LINMSG30)/16; //7号探头模式
                listModel<<(BYTE)(array[i+9]&LINMSGC0)/64; //8号探头模式
                qDebug()<<listModel[4]<<listModel[5]<<listModel[6]<<listModel[7];
            }
            if(array[i+6]==LINMSG1C)
            {
                TYID=(BYTE)array[i+8];
            }
            i+=listText[Count].length()/2+2;
            Count++;
        }
        int Data=0;
        for(int i=0;i<tempData+3;i++)
        {
            Data+=static_cast<char>(array[i]);
        }
        array[tempData+3]=Data&LINMSGFF;
        array[tempData+4]=LINMSGTAIL;
        myCom->write(array);//加载数据
    }
    else if(ID==Send)
    {
        array[5]=LINMSG0E;
        //判断出哪个复选框被选中
        for(int i=0;i<8;i++)
        {
            if(checkBoxMessage[i]->isChecked())
            {
                listNumber<<i;
            }
        }
        if(listNumber.count()==0)
        {
            ui->statusBar->showMessage(tr("请选择ID"),3000);
            return;
        }

        //根据复选框选中来找出对应的ID和长度
        for(int i=0;i<listNumber.count();i++)
        {
            listID<<lineEditNumber[listNumber[i]]->text().toInt(&ok, 16);
        }

        int tempData=0;
        for(int j=0;j<listID.count();j++)
        {
            int tempCount=lineEditCount[listNumber[j]]->text().toInt();

            array[6]=listID[j];
            for(int k=0;k<tempCount;k++)
            {
                tempData=0;
                for(int i=0;i<7;i++)
                {
                    tempData+=static_cast<int>(array[i]);
                }
                array[7]=tempData&LINMSGFF;
                array[8]=LINMSGTAIL;

                myCom->write(array);
                if(array[6]==LINMSG00)
                {
                    Sleep(40);
                }
                Sleep(10);
            }
        }
    }
    else if(ID==FlxLen)
    {
        QList<int>listLength;
        int Count=0;

        //判断出哪个复选框被选中
        for(int i=0;i<8;i++)
        {
            if(checkBoxMessage[i]->isChecked())
            {
                listNumber<<i;
            }
        }

        //根据复选框选中来找出对应的ID和长度
        for(int i=0;i<listNumber.count();i++)
        {
            listID<<lineEditNumber[listNumber[i]]->text().toInt(&ok,16);
            listLength<<lineEditMessage[listNumber[i]]->text().toInt();
        }

        if(ui->checkBoxLength->isChecked())
        {
            //根据对应的ID和长度写其位数
            for(int i=5;i<69;i++)
            {
                Count=0;
                for(int j=0;j<listNumber.count();j++)
                {
                    if(i-5==listID[j])
                    {
                        array[i]=listLength[j];
                        Count++;
                    }
                }
                if(Count==0)
                {
                    array[i]=LINMSG00;
                }
            }
        }
        else
        {
            for(int i=5;i<69;i++)
            {
                array[i]=LINMSG00;
            }
        }

        int tempData=0;
        for(int i=0;i<69;i++)
        {
            tempData+=static_cast<char>(array[i]);
        }
        array[69]=tempData&LINMSGFF;
        array[70]=LINMSGTAIL;
        myCom->write(array);
    }
}

/**************************线程构造********************/
MainThread::MainThread(MainWindow *w)
{
    this->window=w;
}

/**************************线程运行********************/
void MainThread::run()
{
    this->window->sendFrameHead();
}

/**************************自动分配地址*****************/
void MainWindow::on_pushButtonAddress_clicked()
{
    if(!handShake)
    {
        return;
    }

    setupFrame(Length,LINMSG3C,LINMSG08);        //设置长度3C
    setupFrame(Load3C,LINMSG01,LINMSG0F);        //加载数据3C
    setupFrame(Send,  LINMSG3C,LINMSG0F);        //发送帧头3C
    if(ui->lineEditEight->isEnabled())
    {
        setupFrame(Load3C,LINMSG02,LINMSG0F);    //加载数据3C
        setupFrame(Send,LINMSG3C,LINMSG0F);      //发送帧头3C
    }
    if(ui->lineEditSeven->isEnabled())
    {
        setupFrame(Load3C,LINMSG03,LINMSG0F);    //加载数据3C
        setupFrame(Send,LINMSG3C,LINMSG0F);      //发送帧头3C
    }
    if(ui->lineEditSix->isEnabled())
    {
        setupFrame(Load3C,LINMSG04,LINMSG0F);    //加载数据3C
        setupFrame(Send,LINMSG3C,LINMSG0F);      //发送帧头3C
    }
    if(ui->lineEditFive->isEnabled())
    {
        setupFrame(Load3C,LINMSG05,LINMSG0F);    //加载数据3C
        setupFrame(Send,LINMSG3C,LINMSG0F);      //发送帧头3C
    }

    setupFrame(Load3C,LINMSG06,LINMSG0F);        //加载数据3C
    setupFrame(Send,LINMSG3C,LINMSG0F);          //发送帧头3C

    setupFrame(Load3C,LINMSG07,LINMSG0F);        //加载数据3C
    setupFrame(Send,LINMSG3C,LINMSG0F);          //发送帧头3C

    if(ui->lineEditEight->isEnabled())
    {
        setupFrame(Length,LINMSG1C,LINMSG02);    //设置长度1C
        setupFrame(Load1C,LINMSG08,LINMSG10);    //加载1C
        setupFrame(Send,LINMSG1C,LINMSG0F) ;     //发送帧头1C
        setupFrame(Length,LINMSG3A,LINMSG05);    //设置长度3A
        setupFrame(Send,LINMSG3A,LINMSG0F);      //发送帧头3A
    }

    if(ui->lineEditSeven->isEnabled())
    {
        setupFrame(Length,LINMSG1C,LINMSG02);    //设置长度1C
        setupFrame(Load1C,LINMSG07,LINMSG10);    //加载1C
        setupFrame(Send,LINMSG1C,LINMSG0F) ;     //发送帧头1C
        setupFrame(Length,LINMSG3A,LINMSG05);    //设置长度3A
        setupFrame(Send,LINMSG3A,LINMSG0F);      //发送帧头3A
    }

    if(ui->lineEditSix->isEnabled())
    {
        setupFrame(Length,LINMSG1C,LINMSG02);     //设置长度1C
        setupFrame(Load1C,LINMSG06,LINMSG10);     //加载1C
        setupFrame(Send,LINMSG1C,LINMSG0F) ;      //发送帧头1C
        setupFrame(Length,LINMSG3A,LINMSG05);     //设置长度3A
        setupFrame(Send,LINMSG3A,LINMSG0F);       //发送帧头3A
    }

    if(ui->lineEditFive->isEnabled())
    {
        setupFrame(Length,LINMSG1C,LINMSG02);     //设置长度1C
        setupFrame(Load1C,LINMSG05,LINMSG10);     //加载1C
        setupFrame(Send,LINMSG1C,LINMSG0F) ;      //发送帧头1C
        setupFrame(Length,LINMSG3A,LINMSG05);     //设置长度3A
        setupFrame(Send,LINMSG3A,LINMSG0F);       //发送帧头3A
    }
}

/**************************清空信息********************/
void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditAS->clear();
    ui->lineEditBS->clear();
    ui->lineEditCS->clear();
    ui->lineEditDS->clear();
    ui->lineEditX->clear();
    ui->lineEditY->clear();
    ui->lineEditXTab->clear();
    ui->lineEditYTab->clear();
    ui->tableWidgetData->clearContents();
    countRow=0;
    ui->tableWidgetData->setRowCount(0);
    AS=0;
    BS=0;
    CS=0;
    DS=0;
}

/**************************读取数据********************/
void MainWindow::on_pushButtonRead_clicked()
{
    if(!handShake)
    {
        return;
    }
    setupFrame(Length,LINMSG38,LINMSG02);        //设置长度38
    setupFrame(Load,  LINMSG38,LINMSG0F);        //加载数据38
    setupFrame(Send,  LINMSG38,LINMSG0F);        //发送帧头38

    setupFrame(Length,LINMSG1A,LINMSG04);        //设置长度1A
    setupFrame(Load,  LINMSG1A,LINMSG0F);        //加载数据1A
    setupFrame(Send,  LINMSG1A,LINMSG0F);        //发送帧头1A

    setupFrame(Length,LINMSG00,LINMSG03);        //设置长度00
    setupFrame(Load,  LINMSG00,LINMSG06);        //加载数据00
    setupFrame(Send,  LINMSG00,LINMSG0F);        //发送帧头00

    setupFrame(Length,LINMSG05,LINMSG08);        //设置长度05
    setupFrame(Send,  LINMSG05,LINMSG0F);        //发送帧头05

    setupFrame(Length,LINMSG06,LINMSG08);        //设置长度06
    setupFrame(Send,  LINMSG06,LINMSG0F);        //发送帧头06

    setupFrame(Load,  LINMSG00,LINMSG18);        //加载数据00
    setupFrame(Send,  LINMSG00,LINMSG0F);        //发送帧头00

    setupFrame(Length,LINMSG06,LINMSG08);        //设置长度06
    setupFrame(Send,  LINMSG06,LINMSG0F);        //发送帧头06

    setupFrame(Length,LINMSG07,LINMSG08);        //设置长度07
    setupFrame(Send,  LINMSG07,LINMSG0F);        //发送帧头07

    setupFrame(Load,  LINMSG00,LINMSG90);        //加载数据00
    setupFrame(Send,  LINMSG00,LINMSG0F);        //发送帧头00

    setupFrame(Length,LINMSG08,LINMSG08);        //设置长度08
    setupFrame(Send,  LINMSG08,LINMSG0F);        //发送帧头08

    setupFrame(Length,LINMSG07,LINMSG08);        //设置长度07
    setupFrame(Send,  LINMSG07,LINMSG0F);        //发送帧头07
}

/**************************选择分配ID数目***************/
void MainWindow::on_comboBoxNumber_activated(int index)
{
    switch(index)
    {
    case 0:
        ui->lineEditEight->setEnabled(true);
        ui->lineEditSeven->setEnabled(true);
        ui->lineEditSix->setEnabled(true);
        ui->lineEditFive->setEnabled(true);
        break;
    case 1:
        ui->lineEditEight->setEnabled(true);
        ui->lineEditSeven->setEnabled(true);
        ui->lineEditSix->setEnabled(true);
        ui->lineEditFive->setEnabled(false);
        break;
    case 2:
        ui->lineEditEight->setEnabled(true);
        ui->lineEditSeven->setEnabled(true);
        ui->lineEditSix->setEnabled(false);
        ui->lineEditFive->setEnabled(false);
        break;
    case 3:
        ui->lineEditEight->setEnabled(true);
        ui->lineEditSeven->setEnabled(false);
        ui->lineEditSix->setEnabled(false);
        ui->lineEditFive->setEnabled(false);
        break;
    }
}
