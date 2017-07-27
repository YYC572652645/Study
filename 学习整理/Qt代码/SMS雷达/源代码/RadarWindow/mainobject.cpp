#include "mainobject.h"
#include "radarwindow.h"
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
    m_mainWindow=new RadarWindow(0);
    m_mainWindow->setWindowTitle(tr("雷达"));
    SplashScreen::getInstance()->setStart(m_mainWindow,tr("奥迪威传感科技"),QString(""));
    SplashScreen::getInstance()->setStagePercent(40,tr("初始化主界面 ..."));
    SplashScreen::getInstance()->setStagePercent(80,tr("加载界面 ..."));
    SplashScreen::getInstance()->setStagePercent(100,tr("加载完毕！"));
    SplashScreen::getInstance()->setFinish();

    m_mainWindow->showNormal();
}


