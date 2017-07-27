#ifndef SOUNDWIDGET_H
#define SOUNDWIDGET_H
#include <QPainter>
#include <QWidget>
#include <QPaintEvent>
#include <math.h>
#include <QtMath>
#include <QDebug>
namespace Ui {
class SoundWidget;
}

class SoundWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SoundWidget(QWidget *parent = 0);
    ~SoundWidget();

private:
    Ui::SoundWidget *ui;
    double precision;
    void paintEvent(QPaintEvent*);


    void AllBernstein(int n,double u,double*B);
    QPoint PointOnBezir(double u);
    void setPrecision(double precision);
    void appendPoind(QPoint point);
    QPainterPath getPainterPath();
public:
    QList<float>dataDb;
    QList<int>dataAngle;
    QList<QPoint>pointList;

};

#endif // SOUNDWIDGET_H
