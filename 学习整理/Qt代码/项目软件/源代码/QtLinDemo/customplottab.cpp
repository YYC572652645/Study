/***************************************************
 *
 *  名称：--------------------------------------------
 *  显示曲线
 *
 *
 *  功能：--------------------------------------------
 *  1.通过发送指令读取1D信息，在串口设置中发送指令
 *  2.将接收到的信息解包，将数据放到当前结构体数组中画曲线
 *
 *
 *  目的：---------------------------------------------
 *  能够同时将ID号为5，6，7，8的探头原始数据通过曲线显示出来
 *
 * **************************************************/

#include "customplottab.h"
#include "ui_customplottab.h"

/*************************构造函数**************************/
customPlotTab::customPlotTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customPlotTab)
{
    ui->setupUi(this);
    initPlot();
    dataPlot=new DataPlot[4];

    this->dataPlot[0].dataX.resize(63);
    this->dataPlot[0].dataY.resize(63);
    this->dataPlot[1].dataX.resize(63);
    this->dataPlot[1].dataY.resize(63);
    this->dataPlot[2].dataX.resize(63);
    this->dataPlot[2].dataY.resize(63);
    this->dataPlot[3].dataX.resize(63);
    this->dataPlot[3].dataY.resize(63);
}

/*************************析构函数**************************/
customPlotTab::~customPlotTab()
{
    delete []dataPlot;
    delete ui;

}

