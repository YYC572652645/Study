#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H
#include <QMainWindow>
#include <QDialog>
#include "logindata.h"
#include "backpassworddialog.h"
#include <QMessageBox>
#include <QToolButton>
#include <QPixmap>
#include <QDesktopWidget>
#include <QPoint>
#include <QMoveEvent>
#include <QPaintEvent>
#include <QTextStream>
#include <QList>
#include <QKeyEvent>
#include "registerdialog.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_pushButtonLogin_clicked(); //登录按钮
    void actionMin();                  //最小化窗口
    void actionClose();                //关闭窗口
    void on_comboBoxUserName_activated(const QString &arg1);
    void on_comboBoxUserName_currentTextChanged(const QString &arg1);
    void on_checkBoxAuto_clicked();        //自动登录复选按钮
    void on_checkBoxRemeber_clicked();     //记住密码复选按钮
    void on_pushButtonInsertData_clicked();//注册帐号按钮
    void on_pushButtonBackData_clicked();  //找回密码按钮

private:
    Ui::LoginDialog *ui;
    LoginData *login;                //定义数据库类对象
    QPoint mousePosition;            //自己实现拖动操作
    bool isMousePressed;             //自己实现拖动操作
    QToolButton *minButton;          //最小化按钮
    QToolButton *closeButton;        //关闭按钮
    QList<QString>listStringUsnm;    //用来存储用户名
    QList<QString>listStringPsd;     //用来存储密码
    QList<QString>listStringRemember;//用来存储是否密码
    QList<QString>listStringAuto;    //用来存储是否自动登录
    QList<QString>listStringID;      //用来存储属性ID
    QList<QString>listStringTime;    //用来存储登录的时间
protected:
    void mouseMoveEvent(QMouseEvent*event);              //鼠标移动
    void mousePressEvent(QMouseEvent*event);             //鼠标点击
    void mouseReleaseEvent(QMouseEvent*event);           //鼠标释放
    void keyPressEvent(QKeyEvent*k);                     //点击Enter键
    void writeXml();                                     //写xml文件
    bool readXml();                                      //读取xml文件
    void updateXml(QString id, QString rem, QString aut);//更新xml文件
    void deletetXml();                                   //删除xml文件
    int minValudeTime();                                 //找出最小日期
    RegisterDialog registDialog;                         //定义注册对象
    BackPassWordDialog back;                             //定义找回密码对象

};

#endif // LOGINDIALOG_H
