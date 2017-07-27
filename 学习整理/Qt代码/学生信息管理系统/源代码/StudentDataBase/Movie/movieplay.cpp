#include "movieplay.h"
#include "ui_movieplay.h"
static int countClickPlay=0;
static int countClickHide=0;
static int countClickVideo=0;
static int countClickSpace=0;
static bool pressFlag=false;
static bool volumFlag=false;
static int countClickVolum=0;
static int second=0;
static int minite=0;
MoviePlay::MoviePlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoviePlay)
{
    ui->setupUi(this);

    readXml();//读取xml文件
    ui->listWidget->setFrameShape(QFrame::NoFrame);//设置控件无边框
    ui->frame->setFrameShape(QFrame::NoFrame);     //设置面板无边框

    player = new QMediaPlayer;       //新建播放对象
    videoWidget = new QVideoWidget;  //创建视频widget

    //设置视频背景为黑色
    QPalette *palette=new QPalette();
    palette->setBrush(QPalette::Background,Qt::black);
    videoWidget->setPalette(*palette);
    videoWidget->setAutoFillBackground(true);

    //设置视频播放在视频控件上
    player->setVideoOutput(videoWidget);

    //注册监听对象
    videoWidget->installEventFilter(this);
    connect(player,SIGNAL(positionChanged(qint64 )),this,SLOT(valueChange(qint64 )));

    //垂直布局
    vBoxLayout=new QVBoxLayout(ui->groupBox);
    vBoxLayout->addWidget(videoWidget);
    videoWidget->show();
    ui->horizontalSlider->setObjectName(tr("mySlider"));
    ui->horizontalSlider_2->setObjectName(tr("sliderVolum"));
    ui->horizontalSlider_2->setValue(50);
}

MoviePlay::~MoviePlay()
{
    delete ui;
}


/*************************播放暂停******************************/
void MoviePlay::on_pushButtonStop_clicked()
{
    if(player->isVideoAvailable())
    {
        countClickPlay++;
        if(countClickPlay%2==0)
        {
            player->play();
            ui->pushButtonStop->setIcon(QIcon(":/new/prefix1/image/media-pause-32.png"));
            ui->pushButtonStop->setToolTip(tr("暂停"));
        }
        else
        {
            player->pause();
            ui->pushButtonStop->setIcon(QIcon(":/new/prefix1/image/play.ico"));
            ui->pushButtonStop->setToolTip(tr("播放"));
        }
    }
    else
    {
        return;
    }
}


/*************************播放列表隐藏******************************/
void MoviePlay::on_pushButtonHide_clicked()
{
    countClickHide++;
    if(countClickHide%2==0)
    {
        ui->groupBox_3->show();
        ui->pushButtonHide->setIcon(QIcon(":/new/prefix1/image/right.ico"));
        ui->pushButtonHide->setToolTip(tr("隐藏播放列表"));

    }
    else
    {
        ui->groupBox_3->hide();
        player->mutedChanged(true);
        ui->pushButtonHide->setIcon(QIcon(":/new/prefix1/image/rrow.ico"));

        ui->pushButtonHide->setToolTip(tr("显示播放列表"));
    }
}


/*************************打开文件******************************/
void MoviePlay::on_pushButtonFile_clicked()
{

    QString fileName=QFileDialog::getOpenFileName(this,tr("打开文件对话框"),"/","");//获取路径
    QFileInfo fileInfo=QFileInfo(fileName);                                       //取文件名称
    ui->listWidget->addItem(fileInfo.baseName()+"."+fileInfo.suffix());           //设置文件名
    player->setMedia(QUrl::fromLocalFile(fileName));
    filePath<<fileName;
    writeXml(fileName);
    player->play();
    ui->pushButtonStop->setToolTip(tr("暂停"));
    ui->pushButtonStop->setIcon(QIcon(":/new/prefix1/image/media-pause-32.png"));
}


/*************************播放列表被双击******************************/
void MoviePlay::on_listWidget_doubleClicked(const QModelIndex &index)
{ 
    player->setMedia(QUrl::fromLocalFile(filePath[index.row()]));
    player->play();//播放
    ui->pushButtonStop->setToolTip(tr("暂停"));
    ui->pushButtonStop->setIcon(QIcon(":/new/prefix1/image/media-pause-32.png"));
}


