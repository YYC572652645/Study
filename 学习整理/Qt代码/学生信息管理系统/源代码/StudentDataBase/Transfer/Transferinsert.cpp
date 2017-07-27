#include "Transferinsert.h"
#include "ui_Transferinsert.h"

TransferInsert::TransferInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transferinsert)
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
    dateEditTransferTime=new QDateEdit();
    dateEditTransferTime->setMinimumHeight(32);
    widgetTransferTime=new QWidget;
    hboxLayoutTransferTime=new QHBoxLayout();
    hboxLayoutTransferTime->addWidget(dateEditTransferTime);
    hboxLayoutTransferTime->setAlignment(widgetTransferTime,Qt::AlignCenter);
    widgetTransferTime->setLayout(hboxLayoutTransferTime);


    /*************************转学学校***********************/
    LineEditTransferSchool=new QLineEdit();
    LineEditTransferSchool->setMinimumHeight(32);
    widgetTransferSchool=new QWidget;
    hboxLayoutTransferSchool=new QHBoxLayout();
    hboxLayoutTransferSchool->addWidget(LineEditTransferSchool);
    hboxLayoutTransferSchool->setAlignment(widgetTransferSchool,Qt::AlignCenter);
    widgetTransferSchool->setLayout(hboxLayoutTransferSchool);


    /*************************转学类型***********************/
    comboBoxTransferType=new QComboBox();
    comboBoxTransferType->setMinimumHeight(32);
    widgetTransferType=new QWidget;
    hboxLayoutTransferType=new QHBoxLayout();
    hboxLayoutTransferType->addWidget(comboBoxTransferType);
    hboxLayoutTransferType->setAlignment(widgetTransferType,Qt::AlignCenter);
    widgetTransferType->setLayout(hboxLayoutTransferType);
    comboBoxTransferType->addItem(tr("转入"));
    comboBoxTransferType->addItem(tr("转出"));


    /*************************插入按钮***********************/
    pushButtonInsert=new QPushButton();
    pushButtonInsert->setMinimumHeight(25);
    pushButtonInsert->setText(tr("转学录入"));
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
    ui->tableWidget->setCellWidget(1,1,widgetTransferTime);
    ui->tableWidget->setCellWidget(2,1,widgetTransferSchool);
    ui->tableWidget->setCellWidget(3,1,widgetTransferType);
    ui->tableWidget->setCellWidget(4,0,widgetInsert);



    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);


    QTableWidgetItem *TransferTime=new QTableWidgetItem("转学时间:");
    TransferTime->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,TransferTime);


    QTableWidgetItem *TransferSchool=new QTableWidgetItem("转学学校:");
    TransferSchool->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,TransferSchool);

    QTableWidgetItem *TransferType=new QTableWidgetItem("转学类型:");
    TransferType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,TransferType);


    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new TransferDataBase();
}

TransferInsert::~TransferInsert()
{
    delete ui;
}

void TransferInsert::insertData()
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

    data->TransferTime=dateEditTransferTime->text();
    data->TransferSchool=LineEditTransferSchool->text();
    data->TransferType=comboBoxTransferType->currentText();

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
