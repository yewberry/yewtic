/****************************************************************************
** Meta object code from reading C++ file 'toolbar.h'
**
** Created: Sun Jan 3 14:58:21 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/toolbar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ToolBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      26,    8,    8,    8, 0x05,
      46,    8,    8,    8, 0x05,
      63,    8,    8,    8, 0x05,
      82,   78,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     101,   78,    8,    8, 0x0a,
     114,    8,    8,    8, 0x0a,
     130,    8,    8,    8, 0x0a,
     149,    8,    8,    8, 0x0a,
     169,    8,    8,    8, 0x08,
     186,    8,    8,    8, 0x08,
     206,    8,    8,    8, 0x08,
     226,    8,    8,    8, 0x08,
     248,    8,    8,    8, 0x08,
     268,    8,    8,    8, 0x08,
     279,    8,    8,    8, 0x08,
     289,    8,    8,    8, 0x08,
     300,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ToolBar[] = {
    "ToolBar\0\0goBackRequsted()\0goForwardRequsted()\0"
    "reloadRequsted()\0stopRequsted()\0url\0"
    "loadRequsted(QUrl)\0setUrl(QUrl)\0"
    "updateActions()\0enableStopAction()\0"
    "disableStopAction()\0updateBackMenu()\0"
    "updateForwardMenu()\0updateRestoreMenu()\0"
    "updateBookmarksMenu()\0updateHistoryMenu()\0"
    "navigate()\0restore()\0openItem()\0"
    "createBookmark()\0"
};

const QMetaObject ToolBar::staticMetaObject = {
    { &QToolBar::staticMetaObject, qt_meta_stringdata_ToolBar,
      qt_meta_data_ToolBar, 0 }
};

const QMetaObject *ToolBar::metaObject() const
{
    return &staticMetaObject;
}

void *ToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ToolBar))
        return static_cast<void*>(const_cast< ToolBar*>(this));
    return QToolBar::qt_metacast(_clname);
}

int ToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goBackRequsted(); break;
        case 1: goForwardRequsted(); break;
        case 2: reloadRequsted(); break;
        case 3: stopRequsted(); break;
        case 4: loadRequsted((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 5: setUrl((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 6: updateActions(); break;
        case 7: enableStopAction(); break;
        case 8: disableStopAction(); break;
        case 9: updateBackMenu(); break;
        case 10: updateForwardMenu(); break;
        case 11: updateRestoreMenu(); break;
        case 12: updateBookmarksMenu(); break;
        case 13: updateHistoryMenu(); break;
        case 14: navigate(); break;
        case 15: restore(); break;
        case 16: openItem(); break;
        case 17: createBookmark(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void ToolBar::goBackRequsted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ToolBar::goForwardRequsted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ToolBar::reloadRequsted()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void ToolBar::stopRequsted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void ToolBar::loadRequsted(const QUrl & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
