#include "workthread.h"

/***************************构造函数*************************/
WorkThread::WorkThread()
{
    if(readXML())  //如果读取xml文件成功，则连接数据库
    {
        if( !dataCnn() )
        {
            qDebug()<<"连接失败";
        }

    }
}


/***************************连接数据库************************/
bool WorkThread::dataCnn()
{
    //判断默认连接
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


/***************************读取xml文件***********************/
bool WorkThread::readXML()
{
    int Count=0;
    QDomDocument dom;
    QFile *file=new QFile("student.xml");
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


/***************************线程函数**************************/
void WorkThread::run()
{

   recordCount=dataSelectMessage();//查询数据库
   emit dataCount(recordCount);    //发送传送数据信号
   emit dataStruct(studentData);   //发送传送数据信号

}


/***************************查询数据库信息**********************/
int WorkThread::dataSelectMessage()
{
    int Count=0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    bool success=query.exec("select * from studentmessage;");  //执行sql语句
    if(!success)
    {
        return false;
    }
    else
    {
        studentData=new StudentData[query.record().count()];
        while(query.next())        //挨个遍历数据
        {
            studentData[Count].number=query.value(0).toString();
            studentData[Count].name=query.value(1).toString();
            studentData[Count].sex=query.value(2).toString();
            studentData[Count].age=query.value(3).toString();

            Count++;
        }
    }

    db.close();
    return Count;
}
