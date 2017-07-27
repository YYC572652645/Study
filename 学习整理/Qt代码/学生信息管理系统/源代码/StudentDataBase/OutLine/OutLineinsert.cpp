#include "OutLineinsert.h"
#include "ui_OutLineinsert.h"

OutLineInsert::OutLineInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OutLineinsert)
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


    /*************************时间***********************/
    dateEditOutLineTime=new QDateEdit();
    dateEditOutLineTime->setMinimumHeight(32);
    widgetOutLineTime=new QWidget;
    hboxLayoutOutLineTime=new QHBoxLayout();
    hboxLayoutOutLineTime->addWidget(dateEditOutLineTime);
    hboxLayoutOutLineTime->setAlignment(widgetOutLineTime,Qt::AlignCenter);
    widgetOutLineTime->setLayout(hboxLayoutOutLineTime);


    /*************************违规原因***********************/
    LineEditOutLineReason=new QLineEdit();
    LineEditOutLineReason->setMinimumHeight(32);
    widgetOutLineReason=new QWidget;
    hboxLayoutOutLineReason=new QHBoxLayout();
    hboxLayoutOutLineReason->addWidget(LineEditOutLineReason);
    hboxLayoutOutLineReason->setAlignment(widgetOutLineReason,Qt::AlignCenter);
    widgetOutLineReason->setLayout(hboxLayoutOutLineReason);


    /*************************违规级别***********************/
    comboBoxOutLineLevel=new QComboBox();
    comboBoxOutLineLevel->setMinimumHeight(32);
    widgetOutLineLevel=new QWidget;
    hboxLayoutOutLineLevel=new QHBoxLayout();
    hboxLayoutOutLineLevel->addWidget(comboBoxOutLineLevel);
    hboxLayoutOutLineLevel->setAlignment(widgetOutLineLevel,Qt::AlignCenter);
    widgetOutLineLevel->setLayout(hboxLayoutOutLineLevel);
    comboBoxOutLineLevel->addItem(tr("开除学籍"));
    comboBoxOutLineLevel->addItem(tr("留校查看"));
    comboBoxOutLineLevel->addItem(tr("严重警告"));


    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("违规违纪录入"));
    widgetInsert=new QWidget;
    hboxLayoutInsert=new QHBoxLayout();
    hboxLayoutInsert->addWidget(pushButtonInsert);
    hboxLayoutInsert->setAlignment(widgetInsert,Qt::AlignCenter);
    widgetInsert->setLayout(hboxLayoutInsert);

    ui->tableWidget->setRowCount(5);

    QFont f("宋体",14,QFont::Bold,true);
    pushButtonInsert->setFont(f);
    pushButtonInsert->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    pushButtonInsert->setIconSize(QSize(40,40));
    pushButtonInsert->setMaximumWidth(600);
    pushButtonInsert->setMinimumHeight(60);


    ui->tableWidget->setSpan(4,0,4,2);//合并单元格
    ui->tableWidget->setCellWidget(0,1,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetOutLineTime);
    ui->tableWidget->setCellWidget(2,1,widgetOutLineReason);
    ui->tableWidget->setCellWidget(3,1,widgetOutLineLevel);
    ui->tableWidget->setCellWidget(4,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);


    QTableWidgetItem *OutLineTime=new QTableWidgetItem("时间:");
    OutLineTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,OutLineTime);


    QTableWidgetItem *OutLineReason=new QTableWidgetItem("违规原因:");
    OutLineReason->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,OutLineReason);

    QTableWidgetItem *OutLineLevel=new QTableWidgetItem("违规级别:");
    OutLineLevel->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,OutLineLevel);


    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new OutLineDataBase();
}

OutLineInsert::~OutLineInsert()
{
    delete ui;
}

void OutLineInsert::insertData()
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

    data->OutLineTime=dateEditOutLineTime->text();
    data->OutLineReason=LineEditOutLineReason->text();
    data->OutLineLevel=comboBoxOutLineLevel->currentText();

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
