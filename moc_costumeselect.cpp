/****************************************************************************
** Meta object code from reading C++ file 'costumeselect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/GUI/costume/costumeselect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'costumeselect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CostumeSelect_t {
    QByteArrayData data[6];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CostumeSelect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CostumeSelect_t qt_meta_stringdata_CostumeSelect = {
    {
QT_MOC_LITERAL(0, 0, 13), // "CostumeSelect"
QT_MOC_LITERAL(1, 14, 16), // "setCurrentSprite"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 7), // "Sprite*"
QT_MOC_LITERAL(4, 40, 6), // "sprite"
QT_MOC_LITERAL(5, 47, 17) // "updateCostumeList"

    },
    "CostumeSelect\0setCurrentSprite\0\0Sprite*\0"
    "sprite\0updateCostumeList"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CostumeSelect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void CostumeSelect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CostumeSelect *_t = static_cast<CostumeSelect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurrentSprite((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 1: _t->updateCostumeList(); break;
        default: ;
        }
    }
}

const QMetaObject CostumeSelect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CostumeSelect.data,
      qt_meta_data_CostumeSelect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CostumeSelect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CostumeSelect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CostumeSelect.stringdata0))
        return static_cast<void*>(const_cast< CostumeSelect*>(this));
    return QWidget::qt_metacast(_clname);
}

int CostumeSelect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
