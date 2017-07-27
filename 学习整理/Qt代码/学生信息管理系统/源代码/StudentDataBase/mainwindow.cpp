#include "mainwindow.h"
#include "ui_mainwindow.h"


/**************************构造函数***************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("学生信息管理系统"));
    this->addToolBarBreak(Qt::TopToolBarArea);
    toolBar=addToolBar("Tool");
    toolBar->setMovable(false);
    dataBaseCount=0; //查询数据条数
    flage=1;         //打开窗口标志
    changeData=0;    //改变主题标志
    rowCount=-1;     //鼠标点击行数

    numberEdit=new QLineEdit;
    toolBar->addWidget(numberEdit);
    numberButton=new QToolButton;
    numberButton->setText("学号查询");
    numberButton->setIcon(QIcon(":/new/prefix1/image/serch.png"));
    numberButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    numberButton->setToolTip(tr("学号查询"));
    toolBar->addWidget(numberButton);


    nameEdit=new QLineEdit;
    toolBar->addWidget(nameEdit);
    nameButton=new QToolButton;
    nameButton->setIcon(QIcon(":/new/prefix1/image/serch.png"));
    nameButton->setText("姓名查询");
    nameButton->setToolTip(tr("姓名查询"));
    nameButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar->addWidget(nameButton);


    classEdit=new QLineEdit;
    toolBar->addWidget(classEdit);
    toolBar->addSeparator();
    classButton=new QToolButton;
    classButton->setText("班级查询");
    classButton->setIcon(QIcon(":/new/prefix1/image/serch.png"));
    classButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    classButton->setToolTip(tr("班级查询"));
    toolBar->addWidget(classButton);
    toolBar->addSeparator();


    importExcelButton=new QToolButton;
    importExcelButton->setIcon(QIcon(":/new/prefix1/image/excel.png"));
    importExcelButton->setIconSize(QSize(20,20));
    importExcelButton->setText("导入Excel");
    importExcelButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    importExcelButton->setToolTip(tr("导入Excel"));
    toolBar->addWidget(importExcelButton);



    extendExcelButton=new QToolButton;
    extendExcelButton->setIcon(QIcon(":/new/prefix1/image/excel.png"));
    extendExcelButton->setIconSize(QSize(20,20));
    extendExcelButton->setText("导出Excel");
    extendExcelButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    extendExcelButton->setToolTip(tr("导出Excel"));
    toolBar->addWidget(extendExcelButton);
    toolBar->setEnabled(false);

    ui->tableWidgetData->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetData->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetData->setAlternatingRowColors(true);

    //纵向隐藏序号
    QHeaderView *headerView=ui->tableWidgetData->verticalHeader();
    headerView->setHidden(true);


    QDesktopWidget *desktop=QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);  //程序显示在屏幕中间

    QFont f("宋体",9);
    ui->tableWidgetData->horizontalHeader()->setFont(f);//表头设置字体

    addControlWidget();//加载树形控件
    createActions();   //创建菜单


    /************************声明窗口类对象****************************/
    info=new StudentInfo();
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(info);

    poliIsrt=new PoliticalInsert();
    poliSect=new PoliticalSelect();
    cutIsrt=new CutSchoolInsert();
    cutSect=new CutSchoolSelect();
    notIsrt=new NotPassInsert();
    notSect=new NotPassSelect();
    honorIsrt=new HonorInsert();
    honorSect=new HonorSelect();
    dailyIsrt=new DailyInsert();
    dailySect=new DailySelect();
    outLineIsrt=new OutLineInsert();      //违规违纪录入对象
    outLineSect=new OutLineSelect();      //违规违纪查询对象
    orderCastIsrt=new OrderCastInsert();  //成绩排名录入对象
    orderCastSect=new OrderCastSelect();  //成绩排名查询对象
    notBackIsrt=new NotBackInsert();      //夜不归寝录入对象
    notBackSect=new NotBackSelect();      //夜不归寝查询对象
    gradeTestIsrt=new GradeTestInsert();  //等级考试录入对象
    gradeTestSect=new GradeTestSelect();  //等级考试查询对象
    schoolRoolIsrt=new SchoolRoolInsert();//学籍异变录入对象
    schoolRoolSect=new SchoolRoolSelect();//学籍异变查询对象
    transferIsrt=new TransferInsert();    //转学录入对象
    transferSect=new TransferSelect();    //转学查询对象
    weatherData=new WeatherData();        //天气对象
    player=new MoviePlay();               //电影播放对象
    web=new WebData();                    //网站连接对象

    /************************连接信号与槽****************************/
    connect(ui->actionEXIT,SIGNAL(triggered(bool)),this,SLOT(exitLogin()));
    connect(numberButton,SIGNAL(clicked(bool)),this,SLOT(numerSelectFlage()));
    connect(nameButton,SIGNAL(clicked(bool)),this,SLOT(nameSelectFlage()));
    connect(classButton,SIGNAL(clicked(bool)),this,SLOT(classSelectFlage()));
    connect(extendExcelButton,SIGNAL(clicked(bool)),this,SLOT(extendExcelFlage()));
    connect(importExcelButton,SIGNAL(clicked(bool)),this,SLOT(importExcelFlage()));
    connect(ui->tableWidgetData,SIGNAL(pressed(QModelIndex)),this,SLOT(selectText(QModelIndex)));
}


/**************************析构函数***************************/
MainWindow::~MainWindow()
{
    delete ui;
}


/**************************添加控件***************************/
void MainWindow::addControlWidget()
{
    /*******************************树形结构********************************/
    treeWidget=new QTreeWidget();
    ui->toolBar_2->addWidget(treeWidget);
    treeWidget->setHeaderLabel(tr("      学生信息"));
    treeWidget->header()->setStyleSheet("QHeaderView::section {background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);}");

    QTreeWidgetItem *imageStudent1=new QTreeWidgetItem(treeWidget,QStringList(QString("基本信息")));
    imageStudent1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent1_1=new QTreeWidgetItem(imageStudent1,QStringList(QString("基本信息录入")));
    imageStudent1_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent1_2=new QTreeWidgetItem(imageStudent1,QStringList(QString("基本信息查询")));
    imageStudent1_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));

    QTreeWidgetItem *imageStudent2=new QTreeWidgetItem(treeWidget,QStringList(QString("政治面貌")));
    imageStudent2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent2_1=new QTreeWidgetItem(imageStudent2,QStringList(QString("政治面貌录入")));
    imageStudent2_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent2_2=new QTreeWidgetItem(imageStudent2,QStringList(QString("政治面貌查询")));
    imageStudent2_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));

    QTreeWidgetItem *imageStudent3=new QTreeWidgetItem(treeWidget,QStringList(QString("旷课情况")));
    imageStudent3->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent3_1=new QTreeWidgetItem(imageStudent3,QStringList(QString("旷课情况录入")));
    imageStudent3_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent3_2=new QTreeWidgetItem(imageStudent3,QStringList(QString("旷课情况查询")));
    imageStudent3_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent4=new QTreeWidgetItem(treeWidget,QStringList(QString("挂科情况")));
    imageStudent4->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent4_1=new QTreeWidgetItem(imageStudent4,QStringList(QString("挂科情况录入")));
    imageStudent4_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent4_2=new QTreeWidgetItem(imageStudent4,QStringList(QString("挂科情况查询")));
    imageStudent4_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent5=new QTreeWidgetItem(treeWidget,QStringList(QString("获奖情况")));
    imageStudent5->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent5_1=new QTreeWidgetItem(imageStudent5,QStringList(QString("获奖情况录入")));
    imageStudent5_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent5_2=new QTreeWidgetItem(imageStudent5,QStringList(QString("获奖情况查询")));
    imageStudent5_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent6=new QTreeWidgetItem(treeWidget,QStringList(QString("日常情况")));
    imageStudent6->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent6_1=new QTreeWidgetItem(imageStudent6,QStringList(QString("日常情况录入")));
    imageStudent6_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent6_2=new QTreeWidgetItem(imageStudent6,QStringList(QString("日常情况查询")));
    imageStudent6_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent7=new QTreeWidgetItem(treeWidget,QStringList(QString("违规违纪")));
    imageStudent7->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent7_1=new QTreeWidgetItem(imageStudent7,QStringList(QString("违规违纪录入")));
    imageStudent7_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent7_2=new QTreeWidgetItem(imageStudent7,QStringList(QString("违规违纪查询")));
    imageStudent7_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent8=new QTreeWidgetItem(treeWidget,QStringList(QString("成绩排名")));
    imageStudent8->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent8_1=new QTreeWidgetItem(imageStudent8,QStringList(QString("成绩排名录入")));
    imageStudent8_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent8_2=new QTreeWidgetItem(imageStudent8,QStringList(QString("成绩排名查询")));
    imageStudent8_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent9=new QTreeWidgetItem(treeWidget,QStringList(QString("夜不归寝")));
    imageStudent9->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent9_1=new QTreeWidgetItem(imageStudent9,QStringList(QString("夜不归寝录入")));
    imageStudent9_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent9_2=new QTreeWidgetItem(imageStudent9,QStringList(QString("夜不归寝查询")));
    imageStudent9_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));

    QTreeWidgetItem *imageStudent10=new QTreeWidgetItem(treeWidget,QStringList(QString("等级考试")));
    imageStudent10->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent10_1=new QTreeWidgetItem(imageStudent10,QStringList(QString("等级考试录入")));
    imageStudent10_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent10_2=new QTreeWidgetItem(imageStudent10,QStringList(QString("等级考试查询")));
    imageStudent10_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));


    QTreeWidgetItem *imageStudent11=new QTreeWidgetItem(treeWidget,QStringList(QString("学籍异变")));
    imageStudent11->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent11_1=new QTreeWidgetItem(imageStudent11,QStringList(QString("学籍异变录入")));
    imageStudent11_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent11_2=new QTreeWidgetItem(imageStudent11,QStringList(QString("学籍异变查询")));
    imageStudent11_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));

    QTreeWidgetItem *imageStudent12=new QTreeWidgetItem(treeWidget,QStringList(QString("转学")));
    imageStudent12->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent12_1=new QTreeWidgetItem(imageStudent12,QStringList(QString("转学录入")));
    imageStudent12_1->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));
    QTreeWidgetItem *imageStudent12_2=new QTreeWidgetItem(imageStudent12,QStringList(QString("转学查询")));
    imageStudent12_2->setIcon(0,QIcon(":/new/prefix1/image/system-users.png"));

    QHeaderView *headTree=treeWidget->header();
    headTree->setFrameShape(QFrame::NoFrame);
    treeWidget->setMaximumWidth(190);
    treeWidget->setFrameShape(QFrame::NoFrame);
    connect(treeWidget,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(itemDoubleClicked(QTreeWidgetItem*,int)));

}


