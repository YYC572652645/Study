#include <QApplication>
#include <QFont>
#include <QFile>
#include "screen/mainobject.h"
#include "qreadwrite/qreadwriteini.h"
#include "globaldef.h"
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile qssFile(":/style.qss");     //读取qss文件
    qssFile.open(QFile::ReadOnly);    //以只读方式打开文件

    if (qssFile.isOpen())
    {
        QString strQss = QLatin1String(qssFile.readAll());//将qss信息读取到字符串
        qApp->setStyleSheet(strQss);                      //软件设置样式表
        qssFile.close();                                  //关闭文件
    }

    //设置字体
    QFont font("ZYSong18");
    a.setFont(font);

    MainObject object;

    QTranslator translater;
    INICONFIG->readIni();
    if(INICONFIG->getLanguage() == QString::number(ENGLISH))
    {
        if(translater.load(ENGLISHQMPATH))
        {
            a.installTranslator(&translater);
        }
    }
    else
    {
        if(translater.load(CHINESEQMPATH))
        {
            a.installTranslator(&translater);
        }
    }

    object.setInit();

    return a.exec();
}
