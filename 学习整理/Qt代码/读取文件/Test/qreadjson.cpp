#include"qreadjson.h"

QReadJson * QReadJson::instance = NULL;

QReadJson *QReadJson::getInstance()
{
    if(NULL == instance)
    {
        instance = new QReadJson();
    }

    return instance;
}

QReadJson::QReadJson()
{
    this->readJson();
}

bool QReadJson::readJson()
{
    QString strJson;

    QFile *file=new QFile("config.json");
    if(file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        strJson = file->readAll();
        file->close();
    }
    else
    {
        return false;
    }
    file->close();

    QJsonDocument jsonDom = QJsonDocument::fromJson(strJson.toUtf8());
    QJsonObject jsonObject = jsonDom.object();
    QJsonValue jsonValue = jsonObject.value(QString("conn"));


    QJsonObject objectItem = jsonValue.toObject();

    jsonConfig.ip = objectItem["ip"].toString();
    jsonConfig.port = objectItem["port"].toString();
    jsonConfig.dataBaseVersion = objectItem["databaseversion"].toString();
    jsonConfig.dataBaseName = objectItem["databasename"].toString();
    jsonConfig.userName = objectItem["username"].toString();
    jsonConfig.passWord = objectItem["password"].toString();

    delete file;
    return true;
}

const JsonConfig &QReadJson::getJsonConfig()
{
    return jsonConfig;
}


