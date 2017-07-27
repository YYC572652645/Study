#ifndef WORKTHREAD_H
#define WORKTHREAD_H

#include <QObject>
#include <QThread>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlDatabase>
#include<QtXml>

typedef struct StudentData
{
    QString number;
    QString name;
    QString sex;
    QString age;

}StudentData;

class WorkThread : public QThread
{
    Q_OBJECT
public:WorkThread();

private:
    void run();

    /************查询数据库数据*************/
    int dataSelectMessage();

    /************连接数据库*************/
    bool dataCnn();


    /************读取xml文件*************/
    bool readXML();


private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
public:
    StudentData*studentData;
    int recordCount;
signals:
    void dataCount(int );
    void dataStruct(StudentData*);

};

#endif // WORKTHREAD_H
