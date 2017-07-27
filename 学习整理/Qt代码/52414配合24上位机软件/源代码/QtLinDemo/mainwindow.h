#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <windows.h>
#include <QBitmap>
#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include <QEvent>
#include <QLabel>
#include <QVBoxLayout>
#include <QFile>
#include <QIODevice>
#include <QFileDialog>
#include "Config/qreadwriteini.h"
#include <QtSerialPort/QSerialPortInfo>
#include "qextserial/qextserialport.h"
#include <QToolButton>


//读写延时
#define TIME_OUT   10

//帧头帧尾
#define LINMSGHEAD 0x68
#define LINMSGTAIL 0x16
#define AB         0.4
#define OB         0.2

//颜色
#define TextColor      QColor(220,30,30)
#define LineColorOne   QColor(41,138,220)
#define LineColorTwo   QColor(246,98,0)
#define LineColorThree QColor(255,10,10)
#define LineColorFour  QColor(69, 187, 217,150)

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();
    enum Frame
    {
        Conn,      //握手连接
        Baud,      //波特率
        Channel,   //通道
        Imp,       //主从模式
        Length,    //长度
        Load,      //加载
        Deal       //协议
    };
private slots:

    /**********************打开串口***********************/
    void on_pushButtonOpen_clicked();


    /**********************定时器函数*********************/
    void timeUpdate();


    /**********************握手连接***********************/
    void on_pushButtonConn_clicked();


    /**********************更改通道***********************/
    void on_comboBoxGallery_activated(const QString &arg1);


    /**********************更改波特率*********************/
    void on_comboBoxBaud_2_activated(const QString &arg1);


    /**********************更改主从***********************/
    void on_checkBoxImp_clicked();


    /**********************更改协议***********************/
    void on_comboBoxDeal_activated(const QString &arg1);


    /**********************清空**************************/
    void on_pushButtonClear_clicked();


    /**********************保存数据********************/
    void on_pushButtonSave_clicked();


    /**********************蜂鸣器声音********************/
    void beepUpdate();


    /**********************串口更新********************/
    void comUpdate();

private:
    Ui::MainWindow *ui;
    QextSerialPort *myCom;      //声明串口对象
    QTimer *timer;              //定时器
    QTimer *timerBeep;          //定时器
    QTimer *timerCom;          //定时器
    bool handShake;             //握手连接
    bool ok;                    //打开串口标志位
    QByteArray tempData;        //存储接收到的数据
    QLabel *titleLabel;         //标题框
    int heightCar;

    /**********************连接串口**********************/
    void connCom();

    /**********************读取数据**********************/
    void readCom();

    /**********************去除空格**********************/
    void deBlank(QString &str);

    /**********************窗口关闭**********************/
    void closeEvent(QCloseEvent*event);

    /**********************读取探头数据*******************/
    inline void readMessage(QByteArray temp);

    /**********************握手数据**********************/
    inline void readConn(QByteArray temp);

    /**********************保存信息函数*******************/
    void saveConfig();


    /**********************读取信息函数*******************/
    void readConfig();

    /**********************蜂鸣器定时响应*******************/
    void beepTime(int time);

    /**********************设置命令**********************/
    inline void setupFrame(Frame ID);

    /**********************插入数据**********************/
    inline void insertFlage(BYTE flage, QByteArray &array);

    /**********************画图********************/
    void paintPix();

    /**********************事件过滤********************/
    bool eventFilter(QObject *watched, QEvent *event);


};

#endif // MAINWINDOW_H
