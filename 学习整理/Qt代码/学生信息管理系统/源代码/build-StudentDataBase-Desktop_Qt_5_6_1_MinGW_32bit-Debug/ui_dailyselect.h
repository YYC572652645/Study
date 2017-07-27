/********************************************************************************
** Form generated from reading UI file 'dailyselect.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAILYSELECT_H
#define UI_DAILYSELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DailySelect
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButtonDorNumberSec;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButtonDorStatusSec;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *DailySelect)
    {
        if (DailySelect->objectName().isEmpty())
            DailySelect->setObjectName(QStringLiteral("DailySelect"));
        DailySelect->resize(970, 513);
        verticalLayout_2 = new QVBoxLayout(DailySelect);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(DailySelect);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));
        label_2->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(DailySelect);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(150, 25));
        lineEdit->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(lineEdit);

        pushButtonDorNumberSec = new QPushButton(DailySelect);
        pushButtonDorNumberSec->setObjectName(QStringLiteral("pushButtonDorNumberSec"));
        pushButtonDorNumberSec->setMinimumSize(QSize(150, 25));
        pushButtonDorNumberSec->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(pushButtonDorNumberSec);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(DailySelect);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(70, 0));
        label->setMaximumSize(QSize(70, 16777215));

        horizontalLayout->addWidget(label);

        comboBox = new QComboBox(DailySelect);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(150, 25));
        comboBox->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(comboBox);

        pushButtonDorStatusSec = new QPushButton(DailySelect);
        pushButtonDorStatusSec->setObjectName(QStringLiteral("pushButtonDorStatusSec"));
        pushButtonDorStatusSec->setMinimumSize(QSize(150, 25));
        pushButtonDorStatusSec->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(pushButtonDorStatusSec);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(DailySelect);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DailySelect);

        QMetaObject::connectSlotsByName(DailySelect);
    } // setupUi

    void retranslateUi(QWidget *DailySelect)
    {
        DailySelect->setWindowTitle(QApplication::translate("DailySelect", "Form", 0));
        label_2->setText(QApplication::translate("DailySelect", "\345\256\277\350\210\215\345\217\267\357\274\232", 0));
        pushButtonDorNumberSec->setText(QApplication::translate("DailySelect", "\346\237\245\350\257\242", 0));
        label->setText(QApplication::translate("DailySelect", "\345\256\277\350\210\215\346\203\205\345\206\265\357\274\232", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("DailySelect", "\351\200\232\346\212\245\346\211\271\350\257\204", 0)
         << QApplication::translate("DailySelect", "\351\200\232\346\212\245\350\241\250\346\211\254", 0)
        );
        pushButtonDorStatusSec->setText(QApplication::translate("DailySelect", "\346\237\245\350\257\242", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DailySelect", "\345\256\277\350\210\215\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DailySelect", "\345\256\277\350\210\215\346\203\205\345\206\265", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DailySelect", "\346\227\266\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class DailySelect: public Ui_DailySelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAILYSELECT_H
