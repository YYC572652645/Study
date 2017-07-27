#include "cmykthread.h"
#include "globaldef.h"
#include "qnamespace.h"
#include <QTime>
#include <QDebug>

/************************    线程函数         ***************************************/
void CmykThread::run()
{
    getRgbToCmykImage(sourceImage, option, SOURCEIMAGE);
    getRgbToCmykImage(targetImage, option, RESULTIMAGE);
    getRgbToCmykImage(resultImage, option, IMAGEMAX);

    emit sendCmykImage(sourceImage, targetImage, resultImage);
}

/************************    Rgb转CMYK         ***************************************/
void CmykThread::getRgbToCmykImage(QImage &image, int option, int type)
{
    mutex.lock();
    QImage newImage(image.width(), image.height(), QImage::Format_ARGB32);
    if (!image.isNull())
    {
        QColor color;
        for (int x = 0; x < newImage.width(); x++)
        {
            for (int y = 0; y < newImage.height(); y++)
            {
                QColor oldColor = image.pixelColor(x, y).toCmyk();
                double doubleCyan = oldColor.cyan();
                double doubleMagenta = oldColor.magenta();
                double doubleYellow = oldColor.yellow();
                double doubleBlack = oldColor.black();
                switch (option)
                {
                case ZERO:    color = QColor::fromCmyk(0, 0, 0, 0);                                            break;
                case ONE:     color = QColor::fromCmyk(doubleCyan, 0, 0, 0);                                   break;
                case TWO:     color = QColor::fromCmyk(0, doubleMagenta, 0, 0);                                break;
                case THREE:   color = QColor::fromCmyk(0, 0, doubleYellow, 0);                                 break;
                case FOUR:    color = QColor::fromCmyk(0, 0, 0, doubleBlack);                                  break;
                case FIVE:    color = QColor::fromCmyk(doubleCyan, doubleMagenta, 0, 0);                       break;
                case SIX:     color = QColor::fromCmyk(doubleCyan, 0, doubleYellow, 0);                        break;
                case SEVEN:   color = QColor::fromCmyk(doubleCyan, 0, 0, doubleBlack);                         break;
                case EIGHT:   color = QColor::fromCmyk(0, doubleMagenta, doubleYellow, 0);                     break;
                case NINE:    color = QColor::fromCmyk(0, doubleMagenta, 0, doubleBlack);                      break;
                case TEN:     color = QColor::fromCmyk(0, 0, doubleYellow, doubleBlack);                       break;
                case ELEVEN:  color = QColor::fromCmyk(doubleCyan, doubleMagenta, doubleYellow, 0);            break;
                case TWELVE:  color = QColor::fromCmyk(doubleCyan, doubleMagenta, 0, doubleBlack);             break;
                case THIRTEEN:color = QColor::fromCmyk(doubleCyan, 0, doubleYellow, doubleBlack);              break;
                case FOURTEEN:color = QColor::fromCmyk(0, doubleMagenta, doubleYellow, doubleBlack);           break;
                case FIFTEEN: color = QColor::fromCmyk(doubleCyan, doubleMagenta, doubleYellow, doubleBlack);  break;
                }
                newImage.setPixelColor(x, y, color);
            }
        }
    }

    switch(type)
    {
    case SOURCEIMAGE: sourceImage = newImage; break;
    case RESULTIMAGE: targetImage = newImage; break;
    case IMAGEMAX:    resultImage = newImage; break;
    }

    mutex.unlock();
}

/************************    设置选项类型         ***************************************/
void CmykThread::setOption(int value)
{
    option = value;
}

/************************    设置结果图         ***************************************/
void CmykThread::setResultImage(const QImage &value)
{
    resultImage = value;
}

/************************    设置目标图         ***************************************/
void CmykThread::setTargetImage(const QImage &value)
{
    targetImage = value;
}

/************************    设置源图         ***************************************/
void CmykThread::setSourceImage(const QImage &value)
{
    sourceImage = value;
}
