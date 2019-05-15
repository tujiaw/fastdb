/****************************************************************************
** Meta object code from reading C++ file 'replicationdemo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../replicationdemo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'replicationdemo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_replicationdemo_t {
    QByteArrayData data[14];
    char stringdata[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_replicationdemo_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_replicationdemo_t qt_meta_stringdata_replicationdemo = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 6),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 6),
QT_MOC_LITERAL(4, 31, 9),
QT_MOC_LITERAL(5, 41, 9),
QT_MOC_LITERAL(6, 51, 7),
QT_MOC_LITERAL(7, 59, 5),
QT_MOC_LITERAL(8, 65, 9),
QT_MOC_LITERAL(9, 75, 12),
QT_MOC_LITERAL(10, 88, 12),
QT_MOC_LITERAL(11, 101, 5),
QT_MOC_LITERAL(12, 107, 10),
QT_MOC_LITERAL(13, 118, 7)
    },
    "replicationdemo\0sigLog\0\0onOpen\0onPrimary\0"
    "onStandby\0onClear\0onLog\0onGetData\0"
    "onUpdateData\0onAutoToggle\0state\0"
    "onRecovery\0onTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_replicationdemo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   72,    2, 0x08 /* Private */,
       4,    0,   73,    2, 0x08 /* Private */,
       5,    0,   74,    2, 0x08 /* Private */,
       6,    0,   75,    2, 0x08 /* Private */,
       7,    1,   76,    2, 0x08 /* Private */,
       8,    0,   79,    2, 0x08 /* Private */,
       9,    0,   80,    2, 0x08 /* Private */,
      10,    1,   81,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void replicationdemo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        replicationdemo *_t = static_cast<replicationdemo *>(_o);
        switch (_id) {
        case 0: _t->sigLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->onOpen(); break;
        case 2: _t->onPrimary(); break;
        case 3: _t->onStandby(); break;
        case 4: _t->onClear(); break;
        case 5: _t->onLog((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onGetData(); break;
        case 7: _t->onUpdateData(); break;
        case 8: _t->onAutoToggle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->onRecovery(); break;
        case 10: _t->onTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (replicationdemo::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&replicationdemo::sigLog)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject replicationdemo::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_replicationdemo.data,
      qt_meta_data_replicationdemo,  qt_static_metacall, 0, 0}
};


const QMetaObject *replicationdemo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *replicationdemo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_replicationdemo.stringdata))
        return static_cast<void*>(const_cast< replicationdemo*>(this));
    return QDialog::qt_metacast(_clname);
}

int replicationdemo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void replicationdemo::sigLog(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
