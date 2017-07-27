#include "qreadwriteini.h"

QReadWriteIni*QReadWriteIni::instance=NULL;//静态对象初始化

/****************构造函数******************/
QReadWriteIni::QReadWriteIni()
{

}

/****************读取配置文件***************/
void QReadWriteIni::readIni()
{
    QSettings * configIniRead=new QSettings("config.ini",QSettings::IniFormat);//初始化读取Ini文件对象
    strPort=configIniRead->value("conn/strPort").toString();              //端口
    strBaud=configIniRead->value("conn/strBaud").toString();              //波特率
    strData=configIniRead->value("conn/strData").toString();              //数据位
    strCheck=configIniRead->value("conn/strCheck").toString();            //校验位
    strStop=configIniRead->value("conn/strStop").toString();              //停止位
    strLinBaud=configIniRead->value("conn/strLinBaud").toString();        //Lin波特率
    strLinChannel=configIniRead->value("conn/strLinChannel").toString();  //Lin通道
    strLinPact=configIniRead->value("conn/strLinPact").toString();        //Lin协议
    strLinImp=configIniRead->value("conn/strLinImp").toString();          //Lin主机
    strLinSleep=configIniRead->value("conn/strLinSleep").toString();      //Lin睡眠
    strLinWake=configIniRead->value("conn/strLinWake").toString();        //Lin唤醒
    heightCar=configIniRead->value("conn/heightCar").toInt();             //汽车位置
    delete configIniRead;
}

/****************写入配置文件***************/
void QReadWriteIni::writeIni()
{
    QSettings * configIniWrite=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象

    configIniWrite->setValue("conn/strPort",strPort);              //端口
    configIniWrite->setValue("conn/strBaud",strBaud);              //波特率
    configIniWrite->setValue("conn/strData",strData);              //数据位
    configIniWrite->setValue("conn/strCheck",strCheck);            //校验位
    configIniWrite->setValue("conn/strStop",strStop);              //停止位
    configIniWrite->setValue("conn/strLinBaud",strLinBaud);        //Lin波特率
    configIniWrite->setValue("conn/strLinChannel",strLinChannel);  //Lin通道
    configIniWrite->setValue("conn/strLinPact",strLinPact);        //Lin协议
    configIniWrite->setValue("conn/strLinImp",strLinImp);          //Lin主机
    configIniWrite->setValue("conn/strLinSleep",strLinSleep);      //Lin睡眠
    configIniWrite->setValue("conn/strLinWake",strLinWake);        //Lin唤醒

    delete configIniWrite;
}


/****************删除配置文件***************/
void QReadWriteIni::deleteIni()
{
    QSettings * configIniDelete=new QSettings("config.ini",QSettings::IniFormat);//初始化写入Ini文件对象
    configIniDelete->remove("conn/ip");              //IP地址
    configIniDelete->remove("conn/port");            //端口
    configIniDelete->remove("conn/databaseversion"); //数据库版本
    configIniDelete->remove("conn/databasename");    //数据库名称
    configIniDelete->remove("conn/username");        //用户名
    configIniDelete->remove("data/password");        //密码
    delete configIniDelete;
}


/****************获得静态对象***************/
QReadWriteIni *QReadWriteIni::getInstance()
{
    if(instance==NULL)
    {
        instance=new QReadWriteIni();  //创建静态对象
    }
    return instance;
}
