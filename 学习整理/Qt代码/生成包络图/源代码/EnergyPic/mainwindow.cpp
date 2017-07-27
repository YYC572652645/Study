#include "mainwindow.h"
#include "ui_mainwindow.h"

SoundWidget *sound;//Widget对象
/********************构造函数****************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("包络图")); //写标题
    this->setIconSize(QSize(30,30));   //定义图标大小
    this->setWindowIcon(QIcon(":/new/prefix1/logo1.png"));//设置软件图标
    ui->widget->installEventFilter(this);
    dataCount=0;
    dataCountEnergy=0;
    X=0;
    Y=0;
    flage=1;
}


/********************析构函数****************************/
MainWindow::~MainWindow()
{
    delete ui;
}


/********************画图*******************************/
void MainWindow::paintImage()
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
    X=(width-40)/50;
    Y=(height-35)/50;
    for(int i=1;i<50;i++)
    {
        painter->drawLine(30+X*i,6,30+X*i,height-31);
        painter->drawLine(31,5+Y*i,width-11,5+Y*i);
    }

    painter->setPen(QColor(0,0,0)); //设置画笔



    /**************************画刻度线****************************/
    for(int j=5;j>=0;j--)
    {
        painter->drawText(22+X*(25-5*j),height-17,QString::number(-j*0.5,'f',1));
        painter->drawText(10,8+Y*(50-j*5),QString::number(j*0.5,'f',1));

    }
    for(int j=1;j<=5;j++)
    {
        painter->drawText(22+X*(25+j*5),height-17,QString::number(j*0.5,'f',1));
        painter->drawText(10,8+Y*(25-j*5),QString::number(j*0.5+2.5,'f',1));
    }


    painter->translate(30+X*25,height-31);


    /************************绘制包络图**************************/
    for(int K=0;K<dataCount;K++)
    {

        if(dataEnergy[K]<50)
        {
            painter->setPen(QColor(61,89,50,125)); //设置画笔
            painter->setBrush(QColor(61,89,50,125));
        }
        else if(dataEnergy[K]>=50&&dataEnergy[K]<100)
        {
            painter->setPen(QColor(61,89,60,125)); //设置画笔
            painter->setBrush(QColor(61,89,60,125));
        }
        else if(dataEnergy[K]>=100&&dataEnergy[K]<150)
        {
            painter->setPen(QColor(61,89,70,125)); //设置画笔
            painter->setBrush(QColor(61,89,70,125));
        }

        else if(dataEnergy[K]>=150&&dataEnergy[K]<200)
        {
            painter->setPen(QColor(61,89,80,125)); //设置画笔
            painter->setBrush(QColor(61,89,80,125));
        }
        else if(dataEnergy[K]>=200&&dataEnergy[K]<250)
        {
            painter->setPen(QColor(61,89,90,125)); //设置画笔
            painter->setBrush(QColor(61,89,90,125));
        }
        else if(dataEnergy[K]>=250&&dataEnergy[K]<300 )
        {
            painter->setPen(QColor(61,89,100,125)); //设置画笔
            painter->setBrush(QColor(61,89,100,125));
        }
        else if(dataEnergy[K]>=300&&dataEnergy[K]<350)
        {
            painter->setPen(QColor(61,89,110,125)); //设置画笔
            painter->setBrush(QColor(61,89,110,125));
        }
        else if(dataEnergy[K]>=350&&dataEnergy[K]<400)
        {
            painter->setPen(QColor(61,89,120,125)); //设置画笔
            painter->setBrush(QColor(61,89,120,125));
        }
        else if(dataEnergy[K]>=400&&dataEnergy[K]<450)
        {
            painter->setPen(QColor(61,89,130,125)); //设置画笔
            painter->setBrush(QColor(61,89,130,125));
        }
        else if(dataEnergy[K]>=450&&dataEnergy[K]<500)
        {
            painter->setPen(QColor(61,89,140,125)); //设置画笔
            painter->setBrush(QColor(61,89,140,125));
        }
        else if(dataEnergy[K]>=500&&dataEnergy[K]<550)
        {
            painter->setPen(QColor(61,89,150,125)); //设置画笔
            painter->setBrush(QColor(61,89,150,125));
        }
        else if(dataEnergy[K]>=550&&dataEnergy[K]<600)
        {
            painter->setPen(QColor(61,89,160,125)); //设置画笔
            painter->setBrush(QColor(61,89,160,125));
        }
        else if(dataEnergy[K]>=600&&dataEnergy[K]<650)
        {
            painter->setPen(QColor(61,89,170,125)); //设置画笔
            painter->setBrush(QColor(61,89,170,125));
        }
        else if(dataEnergy[K]>=650&&dataEnergy[K]<700)
        {
            painter->setPen(QColor(61,89,180,125)); //设置画笔
            painter->setBrush(QColor(61,89,180,125));
        }
        else if(dataEnergy[K]>=700&&dataEnergy[K]<750)
        {
            painter->setPen(QColor(61,89,190,125)); //设置画笔
            painter->setBrush(QColor(61,89,190,125));
        }
        else if(dataEnergy[K]>=750&&dataEnergy[K]<800)
        {
            painter->setPen(QColor(61,89,200,125)); //设置画笔
            painter->setBrush(QColor(61,89,200,125));
        }
        else if(dataEnergy[K]>=800&&dataEnergy[K]<850)
        {
            painter->setPen(QColor(61,89,210,125)); //设置画笔
            painter->setBrush(QColor(61,89,210,125));
        }
        else if(dataEnergy[K]>=850&&dataEnergy[K]<900)
        {
            painter->setPen(QColor(61,89,220,125)); //设置画笔
            painter->setBrush(QColor(61,89,220,125));
        }
        else if(dataEnergy[K]>=900&&dataEnergy[K]<950)
        {
            painter->setPen(QColor(61,89,230,125)); //设置画笔
            painter->setBrush(QColor(61,89,230,125));
        }
        else if(dataEnergy[K]>=950&&dataEnergy[K]<1000)
        {
            painter->setPen(QColor(61,89,240,125)); //设置画笔
            painter->setBrush(QColor(61,89,240,125));
        }


        painter->drawEllipse(X*(dataX[K]/10.-0.5),-Y*(dataY[K]/10.+0.5),X,Y);
    }
    update();


}