/*************************初始化函数*************************/
void customPlotTab::initPlot()
{
    //设置坐标轴
    ui->customPlot->xAxis->setLabel("时间(单位:ms)");
    ui->customPlot->yAxis->setLabel("幅值(单位:db)");
    ui->customPlot->xAxis->setLabelColor(TextColor);
    ui->customPlot->yAxis->setLabelColor(TextColor);
    ui->customPlot->xAxis->setTickLabelColor(TextColor);
    ui->customPlot->yAxis->setTickLabelColor(TextColor);

    //加该曲线名称
    ui->customPlot->legend->setIconSize(0,0);
    ui->customPlot->legend->setTextColor(TextColor);
    ui->customPlot->legend->setVisible(false);
    ui->customPlot->axisRect()->setupFullAxesBox();
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot->legend->setBrush(QColor(255,255,255,0));


    //根据数据进行画图
    ui->customPlot->addGraph();                     //向绘图区添加一条曲线

    //设置坐标轴显示范围
    ui->customPlot->xAxis->setRange(0,20.16);
    ui->customPlot->yAxis->setRange(0,255);

    //设置曲线颜色
    QPen pen;
    pen.setWidth(3);
    pen.setColor(LineColorOne);
    ui->customPlot->graph(0)->setPen(pen);

    //设置坐标轴
    ui->customPlot_2->xAxis->setLabel("时间(单位:ms)");
    ui->customPlot_2->yAxis->setLabel("幅值(单位:db)");
    ui->customPlot_2->xAxis->setLabelColor(TextColor);
    ui->customPlot_2->yAxis->setLabelColor(TextColor);
    ui->customPlot_2->xAxis->setTickLabelColor(TextColor);
    ui->customPlot_2->yAxis->setTickLabelColor(TextColor);

    //加该曲线名称
    ui->customPlot_2->legend->setVisible(false);
    ui->customPlot_2->legend->setTextColor(TextColor);
    ui->customPlot_2->legend->setIconSize(0,0);
    ui->customPlot_2->axisRect()->setupFullAxesBox();
    ui->customPlot_2->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot_2->legend->setBrush(QColor(255,255,255,0));

    //根据数据进行画图
    ui->customPlot_2->addGraph();                     //向绘图区添加一条曲线

    //设置坐标轴显示范围
    ui->customPlot_2->xAxis->setRange(0,20.16);
    ui->customPlot_2->yAxis->setRange(0,255);

    //设置曲线颜色
    pen.setColor(LineColorTwo);
    ui->customPlot_2->graph(0)->setPen(pen);

    //设置坐标轴
    ui->customPlot_3->xAxis->setLabel("时间(单位:ms)");
    ui->customPlot_3->yAxis->setLabel("幅值(单位:db)");
    ui->customPlot_3->xAxis->setLabelColor(TextColor);
    ui->customPlot_3->yAxis->setLabelColor(TextColor);
    ui->customPlot_3->xAxis->setTickLabelColor(TextColor);
    ui->customPlot_3->yAxis->setTickLabelColor(TextColor);

    //加该曲线名称
    ui->customPlot_3->legend->setVisible(false);
    ui->customPlot_3->legend->setTextColor(TextColor);
    ui->customPlot_3->legend->setIconSize(0,0);
    ui->customPlot_3->axisRect()->setupFullAxesBox();
    ui->customPlot_3->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot_3->legend->setBrush(QColor(255,255,255,0));

    //根据数据进行画图
    ui->customPlot_3->addGraph();                     //向绘图区添加一条曲线

    //设置坐标轴显示范围
    ui->customPlot_3->xAxis->setRange(0,20.16);
    ui->customPlot_3->yAxis->setRange(0,255);

    //设置曲线颜色
    pen.setColor(LineColorThree);
    ui->customPlot_3->graph(0)->setPen(pen);

    //设置坐标轴
    ui->customPlot_4->xAxis->setLabel("时间(单位:ms)");
    ui->customPlot_4->yAxis->setLabel("幅值(单位:db)");
    ui->customPlot_4->xAxis->setLabelColor(TextColor);
    ui->customPlot_4->yAxis->setLabelColor(TextColor);
    ui->customPlot_4->xAxis->setTickLabelColor(TextColor);
    ui->customPlot_4->yAxis->setTickLabelColor(TextColor);

    //加该曲线名称
    ui->customPlot_4->legend->setIconSize(0,0);
    ui->customPlot_4->legend->setTextColor(TextColor);
    ui->customPlot_4->legend->setVisible(false);
    ui->customPlot_4->axisRect()->setupFullAxesBox();
    ui->customPlot_4->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignRight);
    ui->customPlot_4->legend->setBrush(QColor(255,255,255,0));

    //根据数据进行画图
    ui->customPlot_4->addGraph();                     //向绘图区添加一条曲线


    //设置坐标轴显示范围
    ui->customPlot_4->xAxis->setRange(0,20.16);
    ui->customPlot_4->yAxis->setRange(0,255);


    //设置曲线颜色
    pen.setColor(LineColorFour);
    ui->customPlot_4->graph(0)->setPen(pen);

    //设置曲线样式
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
    ui->customPlot_2->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
    ui->customPlot_3->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
    ui->customPlot_4->graph(0)->setLineStyle(QCPGraph::LineStyle::lsStepLeft);
}

/*************************显示悬浮框*************************/
void customPlotTab::showLegnd()
{
    ui->customPlot->graph(0)->setName(tr("X:%1").arg(dataAX));//曲线名称
    ui->customPlot->graph(0)->setName(tr("X:%1").arg(dataAY));//曲线名称
}

/*************************设置曲线**************************/
void customPlotTab::setUpPlot()
{

    //画波形图
    ui->customPlot->graph(0)->setData(this->dataPlot[0].dataX,this->dataPlot[0].dataY);    //设置曲线数据
    ui->customPlot_2->graph(0)->setData(this->dataPlot[1].dataX,this->dataPlot[1].dataY);  //设置曲线数据
    ui->customPlot_3->graph(0)->setData(this->dataPlot[2].dataX,this->dataPlot[2].dataY);  //设置曲线数据
    ui->customPlot_4->graph(0)->setData(this->dataPlot[3].dataX,this->dataPlot[3].dataY);  //设置曲线数据
    //刷新界面
    ui->customPlot->replot();
    ui->customPlot_2->replot();
    ui->customPlot_3->replot();
    ui->customPlot_4->replot();

    //重置vector大小
    this->dataPlot[0].dataX.resize(63);
    this->dataPlot[0].dataY.resize(63);
    this->dataPlot[1].dataX.resize(63);
    this->dataPlot[1].dataY.resize(63);
    this->dataPlot[2].dataX.resize(63);
    this->dataPlot[2].dataY.resize(63);
    this->dataPlot[3].dataX.resize(63);
    this->dataPlot[3].dataY.resize(63);
}

