#include "cutschoolinsert.h"
#include "ui_cutschoolinsert.h"

CutSchoolInsert::CutSchoolInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CutSchoolInsert)
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


    /*************************旷课名称***********************/
    lineEditCutClass=new QLineEdit();
    lineEditCutClass->setMinimumHeight(32);
    widgetCutClass=new QWidget;
    hboxLayoutCutClass=new QHBoxLayout();
    hboxLayoutCutClass->addWidget(lineEditCutClass);
    hboxLayoutCutClass->setAlignment(widgetCutClass,Qt::AlignCenter);
    widgetCutClass->setLayout(hboxLayoutCutClass);




    /*************************旷课时间***********************/
    dateEditCutTime=new QDateEdit();
    dateEditCutTime->setMinimumHeight(32);
    widgetCutTime=new QWidget;
    hboxLayoutCutTime=new QHBoxLayout();
    hboxLayoutCutTime->addWidget(dateEditCutTime);
    hboxLayoutCutTime->setAlignment(widgetCutTime,Qt::AlignCenter);
    widgetCutTime->setLayout(hboxLayoutCutTime);




    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("旷课情况录入"));
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

    ui->tableWidget->setSpan(3,0,3,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetCutClass);
    ui->tableWidget->setCellWidget(2,1,widgetCutTime);
    ui->tableWidget->setCellWidget(3,0,widgetInsert);


    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *cutClass=new QTableWidgetItem("旷课名称:");
    cutClass->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,cutClass);


    QTableWidgetItem *cutTime=new QTableWidgetItem("旷课时间:");
    cutTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,cutTime);

    cutSchool=new CutSchoolDataBase();
    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    dateEditCutTime->setDateTime(QDateTime::currentDateTime());
}

CutSchoolInsert::~CutSchoolInsert()
{
    delete ui;
}

void CutSchoolInsert::insertData()
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
            cutSchool->number=lineEditNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }


    cutSchool->cutClass=lineEditCutClass->text();


    cutSchool->cutTime=dateEditCutTime->text();

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("确定录入吗？"),QPixmap(":/new/prefix1/image/happy.png"),false);
    if(MessageDialog::getInstance()->exec() == QDialog::Accepted)
    {
        if(cutSchool->insertData())
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
