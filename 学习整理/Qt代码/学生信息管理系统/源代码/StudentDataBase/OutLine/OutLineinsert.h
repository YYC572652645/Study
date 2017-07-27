#ifndef OutLineINSERT_H
#define OutLineINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "OutLine/OutLineDataBase.h"
#include "MessageBox/messagedialog.h"
#include <QDebug>

namespace Ui {
class OutLineinsert;
}

class OutLineInsert : public QWidget
{
    Q_OBJECT

public:
    explicit OutLineInsert(QWidget *parent = 0);
    ~OutLineInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::OutLineinsert *ui;

    QWidget     *widgetNumber;        //学号
    QLineEdit   *lineEditNumber;      //学号
    QHBoxLayout *hboxLayoutNumber;    //学号

    QWidget     *widgetOutLineTime;      //时间
    QDateEdit   *dateEditOutLineTime;    //时间
    QHBoxLayout *hboxLayoutOutLineTime;  //时间

    QWidget     *widgetOutLineReason;     //违规原因
    QLineEdit   *LineEditOutLineReason;   //违规原因
    QHBoxLayout *hboxLayoutOutLineReason; //违规原因

    QWidget     *widgetOutLineLevel;     //违规级别
    QComboBox   *comboBoxOutLineLevel;   //违规级别
    QHBoxLayout *hboxLayoutOutLineLevel; //违规级别

    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮


    OutLineDataBase *data;

};

#endif // OutLineINSERT_H
