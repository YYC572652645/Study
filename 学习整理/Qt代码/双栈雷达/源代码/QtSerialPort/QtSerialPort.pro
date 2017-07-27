#-------------------------------------------------
#
# Project created by QtCreator 2016-07-23T08:05:33
#
#-------------------------------------------------

QT         += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  printsupport

TARGET   = QtSerialPort
TEMPLATE = app


SOURCES  += main.cpp\
         mainwindow.cpp \
         qextserialbase.cpp \
         qextserialport.cpp \
         win_qextserialport.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
         qextserialbase.h \
         qextserialport.h \
         win_qextserialport.h \
    qcustomplot.h

FORMS    += mainwindow.ui
QT       += serialport

RESOURCES += \
          res.qrc
RC_FILE = myapp.rc


