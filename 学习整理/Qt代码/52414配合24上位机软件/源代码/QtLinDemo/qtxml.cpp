#include "qtxml.h"


/***************************构造函数********************/
QtXml::QtXml()
{

}


/***************************读取xml文件********************/
bool QtXml::readXML()
{
    int Count=0;
    QDomDocument dom;
    QFile *file=new QFile("config.xml");
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

                    case 0:strPort=domNode.toElement().text();break;
                    case 1:strBaud=domNode.toElement().text();break;
                    case 2:strData=domNode.toElement().text();break;
                    case 3:strCheck=domNode.toElement().text();break;
                    case 4:strStop=domNode.toElement().text();break;
                    case 5:strLinBaud=domNode.toElement().text();break;
                    case 6:strLinChannel=domNode.toElement().text();break;
                    case 7:strLinPact=domNode.toElement().text();break;
                    case 8:strLinImp=domNode.toElement().text();break;
                    case 9:strLinSleep=domNode.toElement().text();break;
                    case 10:strLinWake=domNode.toElement().text();break;
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


/***************更新xml文件********************/
void QtXml::updateXml()
{

    QDomDocument dom;
    QFile *file=new QFile("config.xml");
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

    QDomNodeList nodeList=dom.elementsByTagName("configdata");   //返回根元素
    //以标签名进行查找
    for(int i=0;i<nodeList.count();i++)
    {


        QDomElement e=nodeList.at(i).toElement();
        if(e.attribute("id")=="1")
        {
            QDomNodeList child=nodeList.at(i).childNodes();        //找到它的所有子节点
            child.at(0).toElement().firstChild().setNodeValue(strPort);
            child.at(1).toElement().firstChild().setNodeValue(strBaud);
            child.at(2).toElement().firstChild().setNodeValue(strData);
            child.at(3).toElement().firstChild().setNodeValue(strCheck);
            child.at(4).toElement().firstChild().setNodeValue(strStop);
            child.at(5).toElement().firstChild().setNodeValue(strLinBaud);
            child.at(6).toElement().firstChild().setNodeValue(strLinChannel);
            child.at(7).toElement().firstChild().setNodeValue(strLinPact);
            child.at(8).toElement().firstChild().setNodeValue(strLinImp);
            child.at(9).toElement().firstChild().setNodeValue(strLinSleep);
            child.at(10).toElement().firstChild().setNodeValue(strLinWake);
        }

    }


    QFile f("config.xml");
    if(!f.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        return;
    }

    QTextStream out(&f);
    dom.save(out,4);
    f.close();

}


/***************线程构造函数********************/
XmlThread::XmlThread(QtXml *xml)
{
    this->xml=xml;
}


/***************线程函数************************/
void XmlThread::run()
{
    this->xml->readXML();
}
