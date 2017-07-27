#ifndef VERSIONDIALOG_H
#define VERSIONDIALOG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDialog>

/***************************************************************
   功能:版本信息窗口

   创建人:殷宇辰

   创建时间:2017-6-22
**************************************************************/

namespace Ui {
class VersionDialog;
}

class VersionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VersionDialog(QWidget *parent = 0);
    ~VersionDialog();

private:
    Ui::VersionDialog *ui;
};

#endif // VERSIONDIALOG_H
