#include "qsoundrout.h"
#include "ui_qsoundrout.h"
static float X=0;
static float Y=0;
int tempOne=0;
int tempTwo=0;
QSoundRout::QSoundRout(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QSoundRout)
{
    ui->setupUi(this);
    flage=false;
    ui->widget->installEventFilter(this);
    this->setWindowTitle(tr("声波路径"));
    this->setMinimumSize(700,500);
    this->showFullScreen();
}

QSoundRout::~QSoundRout()
{
    delete ui;
}


/*************************事件函数******************************/
bool QSoundRout::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->widget&&event->type()==QEvent::Paint)
    {
        paintImage();
    }
    if(watched==ui->widget&&event->type()==QEvent::MouseButtonPress)
    {
        mousePress();
    }
    return QWidget::eventFilter(watched,event);
}


/*************************画图函数******************************/
void QSoundRout::paintImage()
{
    QPainter *painter=new QPainter(ui->widget);//画图对象
    float width=ui->widget->width();
    float height=ui->widget->height();

    /**************************画直角坐标系****************************/
    painter->setPen(QColor(0,0,0));           //设置画笔
    painter->drawLine(30,5,width-10,5);
    painter->drawLine(30,5,30,height-30);
    painter->drawLine(width-10,5,width-10,height-30);
    painter->drawLine(30,height-30,width-10,height-30);
    painter->setPen(QColor(200,200,200));
    X=(width-40)/52;
    Y=(height-35)/60;
    for(int i=1;i<60;i++)
    {
        painter->drawLine(31,5+Y*i,width-11,5+Y*i);
    }
    for(int i=1;i<52;i++)
    {
        painter->setPen(QColor(200,200,200));
        painter->drawLine(30+X*i,6,30+X*i,height-31);
        if(i%2==0&&i!=26)
        {
            painter->setPen(Qt::black);
            painter->drawLine(30+X*i,6,30+X*i,height-31);
        }
        if(i%26==0)
        {
            painter->setPen(QPen(Qt::darkRed,2));
            
            painter->drawLine(30+X*i,6,30+X*i,height-31);
        }
    }
    painter->setPen(QColor(0,0,0)); //设置画笔
    
    /**************************画刻度线****************************/
    painter->translate(30,height-31);
    for(int j=1;j<=30;j++)
    {
        if(j<10)
        {
            painter->drawText(-16,5-Y*2*j,QString::number(j*10,'f',0));
        }
        else
        {
            painter->drawText(-20,5-Y*2*j,QString::number(j*10,'f',0));
        }
    }
    
    painter->translate(X*26,0);
    for(int i=0;i<=26;i++)
    {
        if(i%2==0)
        {
            painter->drawText(-10-X*i,20,QString::number((i*5),'f',0));
        }
        if(i%2==0&&i!=0)
        {
            painter->drawText(-10+X*i,20,QString::number((i*5),'f',0));
        }
        
    }



    painter->drawImage(-11+X*5,-10,QImage(":/new/prefix1/image/about.png"));
    painter->drawImage(-12+X*-5,-10,QImage(":/new/prefix1/image/about.png"));
    painter->drawImage(-11+X*15,-10,QImage(":/new/prefix1/image/about.png"));
    painter->drawImage(-12+X*-15,-10,QImage(":/new/prefix1/image/about.png"));

    dataFlage.clear();
    dataFlageSecond.clear();
    dataCount.clear();
    if(dataX.count()>0)
    {
        for(int i=0;i<dataX.count();i++)
        {
            painter->setPen(QPen(Qt::yellow,2));
            float disLeft=sqrt(((dataX[i]*X)-X*-15)*((dataX[i]*X)-X*-15)+(dataY[i]*-Y)*(dataY[i]*-Y));
            float disLeftCenter=sqrt(((dataX[i]*X)-X*-5)*((dataX[i]*X)-X*-5)+(dataY[i]*-Y)*(dataY[i]*-Y));
            float disRightCenter=sqrt(((dataX[i]*X)-X*5)*((dataX[i]*X)-X*5)+(dataY[i]*-Y)*(dataY[i]*-Y));
            float disRight=sqrt(((dataX[i]*X)-X*15)*((dataX[i]*X)-X*15)+(dataY[i]*-Y)*(dataY[i]*-Y));

            float angleLeft=atan(qAbs(dataY[i]*-Y)/qAbs(dataX[i]*X-X*-15))*180/3.1415;
            float angleLeftCenter=atan(qAbs(dataY[i]*-Y)/qAbs(dataX[i]*X-X*-5))*180/3.1415;
            float angleRightCenter=atan(qAbs(dataY[i]*-Y)/qAbs(dataX[i]*X-X*5))*180/3.1415;
            float angleRight=atan(qAbs(dataY[i]*-Y)/qAbs(dataX[i]*X-X*15))*180/3.1415;

            if(disLeft<60*Y&&angleLeft>35)
            {
                painter->drawLine(X*-15,0,(dataX[i]*X),(dataY[i]*Y));
            }
            if(disLeftCenter<60*Y&&angleLeftCenter>35)
            {
                painter->drawLine(X*-5,0,(dataX[i]*X),(dataY[i]*Y));
            }
            if(disRightCenter<60*Y&&angleRightCenter>35)
            {
                painter->drawLine(X*5,0,(dataX[i]*X),(dataY[i]*Y));
            }
            if(disRight<60*Y&&angleRight>35)
            {
                painter->drawLine(X*15,0,(dataX[i]*X),(dataY[i]*Y));
            }

            if(flage)
            {
                if(i==0)
                {
                    if(disLeft<60*Y&&angleLeft>35)
                    {
                        dataFlage<<1;
                    }
                    if(disLeftCenter<60*Y&&angleLeftCenter>35)
                    {
                        dataFlage<<2;
                    }
                    if(disRightCenter<60*Y&&angleRightCenter>35)
                    {
                        dataFlage<<3;
                    }
                    if(disRight<60*Y&&angleRight>35)
                    {
                        dataFlage<<4;
                    }
                }
                if(i==1)
                {
                    if(disLeft<60*Y&&angleLeft>35)
                    {
                        dataFlageSecond<<1;
                    }
                    if(disLeftCenter<60*Y&&angleLeftCenter>35)
                    {
                        dataFlageSecond<<2;
                    }
                    if(disRightCenter<60*Y&&angleRightCenter>35)
                    {
                        dataFlageSecond<<3;
                    }
                    if(disRight<60*Y&&angleRight>35)
                    {
                        dataFlageSecond<<4;
                    }


                    for(int k=0;k<dataFlage.count();k++)
                    {
                        for(int j=0;j<dataFlageSecond.count();j++)
                        {
                            if(dataFlage[k]==dataFlageSecond[j])
                            {
                                dataCount<<dataFlage[k];
                            }
                        }
                    }

                    if(dataCount.count()<2)
                    {
                        break;
                    }
                    else
                    {

                        if(dataCount.count()==2)
                        {
                            if(dataCount[0]==1&&dataCount[1]==2)
                            {
                                tempOne=-5;
                                tempTwo=-15;
                            }
                            else if(dataCount[0]==2&&dataCount[1]==3)
                            {
                                tempOne=5;
                                tempTwo=-5;
                            }
                            else if(dataCount[0]==3&&dataCount[1]==4)
                            {
                                tempOne=15;
                                tempTwo=5;
                            }
                        }
                        if(dataCount.count()==3)
                        {
                            if(dataCount[0]==0&&dataCount[1]==1&&dataCount[2]==2)
                            {
                                tempOne=-5;
                                tempTwo=-15;
                            }
                            else  if(dataCount[0]==1&&dataCount[1]==2&&dataCount[2]==3)
                            {
                                tempOne=5;
                                tempTwo=-5;
                            }
                        }
                        if(dataCount.count()==4)
                        {
                            if(dataCount[0]==0&&dataCount[1]==1&&dataCount[2]==2&&dataCount[3]==4)
                            {
                                tempOne=5;
                                tempTwo=-5;
                            }
                        }

                        painter->drawLine(X*tempOne,0,(dataX[1]*X),(dataY[1]*Y));
                        painter->drawLine(X*tempTwo,0,(dataX[1]*X),(dataY[1]*Y));
                        painter->drawLine(X*tempTwo,0,(dataX[0]*X),(dataY[0]*Y));
                        painter->drawLine((dataX[0]*X),(dataY[0]*Y),(dataX[1]*X),(dataY[1]*Y));
                        painter->drawLine((dataX[1]*X),(dataY[1]*Y),X*tempOne,0);

                        float a1=sqrt(((dataX[0]*X)-X*tempTwo)*((dataX[0]*X)-X*tempTwo)+(dataY[0]*-Y)*(dataY[0]*-Y));
                        float b1=a1+sqrt(((dataX[0]*X)-X*tempOne)*((dataX[0]*X)-X*tempOne)+(dataY[0]*-Y)*(dataY[0]*-Y));
                        float a2=sqrt(((dataX[1]*X)-X*tempTwo)*((dataX[1]*X)-X*tempTwo)+(dataY[1]*-Y)*(dataY[1]*-Y));
                        float b2=a2+sqrt(((dataX[1]*X)-X*tempOne)*((dataX[1]*X)-X*tempOne)+(dataY[1]*-Y)*(dataY[1]*-Y));

                        if((10*X+a2)>(b1-a2))
                        {
                            painter->setPen(QPen(Qt::green,2,Qt::DashLine));

                            painter->drawEllipse(X*tempTwo-a1,-a1,a1*2,a1*2);
                            painter->drawEllipse(X*tempTwo-a2,-a2,a2*2,a2*2);
                            painter->setPen(QPen(Qt::blue,2,Qt::DashLine));
                            qDebug()<<tempOne<<tempTwo;
                            painter->drawEllipse((tempOne+tempTwo)/2*X-b1/2,0-sqrt((b1/2)*(b1/2)-qAbs(tempOne-tempTwo)/2*qAbs(tempOne-tempTwo)/2*X*X),b1,2*sqrt((b1/2)*(b1/2)-qAbs(tempOne-tempTwo)/2*qAbs(tempOne-tempTwo)/2*X*X));
                            painter->drawEllipse((tempOne+tempTwo)/2*X-b2/2,0-sqrt((b2/2)*(b2/2)-qAbs(tempOne-tempTwo)/2*qAbs(tempOne-tempTwo)/2*X*X),b2,2*sqrt((b2/2)*(b2/2)-qAbs(tempOne-tempTwo)/2*qAbs(tempOne-tempTwo)/2*X*X));

                            painter->setBrush(QColor(139,0,0,80));
                            painter->setPen(QPen(Qt::yellow,2,Qt::DashLine));
                            float cosB=(a2*a2+(tempOne-tempTwo)*(tempOne-tempTwo)*X*X-(b1-a2)*(b1-a2))/(2*a2*(tempOne-tempTwo)*X);

                            if(1-cosB*cosB>0)
                            {
                                float sinB=sqrt(1-cosB*cosB);
                                painter->drawEllipse(tempTwo*X+(a2*cosB)-10,((a2)*-sinB)-10,20,20);
                                painter->drawLine(X*tempOne,0,tempTwo*X+(a2*cosB),((a2)*-sinB));
                                painter->drawLine(X*tempTwo,0,tempTwo*X+(a2*cosB),((a2)*-sinB));
                            }

                            cosB=(a1*a1+(tempOne-tempTwo)*(tempOne-tempTwo)*X*X-(b2-a1)*(b2-a1))/(2*a1*(tempOne-tempTwo)*X);
                            if(1-cosB*cosB>0)
                            {
                                float sinB=sqrt(1-cosB*cosB);
                                painter->drawEllipse(tempTwo*X+(a1*cosB)-10,((a1)*-sinB)-10,20,20);
                                painter->drawLine(X*tempOne,0,tempTwo*X+(a1*cosB),((a1)*-sinB));
                                painter->drawLine(X*tempTwo,0,tempTwo*X+(a1*cosB),((a1)*-sinB));
                            }
                        }
                    }
                }
            }
        }
    }

    painter->setBrush(Qt::darkRed);
    for(int i=0;i<dataX.count();i++)
    {
        painter->drawEllipse(QPoint((dataX[i]*X),(dataY[i]*Y)),10,10);
    }


    QRadialGradient radiaGradient(-15*X,0,60*Y,-15*X,0);
    radiaGradient.setColorAt(0.1,QColor(200,0,0,50));
    radiaGradient.setColorAt(0.7,QColor(200,200,0,50));
    radiaGradient.setColorAt(0.9,QColor(30,144,255,50));
    painter->setBrush(radiaGradient);
    painter->setPen(QColor(30,144,255,125));

    /*****************************最左边点********************************/
    QRect rectLeft(-15*X-60*Y,-60*Y,120*Y,120*Y);//画一个矩形域
    QPointF centerLeft(-15*X,0);                 //圆弧的圆心坐标
    QPainterPath myPathLeft;                     //设置路径
    myPathLeft.moveTo(centerLeft);               //将点移动到圆心
    myPathLeft.arcTo(rectLeft,35,110);           //从圆心画圆弧
    painter->drawPath(myPathLeft);


    QRadialGradient radiaGradientCenter(-5*X,0,60*Y,-5*X,0);
    radiaGradientCenter.setColorAt(0.1,QColor(200,0,0,50));
    radiaGradientCenter.setColorAt(0.7,QColor(200,200,0,50));
    radiaGradientCenter.setColorAt(0.9,QColor(30,144,255,50));
    painter->setBrush(radiaGradientCenter);
    painter->setPen(QColor(30,144,255,125));


    /*****************************左边点********************************/
    QRect rectLeftCenter(-5*X-60*Y,-60*Y,120*Y,120*Y);//画一个矩形域
    QPointF centerLeftCenter(-5*X,0);                 //圆弧的圆心坐标
    QPainterPath myPathLeftCenter;                    //设置路径
    myPathLeftCenter.moveTo(centerLeftCenter);        //将点移动到圆心
    myPathLeftCenter.arcTo(rectLeftCenter,35,110);    //从圆心画圆弧
    painter->drawPath(myPathLeftCenter);



    QRadialGradient radiaGradientRightCenter(5*X,0,60*Y,5*X,0);
    radiaGradientRightCenter.setColorAt(0.1,QColor(200,0,0,50));
    radiaGradientRightCenter.setColorAt(0.7,QColor(200,200,0,50));
    radiaGradientRightCenter.setColorAt(0.9,QColor(30,144,255,50));
    painter->setBrush(radiaGradientRightCenter);
    painter->setPen(QColor(30,144,255,125));


    /*****************************右边点********************************/
    QRect rectRightCenter(5*X-60*Y,-60*Y,120*Y,120*Y);//画一个矩形域
    QPointF centerRightCenter(5*X,0);                 //圆弧的圆心坐标
    QPainterPath myPathRightCenter;                    //设置路径
    myPathRightCenter.moveTo(centerRightCenter);        //将点移动到圆心
    myPathRightCenter.arcTo(rectRightCenter,35,110);    //从圆心画圆弧
    painter->drawPath(myPathRightCenter);



    QRadialGradient radiaGradientRight(15*X,0,60*Y,15*X,0);
    radiaGradientRight.setColorAt(0.1,QColor(200,0,0,50));
    radiaGradientRight.setColorAt(0.7,QColor(200,200,0,50));
    radiaGradientRight.setColorAt(0.9,QColor(30,144,255,50));
    painter->setBrush(radiaGradientRight);
    painter->setPen(QColor(30,144,255,125));


    /*****************************最右边点********************************/
    QRect rectRight(15*X-60*Y,-60*Y,120*Y,120*Y);//画一个矩形域
    QPointF centerRight(15*X,0);                 //圆弧的圆心坐标
    QPainterPath myPathRight;                    //设置路径
    myPathRight.moveTo(centerRight);        //将点移动到圆心
    myPathRight.arcTo(rectRight,35,110);    //从圆心画圆弧
    painter->drawPath(myPathRight);

    painter->end();
    update();
}