/********************读取txt文档数据**********************/
void MainWindow::importTxt()
{
    /******************初始化数据********************/
    int Count=0;
    dataCount=0;
    dataX.clear();
    dataY.clear();
    dataEnergy.clear();

    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }

        QTextStream in(&file);         //定义读取文本对象
        QString line = in.readLine();  //读取一行数据
        dataX<<line.toInt();

        while (!line.isNull())
        {



            if(Count%3==0)
            {
                dataCount++;
            }

            line = in.readLine();

            switch (Count%3)
            {
            case 0:dataY<<line.toInt();      break;
            case 1:dataEnergy<<line.toInt(); break;
            case 2:dataX<<line.toInt();      break;
            }
            Count++;

        }

        file.close();
    }
}


/********************导入Excel数据***********************/
void MainWindow::importExcel()
{

    /******************初始化数据********************/
    int Count=0;
    dataCount=0;
    dataCountEnergy=0;
    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;
    dataX.clear();
    dataY.clear();
    angle.clear();
    db.clear();
    dataEnergy.clear();
    if(flage==2)
    {
        sound->dataAngle.clear();
        sound->dataDb.clear();
    }



    excel=new QAxObject("Excel.Application");      //加载Excel驱动
    excel->setProperty("Visible",false);           //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");



    if(!fileName.isEmpty())
    {
        workBooks->dynamicCall("Open(const QString &)",fileName);  //打开指定文件
        workBook=excel->querySubObject("ACtiveWorkBook");
        workSheets=workBook->querySubObject("Sheets");             //Sheets可换做WorkSheets
        int sheetCount=workSheets->property("Count").toInt();      //获取工作表数目


        if(sheetCount>0)
        {

            workSheet=workBook->querySubObject("Sheets(int)",1);        //读取第一个工作表中的内容
            QAxObject *usedRange=workSheet->querySubObject("UsedRange");//求出该表的数据的可用范围
            QAxObject *Rows=usedRange->querySubObject("Rows");          //创建行对象
            QAxObject *columns=usedRange->querySubObject("Columns");    //创建列对象
            int startRow=usedRange->property("Row").toInt();            //获取开始行
            int startColumn=usedRange->property("Column").toInt();      //获取开始列
            int rowCount=Rows->property("Count").toInt();               //获取总共多少行
            int columnCount=columns->property("Count").toInt();         //获取总共多少列


            /*******************************获取单元格中数据***************************/
            for(int i=startRow+1;i<startRow+rowCount;i++)
            {
                for(int j=startColumn;j<startColumn+columnCount;j++)
                {

                    QAxObject *cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据
                    QVariant cellValue=cell->property("Value");                      //得到单元格值


                    if(flage==1)
                    {
                        if(columnCount!=3)
                        {
                            QMessageBox::warning(this,tr("系统提示"),tr("导入格式不正确"));
                            workBook->dynamicCall("Close(Boolen)",false);  //关闭
                            excel->dynamicCall("Quit(void)");              //退出
                            return;
                        }
                        if(Count%3==0)
                        {
                            dataCount++;
                        }
                        if(j==startColumn)
                        {
                            dataX<<cellValue.toInt();
                        }
                        else if(j==startColumn+1)
                        {
                            dataY<<cellValue.toInt();
                        }
                        else if(j==startColumn+2)
                        {
                            dataEnergy<<cellValue.toInt();
                        }
                        Count++;
                    }
                    else if(flage==2)
                    {
                        if(columnCount!=2)
                        {
                            QMessageBox::warning(this,tr("系统提示"),tr("导入格式不正确"));
                            workBook->dynamicCall("Close(Boolen)",false);  //关闭
                            excel->dynamicCall("Quit(void)");              //退出
                            return;
                        }
                        if(Count%2==0)
                        {
                            dataCountEnergy++;
                        }
                        if(j==startColumn)
                        {
                            sound->dataAngle<<cellValue.toInt();
                            angle<<cellValue.toInt();
                        }
                        else if(j==startColumn+1)
                        {
                            db<<cellValue.toFloat();
                            if(cellValue.toFloat()<0)
                            {
                                sound->dataDb<<cellValue.toFloat();
                            }
                            else
                            {
                                sound->dataDb<<0;

                            }
                        }

                        Count++;
                    }
                }
            }
        }
        workBook->dynamicCall("Close(Boolen)",false);  //关闭
        excel->dynamicCall("Quit(void)");              //退出

    }


}