/**************************创建菜单***************************/
void MainWindow::createActions()
{
    menu=new QMenu();           //创建菜单
    update=new QAction(this);   //菜单栏项目更新
    del=new QAction(this);      //菜单栏项目删除
    update->setText(tr("更新"));//菜单栏项目粘贴
    del->setText(tr("删除"));   //菜单栏项目删除
    connect(update,SIGNAL(triggered(bool)),this,SLOT(updateData()));
    connect(del,SIGNAL(triggered(bool)),this,SLOT(deleteData()));
}


/**************************显示菜单***************************/
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    menu->clear();             //清空原有菜单栏项目
    if(flage==2)
    {
        menu->addAction(update);   //加菜单栏项目更新
        menu->addAction(del);      //加菜单栏项目删除
    }
    else
    {
        menu->addAction(del);      //加菜单栏项目删除
    }
    if(flage%2==0)
    {
        menu->exec(QCursor::pos());//在鼠标点击时出现
    }
    event->accept();               //事件响应
}

/**************************最小化***************************/
void MainWindow::changeEvent(QEvent *event)
{
    if(this->windowState()==Qt::WindowMinimized)
    {
        SuspendForm::getInstance()->setVisible(true);
        this->setVisible(false);
        connect(SuspendForm::getInstance(),SIGNAL(sendFlage(int)),this,SLOT(getFlage(int)));

    }
}

void MainWindow::getFlage(int flage)
{
    if(flage==0)
    {
        qDebug()<<"dsadsx";
        qApp->quit();
    }
    else if(flage==1)
    {
        this->setWindowFlags(Qt::Window); //显示之前恢复
        this->showNormal();
        //SuspendForm::getInstance()->close();
    }

}



/**************************退出登录***************************/
void MainWindow::exitLogin()
{
    this->close();
}


