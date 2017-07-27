#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QProcess>
#include <QMainWindow>
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QProgressBar>
#include <QLabel>
#include <QHBoxLayout>
#include <QThread>
#include "DetectAlgorithm.h"
#include "globaldef.h"
#include "systemtray/systemtray.h"
#include "setuplanguage/setuplangue.h"
#include "include/opencv/cv.h"
#include "include/opencv/cv.hpp"

namespace Ui {
class MainWindow;
}

/***************************************************************
   功能:主类窗口

   创建人:殷宇辰

   创建时间:2017-6-20
**************************************************************/

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    void initValue();       //初始化数据
    void initSourceImage(); //初始化源图
    void initTargetImage(); //初始化目标图
    void initStatusBar();   //初始化状态栏

private slots:
    void receiveCmykImage(QImage firstImage, QImage secondImage, QImage thirdImage); //接收线程图片
    void receiveData(int flage, QString data, QString transformData);                //接收线程数据
    void switchLanguage(int language);           //切换语言
    void switchImageSlot();                      //图片切换
    void setUpLanguageSlot();                    //设置语言
    void on_actionOpenImage_triggered();         //打开图像
    void on_actionOpenResult_triggered();        //打开检测结果或目标图
    void on_actionConfirmCompare_triggered();    //确认比较
    void on_actionZoomIn_triggered();            //放大图片
    void on_actionZoomOut_triggered();           //缩小图片
    void on_actionSaveResult_triggered();        //保存检查结果
    void on_actionVersion_triggered();           //版本信息
    void on_actionRotate270_triggered();         //旋转270度
    void on_actionRotate90_triggered();          //旋转90度
    void on_actionBlue_triggered();              //主题风格蓝
    void on_actionLight_triggered();             //主题风格亮
    void on_actionGray_triggered();              //主题风格暗
    void on_actionOpenNextResult_triggered();    //打开下次检查结果
    void on_actionOpenLastResult_triggered();    //打开上次检查结果
    void on_actionMove_triggered();              //移动图片
    void on_actionTool_triggered();              //隐藏工具栏
    void on_actionCyan_triggered();              //青色
    void on_actionMagenta_triggered();           //品红色
    void on_actionYellow_triggered();            //黄色
    void on_actionBlack_triggered();             //黑色
    void on_actionChoseWidget_triggered();       //拆分窗口
    void on_actionBlink_triggered();             //闪烁目标图像
    void on_actionOutPutImage_triggered();       //输出结果图片
    void on_actionShowErrorRect_triggered();     //显示错误边框
    void on_actionExit_triggered();              //退出应用程序
    void on_actionSetError_triggered();          //矩形标记
    void on_actionSetImportantError_triggered(); //多边形检测
    void on_actionSureInitAll_triggered();       //全部确认初始化
    void on_actionRedColor_triggered();          //红色画笔
    void on_actionChengColor_triggered();        //橙色画笔
    void on_actionYellowColor_triggered();       //黄色画笔
    void on_actionGreenColor_triggered();        //绿色画笔
    void on_actionCyanColor_triggered();         //青色画笔
    void on_actionBlueColor_triggered();         //蓝色画笔
    void on_actionPurpleColor_triggered();       //紫色画笔

