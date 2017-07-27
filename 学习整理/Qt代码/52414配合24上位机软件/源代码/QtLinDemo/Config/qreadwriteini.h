#ifndef QREADWRITEINI_H
#define QREADWRITEINI_H
#include<QSettings>

class QReadWriteIni
{
public:

    /****************构造函数***************/
    QReadWriteIni();

    /****************读取配置文件***************/
    void readIni();

    /****************写入配置文件***************/
    void writeIni();

    /****************删除配置文件***************/
    void deleteIni();

    static QReadWriteIni*getInstance();

public:
    static QReadWriteIni*instance;
    QString strPort;         //端口
    QString strBaud;         //波特率
    QString strData;         //数据位
    QString strCheck;        //校验位
    QString strStop;         //停止位
    QString strLinBaud;      //Lin波特率
    QString strLinChannel;   //Lin通道
    QString strLinPact;      //Lin协议
    QString strLinImp;       //Lin主机
    QString strLinSleep;     //Lin睡眠
    QString strLinWake;      //Lin唤醒
    int heightCar;           //汽车高度
};

#endif // QREADWRITEINI_H
