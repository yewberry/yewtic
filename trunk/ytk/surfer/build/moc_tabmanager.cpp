/****************************************************************************
** Meta object code from reading C++ file 'tabmanager.h'
**
** Created: Sun Jan 3 14:58:23 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tabmanager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tabmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TabManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x0a,
      48,   44,   39,   11, 0x0a,
      61,   11,   39,   11, 0x2a,
      80,   70,   39,   11, 0x0a,
     100,   12,   39,   11, 0x2a,
     115,   11,   11,   11, 0x0a,
     134,   12,   11,   11, 0x0a,
     149,   11,   11,   11, 0x0a,
     165,   12,   11,   11, 0x0a,
     181,   11,   11,   11, 0x2a,
     194,   11,   11,   11, 0x0a,
     213,   11,   11,   11, 0x0a,
     220,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_TabManager[] = {
    "TabManager\0\0index\0setCurrentIndex(int)\0"
    "Tab*\0url\0addTab(QUrl)\0addTab()\0index,url\0"
    "insertTab(int,QUrl)\0insertTab(int)\0"
    "removeCurrentTab()\0removeTab(int)\0"
    "removeAllTabs()\0restoreTab(int)\0"
    "restoreTab()\0clearRestoreList()\0load()\0"
    "save()\0"
};

const QMetaObject TabManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TabManager,
      qt_meta_data_TabManager, 0 }
};

const QMetaObject *TabManager::metaObject() const
{
    return &staticMetaObject;
}

void *TabManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TabManager))
        return static_cast<void*>(const_cast< TabManager*>(this));
    return QObject::qt_metacast(_clname);
}

int TabManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setCurrentIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { Tab* _r = addTab((*reinterpret_cast< const QUrl(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Tab**>(_a[0]) = _r; }  break;
        case 2: { Tab* _r = addTab();
            if (_a[0]) *reinterpret_cast< Tab**>(_a[0]) = _r; }  break;
        case 3: { Tab* _r = insertTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< const QUrl(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Tab**>(_a[0]) = _r; }  break;
        case 4: { Tab* _r = insertTab((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Tab**>(_a[0]) = _r; }  break;
        case 5: removeCurrentTab(); break;
        case 6: removeTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: removeAllTabs(); break;
        case 8: restoreTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: restoreTab(); break;
        case 10: clearRestoreList(); break;
        case 11: load(); break;
        case 12: save(); break;
        default: ;
        }
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
