#include "Honorinsert.h"
#include "ui_Honorinsert.h"

HonorInsert::HonorInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HonorInsert)
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


    /*************************获奖种类***********************/
    comboBoxHonorType=new QComboBox();
    comboBoxHonorType->setMinimumHeight(32);
    widgetHonorType=new QWidget;
    hboxLayoutHonorType=new QHBoxLayout();
    hboxLayoutHonorType->addWidget(comboBoxHonorType);
    hboxLayoutHonorType->setAlignment(widgetHonorType,Qt::AlignCenter);
    widgetHonorType->setLayout(hboxLayoutHonorType);
    comboBoxHonorType->addItem(tr("国家"));

    /*************************获奖级别***********************/
    comboBoxHonorLevel=new QComboBox();
    comboBoxHonorLevel->setMinimumHeight(32);
    widgetHonorLevel=new QWidget;
    hboxLayoutHonorLevel=new QHBoxLayout();
    hboxLayoutHonorLevel->addWidget(comboBoxHonorLevel);
    hboxLayoutHonorLevel->setAlignment(widgetHonorLevel,Qt::AlignCenter);
    widgetHonorLevel->setLayout(hboxLayoutHonorLevel);
    comboBoxHonorLevel->addItem(tr("一等奖"));

    /*************************获奖名称***********************/
    lineEditHonorName=new QLineEdit();
    lineEditHonorName->setMinimumHeight(32);
    widgetHonorName=new QWidget;
    hboxLayoutHonorName=new QHBoxLayout();
    hboxLayoutHonorName->addWidget(lineEditHonorName);
    hboxLayoutHonorName->setAlignment(widgetHonorName,Qt::AlignCenter);
    widgetHonorName->setLayout(hboxLayoutHonorName);


    /*************************获奖时间***********************/
    dateEditHonorTime=new QDateEdit();
    dateEditHonorTime->setMinimumHeight(32);
    widgetHonorTime=new QWidget;
    hboxLayoutHonorTime=new QHBoxLayout();
    hboxLayoutHonorTime->addWidget(dateEditHonorTime);
    hboxLayoutHonorTime->setAlignment(widgetHonorTime,Qt::AlignCenter);
    widgetHonorTime->setLayout(hboxLayoutHonorTime);


    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("获奖情况录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    ui->tableWidget->setRowCount(6);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);         //信息录入
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);

    ui->tableWidget->setSpan(5,0,5,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetHonorType);
    ui->tableWidget->setCellWidget(2,1,widgetHonorLevel);
    ui->tableWidget->setCellWidget(3,1,widgetHonorName);
    ui->tableWidget->setCellWidget(4,1,widgetHonorTime);
    ui->tableWidget->setCellWidget(5,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *HonorType=new QTableWidgetItem("获奖种类:");
    HonorType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,HonorType);


    QTableWidgetItem *HonorLevel=new QTableWidgetItem("获奖级别:");
    HonorLevel->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,HonorLevel);


    QTableWidgetItem *HonorName=new QTableWidgetItem("获奖名称:");
    HonorName->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,HonorName);



    QTableWidgetItem *HonorTime=new QTableWidgetItem("获奖时间:");
    HonorTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,0,HonorTime);


    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new HonorDataBase();
}

HonorInsert::~HonorInsert()
{
    delete ui;
}

void HonorInsert::insertData()
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


    data->honorType=comboBoxHonorType->currentText();
    data->honorLevel=comboBoxHonorLevel->currentText();
    data->honorName=lineEditHonorName->text();
    data->honorTime=dateEditHonorTime->text();
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
