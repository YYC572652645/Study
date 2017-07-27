#include "suspendform.h"
#include "ui_suspendform.h"

SuspendForm*SuspendForm::instance=NULL;

SuspendForm::SuspendForm(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint),
    ui(new Ui::SuspendForm)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("学生信息管理系统"));
    this->setAttribute(Qt::WA_TranslucentBackground,true);
    setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::X11BypassWindowManagerHint|Qt::FramelessWindowHint);
    menu= new QMenu();
    actionClose = new QAction(QIcon(":/new/prefix1/image/system-users.png"), tr("退出程序"), this);
    actionShow = new QAction(QIcon(":/new/prefix1/image/system-users.png"), tr("显示窗口"), this);

    menu->addAction(actionShow);
    menu->addAction(actionClose);
    connect(actionShow,SIGNAL(triggered()),this,SLOT(actionShowFrame()));
    connect(actionClose,SIGNAL(triggered()),this,SLOT(actionCloseFrame()));
}

SuspendForm::~SuspendForm()
{
    delete ui;
}

SuspendForm *SuspendForm::getInstance()
{
    if(instance==NULL)
    {
        instance=new SuspendForm();
    }
    return instance;
}


void SuspendForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        point = this->pos()- event->globalPos();
    }
    else if(event->button()==Qt::RightButton)
    {
        menu->exec(QCursor::pos());
    }
}


void SuspendForm::mouseMoveEvent(QMouseEvent *event)
{
    this->move(event->globalPos() + point);
}

void SuspendForm::actionShowFrame()
{
    emit sendFlage(1);
}

void SuspendForm::actionCloseFrame()
{
    emit sendFlage(0);
}
