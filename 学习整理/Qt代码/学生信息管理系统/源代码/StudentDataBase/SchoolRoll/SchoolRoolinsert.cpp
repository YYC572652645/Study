#include "SchoolRoolinsert.h"
#include "ui_SchoolRoolinsert.h"

SchoolRoolInsert::SchoolRoolInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SchoolRoolinsert)
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



    /*************************修复退种类***********************/
    comboBoxSchoolRoolType=new QComboBox();
    comboBoxSchoolRoolType->setMinimumHeight(32);
    widgetSchoolRoolType=new QWidget;
    hboxLayoutSchoolRoolType=new QHBoxLayout();
    hboxLayoutSchoolRoolType->addWidget(comboBoxSchoolRoolType);
    hboxLayoutSchoolRoolType->setAlignment(widgetSchoolRoolType,Qt::AlignCenter);
    widgetSchoolRoolType->setLayout(hboxLayoutSchoolRoolType);
    comboBoxSchoolRoolType->addItem(tr("开除学籍"));
    comboBoxSchoolRoolType->addItem(tr("留校查看"));
    comboBoxSchoolRoolType->addItem(tr("严重警告"));


    /*************************时间***********************/
    dateEditSchoolRoolTime=new QDateEdit();
    dateEditSchoolRoolTime->setMinimumHeight(32);
    widgetSchoolRoolTime=new QWidget;
    hboxLayoutSchoolRoolTime=new QHBoxLayout();
    hboxLayoutSchoolRoolTime->addWidget(dateEditSchoolRoolTime);
    hboxLayoutSchoolRoolTime->setAlignment(widgetSchoolRoolTime,Qt::AlignCenter);
    widgetSchoolRoolTime->setLayout(hboxLayoutSchoolRoolTime);


    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("学籍异变录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    ui->tableWidget->setRowCount(4);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);


    ui->tableWidget->setSpan(3,0,3,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetSchoolRoolTime);
    ui->tableWidget->setCellWidget(2,1,widgetSchoolRoolType);
    ui->tableWidget->setCellWidget(3,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);


    QTableWidgetItem *SchoolRoolType=new QTableWidgetItem("修复退种类:");
    SchoolRoolType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,SchoolRoolType);



    QTableWidgetItem *SchoolRoolTime=new QTableWidgetItem("时间:");
    SchoolRoolTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,SchoolRoolTime);


    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new SchoolRoolDataBase();
}

SchoolRoolInsert::~SchoolRoolInsert()
{
    delete ui;
}

void SchoolRoolInsert::insertData()
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
    data->SchoolRoolType=comboBoxSchoolRoolType->currentText();
    data->SchoolRoolTime=dateEditSchoolRoolTime->text();

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
