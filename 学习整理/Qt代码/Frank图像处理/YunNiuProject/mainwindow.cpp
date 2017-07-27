#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MessageBox/messagedialog.h"
#include "version/versiondialog.h"
#include "qreadwrite/qreadwriteini.h"
#include "mythread/comparethread.h"
#include "mythread/cmykthread.h"
#include "include/mupdf-qt.h"
#include <QFileDialog>
#include <QFile>
#include <QPicture>
#include <QDebug>
#include <QDragEnterEvent>
#include <QPaintEvent>
#include <QUrl>
#include <QDropEvent>
#include <QMimeData>
#include <QTime>
#include <QStringList>
#include <QMessageBox>
#include <QTimer>
#include <QImage>
#include <QBuffer>
#include <QStringList>
#include <QTextCodec>
#pragma comment(lib,"DetectAlgorithm.lib")

/************************    构造函数              **************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->labelSourceImage->installEventFilter(this);                   //设置事件过滤监听事件
    ui->labelResultImage->installEventFilter(this);                   //设置事件过滤监听事件
    ui->labelTargetImage->installEventFilter(this);                   //设置事件过滤监听事件
    ui->centralWidget->installEventFilter(this);                      //设置事件过滤监听事件
    ui->centralWidget->setAcceptDrops(true);                          //可以进行拖放事件

    timer = new QTimer(this);                                         //新建定时器
    timer->setInterval(TIMEINTERNAL);                                 //0.5秒调用一次
    connect(timer, SIGNAL(timeout()), this, SLOT(switchImageSlot())); //连接定时器信号和槽函数

    this->setMouseTracking(true);                                     //触发mouseMoveEvent
    if (INICONFIG->getThemeStyle().toInt() == THEMEBLUE)              //初始化主题
    {
        ui->centralWidget->setStyleSheet(STYLESHEETBLUE);
    }
    else if (INICONFIG->getThemeStyle().toInt() == THEMELIGHT)
    {
        ui->centralWidget->setStyleSheet(STYLESHEETLIGHT);
    }
    else if (INICONFIG->getThemeStyle().toInt() == THEMEGRAY)
    {
        ui->centralWidget->setStyleSheet(STYLESHEETGRAY);
    }

    this->initValue();     //初始化
    this->initStatusBar(); //初始化状态栏
    this->setWindowIcon(QIcon(ICONPATH));

    syetemTray = new SystemTray(this);
    setUpLanguage = new SetUpLangue(this);

    //托盘按钮事件，连接信号和槽
    connect(syetemTray->showWidget, SIGNAL(triggered(bool)), this, SLOT(showNormal()));
    connect(syetemTray->minWidget, SIGNAL(triggered(bool)), this, SLOT(showMinimized()));
    connect(syetemTray->aboutSoftWare, SIGNAL(triggered(bool)), this, SLOT(on_actionVersion_triggered()));
    connect(syetemTray->setUpLanguage, SIGNAL(triggered(bool)), this, SLOT(setUpLanguageSlot()));
    connect(setUpLanguage, SIGNAL(sendLanguage(int)), this, SLOT(switchLanguage(int)));
    connect(setUpLanguage, SIGNAL(sendLanguage(int)), syetemTray, SLOT(switchLanguage(int)));

}

/************************    析构函数              **************************************/
MainWindow::~MainWindow()
{
    delete timer;
    delete setUpLanguage;
    delete gressBar;
    delete gressLabel;
    delete hBoxLayout;
    delete syetemTray;
    delete ui;
}

/************************    初始化                **************************************/
void MainWindow::initValue()
{
    realImagePointX = 0;                          //矩形区域检测实际开始坐标X
    realImagePointY = 0;                          //矩形区域检测实际开始坐标Y
    lastSourceCenterPointX = 0;                   //上次画图点
    lastSourceCenterPointY = 0;                   //上次画图点
    rotateTargel = 0;                             //旋转角度
    sourceMovePoint = INVALIDPOINT;               //开始移动点
    sourceEveryTimeMovePoint = INVALIDPOINT;      //源图每次鼠标移动的点
    startRectPoint = INVALIDPOINT;                //画矩形框开始点
    endRectPoint = INVALIDPOINT;                  //画矩形框结束点
    sourceZoomFactorCount = INITZOOMFACTOR;       //源图缩放系数
    targetZoomFactorCount = NORMALINITZOOMFACTOR; //目标图缩放系数
    sourceLastMovePoint = INVALIDPOINT;           //源图上次鼠标移动的点
    targetLastMovePoint = INVALIDPOINT;           //目标图上次鼠标移动的点
    targetMovePoint = INVALIDPOINT;               //目标图每次鼠标移动的点
    resultPathIndex = 0;                          //当前结果下标
    sourcePressFlage = false;                     //源图片点击标志位
    targetPressFlage = false;                     //目标图片点击标志位
    sourceZoomInFlage = false;                    //源图放大标志位
    sourceZoomOutFlage = false;                   //源图缩小标志位
    targetZoomInFlage = false;                    //目标图放大标志位
    targetZoomOutFlage = false;                   //目标图缩小标志位
    confirmCompareFlage = false;                  //确认检测标志位
    cmykFlage = false;                            //CMYK标志位
    rectReleaseFlage = false;                     //画矩形释放标志
    drawingRectFlag = false;                      //画矩形标志位
    drawingAnomalyFlage = false;                  //画多边形标志位
    anomalyFlage = false;                         //多边形检测标志位
    drawEndFlage = false;                         //画多边形结束标志
    switchImageType = RESULTIMAGE;                //初始化为目标图
    resultImage = QImage();                       //结果图初始化
    resultImageCopy = QImage();                   //结果图副本初始化
    myPen = QPen(REDCOLOR, PENWIDTH);             //初始化画笔
    comparePen = QPen(REDCOLOR, PENWIDTH);        //初始化画笔
    anomalyPoint.clear();                         //多边形点清空
    oneToMorePoint = INVALIDPOINT;                //一对多开始点
}

/************************    初始化源图             **************************************/
void MainWindow::initSourceImage()
{
    if (sourceImage.width() > ui->labelSourceImage->width() || sourceImage.height() > ui->labelSourceImage->height())
    {
        sourceZoomFactorCount = INITZOOMFACTOR;                    //源图缩放系数
    }
    else
    {
        sourceZoomFactorCount = NORMALINITZOOMFACTOR;              //源图缩放系数
    }

    QMatrix matrix;
    matrix.scale(sourceZoomFactorCount, sourceZoomFactorCount);    //每次缩放
    sourceImageCopy = sourceImage.transformed(matrix);             //初始化为20%
}

/************************    初始化目标图           **************************************/
void MainWindow::initTargetImage()
{
    if (targetImage.width() > ui->labelTargetImage->width() || targetImage.height() > ui->labelTargetImage->height())
    {
        QMatrix matrix;
        targetZoomFactorCount = NORMALINITZOOMFACTOR;                  //目标图缩放系数
        matrix.scale(targetZoomFactorCount, targetZoomFactorCount);    //每次缩放
        targetImageCopy = targetImage.transformed(matrix);
    }
    else
    {
        targetZoomFactorCount = 1;         //目标图缩放系数
        targetImageCopy = targetImage;
    }
}

/************************    初始化状态栏           **************************************/
void MainWindow::initStatusBar()
{
    QWidget * widget = new QWidget();
    hBoxLayout = new QHBoxLayout();

    gressBar = new QProgressBar();
    gressLabel = new QLabel();
    gressLabel->setText(tr("进度:"));
    hBoxLayout->addWidget(gressLabel);
    hBoxLayout->addWidget(gressBar);
    widget->setLayout(hBoxLayout);
    ui->statusBar->addWidget(widget);
    ui->statusBar->hide();
}

/************************    切换语言              **************************************/
void MainWindow::switchLanguage(int language)
{
    if (language == ENGLISH)
    {
        if (translater.load(ENGLISHQMPATH))
        {
            qApp->installTranslator(&translater);
        }
        ui->retranslateUi(this);
    }
    else
    {
        if (translater.load(CHINESEQMPATH))
        {
            qApp->installTranslator(&translater);
        }
        ui->retranslateUi(this);
    }
}

