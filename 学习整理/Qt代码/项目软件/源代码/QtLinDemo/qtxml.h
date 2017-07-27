#ifndef QTXML_H
#define QTXML_H
#include <QString>
#include <QtXml>
#include <QIODevice>
#include <QDomNodeList>
#include <QFile>
#include <QDomDocument>
#include <QThread>
class QtXml
{
public:
    /**********************构造函数**********************/
    QtXml();

    /**********************更新xml文件********************/
    void updateXml();

    /**********************读取xml文件********************/
    bool readXML();
public:
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
    QString strLinMCheck[16];//选中
    QString strLinMID[16];   //ID号
    QString strLinMData[16]; //数据
    QString strLinMCount[16];//数据发送次数
    QString strLinSCheck[16];//选中
    QString strLinSID[16];   //ID号
    QString strLinSData[16]; //数据
};

#endif // QTXML_H


class  XmlThread:public QThread
{
private:
    QtXml *xml;
public:
    //构造函数
    XmlThread(QtXml *xml);

    //线程函数
    virtual void run();

};
