#-------------------------------------------------
#
# Project created by QtCreator 2017-07-15T11:05:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = muPdfDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    include/libmupdf_global.h \
    include/mupdf-document.h \
    include/mupdf-link.h \
    include/mupdf-outline.h \
    include/mupdf-page.h \
    include/mupdf-qt.h \
    include/mupdf-textbox.h

FORMS    += mainwindow.ui

LIBS +=  D:\Program\muPdfDemo\lib\x64\libmupdf.lib

RESOURCES += \
    res.qrc