/**************************按照学号查询***********************/
void MainWindow::numerSelect()
{
    if(!numberEdit->text().isEmpty())
    {
        dataBaseCount=data.selectData(numberEdit->text(),"","");
        if(dataBaseCount==0)
        {
            ui->tableWidgetData->setRowCount(0);
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
        else if(dataBaseCount==-1)
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询出错"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }

        ui->tableWidgetData->setRowCount(dataBaseCount);
        for(int i=0;i<dataBaseCount;i++)
        {
            ui->tableWidgetData->setItem(i,0,new QTableWidgetItem(data.studentMessage[i].name));         //姓名
            ui->tableWidgetData->setItem(i,1,new QTableWidgetItem(data.studentMessage[i].sex));          //性别
            ui->tableWidgetData->setItem(i,2,new QTableWidgetItem(data.studentMessage[i].number));       //学号
            ui->tableWidgetData->setItem(i,3,new QTableWidgetItem(data.studentMessage[i].nation));       //民族
            ui->tableWidgetData->setItem(i,4,new QTableWidgetItem(data.studentMessage[i].bornDate));     //出生日期
            ui->tableWidgetData->setItem(i,5,new QTableWidgetItem(data.studentMessage[i].political));    //政治面貌
            ui->tableWidgetData->setItem(i,6,new QTableWidgetItem(data.studentMessage[i].college));      //学院
            ui->tableWidgetData->setItem(i,7,new QTableWidgetItem(data.studentMessage[i].profess));      //专业班级
            ui->tableWidgetData->setItem(i,8,new QTableWidgetItem(data.studentMessage[i].nowClass));     //当前所在班
            ui->tableWidgetData->setItem(i,9,new QTableWidgetItem(data.studentMessage[i].dormNumber));   //宿舍号
            ui->tableWidgetData->setItem(i,10,new QTableWidgetItem(data.studentMessage[i].bedNumber));   //床号
            ui->tableWidgetData->setItem(i,11,new QTableWidgetItem(data.studentMessage[i].cardNumber));  //身份证号
            ui->tableWidgetData->setItem(i,12,new QTableWidgetItem(data.studentMessage[i].bankNumber));  //银行卡号
            ui->tableWidgetData->setItem(i,13,new QTableWidgetItem(data.studentMessage[i].codeNumber));  //邮编
            ui->tableWidgetData->setItem(i,14,new QTableWidgetItem(data.studentMessage[i].QQNumber));    //QQ
            ui->tableWidgetData->setItem(i,15,new QTableWidgetItem(data.studentMessage[i].houseType));   //户口类型
            ui->tableWidgetData->setItem(i,16,new QTableWidgetItem(data.studentMessage[i].address));     //家庭住址
            ui->tableWidgetData->setItem(i,17,new QTableWidgetItem(data.studentMessage[i].origin));      //生源地
            ui->tableWidgetData->setItem(i,18,new QTableWidgetItem(data.studentMessage[i].single));      //是否单亲
            ui->tableWidgetData->setItem(i,19,new QTableWidgetItem(data.studentMessage[i].poverty));     //是否贫困
            ui->tableWidgetData->setItem(i,20,new QTableWidgetItem(data.studentMessage[i].army));        //是否服兵役
            ui->tableWidgetData->setItem(i,21,new QTableWidgetItem(data.studentMessage[i].abord));       //是否留学
            ui->tableWidgetData->setItem(i,22,new QTableWidgetItem(data.studentMessage[i].goHome));      //周末是否回家
            ui->tableWidgetData->setItem(i,23,new QTableWidgetItem(data.studentMessage[i].goRead));      //是否走读
            ui->tableWidgetData->setItem(i,24,new QTableWidgetItem(data.studentMessage[i].fatherName));  //父亲姓名
            ui->tableWidgetData->setItem(i,25,new QTableWidgetItem(data.studentMessage[i].fatherNumber));//父亲联系电话
            ui->tableWidgetData->setItem(i,26,new QTableWidgetItem(data.studentMessage[i].fatherWork));  //父亲工作单位
            ui->tableWidgetData->setItem(i,27,new QTableWidgetItem(data.studentMessage[i].motherName));  //母亲姓名
            ui->tableWidgetData->setItem(i,28,new QTableWidgetItem(data.studentMessage[i].motherNumber));//母亲联系电话
            ui->tableWidgetData->setItem(i,29,new QTableWidgetItem(data.studentMessage[i].motherWork));  //母亲工作单位
            ui->tableWidgetData->setItem(i,30,new QTableWidgetItem(data.studentMessage[i].phoneNumber)); //联系电话
        }

    }
}


/**************************按标志位查询学号********************/
void MainWindow::numerSelectFlage()
{
    if(flage==2)
    {
        this->numerSelect();
    }
    if(flage==4)
    {
        if(!numberEdit->text().isEmpty())
        {
            poliSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==6)
    {
        if(!numberEdit->text().isEmpty())
        {
            notSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==8)
    {
        if(!numberEdit->text().isEmpty())
        {
            notSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==10)
    {
        if(!numberEdit->text().isEmpty())
        {
            honorSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==14)
    {
        if(!numberEdit->text().isEmpty())
        {
            outLineSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==16)
    {
        if(!numberEdit->text().isEmpty())
        {
            orderCastSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==18)
    {
        if(!numberEdit->text().isEmpty())
        {
            notBackSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==20)
    {
        if(!numberEdit->text().isEmpty())
        {
            gradeTestSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==22)
    {
        if(!numberEdit->text().isEmpty())
        {
            schoolRoolSect->numerSelect(numberEdit->text());
        }
    }
    if(flage==24)
    {
        if(!numberEdit->text().isEmpty())
        {
            transferSect->numerSelect(numberEdit->text());
        }
    }
}


/**************************按照姓名查询************************/
void MainWindow::nameSelect()
{
    if(!nameEdit->text().isEmpty())
    {
        dataBaseCount=data.selectData("",nameEdit->text(),"");
        if(dataBaseCount==0)
        {
            ui->tableWidgetData->setRowCount(0);
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
        else if(dataBaseCount==-1)
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询出错"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }

        ui->tableWidgetData->setRowCount(dataBaseCount);
        for(int i=0;i<dataBaseCount;i++)
        {
            ui->tableWidgetData->setItem(i,0,new QTableWidgetItem(data.studentMessage[i].name));         //姓名
            ui->tableWidgetData->setItem(i,1,new QTableWidgetItem(data.studentMessage[i].sex));          //性别
            ui->tableWidgetData->setItem(i,2,new QTableWidgetItem(data.studentMessage[i].number));       //学号
            ui->tableWidgetData->setItem(i,3,new QTableWidgetItem(data.studentMessage[i].nation));       //民族
            ui->tableWidgetData->setItem(i,4,new QTableWidgetItem(data.studentMessage[i].bornDate));     //出生日期
            ui->tableWidgetData->setItem(i,5,new QTableWidgetItem(data.studentMessage[i].political));    //政治面貌
            ui->tableWidgetData->setItem(i,6,new QTableWidgetItem(data.studentMessage[i].college));      //学院
            ui->tableWidgetData->setItem(i,7,new QTableWidgetItem(data.studentMessage[i].profess));      //专业班级
            ui->tableWidgetData->setItem(i,8,new QTableWidgetItem(data.studentMessage[i].nowClass));     //当前所在班
            ui->tableWidgetData->setItem(i,9,new QTableWidgetItem(data.studentMessage[i].dormNumber));   //宿舍号
            ui->tableWidgetData->setItem(i,10,new QTableWidgetItem(data.studentMessage[i].bedNumber));   //床号
            ui->tableWidgetData->setItem(i,11,new QTableWidgetItem(data.studentMessage[i].cardNumber));  //身份证号
            ui->tableWidgetData->setItem(i,12,new QTableWidgetItem(data.studentMessage[i].bankNumber));  //银行卡号
            ui->tableWidgetData->setItem(i,13,new QTableWidgetItem(data.studentMessage[i].codeNumber));  //邮编
            ui->tableWidgetData->setItem(i,14,new QTableWidgetItem(data.studentMessage[i].QQNumber));    //QQ
            ui->tableWidgetData->setItem(i,15,new QTableWidgetItem(data.studentMessage[i].houseType));   //户口类型
            ui->tableWidgetData->setItem(i,16,new QTableWidgetItem(data.studentMessage[i].address));     //家庭住址
            ui->tableWidgetData->setItem(i,17,new QTableWidgetItem(data.studentMessage[i].origin));      //生源地
            ui->tableWidgetData->setItem(i,18,new QTableWidgetItem(data.studentMessage[i].single));      //是否单亲
            ui->tableWidgetData->setItem(i,19,new QTableWidgetItem(data.studentMessage[i].poverty));     //是否贫困
            ui->tableWidgetData->setItem(i,20,new QTableWidgetItem(data.studentMessage[i].army));        //是否服兵役
            ui->tableWidgetData->setItem(i,21,new QTableWidgetItem(data.studentMessage[i].abord));       //是否留学
            ui->tableWidgetData->setItem(i,22,new QTableWidgetItem(data.studentMessage[i].goHome));      //周末是否回家
            ui->tableWidgetData->setItem(i,23,new QTableWidgetItem(data.studentMessage[i].goRead));      //是否走读
            ui->tableWidgetData->setItem(i,24,new QTableWidgetItem(data.studentMessage[i].fatherName));  //父亲姓名
            ui->tableWidgetData->setItem(i,25,new QTableWidgetItem(data.studentMessage[i].fatherNumber));//父亲联系电话
            ui->tableWidgetData->setItem(i,26,new QTableWidgetItem(data.studentMessage[i].fatherWork));  //父亲工作单位
            ui->tableWidgetData->setItem(i,27,new QTableWidgetItem(data.studentMessage[i].motherName));  //母亲姓名
            ui->tableWidgetData->setItem(i,28,new QTableWidgetItem(data.studentMessage[i].motherNumber));//母亲联系电话
            ui->tableWidgetData->setItem(i,29,new QTableWidgetItem(data.studentMessage[i].motherWork));  //母亲工作单位
            ui->tableWidgetData->setItem(i,30,new QTableWidgetItem(data.studentMessage[i].phoneNumber)); //联系电话

        }

    }

}


/********************按标志位查询姓名***************************/
void MainWindow::nameSelectFlage()
{
    if(flage==2)
    {
        this->nameSelect();
    }
    if(flage==4)
    {
        if(!nameEdit->text().isEmpty())
        {
            poliSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==6)
    {
        if(!nameEdit->text().isEmpty())
        {
            cutSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==8)
    {
        if(!nameEdit->text().isEmpty())
        {
            notSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==10)
    {
        if(!nameEdit->text().isEmpty())
        {
            honorSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==14)
    {
        if(!nameEdit->text().isEmpty())
        {
            outLineSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==16)
    {
        if(!nameEdit->text().isEmpty())
        {
            orderCastSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==18)
    {
        if(!nameEdit->text().isEmpty())
        {
            notBackSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==20)
    {
        if(!nameEdit->text().isEmpty())
        {
            gradeTestSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==22)
    {
        if(!nameEdit->text().isEmpty())
        {
            schoolRoolSect->nameSelect(nameEdit->text());
        }
    }
    if(flage==24)
    {
        if(!nameEdit->text().isEmpty())
        {
            transferSect->nameSelect(nameEdit->text());
        }
    }
}


/**************************按照班级查询***********************/
void MainWindow::classSelect()
{
    if(!classEdit->text().isEmpty())
    {
        dataBaseCount=data.selectData("","",classEdit->text());
        if(dataBaseCount==0)
        {
            ui->tableWidgetData->setRowCount(0);
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，无数据！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
        else if(dataBaseCount==-1)
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，查询出错"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }

        ui->tableWidgetData->setRowCount(dataBaseCount);
        for(int i=0;i<dataBaseCount;i++)
        {
            ui->tableWidgetData->setItem(i,0,new QTableWidgetItem(data.studentMessage[i].name));         //姓名
            ui->tableWidgetData->setItem(i,1,new QTableWidgetItem(data.studentMessage[i].sex));          //性别
            ui->tableWidgetData->setItem(i,2,new QTableWidgetItem(data.studentMessage[i].number));       //学号
            ui->tableWidgetData->setItem(i,3,new QTableWidgetItem(data.studentMessage[i].nation));       //民族
            ui->tableWidgetData->setItem(i,4,new QTableWidgetItem(data.studentMessage[i].bornDate));     //出生日期
            ui->tableWidgetData->setItem(i,5,new QTableWidgetItem(data.studentMessage[i].political));    //政治面貌
            ui->tableWidgetData->setItem(i,6,new QTableWidgetItem(data.studentMessage[i].college));      //学院
            ui->tableWidgetData->setItem(i,7,new QTableWidgetItem(data.studentMessage[i].profess));      //专业班级
            ui->tableWidgetData->setItem(i,8,new QTableWidgetItem(data.studentMessage[i].nowClass));     //当前所在班
            ui->tableWidgetData->setItem(i,9,new QTableWidgetItem(data.studentMessage[i].dormNumber));   //宿舍号
            ui->tableWidgetData->setItem(i,10,new QTableWidgetItem(data.studentMessage[i].bedNumber));   //床号
            ui->tableWidgetData->setItem(i,11,new QTableWidgetItem(data.studentMessage[i].cardNumber));  //身份证号
            ui->tableWidgetData->setItem(i,12,new QTableWidgetItem(data.studentMessage[i].bankNumber));  //银行卡号
            ui->tableWidgetData->setItem(i,13,new QTableWidgetItem(data.studentMessage[i].codeNumber));  //邮编
            ui->tableWidgetData->setItem(i,14,new QTableWidgetItem(data.studentMessage[i].QQNumber));    //QQ
            ui->tableWidgetData->setItem(i,15,new QTableWidgetItem(data.studentMessage[i].houseType));   //户口类型
            ui->tableWidgetData->setItem(i,16,new QTableWidgetItem(data.studentMessage[i].address));     //家庭住址
            ui->tableWidgetData->setItem(i,17,new QTableWidgetItem(data.studentMessage[i].origin));      //生源地
            ui->tableWidgetData->setItem(i,18,new QTableWidgetItem(data.studentMessage[i].single));      //是否单亲
            ui->tableWidgetData->setItem(i,19,new QTableWidgetItem(data.studentMessage[i].poverty));     //是否贫困
            ui->tableWidgetData->setItem(i,20,new QTableWidgetItem(data.studentMessage[i].army));        //是否服兵役
            ui->tableWidgetData->setItem(i,21,new QTableWidgetItem(data.studentMessage[i].abord));       //是否留学
            ui->tableWidgetData->setItem(i,22,new QTableWidgetItem(data.studentMessage[i].goHome));      //周末是否回家
            ui->tableWidgetData->setItem(i,23,new QTableWidgetItem(data.studentMessage[i].goRead));      //是否走读
            ui->tableWidgetData->setItem(i,24,new QTableWidgetItem(data.studentMessage[i].fatherName));  //父亲姓名
            ui->tableWidgetData->setItem(i,25,new QTableWidgetItem(data.studentMessage[i].fatherNumber));//父亲联系电话
            ui->tableWidgetData->setItem(i,26,new QTableWidgetItem(data.studentMessage[i].fatherWork));  //父亲工作单位
            ui->tableWidgetData->setItem(i,27,new QTableWidgetItem(data.studentMessage[i].motherName));  //母亲姓名
            ui->tableWidgetData->setItem(i,28,new QTableWidgetItem(data.studentMessage[i].motherNumber));//母亲联系电话
            ui->tableWidgetData->setItem(i,29,new QTableWidgetItem(data.studentMessage[i].motherWork));  //母亲工作单位
            ui->tableWidgetData->setItem(i,30,new QTableWidgetItem(data.studentMessage[i].phoneNumber)); //联系电话

        }

    }
}


/********************按标志位查询班级*****************/
void MainWindow::classSelectFlage()
{
    if(flage==2)
    {
        this->classSelect();
    }
    if(flage==4)
    {
        if(!classEdit->text().isEmpty())
        {
            poliSect->classSelect(classEdit->text());
        }
    }
    if(flage==6)
    {
        if(!classEdit->text().isEmpty())
        {
            cutSect->classSelect(classEdit->text());
        }
    }
    if(flage==8)
    {
        if(!classEdit->text().isEmpty())
        {
            notSect->classSelect(classEdit->text());
        }
    }
    if(flage==10)
    {
        if(!classEdit->text().isEmpty())
        {
            honorSect->classSelect(classEdit->text());
        }
    }
    if(flage==14)
    {
        if(!classEdit->text().isEmpty())
        {
            outLineSect->classSelect(classEdit->text());
        }
    }
    if(flage==16)
    {
        if(!classEdit->text().isEmpty())
        {
            orderCastSect->classSelect(classEdit->text());
        }
    }
    if(flage==18)
    {
        if(!classEdit->text().isEmpty())
        {
            notBackSect->classSelect(classEdit->text());
        }
    }
    if(flage==20)
    {
        if(!classEdit->text().isEmpty())
        {
            gradeTestSect->classSelect(classEdit->text());
        }
    }
    if(flage==22)
    {
        if(!classEdit->text().isEmpty())
        {
            schoolRoolSect->classSelect(classEdit->text());
        }
    }
    if(flage==24)
    {
        if(!classEdit->text().isEmpty())
        {
            transferSect->classSelect(classEdit->text());
        }
    }
}


/**************************树结构****************************/
void MainWindow::itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    QTreeWidgetItem*parent=item->parent();//获取其父节点
    if(parent==NULL)
    {
        return;                           //如果是最顶端节点，返回
    }
    if(parent->text(column)==tr("基本信息"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=1;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(info);
        }
        if(col==1)
        {
            flage=2;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(ui->centralWidget);
        }
    }
    if(parent->text(column)==tr("政治面貌"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=3;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(poliIsrt);
        }
        if(col==1)
        {
            flage=4;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(poliSect);
        }
    }


    if(parent->text(column)==tr("旷课情况"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=5;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(cutIsrt);
        }
        if(col==1)
        {
            flage=6;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(cutSect);
        }
    }
    if(parent->text(column)==tr("挂科情况"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=7;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(notIsrt);
        }
        if(col==1)
        {
            flage=8;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(notSect);
        }
    }
    if(parent->text(column)==tr("获奖情况"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=9;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(honorIsrt);
        }
        if(col==1)
        {
            flage=10;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(honorSect);
        }
    }
    if(parent->text(column)==tr("日常情况"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=11;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(dailyIsrt);
        }
        if(col==1)
        {
            flage=12;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(dailySect);
        }
    }
    if(parent->text(column)==tr("违规违纪"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=13;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(outLineIsrt);
        }
        if(col==1)
        {
            flage=14;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(outLineSect);
        }
    }
    if(parent->text(column)==tr("成绩排名"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=15;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(orderCastIsrt);
        }
        if(col==1)
        {
            flage=16;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(orderCastSect);
        }
    }
    if(parent->text(column)==tr("夜不归寝"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=17;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(notBackIsrt);
        }
        if(col==1)
        {
            flage=18;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(notBackSect);
        }
    }
    if(parent->text(column)==tr("等级考试"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=19;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(gradeTestIsrt);
        }
        if(col==1)
        {
            flage=20;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(gradeTestSect);
        }
    }
    if(parent->text(column)==tr("学籍异变"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=21;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(schoolRoolIsrt);
        }
        if(col==1)
        {
            flage=22;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(schoolRoolSect);
        }
    }
    if(parent->text(column)==tr("转学"))
    {
        int  col=parent->indexOfChild(item);  //item在父项中的节点行号
        if(col==0)
        {
            flage=23;
            toolBar->setEnabled(false);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(transferIsrt);
        }
        if(col==1)
        {
            flage=24;
            toolBar->setEnabled(true);
            if(this->centralWidget())
            {
                this->centralWidget()->setParent(NULL);
            }
            this->setCentralWidget(transferSect);
        }
    }


}


/**************************导出Excel*************************/
void MainWindow::extendExcel()
{
    /******************初始化数据********************/
    QProgressBar *gressBar=new QProgressBar();//创建进度条
    QStatusBar*statusBar=new QStatusBar();
    this->setStatusBar(statusBar);
    statusBar->addWidget(gressBar);       //把进度条加到状态栏
    gressBar->setMinimumWidth(this->width()); //设置进度条宽度
    int dataCount=0;
    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;


    QString fileName=QFileDialog::getSaveFileName(NULL,tr("保存文件"),".","Excel(*.xlsx *.xls)");
    if(fileName.isEmpty())
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        return;
    }


    excel=new QAxObject("Excel.Application");            //加载Excel驱动
    excel->setProperty("Visible",false);                 //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");
    workBooks->dynamicCall("Add");
    workBook=excel->querySubObject("ActiveWorkBook");
    workSheets=workBook->querySubObject("Sheets");       //Sheets可换做WorkSheets
    workSheet=workBook->querySubObject("Sheets(int)",1); //读取第一个工作表中的内容

    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",1,1); //循环获取单元格中数据
    cell->setProperty("Value","姓名");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,2); //循环获取单元格中数据
    cell->setProperty("Value","性别");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,3); //循环获取单元格中数据
    cell->setProperty("Value","学号");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,4); //循环获取单元格中数据
    cell->setProperty("Value","民族");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,5); //循环获取单元格中数据
    cell->setProperty("Value","出生日期");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,6); //循环获取单元格中数据
    cell->setProperty("Value","政治面貌");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,7); //循环获取单元格中数据
    cell->setProperty("Value","学院");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,8); //循环获取单元格中数据
    cell->setProperty("Value","专业班级");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,9); //循环获取单元格中数据
    cell->setProperty("Value","当前所在班");       //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,10); //循环获取单元格中数据
    cell->setProperty("Value","宿舍号");          //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,11); //循环获取单元格中数据
    cell->setProperty("Value","床号");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,12); //循环获取单元格中数据
    cell->setProperty("Value","身份证号");         //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,13); //循环获取单元格中数据
    cell->setProperty("Value","银行卡号");         //写单元格值
    cell=workSheet->querySubObject("Cells(int,int)",1,14); //循环获取单元格中数据
    cell->setProperty("Value","邮编");            //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,15); //循环获取单元格中数据
    cell->setProperty("Value","QQ");             //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,16); //循环获取单元格中数据
    cell->setProperty("Value","户口类型");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,17); //循环获取单元格中数据
    cell->setProperty("Value","家庭住址");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,18); //循环获取单元格中数据
    cell->setProperty("Value","生源地");          //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,19); //循环获取单元格中数据
    cell->setProperty("Value","是否单亲");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,20); //循环获取单元格中数据
    cell->setProperty("Value","是否贫困");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,21); //循环获取单元格中数据
    cell->setProperty("Value","是否服兵役");      //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,22); //循环获取单元格中数据
    cell->setProperty("Value","是否留学");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,23); //循环获取单元格中数据
    cell->setProperty("Value","周末是否回家");     //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,24); //循环获取单元格中数据
    cell->setProperty("Value","是否走读");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,25); //循环获取单元格中数据
    cell->setProperty("Value","父亲姓名");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,26); //循环获取单元格中数据
    cell->setProperty("Value","父亲联系电话");     //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,27); //循环获取单元格中数据
    cell->setProperty("Value","父亲工作单位");     //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,28); //循环获取单元格中数据
    cell->setProperty("Value","母亲姓名");        //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,29); //循环获取单元格中数据
    cell->setProperty("Value","母亲联系电话");     //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,30); //循环获取单元格中数据
    cell->setProperty("Value","母亲工作单位");     //写单元格值
    cell->clear();
    cell=workSheet->querySubObject("Cells(int,int)",1,31); //循环获取单元格中数据
    cell->setProperty("Value","联系电话");        //写单元格值
    cell->clear();

    gressBar->setRange(0,dataBaseCount);
    /*******************************写入单元格数据***************************/
    for(int i=2;i<dataBaseCount+2;i++)
    {
        for(int j=1;j<32;j++)
        {
            cell->clear();
            cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据

            dataCount=i-2;

            switch(j)
            {
            case 1:cell->setProperty("Value",data.studentMessage[dataCount].name);     break;    //写单元格值
            case 2:cell->setProperty("Value",data.studentMessage[dataCount].sex);     break;     //写单元格值
            case 3:cell->setProperty("Value",data.studentMessage[dataCount].number);break;       //写单元格值
            case 4:cell->setProperty("Value",data.studentMessage[dataCount].nation);break;       //写单元格值
            case 5:cell->setProperty("Value",data.studentMessage[dataCount].bornDate);break;     //写单元格值
            case 6:cell->setProperty("Value",data.studentMessage[dataCount].political);break;    //写单元格值
            case 7:cell->setProperty("Value",data.studentMessage[dataCount].college);break;      //写单元格值
            case 8:cell->setProperty("Value",data.studentMessage[dataCount].profess);break;      //写单元格值
            case 9:cell->setProperty("Value",data.studentMessage[dataCount].nowClass);break;     //写单元格值
            case 10:cell->setProperty("Value",data.studentMessage[dataCount].dormNumber);break;  //写单元格值
            case 11:cell->setProperty("Value",data.studentMessage[dataCount].bedNumber);break;   //写单元格值
            case 12:cell->setProperty("Value",data.studentMessage[dataCount].cardNumber);break;  //写单元格值
            case 13:cell->setProperty("Value",data.studentMessage[dataCount].bankNumber);break;  //写单元格值
            case 14:cell->setProperty("Value",data.studentMessage[dataCount].codeNumber);break;  //写单元格值
            case 15:cell->setProperty("Value",data.studentMessage[dataCount].QQNumber);break;    //写单元格值
            case 16:cell->setProperty("Value",data.studentMessage[dataCount].houseType);break;   //写单元格值
            case 17:cell->setProperty("Value",data.studentMessage[dataCount].address);break;     //写单元格值
            case 18:cell->setProperty("Value",data.studentMessage[dataCount].origin);break;      //写单元格值
            case 19:cell->setProperty("Value",data.studentMessage[dataCount].single);break;      //写单元格值
            case 20:cell->setProperty("Value",data.studentMessage[dataCount].poverty);break;     //写单元格值
            case 21:cell->setProperty("Value",data.studentMessage[dataCount].army);break;        //写单元格值
            case 22:cell->setProperty("Value",data.studentMessage[dataCount].abord);break;       //写单元格值
            case 23:cell->setProperty("Value",data.studentMessage[dataCount].goHome);break;      //写单元格值
            case 24:cell->setProperty("Value",data.studentMessage[dataCount].goRead);break;      //写单元格值
            case 25:cell->setProperty("Value",data.studentMessage[dataCount].fatherName);break;  //写单元格值
            case 26:cell->setProperty("Value",data.studentMessage[dataCount].fatherNumber);break;//写单元格值
            case 27:cell->setProperty("Value",data.studentMessage[dataCount].fatherWork);break;  //写单元格值
            case 28:cell->setProperty("Value",data.studentMessage[dataCount].motherName);break;  //写单元格值
            case 29:cell->setProperty("Value",data.studentMessage[dataCount].motherNumber);break;//写单元格值
            case 30:cell->setProperty("Value",data.studentMessage[dataCount].motherWork);break;  //写单元格值
            case 31:cell->setProperty("Value",data.studentMessage[dataCount].phoneNumber);break; //写单元格值
            }


        }
        gressBar->setValue(i-1);
    }


    workBook->dynamicCall("SaveAs(const Qstring&)",QDir::toNativeSeparators(fileName));//保存文件
    workBook->dynamicCall("Close(Boolen)",false);  //关闭
    excel->dynamicCall("Quit(void)");              //退出
    gressBar->deleteLater();
    statusBar->deleteLater();
    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，导出Excel成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
    MessageDialog::getInstance()->exec();
}


/**************************导入Excel*************************/
void MainWindow::importExcel()
{
    QProgressBar *gressBar=new QProgressBar();
    QStatusBar*statusBar=new QStatusBar();
    this->setStatusBar(statusBar);
    statusBar->addWidget(gressBar);
    gressBar->setMinimumWidth(this->width());


    /******************初始化数据********************/
    int Count=0;
    int dataCount=0;

    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;

    QRegExp rx;                                    //正则表达式
    rx.setPatternSyntax(QRegExp::RegExp);          //将元字符设置为统配模式下
    rx.setCaseSensitivity(Qt::CaseSensitive);      //大小写敏感
    excel=new QAxObject("Excel.Application");      //加载Excel驱动
    excel->setProperty("Visible",false);           //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");
    QString fileName=QFileDialog::getOpenFileName(this,tr("打开文件对话框"),"/","excel(*.xlsx *.xls);");//获取路径
    QFileInfo fileInfo;                    //读取文件后缀名
    fileInfo=QFileInfo(fileName);
    QString suffixName=fileInfo.suffix();  //获取文件后缀名
    if(suffixName.isEmpty())
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        return;
    }


    if(suffixName!=tr("xlsx")&&suffixName!=tr("xls"))
    {
        gressBar->deleteLater();
        statusBar->deleteLater();
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，导入格式不正确！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }

    if(!fileName.isEmpty())
    {
        workBooks->dynamicCall("Open(const QString &)",fileName);  //打开指定文件
        workBook=excel->querySubObject("ACtiveWorkBook");
        workSheets=workBook->querySubObject("Sheets");             //Sheets可换做WorkSheets
        int sheetCount=workSheets->property("Count").toInt();      //获取工作表数目


        if(sheetCount>0)
        {

            workSheet=workBook->querySubObject("Sheets(int)",1);        //读取第一个工作表中的内容
            QAxObject *usedRange=workSheet->querySubObject("UsedRange");//求出该表的数据的可用范围
            QAxObject *Rows=usedRange->querySubObject("Rows");          //创建行对象
            QAxObject *columns=usedRange->querySubObject("Columns");    //创建列对象
            int startRow=usedRange->property("Row").toInt();            //获取开始行
            int startColumn=usedRange->property("Column").toInt();      //获取开始列
            int rowCount=Rows->property("Count").toInt();               //获取总共多少行
            int columnCount=columns->property("Count").toInt();         //获取总共多少列

            gressBar->setRange(0,rowCount-1);
            /*******************************获取单元格中数据***************************/
            for(int i=startRow+1;i<startRow+rowCount;i++)
            {
                for(int j=startColumn;j<startColumn+columnCount;j++)
                {

                    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据
                    QVariant cellValue=cell->property("Value");                      //得到单元格值

                    if(columnCount!=31)
                    {
                        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，导入格式不正确！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                        MessageDialog::getInstance()->exec();
                        workBook->dynamicCall("Close(Boolen)",false);  //关闭
                        excel->dynamicCall("Quit(void)");              //退出
                        gressBar->deleteLater();
                        statusBar->deleteLater();
                        return;
                    }
                    if(Count%31==0)
                    {
                        dataCount++;
                    }
                    if(j==startColumn)
                    {
                        data.name=cellValue.toString();
                    }
                    else if(j==startColumn+1)
                    {
                        data.sex=cellValue.toString();
                    }
                    else if(j==startColumn+2)
                    {
                        if(cellValue.toString().isEmpty())
                        {
                            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号为空！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                            MessageDialog::getInstance()->exec();
                            gressBar->deleteLater();
                            statusBar->deleteLater();
                            workBook->dynamicCall("Close(Boolen)",false);  //关闭
                            excel->dynamicCall("Quit(void)");              //退出
                            return;
                        }
                        else
                        {
                            rx.setPattern(QString("[1-9][0-9]{9}"));    //匹配学号10位
                            if(rx.exactMatch(cellValue.toString()))
                            {
                                data.number=cellValue.toString();
                            }
                            else
                            {
                                MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学号错误,请检查学号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                                MessageDialog::getInstance()->exec();
                                gressBar->deleteLater();
                                statusBar->deleteLater();
                                workBook->dynamicCall("Close(Boolen)",false);  //关闭
                                excel->dynamicCall("Quit(void)");              //退出
                                return;
                            }
                        }
                    }
                    else if(j==startColumn+3)
                    {
                        data.nation=cellValue.toString();
                    }
                    else if(j==startColumn+4)
                    {
                        data.bornDate=cellValue.toString();
                    }
                    else if(j==startColumn+5)
                    {
                        data.political=cellValue.toString();
                    }
                    else if(j==startColumn+6)
                    {
                        data.college=cellValue.toString();
                    }
                    else if(j==startColumn+7)
                    {
                        data.profess=cellValue.toString();
                    }
                    else if(j==startColumn+8)
                    {
                        data.nowClass=cellValue.toString();
                    }
                    else if(j==startColumn+9)
                    {
                        data.dormNumber=cellValue.toString();
                    }
                    else if(j==startColumn+10)
                    {
                        data.bedNumber=cellValue.toString();
                    }
                    else if(j==startColumn+11)
                    {
                        if(!cellValue.toString().isEmpty())
                        {
                            rx.setPattern(QString("[0-9]{15,18}"));    //匹配身份证号15位或18位
                            if(rx.exactMatch(cellValue.toString()))
                            {
                                data.cardNumber=cellValue.toString();
                            }
                            else
                            {
                                MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，身份证号错误,请检查身份证号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                                MessageDialog::getInstance()->exec();
                                gressBar->deleteLater();
                                statusBar->deleteLater();
                                workBook->dynamicCall("Close(Boolen)",false);  //关闭
                                excel->dynamicCall("Quit(void)");              //退出
                                return;
                            }
                        }
                        else
                        {
                            data.cardNumber=cellValue.toString();
                        }

                    }
                    else if(j==startColumn+12)
                    {
                        if(!cellValue.toString().isEmpty())
                        {
                            rx.setPattern(QString("[0-9]{16,19}"));    //匹配银行卡号16位或19位
                            if(rx.exactMatch(cellValue.toString()))
                            {
                                data.bankNumber=cellValue.toString();
                            }
                            else
                            {
                                MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，银行卡号错误,请检查银行卡号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
                                MessageDialog::getInstance()->exec();
                                gressBar->deleteLater();
                                statusBar->deleteLater();
                                workBook->dynamicCall("Close(Boolen)",false);  //关闭
                                excel->dynamicCall("Quit(void)");              //退出
                                return;
                            }
                        }
                        else
                        {
                            data.bankNumber=cellValue.toString();
                        }

                    }
                    else if(j==startColumn+13)
                    {
                        data.codeNumber=cellValue.toString();
                    }
                    else if(j==startColumn+14)
                    {
                        data.QQNumber=cellValue.toString();
                    }
                    else if(j==startColumn+15)
                    {
                        data.houseType=cellValue.toString();
                    }
                    else if(j==startColumn+16)
                    {
                        data.address=cellValue.toString();
                    }
                    else if(j==startColumn+17)
                    {
                        data.origin=cellValue.toString();
                    }
                    else if(j==startColumn+18)
                    {
                        data.single=cellValue.toString();
                    }
                    else if(j==startColumn+19)
                    {
                        data.poverty=cellValue.toString();
                    }
                    else if(j==startColumn+20)
                    {
                        data.army=cellValue.toString();
                    }
                    else if(j==startColumn+21)
                    {
                        data.abord=cellValue.toString();
                    }
                    else if(j==startColumn+22)
                    {
                        data.goHome=cellValue.toString();
                    }
                    else if(j==startColumn+23)
                    {
                        data.goRead=cellValue.toString();
                    }
                    else if(j==startColumn+24)
                    {
                        data.fatherName=cellValue.toString();
                    }
                    else if(j==startColumn+25)
                    {
                        data.fatherNumber=cellValue.toString();
                    }
                    else if(j==startColumn+26)
                    {
                        data.fatherWork=cellValue.toString();
                    }
                    else if(j==startColumn+27)
                    {
                        data.motherName=cellValue.toString();
                    }
                    else if(j==startColumn+28)
                    {
                        data.motherNumber=cellValue.toString();
                    }
                    else if(j==startColumn+29)
                    {
                        data.motherWork=cellValue.toString();
                    }
                    else if(j==startColumn+30)
                    {
                        data.phoneNumber=cellValue.toString();
                    }
                    Count++;
                }
                data.insertData();
                gressBar->setValue(i-startRow);
            }
        }
        workBook->dynamicCall("Close(Boolen)",false);  //关闭
        excel->dynamicCall("Quit(void)");              //退出
        gressBar->deleteLater();
        statusBar->deleteLater();
    }

    MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，导入Excel成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
    MessageDialog::getInstance()->exec();

}


