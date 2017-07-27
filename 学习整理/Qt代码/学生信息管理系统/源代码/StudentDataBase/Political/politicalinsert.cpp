#include "politicalinsert.h"
#include "ui_politicalinsert.h"

PoliticalInsert::PoliticalInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PoliticalInsert)
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


    /*************************入团时间***********************/
    dateEditgroMem=new QDateEdit();
    dateEditgroMem->setMinimumHeight(32);
    widgetgroMem=new QWidget;
    hboxLayoutgroMem=new QHBoxLayout();
    hboxLayoutgroMem->addWidget(dateEditgroMem);
    hboxLayoutgroMem->setAlignment(widgetgroMem,Qt::AlignCenter);
    widgetgroMem->setLayout(hboxLayoutgroMem);




    /*************************入党积极分子时间***********************/
    dateEditProActMem=new QDateEdit();
    dateEditProActMem->setMinimumHeight(32);
    widgetProActMem=new QWidget;
    hboxLayoutProActMem=new QHBoxLayout();
    hboxLayoutProActMem->addWidget(dateEditProActMem);
    hboxLayoutProActMem->setAlignment(widgetProActMem,Qt::AlignCenter);
    widgetProActMem->setLayout(hboxLayoutProActMem);


    /*************************入党时间***********************/
    dateEditProMem=new QDateEdit();
    dateEditProMem->setMinimumHeight(32);
    widgetProMem=new QWidget;
    hboxLayoutProMem=new QHBoxLayout();
    hboxLayoutProMem->addWidget(dateEditProMem);
    hboxLayoutProMem->setAlignment(widgetProMem,Qt::AlignCenter);
    widgetProMem->setLayout(hboxLayoutProMem);



    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("政治面貌录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);         //信息录入
    pushButtonInsert->setStyleSheet("QPushButton:hover{background-color:rgb(9,150,200);;}QPushButton:press{background-color:darkcyan;}");
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);

    ui->tableWidget->setSpan(4,0,4,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetgroMem);
    ui->tableWidget->setCellWidget(2,1,widgetProActMem);
    ui->tableWidget->setCellWidget(3,1,widgetProMem);
    ui->tableWidget->setCellWidget(4,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *groMem=new QTableWidgetItem("入团时间:");
    groMem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,groMem);


    QTableWidgetItem *proActMem=new QTableWidgetItem("入党积极分子时间:");
    proActMem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,proActMem);


    QTableWidgetItem *proMem=new QTableWidgetItem("入党时间:");
    proMem->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,proMem);

    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));


    data=new PoliticalDataBase();
}

PoliticalInsert::~PoliticalInsert()
{
    delete ui;
}

void PoliticalInsert::insertData()
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
            data->number=lineEditNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }

    if(dateEditgroMem->text()!="2000/1/1")
    {
        data->groMemTime=dateEditgroMem->text();
    }
    if(dateEditProActMem->text()!="2000/1/1")
    {
        data->parMemActTime=dateEditProActMem->text();
    }
    if(dateEditProMem->text()!="2000/1/1")
    {
        data->parMebrTime=dateEditProMem->text();
    }

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("确定录入吗？"),QPixmap(":/new/prefix1/image/happy.png"),false);
    if(MessageDialog::getInstance()->exec() == QDialog::Accepted)
    {
        if(data->insertData())
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
