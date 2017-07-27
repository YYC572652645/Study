#-------------------------------------------------
#
# Project created by QtCreator 2016-10-06T13:35:45
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport printsupport

TARGET = QtLinDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qextserial/qextserialport.cpp \
    qextserial/qextserialport_win.cpp \
    win_qextserialport.cpp \
    qextserialbase.cpp \
    qcustomplot.cpp \
    qtxml.cpp \
    addwidgettab.cpp \
    customplottab.cpp

HEADERS  += mainwindow.h \
    qextserial/qextserialport.h \
    qextserial/qextserialport_global.h \
    qextserial/qextserialport_p.h \
    win_qextserialport.h \
    qextserialbase.h \
    qcustomplot.h \
    qtxml.h \
    addwidgettab.h \
    customplottab.h

FORMS    += mainwindow.ui \
    addwidgettab.ui \
    customplottab.ui

DISTFILES += \
    qextserial/LICENSE

RESOURCES += \
    qss.qrc
