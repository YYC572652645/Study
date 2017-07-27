#-------------------------------------------------
#
# Project created by QtCreator 2016-09-07T14:26:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtLinPort
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserialbase.cpp \
    qextserialport.cpp \
    win_qextserialport.cpp \
    paintwidget.cpp

HEADERS  += mainwindow.h \
    qextserialbase.h \
    qextserialport.h \
    win_qextserialport.h \
    paintwidget.h

FORMS    += mainwindow.ui \
    paintwidget.ui

RESOURCES += \
    res.qrc



