
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
typedef struct dataSchoolRool
{
    QString name;             //姓名
    QString sex;              //性别
    QString number;           //学号
    QString profess;          //专业班级
    QString SchoolRoolType;   //修复退种类
    QString SchoolRoolTime;   //时间
}dataSchoolRool;




class SchoolRoolDataBase
{
public:
    /************构造函数*************/
    SchoolRoolDataBase();


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
    QString number;           //学号
    QString SchoolRoolType;   //修复退种类
    QString SchoolRoolTime;   //时间


    dataSchoolRool*SchoolRoolMessage;
private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
};

