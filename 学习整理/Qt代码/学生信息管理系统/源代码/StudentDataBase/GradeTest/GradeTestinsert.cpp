#include "GradeTestinsert.h"
#include "ui_GradeTestinsert.h"

GradeTestInsert::GradeTestInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradeTestinsert)
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


    /*************************考试名称***********************/
    comboBoxGradeTestName=new QComboBox();
    comboBoxGradeTestName->setMinimumHeight(32);
    widgetGradeTestName=new QWidget;
    hboxLayoutGradeTestName=new QHBoxLayout();
    hboxLayoutGradeTestName->addWidget(comboBoxGradeTestName);
    hboxLayoutGradeTestName->setAlignment(widgetGradeTestName,Qt::AlignCenter);
    widgetGradeTestName->setLayout(hboxLayoutGradeTestName);
    comboBoxGradeTestName->addItem(tr("英语4级"));
    comboBoxGradeTestName->addItem(tr("英语6级"));
    comboBoxGradeTestName->addItem(tr("计算机二级"));


    /*************************是否通过***********************/
    comboBoxGradeTestIsPass=new QComboBox();
    comboBoxGradeTestIsPass->setMinimumHeight(32);
    widgetGradeTestIsPass=new QWidget;
    hboxLayoutGradeTestIsPass=new QHBoxLayout();
    hboxLayoutGradeTestIsPass->addWidget(comboBoxGradeTestIsPass);
    hboxLayoutGradeTestIsPass->setAlignment(widgetGradeTestIsPass,Qt::AlignCenter);
    widgetGradeTestIsPass->setLayout(hboxLayoutGradeTestIsPass);
    comboBoxGradeTestIsPass->addItem(tr("是"));
    comboBoxGradeTestIsPass->addItem(tr("否"));



    /*************************考试时间***********************/
    dateEditGradeTestTime=new QDateEdit();
    dateEditGradeTestTime->setMinimumHeight(32);
    widgetGradeTestTime=new QWidget;
    hboxLayoutGradeTestTime=new QHBoxLayout();
    hboxLayoutGradeTestTime->addWidget(dateEditGradeTestTime);
    hboxLayoutGradeTestTime->setAlignment(widgetGradeTestTime,Qt::AlignCenter);
    widgetGradeTestTime->setLayout(hboxLayoutGradeTestTime);


    /*************************考试分数***********************/
    LineEditGradeTestFraction=new QLineEdit();
    LineEditGradeTestFraction->setMinimumHeight(32);
    widgetGradeTestFraction=new QWidget;
    hboxLayoutGradeTestFraction=new QHBoxLayout();
    hboxLayoutGradeTestFraction->addWidget(LineEditGradeTestFraction);
    hboxLayoutGradeTestFraction->setAlignment(widgetGradeTestFraction,Qt::AlignCenter);
    widgetGradeTestFraction->setLayout(hboxLayoutGradeTestFraction);





    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("等级考试录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    ui->tableWidget->setRowCount(6);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);


    ui->tableWidget->setSpan(5,0,5,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetGradeTestName);
    ui->tableWidget->setCellWidget(2,1,widgetGradeTestIsPass);
    ui->tableWidget->setCellWidget(3,1,widgetGradeTestTime);
    ui->tableWidget->setCellWidget(4,1,widgetGradeTestFraction);
    ui->tableWidget->setCellWidget(5,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *GradeTestName=new QTableWidgetItem("考试名称:");
    GradeTestName->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,GradeTestName);


    QTableWidgetItem *GradeTestIsPass=new QTableWidgetItem("是否通过:");
    GradeTestIsPass->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,GradeTestIsPass);

    QTableWidgetItem *GradeTestTime=new QTableWidgetItem("考试时间:");
    GradeTestTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,GradeTestTime);


    QTableWidgetItem *GradeTestFraction=new QTableWidgetItem("考试分数:");
    GradeTestFraction->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,0,GradeTestFraction);


    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new GradeTestDataBase();
}

GradeTestInsert::~GradeTestInsert()
{
    delete ui;
}

void GradeTestInsert::insertData()
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
    data->GradeTestName=comboBoxGradeTestName->currentText();
    data->isPass=comboBoxGradeTestIsPass->currentText();
    data->GradeTestTime=dateEditGradeTestTime->text();
    data->GradeTestFraction=LineEditGradeTestFraction->text();

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
