#ifndef NotBackInsert_H
#define NotBackInsert_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include "MessageBox/messagedialog.h"
#include "notBack/notBackdatabase.h"
namespace Ui {
class NotBackInsert;
}

class NotBackInsert : public QWidget
{
    Q_OBJECT

public:
    explicit NotBackInsert(QWidget *parent = 0);
    ~NotBackInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::NotBackInsert *ui;
    NotBackDataBase *notBackDataBase;


    QWidget     *widgetNumber;       //学号
    QLineEdit   *lineEditNumber;     //学号
    QHBoxLayout *hboxLayoutNumber;   //学号


    QWidget     *widgetNotBackTime;     //时间
    QDateEdit   *dateEditNotBackTime;    //时间
    QHBoxLayout *hboxLayoutNotBackTime; //时间

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮
};

#endif // NotBackInsert_H
