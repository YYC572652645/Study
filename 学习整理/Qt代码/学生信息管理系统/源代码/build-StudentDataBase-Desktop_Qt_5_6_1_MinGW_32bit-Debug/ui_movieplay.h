/********************************************************************************
** Form generated from reading UI file 'movieplay.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEPLAY_H
#define UI_MOVIEPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoviePlay
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCurrentTime;
    QSlider *horizontalSlider;
    QLabel *labelTotalTime;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonStop_2;
    QPushButton *pushButtonSpeed;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonKuaiTui;
    QPushButton *pushButtonHide;
    QPushButton *pushButtonSound;
    QSlider *horizontalSlider_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QLabel *label;
    QVBoxLayout *verticalLayout_3;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonFile;
    QPushButton *pushButtonZXMovie;

    void setupUi(QWidget *MoviePlay)
    {
        if (MoviePlay->objectName().isEmpty())
            MoviePlay->setObjectName(QStringLiteral("MoviePlay"));
        MoviePlay->resize(1016, 629);
        verticalLayout_5 = new QVBoxLayout(MoviePlay);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(MoviePlay);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);

        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelCurrentTime = new QLabel(MoviePlay);
        labelCurrentTime->setObjectName(QStringLiteral("labelCurrentTime"));
        labelCurrentTime->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_3->addWidget(labelCurrentTime);

        horizontalSlider = new QSlider(MoviePlay);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setPageStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        labelTotalTime = new QLabel(MoviePlay);
        labelTotalTime->setObjectName(QStringLiteral("labelTotalTime"));
        labelTotalTime->setMaximumSize(QSize(16777215, 15));

        horizontalLayout_3->addWidget(labelTotalTime);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButtonStop_2 = new QPushButton(MoviePlay);
        pushButtonStop_2->setObjectName(QStringLiteral("pushButtonStop_2"));
        pushButtonStop_2->setMinimumSize(QSize(50, 50));
        pushButtonStop_2->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/image/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStop_2->setIcon(icon);

        horizontalLayout->addWidget(pushButtonStop_2);

        pushButtonSpeed = new QPushButton(MoviePlay);
        pushButtonSpeed->setObjectName(QStringLiteral("pushButtonSpeed"));
        pushButtonSpeed->setMinimumSize(QSize(50, 50));
        pushButtonSpeed->setMaximumSize(QSize(50, 50));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/new/prefix1/image/rewind.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSpeed->setIcon(icon1);

        horizontalLayout->addWidget(pushButtonSpeed);

        pushButtonStop = new QPushButton(MoviePlay);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setMinimumSize(QSize(50, 50));
        pushButtonStop->setMaximumSize(QSize(50, 50));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/new/prefix1/image/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonStop->setIcon(icon2);

        horizontalLayout->addWidget(pushButtonStop);

        pushButtonKuaiTui = new QPushButton(MoviePlay);
        pushButtonKuaiTui->setObjectName(QStringLiteral("pushButtonKuaiTui"));
        pushButtonKuaiTui->setMinimumSize(QSize(50, 50));
        pushButtonKuaiTui->setMaximumSize(QSize(50, 50));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/new/prefix1/image/forward.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonKuaiTui->setIcon(icon3);

        horizontalLayout->addWidget(pushButtonKuaiTui);

        pushButtonHide = new QPushButton(MoviePlay);
        pushButtonHide->setObjectName(QStringLiteral("pushButtonHide"));
        pushButtonHide->setMinimumSize(QSize(50, 50));
        pushButtonHide->setMaximumSize(QSize(50, 50));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/new/prefix1/image/right.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonHide->setIcon(icon4);

        horizontalLayout->addWidget(pushButtonHide);

        pushButtonSound = new QPushButton(MoviePlay);
        pushButtonSound->setObjectName(QStringLiteral("pushButtonSound"));
        pushButtonSound->setMinimumSize(QSize(50, 50));
        pushButtonSound->setMaximumSize(QSize(50, 50));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/new/prefix1/image/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSound->setIcon(icon5);

        horizontalLayout->addWidget(pushButtonSound);

        horizontalSlider_2 = new QSlider(MoviePlay);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(300);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);

        groupBox_3 = new QGroupBox(MoviePlay);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(190, 16777215));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        frame = new QFrame(groupBox_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 20));
        frame->setStyleSheet(QStringLiteral("background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #6ea1f1, stop: 1 #567dbc);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 0, 81, 20));
        label->setMinimumSize(QSize(0, 20));

        verticalLayout_4->addWidget(frame);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        listWidget = new QListWidget(groupBox_3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(190, 16777215));
        listWidget->setLineWidth(0);
        listWidget->setBatchSize(100);

        verticalLayout_3->addWidget(listWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonFile = new QPushButton(groupBox_3);
        pushButtonFile->setObjectName(QStringLiteral("pushButtonFile"));
        pushButtonFile->setMinimumSize(QSize(40, 40));
        pushButtonFile->setMaximumSize(QSize(40, 40));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/new/prefix1/image/plus.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonFile->setIcon(icon6);

        horizontalLayout_2->addWidget(pushButtonFile);

        pushButtonZXMovie = new QPushButton(groupBox_3);
        pushButtonZXMovie->setObjectName(QStringLiteral("pushButtonZXMovie"));
        pushButtonZXMovie->setMinimumSize(QSize(40, 40));
        pushButtonZXMovie->setMaximumSize(QSize(40, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/new/prefix1/image/delete.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonZXMovie->setIcon(icon7);

        horizontalLayout_2->addWidget(pushButtonZXMovie);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_4->addWidget(groupBox_3);


        verticalLayout_5->addLayout(horizontalLayout_4);


        retranslateUi(MoviePlay);

        QMetaObject::connectSlotsByName(MoviePlay);
    } // setupUi

    void retranslateUi(QWidget *MoviePlay)
    {
        MoviePlay->setWindowTitle(QApplication::translate("MoviePlay", "Form", 0));
        groupBox->setTitle(QString());
        labelCurrentTime->setText(QString());
        labelTotalTime->setText(QString());
        pushButtonStop_2->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonSpeed->setToolTip(QApplication::translate("MoviePlay", "\345\277\253\351\200\200", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonSpeed->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        pushButtonSpeed->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonStop->setToolTip(QApplication::translate("MoviePlay", "\346\222\255\346\224\276", 0));
#endif // QT_NO_TOOLTIP
        pushButtonStop->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonKuaiTui->setToolTip(QApplication::translate("MoviePlay", "\345\277\253\350\277\233", 0));
#endif // QT_NO_TOOLTIP
        pushButtonKuaiTui->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonHide->setToolTip(QApplication::translate("MoviePlay", "\351\232\220\350\227\217\346\222\255\346\224\276\345\210\227\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        pushButtonHide->setText(QString());
        pushButtonSound->setText(QString());
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("MoviePlay", "\346\222\255\346\224\276\345\210\227\350\241\250", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonFile->setToolTip(QApplication::translate("MoviePlay", "\346\211\223\345\274\200\350\247\206\351\242\221", 0));
#endif // QT_NO_TOOLTIP
        pushButtonFile->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonZXMovie->setToolTip(QApplication::translate("MoviePlay", "\346\270\205\347\251\272\346\222\255\346\224\276\345\210\227\350\241\250", 0));
#endif // QT_NO_TOOLTIP
        pushButtonZXMovie->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MoviePlay: public Ui_MoviePlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEPLAY_H
