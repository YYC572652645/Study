#include "logindialog.h"
#include "ui_logindialog.h"



/**************鼠标作用域********************/
using namespace std;
const static int posMinX=0;
const static int posMaxX=20000;

const static int posMinY=0;
const static int posMaxY=40;


/**************构造函数***********************/
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);

    if(readXml())  //读取xml
    {
        for(int i=0;i<listStringUsnm.count();i++)
        {
            //将comboBoxUserName存储的信息读取出来，进行实时改变lineEdit的密码
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&listStringRemember[i]=="1")
            {

                ui->lineEditPassWord->setText(listStringPsd[i]);//填写密码
                ui->checkBoxRemeber->setChecked(true);          //如过是记住密码,则将复选按钮选中
                if(listStringAuto[i]=="1")                      //如果是自动登录,则将复选按钮选中
                {
                    ui->checkBoxAuto->setChecked(true);
                }
            }

        }
    }

    minButton=new QToolButton(this);   //最小化按钮
    closeButton=new QToolButton(this); //关闭按钮
    int width=this->width();           //获取软件占得像素大小
    isMousePressed=false;


    this->setWindowFlags(Qt::FramelessWindowHint);  //去掉标题栏
    QDesktopWidget *desktop=QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2);  //程序显示在屏幕中间


    /*************************************加载图标********************************/
    QPixmap closePix=style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton->setIcon(closePix);


    QPixmap minPix =style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    minButton->setIcon(minPix);



    /*************************************加载位置********************************/
    minButton->setGeometry(width-60,0,30,30);
    closeButton->setGeometry(width-30,0,30,30);



    setPalette(QPalette(Qt::darkCyan));                      //设置背景色
    setAutoFillBackground(true);
    ui->lineEditPassWord->setEchoMode(QLineEdit::Password);  //设置为加密形式
    login=new LoginData();



    /*************************************信号与槽连接******************************/
    connect(minButton,SIGNAL(clicked(bool)),SLOT(actionMin()));          //最小化按钮
    connect(closeButton,SIGNAL(clicked(bool)),SLOT(actionClose()));      //关闭按钮



    /*************************************背景色与父对话框一样************************/
    minButton->setStyleSheet("background-color:transparent");
    closeButton->setStyleSheet("background-color:transparent");


    /*************************************设置按钮颜色*******************************/
    ui->pushButtonInsertData->setStyleSheet("QPushButton{background-color:transparent;color: rgb(85, 170, 255);}QPushButton:hover{color:rgb(85, 150, 235);}QPushButton:pressed{color:rgb(85, 190, 255);}");
    ui->pushButtonBackData->setStyleSheet("QPushButton{background-color:transparent;color: rgb(85, 170, 255);}QPushButton:hover{color:rgb(85, 150, 235);}QPushButton:pressed{color:rgb(85, 190, 255);}");

}


/**************析构函数***********************/
LoginDialog::~LoginDialog()
{
    delete ui;
}


/***************登录按钮**********************/
void LoginDialog::on_pushButtonLogin_clicked()
{
    int Count=0;
    QString tempRem,tempAuto;
    if(ui->comboBoxUserName->currentText()==tr(""))
    {
        QMessageBox::information(this,tr("系统提示"),tr("请输入用户名"));
        return;
    }
    else if(ui->lineEditPassWord->text()=="")
    {
         QMessageBox::information(this,tr("系统提示"),tr("请输入密码"));
         return;
    }

    if(login->dataSelect(ui->comboBoxUserName->currentText(),ui->lineEditPassWord->text()))
    {
        //判断出输入的用户名是否存在，如果存在则不写入xml中，如果不存在则写入xml中
        for(int i=0;i<listStringUsnm.count();i++)
        {
            if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&ui->lineEditPassWord->text()==listStringPsd[i])
            {
                Count++;

                if(ui->checkBoxRemeber->isChecked())
                {
                    tempRem="1";//如果选中，致为1
                }
                else
                {
                    tempRem="0";//如果未选中，致为0
                }
                if(ui->checkBoxAuto->isChecked())
                {
                    tempAuto="1";//如果选中，致为1
                }
                else
                {
                    tempAuto="0";//如果选中，致为0
                }

                updateXml(listStringID[i],tempRem,tempAuto);               //更新xml文件
            }

        }
        if(Count==0)
        {
            writeXml();
        }

        //只要登录帐号多余8个人的帐号，将登录时间最早的节点删除，最多保留8位用户数据
        if(listStringUsnm.count()>8)
        {
            deletetXml();
        }

        accept();  //判断登录成功后accept,在main.cpp中进入主窗口

    }
    else
    {

        QMessageBox::information(this,tr("系统提示"),tr("登录失败"));//登录失败
    }

}


/***************最小化************************/
void LoginDialog::actionMin()
{
    showMinimized();
}


/***************关闭**************************/
void LoginDialog::actionClose()
{
    close();    //关闭

}


