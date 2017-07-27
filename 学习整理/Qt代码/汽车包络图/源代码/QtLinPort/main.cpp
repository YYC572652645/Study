#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Arial",12,QFont::AnyStyle,false);
    a.setFont(font);
    MainWindow w;
    w.show();

    return a.exec();
}
