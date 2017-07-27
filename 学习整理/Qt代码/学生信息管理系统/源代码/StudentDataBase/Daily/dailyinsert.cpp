#include "dailyinsert.h"
#include "ui_dailyinsert.h"

DailyInsert::DailyInsert(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DailyInsert)
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


    /*************************宿舍号信息***********************/
    lineEditDorNumber=new QLineEdit();
    lineEditDorNumber->setMinimumHeight(32);
    widgetDorNumber=new QWidget;
    hboxLayoutDorNumber=new QHBoxLayout();
    hboxLayoutDorNumber->addWidget(lineEditDorNumber);
    hboxLayoutDorNumber->setAlignment(widgetDorNumber,Qt::AlignCenter);
    widgetDorNumber->setLayout(hboxLayoutDorNumber);


    /*************************时间***********************/
    dateEditDorTime=new QDateEdit();
    dateEditDorTime->setMinimumHeight(32);
    widgetDorTime=new QWidget;
    hboxLayoutDorTime=new QHBoxLayout();
    hboxLayoutDorTime->addWidget(dateEditDorTime);
    hboxLayoutDorTime->setAlignment(widgetDorTime,Qt::AlignCenter);
    widgetDorTime->setLayout(hboxLayoutDorTime);



    /*************************宿舍情况***********************/
    comboBoxDorStatus=new QComboBox();
    comboBoxDorStatus->setMinimumHeight(32);
    widgetDorStatus=new QWidget;
    hboxLayoutDorStatus=new QHBoxLayout();
    hboxLayoutDorStatus->addWidget(comboBoxDorStatus);
    hboxLayoutDorStatus->setAlignment(widgetDorStatus,Qt::AlignCenter);
    widgetDorStatus->setLayout(hboxLayoutDorStatus);
    comboBoxDorStatus->addItem(tr("通报批评"));
    comboBoxDorStatus->addItem(tr("通报表扬"));


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
    ui->tableWidget->setCellWidget(0,1,widgetDorNumber);
    ui->tableWidget->setCellWidget(1,1,widgetDorStatus);
    ui->tableWidget->setCellWidget(2,1,widgetDorTime);
    ui->tableWidget->setCellWidget(3,0,widgetInsert);


    QTableWidgetItem *number=new QTableWidgetItem("宿舍号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,number);

    QTableWidgetItem *status=new QTableWidgetItem("宿舍情况:");
    status->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,status);


    QTableWidgetItem *time=new QTableWidgetItem("时间:");
    time->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,time);



    connect(pushButtonInsert,SIGNAL(clicked(bool)),this,SLOT(insertData()));
    data=new DailyDataBase();

}

DailyInsert::~DailyInsert()
{
    delete ui;
}

void DailyInsert::insertData()
{
    if(lineEditDorNumber->text().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，宿舍号为空,请填写宿舍号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }

    data->dorNumber=lineEditDorNumber->text();
    data->dorStatus=comboBoxDorStatus->currentText();
    data->dorTime=dateEditDorTime->text();

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