/************************    打开源图              **************************************/
void MainWindow::on_actionOpenImage_triggered()
{
    QFileInfo fileInfo  = QFileDialog::getOpenFileName(this, tr("选择文件"), tr(""), tr("图片 (*.png *.bmp *.jpg *.tif *.gif *.pdf)"));
    QString tempFileName = fileInfo.filePath();

    if (!tempFileName.isEmpty())
    {
        firstFileName = fileInfo.fileName();

        {
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            std::string name = code->fromUnicode(tempFileName).data();

            srcImage = cv::imread(name,  cv::IMREAD_COLOR);
        }

        this->initValue();

        fileName.sourceImageFileName = tempFileName;   //源图片赋值

        if(tempFileName.contains(".pdf"))
        {
            sourceImage = pdfToImage(tempFileName);    //加载源图片
            srcImage = QImageToMat(sourceImage);
        }
        else
        {
            sourceImage.load(tempFileName);            //加载源图片
        }

        fileName.targetImageFileName.clear();          //目标图片目录清空
        targetImage = QImage();
        resultImage = QImage();
        comparePoints.clear();
        anomalyPoint.clear();
        sourceSourceImage = sourceImage;

        initSourceImage();

        if (timer->isActive())  //如果定时器在开着
        {
            timer->stop();     //关闭定时器
        }

        on_actionMove_triggered();

        cmykFlage = isShowCmykImage();
    }
}

/************************    打开检测结果或目标图    ***************************************/
void MainWindow::on_actionOpenResult_triggered()
{
    QFileInfo fileInfo  = QFileDialog::getOpenFileName(this, tr("选择文件"), tr(""), tr("图片 (*.png *.bmp *.jpg *.tif *.gif *.pdf *.gtr)"));
    QString tempFileName = fileInfo.filePath();

    if(!tempFileName.contains(".gtr"))
    {
        secondFileName = fileInfo.fileName();

        {
            QTextCodec *code = QTextCodec::codecForName("gb18030");
            std::string name = code->fromUnicode(tempFileName).data();

            compareImage = cv::imread(name,  cv::IMREAD_COLOR);
        }

        fileName.targetImageFileName = tempFileName;

        if(tempFileName.contains(".pdf"))
        {
            targetImage = pdfToImage(tempFileName);    //加载目标图片
            compareImage = QImageToMat(targetImage);
        }
        else
        {
            targetImage.load(tempFileName);            //加载目标图片
        }

        targetTargetImage = targetImage;

        initTargetImage();

        resultImage = QImage();
        resultImageCopy = QImage();

        confirmCompareFlage = false;
        on_actionMove_triggered();

        cmykFlage = isShowCmykImage();
    }
    else
    {
        stringToImage(tempFileName);  //字符串转换为图像
    }
}

/************************    过滤事件               **************************************/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    //结果文件拖放事件过滤
    if (watched == ui->centralWidget)
    {
        if (event->type() == QEvent::DragEnter)
        {
            QDragEnterEvent * dragEnterEvent = dynamic_cast<QDragEnterEvent *>(event);

            dragEnterEvent->acceptProposedAction();

            return true;
        }
        else if (event->type() == QEvent::Drop)
        {
            QDropEvent *dropEvent = dynamic_cast<QDropEvent*>(event);

            QList<QUrl>urls = dropEvent->mimeData()->urls();

            if (urls.isEmpty())  return true;

            stringToImage(urls.first().toLocalFile());  //字符串转换为图像

            return true;
        }
    }

    //源图画图事件过滤
    if (watched == ui->labelSourceImage && event->type() == QEvent::Paint)
    {
        paintSourceImage();
    }

    //目标图画图事件过滤
    if (watched == ui->labelTargetImage && event->type() == QEvent::Paint)
    {
        paintTargetImage();
    }

    //结果图画图事件过滤
    if (watched == ui->labelResultImage && event->type() == QEvent::Paint)
    {
        paintResultImage();
    }

    if (watched == ui->labelSourceImage)
    {
        //源图鼠标点击事件过滤
        if (event->type() == QEvent::MouseButtonPress)
        {
            if (ui->actionZoomIn->isChecked())
            {
                sourceZoomInFlage = sourceZoomFactorCount > ZOOMINMAX ? false : true;
            }
            else if (ui->actionZoomOut->isChecked())
            {
                sourceZoomOutFlage = sourceZoomFactorCount < ZOOMOUTMIN ? false : true;
            }

            if (sourceZoomInFlage || sourceZoomOutFlage)
            {
                if (sourceZoomInFlage)
                {
                    sourceZoomFactorCount += ZOOMINFACTOR;                     //每次放大10%
                }
                else
                {
                    sourceZoomFactorCount -= ZOOMINFACTOR;                     //每次缩小10%
                }

                //放大缩小
                QMatrix matrix;
                matrix.rotate(rotateTargel);
                matrix.scale(sourceZoomFactorCount, sourceZoomFactorCount);    //每次缩放
                sourceImageCopy = sourceImage.transformed(matrix);

                sourceZoomInFlage = false;
                sourceZoomOutFlage = false;

                startRectPoint = INVALIDPOINT;
                endRectPoint = INVALIDPOINT;
            }
            sourcePressFlage = true;
        }

        //滚轮滚动事件
        if (event->type() == QEvent::Wheel)
        {
            if (ui->actionRool->isChecked())
            {
                QWheelEvent *wheelEvent = dynamic_cast<QWheelEvent*>(event);

                if (wheelEvent->delta() > 0)
                {
                    sourceMovePoint += QPoint(0, sourceImageCopy.height() / WHEELMOVETIME);;
                }
                else
                {
                    sourceMovePoint -= QPoint(0, sourceImageCopy.height() / WHEELMOVETIME);;
                }
            }
        }

        //进入离开事件
        if (event->type() == QEvent::Enter)
        {
            this->setUpCheck(SOURCEIMAGE);
        }
        else if (event->type() == QEvent::Leave)
        {
            this->setCursor(Qt::ArrowCursor);
        }
    }

    if (watched == ui->labelTargetImage || watched == ui->labelResultImage)
    {
        //目标图鼠标点击事件过滤
        if (event->type() == QEvent::MouseButtonPress)
        {
            if (ui->actionZoomIn->isChecked())
            {
                targetZoomInFlage = targetZoomFactorCount > ZOOMINMAX ? false : true;
            }
            else if (ui->actionZoomOut->isChecked())
            {
                targetZoomOutFlage = targetZoomFactorCount < ZOOMOUTMIN ? false : true;
            }

            QMatrix matrix;
            if (targetZoomInFlage || targetZoomOutFlage)
            {
                if (targetZoomInFlage)
                {
                    targetZoomFactorCount += ZOOMINFACTOR;                     //每次放大10%
                }
                else
                {
                    targetZoomFactorCount -= ZOOMINFACTOR;                     //每次缩小10%
                }

                matrix.rotate(rotateTargel);
                matrix.scale(targetZoomFactorCount, targetZoomFactorCount);    //每次放大10%
                targetImageCopy = targetImage.transformed(matrix);

                if (!resultImageCopy.isNull())
                {
                    resultImageCopy = resultImage.transformed(matrix);
                }

                if(cmykFlage)
                {
                    targetImageCmyk = targetImageCmyk.transformed(matrix);
                    if (!resultImageCmyk.isNull())
                    {
                        resultImageCmyk = resultImageCmyk.transformed(matrix);
                    }
                }

                targetZoomInFlage = false;
                targetZoomOutFlage = false;
            }
            targetPressFlage = true;
        }

        //滚轮滚动事件
        if (event->type() == QEvent::Wheel)
        {
            if (ui->actionRool->isChecked())
            {
                QWheelEvent *wheelEvent = dynamic_cast<QWheelEvent*>(event);

                if (wheelEvent->delta() > 0)
                {
                    targetMovePoint += QPoint(0, targetImageCopy.height() / WHEELMOVETIME);
                }
                else
                {
                    targetMovePoint -= QPoint(0, targetImageCopy.height() / WHEELMOVETIME);
                }
            }
        }

        //进入离开事件
        if (event->type() == QEvent::Enter)
        {
            this->setUpCheck(RESULTIMAGE);
        }
        else if (event->type() == QEvent::Leave)
        {
            this->setCursor(Qt::ArrowCursor);
        }
    }

    return QWidget::eventFilter(watched, event);
}

