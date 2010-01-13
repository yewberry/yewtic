/****************************************************************************
** Meta object code from reading C++ file 'adressbar.h'
**
** Created: Wed Jan 13 16:25:54 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/adressbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adressbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AdressBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   11,   10,   10, 0x0a,
      47,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AdressBar[] = {
    "AdressBar\0\0url\0loadRequsted(QUrl)\0"
    "setUrl(QUrl)\0load()\0"
};

const QMetaObject AdressBar::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_AdressBar,
      qt_meta_data_AdressBar, 0 }
};

const QMetaObject *AdressBar::metaObject() const
{
    return &staticMetaObject;
}

void *AdressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AdressBar))
        return static_cast<void*>(const_cast< AdressBar*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int AdressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: loadRequsted((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: load(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AdressBar::loadRequsted(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
