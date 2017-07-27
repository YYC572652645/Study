#ifndef DAILYSELECT_H
#define DAILYSELECT_H

#include <QWidget>
#include <QThread>
#include <QAxObject>
#include <QStatusBar>
#include <QProgressBar>
#include <QFileDialog>
#include "Daily/dailyinsert.h"
namespace Ui {
class DailySelect;
}

class DailySelect : public QWidget
{
    Q_OBJECT

public:
    explicit DailySelect(QWidget *parent = 0);
    ~DailySelect();

private:
    Ui::DailySelect *ui;

public:

    /********************查询宿舍号*****************/
    void numerSelect(QString dorNumber);


    /********************查询宿舍情况*****************/
    void statusSelect(QString dorStatus);

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
    DailyDataBase *Daily;
private slots:
    void on_pushButtonDorNumberSec_clicked();
    void on_pushButtonDorStatusSec_clicked();
};

#endif // DAILYSELECT_H

class DailyThread:public QThread
{
    DailySelect *widget;
    QStatusBar*statusBar;
    int width;
    int flage;
public:
    DailyThread(DailySelect *widget,QStatusBar*statusBar,int width,int flage);
public:
    virtual void run();
};
