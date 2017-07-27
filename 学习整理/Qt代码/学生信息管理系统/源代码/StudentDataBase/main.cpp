#include "mainwindow.h"
#include "Login/logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString strQss;
    QFile qssFile(":/new/prefix1/style.qss"); //读取qss文件
    qssFile.open(QFile::ReadOnly);            //以只读方式打开文件

    if(qssFile.isOpen())
    {
        strQss=QLatin1String(qssFile.readAll());//将qss信息读取到字符串
        qApp->setStyleSheet(strQss);            //软件设置样式表
        qssFile.close();                        //关闭文件
    }
    //设置字体
    QFont font("ZYSong18");
    a.setFont(font);
    MainWindow w;
    w.show();
    return a.exec();
}
