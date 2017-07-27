#ifndef ADDWIDGETTAB_H
#define ADDWIDGETTAB_H
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QWidget>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
namespace Ui {
class addWidgetTab;
}

class addWidgetTab : public QWidget
{
    Q_OBJECT

public:
    explicit addWidgetTab(QWidget *parent = 0);
    ~addWidgetTab();

public slots:
    /**********************选择探头**********************/
    void on_comboBox_currentIndexChanged(int index);

public:
    Ui::addWidgetTab *ui;

    /**********************添加控件***********************/
    void addWidgetControl();
public:
    QWidget     *widgetZero[14];         //指令
    QVBoxLayout *vboxLayoutZero[14];     //居中控件
    QComboBox   *lineEditZero[14];       //指令
    QLabel      *lableZero[14];          //信息
    QWidget     *widgetOne[17];          //指令
    QVBoxLayout *vboxLayoutOne[17];      //居中控件
    QLineEdit   *lineEditOne[17];        //指令
    QLabel      *lableOne[17];           //信息
    QWidget     *widgetTwo[17];          //指令
    QVBoxLayout *vboxLayoutTwo[17];      //居中控件
    QLineEdit   *lineEditTwo[17];        //指令
    QLabel      *lableTwo[17];           //信息
    QWidget     *widgetThree[17];        //指令
    QVBoxLayout *vboxLayoutThree[17];    //居中控件
    QLineEdit   *lineEditThree[17];      //指令
    QLabel      *lableThree[17];         //信息
    QWidget     *widgetFour[17];         //指令
    QVBoxLayout *vboxLayoutFour[17];     //居中控件
    QLineEdit   *lineEditFour[17];       //指令
    QLabel      *lableFour[17];          //信息
    QWidget     *widgetFive[17];         //指令
    QVBoxLayout *vboxLayoutFive[17];     //居中控件
    QLineEdit   *lineEditFive[17];       //指令
    QLabel      *lableFive[17];          //信息
    QWidget     *widgetSix[17];          //指令
    QVBoxLayout *vboxLayoutSix[17];      //居中控件
    QLineEdit   *lineEditSix[17];        //指令
    QLabel      *lableSix[17];           //信息
    QWidget     *widgetSeven[17];        //指令
    QVBoxLayout *vboxLayoutSeven[17];    //居中控件
    QLineEdit   *lineEditSeven[17];      //指令
    QLabel      *lableSeven[17];         //信息
    QWidget     *widgetEight[17];        //指令
    QVBoxLayout *vboxLayoutEight[17];    //居中控件
    QLineEdit   *lineEditEight[17];      //指令
    QLabel      *lableEight[17];         //信息
    QWidget     *widgetOneThree[5];      //指令
    QVBoxLayout *vboxLayoutOneThree[5];  //居中控件
    QLineEdit   *lineEditOneThree[5];    //指令
    QLabel      *lableOneThree[5];       //信息
    QWidget     *widgetOneA[5];          //指令
    QVBoxLayout *vboxLayoutOneA[5];      //居中控件
    QComboBox   *lineEditOneA[5];        //指令
    QLabel      *lableOneA[5];           //信息
    QWidget     *widgetTwoZero[11];      //指令
    QVBoxLayout *vboxLayoutTwoZero[11];  //居中控件
    QComboBox   *lineEditTwoZero[11];    //指令
    QLabel      *lableTwoZero[11];       //信息
    QWidget     *widgetTwoTwo[11];       //指令
    QVBoxLayout *vboxLayoutTwoTwo[11];   //居中控件
    QComboBox   *lineEditTwoTwo[11];     //指令
    QLabel      *lableTwoTwo[11];        //信息
    QWidget     *widgetTwoFour[11];      //指令
    QVBoxLayout *vboxLayoutTwoFour[11];  //居中控件
    QComboBox   *lineEditTwoFour[11];    //指令
    QLabel      *lableTwoFour[11];       //信息
    QWidget     *widgetTwoSix[11];       //指令
    QVBoxLayout *vboxLayoutTwoSix[11];   //居中控件
    QComboBox   *lineEditTwoSix[11];     //指令
    QLabel      *lableTwoSix[11];        //信息
    QWidget     *widgetTwoEight[11];     //指令
    QVBoxLayout *vboxLayoutTwoEight[11]; //居中控件
    QComboBox   *lineEditTwoEight[11];   //指令
    QLabel      *lableTwoEight[11];      //信息
    QWidget     *widgetTwoA[11];         //指令
    QVBoxLayout *vboxLayoutTwoA[11];     //居中控件
    QComboBox   *lineEditTwoA[11];       //指令
    QLabel      *lableTwoA[11];          //信息
    QWidget     *widgetTwoC[12];         //指令
    QVBoxLayout *vboxLayoutTwoC[12];     //居中控件
    QLineEdit   *lineEditTwoC[12];       //指令
    QLabel      *lableTwoC[12];          //信息
    QWidget     *widgetTwoE[13];         //指令
    QVBoxLayout *vboxLayoutTwoE[13];     //居中控件
    QComboBox   *lineEditTwoE[13];       //指令
    QLabel      *lableTwoE[13];          //信息
    QWidget     *widgetThreeA[5];        //指令
    QVBoxLayout *vboxLayoutThreeA[5];    //居中控件
    QLineEdit   *lineEditThreeA[5];      //指令
    QLabel      *lableThreeA[5];         //信息
    QWidget     *widgetThreeZero[11];    //指令
    QVBoxLayout *vboxLayoutThreeZero[11];//居中控件
    QComboBox   *lineEditThreeZero[11];  //指令
    QLabel      *lableThreeZero[11];     //信息
private slots:
    void on_pushButton_2_clicked();
    void on_pushButtonSaveInfo_clicked();

signals:
    void readInfo();
};

#endif // ADDWIDGETTAB_H


