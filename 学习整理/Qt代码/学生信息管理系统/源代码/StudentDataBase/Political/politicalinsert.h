#ifndef POLITICALINSERT_H
#define POLITICALINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include "Political/PoliticalDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class PoliticalInsert;
}

class PoliticalInsert : public QWidget
{
    Q_OBJECT

public:
    explicit PoliticalInsert(QWidget *parent = 0);
    ~PoliticalInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::PoliticalInsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号

    QWidget     *widgetgroMem;        //入团时间
    QDateEdit   *dateEditgroMem;      //入团时间
    QHBoxLayout *hboxLayoutgroMem;    //入团时间

    QWidget     *widgetProActMem;     //入党积极分子时间
    QDateEdit   *dateEditProActMem;   //入党积极分子时间
    QHBoxLayout *hboxLayoutProActMem; //入党积极分子时间

    QWidget     *widgetProMem;        //入党时间
    QDateEdit   *dateEditProMem;      //入党时间
    QHBoxLayout *hboxLayoutProMem;    //入党时间

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    PoliticalDataBase *data;

};

#endif // POLITICALINSERT_H
