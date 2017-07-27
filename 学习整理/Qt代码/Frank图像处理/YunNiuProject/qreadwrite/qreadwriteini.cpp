#include "qreadwriteini.h"
#include "globaldef.h"

/****************构造函数******************/
QReadWriteIni::QReadWriteIni()
{
    this->readIni();
}

/****************读取配置文件***************/
void QReadWriteIni::readIni()
{
    QSettings * configIniRead=new QSettings("config.ini",QSettings::IniFormat);//初始化读取Ini文件对象
    themeStyle = configIniRead->value("config/themeStyle").toString();               //主题风格
    language = configIniRead->value("config/language").toString();               //主题风格
    delete configIniRead;
}

/****************写入主题风格配置***************/
void QReadWriteIni::writeThemeStyle()
{
    QSettings * configIniWrite=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    if(themeStyle.isEmpty())
    {
        configIniWrite->setValue("config/themeStyle",THEMEBLUE);                //主题风格
    }
    else
    {
        configIniWrite->setValue("config/themeStyle",themeStyle);              //主题风格
    }
    delete configIniWrite;
}

/****************写入语言配置***************/
void QReadWriteIni::writeLanguage()
{
    QSettings * configIniWrite=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    if(themeStyle.isEmpty())
    {
        configIniWrite->setValue("config/language",CHINESE);                //中文
    }
    else
    {
        configIniWrite->setValue("config/language",language);                //英文
    }
    delete configIniWrite;
}

QString QReadWriteIni::getThemeStyle() const
{
    return themeStyle;
}

void QReadWriteIni::setThemeStyle(const QString &value)
{
    themeStyle = value;
}

QString QReadWriteIni::getLanguage() const
{
    return language;
}

void QReadWriteIni::setLanguage(const QString &value)
{
    language = value;
}