/**************************按标志位导出Excel*************************/
void MainWindow::extendExcelFlage()
{
    if(flage==2)
    {
        //开辟一个子线程
        winMainThread *winMain=new winMainThread(this,ONE);
        winMain->run(); //运行线程
        connect(winMain,SIGNAL(finished()),winMain,SLOT(terminate()));
    }
    if(flage==4)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        PoliticalThread *politicalThread=new PoliticalThread(poliSect,statusBar,this->width(),ONE);
        connect(politicalThread,SIGNAL(finished()),politicalThread,SLOT(terminate()));
        politicalThread->run();
    }
    if(flage==6)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        CutSchoolThread *cutSchoolThread=new CutSchoolThread(cutSect,statusBar,this->width(),ONE);
        connect(cutSchoolThread,SIGNAL(finished()),cutSchoolThread,SLOT(terminate()));
        cutSchoolThread->run();
    }
    if(flage==8)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        NotPassThread *notPassThread=new NotPassThread(notSect,statusBar,this->width(),ONE);
        connect(notPassThread,SIGNAL(finished()),notPassThread,SLOT(terminate()));
        notPassThread->run();
    }
    if(flage==10)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        HonorThread *honorThread=new HonorThread(honorSect,statusBar,this->width(),ONE);
        connect(honorThread,SIGNAL(finished()),honorThread,SLOT(terminate()));
        honorThread->run();
    }
    if(flage==12)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        DailyThread *dailyThread=new DailyThread(dailySect,statusBar,this->width(),ONE);
        connect(dailyThread,SIGNAL(finished()),dailyThread,SLOT(terminate()));
        dailyThread->run();
    }
    if(flage==14)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        OutLineThread *outLineThread=new OutLineThread(outLineSect,statusBar,this->width(),ONE);
        connect(outLineThread,SIGNAL(finished()),outLineThread,SLOT(terminate()));
        outLineThread->run();
    }
    if(flage==16)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        OrderCastThread *outLineThread=new OrderCastThread(orderCastSect,statusBar,this->width(),ONE);
        connect(outLineThread,SIGNAL(finished()),outLineThread,SLOT(terminate()));
        outLineThread->run();
    }
    if(flage==18)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        NotBackThread *notBackThread=new NotBackThread(notBackSect,statusBar,this->width(),ONE);
        connect(notBackThread,SIGNAL(finished()),notBackThread,SLOT(terminate()));
        notBackThread->run();
    }
    if(flage==20)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        GradeTestThread *gradeTestThread=new GradeTestThread(gradeTestSect,statusBar,this->width(),ONE);
        connect(gradeTestThread,SIGNAL(finished()),gradeTestThread,SLOT(terminate()));
        gradeTestThread->run();
    }
    if(flage==22)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        SchoolRoolThread *schoolRoolThread=new SchoolRoolThread(schoolRoolSect,statusBar,this->width(),ONE);
        connect(schoolRoolThread,SIGNAL(finished()),schoolRoolThread,SLOT(terminate()));
        schoolRoolThread->run();
    }
    if(flage==24)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        TransferThread *transferThread=new TransferThread(transferSect,statusBar,this->width(),ONE);
        connect(transferThread,SIGNAL(finished()),transferThread,SLOT(terminate()));
        transferThread->run();
    }
}


