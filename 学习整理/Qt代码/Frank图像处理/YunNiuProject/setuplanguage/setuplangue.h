#ifndef SETUPLANGUE_H
#define SETUPLANGUE_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>
#include <QTranslator>

/***************************************************************
   功能:设置语言的窗口

   创建人:殷宇辰

   创建时间:2017-7-1
**************************************************************/

namespace Ui {
class setuplangue;
}

class SetUpLangue : public QDialog
{
    Q_OBJECT

public:
    explicit SetUpLangue(QWidget *parent = 0);
    ~SetUpLangue();

private slots:
    void on_pushButtonOk_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::setuplangue *ui;

    QTranslator translater;

signals:
    void sendLanguage(int language);  //告诉主窗体改变了语言
};

#endif // SETUPLANGUE_H
