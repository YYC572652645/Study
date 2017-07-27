#ifndef OrderCastINSERT_H
#define OrderCastINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include "OrderCast/OrderCastdatabase.h"
#include "MessageBox/messagedialog.h"
namespace Ui {
class OrderCastInsert;
}

class OrderCastInsert : public QWidget
{
    Q_OBJECT

public:
    explicit OrderCastInsert(QWidget *parent = 0);
    ~OrderCastInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::OrderCastInsert *ui;
    OrderCastDataBase *OrderCast;


    QWidget     *widgetNumber;       //学号
    QLineEdit   *lineEditNumber;     //学号
    QHBoxLayout *hboxLayoutNumber;   //学号

    QWidget     *widgetOrderCastClass;     //班级排名
    QLineEdit   *lineEditOrderCastClass;   //班级排名
    QHBoxLayout *hboxLayoutOrderCastClass; //班级排名

    QWidget     *widgetOrderCastPro;      //专业排名
    QLineEdit   *comboBoxOrderCastPro;    //专业排名
    QHBoxLayout *hboxLayoutOrderCastPro;  //专业排名

    QWidget     *widgetOrderCastTime;         //年份
    QComboBox   *lineEditOrderCastTime;       //年份
    QHBoxLayout *hboxLayoutOrderCastTime;     //年份

    QWidget     *widgetOrderCastStatus;      //学期
    QComboBox   *comboBoxOrderCastStatus;    //学期
    QHBoxLayout *hboxLayoutOrderCastStatus;  //学期


    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮
};

#endif // OrderCastINSERT_H
