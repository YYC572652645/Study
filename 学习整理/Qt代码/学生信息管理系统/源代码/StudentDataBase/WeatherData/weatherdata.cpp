#include "weatherdata.h"
#include "ui_weatherdata.h"

static int countFlage=0;

/***************************构造函数***********************/
WeatherData::WeatherData(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WeatherData)
{
    ui->setupUi(this);

    if(readXML())  //如果读取xml文件成功，则连接数据库
    {
        if( !dataCnn() )
        {
            qDebug()<<"失败";
        }
    }
    ui->labelZY->adjustSize();
    ui->labelZY->setWordWrap(true);
    ui->labelZY->setAlignment(Qt::AlignCenter);
    ui->labelCity->setAlignment(Qt::AlignCenter);
    ui->labelFengLi->setAlignment(Qt::AlignCenter);
    ui->labelFengXiang->setAlignment(Qt::AlignCenter);
    ui->labelTem->setAlignment(Qt::AlignCenter);
    ui->labelTemNow->setAlignment(Qt::AlignCenter);
    ui->labeltemp->setAlignment(Qt::AlignCenter);
    ui->labelTime->setAlignment(Qt::AlignCenter);
    ui->labelWeather->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_5->setAlignment(Qt::AlignCenter);
    ui->label_6->setAlignment(Qt::AlignCenter);
    ui->label_7->setAlignment(Qt::AlignCenter);
    ui->label_8->setAlignment(Qt::AlignCenter);
    ui->label_9->setAlignment(Qt::AlignCenter);
    manager = new QNetworkAccessManager(this);//创建网络获取数据对象
    QBrush qBrush(QColor(255,255,255,0));//设置背景色
    ui->customPlot->setBackground(qBrush);
    ui->customPlot->addGraph();
    ui->customPlot->yAxis->setRange(-40,40);
    ui->customPlot->xAxis->setRange(0,4);

    ui->customPlot->graph(0)->setPen(QPen(QColor(230, 20, 20),3));
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);

    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setPen(QPen(QColor(10, 220, 20),3));
    ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsLine);

    ui->customPlot->xAxis->setTickLength(5);
    ui->customPlot->replot();
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(GetWebJsonData(QNetworkReply *)));//请求完成后获取JSON数据

    //设置纵坐标
    ui->customPlot->xAxis->setAutoTicks(false);
    QVector<double>piTicks;
    piTicks<<0<<1<<2<<3<<4;
    ui->customPlot->xAxis->setTickVector(piTicks);

    ui->customPlot->addGraph();
    ui->customPlot->graph(2)->setPen(QColor(50, 50, 50, 255));
    ui->customPlot->graph(2)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(2)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 6));
    ui->customPlot->graph(2)->setPen(QPen(QColor(220, 100, 50),3));

    ui->customPlot->addGraph();
    ui->customPlot->graph(3)->setPen(QColor(50, 50, 50, 255));
    ui->customPlot->graph(3)->setLineStyle(QCPGraph::lsNone);
    ui->customPlot->graph(3)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 6));
    ui->customPlot->graph(3)->setPen(QPen(QColor(100, 200, 20),3));

    movie = new QMovie(":/new/prefix1/image/loading.gif");
    ui->labelZY->setMovie(movie);
    ui->labelCity->setMovie(movie);
    ui->labelFengLi->setMovie(movie);
    ui->labelFengXiang->setMovie(movie);
    ui->labelTem->setMovie(movie);
    ui->labelTemNow->setMovie(movie);
    ui->labeltemp->setMovie(movie);
    ui->labelTime->setMovie(movie);
    ui->labelWeather->setMovie(movie);
    movie->start();


    highTemp.resize(5);
    lowTemp.resize(5);
    dataX.resize(5);
    for(int i=0;i<5;i++)
    {
        dataX[i]=i;
    }

}


/***************************析构函数***********************/
WeatherData::~WeatherData()
{
    delete ui;
}


/***************************连接数据库*********************/
bool WeatherData::dataCnn()
{

    //是否为默认连接
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db=QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        db=QSqlDatabase::addDatabase(dataBaseVersion);         //设置数据库类型
    }

    db.setHostName(ip);                                        //设置数据库主机名
    db.setPort(port.toInt());                                  //设置端口
    db.setDatabaseName(dataBaseName);                          //设置数据库名
    db.setUserName(userName);                                  //设置用户名
    db.setPassword(passWord);                                  //设置密码
    //如果数据库处于打开状态，则关闭
    if(db.isOpen())
    {
        db.close();
    }
    bool ok=db.open();

    return ok;
}