/**************************按标志位导入Excel*************************/
void MainWindow::importExcelFlage()
{
    if(flage==2)
    {
        //开辟一个子线程
        winMainThread *winMain=new winMainThread(this,TWO);
        winMain->run(); //运行线程
        connect(winMain,SIGNAL(finished()),winMain,SLOT(terminate()));
    }
    if(flage==4)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        PoliticalThread *politicalThread=new PoliticalThread(poliSect,statusBar,this->width(),TWO);
        connect(politicalThread,SIGNAL(finished()),politicalThread,SLOT(terminate()));
        politicalThread->run();
    }
    if(flage==6)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        CutSchoolThread *cutSchoolThread=new CutSchoolThread(cutSect,statusBar,this->width(),TWO);
        connect(cutSchoolThread,SIGNAL(finished()),cutSchoolThread,SLOT(terminate()));
        cutSchoolThread->run();
    }
    if(flage==8)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        NotPassThread *notPassThread=new NotPassThread(notSect,statusBar,this->width(),TWO);
        connect(notPassThread,SIGNAL(finished()),notPassThread,SLOT(terminate()));
        notPassThread->run();
    }
    if(flage==10)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        HonorThread *honorThread=new HonorThread(honorSect,statusBar,this->width(),TWO);
        connect(honorThread,SIGNAL(finished()),honorThread,SLOT(terminate()));
        honorThread->run();
    }
    if(flage==12)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        DailyThread *dailyThread=new DailyThread(dailySect,statusBar,this->width(),TWO);
        connect(dailyThread,SIGNAL(finished()),dailyThread,SLOT(terminate()));
        dailyThread->run();
    }
    if(flage==14)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        OutLineThread *outLineThread=new OutLineThread(outLineSect,statusBar,this->width(),TWO);
        connect(outLineThread,SIGNAL(finished()),outLineThread,SLOT(terminate()));
        outLineThread->run();
    }
    if(flage==16)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        OrderCastThread *outLineThread=new OrderCastThread(orderCastSect,statusBar,this->width(),TWO);
        connect(outLineThread,SIGNAL(finished()),outLineThread,SLOT(terminate()));
        outLineThread->run();
    }
    if(flage==18)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        NotBackThread *notBackThread=new NotBackThread(notBackSect,statusBar,this->width(),TWO);
        connect(notBackThread,SIGNAL(finished()),notBackThread,SLOT(terminate()));
        notBackThread->run();
    }
    if(flage==20)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        GradeTestThread *gradeTestThread=new GradeTestThread(gradeTestSect,statusBar,this->width(),TWO);
        connect(gradeTestThread,SIGNAL(finished()),gradeTestThread,SLOT(terminate()));
        gradeTestThread->run();
    }
    if(flage==22)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        SchoolRoolThread *schoolRoolThread=new SchoolRoolThread(schoolRoolSect,statusBar,this->width(),TWO);
        connect(schoolRoolThread,SIGNAL(finished()),schoolRoolThread,SLOT(terminate()));
        schoolRoolThread->run();
    }
    if(flage==24)
    {
        QStatusBar*statusBar=new QStatusBar();
        this->setStatusBar(statusBar);
        TransferThread *transferThread=new TransferThread(transferSect,statusBar,this->width(),TWO);
        connect(transferThread,SIGNAL(finished()),transferThread,SLOT(terminate()));
        transferThread->run();
    }
}


