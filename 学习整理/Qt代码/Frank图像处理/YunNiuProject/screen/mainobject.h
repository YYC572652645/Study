#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QObject>

class MainWindow;

/***************************************************************
   功能:调用闪屏和主类

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

class MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = 0);
    ~MainObject();

public :
    void setInit();//初始化

private:
    MainWindow *m_mainWindow;

};

#endif // MAINOBJECT_H
