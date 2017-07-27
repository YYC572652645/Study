#-------------------------------------------------
#
# Project created by QtCreator 2016-09-20T17:15:47
#
#-------------------------------------------------

QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnergyPic
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    soundwidget.cpp

HEADERS  += mainwindow.h \
    soundwidget.h

FORMS    += mainwindow.ui \
    soundwidget.ui

RESOURCES += \
    res.qrc
