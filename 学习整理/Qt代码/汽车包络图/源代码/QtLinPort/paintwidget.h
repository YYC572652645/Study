#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
namespace Ui {
class PaintWidget;
}

class PaintWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent = 0);
    ~PaintWidget();

private:
    Ui::PaintWidget *ui;

    /***************************私有函数***************************/
private:
    void paintEvent(QPaintEvent*event);
    void mouseDoubleClickEvent(QMouseEvent*event);
};

#endif // PAINTWIDGET_H