/*************************事件函数******************************/
bool MoviePlay::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==videoWidget&&event->type()==QEvent::MouseButtonDblClick)
    {
        countClickVideo++;
        if(countClickVideo%2==0)
        {
            videoWidget->setFullScreen(false);  //退出全屏
        }
        else
        {
            videoWidget->setFullScreen(true);   //全屏
        }
    }

    return QWidget::eventFilter(watched,event);
}


/*************************电影播放改变横拉条的位置*****************/
void MoviePlay::valueChange(qint64 position)
{
    if(position<player->duration())
    {
        ExchangeTime(position/1000);
        if(second<10&&minite<10)
        {
            ui->labelCurrentTime->setText(tr("0%1:0%2").arg(minite).arg(second));
        }
        else if(second<10)
        {
            ui->labelCurrentTime->setText(tr("%1:0%2").arg(minite).arg(second));
        }
        else if(minite<10)
        {
            ui->labelCurrentTime->setText(tr("0%1:%2").arg(minite).arg(second));
        }
        else
        {
            ui->labelCurrentTime->setText(tr("%1:%2").arg(minite).arg(second));
        }
        ExchangeTime(player->duration()/1000);
        if(second<10&&minite<10)
        {
            ui->labelTotalTime->setText(tr("0%1:0%2").arg(minite).arg(second));
        }
        else if(second<10)
        {
            ui->labelTotalTime->setText(tr("%1:0%2").arg(minite).arg(second));
        }
        else if(minite<10)
        {
            ui->labelTotalTime->setText(tr("0%1:%2").arg(minite).arg(second));
        }
        else
        {
            ui->labelTotalTime->setText(tr("%1:%2").arg(minite).arg(second));
        }
        ui->horizontalSlider->setRange(0,player->duration()/1000); //设置横拉条的范围
        ui->horizontalSlider->setValue(position/1000);             //设置当前横拉条位置
    }
}


/*************************清空函数******************************/
void MoviePlay::on_pushButtonZXMovie_clicked()
{
    filePath.clear();         //清空播放列表路径
    ui->listWidget->clear();  //清空播放列表
    player->stop();           //播放停止
    deletetXml();
    ui->pushButtonStop->setIcon(QIcon(":/new/prefix1/image/play.ico"));
    ui->pushButtonStop->setToolTip(tr("播放"));
}


/*************************滑动横拉条视频快进*********************/
void MoviePlay::on_horizontalSlider_valueChanged(int value)
{
    if(player->isVideoAvailable())
    {
        if(pressFlag)
        {
            player->setPosition(value*1000);   //拉横拉条时设置视频的播放位置
        }
    }
    else
    {
        ui->horizontalSlider->setValue(0);
    }
}


/*************************快进函数******************************/
void MoviePlay::on_pushButtonKuaiTui_clicked()
{
    if(player->isVideoAvailable())
    {
        //快进5秒
        ui->horizontalSlider->setValue(ui->horizontalSlider->value()+5);
        player->setPosition((ui->horizontalSlider->value()+5)*1000);
    }
}


/*************************横拉条被点击******************************/
void MoviePlay::on_horizontalSlider_sliderPressed()
{
    if(player->isVideoAvailable())
    {
        pressFlag=true;
    }
    else
    {
        pressFlag=false;
    }
}


/*************************点击被释放******************************/
void MoviePlay::on_horizontalSlider_sliderReleased()
{
    pressFlag=false;
}


/*************************快退函数******************************/
void MoviePlay::on_pushButtonSpeed_clicked()
{
    if(player->isVideoAvailable())
    {
        //快退5秒
        if(ui->horizontalSlider->value()>=5)
        {
            ui->horizontalSlider->setValue(ui->horizontalSlider->value()-5);
            player->setPosition((ui->horizontalSlider->value()-5)*1000);
        }
    }
}


