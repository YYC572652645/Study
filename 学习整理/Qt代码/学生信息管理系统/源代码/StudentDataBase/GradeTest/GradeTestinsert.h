#ifndef GradeTestINSERT_H
#define GradeTestINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "GradeTest/GradeTestDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class GradeTestinsert;
}

class GradeTestInsert : public QWidget
{
    Q_OBJECT

public:
    explicit GradeTestInsert(QWidget *parent = 0);
    ~GradeTestInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::GradeTestinsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号


    QWidget     *widgetGradeTestName;     //考试名称
    QComboBox   *comboBoxGradeTestName;   //考试名称
    QHBoxLayout *hboxLayoutGradeTestName; //考试名称

    QWidget     *widgetGradeTestIsPass;     //是否通过
    QComboBox   *comboBoxGradeTestIsPass;   //是否通过
    QHBoxLayout *hboxLayoutGradeTestIsPass; //是否通过


    QWidget     *widgetGradeTestTime;        //考试时间
    QDateEdit   *dateEditGradeTestTime;      //考试时间
    QHBoxLayout *hboxLayoutGradeTestTime;    //考试时间

    QWidget     *widgetGradeTestFraction;     //考试分数
    QLineEdit   *LineEditGradeTestFraction;   //考试分数
    QHBoxLayout *hboxLayoutGradeTestFraction; //考试分数


    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    GradeTestDataBase *data;

};

#endif // GradeTestINSERT_H