/**************************更新数据*************************/
void MainWindow::updateData()
{

    if(flage==2)
    {
        if(data.number.isEmpty())
        {
            return;
        }
        if(data.updateData())
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，更新成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
            MessageDialog::getInstance()->exec();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，更新失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
        }

    }
}


/**************************删除数据*************************/
void MainWindow::deleteData()
{
    if(flage==2)
    {
        if(data.number.isEmpty())
        {
            return;
        }
        if(data.deleteData())
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，删除成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
            MessageDialog::getInstance()->exec();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，删除失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();

        }
        if(rowCount!=-1)
        {
            ui->tableWidgetData->removeRow(rowCount);//移除删除的一行
        }

    }
    if(flage==4)
    {
        poliSect->deleteData();
    }
    if(flage==6)
    {
        cutSect->deleteData();
    }
    if(flage==8)
    {
        notSect->deleteData();
    }
    if(flage==10)
    {
        honorSect->deleteData();
    }
    if(flage==12)
    {
        dailySect->deleteData();
    }
    if(flage==14)
    {
        outLineSect->deleteData();
    }
    if(flage==16)
    {
        orderCastSect->deleteData();
    }
    if(flage==18)
    {
        notBackSect->deleteData();
    }
    if(flage==20)
    {
        gradeTestSect->deleteData();
    }
    if(flage==22)
    {
        schoolRoolSect->deleteData();
    }
    if(flage==24)
    {
        transferSect->deleteData();
    }
}


