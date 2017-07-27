#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont f("ZYSong",14);          //设置字体
    a.setFont(f);

    MainWindow w;
    w.show();

    return a.exec();
}
