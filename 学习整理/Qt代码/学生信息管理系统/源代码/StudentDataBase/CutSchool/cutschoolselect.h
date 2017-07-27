#ifndef CUTSCHOOLSELECT_H
#define CUTSCHOOLSELECT_H

#include <QWidget>
#include <QThread>
#include <QAxObject>
#include <QStatusBar>
#include <QProgressBar>
#include <QFileDialog>
#include "CutSchool/cutschoolinsert.h"
namespace Ui {
class CutSchoolSelect;
}

class CutSchoolSelect : public QWidget
{
    Q_OBJECT

public:
    explicit CutSchoolSelect(QWidget *parent = 0);
    ~CutSchoolSelect();

private:
    Ui::CutSchoolSelect *ui;
public:
    CutSchoolDataBase *cutSchool;

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

#endif // CUTSCHOOLSELECT_H
class CutSchoolThread:public QThread
{
    CutSchoolSelect *widget;
    QStatusBar*statusBar;
    int width;
    int flage;
public:
    CutSchoolThread(CutSchoolSelect *widget,QStatusBar*statusBar,int width,int flage);
public:
    virtual void run();
};
