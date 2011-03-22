/****************************************************************************
** Meta object code from reading C++ file 'XMonitor.h'
**
** Created: Tue Mar 22 17:24:07 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/XMonitor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XMonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XMonitor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      27,    9,    9,    9, 0x08,
      44,    9,    9,    9, 0x08,
      68,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_XMonitor[] = {
    "XMonitor\0\0showServerView()\0showReportView()\0"
    "startBackgroundThread()\0stopBackgroundThread()\0"
};

const QMetaObject XMonitor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_XMonitor,
      qt_meta_data_XMonitor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XMonitor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XMonitor))
        return static_cast<void*>(const_cast< XMonitor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int XMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: showServerView(); break;
        case 1: showReportView(); break;
        case 2: startBackgroundThread(); break;
        case 3: stopBackgroundThread(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
