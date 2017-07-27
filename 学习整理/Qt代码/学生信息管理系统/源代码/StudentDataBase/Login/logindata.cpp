#include "logindata.h"


/***************************构造函数***********************/
LoginData::LoginData()
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
bool LoginData::dataCnn()
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


/***************************注册帐号***********************/
bool LoginData::insertData(QString usm, QString psd)
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str=QString("insert into user values('%1','%1');").arg(usm).arg(psd);
    bool success=query.exec(Str);  //执行sql语句
    if(!success)
    {
        return false;
    }
    else
    {
       return true;
    }
    db.close();


}


/***************************找回密码***********************/
bool LoginData::backData(QString usm)
{
    int Count=0;
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str=QString("select * from user where username='%1';").arg(usm);
    bool success=query.exec(Str);  //执行sql语句
    if(!success)
    {
        return false;
    }
    else
    {
        while(query.next())        //挨个遍历数据
        {
            backPassword=query.value(1).toString();
            Count++;
        }
    }
    db.close();
    if(Count>0)
    {
        return true;
    }
    else
    {
        return false;
    }


}


/***************************数据库登录验证******************/
bool LoginData::dataSelect(QString studentUserName,QString studentPassWord)
{
    int Count=0;
    if(!db.isOpen())
    {
        db.open();
    }

    QSqlQuery query;
    QString Str=QString("select * from user where username='%1' and password='%2';").arg(studentUserName).arg(studentPassWord);
    bool success=query.exec(Str);  //执行sql语句

    if(!success)
    {
        return false;
    }
    else
    {
        while(query.next())        //挨个遍历数据
        {
            Count++;
        }
    }
    db.close();

    if(Count==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


/***************************读取xml文件********************/
bool LoginData::readXML()
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