private:
    Ui::MainWindow *ui;

    QTranslator translater;           //国际化
    FileName fileName;                //图片路径
    DataCmyk dataCmyk;                //CMYK代表值
    QString resultTextFileName;       //结果文件路径名
    QString firstFileName;            //源文件名
    QString secondFileName;           //结果文件名
    bool sourceZoomInFlage;           //源图放大标志位
    bool sourceZoomOutFlage;          //源图缩小标志位
    bool targetZoomInFlage;           //源图放大标志位
    bool targetZoomOutFlage;          //源图缩小标志位
    bool confirmCompareFlage;         //确认检测标志位
    bool sourcePressFlage;            //源图片点击标志位
    bool targetPressFlage;            //目标图片点击标志位
    bool mousePress;                  //是否被点击
    bool cmykFlage;                   //点击了CMYK的标志位
    bool rectReleaseFlage;            //画矩形的释放标志
    bool drawingRectFlag;             //画矩形图标志位
    bool drawingAnomalyFlage;         //画多边形标志位
    bool drawEndFlage;                //画多边形结束标志
    bool anomalyFlage;                //多边形检测结束标志
    QPoint sourceMovePoint;           //源图鼠标移动
    QPoint sourceEveryTimeMovePoint;  //源图每次鼠标移动的点
    QPoint sourceLastMovePoint;       //源图上次鼠标移动的点
    QPoint targetMovePoint;           //目标图鼠标移动
    QPoint targetEveryTimeMovePoint;  //目标图每次鼠标移动的点
    QPoint targetLastMovePoint;       //目标图上次鼠标移动的点
    QPoint startRectPoint;            //画矩形框开始坐标
    QPoint endRectPoint;              //画矩形框结束坐标
    QPoint oneToMorePoint;            //一对多开始点
    float sourceZoomFactorCount;      //源图缩放系数
    float targetZoomFactorCount;      //目标图缩放系数
    int resultPathIndex;              //结果路径指针
    int rotateTargel;                 //旋转角度
    int lastSourceCenterPointX;       //上次绘图点
    int lastSourceCenterPointY;       //上次绘图点
    int realImagePointX;              //矩形区域检测
    int realImagePointY;              //矩形区域检测
    int switchImageType;              //图片切换类型
    QList<QPoint>anomalyPoint;        //多边形点坐标
    QSet<QString> resultPathSet;      //结果路径

    QImage sourceSourceImage;         //源图不可变
    QImage targetTargetImage;         //目标图图不可变
    QImage sourceImage;               //源图
    QImage targetImage;               //目标图
    QImage resultImage;               //结果图
    QImage sourceImageCopy;           //源图副本
    QImage targetImageCopy;           //目标图副本
    QImage resultImageCopy;           //结果图副本
    QImage sourceImageCmyk;           //源图CMYK
    QImage targetImageCmyk;           //目标图CMYK
    QImage resultImageCmyk;           //结果图CMYK

    QTimer *timer;                    //图片切换定时器
    QPen myPen;                       //矩形绘图，多边形绘图画笔
    QPen comparePen;                  //用于画检测到的不同点

    cv::Mat srcImage;                 //opencv源图
    cv::Mat compareImage;             //opencv比较图

    QProgressBar *gressBar;           //进度条
    QLabel *gressLabel;               //进度条代表的含义
    QHBoxLayout *hBoxLayout;          //水平布局
    SystemTray *syetemTray;           //系统托盘
    SetUpLangue *setUpLanguage;       //设置语言
    QVector<QVector<QVector<DAPoint>>> comparePoints; //存储检测到的点数据
    QList<DAPoint>pointList;

    bool eventFilter(QObject *watched, QEvent *event);                                        //事件过滤
    void paintSourceImage();                                                                  //画源图
    void paintTargetImage();                                                                  //画目标图
    void paintResultImage();                                                                  //画结果图
    void changeEvent(QEvent*event);                                                           //窗口大小改变事件
    void closeEvent(QCloseEvent* event);                                                      //关闭事件
    void mousePressEvent(QMouseEvent*event);                                                  //鼠标点击
    void mouseReleaseEvent(QMouseEvent *event);                                               //鼠标释放
    void mouseMoveEvent(QMouseEvent *event);                                                  //鼠标移动
    void stringToPoint(QString& data);                                                        //比对结果点
    void matchStringToPoint(QString& data);                                                   //比对结果点
    void setUpCheck(int type);                                                                //设置选中项
    std::string pointToString(QList<QPoint> point);                                           //点转字符串
    const QByteArray imageToString(QImage &image);                                            //图像转换为字符
    void stringToImage(QString textFileName);                                                 //字符转换为图像
    QImage pdfToImage(QString textFileName);                                                  //pdf转图片
    void imageToCmykImage();                                                                  //图片转cmyk图片
    bool isShowCmykImage();                                                                   //是否显示CMYK图
    void outPutResultImage(QString tempFileName);                                             //输出结果图片
    const QRect getImageRect(QImage image);                                                   //提取感兴趣区域矩形域
    const QImage rectToImage();                                                               //画的矩形区域转为图片
    void setPixelToWhite(QImage *image);                                                      //设置透明像素为白色
    void setActionPenColor(int type);                                                         //设置选中画笔颜色选中情况
    void setActionImageOper(int type);                                                        //设置工具栏选中情况
    cv::Mat QImageToMat(const QImage & image);                                                //QImage转换Mat
};

#endif // MAINWINDOW_H