/************************    画源图                 **************************************/
void MainWindow::paintSourceImage()
{
    if (fileName.sourceImageFileName.isEmpty() || sourceZoomFactorCount == 0) return;


    QPainter painter;
    painter.begin(ui->labelSourceImage);

    int centerPointX = (ui->labelSourceImage->width() - sourceImageCopy.width()) / DRAWTIME + sourceMovePoint.x();   //画图起始X坐标
    int centerPointY = (ui->labelSourceImage->height() - sourceImageCopy.height()) / DRAWTIME + sourceMovePoint.y();  //画图起始Y坐标

    QRect imageRect(centerPointX, centerPointY, sourceImageCopy.width(), sourceImageCopy.height());  //画图矩形区域
    if (cmykFlage)
    {
        painter.drawImage(imageRect, sourceImageCmyk);
    }
    /*************************************一对多检测**********************************************/
    else if (comparePoints.count() > 1 && !resultImage.isNull())
    {
        painter.drawImage(imageRect, sourceImageCopy);                             //画一对多整合的图
    }
    else
    {
        painter.drawImage(imageRect, sourceImageCopy);
    }
    ui->splitterFirst->setStyleSheet(SPLITTERSTYLESHEET);

    painter.end();


    /*************************************矩形检测**********************************************/
    if (ui->actionSetError->isChecked())
    {
        QImage tempImage = sourceImageCopy;                              //创建临时图片
        if (cmykFlage) tempImage = sourceImageCmyk;

        painter.begin(&tempImage);                                       //在临时图片上绘图

        painter.setPen(myPen);
        int width = endRectPoint.x() - startRectPoint.x();               //画的矩形宽度
        int height = endRectPoint.y() - startRectPoint.y();              //画的矩形高度
        int imagePointX = startRectPoint.x() - lastSourceCenterPointX;   //画的矩形起始点
        int imagePointY = startRectPoint.y() - lastSourceCenterPointY;   //画的矩形起始点
        QRect rect(imagePointX, imagePointY, width, height);             //画的矩形

        if (drawingRectFlag)
        {
            lastSourceCenterPointX = centerPointX;  //为了防止在拉伸窗口时，矩形框的移动
            lastSourceCenterPointY = centerPointY;  //为了防止在拉伸窗口时，矩形框的移动
        }

        painter.drawRect(rect);

        painter.end();

        painter.begin(ui->labelSourceImage);

        painter.drawImage(imageRect, tempImage);

        painter.end();

        if (rectReleaseFlage)
        {
            realImagePointX = imagePointX / sourceZoomFactorCount;
            realImagePointY = imagePointY / sourceZoomFactorCount;

            rectReleaseFlage = false;
            if (imagePointX < 0 || imagePointY < 0
                    || (imagePointX + width) > tempImage.width()
                    || (imagePointY + height) > tempImage.height())
            {
                MESSAGEBOX->setInfo(tr("系统提示"), tr("请选中图片区域!"), QPixmap(FAILIMAGEPATH), true, this);

                startRectPoint = INVALIDPOINT;
                endRectPoint = INVALIDPOINT;
                return;
            }
        }
    }
    /*************************************多边形检测**********************************************/
    else if (ui->actionSetImportantError->isChecked() && !anomalyPoint.isEmpty())
    {
        QImage tempImage = sourceImageCopy;                              //创建临时图片
        if (cmykFlage) tempImage = sourceImageCmyk;

        painter.begin(&tempImage);                                       //在临时图片上绘图

        painter.setPen(myPen);
        QPoint point = QPoint(lastSourceCenterPointX, lastSourceCenterPointY);
        int i;
        for (i = 0; i < anomalyPoint.count(); i++)
        {
            painter.drawEllipse(anomalyPoint.at(i) - point, MAXPOINTVALUE, MAXPOINTVALUE);
        }

        painter.setPen(myPen);
        for (i = 0; i < anomalyPoint.count() - 1; i++)
        {
            painter.drawLine(anomalyPoint.at(i) - point, anomalyPoint.at(i + 1) - point);
        }

        //如果可以开始检测了，就不画该折线
        if (!drawEndFlage)
        {
            painter.drawLine(anomalyPoint.last() - point, QCursor::pos() - QPoint(centerPointX, centerPointY) - pos() - CURSORMOVEPOINT);
        }
        else
        {
            painter.drawLine(anomalyPoint.first() - point, anomalyPoint.last() - point);
        }

        //正在绘图时
        if (drawingAnomalyFlage)
        {
            lastSourceCenterPointX = centerPointX;  //为了防止在拉伸窗口时，矩形框的移动
            lastSourceCenterPointY = centerPointY;  //为了防止在拉伸窗口时，矩形框的移动
        }

        painter.end();

        painter.begin(ui->labelSourceImage);

        painter.drawImage(imageRect, tempImage);

        painter.end();
    }
}

/************************    画目标图               **************************************/
void MainWindow::paintTargetImage()
{
    if (fileName.targetImageFileName.isEmpty()) return;
    if (targetImage.isNull())  return;

    QPainter painter(ui->labelTargetImage);

    int centerPointX = (ui->labelTargetImage->width() - targetImageCopy.width()) / DRAWTIME + targetMovePoint.x();   //画图起始X坐标
    int centerPointY = (ui->labelTargetImage->height() - targetImageCopy.height()) / DRAWTIME + targetMovePoint.y();  //画图起始Y坐标

    QRect imageRect(centerPointX, centerPointY, targetImageCopy.width(), targetImageCopy.height());  //画图矩形区域

    if (cmykFlage)
    {
        painter.drawImage(imageRect, targetImageCmyk);
    }
    else
    {
        if (resultImageCopy.isNull())
        {
            painter.drawImage(imageRect, targetImageCopy);
        }
        else
        {
            painter.drawImage(imageRect, resultImageCopy);
        }
    }

    ui->splitterSecond->setStyleSheet(SPLITTERSTYLESHEET);

    painter.end();
}

/************************    画结果图               ***************************************/
void MainWindow::paintResultImage()
{
    if (!confirmCompareFlage)
    {
        targetZoomInFlage = false;
        targetZoomOutFlage = false;
        return;
    }

    if (fileName.targetImageFileName.isEmpty()) return;
    if (targetImage.isNull())  return;

    QPainter painter;
    if (resultImage.isNull())
    {
        QSize size(targetImage.width(), targetImage.height());

        resultImage = QImage(size, QImage::Format_ARGB32);
        painter.begin(&resultImage);

        if (!ui->actionShowErrorRect->isChecked())
        {
            painter.setPen(QPen(NOCOLOR, PENWIDTH));
        }
        else
        {
            painter.setPen(comparePen);
        }

        for (int i = 0; i < targetImage.width(); i++)
        {
            for (int j = 0; j < targetImage.height(); j++)
            {
                if(i > resultImage.width() || j > resultImage.height()) continue;
                resultImage.setPixel(i, j, targetImage.pixel(i, j));
            }
        }

        if (!comparePoints.isEmpty())
        {
            for (int i = 0; i < comparePoints.count(); i++)
            {
                for (int j = 0; j < comparePoints.at(i).count(); j++)
                {
                    for (int k = 0; k < comparePoints.at(i).at(j).count(); k++)
                    {
                        if(comparePoints.count() > 1)
                        {
                            painter.drawPoint(comparePoints.at(i).at(j).at(k).x - oneToMorePoint.x(), comparePoints.at(i).at(j).at(k).y - oneToMorePoint.y()); //在图片上绘制比较的点
                        }
                        else
                        {
                            painter.drawPoint(comparePoints.at(i).at(j).at(k).x, comparePoints.at(i).at(j).at(k).y); //在图片上绘制比较的点
                        }
                    }
                }
            }
        }
        cmykFlage = isShowCmykImage();
        painter.end();
    }

    painter.begin(ui->labelResultImage);

    int centerPointX = (ui->labelResultImage->width() - targetImageCopy.width()) / DRAWTIME + targetMovePoint.x();    //画图起始X坐标
    int centerPointY = (ui->labelResultImage->height() - targetImageCopy.height()) / DRAWTIME + targetMovePoint.y();  //画图起始Y坐标

    QRect imageRect(centerPointX, centerPointY, targetImageCopy.width(), targetImageCopy.height());  //画图矩形区域

    if (switchImageType == RESULTIMAGE)
    {
        if (cmykFlage)
        {
            painter.drawImage(imageRect, resultImageCmyk);  //画CMYK图
        }
        else
        {
            QMatrix matrix;
            matrix.rotate(rotateTargel);
            matrix.scale(targetZoomFactorCount, targetZoomFactorCount);     //每次缩放
            resultImageCopy = resultImage.transformed(matrix);
            painter.drawImage(imageRect, resultImageCopy);  //画比较图
        }
    }
    else if (switchImageType == SOURCEIMAGE)
    {
        if (cmykFlage)
        {
            painter.drawImage(imageRect, sourceImageCmyk);  //画CMYK图
        }
        else
        {
            QMatrix matrix;
            matrix.rotate(rotateTargel);
            matrix.scale(targetZoomFactorCount, targetZoomFactorCount);     //每次缩放

            QImage image = sourceImage.transformed(matrix);
            imageRect.setRect(centerPointX, centerPointY, image.width(), image.height());

            painter.drawImage(imageRect, image);  //画目标图
        }
    }

    painter.end();
}

/************************    窗口大小改变事件         **************************************/
void MainWindow::changeEvent(QEvent *event)
{
    if(event->type() != QEvent::WindowStateChange) return;

    gressBar->setMinimumWidth(this->width() - gressLabel->width() * 2);
}