/********************导出Excel***************************/
void MainWindow::extendExcel()
{
    /******************初始化数据********************/
    int Count=0;
    dataCount=0;
    dataCountEnergy=0;
    excel=NULL;
    workBooks=NULL;
    workBook=NULL;
    workSheets=NULL;
    workSheet=NULL;


    fileName=QFileDialog::getSaveFileName(NULL,tr("保存文件"),".","Excel(*.xlsx *.xls)");
    if(fileName.isEmpty())
    {
        return;
    }


    excel=new QAxObject("Excel.Application");      //加载Excel驱动
    excel->setProperty("Visible",false);           //不显示任何警告信息
    workBooks=excel->querySubObject("WorkBooks");


    workBooks->dynamicCall("Add");
    workBook=excel->querySubObject("ActiveWorkBook");

    workSheets=workBook->querySubObject("Sheets");             //Sheets可换做WorkSheets


    workSheet=workBook->querySubObject("Sheets(int)",1);        //读取第一个工作表中的内容
    if(flage==1)
    {
        QAxObject *cell=workSheet->querySubObject("Cells(int,int)",1,1); //循环获取单元格中数据
        cell->setProperty("Value","横坐标"); //写单元格值
        cell->clear();
        cell=workSheet->querySubObject("Cells(int,int)",1,2); //循环获取单元格中数据
        cell->setProperty("Value","纵坐标"); //写单元格值
        cell->clear();
        cell=workSheet->querySubObject("Cells(int,int)",1,3); //循环获取单元格中数据
        cell->setProperty("Value","能量");   //写单元格值


        /*******************************获取单元格中数据***************************/
        for(int i=2;i<dataX.count();i++)
        {
            for(int j=1;j<4;j++)
            {


                cell->clear();
                cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据
                if(dataCount>0)
                {
                    if(Count%3==0)
                    {

                        dataCount++;
                    }
                }


                switch(j)
                {
                case 1:cell->setProperty("Value",dataX[dataCount]);     break;//写单元格值
                case 2:cell->setProperty("Value",dataY[dataCount]);     break;//写单元格值
                case 3:cell->setProperty("Value",dataEnergy[dataCount]);break;//写单元格值
                }


                if(Count==2)
                {
                    dataCount++;
                }
                Count++;
            }
        }
    }
    else if(flage==2)
    {
        QAxObject *cell=workSheet->querySubObject("Cells(int,int)",1,1); //循环获取单元格中数据
        cell->setProperty("Value","角度"); //写单元格值
        cell->clear();
        cell=workSheet->querySubObject("Cells(int,int)",1,2); //循环获取单元格中数据
        cell->setProperty("Value","db值"); //写单元格值


        /*******************************获取单元格中数据***************************/
        for(int i=2;i<=angle.count()+1;i++)
        {
            for(int j=1;j<3;j++)
            {
                cell->clear();
                cell=workSheet->querySubObject("Cells(int,int)",i,j); //循环获取单元格中数据

                switch(j)
                {
                case 1:cell->setProperty("Value",angle[dataCountEnergy]);  break;//写单元格值
                case 2:cell->setProperty("Value",db[dataCountEnergy]);     break;//写单元格值
                }


            }
            dataCountEnergy++;
        }
    }
    workBook->dynamicCall("SaveAs(const Qstring&)",QDir::toNativeSeparators(fileName));//保存文件
    workBook->dynamicCall("Close(Boolen)",false);  //关闭
    excel->dynamicCall("Quit(void)");              //退出


    QMessageBox::about(this,tr("提示"),tr("导出Excel成功"));
}


