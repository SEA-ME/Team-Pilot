/****************************************************************************
** Meta object code from reading C++ file 'datacontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../files/datacontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datacontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataController_t {
    QByteArrayData data[15];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataController_t qt_meta_stringdata_DataController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DataController"
QT_MOC_LITERAL(1, 15, 12), // "speedChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "rpmChanged"
QT_MOC_LITERAL(4, 40, 11), // "tempChanged"
QT_MOC_LITERAL(5, 52, 10), // "humChanged"
QT_MOC_LITERAL(6, 63, 14), // "batteryChanged"
QT_MOC_LITERAL(7, 78, 15), // "distanceChanged"
QT_MOC_LITERAL(8, 94, 10), // "updateFunc"
QT_MOC_LITERAL(9, 105, 5), // "speed"
QT_MOC_LITERAL(10, 111, 3), // "rpm"
QT_MOC_LITERAL(11, 115, 11), // "temperature"
QT_MOC_LITERAL(12, 127, 8), // "humidity"
QT_MOC_LITERAL(13, 136, 7), // "battery"
QT_MOC_LITERAL(14, 144, 8) // "distance"

    },
    "DataController\0speedChanged\0\0rpmChanged\0"
    "tempChanged\0humChanged\0batteryChanged\0"
    "distanceChanged\0updateFunc\0speed\0rpm\0"
    "temperature\0humidity\0battery\0distance"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       6,   56, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,
       5,    0,   52,    2, 0x06 /* Public */,
       6,    0,   53,    2, 0x06 /* Public */,
       7,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       9, QMetaType::Int, 0x00495103,
      10, QMetaType::Int, 0x00495103,
      11, QMetaType::Int, 0x00495103,
      12, QMetaType::Int, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void DataController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->speedChanged(); break;
        case 1: _t->rpmChanged(); break;
        case 2: _t->tempChanged(); break;
        case 3: _t->humChanged(); break;
        case 4: _t->batteryChanged(); break;
        case 5: _t->distanceChanged(); break;
        case 6: _t->updateFunc(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::speedChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::rpmChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::tempChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::humChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::batteryChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DataController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DataController::distanceChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DataController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getSpeed(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getRpm(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->getTemperature(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getHumidity(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getBattery(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getDistance(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DataController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSpeed(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setRpm(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setTemperature(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setHumidity(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setBattery(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setDistance(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject DataController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DataController.data,
    qt_meta_data_DataController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DataController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DataController::speedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DataController::rpmChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DataController::tempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DataController::humChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DataController::batteryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DataController::distanceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
