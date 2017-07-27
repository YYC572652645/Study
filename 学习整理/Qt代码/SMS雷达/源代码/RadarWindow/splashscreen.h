#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QSplashScreen>

class SplashScreen : public QSplashScreen
{
    Q_OBJECT
public:
    explicit SplashScreen(const QPixmap &pixmap = QPixmap(), Qt::WindowFlags f = 0);
    ~SplashScreen();
    //初始化界面
    static SplashScreen *getInstance()
    {
        if(m_staticInstance==NULL)
        {
            m_staticInstance=new SplashScreen(QPixmap(":/new/prefix1/RES/loading.png"));
        }
        return m_staticInstance;
    }


protected:
    void paintEvent (QPaintEvent *event);

private:
    static SplashScreen *m_staticInstance;
    double m_percent;
    QTimer *m_showTimer;
    QWidget *m_widget;
    QPixmap m_pixLogo;
    QString m_textLogo;
    QString m_message;
/////////////////////////////////
public:
    void setStagePercent(const int &percent,const QString &message);            //设置进度
    void setStart(QWidget *widget,const QString &title,const QString &logoFile);//设置开始
    void setFinish();//设置结束
/////////////////////////////////////
private slots:
    void addWidgetOpacity();
};

#endif // SPLASHSCREEN_H
