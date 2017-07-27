#include "DailyDataBase.h"


/***************************构造函数***********************/
DailyDataBase::DailyDataBase()
{

    if(readXML())  //如果读取xml文件成功，则连接数据库
    {
        if( !dataCnn() )
        {
            qDebug()<<"连接失败";
        }

    }
}


/***************************连接数据库*********************/
bool DailyDataBase::dataCnn()
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


/***************************插入数据***********************/
bool DailyDataBase::insertData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str=QString("insert into Daily values('%1','%2','%3');").arg(dorNumber,dorStatus,dorTime);

    bool success=query.exec(Str);  //执行sql语句
    if(!success)
    {
        qDebug()<<"false";
        return false;
    }
    else
    {
        qDebug()<<"success";
        return true;
    }
    query.clear();
    db.close();

}


/***************************查询数据***********************/
int DailyDataBase::selectData(QString dorNumber,QString dorStatus)
{

    int Count=0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str;
    if(!dorNumber.isEmpty())
    {
        Str=QString("select * from daily where 寝室号 like '%%1%';").arg(dorNumber);
    }
    else  if(!dorStatus.isEmpty())
    {
       Str=QString("select * from daily where 寝室状况 like '%%1%';").arg(dorStatus);
    }

    bool success=query.exec(Str);  //执行sql语句

    if(!success)
    {
        return -1;
    }
    else
    {

        if(query.last()!=NULL)
        {
            query.last();
            int num=query.at()+1;
            DailyMessage=new dataDaily[num];//创建动态结构体数组
        }
        else
        {
            return 0;
        }

        query.first();

        while(true)        //挨个遍历数据
        {
            DailyMessage[Count].dorNumber=query.value(0).toString();  //宿舍号
            DailyMessage[Count].dorStatus=query.value(1).toString();  //宿舍情况
            DailyMessage[Count].dorTime=query.value(2).toString();       //时间
            Count++;
            if(!query.next())
            {
                break;
            }
        }
    }
    query.clear();
    db.close();
    return Count;
}


/***************************删除数据***********************/
bool DailyDataBase::deleteData()
{

    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str=QString("delete from Daily where 寝室号='%1'and 时间='%2';").arg(dorNumber,dorTime);
    bool success=query.exec(Str);  //执行sql语句
    if(!success)
    {
        return false;
    }
    else
    {
        return true;
    }
    query.clear();
    db.close();

}


/***************************读取xml文件********************/
bool DailyDataBase::readXML()
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



