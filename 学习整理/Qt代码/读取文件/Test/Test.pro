#-------------------------------------------------
#
# Project created by QtCreator 2017-06-20T08:53:53
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    qreadini.cpp \
    qreadxml.cpp \
    qreadjson.cpp

HEADERS  += mainwindow.h \
    database.h \
    qreadini.h \
    qreadxml.h \
    qreadjson.h

FORMS    += mainwindow.ui