/************************    字符串转点              **************************************/
void MainWindow::stringToPoint(QString& data)
{
    /************************************************************************
     * 三层Vector中
     * 第一层为:一对多的几张图片
     * 第二层为：不同的地方，例如一个圆
     * 第三层为：这个不同的地方中不同的点
     * *********************************************************************/

    QStringList image = data.split("&");
    for (int i = 0; i < image.size(); i++)
    {
        QStringList imageSub = image[i].split("|");
        QVector<QVector<DAPoint>> subPts;
        for (int k = 0; k < imageSub.size(); k++)
        {
            QStringList ringLine = imageSub[k].split(";");
            QVector<DAPoint> subSubPts;
            for (int j = 0; j < ringLine.size(); j++)
            {
                QStringList pt = ringLine[j].split(",");
                DAPoint dap;
                if (pt.size() == 2)
                {
                    dap.x = pt[0].toFloat();
                    dap.y = pt[1].toFloat();
                }

                subSubPts.push_back(dap);
            }
            subPts.push_back(subSubPts);
        }
        comparePoints.push_back(subPts);
    }
}

/************************    设置选中项              **************************************/
void MainWindow::setUpCheck(int type)
{
    if (ui->actionZoomIn->isChecked())
    {
        QMatrix matrix;
        matrix.scale(ZOOMOUTCUTRSOR, ZOOMOUTCUTRSOR);//每次放大10%
        QPixmap pixmap(ZOOMINIMAGEPATH);
        pixmap = pixmap.transformed(matrix);
        this->setCursor(QCursor(pixmap, -1, -1));
    }
    else if (ui->actionZoomOut->isChecked())
    {
        QMatrix matrix;
        matrix.scale(ZOOMOUTCUTRSOR, ZOOMOUTCUTRSOR); //每次放大10%
        QPixmap pixmap(ZOOMOUTIMAGEPATH);
        pixmap = pixmap.transformed(matrix);
        this->setCursor(QCursor(pixmap, -1, -1));
    }
    else if (ui->actionMove->isChecked())
    {
        this->setCursor(Qt::OpenHandCursor);
    }
    else if ((ui->actionSetError->isChecked() || ui->actionSetImportantError->isChecked()) && type == SOURCEIMAGE)
    {
        this->setCursor(Qt::CrossCursor);
    }
}

/************************    点转化为字符串           **************************************/
std::string MainWindow::pointToString(QList<QPoint> point)
{
    QString str;
    for (int i = 0; i < point.count(); i++)
    {
        if (i == 0)
        {
            str += tr("%1,%2").arg(point.at(i).x()).arg(point.at(i).y());
        }
        else
        {
            str += tr(";%1,%2").arg(point.at(i).x()).arg(point.at(i).y());
        }
    }

    qDebug()<<"矩形四边位置"<<str;
    return std::string((const char*)str.toLocal8Bit());
}

/************************    关闭事件                ***************************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    INITEVENT(event);
    INICONFIG->writeThemeStyle();
}

/************************    鼠标点击                ***************************************/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->actionMove->isChecked())
    {
        if (event->button() == Qt::LeftButton)
        {
            mousePress = true;
        }
        if (sourcePressFlage)
        {
            sourceEveryTimeMovePoint = event->globalPos();
            sourceLastMovePoint = INVALIDPOINT;
        }

        if (targetPressFlage)
        {
            targetEveryTimeMovePoint = event->globalPos();
            targetLastMovePoint = INVALIDPOINT;
        }
    }

    if (ui->actionSetError->isChecked())
    {
        if (event->button() == Qt::LeftButton)
        {
            resultImage = QImage();           //结果图清空
            resultImageCopy = QImage();       //结果图副本清空
            comparePoints.clear();            //比对的坐标点进行清空
            confirmCompareFlage = false;      //确认检测标志位清掉

            startRectPoint = event->pos() - COMPENSATEPOINT;
            endRectPoint = startRectPoint;
            rectReleaseFlage = false;
            drawingRectFlag = true;
        }
    }

    if (ui->actionSetImportantError->isChecked())
    {
        if (event->button() == Qt::LeftButton)
        {
            if (anomalyPoint.isEmpty())
            {
                resultImage = QImage();           //结果图清空
                resultImageCopy = QImage();       //结果图副本清空
                comparePoints.clear();            //比对的坐标点进行清空
                confirmCompareFlage = false;      //确认检测标志位清掉
                drawingAnomalyFlage = true;       //开始画多边形
                drawEndFlage = false;
            }

            if (!anomalyPoint.isEmpty())
            {
                QPoint endPoint = anomalyPoint.first() - event->pos() + COMPENSATEPOINT;

                if (endPoint.x() > MINPOINTVALUE && endPoint.x() < MAXPOINTVALUE && endPoint.y() > MINPOINTVALUE && endPoint.y() < MAXPOINTVALUE)
                {
                    drawEndFlage = true;

                    drawingAnomalyFlage = false;
                }
            }

            if (!drawEndFlage)
            {
                QPoint pointData = event->pos() - COMPENSATEPOINT;

                if (anomalyPoint.isEmpty())
                {
                    lastSourceCenterPointX = (ui->labelSourceImage->width() - sourceImageCopy.width()) / DRAWTIME + sourceMovePoint.x();    //画图起始X坐标
                    lastSourceCenterPointY = (ui->labelSourceImage->height() - sourceImageCopy.height()) / DRAWTIME + sourceMovePoint.y();  //画图起始Y坐标
                }

                int  pointX = pointData.x() - lastSourceCenterPointX;
                int  pointY = pointData.y() - lastSourceCenterPointY;

                if (pointX >= 0 && pointX <= sourceImageCopy.width() && pointY >= 0 && pointY <= sourceImageCopy.height())
                {
                    anomalyPoint << pointData;
                }
            }
        }

        if (event->button() == Qt::RightButton) anomalyPoint.clear();
    }
}

/************************    鼠标释放                ***************************************/
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (ui->actionMove->isChecked())
    {
        mousePress = false;
        targetPressFlage = false;
        sourcePressFlage = false;
    }
    if (ui->actionSetError->isChecked())
    {
        if (event->button() == Qt::LeftButton)
        {
            endRectPoint = event->pos() - COMPENSATEPOINT;
            rectReleaseFlage = true;
            drawingRectFlag = false;
        }
    }
}

/************************    鼠标移动                ***************************************/
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (ui->actionMove->isChecked())
    {
        if (mousePress)
        {
            if (sourcePressFlage)
            {
                QPoint movePos = event->globalPos();

                sourceMovePoint += movePos - sourceEveryTimeMovePoint - sourceLastMovePoint;

                sourceLastMovePoint = movePos - sourceEveryTimeMovePoint;
            }

            if (targetPressFlage)
            {
                QPoint movePos = event->globalPos();

                targetMovePoint += movePos - targetEveryTimeMovePoint - targetLastMovePoint;

                targetLastMovePoint = movePos - targetEveryTimeMovePoint;
            }
        }
    }

    if (ui->actionSetError->isChecked())
    {
        if (event->buttons() & Qt::LeftButton)
        {
            endRectPoint = event->pos() - COMPENSATEPOINT;

            //当矩形拉不到图片的地方时，移动图片
            if(endRectPoint.x() > ui->labelSourceImage->width())
            {
                startRectPoint -= ADDXPOINT;
                sourceMovePoint -= ADDXPOINT;
            }
            else if(endRectPoint.x() < 0)
            {
                startRectPoint += ADDXPOINT;
                sourceMovePoint += ADDXPOINT;
            }

            //当矩形拉不到图片的地方时，移动图片
            if(endRectPoint.y() > ui->labelSourceImage->height())
            {
                startRectPoint -= ADDYPOINT;
                sourceMovePoint -= ADDYPOINT;
            }
            else if(endRectPoint.y() < 0)
            {
                startRectPoint += ADDYPOINT;
                sourceMovePoint += ADDYPOINT;
            }
        }
    }
}

