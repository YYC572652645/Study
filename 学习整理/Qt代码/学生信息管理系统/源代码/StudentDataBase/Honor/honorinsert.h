#ifndef HonorINSERT_H
#define HonorINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "Honor/HonorDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class HonorInsert;
}

class HonorInsert : public QWidget
{
    Q_OBJECT

public:
    explicit HonorInsert(QWidget *parent = 0);
    ~HonorInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::HonorInsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号

    QWidget     *widgetHonorType;     //获奖种类
    QComboBox   *comboBoxHonorType;   //获奖种类
    QHBoxLayout *hboxLayoutHonorType; //获奖种类

    QWidget     *widgetHonorLevel;     //获奖级别
    QComboBox   *comboBoxHonorLevel;   //获奖级别
    QHBoxLayout *hboxLayoutHonorLevel; //获奖级别

    QWidget     *widgetHonorName;      //获奖名称
    QLineEdit   *lineEditHonorName;    //获奖名称
    QHBoxLayout *hboxLayoutHonorName;  //获奖名称

    QWidget     *widgetHonorTime;      //获奖时间
    QDateEdit   *dateEditHonorTime;    //获奖时间
    QHBoxLayout *hboxLayoutHonorTime;  //获奖时间

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    HonorDataBase *data;

};

#endif // HonorINSERT_H
