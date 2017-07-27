#include "registerdialog.h"
#include "ui_registerdialog.h"


/**************************构造函数***************************/
RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    setPalette(QPalette(Qt::darkCyan));  //设置背景色
    setAutoFillBackground(true);
    this->setWindowTitle(tr("注册"));
}


/**************************析构函数***************************/
RegisterDialog::~RegisterDialog()
{
    delete ui;
}


/**************************注册用户***************************/
void RegisterDialog::on_pushButtonRegister_clicked()
{
    //如果插入成功则返回
    if(ui->lineEditUserName->text()!=""&&ui->lineEditPassWord->text()!="")
    {
        if(ui->lineEditPassWord->text()==ui->lineEditPassWordAgain->text())
        {
            if(login.insertData(ui->lineEditUserName->text(),ui->lineEditPassWordAgain->text()))
            {
                QMessageBox::information(this,tr("系统提示"),tr("注册成功"));
            }
            else
            {
                 QMessageBox::warning(this,tr("系统提示"),tr("注册失败"));
            }

        }
    }
}
