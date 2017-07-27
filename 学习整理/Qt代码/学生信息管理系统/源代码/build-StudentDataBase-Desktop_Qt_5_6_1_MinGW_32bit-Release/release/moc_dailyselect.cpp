/****************************************************************************
** Meta object code from reading C++ file 'dailyselect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StudentDataBase/Daily/dailyselect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dailyselect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DailySelect_t {
    QByteArrayData data[7];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DailySelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DailySelect_t qt_meta_stringdata_DailySelect = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DailySelect"
QT_MOC_LITERAL(1, 12, 10), // "deleteData"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "selectText"
QT_MOC_LITERAL(4, 35, 5), // "index"
QT_MOC_LITERAL(5, 41, 33), // "on_pushButtonDorNumberSec_cli..."
QT_MOC_LITERAL(6, 75, 33) // "on_pushButtonDorStatusSec_cli..."

    },
    "DailySelect\0deleteData\0\0selectText\0"
    "index\0on_pushButtonDorNumberSec_clicked\0"
    "on_pushButtonDorStatusSec_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DailySelect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DailySelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DailySelect *_t = static_cast<DailySelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleteData(); break;
        case 1: _t->selectText((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->on_pushButtonDorNumberSec_clicked(); break;
        case 3: _t->on_pushButtonDorStatusSec_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject DailySelect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DailySelect.data,
      qt_meta_data_DailySelect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DailySelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DailySelect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DailySelect.stringdata0))
        return static_cast<void*>(const_cast< DailySelect*>(this));
    return QWidget::qt_metacast(_clname);
}

int DailySelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
