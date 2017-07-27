
#include<QString>
#include<QSqlDriver>
#include<QSqlRecord>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtXml>
#include<QFile>
#include<QIODevice>
#include<QDomNodeList>
typedef struct dataKnow
{
    QString name;        //姓名
    QString sex;         //性别
    QString number;      //学号
    QString nation;      //民族
    QString bornDate;    //出生日期
    QString political;   //政治面貌
    QString college;     //学院
    QString profess;     //专业班级
    QString nowClass;    //当前所在班
    QString dormNumber;  //宿舍号
    QString bedNumber;   //床号
    QString cardNumber;  //身份证号
    QString bankNumber;  //银行卡号
    QString codeNumber;  //邮编
    QString QQNumber;    //QQ
    QString houseType;   //户口类型
    QString address;     //家庭住址
    QString origin;      //生源地
    QString single;      //是否单亲
    QString poverty;     //是否贫困
    QString army;        //是否服兵役
    QString abord;       //是否留学
    QString goHome;      //周末是否回家
    QString goRead;      //是否走读
    QString fatherName;  //父亲姓名
    QString fatherNumber;//父亲联系电话
    QString fatherWork;  //父亲工作单位
    QString motherName;  //母亲姓名
    QString motherNumber;//母亲联系电话
    QString motherWork;  //母亲工作单位
    QString phoneNumber; //联系电话
}dataKnow;




class StudentDataBase
{
public:
    /************构造函数*************/
    StudentDataBase();


    /************连接数据库*************/
    bool dataCnn();


    /************插入数据*************/
    bool insertData();


    /************查询数据*************/
    int selectData(QString studentNumber,QString studentName,QString studentClass);


    /************更改数据*************/
    bool updateData();


    /************删除数据*************/
    bool deleteData( );


    /************读取xml文件**********/
    bool readXML();

public:
    QString name;        //姓名
    QString sex;         //性别
    QString number;      //学号
    QString nation;      //民族
    QString bornDate;    //出生日期
    QString political;   //政治面貌
    QString college;     //学院
    QString profess;     //专业班级
    QString nowClass;    //当前所在班
    QString dormNumber;  //宿舍号
    QString bedNumber;   //床号
    QString cardNumber;  //身份证号
    QString bankNumber;  //银行卡号
    QString codeNumber;  //邮编
    QString QQNumber;    //QQ
    QString houseType;   //户口类型
    QString address;     //家庭住址
    QString origin;      //生源地
    QString single;      //是否单亲
    QString poverty;     //是否贫困
    QString army;        //是否服兵役
    QString abord;       //是否留学
    QString goHome;      //周末是否回家
    QString goRead;      //是否走读
    QString fatherName;  //父亲姓名
    QString fatherNumber;//父亲联系电话
    QString fatherWork;  //父亲工作单位
    QString motherName;  //母亲姓名
    QString motherNumber;//母亲联系电话
    QString motherWork;  //母亲工作单位
    QString phoneNumber; //联系电话
    dataKnow*studentMessage;
private:
    QString dataBaseName;          //数据库名称
    QString dataBaseVersion;       //数据库版本
    QString ip;                    //ip地址
    QString port;                  //端口
    QString userName;              //用户名
    QString passWord;              //密码
    QSqlDatabase db;               //定义数据库对象
};

