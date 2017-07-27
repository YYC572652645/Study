/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "O:/WINDOWS/YYC/xf/2016-1-09/QtLinDemo/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[14];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_pushButtonOpen_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 10), // "timeUpdate"
QT_MOC_LITERAL(4, 49, 25), // "on_pushButtonConn_clicked"
QT_MOC_LITERAL(5, 75, 28), // "on_comboBoxGallery_activated"
QT_MOC_LITERAL(6, 104, 4), // "arg1"
QT_MOC_LITERAL(7, 109, 27), // "on_comboBoxBaud_2_activated"
QT_MOC_LITERAL(8, 137, 22), // "on_checkBoxImp_clicked"
QT_MOC_LITERAL(9, 160, 25), // "on_comboBoxDeal_activated"
QT_MOC_LITERAL(10, 186, 26), // "on_pushButtonClear_clicked"
QT_MOC_LITERAL(11, 213, 25), // "on_pushButtonSave_clicked"
QT_MOC_LITERAL(12, 239, 10), // "beepUpdate"
QT_MOC_LITERAL(13, 250, 9) // "comUpdate"

    },
    "MainWindow\0on_pushButtonOpen_clicked\0"
    "\0timeUpdate\0on_pushButtonConn_clicked\0"
    "on_comboBoxGallery_activated\0arg1\0"
    "on_comboBoxBaud_2_activated\0"
    "on_checkBoxImp_clicked\0on_comboBoxDeal_activated\0"
    "on_pushButtonClear_clicked\0"
    "on_pushButtonSave_clicked\0beepUpdate\0"
    "comUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    1,   72,    2, 0x08 /* Private */,
       7,    1,   75,    2, 0x08 /* Private */,
       8,    0,   78,    2, 0x08 /* Private */,
       9,    1,   79,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonOpen_clicked(); break;
        case 1: _t->timeUpdate(); break;
        case 2: _t->on_pushButtonConn_clicked(); break;
        case 3: _t->on_comboBoxGallery_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_comboBoxBaud_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_checkBoxImp_clicked(); break;
        case 6: _t->on_comboBoxDeal_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_pushButtonClear_clicked(); break;
        case 8: _t->on_pushButtonSave_clicked(); break;
        case 9: _t->beepUpdate(); break;
        case 10: _t->comUpdate(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
