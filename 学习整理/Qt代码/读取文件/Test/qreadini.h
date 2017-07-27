#ifndef QREADINI_H
#define QREADINI_H
#include<QSettings>

#define DATACONFIG  QReadIni::getInstance()->getIniConfig()

typedef struct IniConfig
{
    QString ip;                //IP地址
    QString port;              //端口
    QString dataBaseVersion;   //数据库版本
    QString dataBaseName;      //数据库名称
    QString userName;          //用户名
    QString passWord;          //密码
}IniConfig;

class QReadIni
{
public:
    static QReadIni*getInstance();

    void readIni();

    const IniConfig &getIniConfig();

private:
    QReadIni();

    IniConfig iniConfig;

    static QReadIni*instance;
};

#endif // QREADINI_H
