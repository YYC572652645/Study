/****************************************************************************
** Meta object code from reading C++ file 'addwidgettab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imp/QtLinDemo/addwidgettab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addwidgettab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addWidgetTab_t {
    QByteArrayData data[7];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addWidgetTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addWidgetTab_t qt_meta_stringdata_addWidgetTab = {
    {
QT_MOC_LITERAL(0, 0, 12), // "addWidgetTab"
QT_MOC_LITERAL(1, 13, 8), // "readInfo"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 31), // "on_comboBox_currentIndexChanged"
QT_MOC_LITERAL(4, 55, 5), // "index"
QT_MOC_LITERAL(5, 61, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(6, 85, 29) // "on_pushButtonSaveInfo_clicked"

    },
    "addWidgetTab\0readInfo\0\0"
    "on_comboBox_currentIndexChanged\0index\0"
    "on_pushButton_2_clicked\0"
    "on_pushButtonSaveInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addWidgetTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void addWidgetTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addWidgetTab *_t = static_cast<addWidgetTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readInfo(); break;
        case 1: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_2_clicked(); break;
        case 3: _t->on_pushButtonSaveInfo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (addWidgetTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&addWidgetTab::readInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject addWidgetTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addWidgetTab.data,
      qt_meta_data_addWidgetTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addWidgetTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addWidgetTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addWidgetTab.stringdata0))
        return static_cast<void*>(const_cast< addWidgetTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int addWidgetTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void addWidgetTab::readInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
