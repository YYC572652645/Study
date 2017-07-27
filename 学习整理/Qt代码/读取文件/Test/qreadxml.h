#ifndef QREADXML_H
#define QREADXML_H
#include<QString>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>

#define XMLCONFIG  QReadXml::getInstance()->getXmlConfig()

typedef struct XmlConfig
{
    QString ip;                //IP地址
    QString port;              //端口
    QString dataBaseVersion;   //数据库版本
    QString dataBaseName;      //数据库名称
    QString userName;          //用户名
    QString passWord;          //密码
}XmlConfig;

class QReadXml
{
public:
    static QReadXml * getInstance();

    bool readXML();

    const XmlConfig &getXmlConfig();

private:
    QReadXml();

    XmlConfig xmlConfig;

    static QReadXml * instance;
};

#endif // QREADXML_H
