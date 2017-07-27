#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QPaintEvent>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDragEnterEvent>

const static QPoint POINT = QPoint(8, 31);

namespace Ui {
class MainWindow;
}

/***************************************************************
   功能:事件响应例子

   创建人:殷宇辰

   创建时间:2017-7-13
**************************************************************/


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void closeEvent(QCloseEvent* event);                                                      //关闭事件
    void mousePressEvent(QMouseEvent*event);                                                  //鼠标点击
    void mouseReleaseEvent(QMouseEvent *event);                                               //鼠标释放
    void mouseMoveEvent(QMouseEvent *event);                                                  //鼠标移动
    void mouseDoubleClickEvent(QMouseEvent *event);                                           //鼠标双击事件
    void wheelEvent(QWheelEvent*event);                                                       //滚轮滚动事件
    void paintEvent(QPaintEvent * event);                                                     //画图事件
    void enterEvent(QEvent*event);                                                            //鼠标进入事件
    void leaveEvent(QEvent*event);                                                            //鼠标离开事件
    void keyPressEvent(QKeyEvent*event);                                                      //键盘响应事件
    void dragEnterEvent(QDragEnterEvent * event);                                             //拖入事件
    void dropEvent(QDropEvent*event);                                                         //释放事件

private:
    float sliderValue;                 //进度条的值
    QPoint startRectPoint;             //点坐标
    QPoint endRectPoint;               //点坐标
};

#endif // MAINWINDOW_H
