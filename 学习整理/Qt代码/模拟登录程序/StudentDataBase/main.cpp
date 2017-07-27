#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    LoginDialog login;
    if(login.exec()==QDialog::Accepted)
    {
        w.show();
        return a.exec();

    }
    else
    {
        return 0;
    }


}
