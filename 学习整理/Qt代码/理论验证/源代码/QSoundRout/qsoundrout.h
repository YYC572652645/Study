#ifndef QSOUNDROUT_H
#define QSOUNDROUT_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QRadialGradient>
#include <QCursor>
#include <QApplication>
#include <QPixmap>
#include <QDesktopWidget>
#include <math.h>

namespace Ui {
class QSoundRout;
}

class QSoundRout : public QMainWindow
{
    Q_OBJECT

public:
    explicit QSoundRout(QWidget *parent = 0);
    ~QSoundRout();

    void paintImage();           //画图函数
    void mousePress();           //鼠标点击
    void mouseRelease();         //鼠标释放
    bool eventFilter(QObject *watched, QEvent *event);
    QList<int>dataX;
    QList<int>dataY;
    QList<int>dataFlage;
    QList<int>dataFlageSecond;
    QList<int>dataCount;
private slots:
    void on_pushButtonClear_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButton_clicked();

private:
    Ui::QSoundRout *ui;
    bool flage;
    void screenRGB();
};

#endif // QSOUNDROUT_H
