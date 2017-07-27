#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include<QSystemTrayIcon>
#include<QAction>
#include<QApplication>
#include<QMenu>
#include<QWidget>
#include<QObject>

/***************************************************************
   功能:系统托盘

   创建人:殷宇辰

   创建时间:2017-6-28
**************************************************************/

class SystemTray : public QSystemTrayIcon
{
    Q_OBJECT
public:
    explicit SystemTray(QWidget * parent = 0);
    ~SystemTray();

    void addAction();   //添加菜单
    void createAction(); //创建菜单

public:
    QMenu *myMenu;                   //托盘菜单
    QAction* showWidget;             //显示窗口
    QAction* minWidget;              //隐藏窗口
    QAction* setUpLanguage;          //设置语言
    QAction* aboutSoftWare;          //关于软件
    QAction* exitSoftWare;           //退出软件
 signals:
    void showMainWindow();
    void showAboutUs();

private slots:
      void switchLanguage(int language);        //切换语言
};

#endif // SYSTEMTRAY_H
