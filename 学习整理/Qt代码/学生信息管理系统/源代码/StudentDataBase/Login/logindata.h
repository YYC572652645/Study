#ifndef LOGINDATA_H
#define LOGINDATA_H
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlError>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
#include<QDebug>
#include<QMessageBox>



class LoginData
{
public:


    /************构造函数*************/
    LoginData();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData(QString usm,QString psd);


    /************查询数据*************/
    bool backData(QString usm);


    /************数据库登陆验证********/
    bool dataSelect(QString studentUserName, QString studentPassWord);


    /************读取xml文件**********/
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
    QString backPassword;          //找回的密码


};

#endif // LOGINDATA_H
