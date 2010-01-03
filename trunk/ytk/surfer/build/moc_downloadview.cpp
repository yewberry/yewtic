/****************************************************************************
** Meta object code from reading C++ file 'downloadview.h'
**
** Created: Sun Jan 3 14:58:35 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/downloadview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DownloadView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      36,   30,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DownloadView[] = {
    "DownloadView\0\0handleNewItem()\0index\0"
    "handleDeletedItem(int)\0"
};

const QMetaObject DownloadView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_DownloadView,
      qt_meta_data_DownloadView, 0 }
};

const QMetaObject *DownloadView::metaObject() const
{
    return &staticMetaObject;
}

void *DownloadView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DownloadView))
        return static_cast<void*>(const_cast< DownloadView*>(this));
    return QListView::qt_metacast(_clname);
}

int DownloadView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleNewItem(); break;
        case 1: handleDeletedItem((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
