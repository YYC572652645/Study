#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString strQss;
    QFile qssFile(":/style.qss");
    qssFile.open(QFile::  ReadOnly);

    if(qssFile.isOpen())
    {
        strQss=QLatin1String(qssFile.readAll());
        qApp->setStyleSheet(strQss);
        qssFile.close();
    }

    MainWindow w;
    w.show();

    return a.exec();
}
