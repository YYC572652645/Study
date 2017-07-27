#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include"logindata.h"
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

private slots:
    void on_pushButtonRegister_clicked();

private:
    Ui::RegisterDialog *ui;
    LoginData login;
};

#endif // REGISTERDIALOG_H
