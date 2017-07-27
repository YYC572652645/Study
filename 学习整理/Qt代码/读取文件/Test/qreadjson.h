#ifndef QREADJSON_H
#define QREADJSON_H

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDomNodeList>
#include <QJsonDocument>
#include <QJsonObject>

#define JSONCONFIG  QReadJson::getInstance()->getJsonConfig()

typedef struct JsonConfig
{
    QString ip;                //IP地址
    QString port;              //端口
    QString dataBaseVersion;   //数据库版本
    QString dataBaseName;      //数据库名称
    QString userName;          //用户名
    QString passWord;          //密码
}JsonConfig;


class QReadJson
{
public:

    static QReadJson * getInstance();

    bool readJson();

    const JsonConfig &getJsonConfig();

private:
    QReadJson();

    static QReadJson * instance;

    JsonConfig jsonConfig;
};

#endif // QREADJSON_H
