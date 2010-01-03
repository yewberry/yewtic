/****************************************************************************
** Meta object code from reading C++ file 'settingsmanager.h'
**
** Created: Sun Jan 3 14:58:26 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/settingsmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingsmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SettingsManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      25,   16,   16,   16, 0x0a,
      32,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SettingsManager[] = {
    "SettingsManager\0\0reset()\0load()\0save()\0"
};

const QMetaObject SettingsManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SettingsManager,
      qt_meta_data_SettingsManager, 0 }
};

const QMetaObject *SettingsManager::metaObject() const
{
    return &staticMetaObject;
}

void *SettingsManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SettingsManager))
        return static_cast<void*>(const_cast< SettingsManager*>(this));
    return QObject::qt_metacast(_clname);
}

int SettingsManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reset(); break;
        case 1: load(); break;
        case 2: save(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
