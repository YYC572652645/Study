#ifndef DAILYINSERT_H
#define DAILYINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QComboBox>
#include <QMessageBox>
#include "Daily/dailydatabase.h"
#include "MessageBox/messagedialog.h"
namespace Ui {
class DailyInsert;
}

class DailyInsert : public QWidget
{
    Q_OBJECT

public:
    explicit DailyInsert(QWidget *parent = 0);
    ~DailyInsert();

private slots:
    void insertData();   //插入数据

private:
    Ui::DailyInsert *ui;

    QWidget     *widgetDorNumber;      //宿舍号
    QLineEdit   *lineEditDorNumber;    //宿舍号
    QHBoxLayout *hboxLayoutDorNumber;  //宿舍号

    QWidget     *widgetDorTime;        //时间
    QDateEdit   *dateEditDorTime;      //时间
    QHBoxLayout *hboxLayoutDorTime;    //时间

    QWidget     *widgetDorStatus;      //宿舍情况
    QComboBox   *comboBoxDorStatus;    //宿舍情况
    QHBoxLayout *hboxLayoutDorStatus;  //宿舍情况

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮

    DailyDataBase *data;

};

#endif // DAILYINSERT_H
