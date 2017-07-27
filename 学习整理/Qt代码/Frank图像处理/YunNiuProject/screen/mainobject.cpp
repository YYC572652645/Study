#include "mainobject.h"
#include "mainwindow.h"
#include "splashscreen.h"
#include <QDebug>



MainObject::MainObject(QObject *parent) :
    QObject(parent)
{
}

MainObject::~MainObject()
{
    delete m_mainWindow;
}

void MainObject::setInit()
{
    SplashScreen::getInstance()->setStagePercent(0,tr("初始化应用程序 ..."));
    m_mainWindow=new MainWindow(0);
    m_mainWindow->setWindowTitle(tr("Frank 图像处理"));
    SplashScreen::getInstance()->setStart(m_mainWindow,tr(""),QString(":/image/res/LOGO.png"));
    SplashScreen::getInstance()->setStagePercent(40,tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(80,tr("加载界面 ..."));
    SplashScreen::getInstance()->setStagePercent(100,tr("加载完毕！"));
    SplashScreen::getInstance()->setFinish();

    m_mainWindow->showNormal();
}