/************************    确定检测                ***************************************/
void MainWindow::on_actionConfirmCompare_triggered()
{
    if (sourceImage.isNull() || targetImage.isNull() || !resultImage.isNull() || sourceZoomFactorCount == 0)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("当前状态不能进行检测！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }
    comparePoints.clear();
    gressBar->setMinimumWidth(this->width() - gressLabel->width() * 2);
    gressBar->setRange(0, RATE100);                                                //设置进度条范围
    ui->statusBar->show();
    gressBar->setValue(RATE20);

    int contourType = NOPOINTTYPE;                             //检测类型
    std::string pointStr = "17,85;1423,85;1423,1059;17,1059";  //坐标数据;

    if (ui->actionSetError->isChecked())                       //矩形检测
    {
        if (endRectPoint != INVALIDPOINT && startRectPoint != INVALIDPOINT)
        {
            float width = (endRectPoint.x() - startRectPoint.x()) / sourceZoomFactorCount;   //画的矩形宽度
            float height = (endRectPoint.y() - startRectPoint.y()) / sourceZoomFactorCount;  //画的矩形高度

            QList<QPoint>pointData;
            QPoint startPoint = QPoint(realImagePointX, realImagePointY);                    //矩形的左上点
            QPoint endPoint = QPoint(realImagePointX + width, realImagePointY + height);     //矩形的右上点
            QPoint startRightPoint = QPoint(endPoint.x(), startPoint.y());                   //矩形的右下点
            QPoint endLeftPoint = QPoint(startPoint.x(), endPoint.y());                      //矩形的左下点
            pointData << startPoint << startRightPoint << endPoint << endLeftPoint;          //数据存储到列表中

            pointStr = pointToString(pointData);                                             //将列表中的四个点转化为字符串的固定格式

            contourType = RECTPOINTTYPE;
        }
    }
    else if (ui->actionSetImportantError->isChecked())  //多边形检测
    {
        QList<QPoint>pointData;

        for (int i = 0; i < anomalyPoint.count(); i++)
        {
            pointData << QPoint((anomalyPoint.at(i).x() - lastSourceCenterPointX) / sourceZoomFactorCount,
                                (anomalyPoint.at(i).y() - lastSourceCenterPointY) / sourceZoomFactorCount);
        }

        if (!anomalyPoint.isEmpty())
        {
            pointStr = pointToString(pointData);   //将列表中的四个点转化为字符串的固定格式
        }
        contourType = RECTPOINTTYPE;
    }

    on_actionBlink_triggered();                 //闪烁视图
    on_actionShowErrorRect_triggered();         //错误边框

    //创建一个线程
    CompareThread *myThread = new CompareThread();

    myThread->setTemplateImage(sourceImage);  //源图
    myThread->setCompareImage(targetImage);   //比较图
    myThread->setPointStr(pointStr);          //点数据
    myThread->setContourType(contourType);    //比较类型

    connect(myThread, SIGNAL(sendString(int, QString, QString)), this, SLOT(receiveData(int, QString, QString)));
    connect(myThread, SIGNAL(finished()), myThread, SLOT(deleteLater()));
    myThread->start();                      //启动线程函数
}

/************************    接收线程数据             **************************************/
void MainWindow::receiveData(int flage, QString data, QString transformData)
{
    if(flage == 0 || data.isEmpty())
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("检测失败！"), QPixmap(FAILIMAGEPATH), true, this);
        ui->statusBar->hide();
        return;
    }

    stringToPoint(data);                       //将获取到的字符串转化为点
    matchStringToPoint(transformData);         //将获取到的字符串转化为点

    gressBar->setValue(RATE80);
    confirmCompareFlage = true;               //可以开始绘图
    timer->start();                           //定时器开始

    gressBar->setValue(RATE100);

    MESSAGEBOX->setInfo(tr("系统提示"), tr("检测成功！"), QPixmap(OKIMAGEPATH), true, this);

    on_actionMove_triggered();

    ui->statusBar->hide();
}

/************************    图片切换                ***************************************/
void MainWindow::switchImageSlot()
{
    static int tempCount = 0;
    if (tempCount % 2 == 0)
    {
        tempCount = 0;
        switchImageType = RESULTIMAGE;
    }
    else
    {
        switchImageType = SOURCEIMAGE;
    }
    tempCount++;
}

/************************    设置语言                ***************************************/
void MainWindow::setUpLanguageSlot()
{
    setUpLanguage->show();
}

/************************    保存检查结果             ***************************************/
void MainWindow::on_actionSaveResult_triggered()
{
    if (resultImage.isNull() || sourceImage.isNull() || targetImage.isNull())
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("当前还不能进行保存！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(NULL, tr("保存文件"), ".", "gtr(*.gtr)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QFile::Text | QIODevice::Append))  return;

    gressBar->setMinimumWidth(this->width() - gressLabel->width() * 2);
    gressBar->setRange(0, IMAGEMAX);                                                //设置进度条范围
    ui->statusBar->show();

    file.write(imageToString(sourceImage).toHex());
    file.write(&SPLITSTRING);
    gressBar->setValue(RESULTIMAGE);                                                //设置进度条值
    file.write(imageToString(resultImage).toHex());
    gressBar->setValue(IMAGEMAX);                                                   //读取完毕
    file.close();
    resultPathSet.insert(fileName);
    resultPathIndex = resultPathSet.count();
    MESSAGEBOX->setInfo(tr("系统提示"), tr("保存成功"), QPixmap(OKIMAGEPATH), true, this);
    ui->statusBar->hide();
}

/************************    图像转字符串             ***************************************/
const QByteArray MainWindow::imageToString(QImage &image)
{
    QByteArray data;
    QBuffer buffer(&data);
    image.save(&buffer, "png");
    buffer.close();

    return data;
}

/************************    字符串转图像             ***************************************/
void MainWindow::stringToImage(QString textFileName)
{
    if (textFileName.isEmpty()) return;
    QFile file(textFileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) return;
    QByteArray arrayData = file.readAll();

    QList<QByteArray> byteArray = arrayData.split(SPLITSTRING);
    if (byteArray.size() != IMAGEMAX)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("读取失败，请检查数据格式是否正确！"), QPixmap(FAILIMAGEPATH), true, this);
        file.close();
        return;
    }

    gressBar->setMinimumWidth(this->width() - gressLabel->width() * 2);
    gressBar->setRange(0, IMAGEMAX);                                                //设置进度条范围
    ui->statusBar->show();

    sourceImage = QImage::fromData(QByteArray::fromHex(byteArray.at(SOURCEIMAGE))); //读取源图片
    gressBar->setValue(RESULTIMAGE);                                                //设置进度条值
    resultImage = QImage::fromData(QByteArray::fromHex(byteArray.at(RESULTIMAGE))); //读取结果图片
    gressBar->setValue(IMAGEMAX);                                                   //读取完毕

    anomalyPoint.clear();
    startRectPoint = INVALIDPOINT;               //画矩形框开始坐标
    endRectPoint = INVALIDPOINT;                 //画矩形框结束坐标
    sourceMovePoint = INVALIDPOINT;              //源图鼠标移动
    sourceEveryTimeMovePoint = INVALIDPOINT;     //源图每次鼠标移动的点

    targetImage = resultImage;

    initSourceImage();

    initTargetImage();

    resultImageCopy = resultImage;

    fileName.sourceImageFileName = STARTSHOWIMAGE;
    fileName.targetImageFileName = STARTSHOWIMAGE;
    confirmCompareFlage = true;

    cmykFlage = isShowCmykImage();

    on_actionBlink_triggered();                 //闪烁视图
    on_actionShowErrorRect_triggered();         //错误边框

    MESSAGEBOX->setInfo(tr("系统提示"), tr("读取成功"), QPixmap(OKIMAGEPATH), true, this);
    ui->statusBar->hide();
}

/************************    pdf转图片               ***************************************/
QImage MainWindow:: pdfToImage(QString textFileName)
{
    MuPDF::Document * document = MuPDF::loadDocument(textFileName);                   //将pdf文件加载进Document

    if(document->numPages() > MAXPDFPAGE)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("PDF文件页数过多！"), QPixmap(FAILIMAGEPATH), true, this);

        return QImage();
    }

    QImage firstImage = document->page(0)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR); //获取PDF第一页图片


    QSize size = QSize(firstImage.width(), 0);
    for(int i = 0; i < document->numPages(); i++)
    {
        size += QSize(0, document->page(i)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR).size().height()); //计算所有图片的大小，算出pdf总大小
    }

    QImage image = QImage(size, QImage::Format_ARGB32);

    size = QSize(0, 0);
    for(int i = 0; i < document->numPages(); i++)  //根据pdf的页数，进行写入图片操作
    {
        size += QSize(0, document->page(i)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR).size().height());
        if(document->page(i)->isValid())
        {
            QImage tempImage = document->page(i)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR);    //当前页图片

            int width = document->page(i)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR).width();   //当前图片宽度
            int height = document->page(i)->renderImage(PDFZOOMFACTOR, PDFZOOMFACTOR).height(); //当前图片高度

            for(int x = 0; x < width; x++)
            {
                for(int y = 0; y < height; y++)
                {
                    if(x >= image.width() || (y + size.height() - firstImage.height()) >= image.height()) continue;

                    image.setPixel(x, y + size.height() - firstImage.height(), tempImage.pixel(x, y));  //将pdf中的图片写入图片
                }
            }
        }
    }

    return image;
}

/************************    版本信息                ***************************************/
void MainWindow::on_actionVersion_triggered()
{
    VersionDialog dialog(this);
    dialog.exec();
}

