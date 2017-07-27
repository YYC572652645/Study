#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include "win_qextserialport.h"
#include <QTimer>
#include <QTime>
#include <QIODevice>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QPaintEvent>
#include <QPainter>
#include <QImage>
#include <QDebug>
#include <QInputDialog>
#include <QPolygon>
#include <QDesktopWidget>
#include <QPolygon>
#include "paintwidget.h"
#define TIME_OUT 10     //TIME_OUT是串口读写的延时


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



/***************************私有变量***************************/
private:
    Ui::MainWindow *ui;
    Win_QextSerialPort *myCom; //声明串口对象
    QTimer *timer;             //定时器,0.3秒
    QTimer *sendTimer;         //定时器
    QTime time;                //获取当前时间
    QFile *fileSave;           //自动保存文件
    bool fileOk;               //打开文件标志位
    bool ok;                   //打开串口标志位


/***************************私有函数***************************/
private:
    bool eventFilter(QObject *watched, QEvent *event);
    void paintImage();
    void mouseDoubleClick();


/***************************私有槽***************************/
private slots:
    void sengMessage();                  //发送数据
    void connCom();                      //连接串口
    void readCom();                      //定义槽函数读取串口数据
    void timeUpdate();                   //定义一个定时器
    void on_actionAutoSave_triggered();  //自动保存
    void on_actionOpenPort_triggered();  //打开串口
    void on_actionClosePort_triggered(); //关闭串口
    void on_actionExit_triggered();      //退出程序
    void on_actionClearPort_triggered(); //清空串口
    void on_actionAddPort_triggered();   //添加串口
    void on_pushButtonSend_clicked();    //发送指令
    void on_checkBoxSendCon_clicked();   //自动发送
};

#endif // MAINWINDOW_H
