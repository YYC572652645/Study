#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T13:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

TARGET = RadarWindow
TEMPLATE = app


SOURCES += main.cpp\
        radarwindow.cpp \
    splashscreen.cpp \
    mainobject.cpp \
    qextserialbase.cpp \
    win_qextserialport.cpp \
    qextserial/qextserialport.cpp \
    qextserial/qextserialport_win.cpp \
    MessageBox/messagedialog.cpp

HEADERS  += radarwindow.h \
    splashscreen.h \
    mainobject.h \
    qextserialbase.h \
    win_qextserialport.h \
    qextserial/qextserialport.h \
    qextserial/qextserialport_global.h \
    qextserial/qextserialport_p.h \
    MessageBox/messagedialog.h

FORMS    += radarwindow.ui \
    MessageBox/messagedialog.ui

RESOURCES += \
    splashscreen.qrc

DISTFILES +=

#RC_FILE = myapp.rc