/************************    旋转270度               ***************************************/
void MainWindow::on_actionRotate270_triggered()
{
    if (sourceImage.isNull()) return;
    QMatrix matrix;
    rotateTargel += ROTATEANGEL270;

    matrix.rotate(ROTATEANGEL270);
    sourceImageCopy = sourceImageCopy.transformed(matrix);

    if (!targetImage.isNull())
    {
        targetImageCopy = targetImageCopy.transformed(matrix);
        resultImageCopy = resultImageCopy.transformed(matrix);
    }
    if (cmykFlage)
    {
        sourceImageCmyk = sourceImageCmyk.transformed(matrix);
        targetImageCmyk = targetImageCmyk.transformed(matrix);
        resultImageCmyk = resultImageCmyk.transformed(matrix);
    }
    startRectPoint = INVALIDPOINT;               //画矩形框开始坐标
    endRectPoint = INVALIDPOINT;                 //画矩形框结束坐标
    anomalyPoint.clear();
}

/************************    旋转90度                ***************************************/
void MainWindow::on_actionRotate90_triggered()
{
    if (sourceImage.isNull()) return;
    QMatrix matrix;
    rotateTargel += ROTATEANGEL90;

    matrix.rotate(ROTATEANGEL90);
    sourceImageCopy = sourceImageCopy.transformed(matrix);

    if (!targetImage.isNull())
    {
        targetImageCopy = targetImageCopy.transformed(matrix);
        resultImageCopy = resultImageCopy.transformed(matrix);
    }
    if (cmykFlage)
    {
        sourceImageCmyk = sourceImageCmyk.transformed(matrix);
        targetImageCmyk = targetImageCmyk.transformed(matrix);
        resultImageCmyk = resultImageCmyk.transformed(matrix);
    }
    startRectPoint = INVALIDPOINT;               //画矩形框开始坐标
    endRectPoint = INVALIDPOINT;                 //画矩形框结束坐标
    anomalyPoint.clear();
}

/************************    主题风格蓝               ***************************************/
void MainWindow::on_actionBlue_triggered()
{
    INICONFIG->setThemeStyle(QString::number(THEMEBLUE));
    ui->centralWidget->setStyleSheet(STYLESHEETBLUE);
}

/************************    主题风格亮               ***************************************/
void MainWindow::on_actionLight_triggered()
{
    INICONFIG->setThemeStyle(QString::number(THEMELIGHT));
    ui->centralWidget->setStyleSheet(STYLESHEETLIGHT);
}

/************************    主题风格暗               ***************************************/
void MainWindow::on_actionGray_triggered()
{
    INICONFIG->setThemeStyle(QString::number(THEMEGRAY));
    ui->centralWidget->setStyleSheet(STYLESHEETGRAY);
}

