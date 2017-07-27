#include "StudentDataBase.h"


/***************************构造函数***********************/
StudentDataBase::StudentDataBase()
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
bool StudentDataBase::dataCnn()
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
bool StudentDataBase::insertData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str=QString("insert into student values('%1','%2','%3','%4','%5','%6','%7','%8','%9',").arg(name,sex,number,nation,bornDate,political,college,profess,nowClass);
    Str+=QString("'%1','%2','%3','%4','%5','%6','%7','%8','%9',").arg(dormNumber,bedNumber,cardNumber,bankNumber,phoneNumber,QQNumber, houseType, address, origin);
    Str+= QString("'%1','%2','%3','%4','%5','%6','%7','%8','%9',").arg(codeNumber,poverty,army,abord,goHome,goRead,single,fatherName,fatherNumber);
    Str+= QString("'%1','%2','%3','%4');").arg(fatherWork,motherName,motherNumber ,motherWork);

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
int StudentDataBase::selectData(QString studentNumber,QString studentName,QString studentClass)
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
        Str=QString("select * from student where 学号 like '%%1%';").arg(studentNumber);
    }
    else  if(!studentName.isEmpty())
    {
        Str=QString("select * from student where 姓名 like '%%1%';").arg(studentName);
    }
    else  if(!studentClass.isEmpty())
    {
        Str=QString("select * from student where 专业班级  like '%%1%';").arg(studentClass);
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
            studentMessage=new dataKnow[num];//创建动态结构体数组
            qDebug()<<num;
        }
        else
        {
            return 0;
        }
        query.first();
        while(true)        //挨个遍历数据
        {
            studentMessage[Count].name=query.value(0).toString();         //姓名
            studentMessage[Count].sex=query.value(1).toString();          //性别
            studentMessage[Count].number=query.value(2).toString();       //学号
            studentMessage[Count].nation=query.value(3).toString();       //民族
            studentMessage[Count].bornDate=query.value(4).toString();     //出生日期
            studentMessage[Count].political=query.value(5).toString();    //政治面貌
            studentMessage[Count].college=query.value(6).toString();      //学院
            studentMessage[Count].profess=query.value(7).toString();      //专业班级
            studentMessage[Count].nowClass=query.value(8).toString();     //当前所在班
            studentMessage[Count].dormNumber=query.value(9).toString();   //宿舍号
            studentMessage[Count].bedNumber=query.value(10).toString();   //床号
            studentMessage[Count].cardNumber=query.value(11).toString();  //身份证号
            studentMessage[Count].bankNumber=query.value(12).toString();  //银行卡号
            studentMessage[Count].phoneNumber=query.value(13).toString(); //联系电话
            studentMessage[Count].QQNumber=query.value(14).toString();    //QQ
            studentMessage[Count].houseType=query.value(15).toString();   //户口类型
            studentMessage[Count].address=query.value(16).toString();     //家庭住址
            studentMessage[Count].origin=query.value(17).toString();      //生源地
            studentMessage[Count].codeNumber=query.value(18).toString();  //邮编
            studentMessage[Count].poverty=query.value(19).toString();     //是否贫困
            studentMessage[Count].army=query.value(20).toString();        //是否服兵役
            studentMessage[Count].abord=query.value(21).toString();       //是否留学
            studentMessage[Count].goHome=query.value(22).toString();      //周末是否回家
            studentMessage[Count].goRead=query.value(23).toString();      //是否走读
            studentMessage[Count].single=query.value(14).toString();      //是否单亲
            studentMessage[Count].fatherName=query.value(25).toString();  //父亲姓名
            studentMessage[Count].fatherNumber=query.value(26).toString();//父亲联系电话
            studentMessage[Count].fatherWork=query.value(27).toString();  //父亲工作单位
            studentMessage[Count].motherName=query.value(28).toString();  //母亲姓名
            studentMessage[Count].motherNumber=query.value(29).toString();//母亲联系电话
            studentMessage[Count].motherWork=query.value(30).toString();  //母亲工作单位

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


/***************************更改数据***********************/
bool StudentDataBase::updateData()
{
    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;

    QString Str=QString("update student set 姓名='%1',性别 ='%2',学号='%3',民族 ='%4',出生年月 ='%5',政治面貌 ='%6',学院 ='%7',专业班级 ='%8',当前所在班 ='%9',").arg(name,sex,number,nation,bornDate,political,college,profess,nowClass);
    Str+=QString("宿舍号 ='%1',床号='%2',身份证号 ='%3',银行卡号 ='%4',邮编 ='%5',QQ ='%6',户口类型 ='%7',家庭住址 ='%8',生源地 ='%9',").arg(dormNumber,bedNumber,cardNumber,bankNumber,codeNumber,QQNumber, houseType, address, origin);
    Str+= QString("是否单亲 ='%1',是否贫困 ='%2',是否服兵役 ='%3',是否留学 ='%4',周末是否回家 ='%5',是否走读 ='%6',父亲姓名 ='%7',父亲联系电话 ='%8',父亲工作单位 ='%9',").arg(single,poverty,army,abord,goHome,goRead,fatherName,fatherNumber,fatherWork);
    Str+= QString("母亲姓名='%1',母亲联系电话 ='%2',母亲工作单位 ='%3',联系电话 ='%4' where 学号='%5';").arg(motherName,motherNumber ,motherWork,phoneNumber,number);
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


/***************************删除数据***********************/
bool StudentDataBase::deleteData()
{

    if(!db.isOpen())
    {
        db.open();
    }
    QSqlQuery query;
    QString Str=QString("delete from student where 学号='%1';").arg(number);
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
bool StudentDataBase::readXML()
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



