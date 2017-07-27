#include "mainwindow.h"
#include "ui_mainwindow.h"


/**************************构造函数***************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置列表控件等宽显示
    QHeaderView *headerView=ui->tableWidgetData->horizontalHeader();
    headerView->setSectionResizeMode(QHeaderView::Stretch);


    //设置为不可编辑
    ui->tableWidgetData->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //纵向隐藏序号
    headerView=ui->tableWidgetData->verticalHeader();                                        headerView->setHidden(true);

    //设置表头颜色为天蓝色
    ui->tableWidgetData->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;}");

    //设置表格的字体颜色为黑色
    ui->tableWidgetData->setStyleSheet("QTableWidget{border:2px groove cyan;border-radius:0px;color:black;}");


    countData=0;
    connect(ui->actionSelect,SIGNAL(triggered(bool)),this,SLOT(DataSelect()));
    connect(ui->actionEXIT,SIGNAL(triggered(bool)),this,SLOT(exitLogin()));
    QDesktopWidget *desktop=QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);  //程序显示在屏幕中间
}

MainWindow::~MainWindow()
{
    delete ui;
}


/**************************查询数据***************************/
void MainWindow::DataSelect()
{
    workThread=new WorkThread();  //开辟一个子线程
    connect(workThread,SIGNAL(dataCount(int)),this,SLOT(dataCount(int)));                    //子线程想主线程发送数据dataCount
    connect(workThread,SIGNAL(dataStruct(StudentData*)),this,SLOT(dataStruct(StudentData*)));//子线程想主线程发送数据结构体StudentData
    workThread->start();          //调用子线程
}


/**************************退出登录***************************/
void MainWindow::exitLogin()
{
    dialog.show();
    qApp->quit();
    //this->close();
}


/**************************接收子线程传回数据*******************/
void MainWindow::dataCount(int Count)
{
    countData=Count;                            //将子线程传来的数据保存
    ui->tableWidgetData->setRowCount(countData);//设置显示几行网格
}


/**************************接收子线程传回数据*******************/
void MainWindow::dataStruct(StudentData *student)
{
    //如果查询出有数据，就将结构体的值赋值过来
    if(countData>0)
    {
        for(int i=0;i<countData;i++)
        {
            ////将子线程传来的数据在网表格中显示
            ui->tableWidgetData->setItem(i,0,new QTableWidgetItem(student[i].number));
            ui->tableWidgetData->setItem(i,1,new QTableWidgetItem(student[i].name));
            ui->tableWidgetData->setItem(i,2,new QTableWidgetItem(student[i].sex));
            ui->tableWidgetData->setItem(i,3,new QTableWidgetItem(student[i].age));
        }


    }

}

