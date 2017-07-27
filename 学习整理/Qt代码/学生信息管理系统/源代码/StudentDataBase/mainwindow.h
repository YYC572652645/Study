#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QDesktopWidget>
#include <QPaintEvent>
#include <QHeaderView>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QSplitter>
#include <QToolButton>
#include <QToolBar>
#include <QMessageBox>
#include <QTreeWidget>
#include <QComboBox>
#include <QAxObject>
#include <QFileDialog>
#include <QEvent>
#include <QObject>
#include <QProgressBar>
#include <QStatusBar>
#include <QThread>
#include <QPixmap>
#include <QDir>
#include "MessageBox/messagedialog.h"
#include "StudentInfo/studentinfo.h"
#include "Political/politicalinsert.h"
#include "Political/politicalselect.h"
#include "CutSchool/cutschoolselect.h"
#include "CutSchool/cutschoolinsert.h"
#include "NotPass/notpassinsert.h"
#include "NotPass/notpassselect.h"
#include "Honor/honorinsert.h"
#include "Honor/honorselect.h"
#include "Daily/dailyinsert.h"
#include "Daily/dailyselect.h"
#include "OutLine/OutLineinsert.h"
#include "OutLine/OutLineselect.h"
#include "OrderCast/OrderCastInsert.h"
#include "OrderCast/OrderCastSelect.h"
#include "NotBack/notbackinsert.h"
#include "NotBack/notbackselect.h"
#include "Movie/movieplay.h"
#include "Web/webdata.h"
#include "Minimum/suspendform.h"
#include "GradeTest/GradeTestinsert.h"
#include "GradeTest/GradeTestselect.h"
#include "SchoolRoll/SchoolRoolinsert.h"
#include "SchoolRoll/SchoolRoolselect.h"
#include "Transfer/Transferinsert.h"
#include "Transfer/Transferselect.h"
#include "WeatherData/weatherdata.h"
#define ONE 1  //导出Excel
#define TWO 2  //导入Excel

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    friend class Win_QextSerialThread;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    /********************退出登录*****************/
    void exitLogin();


    /********************查询学号*****************/
    void numerSelect();


    /********************按标志位查询学号*****************/
    void numerSelectFlage();


    /********************查询姓名*****************/
    void nameSelect();


    /********************按标志位查询姓名*****************/
    void nameSelectFlage();


    /********************查询班级*****************/
    void classSelect();


    /********************按标志位查询班级*****************/
    void classSelectFlage();


    /********************双击树形控件*************/
    void itemDoubleClicked(QTreeWidgetItem*item, int column);


    /********************导出Excel*****************/
    void extendExcel();


    /********************导入Excel*****************/
    void importExcel();


    /********************按标志位导出Excel*****************/
    void extendExcelFlage();


    /********************按标志位导入Excel*****************/
    void importExcelFlage();


    /********************删除数据*****************/
    void updateData();


    /********************更改数据*****************/
    void deleteData();


    /********************获取当前选中行*****************/
    void selectText(const QModelIndex &index);


    /********************切换风格*****************/
    void on_actionChangeStyle_triggered();


    /********************基本信息查询*****************/
    void on_actionSelect_triggered();


    /********************基本信息录入*****************/
    void on_actionInsert_triggered();


    /********************政治面貌录入*****************/
    void on_actionPoliticalInsert_triggered();


    /********************政治面貌查询*****************/
    void on_actionPoliticalSelect_triggered();

    /********************获取窗口信号*****************/
    void getFlage(int flage);