void QSoundRout::mousePress()
{
    QPoint point=ui->widget->cursor().pos()-this->pos();
    float pointX=(point.x()-41-26*X)/X;
    float pointY=(point.y()-16-60*Y)/Y;
    
    if(pointX>0)
    {
        pointX+=0.5;
    }
    else
    {
        pointX-=0.5;
    }
    if(pointY<0)
    {
        pointY-=0.5;
    }
    
    if(dataX.count()>0)
    {
        if(dataX.last()==static_cast<int>(pointX)&&dataY.last()==static_cast<int>(pointY))
        {
            return;
        }
    }
    dataX<<static_cast<int>(pointX);
    dataY<<static_cast<int>(pointY);
}

void QSoundRout::on_pushButtonClear_clicked()
{
    flage=false;
    dataX.clear();
    dataY.clear();
}

void QSoundRout::on_pushButtonExit_clicked()
{
    this->close();
}

void QSoundRout::screenRGB()
{
    int x=QCursor::pos().x();
    int y=QCursor::pos().y();
    QPixmap pix= QPixmap::grabWindow(QApplication::desktop()->winId(),x,y,1,1);

    if(!pix.isNull())
    {
        QImage image=pix.toImage();
        if(!image.isNull())
        {
            if(image.valid(0,0))
            {
                //color=image.pixel(0,0);
                //qDebug()<<color.red()<<color.green()<<color.blue();
            }

        }
    }
}

void QSoundRout::on_pushButton_clicked()
{
    if(dataX.count()>=2)
    {
        flage=true;
        int Max=dataY[0];
        int secondMax=dataY[1];
        int MinValue=0;
        int secondMinValue=0;
        for(int i=0;i<dataY.count();i++)
        {
            //求出最大值
            if(Max<dataY[i])
            {
                secondMax=Max;
                Max=dataY[i];
                MinValue=i;
            }
            //求出次大值
            else if(Max>dataY[i]&&dataY[i]>secondMax)
            {
                secondMax=dataY[i];
                secondMinValue=i;
            }
        }
        if(secondMinValue==0&&MinValue==0)
        {
            secondMinValue=1;
        }

        //将X的最大值和次大值临时保存
        int XMax=dataX[MinValue];
        int XSecondMax=dataX[secondMinValue];

        //清空list
        dataX.clear();
        dataY.clear();

        //将临时存储的数据放到list中
        dataX<<XMax<<XSecondMax;
        dataY<<Max<<secondMax;
    }

}