/***************鼠标移动**********************/
void LoginDialog::mouseMoveEvent(QMouseEvent *event)
{
    if(isMousePressed==true)
    {
        QPoint movePot=event->globalPos()-mousePosition;
        move(movePot);
    }

}


/***************鼠标点击**********************/
void LoginDialog::mousePressEvent(QMouseEvent *event)
{
    mousePosition=event->pos();  //当鼠标单击窗体准备拖动时，初始化鼠标在窗体中的相对位置
    //只对标题栏范围内的鼠标事件进行处理
    if(mousePosition.x()<=posMinX||mousePosition.x()>=posMaxX)
    {
        return;
    }

    if(mousePosition.y()<=posMinY||mousePosition.y()>=posMaxY)
    {
        return;
    }

    isMousePressed=true;
}


/***************鼠标释放**********************/
void LoginDialog::mouseReleaseEvent(QMouseEvent *event)
{
    isMousePressed=false;
}


/***************点击Enter键**********************/
void LoginDialog::keyPressEvent(QKeyEvent *k)
{
    if(k->key()==Qt::Key_Enter)
    {
        this->on_pushButtonLogin_clicked();//进行登录
    }
}


/***************写xml文件*********************/
void LoginDialog::writeXml()
{

    QFile file("login.xml");
    QDomDocument dom;

    if(file.open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(&file))  //将该xml文件导入到dom中
        {
            file.close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file.close();

    //创建一个新的用户
    QDomElement root=dom.documentElement();
    QDomElement user=dom.createElement("user");          //创建节点
    QDomAttr    id=dom.createAttribute("id");            //创建节点属性
    QDomElement usernm=dom.createElement("username");    //创建子节点
    QDomElement passwd=dom.createElement("password");    //创建子节点
    QDomElement remember=dom.createElement("remember");  //创建子节点
    QDomElement autoLogin=dom.createElement("autologin");//创建子节点
    QDomElement time=dom.createElement("time");          //创建子节点

    QDomText text;

    QString num=root.lastChild().toElement().attribute("id");  //获取xml文件最后一个id的大小是多少
    int count=num.toInt()+1;
    id.setValue(QString::number(count));                       //将id+1后添加到新建的用户中
    user.setAttributeNode(id);

    //将用户名写入XML文件中
    text=dom.createTextNode(ui->comboBoxUserName->currentText());
    usernm.appendChild(text);

    //将密码写入XML文件中
    text=dom.createTextNode(ui->lineEditPassWord->text());
    passwd.appendChild(text);

    //将记住密码标志写入XML文件中
    if(ui->checkBoxRemeber->isChecked())
    {
        text=dom.createTextNode("1");
        remember.appendChild(text);
    }
    else
    {
        text=dom.createTextNode("0");
        remember.appendChild(text);
    }

    //将自动登陆标志写入XML文件中
    if(ui->checkBoxAuto->isChecked())
    {
        text=dom.createTextNode("1");
        autoLogin.appendChild(text);
    }
    else
    {
        text=dom.createTextNode("0");
        autoLogin.appendChild(text);
    }

    //将登录的时间写入XML文件中
    text=dom.createTextNode(QDateTime::currentDateTime().toString("yyyyMMddhhmm"));
    time.appendChild(text);


    //将所有节点依次对应写到根节点的目录下
    user.appendChild(usernm);
    user.appendChild(passwd);
    user.appendChild(remember);
    user.appendChild(autoLogin);
    user.appendChild(time);
    root.appendChild(user);


    QFile f("login.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }


    QTextStream out(&f);
    dom.save(out,4);
    f.close();
}


/***************读取xml文件*******************/
bool LoginDialog::readXml()
{
    int Count=0;
    listStringPsd.clear();     //清空list存储
    listStringUsnm.clear();    //清空list存储
    listStringAuto.clear();    //清空list存储
    listStringRemember.clear();//清空list存储
    listStringID.clear();      //清空list存储
    listStringTime.clear();    //清空list存储


    QDomDocument dom;
    QFile *file=new QFile("login.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return false;
        }
    }
    else
    {
        return false;
    }
    file->close();
    QDomElement docElem=dom.documentElement();    //返回根元素

    QDomNode node=docElem.firstChild();           //返回根节点的第一个子节点

    while(!node.isNull())                         //如果节点不为空
    {
        if(node.isElement())                      //如果节点是元素
        {
            QDomElement element=node.toElement(); //将其转化为元素
            listStringID<<element.attribute("id");

            QDomNodeList list=element.childNodes();//取出该元素的所有子节点放到list中

            //将子节点元素全部取出来
            for(int i=0;i<list.count();i++)
            {
                QDomNode domNode=list.at(i);
                if(domNode.isElement())
                {
                    //将获取的数据一次存储到list列表中
                    switch(i)
                    {
                    case 0:ui->comboBoxUserName->addItem(domNode.toElement().text());listStringUsnm<<domNode.toElement().text();break;
                    case 1:listStringPsd<<domNode.toElement().text();break;
                    case 2:listStringRemember<<domNode.toElement().text();break;
                    case 3:listStringAuto<<domNode.toElement().text();break;
                    case 4:listStringTime<<domNode.toElement().text();break;
                    }

                }
            }
        }

        Count++;
        node=node.nextSibling(); //下一个兄弟节点

    }

    if(Count>0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


/***************更新xml文件********************/
void LoginDialog::updateXml(QString id,QString rem,QString aut)
{
    QDomDocument dom;
    QFile *file=new QFile("login.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file->close();
    QDomNodeList nodeList=dom.elementsByTagName("user");   //返回根元素
    //以标签名进行查找
    for(int i=0;i<nodeList.count();i++)
    {
        QDomElement e=nodeList.at(i).toElement();

        if(e.attribute("id")==id)
        {
            QDomNodeList child=nodeList.at(i).childNodes();        //找到它的所有子节点
            child.at(2).toElement().firstChild().setNodeValue(rem);//将子节点的内容更新
            child.at(3).toElement().firstChild().setNodeValue(aut);//将子节点的内容更新
            child.at(4).toElement().firstChild().setNodeValue(QDateTime::currentDateTime().toString("yyMMddhhmm"));//将子节点的内容更新
        }
    }


    QFile f("login.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}


/***************删除xml节点********************/
void LoginDialog::deletetXml()
{
    QDomDocument dom;
    QFile *file=new QFile("login.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file->close();
    QDomNodeList nodeList=dom.elementsByTagName("user");   //返回根元素
    //以标签名进行查找
    for(int i=0;i<nodeList.count();i++)
    {
        QDomElement e=nodeList.at(i).toElement();

        //判断如果最小时间日期的属性ID，与xml文件的属性ID相同时，删除
        if(e.attribute("id")==listStringID[this->minValudeTime()])
        {
            QDomElement root=dom.documentElement();   //取出根节点
            root.removeChild(nodeList.at(i));         //删除整个节点
        }
    }


    QFile f("login.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}


/***************找出最小日期********************/
int LoginDialog::minValudeTime()
{
    int minValue=0,minMark=0;
    //比较日期大小
    minValue=listStringTime[0].toInt();       //先假设最小值为第一个
    for(int i=0;i<listStringTime.count()-1;i++)
    {
        if(minValue>listStringTime[i+1].toInt())
        {
            minValue=listStringTime[i].toInt();
            minMark=i;                           //记住最小值的下标
        }
    }
    return minMark;
}


/***************点击列表框*********************/
void LoginDialog::on_comboBoxUserName_activated(const QString &arg1)
{

    int Count=0;
    int tempCount=0;
    for(int i=0;i<ui->comboBoxUserName->count();i++)
    {
        //将listFloat存储的信息读取出来，进行实时改变lineEdit的密码
        if(ui->comboBoxUserName->currentText()==listStringUsnm[i]&&listStringRemember[i]=="1")
        {
            Count++;
            ui->checkBoxRemeber->setChecked(true);
            ui->lineEditPassWord->setText(listStringPsd[i]);
            if(listStringAuto[i]=="1")
            {
                ui->checkBoxAuto->setChecked(true);
                tempCount++;
            }

        }

    }

    //根据读取到的数据判断其复选框是否选中，以及控件中是否填写密码
    if(Count==0)
    {
        ui->checkBoxRemeber->setChecked(false);
        ui->lineEditPassWord->clear();
    }
    if(tempCount==0)
    {
        ui->checkBoxAuto->setChecked(false);
    }

}


/***************列表框文本改变******************/
void LoginDialog::on_comboBoxUserName_currentTextChanged(const QString &arg1)
{
    int Count=0;
    //判断出如果不是已经在此登录过的密码,则清空
    for(int j=0;j<listStringUsnm.count();j++)
    {
        if(ui->comboBoxUserName->currentText()==listStringUsnm[j])
        {
            Count++;
        }
    }
    if(Count==0)
    {
        ui->lineEditPassWord->clear();
    }

}


/***************自动登陆************************/
void LoginDialog::on_checkBoxAuto_clicked()
{
    if(!ui->checkBoxRemeber->isChecked())
    {
        ui->checkBoxAuto->setChecked(false);
    }
}


/***************记住密码************************/
void LoginDialog::on_checkBoxRemeber_clicked()
{
    if(!ui->checkBoxRemeber->isChecked())
    {
        ui->checkBoxAuto->setChecked(false);
    }
}


/***************注册界面调用*********************/
void LoginDialog::on_pushButtonInsertData_clicked()
{
    registDialog.show();

}


/***************找回密码界面调用******************/
void LoginDialog::on_pushButtonBackData_clicked()
{
    back.show();
}




