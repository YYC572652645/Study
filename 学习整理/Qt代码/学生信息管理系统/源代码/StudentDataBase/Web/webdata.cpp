#include "webdata.h"
#include "ui_webdata.h"

WebData::WebData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebData)
{
    ui->setupUi(this);
}

WebData::~WebData()
{
    delete ui;
}

void WebData::showWeb(QString webUrl)
{
    //
    ui->axWidget->setControl(QString::fromUtf8("{8856F961-340A-11D0-A96B-00C04FD705A2}")); //设置插件为IE
    ui->axWidget->dynamicCall("Navigate(const QString&)", webUrl);     //调用参数
}
