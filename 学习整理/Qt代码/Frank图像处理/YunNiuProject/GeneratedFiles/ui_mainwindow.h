/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenImage;
    QAction *actionOpenResult;
    QAction *actionOpenNextResult;
    QAction *actionOpenLastResult;
    QAction *actionExit;
    QAction *actionTool;
    QAction *actionAddTag;
    QAction *actionSaveResult;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionBlue;
    QAction *actionLight;
    QAction *actionGray;
    QAction *actionVersion;
    QAction *actionConfirmCompare;
    QAction *actionSureInitAll;
    QAction *actionOutPutImage;
    QAction *actionBlink;
    QAction *actionShowErrorRect;
    QAction *actionChoseWidget;
    QAction *actionMove;
    QAction *actionRool;
    QAction *actionRotate270;
    QAction *actionRotate90;
    QAction *actionCyan;
    QAction *actionMagenta;
    QAction *actionYellow;
    QAction *actionBlack;
    QAction *actionSetImportantError;
    QAction *actionSetError;
    QAction *actionRedColor;
    QAction *actionChengColor;
    QAction *actionYellowColor;
    QAction *actionGreenColor;
    QAction *actionCyanColor;
    QAction *actionBlueColor;
    QAction *actionPurpleColor;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitterFirst;
    QLabel *labelSourceImage;
    QSplitter *splitterSecond;
    QLabel *labelResultImage;
    QLabel *labelTargetImage;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_7;
    QMenu *menu_8;
    QMenu *menu_11;
    QMenu *menu_14;
    QMenu *menu_15;
    QMenu *menu_10;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1456, 877);
        MainWindow->setMinimumSize(QSize(900, 652));
        actionOpenImage = new QAction(MainWindow);
        actionOpenImage->setObjectName(QStringLiteral("actionOpenImage"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/res/open_souce.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenImage->setIcon(icon);
        actionOpenResult = new QAction(MainWindow);
        actionOpenResult->setObjectName(QStringLiteral("actionOpenResult"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/res/open1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenResult->setIcon(icon1);
        actionOpenNextResult = new QAction(MainWindow);
        actionOpenNextResult->setObjectName(QStringLiteral("actionOpenNextResult"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/res/open2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenNextResult->setIcon(icon2);
        actionOpenLastResult = new QAction(MainWindow);
        actionOpenLastResult->setObjectName(QStringLiteral("actionOpenLastResult"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/res/open3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenLastResult->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/res/logout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon4);
        actionTool = new QAction(MainWindow);
        actionTool->setObjectName(QStringLiteral("actionTool"));
        actionTool->setCheckable(true);
        actionTool->setChecked(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/res/toolbar.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTool->setIcon(icon5);
        actionAddTag = new QAction(MainWindow);
        actionAddTag->setObjectName(QStringLiteral("actionAddTag"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/res/stamps.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAddTag->setIcon(icon6);
        actionSaveResult = new QAction(MainWindow);
        actionSaveResult->setObjectName(QStringLiteral("actionSaveResult"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/image/res/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveResult->setIcon(icon7);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QStringLiteral("actionZoomIn"));
        actionZoomIn->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/image/res/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon8);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QStringLiteral("actionZoomOut"));
        actionZoomOut->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/image/res/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon9);
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName(QStringLiteral("actionBlue"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/image/res/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBlue->setIcon(icon10);
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QStringLiteral("actionLight"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/image/res/light.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLight->setIcon(icon11);
        actionGray = new QAction(MainWindow);
        actionGray->setObjectName(QStringLiteral("actionGray"));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/image/res/black.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGray->setIcon(icon12);
        actionVersion = new QAction(MainWindow);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/image/res/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVersion->setIcon(icon13);
        actionConfirmCompare = new QAction(MainWindow);
        actionConfirmCompare->setObjectName(QStringLiteral("actionConfirmCompare"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/image/res/red3.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfirmCompare->setIcon(icon14);
        actionSureInitAll = new QAction(MainWindow);
        actionSureInitAll->setObjectName(QStringLiteral("actionSureInitAll"));
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/image/res/initialAllConfirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSureInitAll->setIcon(icon15);
        actionOutPutImage = new QAction(MainWindow);
        actionOutPutImage->setObjectName(QStringLiteral("actionOutPutImage"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/image/res/outputPrintImg.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOutPutImage->setIcon(icon16);
        actionBlink = new QAction(MainWindow);
        actionBlink->setObjectName(QStringLiteral("actionBlink"));
        actionBlink->setCheckable(true);
        actionBlink->setChecked(true);
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/image/res/blinkView.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBlink->setIcon(icon17);
        actionShowErrorRect = new QAction(MainWindow);
        actionShowErrorRect->setObjectName(QStringLiteral("actionShowErrorRect"));
        actionShowErrorRect->setCheckable(true);
        actionShowErrorRect->setChecked(true);
        QIcon icon18;
        icon18.addFile(QStringLiteral(":/image/res/dd.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowErrorRect->setIcon(icon18);
        actionChoseWidget = new QAction(MainWindow);
        actionChoseWidget->setObjectName(QStringLiteral("actionChoseWidget"));
        actionChoseWidget->setCheckable(false);
        QIcon icon19;
        icon19.addFile(QStringLiteral(":/image/res/switchSplitWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChoseWidget->setIcon(icon19);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        actionMove->setChecked(true);
        QIcon icon20;
        icon20.addFile(QStringLiteral(":/image/res/finger.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon20);
        actionRool = new QAction(MainWindow);
        actionRool->setObjectName(QStringLiteral("actionRool"));
        actionRool->setCheckable(true);
        actionRool->setChecked(true);
        QIcon icon21;
        icon21.addFile(QStringLiteral(":/image/res/sign-down.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRool->setIcon(icon21);
        actionRotate270 = new QAction(MainWindow);
        actionRotate270->setObjectName(QStringLiteral("actionRotate270"));
        QIcon icon22;
        icon22.addFile(QStringLiteral(":/image/res/rotation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate270->setIcon(icon22);
        actionRotate90 = new QAction(MainWindow);
        actionRotate90->setObjectName(QStringLiteral("actionRotate90"));
        QIcon icon23;
        icon23.addFile(QStringLiteral(":/image/res/rotate-right.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate90->setIcon(icon23);
        actionCyan = new QAction(MainWindow);
        actionCyan->setObjectName(QStringLiteral("actionCyan"));
        actionCyan->setCheckable(true);
        actionCyan->setChecked(true);
        QIcon icon24;
        icon24.addFile(QStringLiteral(":/image/res/cyan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCyan->setIcon(icon24);
        actionMagenta = new QAction(MainWindow);
        actionMagenta->setObjectName(QStringLiteral("actionMagenta"));
        actionMagenta->setCheckable(true);
        actionMagenta->setChecked(true);
        QIcon icon25;
        icon25.addFile(QStringLiteral(":/image/res/magenta.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMagenta->setIcon(icon25);
        actionYellow = new QAction(MainWindow);
        actionYellow->setObjectName(QStringLiteral("actionYellow"));
        actionYellow->setCheckable(true);
        actionYellow->setChecked(true);
        QIcon icon26;
        icon26.addFile(QStringLiteral(":/image/res/yellow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionYellow->setIcon(icon26);
        actionBlack = new QAction(MainWindow);
        actionBlack->setObjectName(QStringLiteral("actionBlack"));
        actionBlack->setCheckable(true);
        actionBlack->setChecked(true);
        QIcon icon27;
        icon27.addFile(QStringLiteral(":/image/res/white.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBlack->setIcon(icon27);
        actionSetImportantError = new QAction(MainWindow);
        actionSetImportantError->setObjectName(QStringLiteral("actionSetImportantError"));
        actionSetImportantError->setCheckable(true);
        QIcon icon28;
        icon28.addFile(QStringLiteral(":/image/res/more.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetImportantError->setIcon(icon28);
        actionSetError = new QAction(MainWindow);
        actionSetError->setObjectName(QStringLiteral("actionSetError"));
        actionSetError->setCheckable(true);
        QIcon icon29;
        icon29.addFile(QStringLiteral(":/image/res/rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetError->setIcon(icon29);
        actionRedColor = new QAction(MainWindow);
        actionRedColor->setObjectName(QStringLiteral("actionRedColor"));
        actionRedColor->setCheckable(true);
        QIcon icon30;
        icon30.addFile(QStringLiteral(":/image/res/red.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedColor->setIcon(icon30);
        actionChengColor = new QAction(MainWindow);
        actionChengColor->setObjectName(QStringLiteral("actionChengColor"));
        actionChengColor->setCheckable(true);
        QIcon icon31;
        icon31.addFile(QStringLiteral(":/image/res/cheng.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChengColor->setIcon(icon31);
        actionYellowColor = new QAction(MainWindow);
        actionYellowColor->setObjectName(QStringLiteral("actionYellowColor"));
        actionYellowColor->setCheckable(true);
        QIcon icon32;
        icon32.addFile(QStringLiteral(":/image/res/huang.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionYellowColor->setIcon(icon32);
        actionGreenColor = new QAction(MainWindow);
        actionGreenColor->setObjectName(QStringLiteral("actionGreenColor"));
        actionGreenColor->setCheckable(true);
        QIcon icon33;
        icon33.addFile(QStringLiteral(":/image/res/green.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGreenColor->setIcon(icon33);
        actionCyanColor = new QAction(MainWindow);
        actionCyanColor->setObjectName(QStringLiteral("actionCyanColor"));
        actionCyanColor->setCheckable(true);
        QIcon icon34;
        icon34.addFile(QStringLiteral(":/image/res/qing.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCyanColor->setIcon(icon34);
        actionBlueColor = new QAction(MainWindow);
        actionBlueColor->setObjectName(QStringLiteral("actionBlueColor"));
        actionBlueColor->setCheckable(true);
        QIcon icon35;
        icon35.addFile(QStringLiteral(":/image/res/blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBlueColor->setIcon(icon35);
        actionPurpleColor = new QAction(MainWindow);
        actionPurpleColor->setObjectName(QStringLiteral("actionPurpleColor"));
        actionPurpleColor->setCheckable(true);
        QIcon icon36;
        icon36.addFile(QStringLiteral(":/image/res/purplr.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPurpleColor->setIcon(icon36);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitterFirst = new QSplitter(centralWidget);
        splitterFirst->setObjectName(QStringLiteral("splitterFirst"));
        splitterFirst->setOrientation(Qt::Horizontal);
        labelSourceImage = new QLabel(splitterFirst);
        labelSourceImage->setObjectName(QStringLiteral("labelSourceImage"));
        splitterFirst->addWidget(labelSourceImage);
        splitterSecond = new QSplitter(splitterFirst);
        splitterSecond->setObjectName(QStringLiteral("splitterSecond"));
        splitterSecond->setOrientation(Qt::Vertical);
        labelResultImage = new QLabel(splitterSecond);
        labelResultImage->setObjectName(QStringLiteral("labelResultImage"));
        splitterSecond->addWidget(labelResultImage);
        labelTargetImage = new QLabel(splitterSecond);
        labelTargetImage->setObjectName(QStringLiteral("labelTargetImage"));
        splitterSecond->addWidget(labelTargetImage);
        splitterFirst->addWidget(splitterSecond);

        verticalLayout->addWidget(splitterFirst);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1456, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_7 = new QMenu(menuBar);
        menu_7->setObjectName(QStringLiteral("menu_7"));
        menu_8 = new QMenu(menuBar);
        menu_8->setObjectName(QStringLiteral("menu_8"));
        menu_11 = new QMenu(menuBar);
        menu_11->setObjectName(QStringLiteral("menu_11"));
        menu_14 = new QMenu(menuBar);
        menu_14->setObjectName(QStringLiteral("menu_14"));
        menu_15 = new QMenu(menuBar);
        menu_15->setObjectName(QStringLiteral("menu_15"));
        menu_10 = new QMenu(menuBar);
        menu_10->setObjectName(QStringLiteral("menu_10"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_7->menuAction());
        menuBar->addAction(menu_8->menuAction());
        menuBar->addAction(menu_11->menuAction());
        menuBar->addAction(menu_14->menuAction());
        menuBar->addAction(menu_10->menuAction());
        menuBar->addAction(menu_15->menuAction());
        menu->addAction(actionOpenImage);
        menu->addAction(actionOpenResult);
        menu->addAction(actionOpenNextResult);
        menu->addAction(actionOpenLastResult);
        menu->addAction(actionExit);
        menu_7->addAction(actionTool);
        menu_7->addAction(actionAddTag);
        menu_8->addAction(actionSaveResult);
        menu_11->addAction(actionZoomIn);
        menu_11->addAction(actionZoomOut);
        menu_14->addAction(actionBlue);
        menu_14->addAction(actionLight);
        menu_14->addAction(actionGray);
        menu_15->addAction(actionVersion);
        menu_10->addAction(actionRedColor);
        menu_10->addAction(actionChengColor);
        menu_10->addAction(actionYellowColor);
        menu_10->addAction(actionGreenColor);
        menu_10->addAction(actionCyanColor);
        menu_10->addAction(actionBlueColor);
        menu_10->addAction(actionPurpleColor);
        mainToolBar->addAction(actionOpenImage);
        mainToolBar->addAction(actionOpenResult);
        mainToolBar->addAction(actionOpenNextResult);
        mainToolBar->addAction(actionOpenLastResult);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionConfirmCompare);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSureInitAll);
        mainToolBar->addAction(actionAddTag);
        mainToolBar->addAction(actionOutPutImage);
        mainToolBar->addAction(actionBlink);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionShowErrorRect);
        mainToolBar->addAction(actionChoseWidget);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSetError);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSetImportantError);
        mainToolBar->addAction(actionMove);
        mainToolBar->addAction(actionRool);
        mainToolBar->addAction(actionZoomIn);
        mainToolBar->addAction(actionZoomOut);
        mainToolBar->addAction(actionRotate270);
        mainToolBar->addAction(actionRotate90);
        mainToolBar->addAction(actionCyan);
        mainToolBar->addAction(actionMagenta);
        mainToolBar->addAction(actionYellow);
        mainToolBar->addAction(actionBlack);
        mainToolBar->addAction(actionVersion);
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpenImage->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\272\220\345\233\276", 0));
#ifndef QT_NO_TOOLTIP
        actionOpenImage->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\272\220\345\233\276", 0));
#endif // QT_NO_TOOLTIP
        actionOpenResult->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\243\200\346\265\213\347\273\223\346\236\234\346\210\226\347\233\256\346\240\207\345\233\276\347\211\207", 0));
#ifndef QT_NO_TOOLTIP
        actionOpenResult->setToolTip(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\243\200\346\265\213\347\273\223\346\236\234\346\210\226\347\233\256\346\240\207\345\233\276\347\211\207", 0));
#endif // QT_NO_TOOLTIP
        actionOpenNextResult->setText(QApplication::translate("MainWindow", "\344\270\213\346\254\241\346\243\200\346\265\213\347\273\223\346\236\234", 0));
        actionOpenLastResult->setText(QApplication::translate("MainWindow", "\344\270\212\346\254\241\346\243\200\346\265\213\347\273\223\346\236\234", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        actionTool->setText(QApplication::translate("MainWindow", "\345\267\245\345\205\267\346\235\241", 0));
        actionAddTag->setText(QApplication::translate("MainWindow", "\346\211\223\346\240\207\347\255\276", 0));
        actionSaveResult->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\346\243\200\346\237\245\347\273\223\346\236\234", 0));
        actionZoomIn->setText(QApplication::translate("MainWindow", "\346\224\276\345\244\247", 0));
        actionZoomOut->setText(QApplication::translate("MainWindow", "\347\274\251\345\260\217", 0));
        actionBlue->setText(QApplication::translate("MainWindow", "\350\223\235", 0));
        actionLight->setText(QApplication::translate("MainWindow", "\344\272\256", 0));
        actionGray->setText(QApplication::translate("MainWindow", "\346\232\227", 0));
        actionVersion->setText(QApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        actionConfirmCompare->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0));
#ifndef QT_NO_TOOLTIP
        actionConfirmCompare->setToolTip(QApplication::translate("MainWindow", "\347\241\256\350\256\244", 0));
#endif // QT_NO_TOOLTIP
        actionSureInitAll->setText(QApplication::translate("MainWindow", "\345\205\250\351\203\250\347\241\256\350\256\244\345\210\235\345\247\213\345\214\226", 0));
#ifndef QT_NO_TOOLTIP
        actionSureInitAll->setToolTip(QApplication::translate("MainWindow", "\345\205\250\351\203\250\347\241\256\350\256\244\345\210\235\345\247\213\345\214\226", 0));
#endif // QT_NO_TOOLTIP
        actionOutPutImage->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\347\211\207", 0));
#ifndef QT_NO_TOOLTIP
        actionOutPutImage->setToolTip(QApplication::translate("MainWindow", "\350\276\223\345\207\272\345\233\276\347\211\207", 0));
#endif // QT_NO_TOOLTIP
        actionBlink->setText(QApplication::translate("MainWindow", "\351\227\252\347\203\201\350\247\206\345\233\276\346\230\276\347\244\272\346\257\224\350\276\203\346\272\220\345\222\214\347\233\256\346\240\207\345\233\276\345\203\217", 0));
#ifndef QT_NO_TOOLTIP
        actionBlink->setToolTip(QApplication::translate("MainWindow", "\351\227\252\347\203\201\350\247\206\345\233\276\346\230\276\347\244\272\346\257\224\350\276\203\346\272\220\345\222\214\347\233\256\346\240\207\345\233\276\345\203\217", 0));
#endif // QT_NO_TOOLTIP
        actionShowErrorRect->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\351\224\231\350\257\257\350\276\271\346\241\206", 0));
#ifndef QT_NO_TOOLTIP
        actionShowErrorRect->setToolTip(QApplication::translate("MainWindow", "\346\230\276\347\244\272\351\224\231\350\257\257\350\276\271\346\241\206", 0));
#endif // QT_NO_TOOLTIP
        actionChoseWidget->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\210\206\345\211\262\347\252\227\345\217\243", 0));
#ifndef QT_NO_TOOLTIP
        actionChoseWidget->setToolTip(QApplication::translate("MainWindow", "\351\200\211\346\213\251\345\210\206\345\211\262\347\252\227\345\217\243", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setText(QApplication::translate("MainWindow", "\347\247\273\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("MainWindow", "\347\247\273\345\212\250", 0));
#endif // QT_NO_TOOLTIP
        actionRool->setText(QApplication::translate("MainWindow", "\346\273\232\345\212\250", 0));
#ifndef QT_NO_TOOLTIP
        actionRool->setToolTip(QApplication::translate("MainWindow", "\346\273\232\345\212\250", 0));
#endif // QT_NO_TOOLTIP
        actionRotate270->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\254270\345\272\246", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate270->setToolTip(QApplication::translate("MainWindow", "\346\227\213\350\275\254270\345\272\246", 0));
#endif // QT_NO_TOOLTIP
        actionRotate90->setText(QApplication::translate("MainWindow", "\346\227\213\350\275\25490\345\272\246", 0));
        actionCyan->setText(QApplication::translate("MainWindow", "\351\235\222\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionCyan->setToolTip(QApplication::translate("MainWindow", "\351\235\222\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionMagenta->setText(QApplication::translate("MainWindow", "\345\223\201\347\272\242\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionMagenta->setToolTip(QApplication::translate("MainWindow", "\345\223\201\347\272\242\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionYellow->setText(QApplication::translate("MainWindow", "\351\273\204\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionYellow->setToolTip(QApplication::translate("MainWindow", "\351\273\204\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionBlack->setText(QApplication::translate("MainWindow", "\351\273\221\350\211\262", 0));
#ifndef QT_NO_TOOLTIP
        actionBlack->setToolTip(QApplication::translate("MainWindow", "\351\273\221\350\211\262", 0));
#endif // QT_NO_TOOLTIP
        actionSetImportantError->setText(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242\346\243\200\346\265\213", 0));
#ifndef QT_NO_TOOLTIP
        actionSetImportantError->setToolTip(QApplication::translate("MainWindow", "\345\244\232\350\276\271\345\275\242\346\243\200\346\265\213", 0));
#endif // QT_NO_TOOLTIP
        actionSetError->setText(QApplication::translate("MainWindow", "\347\237\251\345\275\242\346\243\200\346\265\213", 0));
#ifndef QT_NO_TOOLTIP
        actionSetError->setToolTip(QApplication::translate("MainWindow", "\347\237\251\345\275\242\346\243\200\346\265\213", 0));
#endif // QT_NO_TOOLTIP
        actionRedColor->setText(QApplication::translate("MainWindow", "\347\272\242\350\211\262", 0));
        actionChengColor->setText(QApplication::translate("MainWindow", "\346\251\231\350\211\262", 0));
        actionYellowColor->setText(QApplication::translate("MainWindow", "\351\273\204\350\211\262", 0));
        actionGreenColor->setText(QApplication::translate("MainWindow", "\347\273\277\350\211\262", 0));
        actionCyanColor->setText(QApplication::translate("MainWindow", "\351\235\222\350\211\262", 0));
        actionBlueColor->setText(QApplication::translate("MainWindow", "\350\223\235\350\211\262", 0));
        actionPurpleColor->setText(QApplication::translate("MainWindow", "\347\264\253\350\211\262", 0));
        labelSourceImage->setText(QString());
        labelResultImage->setText(QString());
        labelTargetImage->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
        menu_7->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", 0));
        menu_8->setTitle(QApplication::translate("MainWindow", "\346\243\200\346\237\245", 0));
        menu_11->setTitle(QApplication::translate("MainWindow", "\345\217\230\347\204\246", 0));
        menu_14->setTitle(QApplication::translate("MainWindow", "\344\270\273\351\242\230\351\243\216\346\240\274", 0));
        menu_15->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        menu_10->setTitle(QApplication::translate("MainWindow", "\347\224\273\347\254\224\351\242\234\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