private slots:
    void on_actionNotPassInsert_triggered();

    void on_actionCutSchoolSelect_triggered();

    void on_actionCutSchoolInsert_triggered();

    void on_actionNotPassSelect_triggered();

    void on_actionHornorInsert_triggered();

    void on_actionHornorSelect_triggered();

    void on_actionScreen_triggered();

    void on_actionDayInsert_triggered();

    void on_actionDaySelect_triggered();

    void on_actionOutLineInsert_triggered();

    void on_actionOutLineSelect_triggered();

    void on_actionGradeInsert_triggered();

    void on_actionGradeSelect_triggered();

    void on_actionMovie_triggered();

    void on_actionJiaowu_triggered();

    void on_actionXinXi_triggered();

    void on_actionBaiDu_triggered();

    void on_actionNotBackIsrt_triggered();

    void on_actionNotBackSect_triggered();

    void on_actionGradeTestIsrt_triggered();

    void on_actionGradeTestSect_triggered();

    void on_actionSchoolRoolIsrt_triggered();

    void on_actionSchoolRoolSect_triggered();

    void on_actionTransferIsrt_triggered();

    void on_actionTransferSect_triggered();

    void on_actionWeather_triggered();

private:
    Ui::MainWindow *ui;
    StudentInfo *info;              //学生信息录入对象
    PoliticalInsert*poliIsrt;       //政治面貌录入对象
    PoliticalSelect*poliSect;       //政治面貌查询对象
    CutSchoolInsert*cutIsrt;        //旷课情况录入对象
    CutSchoolSelect*cutSect;        //旷课情况查询对象
    NotPassInsert*notIsrt;          //挂科情况录入对象
    NotPassSelect*notSect;          //挂科情况查询对象
    HonorInsert*honorIsrt;          //获奖情况录入对象
    HonorSelect*honorSect;          //获奖情况查询对象
    DailyInsert*dailyIsrt;          //日常情况录入对象
    DailySelect*dailySect;          //日常情况查询对象
    OutLineInsert*outLineIsrt;      //违规违纪录入对象
    OutLineSelect*outLineSect;      //违规违纪查询对象
    OrderCastInsert*orderCastIsrt;  //成绩排名录入对象
    OrderCastSelect*orderCastSect;  //成绩排名查询对象
    NotBackInsert*notBackIsrt;      //夜不归寝录入对象
    NotBackSelect*notBackSect;      //夜不归寝查询对象
    GradeTestInsert*gradeTestIsrt;  //等级考试录入对象
    GradeTestSelect*gradeTestSect;  //等级考试查询对象
    SchoolRoolInsert*schoolRoolIsrt;//学籍异变录入对象
    SchoolRoolSelect*schoolRoolSect;//学籍异变查询对象
    TransferInsert*transferIsrt;    //转学录入对象
    TransferSelect*transferSect;    //转学查询对象
    StudentDataBase data;           //声明数据库对象
    WeatherData*weatherData;       //天气对象
    MoviePlay *player;              //播放器对象
    WebData*web;                    //网站对象
    QToolBar *toolBar;              //工具栏
    QLineEdit *numberEdit;          //学号输入框
    QToolButton *numberButton;      //学号查询按钮
    QLineEdit *nameEdit;            //姓名输入框
    QToolButton *nameButton;        //姓名按钮
    QLineEdit *classEdit;           //班级输入框
    QToolButton *classButton;       //班级按钮
    QToolButton *importExcelButton; //导入Excel
    QToolButton *extendExcelButton; //导出Excel
    QTreeWidget *treeWidget;        //树形控件
    QMenu *menu;                    //菜单
    QAction*update;                 //更新
    QAction*del;                    //删除
    int dataBaseCount;              //查询的数据条数
    int flage;                      //打开窗口标志位
    int changeData;                 //切换主题标志位
    int rowCount;                   //鼠标点击的行

    /********************创建操作excel对象*****************/
    QAxObject *excel;
    QAxObject *workBooks;
    QAxObject *workBook;
    QAxObject *workSheets;
    QAxObject *workSheet;

private:
    /****************添加控件函数******************/
    void addControlWidget();


    /****************创建菜单栏目******************/
    void createActions();


    /****************重写菜单事件函数***************/
    void contextMenuEvent(QContextMenuEvent *event);

    void changeEvent(QEvent*event);
};

#endif // MAINWINDOW_H
class winMainThread:public QThread
{
    MainWindow * windowThread;
    int flage;
public :
    winMainThread(MainWindow * windowThread, int flage);
public:
    virtual void run();

};
