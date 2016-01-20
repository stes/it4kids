/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/GUI/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[366];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "currentSpriteChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 7), // "Sprite*"
QT_MOC_LITERAL(4, 41, 6), // "sprite"
QT_MOC_LITERAL(5, 48, 8), // "newSound"
QT_MOC_LITERAL(6, 57, 10), // "newCostume"
QT_MOC_LITERAL(7, 68, 24), // "on_soundFromFile_clicked"
QT_MOC_LITERAL(8, 93, 26), // "on_costumeFromFile_clicked"
QT_MOC_LITERAL(9, 120, 21), // "on_buttonFile_clicked"
QT_MOC_LITERAL(10, 142, 21), // "on_buttonEdit_clicked"
QT_MOC_LITERAL(11, 164, 28), // "on_buttonAddDragElem_clicked"
QT_MOC_LITERAL(12, 193, 25), // "on_spriteFromFile_clicked"
QT_MOC_LITERAL(13, 219, 28), // "on_buttonScriptStart_clicked"
QT_MOC_LITERAL(14, 248, 19), // "changeCurrentSprite"
QT_MOC_LITERAL(15, 268, 37), // "customContextMenuRequestedAdd..."
QT_MOC_LITERAL(16, 306, 3), // "pos"
QT_MOC_LITERAL(17, 310, 20), // "eraseItemAddDragElem"
QT_MOC_LITERAL(18, 331, 17), // "setCurrentCostume"
QT_MOC_LITERAL(19, 349, 8), // "Costume*"
QT_MOC_LITERAL(20, 358, 7) // "costume"

    },
    "MainWindow\0currentSpriteChanged\0\0"
    "Sprite*\0sprite\0newSound\0newCostume\0"
    "on_soundFromFile_clicked\0"
    "on_costumeFromFile_clicked\0"
    "on_buttonFile_clicked\0on_buttonEdit_clicked\0"
    "on_buttonAddDragElem_clicked\0"
    "on_spriteFromFile_clicked\0"
    "on_buttonScriptStart_clicked\0"
    "changeCurrentSprite\0"
    "customContextMenuRequestedAddDragElem\0"
    "pos\0eraseItemAddDragElem\0setCurrentCostume\0"
    "Costume*\0costume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    1,   96,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      17,    0,  102,    2, 0x08 /* Private */,
      18,    1,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QPoint,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentSpriteChanged((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 1: _t->newSound(); break;
        case 2: _t->newCostume(); break;
        case 3: _t->on_soundFromFile_clicked(); break;
        case 4: _t->on_costumeFromFile_clicked(); break;
        case 5: _t->on_buttonFile_clicked(); break;
        case 6: _t->on_buttonEdit_clicked(); break;
        case 7: _t->on_buttonAddDragElem_clicked(); break;
        case 8: _t->on_spriteFromFile_clicked(); break;
        case 9: _t->on_buttonScriptStart_clicked(); break;
        case 10: _t->changeCurrentSprite((*reinterpret_cast< Sprite*(*)>(_a[1]))); break;
        case 11: _t->customContextMenuRequestedAddDragElem((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 12: _t->eraseItemAddDragElem(); break;
        case 13: _t->setCurrentCostume((*reinterpret_cast< Costume*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(Sprite * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::currentSpriteChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::newSound)) {
                *result = 1;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::newCostume)) {
                *result = 2;
            }
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

// SIGNAL 0
void MainWindow::currentSpriteChanged(Sprite * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::newSound()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::newCostume()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
