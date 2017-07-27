#include "versiondialog.h"
#include "ui_versiondialog.h"
#include <QDesktopWidget>
#include "globaldef.h"

VersionDialog::VersionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VersionDialog)
{
    ui->setupUi(this);

    this->setWindowTitle(tr("版本信息"));
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);          //去掉窗口右上角的问号
    this->setWindowIcon(QIcon(ICONPATH));
    QDesktopWidget *desktop=QApplication::desktop();
    this->move((desktop->width()-this->width()) / 2,(desktop->height()-this->height()) / 2);  //程序显示在屏幕中间
}

VersionDialog::~VersionDialog()
{
    delete ui;
}
