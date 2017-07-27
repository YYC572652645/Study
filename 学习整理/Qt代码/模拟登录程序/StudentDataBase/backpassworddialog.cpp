#include "backpassworddialog.h"
#include "ui_backpassworddialog.h"


/**************************构造函数***************************/
BackPassWordDialog::BackPassWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackPassWordDialog)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::darkCyan));  //设置背景色
    setAutoFillBackground(true);
    ui->lineEditPsd->setEnabled(false);  //将密码控件置为不可写
    this->setWindowTitle(tr("找回密码")); //设置窗口标题
}


/**************************析构函数***************************/
BackPassWordDialog::~BackPassWordDialog()
{
    delete ui;
}


/**************************找回密码***************************/
void BackPassWordDialog::on_pushButtonBack_clicked()
{
    //如果数据库检测到，则写入密码
    if(login.backData(ui->lineEditUsm->text()))
    {
        ui->lineEditPsd->setText(login.backPassword);
    }
    else
    {
        ui->lineEditPsd->clear();
        QMessageBox::warning(this,tr("系统提示"),tr("找回密码失败"));
    }
}
