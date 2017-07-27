#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <QWidget>
#include <QString>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QtXml>
#include <QFile>
#include <QIODevice>
#include <QDomNodeList>
#include <QtScript>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QScriptValue>
#include <QVariantMap>
#include <QPaintEvent>
#include <QPainter>
#include <QScriptEngine>
#include "QCustomPlot/qcustomplot.h"
typedef struct DataWeather
{
    QString type;     //天气
    QString date;     //时间
    QString fengLi;   //风力
    QString fengXiang;//风向
}DataWeather;

namespace Ui {
class WeatherData;
}

class WeatherData : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherData(QWidget *parent = 0);
    ~WeatherData();

    /**********************查询数据*************************/
    void selectData(QString cityName);


    /**********************读取Xml文件**********************/
    bool readXML();


    /**********************连接数据库***********************/
    bool dataCnn();


    /**********************解析JSON数据********************/
    void analyseJson();

    /**********************画图函数************************/
    void paintEvent(QPaintEvent *event);

    void getWeather(QString cityNumber);
private:
    Ui::WeatherData *ui;
    QString cityNumber;            //城市编号
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
    QNetworkAccessManager *manager;//网络获取数据对象
    QByteArray weather;            //存储获取的数据
    QString strJson;               //存储JSON数据
    QVector<double>highTemp;       //高温数据
    QVector<double>lowTemp;        //低温数据
    QVector<double>dataX;          //横轴数据
    DataWeather dataWeather[5];    //未来数据
    QMovie *movie;                 //播放gif


private slots:
    /*****************获取JSON数据****************/
    void GetWebJsonData(QNetworkReply *reply);
    void on_pushButtonSelectData_clicked();
    void on_pushButtonShang_clicked();
    void on_pushButtonNext_clicked();
};

#endif // WEATHERDATA_H
