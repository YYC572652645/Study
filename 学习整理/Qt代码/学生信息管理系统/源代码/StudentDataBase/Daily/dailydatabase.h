
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
typedef struct dataDaily
{
    QString dorNumber;     //宿舍号
    QString dorStatus;     //宿舍情况
    QString dorTime;       //时间
}dataDaily;




class DailyDataBase
{
public:
    /************构造函数*************/
    DailyDataBase();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    int selectData(QString dorNumber, QString dorStatus);


    /************删除数据*************/
    bool deleteData( );


    /************读取xml文件**********/
    bool readXML();

public:
    QString dorNumber;     //宿舍号
    QString dorStatus;     //宿舍情况
    QString dorTime;       //时间
    dataDaily*DailyMessage;
private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
};

