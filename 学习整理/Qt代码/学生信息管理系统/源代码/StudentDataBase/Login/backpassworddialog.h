#ifndef BACKPASSWORDDIALOG_H
#define BACKPASSWORDDIALOG_H

#include <QDialog>
#include"logindata.h"
namespace Ui {
class BackPassWordDialog;
}

class BackPassWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BackPassWordDialog(QWidget *parent = 0);
    ~BackPassWordDialog();

private slots:
    void on_pushButtonBack_clicked();//找回密码按钮

private:
    Ui::BackPassWordDialog *ui;
    LoginData login;                 //数据库类对象
};

#endif // BACKPASSWORDDIALOG_H
