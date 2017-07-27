#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QDateEdit>
#include <QComboBox>
#include <QFont>
#include <QPushButton>
#include <QMessageBox>
#include "MessageBox/messagedialog.h"
#include "StudentDataBase.h"
namespace Ui {
class StudentInfo;
}

class StudentInfo : public QWidget
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = 0);
    ~StudentInfo();
public slots:
    void insertData();  //录入数据
public:
    Ui::StudentInfo *ui;
    StudentDataBase *data;              //数据库对象
    QWidget     *widgetName;            //姓名
    QLineEdit   *lineEditName;          //姓名
    QHBoxLayout *hboxLayoutName;        //居中控件
    QRadioButton*radioBoy;              //性别
    QRadioButton*radioGirl;             //性别
    QHBoxLayout *hboxLayoutSex;         //水平布局
    QWidget     *widgetSex;             //性别
    QLineEdit   *lineEditNumber;        //学号
    QWidget     *widgetNumber;          //学号
    QHBoxLayout *hboxLayoutNumber;      //水平布局
    QComboBox   *comboBoxNation;        //民族
    QWidget     *widgetNation;          //民族
    QHBoxLayout *hboxLayoutNation;      //水平布局
    QDateEdit   *dateEditBornDate;      //出生日期
    QWidget     *widgetBornDate;        //出生日期
    QHBoxLayout *hboxLayoutBornDate;    //水平布局
    QComboBox   *comboBoxPolitical;     //政治面貌
    QWidget     *widgetPolitical;       //政治面貌
    QHBoxLayout *hboxLayoutPolitical;   //水平布局
    QComboBox   *comboBoxCollege;       //学院
    QWidget     *widgetCollege;         //学院
    QHBoxLayout *hboxLayoutCollege;     //水平布局
    QComboBox   *comboBoxProfess;       //专业班级
    QLineEdit   *lineEditProfessYear;   //专业班级
    QWidget     *widgetProfess;         //专业班级
    QHBoxLayout *hboxLayoutProfess;     //水平布局
    QComboBox   *comboBoxNowClass;      //当前所在班
    QLineEdit   *lineEditNowClassYear;  //当前所在班
    QHBoxLayout *hboxLayoutNowClass;    //水平布局
    QWidget     *widgetNowClass;        //当前所在班
    QComboBox   *comboBoxDorm;          //宿舍楼
    QLineEdit   *lineEditDormNumber;    //宿舍号
    QHBoxLayout *hboxLayoutDorm;        //水平布局
    QGroupBox   *widgetDorm;            //宿舍号
    QLineEdit   *lineEditBedNumber;     //床号
    QWidget     *widgetBedNumber;       //床号
    QHBoxLayout *hboxLayoutBedNumber;   //水平布局
    QLineEdit   *lineEditCardNumber;    //身份证号
    QWidget     *widgetCardNumber;      //身份证号
    QHBoxLayout *hboxLayoutCardNumber;  //水平布局
    QLineEdit   *lineEditBankNumber;    //银行卡号
    QWidget     *widgetBankNumber;      //银行卡号
    QHBoxLayout *hboxLayoutBankNumber;  //水平布局
    QLineEdit   *lineEditCodeNumber;    //邮编
    QWidget     *widgetCodeNumber;      //邮编
    QHBoxLayout *hboxLayoutCodeNumber;  //水平布局
    QLineEdit   *lineEditQQNumber;      //QQ
    QWidget     *widgetQQNumber;        //QQ
    QHBoxLayout *hboxLayoutQQNumber;    //水平布局
    QComboBox   *comboBoxHouseType;     //户口类型
    QWidget     *widgetHouseType;       //户口类型
    QHBoxLayout *hboxLayoutHouseType;   //水平布局
    QLineEdit   *lineEditAddress;       //家庭住址
    QWidget     *widgetAddress;         //家庭住址
    QHBoxLayout *hboxLayoutAddress;     //水平布局
    QLineEdit   *lineEditOrigin;        //生源地
    QWidget     *widgetOrigin;          //生源地
    QHBoxLayout *hboxLayoutOrigin;      //水平布局
    QComboBox   *comboBoxSingle;        //是否单亲
    QWidget     *widgetSingle;          //是否单亲
    QHBoxLayout *hboxLayoutSingle;      //水平布局
    QComboBox   *comboBoxPoverty;       //是否贫困
    QWidget     *widgetPoverty;         //是否贫困
    QHBoxLayout *hboxLayoutPoverty;     //水平布局
    QComboBox   *comboBoxArmy;          //是否服兵役
    QWidget     *widgetArmy;            //是否服兵役
    QHBoxLayout *hboxLayoutArmy;        //水平布局
    QComboBox   *comboBoxAbord;         //是否留学
    QWidget     *widgetAbord;           //是否留学
    QHBoxLayout *hboxLayoutAbord;       //水平布局
    QComboBox   *comboBoxGoHome;        //周末是否回家
    QWidget     *widgetGoHome;          //周末是否回家
    QHBoxLayout *hboxLayoutGoHome;      //水平布局
    QComboBox   *comboBoxGoRead;        //是否走读
    QWidget     *widgetGoRead;          //是否走读
    QHBoxLayout *hboxLayoutGoRead;      //水平布局
    QLineEdit   *lineEditFatherName;    //父亲姓名
    QWidget     *widgetFatherName;      //父亲姓名
    QHBoxLayout *hboxLayoutFatherName;  //水平布局
    QLineEdit   *lineEditFatherNumber;  //父亲联系电话
    QWidget     *widgetFatherNumber;    //父亲联系电话
    QHBoxLayout *hboxLayoutFatherNumber;//水平布局
    QLineEdit   *lineEditFatherWork;    //父亲工作单位
    QWidget     *widgetFatherWork;      //父亲工作单位
    QHBoxLayout *hboxLayoutFatherWork;  //水平布局
    QLineEdit   *lineEditMotherName;    //母亲姓名
    QWidget     *widgetMotherName;      //母亲姓名
    QHBoxLayout *hboxLayoutMotherName;  //水平布局
    QLineEdit   *lineEditMotherNumber;  //母亲联系电话
    QWidget     *widgetMotherNumber;    //母亲联系电话
    QHBoxLayout *hboxLayoutMotherNumber;//水平布局
    QLineEdit   *lineEditMotherWork;    //母亲工作单位
    QWidget     *widgetMotherWork;      //母亲工作单位
    QHBoxLayout *hboxLayoutMotherWork;  //水平布局
    QLineEdit   *lineEditPhoneNumber;   //联系电话
    QWidget     *widgetPhoneNumber;     //联系电话
    QHBoxLayout *hboxLayoutPhoneNumber; //水平布局
    QPushButton *insertButton;          //录入数据
};

#endif // STUDENTINFO_H
