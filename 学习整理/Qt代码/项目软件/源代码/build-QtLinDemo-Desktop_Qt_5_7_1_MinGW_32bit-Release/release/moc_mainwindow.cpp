/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imp/QtLinDemo/mainwindow.h"
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
    QByteArrayData data[19];
    char stringdata0[396];
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
QT_MOC_LITERAL(3, 38, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(4, 65, 10), // "timeUpdate"
QT_MOC_LITERAL(5, 76, 25), // "on_pushButtonConn_clicked"
QT_MOC_LITERAL(6, 102, 28), // "on_comboBoxGallery_activated"
QT_MOC_LITERAL(7, 131, 4), // "arg1"
QT_MOC_LITERAL(8, 136, 27), // "on_comboBoxBaud_2_activated"
QT_MOC_LITERAL(9, 164, 22), // "on_checkBoxImp_clicked"
QT_MOC_LITERAL(10, 187, 25), // "on_comboBoxDeal_activated"
QT_MOC_LITERAL(11, 213, 25), // "on_checkBoxLength_clicked"
QT_MOC_LITERAL(12, 239, 24), // "on_checkBoxCheck_clicked"
QT_MOC_LITERAL(13, 264, 15), // "readInfoMessage"
QT_MOC_LITERAL(14, 280, 28), // "on_pushButtonAddress_clicked"
QT_MOC_LITERAL(15, 309, 26), // "on_pushButtonClear_clicked"
QT_MOC_LITERAL(16, 336, 25), // "on_pushButtonRead_clicked"
QT_MOC_LITERAL(17, 362, 27), // "on_comboBoxNumber_activated"
QT_MOC_LITERAL(18, 390, 5) // "index"

    },
    "MainWindow\0on_pushButtonOpen_clicked\0"
    "\0on_pushButtonStart_clicked\0timeUpdate\0"
    "on_pushButtonConn_clicked\0"
    "on_comboBoxGallery_activated\0arg1\0"
    "on_comboBoxBaud_2_activated\0"
    "on_checkBoxImp_clicked\0on_comboBoxDeal_activated\0"
    "on_checkBoxLength_clicked\0"
    "on_checkBoxCheck_clicked\0readInfoMessage\0"
    "on_pushButtonAddress_clicked\0"
    "on_pushButtonClear_clicked\0"
    "on_pushButtonRead_clicked\0"
    "on_comboBoxNumber_activated\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    0,   99,    2, 0x08 /* Private */,
      10,    1,  100,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonOpen_clicked(); break;
        case 1: _t->on_pushButtonStart_clicked(); break;
        case 2: _t->timeUpdate(); break;
        case 3: _t->on_pushButtonConn_clicked(); break;
        case 4: _t->on_comboBoxGallery_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_comboBoxBaud_2_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_checkBoxImp_clicked(); break;
        case 7: _t->on_comboBoxDeal_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_checkBoxLength_clicked(); break;
        case 9: _t->on_checkBoxCheck_clicked(); break;
        case 10: _t->readInfoMessage(); break;
        case 11: _t->on_pushButtonAddress_clicked(); break;
        case 12: _t->on_pushButtonClear_clicked(); break;
        case 13: _t->on_pushButtonRead_clicked(); break;
        case 14: _t->on_comboBoxNumber_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
