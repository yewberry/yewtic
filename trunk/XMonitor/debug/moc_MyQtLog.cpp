/****************************************************************************
** Meta object code from reading C++ file 'MyQtLog.h'
**
** Created: Fri Mar 4 20:01:22 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/MyQtLog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyQtLog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyQtLog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,    9,    8,    8, 0x0a,
      44,    9,    8,    8, 0x0a,
      65,    9,    8,    8, 0x0a,
      86,    9,    8,    8, 0x0a,
     107,    9,    8,    8, 0x0a,
     132,  128,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyQtLog[] = {
    "MyQtLog\0\0msg,file,line\0d(QString,char*,int)\0"
    "i(QString,char*,int)\0w(QString,char*,int)\0"
    "e(QString,char*,int)\0f(QString,char*,int)\0"
    "msg\0write(QString)\0"
};

const QMetaObject MyQtLog::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyQtLog,
      qt_meta_data_MyQtLog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyQtLog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyQtLog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyQtLog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyQtLog))
        return static_cast<void*>(const_cast< MyQtLog*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyQtLog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: d((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: i((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: w((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: e((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: f((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 5: write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
