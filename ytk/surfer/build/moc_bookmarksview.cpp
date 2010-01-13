/****************************************************************************
** Meta object code from reading C++ file 'bookmarksview.h'
**
** Created: Wed Jan 13 16:25:45 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/bookmarksview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bookmarksview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BookmarksView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      37,   14,   14,   14, 0x08,
      52,   14,   14,   14, 0x08,
      64,   14,   14,   14, 0x08,
      74,   14,   14,   14, 0x08,
      95,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BookmarksView[] = {
    "BookmarksView\0\0addTabToCurrentItem()\0"
    "createFolder()\0editTitle()\0editUrl()\0"
    "copyCurrentItemUrl()\0removeCurrentItem()\0"
};

const QMetaObject BookmarksView::staticMetaObject = {
    { &QTreeView::staticMetaObject, qt_meta_stringdata_BookmarksView,
      qt_meta_data_BookmarksView, 0 }
};

const QMetaObject *BookmarksView::metaObject() const
{
    return &staticMetaObject;
}

void *BookmarksView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BookmarksView))
        return static_cast<void*>(const_cast< BookmarksView*>(this));
    return QTreeView::qt_metacast(_clname);
}

int BookmarksView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addTabToCurrentItem(); break;
        case 1: createFolder(); break;
        case 2: editTitle(); break;
        case 3: editUrl(); break;
        case 4: copyCurrentItemUrl(); break;
        case 5: removeCurrentItem(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
