/****************************************************************************
** Meta object code from reading C++ file 'searchbar.h'
**
** Created: Sun Jan 3 14:58:27 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/searchbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SearchBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      38,   11,   10,   10, 0x05,
      75,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SearchBar[] = {
    "SearchBar\0\0text,forward,caseSensitive\0"
    "searchDataChanged(QString,bool,bool)\0"
    "closeRequested()\0changeSearchData()\0"
};

const QMetaObject SearchBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_SearchBar,
      qt_meta_data_SearchBar, 0 }
};

const QMetaObject *SearchBar::metaObject() const
{
    return &staticMetaObject;
}

void *SearchBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchBar))
        return static_cast<void*>(const_cast< SearchBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int SearchBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: searchDataChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: closeRequested(); break;
        case 2: changeSearchData(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SearchBar::searchDataChanged(const QString & _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SearchBar::closeRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
