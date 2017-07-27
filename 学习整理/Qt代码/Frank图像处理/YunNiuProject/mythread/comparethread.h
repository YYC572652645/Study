#ifndef MYTHREAD_H
#define MYTHREAD_H

#include "globaldef.h"
#include <QThread>
#include <QImage>
#include <QMutex>

/***************************************************************
   功能:采用多线程进行图片比较

   创建人:殷宇辰

   创建时间:2017-7-10
**************************************************************/

class CompareThread : public QThread
{
    Q_OBJECT

public:

    void setTemplateImage(const QImage &value);  //源图

    void setCompareImage(const QImage &value);   //比较图

    void setContourType(int value);              //比较类型

    void setPointStr(const std::string &value);  //点数据

private:
    QImage templateImage;          //源图
    QImage compareImage;           //比较图
    int contourType;               //比较类型
    std::string pointStr;          //点数据

private:
    QMutex mutex;                  //互斥量
    void run();                    //线程函数
    void getInspectResultData();   //获取检测结果

signals:
    void sendString(int, QString, QString); //发送数据槽函数
};

#endif // MYTHREAD_H
