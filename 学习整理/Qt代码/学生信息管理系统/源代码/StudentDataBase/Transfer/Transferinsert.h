#ifndef TransferINSERT_H
#define TransferINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "Transfer/TransferDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class Transferinsert;
}

class TransferInsert : public QWidget
{
    Q_OBJECT

public:
    explicit TransferInsert(QWidget *parent = 0);
    ~TransferInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::Transferinsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号

    QWidget     *widgetTransferTime;      //时间
    QDateEdit   *dateEditTransferTime;    //时间
    QHBoxLayout *hboxLayoutTransferTime;  //时间

    QWidget     *widgetTransferSchool;     //转学学校
    QLineEdit   *LineEditTransferSchool;   //转学学校
    QHBoxLayout *hboxLayoutTransferSchool; //转学学校

    QWidget     *widgetTransferType;     //转学类型
    QComboBox   *comboBoxTransferType;   //转学类型
    QHBoxLayout *hboxLayoutTransferType; //转学类型

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    TransferDataBase *data;

};

#endif // TransferINSERT_H
