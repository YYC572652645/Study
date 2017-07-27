#ifndef SUSPENDFORM_H
#define SUSPENDFORM_H

#include <QWidget>
#include <QPoint>
#include <QMouseEvent>
#include <QMenu>
namespace Ui {
class SuspendForm;
}

class SuspendForm : public QWidget
{
    Q_OBJECT

public:
    explicit SuspendForm(QWidget *parent = 0);
    ~SuspendForm();
    static SuspendForm*getInstance();
    QPoint point;
    QMenu*menu;
    QAction*actionShow;
    QAction*actionClose;

private:
    Ui::SuspendForm *ui;
    static SuspendForm*instance;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private slots:
    void actionShowFrame();
    void actionCloseFrame();
signals:
    void sendFlage(int flage);
};

#endif // SUSPENDFORM_H
