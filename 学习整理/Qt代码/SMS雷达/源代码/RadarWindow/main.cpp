#include "radarwindow.h"
#include <QApplication>
#include "mainobject.h"
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
    QFont font("ZYSong",14);
    a.setFont(font);
    MainObject mainObject;
    mainObject.setInit();
    return a.exec();
}
