/********************************************************************************
** Form generated from reading UI file 'webdata.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBDATA_H
#define UI_WEBDATA_H

#include <ActiveQt/QAxWidget>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WebData
{
public:
    QVBoxLayout *verticalLayout;
    QAxWidget *axWidget;

    void setupUi(QWidget *WebData)
    {
        if (WebData->objectName().isEmpty())
            WebData->setObjectName(QStringLiteral("WebData"));
        WebData->resize(400, 300);
        verticalLayout = new QVBoxLayout(WebData);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        axWidget = new QAxWidget(WebData);
        axWidget->setObjectName(QStringLiteral("axWidget"));

        verticalLayout->addWidget(axWidget);


        retranslateUi(WebData);

        QMetaObject::connectSlotsByName(WebData);
    } // setupUi

    void retranslateUi(QWidget *WebData)
    {
        WebData->setWindowTitle(QApplication::translate("WebData", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class WebData: public Ui_WebData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBDATA_H