/**************************表格控件**************************/
void MainWindow::selectText(const QModelIndex &index)
{

    rowCount=index.row();
    if(flage==2)
    {
        for(int i=0;i<31;i++)
        {
            QTableWidgetItem*item=ui->tableWidgetData->item(index.row(),i);
            switch(i)
            {
            case 0:data.name=item->text(); break;
            case 1:data.sex=item->text();break;
            case 2:data.number=item->text();break;
            case 3:data.nation=item->text();break;
            case 4:data.bornDate=item->text();break;
            case 5:data.political=item->text();break;
            case 6:data.college=item->text();break;
            case 7:data.profess=item->text();break;
            case 8:data.nowClass=item->text();break;
            case 9:data.dormNumber=item->text();break;
            case 10:data.bedNumber=item->text();break;
            case 11:data.cardNumber=item->text();break;
            case 12:data.bankNumber=item->text();break;
            case 13:data.codeNumber=item->text();break;
            case 14:data.QQNumber=item->text();break;
            case 15:data.houseType=item->text();break;
            case 16:data.address=item->text();break;
            case 17:data.origin=item->text();break;
            case 18:data.single=item->text();break;
            case 19:data.poverty=item->text();break;
            case 20:data.army=item->text();break;
            case 21:data.abord=item->text();break;
            case 22:data.goHome=item->text();break;
            case 23:data.goRead=item->text();break;
            case 24:data.fatherName=item->text();break;
            case 25:data.fatherNumber=item->text();break;
            case 26:data.fatherWork=item->text();break;
            case 27:data.motherName=item->text();break;
            case 28:data.motherNumber=item->text();break;
            case 29:data.motherWork=item->text();break;
            case 30:data.phoneNumber=item->text();break;
            }
        }
    }


}


