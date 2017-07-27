/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEXIT;
    QAction *actionInsert;
    QAction *actionSelect;
    QAction *actionPoliticalInsert;
    QAction *actionPoliticalSelect;
    QAction *actionCutSchoolInsert;
    QAction *actionCutSchoolSelect;
    QAction *actionNotPassInsert;
    QAction *actionNotPassSelect;
    QAction *actionHornorInsert;
    QAction *actionHornorSelect;
    QAction *actionDayInsert;
    QAction *actionDaySelect;
    QAction *actionOutLineInsert;
    QAction *actionOutLineSelect;
    QAction *actionGradeInsert;
    QAction *actionGradeSelect;
    QAction *actionChangeStyle;
    QAction *actionXinXi;
    QAction *actionJiaowu;
    QAction *actionScreen;
    QAction *actionMovie;
    QAction *actionBaiDu;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidgetData;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(841, 483);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        actionEXIT = new QAction(MainWindow);
        actionEXIT->setObjectName(QStringLiteral("actionEXIT"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEXIT->setIcon(icon);
        actionInsert = new QAction(MainWindow);
        actionInsert->setObjectName(QStringLiteral("actionInsert"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/system-users.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert->setIcon(icon1);
        actionSelect = new QAction(MainWindow);
        actionSelect->setObjectName(QStringLiteral("actionSelect"));
        actionSelect->setIcon(icon1);
        actionPoliticalInsert = new QAction(MainWindow);
        actionPoliticalInsert->setObjectName(QStringLiteral("actionPoliticalInsert"));
        actionPoliticalInsert->setIcon(icon1);
        actionPoliticalSelect = new QAction(MainWindow);
        actionPoliticalSelect->setObjectName(QStringLiteral("actionPoliticalSelect"));
        actionPoliticalSelect->setIcon(icon1);
        actionCutSchoolInsert = new QAction(MainWindow);
        actionCutSchoolInsert->setObjectName(QStringLiteral("actionCutSchoolInsert"));
        actionCutSchoolInsert->setIcon(icon1);
        actionCutSchoolSelect = new QAction(MainWindow);
        actionCutSchoolSelect->setObjectName(QStringLiteral("actionCutSchoolSelect"));
        actionCutSchoolSelect->setIcon(icon1);
        actionNotPassInsert = new QAction(MainWindow);
        actionNotPassInsert->setObjectName(QStringLiteral("actionNotPassInsert"));
        actionNotPassInsert->setIcon(icon1);
        actionNotPassSelect = new QAction(MainWindow);
        actionNotPassSelect->setObjectName(QStringLiteral("actionNotPassSelect"));
        actionNotPassSelect->setIcon(icon1);
        actionHornorInsert = new QAction(MainWindow);
        actionHornorInsert->setObjectName(QStringLiteral("actionHornorInsert"));
        actionHornorInsert->setIcon(icon1);
        actionHornorSelect = new QAction(MainWindow);
        actionHornorSelect->setObjectName(QStringLiteral("actionHornorSelect"));
        actionHornorSelect->setIcon(icon1);
        actionDayInsert = new QAction(MainWindow);
        actionDayInsert->setObjectName(QStringLiteral("actionDayInsert"));
        actionDayInsert->setIcon(icon1);
        actionDaySelect = new QAction(MainWindow);
        actionDaySelect->setObjectName(QStringLiteral("actionDaySelect"));
        actionDaySelect->setIcon(icon1);
        actionOutLineInsert = new QAction(MainWindow);
        actionOutLineInsert->setObjectName(QStringLiteral("actionOutLineInsert"));
        actionOutLineInsert->setIcon(icon1);
        actionOutLineSelect = new QAction(MainWindow);
        actionOutLineSelect->setObjectName(QStringLiteral("actionOutLineSelect"));
        actionOutLineSelect->setIcon(icon1);
        actionGradeInsert = new QAction(MainWindow);
        actionGradeInsert->setObjectName(QStringLiteral("actionGradeInsert"));
        actionGradeInsert->setIcon(icon1);
        actionGradeSelect = new QAction(MainWindow);
        actionGradeSelect->setObjectName(QStringLiteral("actionGradeSelect"));
        actionGradeSelect->setIcon(icon1);
        actionChangeStyle = new QAction(MainWindow);
        actionChangeStyle->setObjectName(QStringLiteral("actionChangeStyle"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/square.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChangeStyle->setIcon(icon2);
        actionXinXi = new QAction(MainWindow);
        actionXinXi->setObjectName(QStringLiteral("actionXinXi"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/internet-web-browser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionXinXi->setIcon(icon3);
        actionJiaowu = new QAction(MainWindow);
        actionJiaowu->setObjectName(QStringLiteral("actionJiaowu"));
        actionJiaowu->setIcon(icon3);
        actionScreen = new QAction(MainWindow);
        actionScreen->setObjectName(QStringLiteral("actionScreen"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/gallery.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScreen->setIcon(icon4);
        actionMovie = new QAction(MainWindow);
        actionMovie->setObjectName(QStringLiteral("actionMovie"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image/videos.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMovie->setIcon(icon5);
        actionBaiDu = new QAction(MainWindow);
        actionBaiDu->setObjectName(QStringLiteral("actionBaiDu"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/image/Baidu.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBaiDu->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidgetData = new QTableWidget(centralWidget);
        if (tableWidgetData->columnCount() < 31)
            tableWidgetData->setColumnCount(31);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(20, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(21, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(22, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(23, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(24, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(25, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(26, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(27, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(28, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(29, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidgetData->setHorizontalHeaderItem(30, __qtablewidgetitem30);
        tableWidgetData->setObjectName(QStringLiteral("tableWidgetData"));

        verticalLayout->addWidget(tableWidgetData);

        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QStringLiteral("toolBar_2"));
        toolBar_2->setMovable(false);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar_2);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 841, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionJiaowu);
        toolBar->addAction(actionXinXi);
        toolBar->addSeparator();
        toolBar->addAction(actionMovie);
        toolBar->addAction(actionScreen);
        toolBar->addAction(actionChangeStyle);
        toolBar->addSeparator();
        toolBar->addAction(actionEXIT);
        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionInsert);
        menu->addAction(actionSelect);
        menu->addSeparator();
        menu->addAction(actionPoliticalInsert);
        menu->addAction(actionPoliticalSelect);
        menu->addSeparator();
        menu->addAction(actionCutSchoolInsert);
        menu->addAction(actionCutSchoolSelect);
        menu->addSeparator();
        menu->addAction(actionNotPassInsert);
        menu->addAction(actionNotPassSelect);
        menu->addSeparator();
        menu->addAction(actionHornorInsert);
        menu->addAction(actionHornorSelect);
        menu->addSeparator();
        menu->addAction(actionDayInsert);
        menu->addAction(actionDaySelect);
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(actionOutLineInsert);
        menu->addAction(actionOutLineSelect);
        menu->addSeparator();
        menu->addSeparator();
        menu->addAction(actionGradeInsert);
        menu->addAction(actionGradeSelect);
        menu->addSeparator();
        menu->addSeparator();
        menu_2->addAction(actionXinXi);
        menu_2->addAction(actionJiaowu);
        menu_2->addAction(actionBaiDu);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEXIT->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#ifndef QT_NO_TOOLTIP
        actionEXIT->setToolTip(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", 0));
#endif // QT_NO_TOOLTIP
        actionInsert->setText(QApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257\345\275\225\345\205\245", 0));
        actionSelect->setText(QApplication::translate("MainWindow", "\345\237\272\346\234\254\344\277\241\346\201\257\346\237\245\350\257\242", 0));
        actionPoliticalInsert->setText(QApplication::translate("MainWindow", "\346\224\277\346\262\273\351\235\242\350\262\214\345\275\225\345\205\245", 0));
        actionPoliticalSelect->setText(QApplication::translate("MainWindow", "\346\224\277\346\262\273\351\235\242\350\262\214\346\237\245\350\257\242", 0));
        actionCutSchoolInsert->setText(QApplication::translate("MainWindow", "\346\227\267\350\257\276\346\203\205\345\206\265\345\275\225\345\205\245", 0));
        actionCutSchoolSelect->setText(QApplication::translate("MainWindow", "\346\227\267\350\257\276\346\203\205\345\206\265\346\237\245\350\257\242", 0));
        actionNotPassInsert->setText(QApplication::translate("MainWindow", "\346\214\202\347\247\221\346\203\205\345\206\265\345\275\225\345\205\245", 0));
        actionNotPassSelect->setText(QApplication::translate("MainWindow", "\346\214\202\347\247\221\346\203\205\345\206\265\346\237\245\350\257\242", 0));
        actionHornorInsert->setText(QApplication::translate("MainWindow", "\350\216\267\345\245\226\346\203\205\345\206\265\345\275\225\345\205\245", 0));
        actionHornorSelect->setText(QApplication::translate("MainWindow", "\350\216\267\345\245\226\346\203\205\345\206\265\346\237\245\350\257\242", 0));
        actionDayInsert->setText(QApplication::translate("MainWindow", "\346\227\245\345\270\270\346\203\205\345\206\265\345\275\225\345\205\245", 0));
        actionDaySelect->setText(QApplication::translate("MainWindow", "\346\227\245\345\270\270\346\203\205\345\206\265\346\237\245\350\257\242", 0));
        actionOutLineInsert->setText(QApplication::translate("MainWindow", "\350\277\235\350\247\204\350\277\235\347\272\252\345\275\225\345\205\245", 0));
        actionOutLineSelect->setText(QApplication::translate("MainWindow", "\350\277\235\350\247\204\350\277\235\347\272\252\346\237\245\350\257\242", 0));
        actionGradeInsert->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251\346\216\222\345\220\215\345\275\225\345\205\245", 0));
        actionGradeSelect->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251\346\216\222\345\220\215\346\237\245\350\257\242", 0));
        actionChangeStyle->setText(QApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\273\351\242\230", 0));
#ifndef QT_NO_TOOLTIP
        actionChangeStyle->setToolTip(QApplication::translate("MainWindow", "\345\210\207\346\215\242\344\270\273\351\242\230", 0));
#endif // QT_NO_TOOLTIP
        actionXinXi->setText(QApplication::translate("MainWindow", "\344\277\241\346\201\257\345\267\245\347\250\213\345\255\246\351\231\242\347\275\221\347\253\231", 0));
        actionJiaowu->setText(QApplication::translate("MainWindow", "\346\225\231\345\212\241\345\244\204\347\275\221\347\253\231", 0));
#ifndef QT_NO_TOOLTIP
        actionJiaowu->setToolTip(QApplication::translate("MainWindow", "\346\225\231\345\212\241\345\244\204\347\275\221\347\253\231", 0));
#endif // QT_NO_TOOLTIP
        actionScreen->setText(QApplication::translate("MainWindow", "\346\210\252\345\261\217", 0));
#ifndef QT_NO_TOOLTIP
        actionScreen->setToolTip(QApplication::translate("MainWindow", "\346\210\252\345\261\217", 0));
#endif // QT_NO_TOOLTIP
        actionMovie->setText(QApplication::translate("MainWindow", "\346\222\255\346\224\276\350\247\206\351\242\221", 0));
#ifndef QT_NO_TOOLTIP
        actionMovie->setToolTip(QApplication::translate("MainWindow", "\346\222\255\346\224\276\350\247\206\351\242\221", 0));
#endif // QT_NO_TOOLTIP
        actionBaiDu->setText(QApplication::translate("MainWindow", "\347\231\276\345\272\246\344\270\200\344\270\213", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetData->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetData->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\346\200\247\345\210\253", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetData->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetData->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\346\260\221\346\227\217", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetData->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\345\207\272\347\224\237\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetData->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\346\224\277\346\262\273\351\235\242\350\262\214", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetData->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\345\255\246\351\231\242", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetData->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\344\270\223\344\270\232\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetData->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidgetData->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\345\256\277\350\210\215\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidgetData->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\345\272\212\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidgetData->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "\350\272\253\344\273\275\350\257\201\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetData->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "\351\223\266\350\241\214\345\215\241\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetData->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "\351\202\256\347\274\226", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetData->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "QQ", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetData->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "\346\210\267\345\217\243\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetData->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "\345\256\266\345\272\255\344\275\217\345\235\200", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetData->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "\347\224\237\346\272\220\345\234\260", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetData->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "\345\215\225\344\272\262", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetData->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "\350\264\253\345\233\260", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetData->horizontalHeaderItem(20);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "\346\234\215\345\205\265\345\275\271", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetData->horizontalHeaderItem(21);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "\347\225\231\345\255\246", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetData->horizontalHeaderItem(22);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "\345\221\250\346\234\253\345\233\236\345\256\266", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetData->horizontalHeaderItem(23);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "\350\265\260\350\257\273", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidgetData->horizontalHeaderItem(24);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "\347\210\266\344\272\262\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidgetData->horizontalHeaderItem(25);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "\347\224\265\350\257\235", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidgetData->horizontalHeaderItem(26);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidgetData->horizontalHeaderItem(27);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "\346\257\215\344\272\262\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidgetData->horizontalHeaderItem(28);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "\347\224\265\350\257\235", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidgetData->horizontalHeaderItem(29);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "\345\215\225\344\275\215", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidgetData->horizontalHeaderItem(30);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "\344\270\252\344\272\272\347\224\265\350\257\235", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\345\255\246\347\224\237\344\277\241\346\201\257", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\255\246\346\240\241\347\275\221\347\253\231", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
