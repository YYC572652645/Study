/****************************************************************************
** Meta object code from reading C++ file 'customplottab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../imp/QtLinDemo/customplottab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customplottab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_customPlotTab_t {
    QByteArrayData data[10];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_customPlotTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_customPlotTab_t qt_meta_stringdata_customPlotTab = {
    {
QT_MOC_LITERAL(0, 0, 13), // "customPlotTab"
QT_MOC_LITERAL(1, 14, 8), // "readInfo"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "readInfoMessage"
QT_MOC_LITERAL(4, 40, 29), // "on_checkBoxMoveChange_clicked"
QT_MOC_LITERAL(5, 70, 28), // "on_checkBoxPicChange_clicked"
QT_MOC_LITERAL(6, 99, 32), // "on_checkBoxBackGroundCge_clicked"
QT_MOC_LITERAL(7, 132, 26), // "on_pushButtonClear_clicked"
QT_MOC_LITERAL(8, 159, 32), // "on_pushButtonReadMessage_clicked"
QT_MOC_LITERAL(9, 192, 29) // "on_pushButtonReadInfo_clicked"

    },
    "customPlotTab\0readInfo\0\0readInfoMessage\0"
    "on_checkBoxMoveChange_clicked\0"
    "on_checkBoxPicChange_clicked\0"
    "on_checkBoxBackGroundCge_clicked\0"
    "on_pushButtonClear_clicked\0"
    "on_pushButtonReadMessage_clicked\0"
    "on_pushButtonReadInfo_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_customPlotTab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void customPlotTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        customPlotTab *_t = static_cast<customPlotTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readInfo(); break;
        case 1: _t->readInfoMessage(); break;
        case 2: _t->on_checkBoxMoveChange_clicked(); break;
        case 3: _t->on_checkBoxPicChange_clicked(); break;
        case 4: _t->on_checkBoxBackGroundCge_clicked(); break;
        case 5: _t->on_pushButtonClear_clicked(); break;
        case 6: _t->on_pushButtonReadMessage_clicked(); break;
        case 7: _t->on_pushButtonReadInfo_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (customPlotTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customPlotTab::readInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (customPlotTab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&customPlotTab::readInfoMessage)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject customPlotTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_customPlotTab.data,
      qt_meta_data_customPlotTab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *customPlotTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customPlotTab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_customPlotTab.stringdata0))
        return static_cast<void*>(const_cast< customPlotTab*>(this));
    return QWidget::qt_metacast(_clname);
}

int customPlotTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void customPlotTab::readInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void customPlotTab::readInfoMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