/***************写xml文件*********************/
void MoviePlay::writeXml(QString strFile)
{

    QFile file("playlist.xml");
    QDomDocument dom;

    if(file.open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(&file))  //将该xml文件导入到dom中
        {
            file.close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file.close();

    //创建一个新的用户
    QDomElement root=dom.documentElement();
    QDomElement user=dom.createElement("user");          //创建节点
    QDomAttr    id=dom.createAttribute("id");            //创建节点属性
    QDomElement play=dom.createElement("play");        //创建子节点

    QDomText text;
    QString num;
    if(root.lastChild().toElement().attribute("id").isNull())
    {
        num="0";
    }
    else
    {
        num=root.lastChild().toElement().attribute("id");  //获取xml文件最后一个id的大小是多少
    }
    int count=num.toInt()+1;
    id.setValue(QString::number(count));                       //将id+1后添加到新建的用户中
    user.setAttributeNode(id);

    //将用户名写入XML文件中
    text=dom.createTextNode(strFile);
    play.appendChild(text);

    //将所有节点依次对应写到根节点的目录下
    user.appendChild(play);
    root.appendChild(user);

    QFile f("playlist.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();
}


/***************读取xml文件*******************/
void MoviePlay::readXml()
{
    QDomDocument dom;
    QFile *file=new QFile("playlist.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
        }
    }

    file->close();
    QDomElement docElem=dom.documentElement();    //返回根元素

    QDomNode node=docElem.firstChild();           //返回根节点的第一个子节点

    while(!node.isNull())                         //如果节点不为空
    {
        if(node.isElement())                      //如果节点是元素
        {
            QDomElement element=node.toElement(); //将其转化为元素

            QDomNodeList list=element.childNodes();//取出该元素的所有子节点放到list中

            //将子节点元素全部取出来
            for(int i=0;i<list.count();i++)
            {
                QDomNode domNode=list.at(i);
                if(domNode.isElement())
                {
                    //将获取的数据一次存储到list列表中
                    switch(i)
                    {
                    case 0:
                        filePath<<domNode.toElement().text();
                        QFileInfo fileInfo=QFileInfo(domNode.toElement().text());                                       //取文件名称
                        ui->listWidget->addItem(fileInfo.baseName()+"."+fileInfo.suffix());           //设置文件名
                        break;
                    }
                }
            }
        }
        node=node.nextSibling(); //下一个兄弟节点
    }

}


/***************删除xml节点********************/
void MoviePlay::deletetXml()
{
    QDomDocument dom;
    QFile *file=new QFile("playlist.xml");
    if(file->open(QIODevice::ReadOnly))
    {
        if(!dom.setContent(file))  //将该xml文件导入到dom中
        {
            file->close();
            return ;
        }
    }
    else
    {
        return ;
    }
    file->close();

    QDomNodeList nodeList=dom.elementsByTagName("user");   //返回根元素
    //以标签名进行查找
    for(int i=0;i<nodeList.count();i++)
    {
        QDomElement e=nodeList.at(i).toElement();

        //判断如果最小时间日期的属性ID，与xml文件的属性ID相同时，删除
        qDebug()<<e.attribute("id").toInt();
        if(e.attribute("id").toInt()>=0)
        {
            QDomElement root=dom.documentElement();   //取出根节点
            root.removeChild(nodeList.at(i));         //删除整个节点
        }
    }


    QFile f("playlist.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}


/***************时间更改********************/
void MoviePlay::ExchangeTime(int duration)
{
    second=duration%60;
    minite=duration/60;
}


void MoviePlay::on_pushButtonStop_2_clicked()
{
    if(player->isVideoAvailable())
    {
        player->stop();
    }
}

void MoviePlay::on_pushButtonSound_clicked()
{
    if(player->isVideoAvailable())
    {
        countClickVolum++;
        if(countClickVolum%2==0)
        {
            ui->pushButtonSound->setToolTip("静音");
            player->setVolume(ui->horizontalSlider_2->value());
            ui->pushButtonSound->setIcon(QIcon(":/new/prefix1/image/sound.png"));
        }
        else
        {
            player->setVolume(0);
            volumFlag=true;
            ui->pushButtonSound->setToolTip("取消静音");
            ui->pushButtonSound->setIcon(QIcon(":/new/prefix1/image/nosound.png"));
        }
    }
}

void MoviePlay::on_horizontalSlider_2_sliderMoved(int position)
{
    if(player->isVideoAvailable())
    {
        if(volumFlag)
        {
            return;
        }
        else
        {
            player->setVolume(position);
        }
    }
    else
    {
        ui->horizontalSlider_2->setValue(50);
    }

}
