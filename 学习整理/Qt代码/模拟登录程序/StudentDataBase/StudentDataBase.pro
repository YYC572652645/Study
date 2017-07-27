#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T08:22:10
#
#-------------------------------------------------

QT       += core gui sql  xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudentDataBase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    logindata.cpp \
    workthread.cpp \
    registerdialog.cpp \
    backpassworddialog.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    logindata.h \
    workthread.h \
    registerdialog.h \
    backpassworddialog.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registerdialog.ui \
    backpassworddialog.ui

DISTFILES +=

RESOURCES +=
