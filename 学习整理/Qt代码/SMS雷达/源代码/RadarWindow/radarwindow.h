#ifndef RADARWINDOW_H
#define RADARWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QTime>
#include <QToolButton>
#include <QPoint>
#include <QPaintEvent>
#include <QBitmap>
#include <QPainter>
#include <QPixmap>
#include <QDesktopWidget>
#include <QCursor>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QConicalGradient>
#include <QScrollBar>
#include <windows.h>
#include <QTime>
#include <QFile>
#include <QEvent>
#include <QTextStream>
#include <math.h>
#include "qextserial/qextserialport.h"
#include"MessageBox/messagedialog.h"
#include<QtSerialPort/QSerialPortInfo>


namespace Ui {
class RadarWindow;
}

class RadarWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RadarWindow(QWidget *parent = 0);
    ~RadarWindow();

private:
    Ui::RadarWindow *ui;
    QextSerialPort *myCom;    //声明对象
    bool ok;                  //串口打开状态
    QTimer *timer;            //定时器,0.3秒
    QTime time;               //获取当前时间
    QFile *fileSave;          //自动保存文件
    bool fileOk;              //打开文件标志
    int nCount;               //计数器
    int indexTarget;          //目标指针
    float XTarget[6];         //X坐标
    float YTarget[6];         //Y坐标
    float XSpeedTarget[6];    //X方向速度
    float YSpeedTarget[6];    //Y方向速度
    QPoint mousePosition;     //自己实现拖动操作
    bool isMousePressed;      //自己实现拖动操作
    QToolButton *minButton;   //最小化按钮
    QToolButton *maxButton;   //最大化按钮
    QToolButton *closeButton; //关闭按钮
    QLabel *labelTitle;       //软件名称
    QLabel *iconLabel;        //软件图标
    bool maxNormal;           //判断是否最大化标志位
    QPixmap normalPix;        //缩小图标
    QPixmap maxPix;           //最大化图标
    int vrel;                 //速度
    int Count;                //计数器
    QImage imgOther;          //反面图像
    QImage imgFrond;          //正面图像

private slots:

    /************连接串口**************/
    void connCom();

    /************读取串口数据***********/
    void readCom();

    /************定义定时器*************/
    void timeUpdate();

    /************最小化窗口************/
    void actionMin();

    /************最大化窗口************/
    void actionMax();

    /************关闭窗口**************/
    void actionClose();

    /************重写画图函数***********/
    void on_pushButtonSave_clicked();

    /************纵向像素移动***********/
    void on_horizontalSlider_sliderMoved(int position);

    /************横向像素移动***********/
    void on_horizontalSlider_2_sliderMoved(int position);

    /************纵向像素值改变*********/
    void on_horizontalSlider_valueChanged(int value);

    /************横向向像素值改变*******/
    void on_horizontalSlider_2_valueChanged(int value);

protected:

    /************鼠标移动*************/
    void mouseMoveEvent(QMouseEvent*event);

    /************鼠标点击*************/
    void mousePressEvent(QMouseEvent*event);

    /************鼠标释放*************/
    void mouseReleaseEvent(QMouseEvent*event);

    /************画图函数**************/
    void paintImage();

    /************重写画图函数***********/
    bool eventFilter(QObject *watched, QEvent *event);

    /************重写画图函数***********/
    void paintEvent(QPaintEvent*event);
};

#endif // RADARWINDOW_H
