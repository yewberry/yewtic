/****************************************************************************
** Meta object code from reading C++ file 'tab.h'
**
** Created: Sun Jan 3 14:58:24 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tab[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x0a,
      18,   14,    4,    4, 0x0a,
      29,    4,    4,    4, 0x08,
      43,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Tab[] = {
    "Tab\0\0reload()\0url\0load(QUrl)\0updateTitle()\0"
    "updateIcon()\0"
};

const QMetaObject Tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tab,
      qt_meta_data_Tab, 0 }
};

const QMetaObject *Tab::metaObject() const
{
    return &staticMetaObject;
}

void *Tab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tab))
        return static_cast<void*>(const_cast< Tab*>(this));
    return QWidget::qt_metacast(_clname);
}

int Tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reload(); break;
        case 1: load((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: updateTitle(); break;
        case 3: updateIcon(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
