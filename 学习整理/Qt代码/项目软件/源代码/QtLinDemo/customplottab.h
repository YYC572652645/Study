#ifndef CUSTOMPLOTTAB_H
#define CUSTOMPLOTTAB_H
#include <windows.h>
#include <QWidget>
#include <QVector>
#include <QThread>
#define TextColor      QColor(0,0,0)        //坐标颜色
#define LineColorOne   QColor(41,138,220)   //线颜色
#define LineColorTwo   QColor(246,98,0)     //线颜色
#define LineColorThree QColor(255,10,10)    //线颜色
#define LineColorFour  QColor(144,238,144)  //线颜色
#define PlotNoColor    QColor(0,0,0,0)      //无颜色

//存储数据XY坐标
typedef struct DataPlot
{
    QVector<double>dataX;
    QVector<double>dataY;

}DataPlot;


namespace Ui {
class customPlotTab;
}
class CustomPlotThread;
class customPlotTab : public QWidget
{
    Q_OBJECT

public:
    explicit customPlotTab(QWidget *parent = 0);
    ~customPlotTab();

private:
    Ui::customPlotTab *ui;
public:
    float dataAX;
    float dataAY;
    float dataBX;
    float dataBY;

    /**********************初始化函数***********************/
    void initPlot();

    /**********************显示悬浮框***********************/
    void showLegnd();
public:
    void setUpPlot();
    DataPlot*dataPlot;
private slots:
    /**********************移动缩放************************/
    void on_checkBoxMoveChange_clicked();

    /**********************显示悬浮框**********************/
    void on_checkBoxPicChange_clicked();

    /**********************加背景图例**********************/
    void on_checkBoxBackGroundCge_clicked();

    /**********************清空信息**********************/
    void on_pushButtonClear_clicked();

    /**********************读取数据**********************/
    void on_pushButtonReadMessage_clicked();


    void on_pushButtonReadInfo_clicked();

signals:
    void readInfo();
    void readInfoMessage();

};

#endif // CUSTOMPLOTTAB_H

class CustomPlotThread:public QThread
{
private:
    customPlotTab *plot;
public:
    /**********************构造函数**********************/
    CustomPlotThread(customPlotTab *plot);

    /**********************线程运行函数*******************/
    virtual void run();

};
