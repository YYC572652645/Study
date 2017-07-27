#ifndef NotPassINSERT_H
#define NotPassINSERT_H

#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>
#include "NotPass/NotPassdatabase.h"
#include "MessageBox/messagedialog.h"
namespace Ui {
class NotPassInsert;
}

class NotPassInsert : public QWidget
{
    Q_OBJECT

public:
    explicit NotPassInsert(QWidget *parent = 0);
    ~NotPassInsert();

private slots:
    void insertData();   //插入数据
private:
    Ui::NotPassInsert *ui;
    NotPassDataBase *NotPass;


    QWidget     *widgetNumber;       //学号
    QLineEdit   *lineEditNumber;     //学号
    QHBoxLayout *hboxLayoutNumber;   //学号

    QWidget     *widgetNotPassClass;     //挂科名称
    QLineEdit   *lineEditNotPassClass;   //挂科名称
    QHBoxLayout *hboxLayoutNotPassClass; //挂科名称

    QWidget     *widgetNotPassGrade;      //挂科学分
    QComboBox   *comboBoxNotPassGrade;    //挂科学分
    QHBoxLayout *hboxLayoutNotPassGrade;  //挂科学分

    QWidget     *widgetNotPassPro;         //挂科性质
    QLineEdit   *lineEditNotPassPro;       //挂科性质
    QHBoxLayout *hboxLayoutNotPassPro;     //挂科性质

    QWidget     *widgetNotPassStatus;      //挂科状态
    QComboBox   *comboBoxNotPassStatus;    //挂科状态
    QHBoxLayout *hboxLayoutNotPassStatus;  //挂科状态


    QWidget      *widgetInsert;        //插入数据按钮
    QPushButton  *pushButtonInsert;    //插入数据按钮
    QHBoxLayout  *hboxLayoutInsert;    //插入数据按钮
};

#endif // NotPassINSERT_H