/********************鼠标放置响应*************************/
bool MainWindow::event(QEvent *e)
{
    if(e->type()==QEvent::ToolTip)
    {

        QPoint point=ui->widget->cursor().pos()-this->pos();
        float pointX=(point.x()-50-25*X)/X;
        float pointY=(point.y()-86-50*Y)/Y;
        if(pointX>0)
        {
            pointX=pointX+0.3;
        }
        int dataXWanted=static_cast<int>(pointX)*10;
        int dataYWanted=static_cast<int>(pointY)*(-10);
        int wantedCount=-1;
        for(int i=0;i<dataX.count();i++)
        {
            if(dataXWanted==dataX[i])
            {
                for(int j=0;j<dataY.count();j++)
                {
                    if(i==j)
                    {
                        if(dataYWanted==dataY[j])
                        {
                            wantedCount=i;
                        }
                    }
                }

            }
        }
        QRect rect(QRect(ui->widget->cursor().pos().x(),ui->widget->cursor().pos().y(),10,20));
        if(wantedCount!=-1)
        {
            QToolTip::showText(ui->widget->cursor().pos(), tr("能量:%1").arg(dataEnergy[wantedCount]),ui->widget,rect,700);
        }
        else
        {
            ui->widget->setToolTip(tr(""));
        }
    }
    return QMainWindow::event(e);
}


/********************重写函数****************************/
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==ui->widget&&event->type()==QEvent::Paint)
    {
        paintImage();
    }
    return QWidget::eventFilter(watched,event);
}


/********************读取信息响应函数**********************/
void MainWindow::on_actionRead_triggered()
{

    fileName=QFileDialog::getOpenFileName(this,tr("打开文件对话框"),"/","excel(*.xlsx *.xls);;txt(*.txt)");//获取路径
    QFileInfo fileInfo;                    //读取文件后缀名
    fileInfo=QFileInfo(fileName);
    QString suffixName=fileInfo.suffix();  //获取文件后缀名
    if(suffixName.isEmpty())
    {
        return;
    }


    if(suffixName==tr("xlsx")||suffixName==tr("xls"))
    {

        importExcel();
    }
    else if(suffixName=="txt")
    {
        importTxt();
    }

}


/********************导出Excel响应函数*********************/
void MainWindow::on_actionExtend_triggered()
{
    extendExcel();
}


/********************距离包络图***************************/
void MainWindow::on_actionDistance_triggered()
{

    flage=1;

    if( this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);//释放setCentralWidget的所有权
    }

    this->setCentralWidget(ui->centralWidget);
}


/********************声压包络图***************************/
void MainWindow::on_actionSound_triggered()
{
    flage=2;
    sound=new SoundWidget();      //定义画图对象

    if( this->centralWidget())
    {
        this->centralWidget()->setParent(NULL);//释放setCentralWidget的所有权
    }
    this->setCentralWidget(sound);
}
