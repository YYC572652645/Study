#-------------------------------------------------
#
# Project created by QtCreator 2017-07-13T17:10:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TranslateDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

TRANSLATIONS += english.ts\
                chinese.ts

RESOURCES += \
    res.qrc
