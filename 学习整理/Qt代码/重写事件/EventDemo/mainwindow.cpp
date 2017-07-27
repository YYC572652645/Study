#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPainter>
#include <QMimeData>
#include <QRect>
#include <QDebug>

/************************    构造函数         **************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), sliderValue(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置背景色为黑色
    this->setPalette(QPalette(Qt::black));
    this->setAutoFillBackground(true);

    this->setWindowTitle("灏夏星辰-重写事件Demo");
    this->setWindowIcon(QIcon(":/image/image.png"));

    ui->textEdit->setAcceptDrops(false);
    this->setAcceptDrops(true);

    startRectPoint = QPoint(0, 0);
    endRectPoint = QPoint(0, 0);
}

/************************    析构函数         **************************************/
MainWindow::~MainWindow()
{
    delete ui;
}

/************************    退出程序事件      **************************************/
void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::aboutQt(this, tr("关闭提示"));
}

/************************    鼠标点击事件      **************************************/
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        startRectPoint = event->globalPos() - pos() - POINT;
        endRectPoint  = event->globalPos() - pos() - POINT;
        update();
    }
    else if(event->button() == Qt::RightButton)
    {
        startRectPoint = QPoint(0, 0);
        endRectPoint  = QPoint(0, 0);
    }
}

/************************    鼠标释放事件      **************************************/
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        endRectPoint  = event->globalPos() - pos() - POINT;
        update();
    }
    else if(event->button() == Qt::RightButton)
    {
        startRectPoint = QPoint(0, 0);
        endRectPoint  = QPoint(0, 0);
    }
}

/************************    鼠标移动事件      **************************************/
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        endRectPoint  = event->globalPos() - pos() - POINT;
        update();
    }
}

/************************    鼠标双击事件      **************************************/
void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    static int tempCount = 0;

    if(tempCount % 2 == 0)
    {
        this->showFullScreen();
    }
    else
    {
        this->showNormal();
    }
    tempCount ++;

}

/************************    滚轮滚动事件      **************************************/
void MainWindow::wheelEvent(QWheelEvent *event)
{
    //鼠标向上滚动
    if (event->delta() > 0)
    {

        if (sliderValue > 0.99) return;
        sliderValue += 0.02;
    }
    //鼠标向下滚动
    else
    {
        if (sliderValue <= 0.01) return;
        sliderValue -= 0.02;
    }

    update();
}

/************************    画图事件         **************************************/
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    float sliderMaxValue = height() * 0.9;
    float sliderHigh  = -height() * 0.8;  //进度条高度
    const int sliderWidth = 60;           //进度条宽度

    //将坐标系的该点变成原点坐标
    painter.translate(width() * 0.2, sliderMaxValue);

    //设置画笔为红色
    QPen pen(Qt::white, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    painter.setPen(pen);

    //画下面直线
    painter.drawLine(0, 0, sliderWidth, 0);

    //画左边直线
    painter.drawLine(0, 0, 0, sliderHigh);

    //画右边直线
    painter.drawLine(sliderWidth, 0, sliderWidth, sliderHigh);

    //画上面直线线
    painter.drawLine(0, sliderHigh, sliderWidth, sliderHigh);

    //画进度值
    if(sliderValue < 0.01)
    {
        painter.drawText(sliderWidth - 40, sliderHigh - 10,tr("%0"));
    }
    else
    {
        painter.drawText(sliderWidth - 40, sliderHigh - 10,tr("%%1").arg(sliderValue * 100));
    }

    //将矩形填充为白色
    QPolygon polyGon;
    polyGon<<QPoint(sliderWidth, 0);
    polyGon<<QPoint(sliderWidth, sliderHigh);
    polyGon<<QPoint(0, sliderHigh);
    polyGon<<QPoint(0, 0);
    painter.setBrush(Qt::white);
    painter.drawConvexPolygon(polyGon);

    //设置渐变
    QLinearGradient linerGradient = QLinearGradient(0, 0, 0, sliderHigh);
    linerGradient.setColorAt(0.0, Qt::cyan);
    linerGradient.setColorAt(0.3, Qt::green);
    linerGradient.setColorAt(0.7, Qt::yellow);
    linerGradient.setColorAt(1.0, Qt::red);

    QBrush brush(linerGradient);
    painter.setBrush(brush);

    painter.drawRect(0, 0, sliderWidth, sliderHigh * sliderValue);

    int width = endRectPoint.x() - startRectPoint.x();               //画的矩形宽度
    int height = endRectPoint.y() - startRectPoint.y();              //画的矩形高度

    QPainter painterRect(this);

    painterRect.setPen(QPen(Qt::darkRed, 2));
    QRect rect(startRectPoint.x(), startRectPoint.y(), width, height);
    painterRect.drawRect(rect);

    painterRect.end();
    painter.end();
}

/************************    进入事件         **************************************/
void MainWindow::enterEvent(QEvent *event)
{
    this->setCursor(Qt::PointingHandCursor);
}

/************************    离开事件         **************************************/
void MainWindow::leaveEvent(QEvent *event)
{
    this->setCursor(Qt::ArrowCursor);
}

/************************    键盘事件         **************************************/
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_F5)
    {
        ui->textEdit->clear();
    }
}

/************************    拖入事件         **************************************/
void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

/************************    释放事件         **************************************/
void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl>urls = event->mimeData()->urls();

    if (urls.isEmpty())  return;

    QFile file(urls.first().toLocalFile());

    if(!file.open(QFile::ReadOnly | QFile::Text)) return;

    ui->textEdit->setText(QString::fromLocal8Bit(file.readAll()));
}
