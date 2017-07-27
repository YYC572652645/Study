/****************************************************************************
** Meta object code from reading C++ file 'movieplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../StudentDataBase/Movie/movieplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'movieplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MoviePlay_t {
    QByteArrayData data[19];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MoviePlay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MoviePlay_t qt_meta_stringdata_MoviePlay = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MoviePlay"
QT_MOC_LITERAL(1, 10, 25), // "on_pushButtonStop_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_pushButtonHide_clicked"
QT_MOC_LITERAL(4, 63, 25), // "on_pushButtonFile_clicked"
QT_MOC_LITERAL(5, 89, 27), // "on_listWidget_doubleClicked"
QT_MOC_LITERAL(6, 117, 5), // "index"
QT_MOC_LITERAL(7, 123, 28), // "on_pushButtonZXMovie_clicked"
QT_MOC_LITERAL(8, 152, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(9, 185, 5), // "value"
QT_MOC_LITERAL(10, 191, 28), // "on_pushButtonKuaiTui_clicked"
QT_MOC_LITERAL(11, 220, 11), // "valueChange"
QT_MOC_LITERAL(12, 232, 8), // "position"
QT_MOC_LITERAL(13, 241, 33), // "on_horizontalSlider_sliderPre..."
QT_MOC_LITERAL(14, 275, 34), // "on_horizontalSlider_sliderRel..."
QT_MOC_LITERAL(15, 310, 26), // "on_pushButtonSpeed_clicked"
QT_MOC_LITERAL(16, 337, 27), // "on_pushButtonStop_2_clicked"
QT_MOC_LITERAL(17, 365, 26), // "on_pushButtonSound_clicked"
QT_MOC_LITERAL(18, 392, 33) // "on_horizontalSlider_2_sliderM..."

    },
    "MoviePlay\0on_pushButtonStop_clicked\0"
    "\0on_pushButtonHide_clicked\0"
    "on_pushButtonFile_clicked\0"
    "on_listWidget_doubleClicked\0index\0"
    "on_pushButtonZXMovie_clicked\0"
    "on_horizontalSlider_valueChanged\0value\0"
    "on_pushButtonKuaiTui_clicked\0valueChange\0"
    "position\0on_horizontalSlider_sliderPressed\0"
    "on_horizontalSlider_sliderReleased\0"
    "on_pushButtonSpeed_clicked\0"
    "on_pushButtonStop_2_clicked\0"
    "on_pushButtonSound_clicked\0"
    "on_horizontalSlider_2_sliderMoved"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MoviePlay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    1,   87,    2, 0x08 /* Private */,
       7,    0,   90,    2, 0x08 /* Private */,
       8,    1,   91,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void MoviePlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MoviePlay *_t = static_cast<MoviePlay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButtonStop_clicked(); break;
        case 1: _t->on_pushButtonHide_clicked(); break;
        case 2: _t->on_pushButtonFile_clicked(); break;
        case 3: _t->on_listWidget_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->on_pushButtonZXMovie_clicked(); break;
        case 5: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButtonKuaiTui_clicked(); break;
        case 7: _t->valueChange((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_horizontalSlider_sliderPressed(); break;
        case 9: _t->on_horizontalSlider_sliderReleased(); break;
        case 10: _t->on_pushButtonSpeed_clicked(); break;
        case 11: _t->on_pushButtonStop_2_clicked(); break;
        case 12: _t->on_pushButtonSound_clicked(); break;
        case 13: _t->on_horizontalSlider_2_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MoviePlay::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MoviePlay.data,
      qt_meta_data_MoviePlay,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MoviePlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MoviePlay::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MoviePlay.stringdata0))
        return static_cast<void*>(const_cast< MoviePlay*>(this));
    return QWidget::qt_metacast(_clname);
}

int MoviePlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
