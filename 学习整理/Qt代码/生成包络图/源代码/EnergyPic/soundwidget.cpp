#include "soundwidget.h"
#include "ui_soundwidget.h"


/**********************构造函数函数**********************/
SoundWidget::SoundWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SoundWidget)
{
    precision=0.01;
    ui->setupUi(this);

}


/**********************析构函数**********************/
SoundWidget::~SoundWidget()
{
    delete ui;
}


/**********************画图函数**********************/
void SoundWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen(QColor(100,100,100),1,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);

    painter.setRenderHint(QPainter::Antialiasing);//消锯齿
    int width=this->width();
    int height=this->height();


    /***************************画半直径刻度线**********************************/
    QRect rect;
    for(int i=0;i<15;i++)
    {
        painter.setPen(pen);
        rect.setRect(width*0.47-i*40,height*0.9-i*40,80+i*80,80+i*80);
        painter.drawPie(rect,0,180*16); //画半圆
        painter.setPen(Qt::black);      //设置画笔
        painter.drawText(width*0.47-567+i*40,height*0.9+50,tr("%1").arg(i*(-2)));//写刻度
        painter.drawText(width*0.47+635-i*40,height*0.9+50,tr("%1").arg(i*(-2)));//写刻度
    }

    painter.drawText(width*0.47-567,height*0.9+50,tr("0db"));//写刻度
    painter.drawText(width*0.47+635,height*0.9+50,tr("0db"));//写刻度
    painter.drawText(width*0.47+30,height*0.9+50,tr("-30db"));//写刻度
    painter.setPen(pen);//设置画笔
    for(int j=1;j<19;j++)
    {
        painter.drawPie(width*0.47-560,height*0.9-560,1200,1200,0,5*16*j);
        painter.drawPie(width*0.47-560,height*0.9-560,1200,1200,0,90*16+5*16*j);
    }


    QPen penTwo(Qt::black,2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(penTwo);//设置画笔
    painter.drawPie(width*0.47-560,height*0.9-560,1200,1200,0,5*16*18);
    painter.drawPie(width*0.47-560,height*0.9-560,1200,1200,0,90*16+5*16*18);


    /***************************画扇形刻度线**********************************/
    painter.drawText(width*0.47+670,height*0.9+45,"90º");
    painter.drawText(width*0.47+670-7,height*0.9+45-110,"80º");
    painter.drawText(width*0.47+670-38,height*0.9+45-218,"70º");
    painter.drawText(width*0.47+670-80,height*0.9+45-310,"60º");
    painter.drawText(width*0.47+670-150,height*0.9+45-410,"50º");
    painter.drawText(width*0.47+670-225,height*0.9+45-490,"40º");
    painter.drawText(width*0.47+670-318,height*0.9+45-555,"30º");
    painter.drawText(width*0.47+670-420,height*0.9+45-600,"20º");
    painter.drawText(width*0.47+670-530,height*0.9+45-630,"10º");
    painter.drawText(width*0.47+670-630,height*0.9+45-640,"0º");
    painter.drawText(width*0.47-610,height*0.9+45,"90º");
    painter.drawText(width*0.47-610+7,height*0.9+45-110,"80º");
    painter.drawText(width*0.47-610+38,height*0.9+45-218,"70º");
    painter.drawText(width*0.47-610+80,height*0.9+45-310,"60º");
    painter.drawText(width*0.47-610+150,height*0.9+45-410,"50º");
    painter.drawText(width*0.47-610+225,height*0.9+45-490,"40º");
    painter.drawText(width*0.47-610+318,height*0.9+45-555,"30º");
    painter.drawText(width*0.47-610+420,height*0.9+45-600,"20º");
    painter.drawText(width*0.47-610+530,height*0.9+45-630,"10º");


    painter.setPen(Qt::black);//设置画笔
    for(int i=1;i<=15;i++)
    {
        painter.drawText(width*0.47+45,height*0.9+50-i*40,tr("%1db").arg(i*2-30));
    }

    painter.translate(width*0.47+40,height*0.9+40);  //将（0，0）点变为原点



    QPainterPath path;

    QPen penThree(QColor(61,89,200),2,Qt::SolidLine,Qt::RoundCap,Qt::RoundJoin);
    painter.setPen(penThree);

    for(int i=0;i<dataAngle.count()-2;i+=2)
    {
        if(i+1==dataAngle.count()/2)
        {
            i++;
        }
        path.moveTo(20*sin((dataAngle[i]/180.)*M_PI)*(30+dataDb[i]),(30+dataDb[i])*(-20)*cos((dataAngle[i]/180.)*M_PI));
        path.cubicTo(20*sin((dataAngle[i]/180.)*M_PI)*(30+dataDb[i]),(30+dataDb[i])*(-20)*cos((dataAngle[i]/180.)*M_PI),20*sin((dataAngle[i+1]/180.)*M_PI)*(30+dataDb[i+1]),(30+dataDb[i+1])*(-20)*cos((dataAngle[i+1]/180.)*M_PI),20*sin((dataAngle[i+2]/180.)*M_PI)*(30+dataDb[i+2]),(30+dataDb[i+2])*(-20)*cos((dataAngle[i+2]/180.)*M_PI));

    }

    painter.drawPath(path);
    update();

}


/**********************计算系数**********************/
void SoundWidget::AllBernstein(int n, double u, double *B)
{
    B[0]=1.0;
    double u1=1.0-u;
    for(int j=1;j<=n;j++)
    {
        double saved=0.0;
        for(int k=0;k<j;k++)
        {
            double temp=B[k];
            B[k]=saved+u1*temp;
            saved=u*temp;
        }
        B[j]=saved;
    }
}


/**********************计算点************************/
QPoint SoundWidget::PointOnBezir(double u)
{
    int n=pointList.length();
    double *coefficient=new double[n];
    memset(coefficient,0,sizeof(coefficient));
    AllBernstein(n-1,u,coefficient);

    QPoint tempPoint(0.0,0.0);

    for(int i=0;i<pointList.length();i++)
    {
        QPoint temp=pointList.at(i);
        tempPoint=tempPoint+temp*coefficient[i];
    }
    return tempPoint;
}


/**********************设置时间**********************/
void SoundWidget::setPrecision(double precision)
{
    if(precision<1)
    {
        this->precision=precision;
    }
}


/**********************添加点**********************/
void SoundWidget::appendPoind(QPoint point)
{
    pointList.append(point);
}


/**********************得到路径**********************/
QPainterPath SoundWidget::getPainterPath()
{
    QPainterPath path;
    path.moveTo(pointList.at(0));

    for(double t=0;t<1;t+=precision)
    {
        QPoint pTemp=PointOnBezir(t);
        path.lineTo(pTemp);
    }
    return path;
}


