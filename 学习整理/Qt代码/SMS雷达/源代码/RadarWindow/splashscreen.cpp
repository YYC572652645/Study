#include "splashscreen.h"
#include <QPainter>
#include <QTimer>
#include <QApplication>
#include <QGuiApplication>
#include <QDebug>

SplashScreen * SplashScreen::m_staticInstance=NULL;

SplashScreen::SplashScreen(const QPixmap &pixmap, Qt::WindowFlags f):
    QSplashScreen(pixmap,f)
  ,m_percent(0)
  ,m_showTimer(new QTimer(this))
  ,m_widget(NULL)
{
    SplashScreen::m_staticInstance=this;
    //
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);
    m_showTimer->setInterval(20);
    connect(m_showTimer,SIGNAL(timeout()),this,SLOT(addWidgetOpacity()));
    this->setDisabled(true);
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QFont font(QString("微软雅黑"));
    QPen pen;
    pen.setColor(Qt::white);
    painter.setPen(pen);
    QBrush brush(QColor(100,100,100,255));
    painter.setBrush(brush);
    painter.drawRoundedRect(70,this->rect().height()-70,(this->rect().width()-70*2),7,4,10);
    //drawLogo
    font.setPixelSize(18);
    font.setBold(true);
    painter.setFont(font);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawPixmap(this->width()/2-m_pixLogo.width()/2,50,m_pixLogo);
    painter.drawText(0,m_pixLogo.height()+50+50,this->width(),20,Qt::AlignCenter,m_textLogo);
    //drawMessage
    font.setPixelSize(16);
    font.setBold(true);
    painter.setFont(font);
    pen.setColor(Qt::yellow);
    painter.setPen(pen);
    painter.drawText(0,this->height()-70-70,this->width(),20,Qt::AlignCenter,m_message);
    //drawLine(%)
    pen.setColor(Qt::white);
    painter.setPen(pen);
    if(m_percent!=0)
    {
        QBrush brush(Qt::white);
        painter.setBrush(brush);
        painter.drawRoundedRect(70,this->rect().height()-70,(this->rect().width()-70*2)*m_percent/100,7,4,10);
    }
    //drawPercent(%)
    font.setPixelSize(14);
    font.setBold(false);
    painter.setFont(font);
    pen.setColor(Qt::white);
    painter.setPen(pen);
    painter.drawText(0,this->rect().height()-70,this->rect().width(),70-20,Qt::AlignCenter,QString::number(m_percent,'f',0)+QString("%"));
    //
    painter.end();
    //----------------------------------
    this->activateWindow();
}
/*************************************设置进度****************************************/
void SplashScreen::setStagePercent(const int &percent, const QString &message)
{
    if(this->isHidden())
    {
        this->show();
    }
    if(!this->isActiveWindow())
    {
        this->activateWindow();
        this->raise();
    }
    m_message=message;

    while (m_percent<percent)
    {
        m_percent=m_percent+0.1;
        qApp->processEvents();
        this->repaint();
    }
}

void SplashScreen::setStart(QWidget *widget, const QString &title, const QString &logoFile)
{
    m_widget=widget;
    m_pixLogo=QPixmap(logoFile);
    m_textLogo=title;
    widget->setWindowOpacity(0);
}

void SplashScreen::setFinish()
{
    this->close();
    m_showTimer->start();
    //
    m_widget->activateWindow();
    m_widget->raise();
}

void SplashScreen::addWidgetOpacity()
{
    if(m_widget==NULL){
        m_showTimer->stop();
        return;
    }
    if(m_widget->windowOpacity()<1)
    {
        m_widget->setWindowOpacity(m_widget->windowOpacity()+0.1);
    }
    else
    {
        m_showTimer->stop();
        this->finish(m_widget);
        this->deleteLater();
    }
}
