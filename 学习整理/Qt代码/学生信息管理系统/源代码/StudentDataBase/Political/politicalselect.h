#ifndef POLITICALSELECT_H
#define POLITICALSELECT_H
#include "Political/politicalinsert.h"
#include "MessageBox/messagedialog.h"
#include <QWidget>
#include <QProgressBar>
#include <QStatusBar>
#include <QAxObject>
#include <QFileDialog>
#include <QThread>
namespace Ui {
class PoliticalSelect;
}

class PoliticalSelect : public QWidget
{
    Q_OBJECT
    friend class politicalThread;
public:
    explicit PoliticalSelect(QWidget *parent = 0);
    ~PoliticalSelect();

private:
    Ui::PoliticalSelect *ui;
public:
    PoliticalDataBase *poli; //数据库对象
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

#endif // POLITICALSELECT_H
class PoliticalThread:public QThread
{
    PoliticalSelect *widget;
    QStatusBar*statusBar;
    int width;
    int flage;
public:
    PoliticalThread(PoliticalSelect *widget,QStatusBar*statusBar,int width,int flage);
public:
    virtual void run();
};
