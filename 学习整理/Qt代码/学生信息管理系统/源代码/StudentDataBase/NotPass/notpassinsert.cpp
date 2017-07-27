#include "NotPassinsert.h"
#include "ui_NotPassinsert.h"

NotPassInsert::NotPassInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NotPassInsert)
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


    /*************************挂科名称***********************/
    lineEditNotPassClass=new QLineEdit();
    lineEditNotPassClass->setMinimumHeight(32);
    widgetNotPassClass=new QWidget;
    hboxLayoutNotPassClass=new QHBoxLayout();
    hboxLayoutNotPassClass->addWidget(lineEditNotPassClass);
    hboxLayoutNotPassClass->setAlignment(widgetNotPassClass,Qt::AlignCenter);
    widgetNotPassClass->setLayout(hboxLayoutNotPassClass);




    /*************************挂科学分***********************/
    comboBoxNotPassGrade=new QComboBox();
    comboBoxNotPassGrade->setMinimumHeight(32);
    widgetNotPassGrade=new QWidget;
    hboxLayoutNotPassGrade=new QHBoxLayout();
    hboxLayoutNotPassGrade->addWidget(comboBoxNotPassGrade);
    hboxLayoutNotPassGrade->setAlignment(widgetNotPassGrade,Qt::AlignCenter);
    widgetNotPassGrade->setLayout(hboxLayoutNotPassGrade);
    comboBoxNotPassGrade->addItem(tr("0.5"));
    comboBoxNotPassGrade->addItem(tr("1"));
    comboBoxNotPassGrade->addItem(tr("1.5"));
    comboBoxNotPassGrade->addItem(tr("2"));
    comboBoxNotPassGrade->addItem(tr("2.5"));
    comboBoxNotPassGrade->addItem(tr("3"));
    comboBoxNotPassGrade->addItem(tr("3.5"));
    comboBoxNotPassGrade->addItem(tr("4"));
    comboBoxNotPassGrade->addItem(tr("4.5"));
    comboBoxNotPassGrade->addItem(tr("5"));


    /*************************挂科性质***********************/
    lineEditNotPassPro=new QLineEdit();
    lineEditNotPassPro->setMinimumHeight(32);
    widgetNotPassPro=new QWidget;
    hboxLayoutNotPassPro=new QHBoxLayout();
    hboxLayoutNotPassPro->addWidget(lineEditNotPassPro);
    hboxLayoutNotPassPro->setAlignment(widgetNotPassPro,Qt::AlignCenter);
    widgetNotPassPro->setLayout(hboxLayoutNotPassPro);




    /*************************挂科状态***********************/
    comboBoxNotPassStatus=new QComboBox();
    comboBoxNotPassStatus->setMinimumHeight(32);
    widgetNotPassStatus=new QWidget;
    hboxLayoutNotPassStatus=new QHBoxLayout();
    hboxLayoutNotPassStatus->addWidget(comboBoxNotPassStatus);
    hboxLayoutNotPassStatus->setAlignment(widgetNotPassStatus,Qt::AlignCenter);
    widgetNotPassStatus->setLayout(hboxLayoutNotPassStatus);
    comboBoxNotPassStatus->addItem(tr("已修"));
    comboBoxNotPassStatus->addItem(tr("未修"));


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

    ui->tableWidget->setSpan(5,0,5,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetNotPassClass);
    ui->tableWidget->setCellWidget(2,1,widgetNotPassGrade);
    ui->tableWidget->setCellWidget(3,1,widgetNotPassPro);
    ui->tableWidget->setCellWidget(4,1,widgetNotPassStatus);
    ui->tableWidget->setCellWidget(5,0,widgetInsert);


    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *NotPassClass=new QTableWidgetItem("旷课名称:");
    NotPassClass->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,NotPassClass);


    QTableWidgetItem *NotPassGrade=new QTableWidgetItem("挂科学分:");
    NotPassGrade->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,NotPassGrade);

    QTableWidgetItem *NotPassPro=new QTableWidgetItem("挂科性质:");
    NotPassPro->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,NotPassPro);


    QTableWidgetItem *NotPassStatus=new QTableWidgetItem("挂科状态:");
    NotPassStatus->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,0,NotPassStatus);


    NotPass=new NotPassDataBase();
    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
}

NotPassInsert::~NotPassInsert()
{
    delete ui;
}

void NotPassInsert::insertData()
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
            NotPass->number=lineEditNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }
    NotPass->notPassClass=lineEditNotPassClass->text();
    NotPass->notPassGrade=comboBoxNotPassGrade->currentText();
    NotPass->notPassPro=lineEditNotPassPro->text();
    NotPass->notPassState=comboBoxNotPassStatus->currentText();

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("确定录入吗？"),QPixmap(":/new/prefix1/image/happy.png"),false);
    if(MessageDialog::getInstance()->exec() == QDialog::Accepted)
    {
        if(NotPass->insertData())
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
