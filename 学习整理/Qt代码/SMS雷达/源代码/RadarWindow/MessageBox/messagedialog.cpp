#include "messagedialog.h"
#include "ui_messagedialog.h"

MessageDialog* MessageDialog::m_staticInstance=NULL;//静态对象
const QString okText="确定";
const QString cancelText="取消";

/****************************************构造函数*******************************/
MessageDialog::MessageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MessageDialog)
{
    ui->setupUi(this);
    MessageDialog::m_staticInstance=this; //给静态变量赋值
    this->resize(320,160);    //重定义界面大小
    int width=this->width();  //获取界面宽度
    int height=this->height();//获取界面高度
    mousePress=false;         //初始化为未按下鼠标左键
    this->setWindowFlags(Qt::FramelessWindowHint);//标题框隐藏

    //加载图标
    QPixmap closePix=style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    closeButton=new QToolButton(this);
    closeButton->setIcon(closePix);
    closeButton->setGeometry(width-30,0,30,30);
    closeButton->setObjectName("closeButton");

    //设置标题
    titleLabel=new QLabel(this);
    titleLabel->setObjectName(QString::fromUtf8("labelOne"));
    QFont font=titleLabel->font();
    font.setBold(true);
    titleLabel->setFont(font);
    titleLabel->setGeometry(0,0,width-50,30);


    //设置图片
    imgLabel=new QLabel(this);
    imgLabel->setGeometry(20,50,36,36);
    imgLabel->setScaledContents(true);


    //设置消息
    msgLabel=new QLabel(this);
    msgLabel->setGeometry(65,60,width-100,50);
    msgLabel->setWordWrap(true);
    msgLabel->setAlignment(Qt::AlignTop);
    msgLabel->setObjectName(QString::fromUtf8("labelTwo"));


    //取消按钮
    cancelButton=new QPushButton(this);
    cancelButton->resize(100,25);
    cancelButton->move(width-cancelButton->width()-10,height-35);
    cancelButton->setObjectName(QString::fromUtf8("PushButtonCancel"));

    //确定按钮
    okButton=new QPushButton(this);
    okButton->resize(100,25);
    okButton->move(width-okButton->width()-cancelButton->width()-20,height-35);
    okButton->setObjectName(QString::fromUtf8("PushButtonOK"));

    //连接信号与槽
    connect(okButton,SIGNAL(clicked(bool)),this,SLOT(okOperate()));
    connect(cancelButton,SIGNAL(clicked(bool)),this,SLOT(cancelOperate()));
    connect(closeButton,SIGNAL(clicked(bool)),this,SLOT(close()));      //关闭按钮

}


/****************************************析构函数*******************************/
MessageDialog::~MessageDialog()
{
    delete ui;
}


/****************************************设置函数*******************************/
void MessageDialog::setInfo(QString titleInfo, QString info, QPixmap pixmap, bool isOkHidden)
{
    //设置标题
    titleLabel->setText(" "+titleInfo);

    //设置提示信息
    msgLabel->setText(info);

    //设置图标
    imgLabel->setPixmap(pixmap);

    //是否隐藏确定按钮
    okButton->setHidden(isOkHidden);
    if(isOkHidden)
    {
        cancelButton->setText(okText);
    }
    else
    {
        okButton->setText(okText);
        cancelButton->setText(cancelText);
    }
    //设置默认按钮为取消按钮
    cancelButton->setFocus();
}


/****************************************画图函数*******************************/
void MessageDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/new/prefix1/RES/background1.png"));
    QBitmap bitmap(this->size());
    QPainter painter2(&bitmap);
    painter2.fillRect(bitmap.rect(),Qt::white);
    painter2.setBrush(QColor(0,0,0));
    painter2.drawRoundedRect(rect(),4,4);
    setMask(bitmap);
}


/****************************************鼠标点击*******************************/
void MessageDialog::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        mousePress=true;
    }
    movePoint=event->globalPos()-pos();
}


/****************************************鼠标释放*******************************/
void MessageDialog::mouseReleaseEvent(QMouseEvent *event)
{
    mousePress=false;
}


/****************************************鼠标移动*******************************/
void MessageDialog::mouseMoveEvent(QMouseEvent *event)
{
    if( mousePress)
    {
        QPoint movePos=event->globalPos();
        move(movePos-movePoint);
    }
}


/****************************************确定函数*******************************/
void MessageDialog::okOperate()
{
    this->accept();
}


/****************************************取消函数*******************************/
void MessageDialog::cancelOperate()
{
    this->reject();
}
