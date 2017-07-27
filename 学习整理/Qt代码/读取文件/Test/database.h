#ifndef DATABASE_H
#define DATABASE_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QFile>
#include<QIODevice>
#include<QDebug>

class DataBase
{
public:
    /************构造函数*************/
    DataBase();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    bool selectData();


    /************更改数据*************/
    bool updateData();


    /************删除数据*************/
    bool deleteData();


private:
    QSqlDatabase db;               //定义数据库对象
};

#endif // DATABASE_H
