#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T08:22:10
#
#-------------------------------------------------

QT       += core gui sql  xml  axcontainer  multimedia multimediawidgets  network script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = StudentDataBase
TEMPLATE = app

CONFIG  += qaxcontainer

SOURCES += main.cpp\
        mainwindow.cpp \
    StudentInfo/studentdataBase.cpp \
    StudentInfo/studentinfo.cpp \
    Login/backpassworddialog.cpp \
    Login/logindata.cpp \
    Login/logindialog.cpp \
    Login/registerdialog.cpp \
    Political/PoliticalDataBase.cpp \
    Political/politicalinsert.cpp \
    Political/politicalselect.cpp \
    CutSchool/cutschooldatabase.cpp \
    CutSchool/cutschoolinsert.cpp \
    CutSchool/cutschoolselect.cpp \
    NotPass/notpassdatabase.cpp \
    NotPass/notpassinsert.cpp \
    NotPass/notpassselect.cpp \
    Honor/HonorDataBase.cpp \
    Honor/honorinsert.cpp \
    Honor/honorselect.cpp \
    Daily/dailydatabase.cpp \
    Daily/dailyselect.cpp \
    Daily/dailyinsert.cpp \
    MessageBox/messagedialog.cpp \
    OutLine/OutLineDataBase.cpp \
    OutLine/OutLineinsert.cpp \
    OutLine/OutLineselect.cpp \
    OrderCast/OrderCastDataBase.cpp \
    OrderCast/OrderCastInsert.cpp \
    OrderCast/OrderCastSelect.cpp \
    Movie/movieplay.cpp \
    Web/webdata.cpp \
    NotBack/notbackdatabase.cpp \
    NotBack/notbackinsert.cpp \
    NotBack/notbackselect.cpp \
    Minimum/suspendform.cpp \
    GradeTest/GradeTestDataBase.cpp \
    GradeTest/GradeTestinsert.cpp \
    GradeTest/GradeTestselect.cpp \
    SchoolRoll/SchoolRoolDataBase.cpp \
    SchoolRoll/SchoolRoolinsert.cpp \
    SchoolRoll/SchoolRoolselect.cpp \
    Transfer/TransferDataBase.cpp \
    Transfer/Transferinsert.cpp \
    Transfer/Transferselect.cpp \
    WeatherData/weatherdata.cpp \
    QCustomPlot/qcustomplot.cpp

HEADERS  += mainwindow.h \
    StudentInfo/StudentDataBase.h \
    StudentInfo/studentinfo.h \
    Login/backpassworddialog.h \
    Login/logindata.h \
    Login/logindialog.h \
    Login/registerdialog.h \
    Political/PoliticalDataBase.h \
    Political/politicalinsert.h \
    Political/politicalselect.h \
    CutSchool/cutschooldatabase.h \
    CutSchool/cutschoolinsert.h \
    CutSchool/cutschoolselect.h \
    NotPass/notpassdatabase.h \
    NotPass/notpassinsert.h \
    NotPass/notpassselect.h \
    Honor/HonorDataBase.h \
    Honor/honorinsert.h \
    Honor/honorselect.h \
    Daily/dailydatabase.h \
    Daily/dailyselect.h \
    Daily/dailyinsert.h \
    MessageBox/messagedialog.h \
    OutLine/OutLineDataBase.h \
    OutLine/OutLineinsert.h \
    OutLine/OutLineselect.h \
    OrderCast/OrderCastDataBase.h \
    OrderCast/OrderCastInsert.h \
    OrderCast/OrderCastSelect.h \
    Movie/movieplay.h \
    Web/webdata.h \
    NotBack/notbackdatabase.h \
    NotBack/notbackinsert.h \
    NotBack/notbackselect.h \
    Minimum/suspendform.h \
    GradeTest/GradeTestDataBase.h \
    GradeTest/GradeTestinsert.h \
    GradeTest/GradeTestselect.h \
    SchoolRoll/SchoolRoolDataBase.h \
    SchoolRoll/SchoolRoolinsert.h \
    SchoolRoll/SchoolRoolselect.h \
    Transfer/TransferDataBase.h \
    Transfer/Transferinsert.h \
    Transfer/Transferselect.h \
    WeatherData/weatherdata.h \
    QCustomPlot/qcustomplot.h

FORMS    += mainwindow.ui \
    StudentInfo/studentinfo.ui \
    Login/backpassworddialog.ui \
    Login/logindialog.ui \
    Login/registerdialog.ui \
    Political/politicalinsert.ui \
    Political/politicalselect.ui \
    CutSchool/cutschoolinsert.ui \
    CutSchool/cutschoolselect.ui \
    NotPass/notpassinsert.ui \
    NotPass/notpassselect.ui \
    Honor/honorinsert.ui \
    Honor/honorselect.ui \
    Daily/dailyselect.ui \
    Daily/dailyinsert.ui \
    MessageBox/messagedialog.ui \
    OutLine/OutLineinsert.ui \
    OutLine/OutLineselect.ui \
    OrderCast/OrderCastInsert.ui \
    OrderCast/OrderCastSelect.ui \
    Movie/movieplay.ui \
    Web/webdata.ui \
    NotBack/notbackinsert.ui \
    NotBack/notbackselect.ui \
    Minimum/suspendform.ui \
    GradeTest/GradeTestinsert.ui \
    GradeTest/GradeTestselect.ui \
    SchoolRoll/SchoolRoolinsert.ui \
    SchoolRoll/SchoolRoolselect.ui \
    Transfer/Transferinsert.ui \
    Transfer/Transferselect.ui \
    WeatherData/weatherdata.ui

DISTFILES +=
RESOURCES +=res.qrc
RC_FILE+=myapp.rc

SUBDIRS += \
    ../../QT/webWidget/webWidget.pro
