/********************************************************************************
** Form generated from reading UI file 'setuplangue.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUPLANGUE_H
#define UI_SETUPLANGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_setuplangue
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QRadioButton *radioButtonChinese;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButtonEnglish;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonOk;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *setuplangue)
    {
        if (setuplangue->objectName().isEmpty())
            setuplangue->setObjectName(QStringLiteral("setuplangue"));
        setuplangue->resize(189, 126);
        setuplangue->setMinimumSize(QSize(189, 126));
        setuplangue->setMaximumSize(QSize(189, 126));
        verticalLayout_2 = new QVBoxLayout(setuplangue);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        radioButtonChinese = new QRadioButton(setuplangue);
        radioButtonChinese->setObjectName(QStringLiteral("radioButtonChinese"));
        radioButtonChinese->setChecked(true);

        horizontalLayout->addWidget(radioButtonChinese);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        radioButtonEnglish = new QRadioButton(setuplangue);
        radioButtonEnglish->setObjectName(QStringLiteral("radioButtonEnglish"));

        horizontalLayout->addWidget(radioButtonEnglish);


        verticalLayout->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonOk = new QPushButton(setuplangue);
        pushButtonOk->setObjectName(QStringLiteral("pushButtonOk"));

        horizontalLayout_2->addWidget(pushButtonOk);

        pushButtonCancel = new QPushButton(setuplangue);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(setuplangue);

        QMetaObject::connectSlotsByName(setuplangue);
    } // setupUi

    void retranslateUi(QDialog *setuplangue)
    {
        setuplangue->setWindowTitle(QApplication::translate("setuplangue", "Dialog", 0));
        radioButtonChinese->setText(QApplication::translate("setuplangue", "\344\270\255\346\226\207", 0));
        radioButtonEnglish->setText(QApplication::translate("setuplangue", "\350\213\261\346\226\207", 0));
        pushButtonOk->setText(QApplication::translate("setuplangue", "\347\241\256\345\256\232", 0));
        pushButtonCancel->setText(QApplication::translate("setuplangue", "\345\217\226\346\266\210", 0));
    } // retranslateUi

};

namespace Ui {
    class setuplangue: public Ui_setuplangue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUPLANGUE_H