/***************************查询数据***********************/
void WeatherData::selectData(QString cityName)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str;

    Str=QString("select citycode from citycode where cityname='%1';").arg(cityName);

    qDebug()<<Str;
    bool success=query.exec(Str);  //执行sql语句
    qDebug()<<success;
    if(!success)
    {
        return;
    }
    else
    {
        query.first();
        while(true)        //挨个遍历数据
        {
            cityNumber=query.value(0).toString();         //姓名
            if(!query.next())
            {
                break;
            }
        }
    }
    query.clear();
    db.close();
}


/***************************解析JSON数据*******************/
void WeatherData::analyseJson()
{
    QJsonParseError err;       //判断错误对象
    QJsonDocument doc = QJsonDocument::fromJson(weather,&err);   //得到JSON数据进document
    QJsonObject obj= doc.object().value("data").toObject();      //object()获得json最外面一层
    movie->stop();
    ui->labelCity->setText(doc.object().value("data").toObject().take("city").toString());
    ui->labelTemNow->setText(doc.object().value("data").toObject().take("wendu").toString()+"℃");
    ui->labelZY->setText(doc.object().value("data").toObject().take("ganmao").toString());


    //判断是否有元素forecast
    if (obj.contains("forecast"))
    {
        QJsonValue arraysValue = obj.take("forecast");
        if (arraysValue.isArray())
        {
            QJsonArray heeloArray = arraysValue.toArray();
            for (int i = 0; i < heeloArray.count(); i++)
            {
                QJsonValue helloArrayValue = heeloArray.at(i);
                QString strTemp=helloArrayValue.toObject().take("high").toString();
                strTemp.replace(QString("高温 "),QString(""));
                strTemp.replace(QString("℃"),QString(""));
                highTemp[i]=strTemp.toDouble();
                strTemp=helloArrayValue.toObject().take("low").toString();
                strTemp.replace(QString("低温 "),QString(""));
                strTemp.replace(QString("℃"),QString(""));
                lowTemp[i]=strTemp.toDouble();
                dataWeather[i].type=helloArrayValue.toObject().take("type").toString();
                dataWeather[i].date=helloArrayValue.toObject().take("date").toString();
                dataWeather[i].fengLi=helloArrayValue.toObject().take("fengli").toString();
                dataWeather[i].fengXiang=helloArrayValue.toObject().take("fengxiang").toString();
            }
        }
    }

    ui->customPlot->graph(0)->setData(dataX,highTemp);
    ui->customPlot->graph(1)->setData(dataX,lowTemp);
    ui->customPlot->graph(2)->setData(dataX,highTemp);
    ui->customPlot->graph(3)->setData(dataX,lowTemp);
    ui->labeltemp->setText(tr("%1").arg(highTemp[0]));
    ui->labelTem->setText(tr("%1").arg(lowTemp[0]));
    ui->labelTime->setText(dataWeather[0].date);
    ui->labelWeather->setText(dataWeather[0].type);
    ui->labelFengLi->setText(dataWeather[0].fengLi);
    ui->labelFengXiang->setText(dataWeather[0].fengXiang);
    ui->customPlot->yAxis->setRange(highTemp[0]-20,highTemp[0]+10);

    ui->customPlot->replot();
}


/*****************画图函数*****************************/
void WeatherData::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/new/prefix1/image/weather.jpg"));

    update();

}


/***************************获取天气数据*******************/
void WeatherData::getWeather(QString cityNumber)
{
    ui->labelZY->setMovie(movie);
    ui->labelCity->setMovie(movie);
    ui->labelFengLi->setMovie(movie);
    ui->labelFengXiang->setMovie(movie);
    ui->labelTem->setMovie(movie);
    ui->labelTemNow->setMovie(movie);
    ui->labeltemp->setMovie(movie);
    ui->labelTime->setMovie(movie);
    ui->labelWeather->setMovie(movie);
    movie->start();
    manager->get(QNetworkRequest(QUrl("http://wthrcdn.etouch.cn/weather_mini?citykey="+cityNumber)));     //发送get请求像中国天气网
}


