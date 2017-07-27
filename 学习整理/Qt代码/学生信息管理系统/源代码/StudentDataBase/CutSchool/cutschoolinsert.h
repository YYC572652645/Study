#ifndef CUTSCHOOLINSERT_H
#define CUTSCHOOLINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include "MessageBox/messagedialog.h"
#include "CutSchool/cutschooldatabase.h"
namespace Ui {
class CutSchoolInsert;
}

class CutSchoolInsert : public QWidget
{
    Q_OBJECT

public:
    explicit CutSchoolInsert(QWidget *parent = 0);
    ~CutSchoolInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::CutSchoolInsert *ui;
    CutSchoolDataBase *cutSchool;


    QWidget     *widgetNumber;       //学号
    QLineEdit   *lineEditNumber;     //学号
    QHBoxLayout *hboxLayoutNumber;   //学号

    QWidget     *widgetCutClass;     //旷课名称
    QLineEdit   *lineEditCutClass;   //旷课名称
    QHBoxLayout *hboxLayoutCutClass; //旷课名称

    QWidget     *widgetCutTime;      //旷课时间
    QDateEdit   *dateEditCutTime;    //旷课时间
    QHBoxLayout *hboxLayoutCutTime;  //旷课时间

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮
};

#endif // CUTSCHOOLINSERT_H
