#include "database.h"
#include"qreadini.h"

/***************************构造函数***********************/
DataBase::DataBase()
{   
    if(!dataCnn())
    {
        qDebug()<<"连接失败";
    }
}

/***************************连接数据库*********************/
bool DataBase::dataCnn()
{
    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db = QSqlDatabase::addDatabase(DATACONFIG.dataBaseVersion);         //设置数据库类型
    }

    db.setHostName(DATACONFIG.ip);                                        //设置数据库主机名
    db.setPort(DATACONFIG.port.toInt());                                  //设置端口
    db.setDatabaseName(DATACONFIG.dataBaseName);                          //设置数据库名
    db.setUserName(DATACONFIG.userName);                                  //设置用户名
    db.setPassword(DATACONFIG.passWord);                                  //设置密码
    //如果数据库处于打开状态，则关闭
    if(db.isOpen())
    {
        db.close();
    }
    return db.open();
}

/***************************插入数据***********************/
bool DataBase::insertData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("insert into table values('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************查询数据***********************/
bool DataBase::selectData()
{
    int Count = 0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("select * from table;");
    bool success = query.exec(Str);  //执行sql语句
    if(!success)
    {
        return false;
    }
    else
    {
        while(query.next())        //挨个遍历数据
        {
            Count ++;
        }
    }
    db.close();

    return Count > 0 ? true : false;
}

/***************************更改数据***********************/
bool DataBase::updateData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("update  table set('','');");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

/***************************删除数据***********************/
bool DataBase::deleteData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str = QString("delete from table where ;");
    bool success = query.exec(Str);  //执行sql语句

    db.close();

    return success;
}

