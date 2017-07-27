/********************************************************************************
** Form generated from reading UI file 'backpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKPASSWORDDIALOG_H
#define UI_BACKPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BackPassWordDialog
{
public:
    QLabel *label;
    QLineEdit *lineEditUsm;
    QLabel *label_2;
    QPushButton *pushButtonBack;
    QLineEdit *lineEditPsd;

    void setupUi(QDialog *BackPassWordDialog)
    {
        if (BackPassWordDialog->objectName().isEmpty())
            BackPassWordDialog->setObjectName(QStringLiteral("BackPassWordDialog"));
        BackPassWordDialog->resize(337, 265);
        BackPassWordDialog->setModal(true);
        label = new QLabel(BackPassWordDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 40, 41, 31));
        lineEditUsm = new QLineEdit(BackPassWordDialog);
        lineEditUsm->setObjectName(QStringLiteral("lineEditUsm"));
        lineEditUsm->setGeometry(QRect(140, 40, 113, 31));
        label_2 = new QLabel(BackPassWordDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(80, 100, 41, 31));
        pushButtonBack = new QPushButton(BackPassWordDialog);
        pushButtonBack->setObjectName(QStringLiteral("pushButtonBack"));
        pushButtonBack->setGeometry(QRect(90, 180, 151, 41));
        lineEditPsd = new QLineEdit(BackPassWordDialog);
        lineEditPsd->setObjectName(QStringLiteral("lineEditPsd"));
        lineEditPsd->setGeometry(QRect(140, 100, 113, 31));

        retranslateUi(BackPassWordDialog);

        QMetaObject::connectSlotsByName(BackPassWordDialog);
    } // setupUi

    void retranslateUi(QDialog *BackPassWordDialog)
    {
        BackPassWordDialog->setWindowTitle(QApplication::translate("BackPassWordDialog", "Dialog", 0));
        label->setText(QApplication::translate("BackPassWordDialog", "\345\270\220\345\217\267\357\274\232", 0));
        label_2->setText(QApplication::translate("BackPassWordDialog", "\345\257\206\347\240\201\357\274\232", 0));
        pushButtonBack->setText(QApplication::translate("BackPassWordDialog", "\346\211\276\345\233\236\345\257\206\347\240\201", 0));
    } // retranslateUi

};

namespace Ui {
    class BackPassWordDialog: public Ui_BackPassWordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKPASSWORDDIALOG_H
