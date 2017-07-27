
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
typedef struct dataHonor
{
    QString name;          //姓名
    QString sex;           //性别
    QString number;        //学号
    QString profess;       //专业班级
    QString honorType;     //获奖种类
    QString honorLevel;    //获奖级别
    QString honorName;     //获奖名称
    QString honorTime;     //获奖时间
}dataHonor;




class HonorDataBase
{
public:
    /************构造函数*************/
    HonorDataBase();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    int selectData(QString studentNumber,QString studentName,QString studentClass);


    /************删除数据*************/
    bool deleteData( );


    /************读取xml文件**********/
    bool readXML();

public:
    QString number;        //学号
    QString honorType;     //获奖种类
    QString honorLevel;    //获奖级别
    QString honorName;     //获奖名称
    QString honorTime;     //获奖时间

    dataHonor*HonorMessage;
private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
};