/**********************可放大缩小***************************/
void customPlotTab::on_checkBoxMoveChange_clicked()
{
    if(ui->checkBoxMoveChange->isChecked())
    {
        ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot_2->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot_3->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
        ui->customPlot_4->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    }
    else
    {
        ui->customPlot->setInteractions(QCP::iSelectOther);
        ui->customPlot_2->setInteractions(QCP::iSelectOther);
        ui->customPlot_3->setInteractions(QCP::iSelectOther);
        ui->customPlot_4->setInteractions(QCP::iSelectOther);
    }

    //刷新
    ui->customPlot->replot();
    ui->customPlot_2->replot();
    ui->customPlot_3->replot();
    ui->customPlot_4->replot();
}

/**********************加悬浮小窗口*************************/
void customPlotTab::on_checkBoxPicChange_clicked()
{
    if(ui->checkBoxPicChange->isChecked())
    {
        ui->customPlot->legend->setVisible(true);
        ui->customPlot_2->legend->setVisible(true);
        ui->customPlot_3->legend->setVisible(true);
        ui->customPlot_4->legend->setVisible(true);
    }
    else
    {
        ui->customPlot->legend->setVisible(false);
        ui->customPlot_2->legend->setVisible(false);
        ui->customPlot_3->legend->setVisible(false);
        ui->customPlot_4->legend->setVisible(false);
    }
    ui->customPlot->replot();
    ui->customPlot_2->replot();
    ui->customPlot_3->replot();
    ui->customPlot_4->replot();
}

/**********************加背景图例***********************/
void customPlotTab::on_checkBoxBackGroundCge_clicked()
{

    if (ui->checkBoxBackGroundCge->isChecked())
    {
        ui->customPlot->graph(0)->setBrush(QBrush(QColor(41,138,220,100)));
        ui->customPlot_2->graph(0)->setBrush(QBrush(QColor(246,98,0,100)));
        ui->customPlot_3->graph(0)->setBrush(QBrush(QColor(255,10,10,100)));
        ui->customPlot_4->graph(0)->setBrush(QBrush(QColor(144,238,144,100)));
    }
    else
    {
        ui->customPlot->graph(0)->setBrush(QBrush(PlotNoColor));
        ui->customPlot_2->graph(0)->setBrush(QBrush(PlotNoColor));
        ui->customPlot_3->graph(0)->setBrush(QBrush(PlotNoColor));
        ui->customPlot_4->graph(0)->setBrush(QBrush(PlotNoColor));
    }
    ui->customPlot->replot();
    ui->customPlot_2->replot();
    ui->customPlot_3->replot();
    ui->customPlot_4->replot();
}


/*************************清空信息************************/
void customPlotTab::on_pushButtonClear_clicked()
{
    ui->customPlot->graph(0)->clearData();  //清空数据显示
    ui->customPlot_2->graph(0)->clearData();//清空数据显示
    ui->customPlot_3->graph(0)->clearData();//清空数据显示
    ui->customPlot_4->graph(0)->clearData();//清空数据显示
    ui->customPlot->replot();
    ui->customPlot_2->replot();
    ui->customPlot_3->replot();
    ui->customPlot_4->replot();
}

/*************************读取数据************************/
void customPlotTab::on_pushButtonReadMessage_clicked()
{
    on_pushButtonClear_clicked();  //清空信息
    emit readInfo();               //发送信号
}

/*************************清空信息************************/
void customPlotTab::on_pushButtonReadInfo_clicked()
{
    emit readInfoMessage();
}

/*************************线程构造函数************************/
CustomPlotThread::CustomPlotThread(customPlotTab *plot)
{
    this->plot=plot;
}

/*************************线程运行函数************************/
void CustomPlotThread::run()
{
    this->plot->setUpPlot();
}
