#include "paintwidget.h"
#include "ui_paintwidget.h"


/********************构造函数********************/
PaintWidget::PaintWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PaintWidget)
{
    ui->setupUi(this);
}


/********************析构函数********************/
PaintWidget::~PaintWidget()
{
    delete ui;
}



/********************画图函数********************/
void PaintWidget::paintEvent(QPaintEvent*event)
{
    QImage img;
    img.load(":/new/prefix1/car/car3.png"); //加载图片
    QPainter painter(this);      //在widget上绘制
    painter.setBrush(Qt::black);            //设置画刷
    painter.drawRect(0,0,this->width(),this->height()); //画一个矩形域，与控件大小相同
    int pointX=this->width()*0.5-0.55*img.width();                 //汽车图片的横坐标
    int pointY=this->height()*0.5-0.6*img.height();                //汽车图片纵坐标
    painter.translate(pointX+0.45*img.width()+10,pointY+0.34*img.height()-10);//将该点变为直角坐标系的原点


    /*********************************************************包络图第一层******************************************************/

    /*****************************设置参数********************************/
    int valueX=-150;
    int valueY=-150;
    int valueArea=300;
    int startAngle=60;
    int rangeAngle=60;


    QRadialGradient radiaGradient(0,0,150,0,0);
    radiaGradient.setColorAt(0.1,QColor(200,0,0,125));
    radiaGradient.setColorAt(0.7,QColor(200,200,0,125));
    radiaGradient.setColorAt(0.9,QColor(30,144,255,125));
    painter.setBrush(radiaGradient);
    painter.setPen(QColor(30,144,255,125));

    /*****************************画车前方包络图********************************/
    QRect rectLeft(valueX,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerLeft(0,0);                          //圆弧的圆心坐标
    QPainterPath myPathLeft;                          //设置路径
    myPathLeft.moveTo(centerLeft);                    //将点移动到圆心
    myPathLeft.arcTo(rectLeft,startAngle+15,60);      //从圆心画圆弧
    painter.drawPath(myPathLeft);                     //画出图形


    radiaGradient.setCenter(30,-9);
    radiaGradient.setFocalPoint(30,-9);
    painter.setBrush(radiaGradient);
    painter.setBrush(radiaGradient);        //设置画刷
    QRect rectLeftCenter(valueX+30,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerLeftCenter(30,-9);                           //圆弧的圆心坐标
    QPainterPath myPathLeftCenter;                             //设置路径
    myPathLeftCenter.moveTo(centerLeftCenter);                 //将点移动到圆心
    myPathLeftCenter.arcTo(rectLeftCenter,startAngle,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathLeftCenter);                          //画出图形


    radiaGradient.setCenter(60,-9);
    radiaGradient.setFocalPoint(60,-9);
    painter.setBrush(radiaGradient);
    QRect rectRightCenter(valueX+60,valueY,valueArea,valueArea);   //画一个矩形域
    QPointF centerRightCenter(60,-9);                              //圆弧的圆心坐标
    QPainterPath myPathRightCenter;                                //设置路径
    myPathRightCenter.moveTo(centerRightCenter);                   //将点移动到圆心
    myPathRightCenter.arcTo(rectRightCenter,startAngle,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathRightCenter);                           //画出图形


    radiaGradient.setCenter(88,1);
    radiaGradient.setFocalPoint(88,1);
    painter.setBrush(radiaGradient);
    QRect rectRight(valueX+88,valueY,valueArea,valueArea);//画一个矩形域
    QPointF centerRight(88,1);                            //圆弧的圆心坐标
    QPainterPath myPathRight;                             //设置路径
    myPathRight.moveTo(centerRight);                      //将点移动到圆心
    myPathRight.arcTo(rectRight,startAngle-15,rangeAngle);//从圆心画圆弧
    painter.drawPath(myPathRight);





    /*****************************设置参数********************************/
    valueX=-150;
    valueY=-150;
    valueArea=300;



    /*****************************画车后方包络图********************************/
    QPainter painterTail(this);
    painterTail.translate(pointX+0.45*img.width()+10,pointY+0.9*img.height()-10);
    painterTail.setPen(QColor(30,144,255,125));


    radiaGradient.setCenter(0,0);
    radiaGradient.setFocalPoint(0,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRight(valueX,valueY,valueArea,valueArea);         //画一个矩形域
    QPointF centerTailRight(0,0);                                   //圆弧的圆心坐标
    QPainterPath myPathTailRight;                                   //设置路径
    myPathTailRight.moveTo(centerTailRight);                        //将点移动到圆心
    myPathTailRight.arcTo(rectTailRight,180+startAngle,rangeAngle); //从圆心画圆弧
    painterTail.drawPath(myPathTailRight);                          //画出图形


    radiaGradient.setCenter(30,0);
    radiaGradient.setFocalPoint(30,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailLeftCenter(valueX+30,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailLeftCenter(30,0);                                       //圆弧的圆心坐标
    QPainterPath myPathTailLeftCenter;                                        //设置路径
    myPathTailLeftCenter.moveTo(centerTailLeftCenter);                        //将点移动到圆心
    myPathTailLeftCenter.arcTo(rectTailLeftCenter,180+startAngle,rangeAngle); //从圆心画圆弧
    painterTail.drawPath(myPathTailLeftCenter);                               //画出图形


    radiaGradient.setCenter(60,0);
    radiaGradient.setFocalPoint(60,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailRightCenter(valueX+60,valueY,valueArea,valueArea);           //画一个矩形域
    QPointF centerTailRightCenter(60,0);                                       //圆弧的圆心坐标
    QPainterPath myPathTailRightCenter;                                        //设置路径
    myPathTailRightCenter.moveTo(centerTailRightCenter);                       //将点移动到圆心
    myPathTailRightCenter.arcTo(rectTailRightCenter,180+startAngle,rangeAngle);//从圆心画圆弧
    painterTail.drawPath(myPathTailRightCenter);                               //画出图形


    radiaGradient.setCenter(90,0);
    radiaGradient.setFocalPoint(90,0);
    painterTail.setBrush(radiaGradient);
    QRect rectTailLeft(valueX+90,valueY,valueArea,valueArea);        //画一个矩形域
    QPointF centerTailLeft(90,0);                                    //圆弧的圆心坐标
    QPainterPath myPathTailLeft;                                     //设置路径
    myPathTailLeft.moveTo(centerTailLeft);                           //将点移动到圆心
    myPathTailLeft.arcTo(rectTailLeft,180+startAngle,rangeAngle);    //从圆心画圆弧
    painterTail.drawPath(myPathTailLeft);                            //画出图形






    /*****************************设置参数********************************/
    valueX=-200;
    valueY=-200;
    valueArea=400;
    startAngle=60;
    rangeAngle=60;


    /*****************************画车左方包络图********************************/
    QPainter painterLeft(this);
    painterLeft.translate(pointX+0.44*img.width()+6,pointY+0.45*img.height()-10);
    painterLeft.setPen(QColor(30,144,255,125));

    radiaGradient.setCenter(0,-30);
    radiaGradient.setFocalPoint(0,-30);
    painterLeft.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarLeft(valueX,valueY-30,valueArea,valueArea);          //画一个矩形域
    QPointF centerCarLeft(0,-30);                                     //圆弧的圆心坐标
    QPainterPath myPathCarLeft;                                       //设置路径
    myPathCarLeft.moveTo(centerCarLeft);                              //将点移动到圆心
    myPathCarLeft.arcTo(rectCarLeft,90+startAngle,rangeAngle);        //从圆心画圆弧
    painterLeft.drawPath(myPathCarLeft);                              //画出图形


    radiaGradient.setCenter(0,180);
    radiaGradient.setFocalPoint(0,180);
    painterLeft.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarLeftLast(valueX,valueY+180,valueArea,valueArea);     //画一个矩形域
    QPointF centerCarLeftLast(0,180);                                 //圆弧的圆心坐标
    QPainterPath myPathCarLeftLast;                                   //设置路径
    myPathCarLeftLast.moveTo(centerCarLeftLast);                      //将点移动到圆心
    myPathCarLeftLast.arcTo(rectCarLeftLast,90+startAngle,rangeAngle);//从圆心画圆弧
    painterLeft.drawPath(myPathCarLeftLast);                          //画出图形




    /*****************************设置参数********************************/
    valueX=-200;
    valueY=-200;
    valueArea=400;

    /*****************************画车右方包络图********************************/
    QPainter painterRight(this);
    painterRight.translate(pointX+0.61*img.width()+6,pointY+0.45*img.height()-10);
    painterRight.setPen(QColor(30,144,255,125));


    radiaGradient.setCenter(0,-30);
    radiaGradient.setFocalPoint(0,-30);
    painterRight.setBrush(radiaGradient);                               //设置画刷
    QRect rectCarRight(valueX,valueY-30,valueArea,valueArea);           //画一个矩形域
    QPointF centerCarRight(0,-30);                                      //圆弧的圆心坐标
    QPainterPath myPathCarRight;                                        //设置路径
    myPathCarRight.moveTo(centerCarRight);                              //将点移动到圆心
    myPathCarRight.arcTo(rectCarRight,270+startAngle,rangeAngle);       //从圆心画圆弧
    painterRight.drawPath(myPathCarRight);                              //画出图形


    radiaGradient.setCenter(0,180);
    radiaGradient.setFocalPoint(0,180);
    painterRight.setBrush(radiaGradient);                                  //设置画刷
    QRect rectCarRightLast(valueX,valueY+180,valueArea,valueArea);       //画一个矩形域
    QPointF centerCarRightLast(0,180);                                   //圆弧的圆心坐标
    QPainterPath myPathCarRightLast;                                     //设置路径
    myPathCarRightLast.moveTo(centerCarRightLast);                       //将点移动到圆心
    myPathCarRightLast.arcTo(rectCarRightLast,270+startAngle,rangeAngle);//从圆心画圆弧
    painterRight.drawPath(myPathCarRightLast);                           //画出图形


    QPainter painterLast(this);                            //在widget上绘制
    painterLast.drawImage(pointX,pointY,img);                         //将图片加载到界面上
    update();
}


/********************双击响应函数********************/
void PaintWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    this->close();
}



