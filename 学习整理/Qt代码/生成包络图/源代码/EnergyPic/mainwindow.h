#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolTip>
#include <QPainter>
#include <QPaintEvent>
#include <QEvent>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QAxObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QEvent>
#include "soundwidget.h"
#include <QDebug>

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

    /********************读取文件数据*******************/
    void on_actionRead_triggered();


    /********************导出Excel表格*****************/
    void on_actionExtend_triggered();

    void on_actionDistance_triggered();

    void on_actionSound_triggered();

private:
    Ui::MainWindow *ui;

    /********************重写事件***********************/
    bool eventFilter(QObject *watched, QEvent *event);

    /********************画图函数***********************/
    void paintImage();

    /********************导入Txt文档********************/
    void importTxt();

    /********************导入Excel**********************/
    void importExcel();

    /********************导出Excel**********************/
    void extendExcel();

    /********************重写事件函数*********************/
    bool event(QEvent *event);


    /********************存储数据的List*******************/
    QList<int>dataX;
    QList<int>dataY;
    QList<int>dataEnergy;
    QList<int>angle;
    QList<float>db;


    /********************创建操作excel对象*****************/
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;



    QString fileName;  //文件名称
    float X;           //横坐标
    float Y;           //纵坐标
    int dataCount;     //数据条数
    int dataCountEnergy;//数据条数
    int flage;         //设置标志位
    SoundWidget * sound;



};

#endif // MAINWINDOW_H