/*****************获取JSON数据*****************************/
void WeatherData::GetWebJsonData(QNetworkReply *reply)
{
    weather=reply->readAll();  //获取网页数据
    strJson=QString(weather);
    //qDebug()<<strJson;
    analyseJson();             //解析JSON
}


/***************************读取xml文件********************/
bool WeatherData::readXML()
{
    int Count=0;
    QDomDocument dom;
    QFile *file=new QFile("data.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return false;
        }
    }
    else
    {
        return false;
    }
    file->close();
    QDomElement docElem=dom.documentElement();   //返回根元素
    QDomNode node=docElem.firstChild();          //返回根节点的第一个子节点

    while(!node.isNull())                        //如果节点不为空
    {
        if(node.isElement())                     //如果节点是元素
        {
            QDomElement element=node.toElement();//将其转化为元素
            QDomNodeList list=element.childNodes();//取出该元素的所有子节点放到list中

            //将子节点元素全部取出来
            for(int i=0;i<list.count();i++)
            {
                QDomNode domNode=list.at(i);
                if(domNode.isElement())
                {
                    //取出我们所要的数据
                    switch(i)
                    {
                    case 0:ip=domNode.toElement().text();break;
                    case 1:port=domNode.toElement().text();break;
                    case 2:dataBaseVersion=domNode.toElement().text();break;
                    case 3:dataBaseName=domNode.toElement().text();break;
                    case 4:userName=domNode.toElement().text();break;
                    case 5:passWord=domNode.toElement().text();break;
                    }
                }
            }
        }

        Count++;
        node=node.nextSibling(); //下一个兄弟节点
    }

    if(Count==1)
    {
        return true;
    }
    else
    {
        return false;
    }

}


/***************************查询天气***********************/
void WeatherData::on_pushButtonSelectData_clicked()
{
    this->selectData(ui->comboBoxCity->currentText());
    getWeather(cityNumber);
}


/***************************查询上一天天气***********************/
void WeatherData::on_pushButtonShang_clicked()
{
    if(countFlage==0)
    {
        ui->labeltemp->setText(tr("%1").arg(highTemp[countFlage]));
        ui->labelTem->setText(tr("%1").arg(lowTemp[countFlage]));
        ui->labelTime->setText(dataWeather[countFlage].date);
        ui->labelWeather->setText(dataWeather[countFlage].type);
        ui->labelFengLi->setText(dataWeather[countFlage].fengLi);
        ui->labelFengXiang->setText(dataWeather[countFlage].fengXiang);
        return;
    }
    else
    {
        countFlage--;
        ui->labeltemp->setText(tr("%1").arg(highTemp[countFlage]));
        ui->labelTem->setText(tr("%1").arg(lowTemp[countFlage]));
        ui->labelTime->setText(dataWeather[countFlage].date);
        ui->labelWeather->setText(dataWeather[countFlage].type);
        ui->labelFengLi->setText(dataWeather[countFlage].fengLi);
        ui->labelFengXiang->setText(dataWeather[countFlage].fengXiang);

    }

}

void WeatherData::on_pushButtonNext_clicked()
{
    if(countFlage==4)
    {
        ui->labeltemp->setText(tr("%1").arg(highTemp[countFlage]));
        ui->labelTem->setText(tr("%1").arg(lowTemp[countFlage]));
        ui->labelTime->setText(dataWeather[countFlage].date);
        ui->labelWeather->setText(dataWeather[countFlage].type);
        ui->labelFengLi->setText(dataWeather[countFlage].fengLi);
        ui->labelFengXiang->setText(dataWeather[countFlage].fengXiang);
        return;
    }
    else
    {
        countFlage++;
        ui->labeltemp->setText(tr("%1").arg(highTemp[countFlage]));
        ui->labelTem->setText(tr("%1").arg(lowTemp[countFlage]));
        ui->labelTime->setText(dataWeather[countFlage].date);
        ui->labelWeather->setText(dataWeather[countFlage].type);
        ui->labelFengLi->setText(dataWeather[countFlage].fengLi);
        ui->labelFengXiang->setText(dataWeather[countFlage].fengXiang);

    }
}
