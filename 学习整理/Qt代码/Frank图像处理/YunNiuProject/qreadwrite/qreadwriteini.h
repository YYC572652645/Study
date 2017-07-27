
#ifndef QREADWRITEINI_H
#define QREADWRITEINI_H
#include<QSettings>
#include<singleton/singleton.h>

/***************************************************************
   功能:读取配置INI文件

   创建人:殷宇辰

   创建时间:2017-6-22
**************************************************************/

#define INICONFIG  Singleton<QReadWriteIni>::getInstance()

class QReadWriteIni
{
public:

    /****************构造函数***************/
    QReadWriteIni();

    /****************读取配置文件***************/
    void readIni();

    /****************写入主题风格配置***************/
    void writeThemeStyle();

    /****************写入主题风格配置***************/
    void writeLanguage();

public:

    QString getThemeStyle() const;
    void setThemeStyle(const QString &value);

    QString getLanguage() const;
    void setLanguage(const QString &value);

private:
    QString themeStyle;      //主题风格
    QString language;        //语言
};

#endif // QREADWRITEINI_H
