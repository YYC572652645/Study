#ifndef NotPassSELECT_H
#define NotPassSELECT_H

#include <QWidget>
#include <QThread>
#include <QAxObject>
#include <QStatusBar>
#include <QProgressBar>
#include <QFileDialog>
#include "NotPass/NotPassinsert.h"
namespace Ui {
class NotPassSelect;
}

class NotPassSelect : public QWidget
{
    Q_OBJECT

public:
    explicit NotPassSelect(QWidget *parent = 0);
    ~NotPassSelect();

private:
    Ui::NotPassSelect *ui;
public:
    NotPassDataBase *NotPass;

public:

    /********************查询学号*****************/
    void numerSelect(QString number);


    /********************查询姓名*****************/
    void nameSelect(QString name);


    /********************查询班级*****************/
    void classSelect(QString strClass);


    /********************导出Excel*****************/
    void extendExcel(QStatusBar *statusBar, float width);


    /********************导入Excel*****************/
    void importExcel(QStatusBar*statusBar,float width);


public slots:
    /********************删除数据*****************/
    void deleteData();


    /********************获取当前选中行*****************/
    void selectText(const QModelIndex &index);


protected:

    /********************创建操作excel对象*****************/
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;
    int dataBaseCount;
    int rowCount;
};

#endif // NotPassSELECT_H
class NotPassThread:public QThread
{
    NotPassSelect *widget;
    QStatusBar*statusBar;
    int width;
    int flage;
public:
    NotPassThread(NotPassSelect *widget,QStatusBar*statusBar,int width,int flage);
public:
    virtual void run();
};
