#ifndef ADDWIDGETTAB_H
#define ADDWIDGETTAB_H

#include <QWidget>

namespace Ui {
class addWidgetTab;
}

class addWidgetTab : public QWidget
{
    Q_OBJECT

public:
    explicit addWidgetTab(QWidget *parent = 0);
    ~addWidgetTab();

private:
    Ui::addWidgetTab *ui;
};

#endif // ADDWIDGETTAB_H
