#include "addwidgettab.h"
#include "ui_addwidgettab.h"

addWidgetTab::addWidgetTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addWidgetTab)
{
    ui->setupUi(this);
}

addWidgetTab::~addWidgetTab()
{
    delete ui;
}
