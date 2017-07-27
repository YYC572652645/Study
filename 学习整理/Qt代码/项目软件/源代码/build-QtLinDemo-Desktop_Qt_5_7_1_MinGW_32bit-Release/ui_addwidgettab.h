/********************************************************************************
** Form generated from reading UI file 'addwidgettab.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWIDGETTAB_H
#define UI_ADDWIDGETTAB_H

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

class Ui_addWidgetTab
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_16;
    QLineEdit *lineEditX;
    QLabel *label_17;
    QLineEdit *lineEditY;
    QPushButton *pushButtonSaveInfo;
    QSpacerItem *horizontalSpacer_14;
    QTableWidget *tableWidget;

    void setupUi(QWidget *addWidgetTab)
    {
        if (addWidgetTab->objectName().isEmpty())
            addWidgetTab->setObjectName(QStringLiteral("addWidgetTab"));
        addWidgetTab->resize(616, 484);
        addWidgetTab->setStyleSheet(QStringLiteral(" background-color:rgba(69, 187, 217,255);"));
        verticalLayout = new QVBoxLayout(addWidgetTab);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        comboBox = new QComboBox(addWidgetTab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMinimumSize(QSize(120, 0));

        horizontalLayout_14->addWidget(comboBox);

        pushButton = new QPushButton(addWidgetTab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(100, 25));

        horizontalLayout_14->addWidget(pushButton);

        pushButton_2 = new QPushButton(addWidgetTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(100, 25));

        horizontalLayout_14->addWidget(pushButton_2);

        label_16 = new QLabel(addWidgetTab);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_14->addWidget(label_16);

        lineEditX = new QLineEdit(addWidgetTab);
        lineEditX->setObjectName(QStringLiteral("lineEditX"));

        horizontalLayout_14->addWidget(lineEditX);

        label_17 = new QLabel(addWidgetTab);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_14->addWidget(label_17);

        lineEditY = new QLineEdit(addWidgetTab);
        lineEditY->setObjectName(QStringLiteral("lineEditY"));

        horizontalLayout_14->addWidget(lineEditY);

        pushButtonSaveInfo = new QPushButton(addWidgetTab);
        pushButtonSaveInfo->setObjectName(QStringLiteral("pushButtonSaveInfo"));
        pushButtonSaveInfo->setMinimumSize(QSize(100, 25));

        horizontalLayout_14->addWidget(pushButtonSaveInfo);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_14);


        verticalLayout_12->addLayout(horizontalLayout_14);

        tableWidget = new QTableWidget(addWidgetTab);
        if (tableWidget->columnCount() < 17)
            tableWidget->setColumnCount(17);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        if (tableWidget->rowCount() < 21)
            tableWidget->setRowCount(21);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(20, __qtablewidgetitem37);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setStyleSheet(QStringLiteral(" background-color:rgba(69, 187, 217,255);"));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableWidget->setGridStyle(Qt::CustomDashLine);

        verticalLayout_12->addWidget(tableWidget);


        verticalLayout->addLayout(verticalLayout_12);

        QWidget::setTabOrder(pushButton, comboBox);
        QWidget::setTabOrder(comboBox, pushButton_2);
        QWidget::setTabOrder(pushButton_2, lineEditX);
        QWidget::setTabOrder(lineEditX, lineEditY);
        QWidget::setTabOrder(lineEditY, pushButtonSaveInfo);
        QWidget::setTabOrder(pushButtonSaveInfo, tableWidget);

        retranslateUi(addWidgetTab);

        QMetaObject::connectSlotsByName(addWidgetTab);
    } // setupUi

    void retranslateUi(QWidget *addWidgetTab)
    {
        addWidgetTab->setWindowTitle(QApplication::translate("addWidgetTab", "Form", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2641", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2642", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2643", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2644", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2645", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2646", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2647", 0)
         << QApplication::translate("addWidgetTab", "\346\216\242\345\244\2648", 0)
        );
        pushButton->setText(QApplication::translate("addWidgetTab", "\345\206\231\345\205\245", 0));
        pushButton_2->setText(QApplication::translate("addWidgetTab", "\350\257\273\345\217\226\346\225\260\346\215\256", 0));
        label_16->setText(QApplication::translate("addWidgetTab", "X:", 0));
        label_17->setText(QApplication::translate("addWidgetTab", "Y:", 0));
        pushButtonSaveInfo->setText(QApplication::translate("addWidgetTab", "\344\277\235\345\255\230", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("addWidgetTab", "\346\226\260\345\273\272\345\210\227", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("addWidgetTab", "0X00", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("addWidgetTab", "0X01", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("addWidgetTab", "0X02", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("addWidgetTab", "0X03", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem21->setText(QApplication::translate("addWidgetTab", "0X04", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem22->setText(QApplication::translate("addWidgetTab", "0X05", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem23->setText(QApplication::translate("addWidgetTab", "0X06", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem24->setText(QApplication::translate("addWidgetTab", "0X07", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem25->setText(QApplication::translate("addWidgetTab", "0X08", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem26->setText(QApplication::translate("addWidgetTab", "0X13", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem27->setText(QApplication::translate("addWidgetTab", "0X1A", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem28->setText(QApplication::translate("addWidgetTab", "0X20", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem29->setText(QApplication::translate("addWidgetTab", "0X22", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem30->setText(QApplication::translate("addWidgetTab", "0X24", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem31->setText(QApplication::translate("addWidgetTab", "0X26", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem32->setText(QApplication::translate("addWidgetTab", "0X28", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem33->setText(QApplication::translate("addWidgetTab", "0X2A", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem34->setText(QApplication::translate("addWidgetTab", "0X2C", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem35->setText(QApplication::translate("addWidgetTab", "0X2E", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem36->setText(QApplication::translate("addWidgetTab", "0X30", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(20);
        ___qtablewidgetitem37->setText(QApplication::translate("addWidgetTab", "0X3A", 0));
    } // retranslateUi

};

namespace Ui {
    class addWidgetTab: public Ui_addWidgetTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWIDGETTAB_H
