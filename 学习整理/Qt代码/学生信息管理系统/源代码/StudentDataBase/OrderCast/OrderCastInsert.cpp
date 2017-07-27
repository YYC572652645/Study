#include "OrderCastinsert.h"
#include "ui_OrderCastinsert.h"

OrderCastInsert::OrderCastInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OrderCastInsert)
{
    ui->setupUi(this);

    //把表头上面去掉
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);


    //设置列表控件等宽显示
    QHeaderView *headerView=ui->tableWidget->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);


    //设置列表控件等高显示
    QHeaderView *leftHeaderView=ui->tableWidget->verticalHeader();
    leftHeaderView->setSectionResizeMode(QHeaderView::Stretch);

    //设置不能选择
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);

    //设置无边框
    ui->tableWidget->setFrameShape(QFrame::NoFrame);

    //设置为不可编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


    /*************************学号信息***********************/
    lineEditNumber=new QLineEdit();
    lineEditNumber->setMinimumHeight(32);
    widgetNumber=new QWidget;
    hboxLayoutNumber=new QHBoxLayout();
    hboxLayoutNumber->addWidget(lineEditNumber);
    hboxLayoutNumber->setAlignment(widgetNumber,Qt::AlignCenter);
    widgetNumber->setLayout(hboxLayoutNumber);


    /*************************班级排名***********************/
    lineEditOrderCastClass=new QLineEdit();
    lineEditOrderCastClass->setMinimumHeight(32);
    widgetOrderCastClass=new QWidget;
    hboxLayoutOrderCastClass=new QHBoxLayout();
    hboxLayoutOrderCastClass->addWidget(lineEditOrderCastClass);
    hboxLayoutOrderCastClass->setAlignment(widgetOrderCastClass,Qt::AlignCenter);
    widgetOrderCastClass->setLayout(hboxLayoutOrderCastClass);


    /*************************专业排名***********************/
    comboBoxOrderCastPro=new QLineEdit();
    comboBoxOrderCastPro->setMinimumHeight(32);
    widgetOrderCastPro=new QWidget;
    hboxLayoutOrderCastPro=new QHBoxLayout();
    hboxLayoutOrderCastPro->addWidget(comboBoxOrderCastPro);
    hboxLayoutOrderCastPro->setAlignment(widgetOrderCastPro,Qt::AlignCenter);
    widgetOrderCastPro->setLayout(hboxLayoutOrderCastPro);


    /*************************年份***********************/
    lineEditOrderCastTime=new QComboBox();
    lineEditOrderCastTime->setMinimumHeight(32);
    widgetOrderCastTime=new QWidget;
    hboxLayoutOrderCastTime=new QHBoxLayout();
    hboxLayoutOrderCastTime->addWidget(lineEditOrderCastTime);
    hboxLayoutOrderCastTime->setAlignment(widgetOrderCastTime,Qt::AlignCenter);
    widgetOrderCastTime->setLayout(hboxLayoutOrderCastTime);
    for(int i=2013;i<2100;i++)
    {
        lineEditOrderCastTime->addItem(tr("%1").arg(i));
    }


    /*************************学期***********************/
    comboBoxOrderCastStatus=new QComboBox();
    comboBoxOrderCastStatus->setMinimumHeight(32);
    widgetOrderCastStatus=new QWidget;
    hboxLayoutOrderCastStatus=new QHBoxLayout();
    hboxLayoutOrderCastStatus->addWidget(comboBoxOrderCastStatus);
    hboxLayoutOrderCastStatus->setAlignment(widgetOrderCastStatus,Qt::AlignCenter);
    widgetOrderCastStatus->setLayout(hboxLayoutOrderCastStatus);
    comboBoxOrderCastStatus->addItem(tr("上学期"));
    comboBoxOrderCastStatus->addItem(tr("下学期"));


    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("成绩排名录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);         //信息录入
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);

    ui->tableWidget->setSpan(5,0,5,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetOrderCastClass);
    ui->tableWidget->setCellWidget(2,1,widgetOrderCastPro);
    ui->tableWidget->setCellWidget(3,1,widgetOrderCastTime);
    ui->tableWidget->setCellWidget(4,1,widgetOrderCastStatus);
    ui->tableWidget->setCellWidget(5,0,widgetInsert);


    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *OrderCastClass=new QTableWidgetItem("班级排名:");
    OrderCastClass->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,OrderCastClass);


    QTableWidgetItem *OrderCastPro=new QTableWidgetItem("专业排名:");
    OrderCastPro->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,OrderCastPro);

    QTableWidgetItem *OrderCastTime=new QTableWidgetItem("年份:");
    OrderCastTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,OrderCastTime);


    QTableWidgetItem *OrderCastStatus=new QTableWidgetItem("学期:");
    OrderCastStatus->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,0,OrderCastStatus);


    OrderCast=new OrderCastDataBase();
    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
}

OrderCastInsert::~OrderCastInsert()
{
    delete ui;
}

void OrderCastInsert::insertData()
{
    QRegExp rx;                              //正则表达式
    rx.setPatternSyntax(QRegExp::RegExp);    //将元字符设置为统配模式下
    rx.setCaseSensitivity(Qt::CaseSensitive);//大小写敏感


    if(lineEditNumber->text().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号为空,请填写学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        rx.setPattern(QString("[1-9][0-9]{9}"));    //匹配学号10位
        if(rx.exactMatch(lineEditNumber->text()))
        {
            OrderCast->number=lineEditNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }
    OrderCast->OrderCastClass=lineEditOrderCastClass->text();
    OrderCast->OrderCastPro=comboBoxOrderCastPro->text();
    OrderCast->OrderCastTime=lineEditOrderCastTime->currentText();
    OrderCast->OrderCastTerm=comboBoxOrderCastStatus->currentText();

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("确定录入吗？"),QPixmap(":/new/prefix1/image/happy.png"),false);
    if(MessageDialog::getInstance()->exec() == QDialog::Accepted)
    {
        if(OrderCast->insertData())
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，录入成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
            MessageDialog::getInstance()->exec();
        }
        else
        {

            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，录入失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
        }
    }
}
