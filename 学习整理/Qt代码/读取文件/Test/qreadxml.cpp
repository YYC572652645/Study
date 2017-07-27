#include "qreadxml.h"

QReadXml *QReadXml::instance = NULL;

QReadXml *QReadXml::getInstance()
{
    if(NULL == instance)
    {
        instance = new QReadXml();
    }

    return instance;
}

QReadXml::QReadXml()
{
    this->readXML();
}

bool QReadXml::readXML()
{
    int countData = 0;
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
    QDomElement docElem = dom.documentElement();   //返回根元素

    QDomNode node = docElem.firstChild();          //返回根节点的第一个子节点

    while(!node.isNull())                        //如果节点不为空
    {
        if(node.isElement())                     //如果节点是元素
        {
            QDomElement element=node.toElement();//将其转化为元素

            QDomNodeList list=element.childNodes();//取出该元素的所有子节点放到list中

            //将子节点元素全部取出来
            for(int i = 0; i < list.count(); i ++)
            {
                QDomNode domNode = list.at(i);
                if(domNode.isElement())
                {
                    //取出我们所要的数据
                    switch(i)
                    {
                    case 0:xmlConfig.ip = domNode.toElement().text();break;
                    case 1:xmlConfig.port = domNode.toElement().text();break;
                    case 2:xmlConfig.dataBaseVersion = domNode.toElement().text();break;
                    case 3:xmlConfig.dataBaseName = domNode.toElement().text();break;
                    case 4:xmlConfig.userName = domNode.toElement().text();break;
                    case 5:xmlConfig.passWord = domNode.toElement().text();break;
                    }
                }
            }
        }

        countData++;
        node = node.nextSibling(); //下一个兄弟节点
    }

    qDebug()<<xmlConfig.ip;
    return countData > 0 ? true : false;
}

const XmlConfig &QReadXml::getXmlConfig()
{
    return xmlConfig;
}




