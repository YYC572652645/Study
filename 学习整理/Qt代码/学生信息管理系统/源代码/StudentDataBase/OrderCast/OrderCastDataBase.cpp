#include "OrderCastDataBase.h"


/***************************构造函数***********************/
OrderCastDataBase::OrderCastDataBase()
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
bool OrderCastDataBase::dataCnn()
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
bool OrderCastDataBase::insertData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str=QString("insert into rank values('%1','%2','%3','%4');").arg(number,OrderCastClass,OrderCastPro,OrderCastTime+OrderCastTerm);

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


/***************************查询数据***********************/
int OrderCastDataBase::selectData(QString studentNumber,QString studentName,QString studentClass)
{

    int Count=0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str;
    if(!studentNumber.isEmpty())
    {
        Str=QString("select student.姓名,student.性别,student.学号,student.专业班级,rank.班级排名,rank.专业排名,rank.时间 from rank,student where rank.学号=student.学号 and student.学号 like '%%1%';").arg(studentNumber);
    }
    else  if(!studentName.isEmpty())
    {
       Str=QString("select student.姓名,student.性别,student.学号,student.专业班级,rank.班级排名,rank.专业排名,rank.时间 from rank,student where rank.学号=student.学号 and  student.姓名 like '%%1%';").arg(studentName);
    }
    else  if(!studentClass.isEmpty())
    {
        Str=QString("select student.姓名,student.性别,student.学号,student.专业班级,rank.班级排名,rank.专业排名,rank.时间 from rank,student where rank.学号=student.学号 and student.专业班级 like '%%1%';").arg(studentClass);
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
            OrderCastMessage=new dataOrderCast[num];//创建动态结构体数组
        }
        else
        {
            return 0;
        }

        query.first();

        while(true)        //挨个遍历数据
        {
            OrderCastMessage[Count].name=query.value(0).toString();         //姓名
            OrderCastMessage[Count].sex=query.value(1).toString();          //性别
            OrderCastMessage[Count].number=query.value(2).toString();       //学号
            OrderCastMessage[Count].profess=query.value(3).toString();      //专业班级
            OrderCastMessage[Count].OrderCastClass=query.value(4).toString(); //班级排名
            OrderCastMessage[Count].OrderCastPro=query.value(5).toString(); //专业排名
            OrderCastMessage[Count].OrderCastTime=query.value(6).toString();   //年份
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
bool OrderCastDataBase::deleteData()
{

    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str=QString("delete from rank where 学号='%1' and 时间='%3';").arg(number).arg(OrderCastTime);
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
bool OrderCastDataBase::readXML()
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



