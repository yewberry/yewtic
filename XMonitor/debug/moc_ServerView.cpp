/****************************************************************************
** Meta object code from reading C++ file 'ServerView.h'
**
** Created: Fri Mar 4 20:01:05 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ServerView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerView[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      37,   11,   11,   11, 0x08,
      57,   52,   11,   11, 0x08,
      87,   11,   11,   11, 0x08,
     122,  119,  103,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerView[] = {
    "ServerView\0\0addServer()\0deleteItem()\0"
    "activeServer()\0node\0activeServer(ServerViewNode*)\0"
    "updateActions()\0ServerViewNode*\0id\0"
    "addItem(QString)\0"
};

const QMetaObject ServerView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerView,
      qt_meta_data_ServerView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServerView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServerView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServerView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerView))
        return static_cast<void*>(const_cast< ServerView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addServer(); break;
        case 1: deleteItem(); break;
        case 2: activeServer(); break;
        case 3: activeServer((*reinterpret_cast< ServerViewNode*(*)>(_a[1]))); break;
        case 4: updateActions(); break;
        case 5: { ServerViewNode* _r = addItem((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ServerViewNode**>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
