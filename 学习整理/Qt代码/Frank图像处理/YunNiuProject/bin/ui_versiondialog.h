/********************************************************************************
** Form generated from reading UI file 'versiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERSIONDIALOG_H
#define UI_VERSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VersionDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *labelVersionImage;
    QLineEdit *lineEdit;

    void setupUi(QDialog *VersionDialog)
    {
        if (VersionDialog->objectName().isEmpty())
            VersionDialog->setObjectName(QStringLiteral("VersionDialog"));
        VersionDialog->resize(460, 387);
        VersionDialog->setMinimumSize(QSize(460, 387));
        VersionDialog->setMaximumSize(QSize(460, 387));
        verticalLayout_2 = new QVBoxLayout(VersionDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelVersionImage = new QLabel(VersionDialog);
        labelVersionImage->setObjectName(QStringLiteral("labelVersionImage"));
        labelVersionImage->setStyleSheet(QStringLiteral("background-image: url(:/image/res/Version.png);"));

        verticalLayout->addWidget(labelVersionImage);

        lineEdit = new QLineEdit(VersionDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(lineEdit);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(VersionDialog);

        QMetaObject::connectSlotsByName(VersionDialog);
    } // setupUi

    void retranslateUi(QDialog *VersionDialog)
    {
        VersionDialog->setWindowTitle(QApplication::translate("VersionDialog", "Dialog", 0));
        labelVersionImage->setText(QString());
        lineEdit->setText(QApplication::translate("VersionDialog", "Frank View", 0));
    } // retranslateUi

};

namespace Ui {
    class VersionDialog: public Ui_VersionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERSIONDIALOG_H
