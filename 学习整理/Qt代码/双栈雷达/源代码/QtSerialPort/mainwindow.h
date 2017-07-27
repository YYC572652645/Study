#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "win_qextserialport.h"
#include <QList>
#include <QFileDialog>
#include <QDir>
#include <QPainter>
#include <QLinearGradient>
#include <QPolygon>
#include<QTime>
#include<QToolButton>
#include<QPoint>
#include<QMouseEvent>
#include<QLabel>
#include<QBitmap>
#include<QSerialPortInfo>
#define DIS 1.8
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;




    /********************************变量******************************/
    Win_QextSerialPort *myCom;    //声明对象
    Win_QextSerialPort *myComTwo; //声明对象
    bool ok;                      //标志位
    bool okTwo;                   //标志位
    double remeberData;           //保存上一次的数据
    double hk;                    //现在的值
    double pk;                    //协方差
    double pknow;                 //协方差辅助
    double Q;                     //经验值
    double R;                     //经验值
    double kg;                    //增益值
    double hknow;                 //最终值
    double temphkNow;             //记忆数据

    double remeberDataTwo;           //保存上一次的数据
    double hkTwo;                    //现在的值
    double pkTwo;                    //协方差
    double pknowTwo;                 //协方差辅助
    double QTwo;                     //经验值
    double RTwo;                     //经验值
    double kgTwo;                    //增益值
    double hknowTwo;                 //最终值
    double temphkNowTwo;             //记忆数据
    QTimer *timer;                //定时器,0.3秒
    QTime time;                   //获取当前时间
    QFile*fileSave;               //自动保存文件
    bool fileOk;                  //打开文件标志位
    QFile*fileSaveTwo;               //自动保存文件
    bool fileOkTwo;                  //打开文件标志位
    QFile*fileSaveThree;               //自动保存文件
    bool fileOkThree;                  //打开文件标志位
    double s1;                    //实际距离
    double s2;                    //实际距离
    double s3;                    //预估距离
    double predictLeft;           //左预估值
    double predictRight;          //右预估值
    int nCount;                   //计数器
    QList<double>listFloat;       //存储距离

    double s1Two;                    //实际距离
    double s2Two;                    //实际距离
    double s3Two;                    //预估距离
    double predictLeftTwo;           //左预估值
    double predictRightTwo;          //右预估值
    int nCountTwo;                   //计数器
    QList<double>listFloatTwo;       //存储距离

    QPoint mousePosition;         //自己实现拖动操作
    bool isMousePressed;          //自己实现拖动操作
    QToolButton *minButton;       //最小化按钮
    QToolButton *maxButton;       //最大化按钮
    QToolButton *openCom;         //打开串口一
    QToolButton *openComTwo;      //打开串口一
    QToolButton *comClose;        //关闭串口二
    QToolButton *comCloseTwo;     //关闭串口二
    QToolButton *actionSave;      //保存按钮
    QToolButton *actionDelete;    //清空按钮
    QToolButton *closeButton;     //关闭按钮
    QLabel *labelTitle;           //软件名称
    QLabel *iconLabel;            //软件图标
    bool maxNormal;               //判断是否最大化标志位
    QPixmap normalPix;            //缩小图标
    QPixmap maxPix;               //最大化图标
    double vrel;                  //速度
    double vrelTwo;               //速度
    QVector<double>dataX;         //X坐标
    QVector<double>dataY;         //Y坐标


    /*******************************函数**********************************/
    void paintEvent(QPaintEvent *);
    /*****************************************画图函数
    返回值                                 void
    参数类型                               QPaintEvent*
    ************************************************/


    /********************************槽函数********************************/
private slots:
    void connCom();                    //连接
    void connComTwo();                 //连接
    void readCom();                    //定义槽函数读取串口数据
    void timeUpdate();                 //定义一个定时器
    void closeCom();                   //关闭串口
    void closeComTwo();                //关闭串口
    void saveFile();                   //保存文件
    void clearMessage();               //清空信息
    void on_pushButtonSave_clicked();  //保存
    void actionMin();                  //最小化窗口
    void actionMax();                  //最大化窗口
    void actionClose();                //关闭窗口


protected:

    //重新实现拖动操作
    void mouseMoveEvent(QMouseEvent*event);
    void mousePressEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);
    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MAINWINDOW_H
