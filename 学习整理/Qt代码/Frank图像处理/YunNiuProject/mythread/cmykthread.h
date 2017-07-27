#ifndef CMYKTHREAD_H
#define CMYKTHREAD_H

#include <QObject>
#include <QThread>
#include <QImage>

/***************************************************************
   功能:采用多线程转换CMYK格式

   创建人:殷宇辰

   创建时间:2017-7-17
**************************************************************/

class CmykThread : public QThread
{
    Q_OBJECT
  public:
    void run();

    void getRgbToCmykImage(QImage &image, int option, int type);      //RGB转CMYK

    void setOption(int value);                  //设置选项类型

    void setResultImage(const QImage &value);   //设置结果图

    void setTargetImage(const QImage &value);   //设置目标图

    void setSourceImage(const QImage &value);   //设置源图

signals:
    void sendCmykImage(QImage, QImage, QImage); //发送线程数据

private:
    int option;
    QImage sourceImage;  //源图
    QImage targetImage;  //目标图
    QImage resultImage;  //结果图
    QMutex mutex;        //互斥锁
};
#endif // CMYKTHREAD_H
