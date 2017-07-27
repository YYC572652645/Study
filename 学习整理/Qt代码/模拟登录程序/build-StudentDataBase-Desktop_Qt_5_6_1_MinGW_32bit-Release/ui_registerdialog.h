/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

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

class Ui_RegisterDialog
{
public:
    QPushButton *pushButtonRegister;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditUserName;
    QLineEdit *lineEditPassWord;
    QLineEdit *lineEditPassWordAgain;
    QLabel *label_3;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(400, 300);
        RegisterDialog->setModal(true);
        pushButtonRegister = new QPushButton(RegisterDialog);
        pushButtonRegister->setObjectName(QStringLiteral("pushButtonRegister"));
        pushButtonRegister->setEnabled(true);
        pushButtonRegister->setGeometry(QRect(90, 230, 181, 31));
        label = new QLabel(RegisterDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 42, 54, 41));
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 100, 61, 31));
        lineEditUserName = new QLineEdit(RegisterDialog);
        lineEditUserName->setObjectName(QStringLiteral("lineEditUserName"));
        lineEditUserName->setGeometry(QRect(160, 50, 161, 31));
        lineEditPassWord = new QLineEdit(RegisterDialog);
        lineEditPassWord->setObjectName(QStringLiteral("lineEditPassWord"));
        lineEditPassWord->setGeometry(QRect(160, 100, 161, 31));
        lineEditPassWordAgain = new QLineEdit(RegisterDialog);
        lineEditPassWordAgain->setObjectName(QStringLiteral("lineEditPassWordAgain"));
        lineEditPassWordAgain->setGeometry(QRect(162, 160, 161, 31));
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 160, 101, 31));

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", 0));
        pushButtonRegister->setText(QApplication::translate("RegisterDialog", "\346\263\250\345\206\214", 0));
        label->setText(QApplication::translate("RegisterDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_2->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", 0));
        label_3->setText(QApplication::translate("RegisterDialog", "\345\206\215\350\276\223\344\270\200\346\254\241\345\257\206\347\240\201\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
