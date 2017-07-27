/********************************************************************************
** Form generated from reading UI file 'customplottab.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMPLOTTAB_H
#define UI_CUSTOMPLOTTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_customPlotTab
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_15;
    QSpacerItem *horizontalSpacer_25;
    QPushButton *pushButtonReadMessage;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *pushButtonReadInfo;
    QSpacerItem *horizontalSpacer_16;
    QPushButton *pushButtonClear;
    QSpacerItem *horizontalSpacer_17;
    QPushButton *pushButtonScreen;
    QSpacerItem *horizontalSpacer_19;
    QCheckBox *checkBoxMoveChange;
    QSpacerItem *horizontalSpacer_18;
    QCheckBox *checkBoxPicChange;
    QSpacerItem *horizontalSpacer_20;
    QCheckBox *checkBoxBackGroundCge;
    QSpacerItem *horizontalSpacer_21;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_17;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_16;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot_2;
    QHBoxLayout *horizontalLayout_17;
    QCustomPlot *customPlot_3;
    QCustomPlot *customPlot_4;

    void setupUi(QWidget *customPlotTab)
    {
        if (customPlotTab->objectName().isEmpty())
            customPlotTab->setObjectName(QStringLiteral("customPlotTab"));
        customPlotTab->resize(785, 506);
        verticalLayout = new QVBoxLayout(customPlotTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        groupBox_7 = new QGroupBox(customPlotTab);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 55));
        groupBox_7->setMaximumSize(QSize(16777215, 55));
        verticalLayout_14 = new QVBoxLayout(groupBox_7);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_25);

        pushButtonReadMessage = new QPushButton(groupBox_7);
        pushButtonReadMessage->setObjectName(QStringLiteral("pushButtonReadMessage"));
        pushButtonReadMessage->setMinimumSize(QSize(100, 25));

        horizontalLayout_15->addWidget(pushButtonReadMessage);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_15);

        pushButtonReadInfo = new QPushButton(groupBox_7);
        pushButtonReadInfo->setObjectName(QStringLiteral("pushButtonReadInfo"));
        pushButtonReadInfo->setMinimumSize(QSize(100, 25));

        horizontalLayout_15->addWidget(pushButtonReadInfo);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_16);

        pushButtonClear = new QPushButton(groupBox_7);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setMinimumSize(QSize(100, 25));

        horizontalLayout_15->addWidget(pushButtonClear);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_17);

        pushButtonScreen = new QPushButton(groupBox_7);
        pushButtonScreen->setObjectName(QStringLiteral("pushButtonScreen"));
        pushButtonScreen->setMinimumSize(QSize(100, 25));

        horizontalLayout_15->addWidget(pushButtonScreen);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_19);

        checkBoxMoveChange = new QCheckBox(groupBox_7);
        checkBoxMoveChange->setObjectName(QStringLiteral("checkBoxMoveChange"));
        checkBoxMoveChange->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(checkBoxMoveChange);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_18);

        checkBoxPicChange = new QCheckBox(groupBox_7);
        checkBoxPicChange->setObjectName(QStringLiteral("checkBoxPicChange"));
        checkBoxPicChange->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(checkBoxPicChange);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_20);

        checkBoxBackGroundCge = new QCheckBox(groupBox_7);
        checkBoxBackGroundCge->setObjectName(QStringLiteral("checkBoxBackGroundCge"));
        checkBoxBackGroundCge->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_15->addWidget(checkBoxBackGroundCge);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_21);


        verticalLayout_14->addLayout(horizontalLayout_15);


        verticalLayout_16->addWidget(groupBox_7);

        groupBox_6 = new QGroupBox(customPlotTab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setStyleSheet(QStringLiteral(""));
        verticalLayout_17 = new QVBoxLayout(groupBox_6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        customPlot = new QCustomPlot(groupBox_6);
        customPlot->setObjectName(QStringLiteral("customPlot"));

        horizontalLayout_16->addWidget(customPlot);

        customPlot_2 = new QCustomPlot(groupBox_6);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));

        horizontalLayout_16->addWidget(customPlot_2);


        verticalLayout_15->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        customPlot_3 = new QCustomPlot(groupBox_6);
        customPlot_3->setObjectName(QStringLiteral("customPlot_3"));

        horizontalLayout_17->addWidget(customPlot_3);

        customPlot_4 = new QCustomPlot(groupBox_6);
        customPlot_4->setObjectName(QStringLiteral("customPlot_4"));

        horizontalLayout_17->addWidget(customPlot_4);


        verticalLayout_15->addLayout(horizontalLayout_17);


        verticalLayout_17->addLayout(verticalLayout_15);


        verticalLayout_16->addWidget(groupBox_6);


        verticalLayout->addLayout(verticalLayout_16);


        retranslateUi(customPlotTab);

        QMetaObject::connectSlotsByName(customPlotTab);
    } // setupUi

    void retranslateUi(QWidget *customPlotTab)
    {
        customPlotTab->setWindowTitle(QApplication::translate("customPlotTab", "Form", 0));
        groupBox_7->setTitle(QString());
        pushButtonReadMessage->setText(QApplication::translate("customPlotTab", "\350\257\273\345\217\226\344\277\241\346\201\257", 0));
        pushButtonReadInfo->setText(QApplication::translate("customPlotTab", "\350\257\273\345\217\226", 0));
        pushButtonClear->setText(QApplication::translate("customPlotTab", "\346\270\205\347\251\272", 0));
        pushButtonScreen->setText(QApplication::translate("customPlotTab", "\346\210\252\345\261\217", 0));
        checkBoxMoveChange->setText(QApplication::translate("customPlotTab", "\347\247\273\345\212\250\347\274\251\346\224\276", 0));
        checkBoxPicChange->setText(QApplication::translate("customPlotTab", "\345\233\276\344\276\213\350\257\264\346\230\216", 0));
        checkBoxBackGroundCge->setText(QApplication::translate("customPlotTab", "\351\230\264\345\275\261\350\203\214\346\231\257", 0));
        groupBox_6->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class customPlotTab: public Ui_customPlotTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMPLOTTAB_H
