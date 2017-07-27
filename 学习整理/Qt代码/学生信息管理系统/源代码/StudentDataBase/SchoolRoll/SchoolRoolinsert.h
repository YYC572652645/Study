#ifndef SchoolRoolINSERT_H
#define SchoolRoolINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "SchoolRoll/SchoolRoolDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class SchoolRoolinsert;
}

class SchoolRoolInsert : public QWidget
{
    Q_OBJECT

public:
    explicit SchoolRoolInsert(QWidget *parent = 0);
    ~SchoolRoolInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::SchoolRoolinsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号

    QWidget     *widgetSchoolRoolTime;      //时间
    QDateEdit   *dateEditSchoolRoolTime;    //时间
    QHBoxLayout *hboxLayoutSchoolRoolTime;  //时间


    QWidget     *widgetSchoolRoolType;     //修复退种类
    QComboBox   *comboBoxSchoolRoolType;   //修复退种类
    QHBoxLayout *hboxLayoutSchoolRoolType; //修复退种类

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    SchoolRoolDataBase *data;

};

#endif // SchoolRoolINSERT_H
