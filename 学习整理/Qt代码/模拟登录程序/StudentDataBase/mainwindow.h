#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "logindialog.h"
#include "logindata.h"
#include <QDesktopWidget>
#include <QPaintEvent>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QString>
#include "workthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void DataSelect();                    //查询数据
    void exitLogin();                     //退出登录
    void dataCount(int Count);            //接收子线程数据
    void dataStruct(StudentData *student);//接收子线程数据

private:
    Ui::MainWindow *ui;
    WorkThread *workThread;   //创建子线程对象
    LoginData loginData;      //创建数据库类对象 
    LoginDialog dialog;       //登录对话框对象
    int countData;            //保存数据库中查询的数据条数

};

#endif // MAINWINDOW_H
