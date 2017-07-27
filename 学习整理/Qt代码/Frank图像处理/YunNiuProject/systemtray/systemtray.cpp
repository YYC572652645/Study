#include "systemtray.h"
#include "globaldef.h"
#include <QDebug>
#include <QIcon>
#include "version/versiondialog.h"

SystemTray::SystemTray(QWidget * parent)
    :QSystemTrayIcon(parent)
{
    this->createAction();  //创建托盘菜单
    this->addAction();     //菜单添加事件

}

SystemTray::~SystemTray()
{

}

void SystemTray::addAction()
{
    myMenu->addAction(showWidget);
    myMenu->addAction(minWidget);
    myMenu->addAction(setUpLanguage);
    myMenu->addAction(aboutSoftWare);
    myMenu->addAction(exitSoftWare);
}

void SystemTray::createAction()
{
    myMenu = new QMenu();                                         //托盘菜单
    showWidget = new QAction(tr("显示窗口 "), this);                //最大化
    minWidget = new QAction(tr("隐藏窗口 "), this);                 //最小化
    setUpLanguage = new QAction(tr("设置语言 "), this);             //设置语言
    aboutSoftWare = new QAction(tr("关于软件 "), this);             //关于软件
    exitSoftWare = new QAction(tr("退出软件 "), this);              //退出软件

    this->setIcon(QIcon(ICONPATH));
    this->setToolTip(tr("Frank 图像处理"));

    connect(exitSoftWare, SIGNAL(triggered(bool)), qApp, SLOT(quit())); //退出软件

    this->setContextMenu(myMenu);

    this->show();
}

void SystemTray::switchLanguage(int language)
{
    if(language == ENGLISH)
    {
        showWidget->setText("Show Widget");           //最大化
        minWidget->setText("Hide Widget");            //最小化
        setUpLanguage->setText("Set Language");       //设置语言
        aboutSoftWare->setText("About");              //关于软件
        exitSoftWare->setText("Quit");                //退出软件
    }
    else
    {
        showWidget->setText("显示窗口 ");                //最大化
        minWidget->setText("隐藏窗口 ");                 //最小化
        setUpLanguage->setText("设置语言 ");             //设置语言
        aboutSoftWare->setText("关于软件 ");             //关于软件
        exitSoftWare->setText("退出软件 ");              //退出软件
    }
}
