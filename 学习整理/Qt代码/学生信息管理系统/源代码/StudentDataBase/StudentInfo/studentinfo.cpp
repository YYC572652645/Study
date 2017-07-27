#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);


    data=new StudentDataBase();
    this->setMinimumSize(700,500);


    /*************************姓名信息***********************/
    lineEditName=new QLineEdit();
    lineEditName->setMinimumHeight(25);
    widgetName=new QWidget;
    hboxLayoutName=new QHBoxLayout();
    hboxLayoutName->addWidget(lineEditName);
    hboxLayoutName->setAlignment(widgetName,Qt::AlignCenter);
    widgetName->setLayout(hboxLayoutName);


    /*************************性别信息***********************/
    widgetSex=new QWidget;
    hboxLayoutSex=new QHBoxLayout;
    radioBoy=new QRadioButton();
    radioGirl=new QRadioButton();
    radioBoy->setText(tr("男"));
    radioGirl->setText(tr("女"));
    radioBoy->setChecked(true);
    hboxLayoutSex->addWidget(radioBoy);
    hboxLayoutSex->addWidget(radioGirl);
    hboxLayoutSex->setAlignment(widgetSex,Qt::AlignCenter);
    widgetSex->setLayout(hboxLayoutSex);


    /*************************学号信息***********************/
    lineEditNumber=new QLineEdit();
    lineEditNumber->setMinimumHeight(25);
    widgetNumber=new QWidget;
    hboxLayoutNumber=new QHBoxLayout();
    hboxLayoutNumber->addWidget(lineEditNumber);
    hboxLayoutNumber->setAlignment(widgetNumber,Qt::AlignCenter);
    widgetNumber->setLayout(hboxLayoutNumber);


    /*************************民族信息***********************/
    comboBoxNation=new QComboBox();
    comboBoxNation->setMinimumHeight(25);
    widgetNation=new QWidget;
    hboxLayoutNation=new QHBoxLayout();
    hboxLayoutNation->addWidget(comboBoxNation);
    hboxLayoutNation->setAlignment(widgetNation,Qt::AlignCenter);
    widgetNation->setLayout(hboxLayoutNation);

    comboBoxNation->addItem(tr("汉族"));
    comboBoxNation->addItem(tr("回族"));
    comboBoxNation->addItem(tr("蒙古族"));
    comboBoxNation->addItem(tr("藏族"));
    comboBoxNation->addItem(tr("维吾尔族"));
    comboBoxNation->addItem(tr("苗族"));
    comboBoxNation->addItem(tr("彝族"));
    comboBoxNation->addItem(tr("壮族"));
    comboBoxNation->addItem(tr("布依族"));
    comboBoxNation->addItem(tr("朝鲜族"));
    comboBoxNation->addItem(tr("满族"));
    comboBoxNation->addItem(tr("侗族"));
    comboBoxNation->addItem(tr("瑶族"));
    comboBoxNation->addItem(tr("白族"));
    comboBoxNation->addItem(tr("土家族"));
    comboBoxNation->addItem(tr("哈尼族"));
    comboBoxNation->addItem(tr("哈萨克族"));
    comboBoxNation->addItem(tr("傣族"));
    comboBoxNation->addItem(tr("黎族"));
    comboBoxNation->addItem(tr("僳僳族"));
    comboBoxNation->addItem(tr("佤族"));
    comboBoxNation->addItem(tr("畲族"));
    comboBoxNation->addItem(tr("高山族"));
    comboBoxNation->addItem(tr("拉祜族"));
    comboBoxNation->addItem(tr("水族"));
    comboBoxNation->addItem(tr("东乡族"));
    comboBoxNation->addItem(tr("纳西族"));


    comboBoxNation->addItem(tr("景颇族"));
    comboBoxNation->addItem(tr("柯尔克孜族"));

    comboBoxNation->addItem(tr("土族"));
    comboBoxNation->addItem(tr("达斡尔族"));
    comboBoxNation->addItem(tr("仫佬族"));
    comboBoxNation->addItem(tr("羌族"));
    comboBoxNation->addItem(tr("布朗族"));
    comboBoxNation->addItem(tr("撒拉族"));
    comboBoxNation->addItem(tr("毛南族"));
    comboBoxNation->addItem(tr("仡佬族"));
    comboBoxNation->addItem(tr("锡伯族"));
    comboBoxNation->addItem(tr("阿昌族"));
    comboBoxNation->addItem(tr("普米族"));
    comboBoxNation->addItem(tr("塔吉克族"));
    comboBoxNation->addItem(tr("怒族"));
    comboBoxNation->addItem(tr("乌孜别克族"));
    comboBoxNation->addItem(tr("俄罗斯族"));
    comboBoxNation->addItem(tr("鄂温克族"));
    comboBoxNation->addItem(tr("德昂族"));
    comboBoxNation->addItem(tr("保安族"));
    comboBoxNation->addItem(tr("裕固族"));
    comboBoxNation->addItem(tr("京族"));
    comboBoxNation->addItem(tr("塔塔尔族"));
    comboBoxNation->addItem(tr("独龙族"));
    comboBoxNation->addItem(tr("鄂伦春族"));
    comboBoxNation->addItem(tr("赫哲族"));
    comboBoxNation->addItem(tr("门巴族"));
    comboBoxNation->addItem(tr("珞巴族"));
    comboBoxNation->addItem(tr("基诺族"));



    /*************************出生日期信息***********************/
    dateEditBornDate=new QDateEdit();
    dateEditBornDate->setMinimumHeight(25);
    widgetBornDate=new QWidget;
    hboxLayoutBornDate=new QHBoxLayout();
    hboxLayoutBornDate->addWidget(dateEditBornDate);
    hboxLayoutBornDate->setAlignment(widgetBornDate,Qt::AlignCenter);
    widgetBornDate->setLayout(hboxLayoutBornDate);



    /*************************政治面貌信息***********************/
    comboBoxPolitical=new QComboBox();
    comboBoxPolitical->setMinimumHeight(25);
    widgetPolitical=new QWidget;
    hboxLayoutPolitical=new QHBoxLayout();
    hboxLayoutPolitical->addWidget(comboBoxPolitical);
    hboxLayoutPolitical->setAlignment(widgetPolitical,Qt::AlignCenter);
    widgetPolitical->setLayout(hboxLayoutPolitical);
    comboBoxPolitical->addItem(tr("共青团员"));
    comboBoxPolitical->addItem(tr("积极分子"));
    comboBoxPolitical->addItem(tr("预备党员"));
    comboBoxPolitical->addItem(tr("党员"));
    comboBoxPolitical->addItem(tr("无"));



    /*************************学院信息***********************/
    comboBoxCollege=new QComboBox();
    comboBoxCollege->setMinimumHeight(25);
    widgetCollege=new QWidget;
    hboxLayoutCollege=new QHBoxLayout();
    hboxLayoutCollege->addWidget(comboBoxCollege);
    hboxLayoutCollege->setAlignment(widgetCollege,Qt::AlignCenter);
    widgetCollege->setLayout(hboxLayoutCollege);
    comboBoxCollege->addItem(tr("信息工程学院"));





    /*************************专业班级***********************/
    widgetProfess=new QGroupBox(tr(""));
    hboxLayoutProfess=new QHBoxLayout;
    comboBoxProfess=new QComboBox();
    lineEditProfessYear=new QLineEdit();
    comboBoxProfess->setMinimumHeight(25);
    lineEditProfessYear->setMinimumHeight(25);
    lineEditProfessYear->setMinimumWidth(35);
    hboxLayoutProfess->addWidget(comboBoxProfess);
    hboxLayoutProfess->addWidget(lineEditProfessYear);
    hboxLayoutProfess->setAlignment(widgetCollege,Qt::AlignCenter);
    widgetProfess->setLayout(hboxLayoutProfess);
    widgetProfess->setStyleSheet("QGroupBox{border-width:0;border-style:outset}");
    comboBoxProfess->addItem(tr("计算机"));
    comboBoxProfess->addItem(tr("自动化"));
    comboBoxProfess->addItem(tr("电信类"));
    comboBoxProfess->addItem(tr("电子"));
    comboBoxProfess->addItem(tr("通信"));


    /*************************当前所在班***********************/
    widgetNowClass=new QGroupBox(tr(""));
    hboxLayoutNowClass=new QHBoxLayout;
    comboBoxNowClass=new QComboBox();
    lineEditNowClassYear=new QLineEdit();
    comboBoxNowClass->setMinimumHeight(25);
    lineEditNowClassYear->setMinimumHeight(25);
    lineEditNowClassYear->setMinimumWidth(35);
    hboxLayoutNowClass->addWidget(comboBoxNowClass);
    hboxLayoutNowClass->addWidget(lineEditNowClassYear);
    hboxLayoutNowClass->setAlignment(widgetCollege,Qt::AlignCenter);
    widgetNowClass->setLayout(hboxLayoutNowClass);
    widgetNowClass->setStyleSheet("QGroupBox{border-width:0;border-style:outset}");
    comboBoxNowClass->addItem(tr("计算机"));
    comboBoxNowClass->addItem(tr("自动化"));
    comboBoxNowClass->addItem(tr("电信类"));
    comboBoxNowClass->addItem(tr("电子"));
    comboBoxNowClass->addItem(tr("通信"));




    /*************************宿舍号***********************/
    widgetDorm=new QGroupBox(tr(""));
    hboxLayoutDorm=new QHBoxLayout;
    comboBoxDorm=new QComboBox();
    lineEditDormNumber=new QLineEdit();
    comboBoxDorm->setMinimumHeight(25);
    lineEditDormNumber->setMinimumHeight(25);
    lineEditDormNumber->setMinimumWidth(35);
    hboxLayoutDorm->addWidget(comboBoxDorm);
    hboxLayoutDorm->addWidget(lineEditDormNumber);
    widgetDorm->setLayout(hboxLayoutDorm);
    widgetDorm->setStyleSheet("QGroupBox{border-width:0;border-style:outset}");
    comboBoxDorm->addItem("黄海校内4舍");
    comboBoxDorm->addItem("渤海校内1舍");
    comboBoxDorm->addItem("渤海校内2舍");
    comboBoxDorm->addItem("渤海校内3舍");
    comboBoxDorm->addItem("渤海校内4舍");
    comboBoxDorm->addItem("渤海校内5舍");
    comboBoxDorm->addItem("渤海校内6舍");
    comboBoxDorm->addItem("渤海校内7舍");
    comboBoxDorm->addItem("黄海校内1舍");
    comboBoxDorm->addItem("黄海校内2舍");
    comboBoxDorm->addItem("黄海校内3舍");
    comboBoxDorm->addItem("黄海校内7舍");
    comboBoxDorm->addItem("黄海校内8舍");
    comboBoxDorm->addItem("黄海公寓1号");
    comboBoxDorm->addItem("黄海公寓2号");
    comboBoxDorm->addItem("黄海公寓2副");
    comboBoxDorm->addItem("黄海校内3号");
    comboBoxDorm->addItem("黄海校内4号");


    /*************************床号信息***********************/
    lineEditBedNumber=new QLineEdit();
    lineEditBedNumber->setMinimumHeight(25);
    widgetBedNumber=new QWidget;
    hboxLayoutBedNumber=new QHBoxLayout();
    hboxLayoutBedNumber->addWidget(lineEditBedNumber);
    hboxLayoutBedNumber->setAlignment(widgetBedNumber,Qt::AlignCenter);
    widgetBedNumber->setLayout(hboxLayoutBedNumber);



    /*************************身份证号信息***********************/
    lineEditCardNumber=new QLineEdit();
    lineEditCardNumber->setMinimumHeight(25);
    widgetCardNumber=new QWidget;
    hboxLayoutCardNumber=new QHBoxLayout();
    hboxLayoutCardNumber->addWidget(lineEditCardNumber);
    hboxLayoutCardNumber->setAlignment(widgetCardNumber,Qt::AlignCenter);
    widgetCardNumber->setLayout(hboxLayoutCardNumber);


    /*************************银行卡号信息***********************/
    lineEditBankNumber=new QLineEdit();
    lineEditBankNumber->setMinimumHeight(25);
    widgetBankNumber=new QWidget;
    hboxLayoutBankNumber=new QHBoxLayout();
    hboxLayoutBankNumber->addWidget(lineEditBankNumber);
    hboxLayoutBankNumber->setAlignment(widgetBankNumber,Qt::AlignCenter);
    widgetBankNumber->setLayout(hboxLayoutBankNumber);





    /*************************邮编信息***********************/
    lineEditCodeNumber=new QLineEdit();
    lineEditCodeNumber->setMinimumHeight(25);
    widgetCodeNumber=new QWidget;
    hboxLayoutCodeNumber=new QHBoxLayout();
    hboxLayoutCodeNumber->addWidget(lineEditCodeNumber);
    hboxLayoutCodeNumber->setAlignment(widgetCodeNumber,Qt::AlignCenter);
    widgetCodeNumber->setLayout(hboxLayoutCodeNumber);


    /*************************QQ信息***********************/
    lineEditQQNumber=new QLineEdit();
    lineEditQQNumber->setMinimumHeight(25);
    widgetQQNumber=new QWidget;
    hboxLayoutQQNumber=new QHBoxLayout();
    hboxLayoutQQNumber->addWidget(lineEditQQNumber);
    hboxLayoutQQNumber->setAlignment(widgetQQNumber,Qt::AlignCenter);
    widgetQQNumber->setLayout(hboxLayoutQQNumber);



    /*************************户口类型信息***********************/
    comboBoxHouseType=new QComboBox();
    comboBoxHouseType->setMinimumHeight(25);
    widgetHouseType=new QWidget;
    hboxLayoutHouseType=new QHBoxLayout();
    hboxLayoutHouseType->addWidget(comboBoxHouseType);
    hboxLayoutHouseType->setAlignment(widgetHouseType,Qt::AlignCenter);
    widgetHouseType->setLayout(hboxLayoutHouseType);
    comboBoxHouseType->addItem(tr("城市"));
    comboBoxHouseType->addItem(tr("农村"));


    /*************************家庭住址信息***********************/
    lineEditAddress=new QLineEdit();
    lineEditAddress->setMinimumHeight(25);
    widgetAddress=new QWidget;
    hboxLayoutAddress=new QHBoxLayout();
    hboxLayoutAddress->addWidget(lineEditAddress);
    hboxLayoutAddress->setAlignment(widgetAddress,Qt::AlignCenter);
    widgetAddress->setLayout(hboxLayoutAddress);


    /*************************生源地信息***********************/
    lineEditOrigin=new QLineEdit();
    lineEditOrigin->setMinimumHeight(25);
    widgetOrigin=new QWidget;
    hboxLayoutOrigin=new QHBoxLayout();
    hboxLayoutOrigin->addWidget(lineEditOrigin);
    hboxLayoutOrigin->setAlignment(widgetOrigin,Qt::AlignCenter);
    widgetOrigin->setLayout(hboxLayoutOrigin);


    /*************************是否单亲信息***********************/
    comboBoxSingle=new QComboBox();
    comboBoxSingle->setMinimumHeight(25);
    widgetSingle=new QWidget;
    hboxLayoutSingle=new QHBoxLayout();
    hboxLayoutSingle->addWidget(comboBoxSingle);
    hboxLayoutSingle->setAlignment(widgetSingle,Qt::AlignCenter);
    widgetSingle->setLayout(hboxLayoutSingle);
    comboBoxSingle->addItem(tr("是"));
    comboBoxSingle->addItem(tr("否"));


    /************************是否贫困信息***********************/
    comboBoxPoverty=new QComboBox();
    comboBoxPoverty->setMinimumHeight(25);
    widgetPoverty=new QWidget;
    hboxLayoutPoverty=new QHBoxLayout();
    hboxLayoutPoverty->addWidget(comboBoxPoverty);
    hboxLayoutPoverty->setAlignment(widgetPoverty,Qt::AlignCenter);
    widgetPoverty->setLayout(hboxLayoutPoverty);
    comboBoxPoverty->addItem(tr("是"));
    comboBoxPoverty->addItem(tr("否"));



    /*************************是否服兵役信息***********************/
    comboBoxArmy=new QComboBox();
    comboBoxArmy->setMinimumHeight(25);
    widgetArmy=new QWidget;
    hboxLayoutArmy=new QHBoxLayout();
    hboxLayoutArmy->addWidget(comboBoxArmy);
    hboxLayoutArmy->setAlignment(widgetArmy,Qt::AlignCenter);
    widgetArmy->setLayout(hboxLayoutArmy);
    comboBoxArmy->addItem(tr("是"));
    comboBoxArmy->addItem(tr("否"));


    /*************************是否留学信息***********************/
    comboBoxAbord=new QComboBox();
    comboBoxAbord->setMinimumHeight(25);
    widgetAbord=new QWidget;
    hboxLayoutAbord=new QHBoxLayout();
    hboxLayoutAbord->addWidget(comboBoxAbord);
    hboxLayoutAbord->setAlignment(widgetAbord,Qt::AlignCenter);
    widgetAbord->setLayout(hboxLayoutAbord);
    comboBoxAbord->addItem(tr("是"));
    comboBoxAbord->addItem(tr("否"));



    /*************************周末是否回家信息***********************/
    comboBoxGoHome=new QComboBox();
    comboBoxGoHome->setMinimumHeight(25);
    widgetGoHome=new QWidget;
    hboxLayoutGoHome=new QHBoxLayout();
    hboxLayoutGoHome->addWidget(comboBoxGoHome);
    hboxLayoutGoHome->setAlignment(widgetGoHome,Qt::AlignCenter);
    widgetGoHome->setLayout(hboxLayoutGoHome);
    comboBoxGoHome->addItem(tr("是"));
    comboBoxGoHome->addItem(tr("否"));


    /*************************是否走读信息***********************/
    comboBoxGoRead=new QComboBox();
    comboBoxGoRead->setMinimumHeight(25);
    widgetGoRead=new QWidget;
    hboxLayoutGoRead=new QHBoxLayout();
    hboxLayoutGoRead->addWidget(comboBoxGoRead);
    hboxLayoutGoRead->setAlignment(widgetGoRead,Qt::AlignCenter);
    widgetGoRead->setLayout(hboxLayoutGoRead);
    comboBoxGoRead->addItem(tr("是"));
    comboBoxGoRead->addItem(tr("否"));


    /*************************父亲姓名信息***********************/
    lineEditFatherName=new QLineEdit();
    lineEditFatherName->setMinimumHeight(25);
    widgetFatherName=new QWidget;
    hboxLayoutFatherName=new QHBoxLayout();
    hboxLayoutFatherName->addWidget(lineEditFatherName);
    hboxLayoutFatherName->setAlignment(widgetFatherName,Qt::AlignCenter);
    widgetFatherName->setLayout(hboxLayoutFatherName);


    /*************************父亲电话信息***********************/
    lineEditFatherNumber=new QLineEdit();
    lineEditFatherNumber->setMinimumHeight(25);
    widgetFatherNumber=new QWidget;
    hboxLayoutFatherNumber=new QHBoxLayout();
    hboxLayoutFatherNumber->addWidget(lineEditFatherNumber);
    hboxLayoutFatherNumber->setAlignment(widgetFatherNumber,Qt::AlignCenter);
    widgetFatherNumber->setLayout(hboxLayoutFatherNumber);


    /*************************父亲工作单位信息***********************/
    lineEditFatherWork=new QLineEdit();
    lineEditFatherWork->setMinimumHeight(25);
    widgetFatherWork=new QWidget;
    hboxLayoutFatherWork=new QHBoxLayout();
    hboxLayoutFatherWork->addWidget(lineEditFatherWork);
    hboxLayoutFatherWork->setAlignment(widgetFatherWork,Qt::AlignCenter);
    widgetFatherWork->setLayout(hboxLayoutFatherWork);




    /*************************母亲姓名信息***********************/
    lineEditMotherName=new QLineEdit();
    lineEditMotherName->setMinimumHeight(25);
    widgetMotherName=new QWidget;
    hboxLayoutMotherName=new QHBoxLayout();
    hboxLayoutMotherName->addWidget(lineEditMotherName);
    hboxLayoutMotherName->setAlignment(widgetMotherName,Qt::AlignCenter);
    widgetMotherName->setLayout(hboxLayoutMotherName);



    /*************************母亲电话信息***********************/
    lineEditMotherNumber=new QLineEdit();
    lineEditMotherNumber->setMinimumHeight(25);
    widgetMotherNumber=new QWidget;
    hboxLayoutMotherNumber=new QHBoxLayout();
    hboxLayoutMotherNumber->addWidget(lineEditMotherNumber);
    hboxLayoutMotherNumber->setAlignment(widgetMotherNumber,Qt::AlignCenter);
    widgetMotherNumber->setLayout(hboxLayoutMotherNumber);



    /*************************母亲工作单位信息***********************/
    lineEditMotherWork=new QLineEdit();
    lineEditMotherWork->setMinimumHeight(25);
    widgetMotherWork=new QWidget;
    hboxLayoutMotherWork=new QHBoxLayout();
    hboxLayoutMotherWork->addWidget(lineEditMotherWork);
    hboxLayoutMotherWork->setAlignment(widgetMotherWork,Qt::AlignCenter);
    widgetMotherWork->setLayout(hboxLayoutMotherWork);



    /*************************个人电话信息***********************/
    lineEditPhoneNumber=new QLineEdit();
    lineEditPhoneNumber->setMinimumHeight(25);
    widgetPhoneNumber=new QWidget;
    hboxLayoutPhoneNumber=new QHBoxLayout();
    hboxLayoutPhoneNumber->addWidget(lineEditPhoneNumber);
    hboxLayoutPhoneNumber->setAlignment(widgetPhoneNumber,Qt::AlignCenter);
    widgetPhoneNumber->setLayout(hboxLayoutPhoneNumber);


    /*************************录入数据信息***********************/
    insertButton=new QPushButton();
    insertButton->setText("信息录入");



    /*************************添加控件***********************/
    ui->tableWidget->setCellWidget(0,1,widgetName);
    ui->tableWidget->setCellWidget(0,3,widgetSex);
    ui->tableWidget->setCellWidget(0,5,widgetNumber);
    ui->tableWidget->setCellWidget(1,1,widgetNation);
    ui->tableWidget->setCellWidget(1,3,widgetBornDate);
    ui->tableWidget->setCellWidget(1,5,widgetPolitical);
    ui->tableWidget->setCellWidget(2,1,widgetCollege);
    ui->tableWidget->setCellWidget(2,3,widgetProfess);
    ui->tableWidget->setCellWidget(2,5,widgetNowClass);
    ui->tableWidget->setCellWidget(3,1,widgetDorm);
    ui->tableWidget->setCellWidget(3,3,widgetBedNumber);
    ui->tableWidget->setCellWidget(3,5,widgetCardNumber);
    ui->tableWidget->setCellWidget(4,1,widgetBankNumber);
    ui->tableWidget->setCellWidget(4,3,widgetCodeNumber);
    ui->tableWidget->setCellWidget(4,5,widgetQQNumber);
    ui->tableWidget->setCellWidget(5,1,widgetHouseType);
    ui->tableWidget->setCellWidget(5,3,widgetAddress);
    ui->tableWidget->setCellWidget(5,5,widgetOrigin);
    ui->tableWidget->setCellWidget(6,1,widgetSingle);
    ui->tableWidget->setCellWidget(6,3,widgetPoverty);
    ui->tableWidget->setCellWidget(6,5,widgetArmy);
    ui->tableWidget->setCellWidget(7,1,widgetAbord);
    ui->tableWidget->setCellWidget(7,3,widgetGoHome);
    ui->tableWidget->setCellWidget(7,5,widgetGoRead);
    ui->tableWidget->setCellWidget(8,1,widgetFatherName);
    ui->tableWidget->setCellWidget(8,3,widgetFatherNumber);
    ui->tableWidget->setCellWidget(8,5,widgetFatherWork);
    ui->tableWidget->setCellWidget(9,1,widgetMotherName);
    ui->tableWidget->setCellWidget(9,3,widgetMotherNumber);
    ui->tableWidget->setCellWidget(9,5,widgetMotherWork);
    ui->tableWidget->setCellWidget(10,1,widgetPhoneNumber);
    ui->tableWidget->setCellWidget(10,5,insertButton);



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

    QFont f("宋体",14,QFont::Bold,true);
    insertButton->setFont(f);         //信息录入
    insertButton->setIcon(QIcon(":/new/prefix1/image/indexedDB.png"));
    insertButton->setIconSize(QSize(30,30));


    QTableWidgetItem *name=new QTableWidgetItem("姓名:");
    name->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,0,name);

    QTableWidgetItem *sex=new QTableWidgetItem("性别:");
    sex->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,2,sex);


    QTableWidgetItem *number=new QTableWidgetItem("学号:");
    number->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0,4,number);


    QTableWidgetItem *nation=new QTableWidgetItem("民族:");
    nation->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,0,nation);


    QTableWidgetItem *bornDate=new QTableWidgetItem("出生日期:");
    bornDate->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,2,bornDate);


    QTableWidgetItem *political=new QTableWidgetItem("政治面貌:");
    political->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1,4,political);



    QTableWidgetItem *college=new QTableWidgetItem("学院:");
    college->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,0,college);



    QTableWidgetItem *profess=new QTableWidgetItem("专业班级:");
    profess->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,2,profess);



    QTableWidgetItem *nowClass=new QTableWidgetItem("当前所在班:");
    nowClass->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2,4,nowClass);


    QTableWidgetItem *dorm=new QTableWidgetItem("宿舍号:");
    dorm->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,0,dorm);



    QTableWidgetItem *bedNumber=new QTableWidgetItem("床号:");
    bedNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,2,bedNumber);


    QTableWidgetItem *cardNumber=new QTableWidgetItem("身份证号:");
    cardNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3,4,cardNumber);


    QTableWidgetItem *bankNumber=new QTableWidgetItem("银行卡号:");
    bankNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,0,bankNumber);

    QTableWidgetItem *code=new QTableWidgetItem("邮编:");
    code->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,2,code);


    QTableWidgetItem *QQ=new QTableWidgetItem("QQ:");
    QQ->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4,4,QQ);


    QTableWidgetItem *houseType=new QTableWidgetItem("户口类型:");
    houseType->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5,0,houseType);


    QTableWidgetItem *address=new QTableWidgetItem("家庭住址:");
    address->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5,2,address);


    QTableWidgetItem *origin=new QTableWidgetItem("生源地:");
    origin->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5,4,origin);


    QTableWidgetItem *single=new QTableWidgetItem("是否单亲:");
    single->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(6,0,single);



    QTableWidgetItem *poverty=new QTableWidgetItem("是否贫困:");
    poverty->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(6,2,poverty);




    QTableWidgetItem *army=new QTableWidgetItem("是否服兵役:");
    army->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(6,4,army);




    QTableWidgetItem *abord=new QTableWidgetItem("是否留学:");
    abord->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(7,0,abord);



    QTableWidgetItem *goHome=new QTableWidgetItem("周末是否回家:");
    goHome->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(7,2,goHome);



    QTableWidgetItem *goRead=new QTableWidgetItem("是否走读:");
    goRead->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(7,4,goRead);



    QTableWidgetItem *fatherName=new QTableWidgetItem("父亲姓名:");
    fatherName->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(8,0,fatherName);


    QTableWidgetItem *fatherNumber=new QTableWidgetItem("父亲电话:");
    fatherNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(8,2,fatherNumber);


    QTableWidgetItem *fatherWork=new QTableWidgetItem("父亲工作单位:");
    fatherWork->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(8,4,fatherWork);


    QTableWidgetItem *motherName=new QTableWidgetItem("母亲姓名:");
    motherName->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(9,0,motherName);


    QTableWidgetItem *motherNumber=new QTableWidgetItem("母亲电话:");
    motherNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(9,2,motherNumber);


    QTableWidgetItem *motherWork=new QTableWidgetItem("母亲工作单位:");
    motherWork->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(9,4,motherWork);

    QTableWidgetItem *phoneNumber=new QTableWidgetItem("个人电话:");
    phoneNumber->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(10,0,phoneNumber);

    connect(insertButton,SIGNAL(clicked(bool)),this,SLOT(insertData()));
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::insertData()
{
    QRegExp rx;                              //正则表达式
    rx.setPatternSyntax(QRegExp::RegExp);    //将元字符设置为统配模式下
    rx.setCaseSensitivity(Qt::CaseSensitive);//大小写敏感


    if(lineEditName->text().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，姓名为空,请填写姓名！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->name=lineEditName->text();
    }


    if(radioBoy->isChecked())
    {
        data->sex=tr("男");
    }
    if(radioGirl->isChecked())
    {
        data->sex=tr("女");
    }


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


    if(comboBoxNation->currentText().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，民族为空,请填写民族！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->nation=comboBoxNation->currentText();
    }


    if(dateEditBornDate->text().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，出生日期为空,请填写出生日期！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->bornDate=dateEditBornDate->text();
    }


    if(comboBoxPolitical->currentText().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，政治面貌为空,请填写政治面貌！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->political=comboBoxPolitical->currentText();
    }

    if(comboBoxCollege->currentText().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，学院为空,请填写学院！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->college=comboBoxCollege->currentText();
    }

    if(lineEditProfessYear->text().isEmpty())
    {
        MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，专业班级为空,请填写专业班级！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
        MessageDialog::getInstance()->exec();
        return;
    }
    else
    {
        data->profess=comboBoxProfess->currentText()+lineEditProfessYear->text();
    }


    data->nowClass=comboBoxNowClass->currentText()+lineEditNowClassYear->text();
    data->dormNumber=comboBoxDorm->currentText()+lineEditDormNumber->text();
    data->bedNumber=lineEditBedNumber->text();


    if(!lineEditCardNumber->text().isEmpty())
    {
        rx.setPattern(QString("[0-9]{15,18}"));    //匹配身份证号15位或18位
        if(rx.exactMatch(lineEditCardNumber->text()))
        {
            data->cardNumber=lineEditCardNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，身份证号错误,请检查身份证号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }
    else
    {
        data->cardNumber=lineEditCardNumber->text();
    }


    if(!lineEditBankNumber->text().isEmpty())
    {
        rx.setPattern(QString("[0-9]{16,19}"));    //匹配银行卡号16位或19位
        if(rx.exactMatch(lineEditBankNumber->text()))
        {
            data->bankNumber=lineEditBankNumber->text();
        }
        else
        {
            MessageDialog::getInstance()->setInfo(tr("系统提示"),tr("对不起，银行卡号错误,请检查银行卡号！"),QPixmap(":/new/prefix1/image/icon-fail.png"),true);
            MessageDialog::getInstance()->exec();
            return;
        }
    }
    else
    {
        data->bankNumber=lineEditBankNumber->text();
    }

    data->codeNumber=lineEditCodeNumber->text();
    data->QQNumber=lineEditQQNumber->text();
    data->houseType=comboBoxHouseType->currentText();
    data->address=lineEditAddress->text();
    data->origin=lineEditOrigin->text();
    data->single=comboBoxSingle->currentText();
    data->poverty=comboBoxPoverty->currentText();
    data->army=comboBoxArmy->currentText();
    data->abord=comboBoxAbord->currentText();
    data->goHome=comboBoxGoHome->currentText();
    data->goRead=comboBoxGoRead->currentText();
    data->fatherName=lineEditFatherName->text();
    data->fatherNumber=lineEditFatherNumber->text();
    data->fatherWork=lineEditFatherWork->text();
    data->motherName=lineEditMotherName->text();
    data->motherNumber=lineEditMotherNumber->text();
    data->motherWork=lineEditMotherWork->text();
    data->phoneNumber=lineEditPhoneNumber->text();

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