/**************************改变主题**************************/
void MainWindow::on_actionChangeStyle_triggered()
{
    changeData++;
    if(changeData==4)
    {
        ui->toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(40,150,200,160),stop: 0.6 rgb(40,150,200,220),stop:1 rgb(40,150,200,255));");
        ui->toolBar_2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(255,255,255,160),stop: 0.6 rgb(255,255,255,220),stop:1 rgb(255,255,255,255));");
        toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(40,150,200,160),stop: 0.6 rgb(40,150,200,220),stop:1 rgb(40,150,200,255));");
    }
    else if(changeData==3)
    {
        ui->toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(255,50,50,160),stop: 0.6 rgb(255,100,100,220),stop:1 rgb(255,50,50,100));");
        ui->toolBar_2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(255,50,50,160),stop: 0.6 rgb(255,100,100,220),stop:1 rgb(255,50,50,100));");
        toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(255,50,50,160),stop: 0.6 rgb(255,100,100,220),stop:1 rgb(255,50,50,100));");
    }
    else if(changeData==2)
    {
        ui->toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(100,255,150,160),stop: 0.6 rgb(100,255,100,220),stop:1 rgb(100,255,50,255));");
        ui->toolBar_2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(100,255,150,160),stop: 0.6 rgb(100,255,100,220),stop:1 rgb(100,255,50,255));");
        toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(100,255,150,160),stop: 0.6 rgb(100,255,100,220),stop:1 rgb(100,255,50,255));");
    }
    else if(changeData==1)
    {
        ui->toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(40,150,50,160),stop: 0.6 rgb(40,150,100,220),stop:1 rgb(40,150,150,255));");
        ui->toolBar_2->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(40,150,50,160),stop: 0.6 rgb(40,150,100,220),stop:1 rgb(40,150,150,255));");
        toolBar->setStyleSheet("background-color: qlineargradient(x1: 0, y1: 0, x2: 0.7, y2: 0.7,stop: 0.3 rgb(40,150,50,160),stop: 0.6 rgb(40,150,100,220),stop:1 rgb(40,150,150,255));");
    }
    if(changeData==4)
    {
        changeData=0;
    }

}


/**************************基本信息查询***********************/
void MainWindow::on_actionSelect_triggered()
{
    flage=2;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(ui->centralWidget);
}


/**************************基本信息录入***********************/
void MainWindow::on_actionInsert_triggered()
{
    flage=1;
    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(info);
}


/**************************政治面貌录入***********************/
void MainWindow::on_actionPoliticalInsert_triggered()
{
    flage=3;
    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(poliIsrt);
}


/**************************政治面貌查询***********************/
void MainWindow::on_actionPoliticalSelect_triggered()
{
    flage=4;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(poliSect);
}


/**************************旷课情况录入***********************/
void MainWindow::on_actionCutSchoolInsert_triggered()
{
    flage=5;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(cutIsrt);
}


/**************************旷课情况查询***********************/
void MainWindow::on_actionCutSchoolSelect_triggered()
{
    flage=6;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(cutSect);
}


/**************************挂科情况录入***********************/
void MainWindow::on_actionNotPassInsert_triggered()
{
    flage=7;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(notIsrt);
}


/**************************挂科情况查询***********************/
void MainWindow::on_actionNotPassSelect_triggered()
{
    flage=8;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(notSect);
}


/**************************获奖情况录入***********************/
void MainWindow::on_actionHornorInsert_triggered()
{
    flage=9;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(honorIsrt);
}


/**************************获奖情况查询***********************/
void MainWindow::on_actionHornorSelect_triggered()
{
    flage=10;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(honorSect);
}


/**************************日常情况录入***********************/
void MainWindow::on_actionDayInsert_triggered()
{
    flage=11;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(dailyIsrt);
}


/**************************日常情况查询***********************/
void MainWindow::on_actionDaySelect_triggered()
{
    flage=12;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(dailySect);
}


/**************************违规违纪录入***********************/
void MainWindow::on_actionOutLineInsert_triggered()
{
    flage=13;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(outLineIsrt);
}


/**************************违规违纪查询***********************/
void MainWindow::on_actionOutLineSelect_triggered()
{
    flage=14;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(outLineSect);
}


/**************************成绩排名录入***********************/
void MainWindow::on_actionGradeInsert_triggered()
{
    flage=15;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(orderCastIsrt);
}


/**************************成绩排名查询***********************/
void MainWindow::on_actionGradeSelect_triggered()
{
    flage=16;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(orderCastSect);
}


/**************************播放视频***********************/
void MainWindow::on_actionMovie_triggered()
{

    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(player);

}


/**************************截屏函数***********************/
void MainWindow::on_actionScreen_triggered()
{
    QTime time=QTime::currentTime();    //获取当前事件
    QDir *dir = new QDir;
    bool exist = dir->exists("Screen"); //判断是否存在Screen路径
    if(!exist)
    {
        dir->mkdir("Screen"); //如果不存在，则创建该路径
    }

    //进行截屏，截取当前窗口
    QPixmap pix=QPixmap::grabWindow(QApplication::desktop()->winId(),this->x(),this->y(),frameGeometry().width(),frameGeometry().height());
    QString str=time.toString("HH点mm分ss秒");        //当前时间
    bool pixOk =pix.save(tr("Screen/%1截屏.png").arg(str),"png"); //保存至Screen文件夹下

    //提示是否截屏成功
    if(pixOk)
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("恭喜你，截图成功！"),QPixmap(":/new/prefix1/image/icon-ok.png"),true);
        MessageDialog::getInstance()->exec();
    }
    else
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，截图失败！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();

    }

}


/**************************构造函数***********************/
winMainThread::winMainThread(MainWindow *windowThread,int flage)
{
    this->windowThread=windowThread;  //传递窗口对象
    this->flage=flage;                //窗口标志
}


/**************************线程函数***********************/
void winMainThread::run()
{
    if(flage==ONE)
    {
        this->windowThread->extendExcel();//放在线程中导入Excel
    }
    else if(flage==TWO)
    {
        this->windowThread->importExcel();//放在线程中导入Excel
    }
}


/**************************教务处网站***********************/
void MainWindow::on_actionJiaowu_triggered()
{
    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(web);
    web->showWeb("http://jwch.dlou.edu.cn/");
}


/**************************信息工程学院网站******************/
void MainWindow::on_actionXinXi_triggered()
{
    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(web);
    web->showWeb("http://xxgc.dlou.edu.cn/");
}


/**************************百度一下************************/
void MainWindow::on_actionBaiDu_triggered()
{
    toolBar->setEnabled(false);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(web);
    web->showWeb("www.baidu.com");
}

/**************************夜不归寝录入************************/
void MainWindow::on_actionNotBackIsrt_triggered()
{
    flage=17;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(notBackIsrt);
}

/**************************夜不归寝查询************************/
void MainWindow::on_actionNotBackSect_triggered()
{
    flage=18;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(notBackSect);
}

/**************************等级考试录入************************/
void MainWindow::on_actionGradeTestIsrt_triggered()
{
    flage=19;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(gradeTestIsrt);
}

/**************************等级考试查询************************/
void MainWindow::on_actionGradeTestSect_triggered()
{
    flage=20;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(gradeTestSect);
}

/**************************学籍异变录入************************/
void MainWindow::on_actionSchoolRoolIsrt_triggered()
{
    flage=21;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(schoolRoolIsrt);
}


/**************************学籍异变查询************************/
void MainWindow::on_actionSchoolRoolSect_triggered()
{
    flage=22;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(schoolRoolSect);
}


/**************************转学录入************************/
void MainWindow::on_actionTransferIsrt_triggered()
{
    flage=23;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(transferIsrt);
}


/**************************转学查询************************/
void MainWindow::on_actionTransferSect_triggered()
{
    flage=24;
    toolBar->setEnabled(true);
    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(transferSect);
}

void MainWindow::on_actionWeather_triggered()
{

    if(this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);
    }
    this->setCentralWidget(weatherData);
    weatherData->getWeather("101070201");
}