/************************    打开下次检查结果          ***************************************/
void MainWindow::on_actionOpenNextResult_triggered()
{
    if (resultPathSet.count() <= 0)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("未生成检查结果！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }

    if (resultPathSet.count() <= resultPathIndex)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("没有下次检查结果！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }

    resultPathIndex ++;
    QList<QString>resultList = resultPathSet.toList();
    if(resultPathIndex <= resultList.size())
    {
        stringToImage(resultList[resultPathIndex - 1]);
    }
}

/************************    打开上次检查结果          ***************************************/
void MainWindow::on_actionOpenLastResult_triggered()
{
    if (resultPathSet.count() <= 0)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("未生成检查结果！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }

    if (resultPathIndex <= 0)
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("没有上次检查结果！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }

    resultPathIndex--;
    QList<QString>resultList = resultPathSet.toList();
    if(resultPathIndex < resultList.size())
    {
        stringToImage(resultList[resultPathIndex]);
    }
}

/************************    放大图片                 ***************************************/
void MainWindow::on_actionZoomIn_triggered()
{
    setActionImageOper(ZOOMINOPER);
}

/************************    缩小图片                 ***************************************/
void MainWindow::on_actionZoomOut_triggered()
{
    setActionImageOper(ZOOMOUTOPER);
}

/************************    移动图片                 ***************************************/
void MainWindow::on_actionMove_triggered()
{
    setActionImageOper(MOVEOPER);
    sourcePressFlage = false;                        //源图片点击标志位
    targetPressFlage = false;                        //目标图片点击标志位
}

/************************    隐藏工具栏               ***************************************/
void MainWindow::on_actionTool_triggered()
{
    if (ui->actionTool->isChecked())
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}

/************************    是否显示CMYK图           ***************************************/
bool MainWindow::isShowCmykImage()
{
    int tempCount = 0;
    if (!ui->actionCyan->isChecked())
    {
        tempCount++;
        this->on_actionCyan_triggered();
    }
    if (!ui->actionMagenta->isChecked())
    {
        tempCount++;
        this->on_actionMagenta_triggered();
    }

    if (!ui->actionYellow->isChecked())
    {
        tempCount++;
        this->on_actionYellow_triggered();
    }

    if (!ui->actionBlack->isChecked())
    {
        tempCount++;
        this->on_actionBlack_triggered();
    }

    return tempCount > 0 ? true : false;
}

/************************    接收线程图片             ***************************************/
void MainWindow::receiveCmykImage(QImage firstImage, QImage secondImage, QImage thirdImage)
{
    sourceImageCmyk = firstImage;
    targetImageCmyk = secondImage;
    resultImageCmyk = thirdImage;

    QMatrix matrix;

    matrix.rotate(rotateTargel);

    if(!sourceImageCmyk.isNull()) sourceImageCmyk = sourceImageCmyk.transformed(matrix);
    if(!targetImageCmyk.isNull()) targetImageCmyk = targetImageCmyk.transformed(matrix);
    if(!resultImageCmyk.isNull()) resultImageCmyk = resultImageCmyk.transformed(matrix);

    int option = dataCmyk.cyanState + dataCmyk.magantState + dataCmyk.yellowState + dataCmyk.blackState;
    cmykFlage = option == FIFTEEN ? false : true;
}

/************************    图片转cmyk图片           ***************************************/
void MainWindow::imageToCmykImage()
{
    int option = dataCmyk.cyanState + dataCmyk.magantState + dataCmyk.yellowState + dataCmyk.blackState;
    //创建一个线程
    CmykThread *cmykThread = new CmykThread();

    cmykThread->setSourceImage(sourceImage);
    cmykThread->setTargetImage(targetImage);
    cmykThread->setResultImage(resultImage);
    cmykThread->setOption(option);

    connect(cmykThread, SIGNAL(sendCmykImage(QImage, QImage, QImage)), this, SLOT(receiveCmykImage(QImage,  QImage, QImage)));
    connect(cmykThread, SIGNAL(finished()), cmykThread, SLOT(deleteLater()));
    cmykThread->start();                      //启动线程函数
}

/************************    CMYK青色                ***************************************/
void MainWindow::on_actionCyan_triggered()
{
    if (ui->actionCyan->isChecked())
    {
        dataCmyk.cyanState = CYAN;
    }
    else
    {
        dataCmyk.cyanState = INVALID;
    }

    imageToCmykImage();
}

/************************    CMYK品红                ***************************************/
void MainWindow::on_actionMagenta_triggered()
{
    if (ui->actionMagenta->isChecked())
    {
        dataCmyk.magantState = MAGANT;
    }
    else
    {
        dataCmyk.magantState = INVALID;
    }

    imageToCmykImage();
}

/************************    CMYK黄色                ***************************************/
void MainWindow::on_actionYellow_triggered()
{
    if (ui->actionYellow->isChecked())
    {
        dataCmyk.yellowState = YELLOW;
    }
    else
    {
        dataCmyk.yellowState = INVALID;
    }

    imageToCmykImage();
}

/************************    CMYK黑色                ***************************************/
void MainWindow::on_actionBlack_triggered()
{
    if (ui->actionBlack->isChecked())
    {
        dataCmyk.blackState = BLACK;
    }
    else
    {
        dataCmyk.blackState = INVALID;
    }

    imageToCmykImage();
}

/************************    拆分窗口                 ***************************************/
void MainWindow::on_actionChoseWidget_triggered()
{
    static int tempCount = 0;

    switch (tempCount % MAXWIDGET)
    {
    case SOURCEWIDGET: ui->labelSourceImage->show(); ui->labelTargetImage->show(); ui->labelResultImage->hide(); break;
    case TARGETWIDGET: ui->labelSourceImage->show(); ui->labelTargetImage->hide(); ui->labelResultImage->show(); break;
    case RESULTWIDGET: ui->labelSourceImage->hide(); ui->labelTargetImage->show(); ui->labelResultImage->show(); break;
    case ALLWIDGET:    ui->labelSourceImage->show(); ui->labelTargetImage->show(); ui->labelResultImage->show(); break;
    }

    tempCount++;
}

/************************    闪烁目标图像              ***************************************/
void MainWindow::on_actionBlink_triggered()
{
    if (!ui->actionBlink->isChecked())
    {
        if (timer->isActive())
        {
            timer->stop();
        }
        switchImageType = RESULTIMAGE;
    }
    else
    {
        timer->start();
    }
}

/************************    输出结果图片              ***************************************/
void MainWindow::on_actionOutPutImage_triggered()
{
    if (resultImage.isNull() || sourceImage.isNull() || targetImage.isNull())
    {
        MESSAGEBOX->setInfo(tr("系统提示"), tr("当前还不能进行输出！"), QPixmap(FAILIMAGEPATH), true, this);
        return;
    }
    QString fileName = QFileDialog::getSaveFileName(NULL, tr("输出结果图片"), ".", "png(*.png)");
    if (fileName.isEmpty()) return;

    outPutResultImage(fileName);

    MESSAGEBOX->setInfo(tr("系统提示"), tr("输出结果图片成功!"), QPixmap(OKIMAGEPATH), true, this);
}

/************************    输出结果图片              ***************************************/
void MainWindow::outPutResultImage(QString tempFileName)
{
    QImage newImage;
    if (cmykFlage)
    {
        int width = (sourceImageCmyk.width() + resultImageCmyk.width())  + HEIGHTVALUE * 2;
        int height = std::max(sourceImageCmyk.height(), resultImageCmyk.height()) + WIDTHVALUE;
        newImage = QImage(width, height, QImage::Format_ARGB32);
    }
    else
    {
        int width = (sourceImage.width() + resultImage.width()) + HEIGHTVALUE * 2;
        int height = std::max(sourceImage.height(), resultImage.height()) + WIDTHVALUE;
        newImage = QImage(width, height, QImage::Format_ARGB32);
    }

    gressBar->setMinimumWidth(this->width() - gressLabel->width() * 2);
    gressBar->setRange(0, newImage.width());                                                //设置进度条范围
    ui->statusBar->show();

    bool addFlage = false;  //是否加补偿值
    QColor color;
    for (int x = 0; x < newImage.width() - HEIGHTVALUE; x++)
    {
        for (int y = 0; y < newImage.height() - WIDTHVALUE; y++)
        {
            if (cmykFlage)
            {
                if (x >= sourceImageCmyk.width())
                {
                    if (!addFlage)
                    {
                        x += HEIGHTVALUE;
                        addFlage = true;
                    }

                    if (y >= resultImageCmyk.height()) continue;

                    color = QColor(resultImageCmyk.pixel(x - sourceImageCmyk.width() - HEIGHTVALUE, y));
                }
                else
                {
                    color = QColor(sourceImageCmyk.pixel(x, y));
                }
            }
            else
            {
                if (x >= sourceImage.width())
                {
                    if (!addFlage)
                    {
                        x += HEIGHTVALUE;
                        addFlage = true;
                    }
                    if (y >= resultImage.height()) continue;

                    color = QColor(resultImage.pixel(x - sourceImage.width() - HEIGHTVALUE, y));

                }
                else
                {
                    color = QColor(sourceImage.pixel(x, y));
                }
            }
            newImage.setPixelColor(x, y, color);
        }

        gressBar->setValue(x);
    }
    setPixelToWhite(&newImage);

    QPainter painter(&newImage);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);

    QPen pen = painter.pen();

    pen.setColor(Qt::black);

    QFont font = painter.font();
    font.setPixelSize(28);
    font.setBold(true);

    painter.setPen(pen);
    painter.setFont(font);

    QPoint point = QPoint(0, newImage.height() - WIDTHVALUE + OUTPUTVALUE);

    painter.drawText(point, tr(" Inspection  %1   Inspection time  %2 ").arg(firstFileName)
                     .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));

    point = QPoint(newImage.width() / 2, newImage.height() - WIDTHVALUE + OUTPUTVALUE);

    painter.drawText(point, tr(" Inspection  %1   Inspection time  %2 ").arg(secondFileName)
                     .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss")));

    newImage.save(tempFileName);
    gressBar->setValue(newImage.width());
    ui->statusBar->hide();
}

/************************    提取感兴趣区域矩形域       ***************************************/
const QRect MainWindow::getImageRect(QImage image)
{
    /*************************************************************************
     * 思路：
     * 一张含有空白区域的图片，要获取到有图的矩形区域部分
     * 将图片的像素中扫描每一行，直到发现含有不是全白的像素连续超过40个像素，记录此时的白色行高
     * 转90度再记录，总共转了4次，转了360度，这个时候根据上下左右的白边宽度，计算出矩形域的
     * 开始部分的坐标，和矩形区域的长和宽度，然后将这个块区域保存到一块新的图片中
     * ***********************************************************************/
    QList<int>whiteRowHigh;
    oneToMorePoint = INVALIDPOINT;

    for(int i = 0; i < COLORCOUNT; i ++)
    {
        for(int y = 0; y < image.height(); y++)
        {
            int count = 0;        //数据连续区域
            for(int x = 0; x < image.width(); x++)
            {
                if(image.pixel(x, y) != BLACKPIXEL)
                {
                    count ++;
                }
            }

            if(count > POINTCOUNT)
            {
                whiteRowHigh << y;

                QMatrix matrix;

                matrix.rotate(ROTATEANGEL90);

                image = image.transformed(matrix);

                break;
            }
        }
    }

    if(whiteRowHigh.size() >= COLORCOUNT)
    {
        oneToMorePoint = QPoint(whiteRowHigh[1], whiteRowHigh[0]);

        int rectWidth = image.width() - whiteRowHigh[1] - whiteRowHigh[3];

        int rectHigh = image.height() - whiteRowHigh[0] - whiteRowHigh[2];

        QRect rect(oneToMorePoint.x(), oneToMorePoint.y(), rectWidth, rectHigh);

        return rect;
    }

    return QRect(0, 0, 0, 0);
}

/************************    画的矩形区域转为图片       ***************************************/
const QImage MainWindow::rectToImage()
{
    if(!ui->actionSetError->isChecked()) return QImage();
    if(startRectPoint == INVALIDPOINT && endRectPoint == INVALIDPOINT) return QImage();

    float width = (endRectPoint.x() - startRectPoint.x()) / sourceZoomFactorCount;   //画的矩形宽度
    float height = (endRectPoint.y() - startRectPoint.y()) / sourceZoomFactorCount;  //画的矩形高度

    //将画的矩形区域转化为图片
    QImage tempImage(QSize(width, height), QImage::Format_ARGB32);
    for(int i = 0; i < tempImage.width(); i++)
    {
        for(int j = 0; j < tempImage.height(); j++)
        {
            if((realImagePointX + i) >= sourceImage.width() ||  (realImagePointY + j) >= sourceImage.height()) continue;
            tempImage.setPixel(i, j, sourceImage.pixel(realImagePointX + i, realImagePointY + j));
        }
    }
    return tempImage;
}

/************************    设置透明像素为白色         ***************************************/
void MainWindow::setPixelToWhite(QImage *image)
{
    for(int i = 0; i < image->width(); i++)
    {
        for(int j = 0; j < image->height(); j++)
        {
            if(image->pixel(i,j) == 0) image->setPixel(i, j, WHITEPIXEL);
        }
    }
}

/************************    设置选中画笔颜色          ***************************************/
void MainWindow::setActionPenColor(int type)
{
    QList<QAction*>colorList;

    colorList.push_back(ui->actionRedColor);
    colorList.push_back(ui->actionChengColor);
    colorList.push_back(ui->actionYellowColor);
    colorList.push_back(ui->actionGreenColor);
    colorList.push_back(ui->actionCyanColor);
    colorList.push_back(ui->actionBlueColor);
    colorList.push_back(ui->actionPurpleColor);

    colorList.at(type)->setChecked(true);
    colorList.removeAt(type);
    for(int j = 0; j < colorList.size(); j ++)
    {
        colorList.at(j)->setChecked(false);
    }

    colorList.clear();

    resultImage = QImage();
}

/************************    设置工具栏选中情况        ***************************************/
void MainWindow::setActionImageOper(int type)
{
    QList<QAction*>operList;

    operList.push_back(ui->actionSetError);
    operList.push_back(ui->actionSetImportantError);
    operList.push_back(ui->actionMove);
    operList.push_back(ui->actionZoomIn);
    operList.push_back(ui->actionZoomOut);

    operList.at(type)->setChecked(true);
    operList.removeAt(type);
    for(int j = 0; j < operList.size(); j ++)
    {
        operList.at(j)->setChecked(false);
    }

    operList.clear();
}

/************************    显示错误边框             ***************************************/
void MainWindow::on_actionShowErrorRect_triggered()
{ 
    resultImage = QImage();
}

/************************    退出应用程序             ***************************************/
void MainWindow::on_actionExit_triggered()
{
    this->close();
}

/************************    矩形检测                ***************************************/
void MainWindow::on_actionSetError_triggered()
{
    setActionImageOper(RECTOPER);                  //设置选中
    startRectPoint = INVALIDPOINT;                 //画矩形框开始坐标
    endRectPoint = INVALIDPOINT;                   //画矩形框结束坐标
    if(!resultImage.isNull())
    {
        on_actionSureInitAll_triggered();              //全部确认初始化
    }
}

/************************    多边形检测               ***************************************/
void MainWindow::on_actionSetImportantError_triggered()
{
    setActionImageOper(POLYGONOPER);               //设置选中
    anomalyPoint.clear();                          //数据清空
    startRectPoint = INVALIDPOINT;                 //画矩形框开始坐标
    endRectPoint = INVALIDPOINT;                   //画矩形框结束坐标
    if(!resultImage.isNull())
    {
        on_actionSureInitAll_triggered();              //全部确认初始化
    }
}

/************************    全部确认初始化           ***************************************/
void MainWindow::on_actionSureInitAll_triggered()
{
    this->initValue();

    resultImage = QImage();

    resultImageCopy = QImage();

    sourceImage = sourceSourceImage;

    targetImage = targetTargetImage;

    srcImage = QImageToMat(sourceImage);

    compareImage = QImageToMat(targetImage);

    initSourceImage();

    initTargetImage();

    update();
}

/************************    红色画笔                ***************************************/
void MainWindow::on_actionRedColor_triggered()
{
    myPen = QPen(REDCOLOR, PENWIDTH);
    comparePen = QPen(REDCOLOR, PENWIDTH);
    setActionPenColor(REDPENCOLOR);
}

/************************    橙色画笔                ***************************************/
void MainWindow::on_actionChengColor_triggered()
{
    myPen = QPen(CHENGCOLOR, PENWIDTH);
    comparePen = QPen(CHENGCOLOR, PENWIDTH);
    setActionPenColor(CHENGPENCOLOR);
}

/************************    黄色画笔                ***************************************/
void MainWindow::on_actionYellowColor_triggered()
{
    myPen = QPen(YELLOWCOLOR, PENWIDTH);
    comparePen = QPen(YELLOWCOLOR, PENWIDTH);
    setActionPenColor(YELLOWPENCOLOR);
}

/************************    绿色画笔                ***************************************/
void MainWindow::on_actionGreenColor_triggered()
{
    myPen = QPen(GREENCOLOR, PENWIDTH);
    comparePen = QPen(GREENCOLOR, PENWIDTH);
    setActionPenColor(GREENPENCOLOR);
}

/************************    青色画笔               ***************************************/
void MainWindow::on_actionCyanColor_triggered()
{
    myPen = QPen(CYANCOLOR, PENWIDTH);
    comparePen = QPen(CYANCOLOR, PENWIDTH);
    setActionPenColor(CYANPENCOLOR);
}

/************************    蓝色画笔               ***************************************/
void MainWindow::on_actionBlueColor_triggered()
{
    myPen = QPen(BLUECOLOR, PENWIDTH);
    comparePen = QPen(BLUECOLOR, PENWIDTH);
    setActionPenColor(BLUEPENCOLOR);
}

/************************    紫色画笔               ***************************************/
void MainWindow::on_actionPurpleColor_triggered()
{
    myPen = QPen(PURPLECOLOR, PENWIDTH);
    comparePen = QPen(PURPLECOLOR, PENWIDTH);
    setActionPenColor(PURPLEPENCOLOR);
}

/************************    字符串转点              **************************************/
void MainWindow::matchStringToPoint(QString &data)
{

    QVector<QVector<DAPoint>> pointData;
    QStringList imageData = data.split("|");

    for(int i = 0; i < imageData.size(); i ++)
    {
        QStringList lineData =  imageData[i].split(";");
        QVector<DAPoint> subSubPts;

        for(int j = 0; j < lineData.size(); j ++)
        {
            DAPoint dap;
            QStringList pt = lineData[j].split(",");

            if (pt.size() == 2)
            {
                dap.x = pt[0].toFloat();
                dap.y = pt[1].toFloat();
            }
            subSubPts.push_back(dap);
        }
        pointData.push_back(subSubPts);
    }

    if(pointData.size() >= 2)
    {
        if(comparePoints.count() > 1 && ui->actionSetError->isChecked())
        {
            srcImage = QImageToMat(rectToImage());
        }

        QRect tempRect;

        //使用OPenCv的仿射变换进行匹配图片
        cv::Point2f srcPoint[3];                                           //模板图的三个点

        cv::Point2f **dstPoint = new cv::Point2f * [pointData.size() - 1]; //检测图像的三个点，因为可能为一对多，则动态创建
        for(int i = 0; i < pointData.size() - 1; i ++)
        {
            dstPoint[i] = new cv::Point2f[3];
        }

        for(int i = 0; i < pointData.size(); i++)
        {
            for(int j = 0; j < pointData[i].size(); j++)
            {
                if(i == 0)
                {
                    if( pointData.size() > 2)
                    {
                        srcPoint[j] = cv::Point2f(pointData.at(i).at(j).x - realImagePointX, pointData.at(i).at(j).y - realImagePointY);         //模板图的三个点
                    }
                    else
                    {
                        srcPoint[j] = cv::Point2f(pointData.at(i).at(j).x, pointData.at(i).at(j).y);         //模板图的三个点
                    }
                }
                else
                {
                    dstPoint[i - 1][j] = cv::Point2f(pointData.at(i).at(j).x, pointData.at(i).at(j).y);  //检测图像的三个点
                }
            }
        }

        cv::Mat *dstImage = new  cv::Mat[pointData.size() - 1];  //创建匹配的图像

        for(int i = 0; i < pointData.size() - 1; i ++)
        {
            const cv::Mat affineMatrix = cv::getAffineTransform(srcPoint, dstPoint[i]);//使用仿射变换

            cv::warpAffine(srcImage, dstImage[i], affineMatrix, compareImage.size());   //进行平移旋转缩放等后的图片
            cv::cvtColor(dstImage[i], dstImage[i], CV_BGR2RGB);
        }

        cv::Mat dst= dstImage[0];

        for(int i = 0; i < pointData.size() - 2; i ++)
        {
            cv::addWeighted(dst, 1, dstImage[i + 1], 1, 0,  dst);       //将图片进行混合视图
        }


        if(NULL != dst.data)
        {
            sourceImage = QImage((const uchar*)dst.data, dst.cols, dst.rows, dst.cols * dst.channels(), QImage::Format_RGB888);
            sourceImage.bits();
            if(comparePoints.count() > 1)
            {
                tempRect = getImageRect(sourceImage);                  //如果是一对多，将矩形截取为图片
                cv::Rect rect(tempRect.x(), tempRect.y(), tempRect.width(), tempRect.height());

                //截取模板图感兴趣区域
                {
                    dst(rect).copyTo(dst);
                    sourceImage = QImage((const uchar*)dst.data, dst.cols, dst.rows, dst.cols * dst.channels(), QImage::Format_RGB888);
                    sourceImage.bits();
                }

                //截取目标图感兴趣区域
                {
                    cv::cvtColor(compareImage, compareImage, CV_BGR2RGB);
                    compareImage(rect).copyTo(compareImage);
                    targetImage = QImage((const uchar*)compareImage.data, compareImage.cols, compareImage.rows, compareImage.cols * compareImage.channels(), QImage::Format_RGB888);
                    targetImage.bits();
                }
            }
        }

        //将图片初始化
        {
            initSourceImage();
            initTargetImage();
            startRectPoint = INVALIDPOINT;
            endRectPoint = INVALIDPOINT;
            anomalyPoint.clear();
            rotateTargel = 0;
        }

        //释放内存
        {
            for(int i = 0; i < pointData.size() - 1; i++)
            {
                delete []dstPoint[i];
            }
            delete []dstPoint;

            delete []dstImage;
        }
    }
}

/************************    QImage转换Mat          **************************************/
cv::Mat MainWindow::QImageToMat(const QImage &image)
{
    cv::Mat matFirst(image.height(), image.width(), CV_8UC4, (uchar*)image.bits(), image.bytesPerLine());

    cv::Mat matSecond = cv::Mat(matFirst.rows, matFirst.cols, CV_8UC3);

    int fromTo[] = {0, 0, 1, 1, 2, 2};

    //把输入矩阵的某些通道拆分给对应的输出矩阵
    cv::mixChannels(&matFirst, 1, &matSecond, 1, fromTo, 3);

    return matSecond;
}
