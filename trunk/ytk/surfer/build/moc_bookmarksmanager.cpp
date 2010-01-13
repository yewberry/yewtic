/****************************************************************************
** Meta object code from reading C++ file 'bookmarksmanager.h'
**
** Created: Wed Jan 13 16:25:46 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/bookmarksmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookmarksmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BookmarksManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x0a,
      25,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_BookmarksManager[] = {
    "BookmarksManager\0\0load()\0save()\0"
};

const QMetaObject BookmarksManager::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_BookmarksManager,
      qt_meta_data_BookmarksManager, 0 }
};

const QMetaObject *BookmarksManager::metaObject() const
{
    return &staticMetaObject;
}

void *BookmarksManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BookmarksManager))
        return static_cast<void*>(const_cast< BookmarksManager*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int BookmarksManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load(); break;
        case 1: save(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
