#include "qtxml.h"

/***************************构造函数***********************/
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
                    case 11:strLinMCheck[0]=domNode.toElement().text();break;
                    case 12:strLinMCheck[1]=domNode.toElement().text();break;
                    case 13:strLinMCheck[2]=domNode.toElement().text();break;
                    case 14:strLinMCheck[3]=domNode.toElement().text();break;
                    case 15:strLinMCheck[4]=domNode.toElement().text();break;
                    case 16:strLinMCheck[5]=domNode.toElement().text();break;
                    case 17:strLinMCheck[6]=domNode.toElement().text();break;
                    case 18:strLinMCheck[7]=domNode.toElement().text();break;
                    case 19:strLinMCheck[8]=domNode.toElement().text();break;
                    case 20:strLinMCheck[9]=domNode.toElement().text();break;
                    case 21:strLinMCheck[10]=domNode.toElement().text();break;
                    case 22:strLinMCheck[11]=domNode.toElement().text();break;
                    case 23:strLinMCheck[12]=domNode.toElement().text();break;
                    case 24:strLinMCheck[13]=domNode.toElement().text();break;
                    case 25:strLinMCheck[14]=domNode.toElement().text();break;
                    case 26:strLinMCheck[15]=domNode.toElement().text();break;
                    case 27:strLinMID[0]=domNode.toElement().text();break;
                    case 28:strLinMID[1]=domNode.toElement().text();break;
                    case 29:strLinMID[2]=domNode.toElement().text();break;
                    case 30:strLinMID[3]=domNode.toElement().text();break;
                    case 31:strLinMID[4]=domNode.toElement().text();break;
                    case 32:strLinMID[5]=domNode.toElement().text();break;
                    case 33:strLinMID[6]=domNode.toElement().text();break;
                    case 34:strLinMID[7]=domNode.toElement().text();break;
                    case 35:strLinMID[8]=domNode.toElement().text();break;
                    case 36:strLinMID[9]=domNode.toElement().text();break;
                    case 37:strLinMID[10]=domNode.toElement().text();break;
                    case 38:strLinMID[11]=domNode.toElement().text();break;
                    case 39:strLinMID[12]=domNode.toElement().text();break;
                    case 40:strLinMID[13]=domNode.toElement().text();break;
                    case 41:strLinMID[14]=domNode.toElement().text();break;
                    case 42:strLinMID[15]=domNode.toElement().text();break;
                    case 43:strLinMData[0]=domNode.toElement().text();break;
                    case 44:strLinMData[1]=domNode.toElement().text();break;
                    case 45:strLinMData[2]=domNode.toElement().text();break;
                    case 46:strLinMData[3]=domNode.toElement().text();break;
                    case 47:strLinMData[4]=domNode.toElement().text();break;
                    case 48:strLinMData[5]=domNode.toElement().text();break;
                    case 49:strLinMData[6]=domNode.toElement().text();break;
                    case 50:strLinMData[7]=domNode.toElement().text();break;
                    case 51:strLinMData[8]=domNode.toElement().text();break;
                    case 52:strLinMData[9]=domNode.toElement().text();break;
                    case 53:strLinMData[10]=domNode.toElement().text();break;
                    case 54:strLinMData[11]=domNode.toElement().text();break;
                    case 55:strLinMData[12]=domNode.toElement().text();break;
                    case 56:strLinMData[13]=domNode.toElement().text();break;
                    case 57:strLinMData[14]=domNode.toElement().text();break;
                    case 58:strLinMData[15]=domNode.toElement().text();break;
                    case 59:strLinMCount[0]=domNode.toElement().text();break;
                    case 60:strLinMCount[1]=domNode.toElement().text();break;
                    case 61:strLinMCount[2]=domNode.toElement().text();break;
                    case 62:strLinMCount[3]=domNode.toElement().text();break;
                    case 63:strLinMCount[4]=domNode.toElement().text();break;
                    case 64:strLinMCount[5]=domNode.toElement().text();break;
                    case 65:strLinMCount[6]=domNode.toElement().text();break;
                    case 66:strLinMCount[7]=domNode.toElement().text();break;
                    case 67:strLinMCount[8]=domNode.toElement().text();break;
                    case 68:strLinMCount[9]=domNode.toElement().text();break;
                    case 69:strLinMCount[10]=domNode.toElement().text();break;
                    case 70:strLinMCount[11]=domNode.toElement().text();break;
                    case 71:strLinMCount[12]=domNode.toElement().text();break;
                    case 72:strLinMCount[13]=domNode.toElement().text();break;
                    case 73:strLinMCount[14]=domNode.toElement().text();break;
                    case 74:strLinMCount[15]=domNode.toElement().text();break;
                    case 75:strLinSCheck[0]=domNode.toElement().text();break;
                    case 76:strLinSCheck[1]=domNode.toElement().text();break;
                    case 77:strLinSCheck[2]=domNode.toElement().text();break;
                    case 78:strLinSCheck[3]=domNode.toElement().text();break;
                    case 79:strLinSCheck[4]=domNode.toElement().text();break;
                    case 80:strLinSCheck[5]=domNode.toElement().text();break;
                    case 81:strLinSCheck[6]=domNode.toElement().text();break;
                    case 82:strLinSCheck[7]=domNode.toElement().text();break;
                    case 83:strLinSCheck[8]=domNode.toElement().text();break;
                    case 84:strLinSCheck[9]=domNode.toElement().text();break;
                    case 85:strLinSCheck[10]=domNode.toElement().text();break;
                    case 86:strLinSCheck[11]=domNode.toElement().text();break;
                    case 87:strLinSCheck[12]=domNode.toElement().text();break;
                    case 88:strLinSCheck[13]=domNode.toElement().text();break;
                    case 89:strLinSCheck[14]=domNode.toElement().text();break;
                    case 90:strLinSCheck[15]=domNode.toElement().text();break;
                    case 91:strLinSID[0]=domNode.toElement().text();break;
                    case 92:strLinSID[1]=domNode.toElement().text();break;
                    case 93:strLinSID[2]=domNode.toElement().text();break;
                    case 94:strLinSID[3]=domNode.toElement().text();break;
                    case 95:strLinSID[4]=domNode.toElement().text();break;
                    case 96:strLinSID[5]=domNode.toElement().text();break;
                    case 97:strLinSID[6]=domNode.toElement().text();break;
                    case 98:strLinSID[7]=domNode.toElement().text();break;
                    case 99:strLinSID[8]=domNode.toElement().text();break;
                    case 100:strLinSID[9]=domNode.toElement().text();break;
                    case 101:strLinSID[10]=domNode.toElement().text();break;
                    case 102:strLinSID[11]=domNode.toElement().text();break;
                    case 103:strLinSID[12]=domNode.toElement().text();break;
                    case 104:strLinSID[13]=domNode.toElement().text();break;
                    case 105:strLinSID[14]=domNode.toElement().text();break;
                    case 106:strLinSID[15]=domNode.toElement().text();break;
                    case 107:strLinSData[0]=domNode.toElement().text();break;
                    case 108:strLinSData[1]=domNode.toElement().text();break;
                    case 109:strLinSData[2]=domNode.toElement().text();break;
                    case 110:strLinSData[3]=domNode.toElement().text();break;
                    case 111:strLinSData[4]=domNode.toElement().text();break;
                    case 112:strLinSData[5]=domNode.toElement().text();break;
                    case 113:strLinSData[6]=domNode.toElement().text();break;
                    case 114:strLinSData[7]=domNode.toElement().text();break;
                    case 115:strLinSData[8]=domNode.toElement().text();break;
                    case 116:strLinSData[9]=domNode.toElement().text();break;
                    case 117:strLinSData[10]=domNode.toElement().text();break;
                    case 118:strLinSData[11]=domNode.toElement().text();break;
                    case 119:strLinSData[12]=domNode.toElement().text();break;
                    case 120:strLinSData[13]=domNode.toElement().text();break;
                    case 121:strLinSData[14]=domNode.toElement().text();break;
                    case 122:strLinSData[15]=domNode.toElement().text();break;

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

/***************************更新xml文件********************/
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
            for(int i=11;i<27;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinMCheck[i-11]);
            }

            for(int i=27;i<43;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinMID[i-27]);
            }
            for(int i=43;i<59;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinMData[i-43]);
            }
            for(int i=59;i<75;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinMCount[i-59]);
            }
            for(int i=75;i<91;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinSCheck[i-75]);
            }
            for(int i=91;i<107;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinSID[i-91]);
            }
            for(int i=107;i<123;i++)
            {
                child.at(i).toElement().firstChild().setNodeValue(strLinSData[i-107]);
            }
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

/***************************线程构造函数********************/
XmlThread::XmlThread(QtXml *xml)
{
    this->xml=xml;
}

/***************************线程函数************************/
void XmlThread::run()
{
    this->xml->readXML();
}
