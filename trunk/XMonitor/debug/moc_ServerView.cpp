/****************************************************************************
** Meta object code from reading C++ file 'ServerView.h'
**
** Created: Tue Mar 8 17:07:30 2011
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
      34,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      62,   11,   11,   11, 0x08,
      97,   94,   78,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ServerView[] = {
    "ServerView\0\0addServer()\0addStep()\0"
    "deleteItem()\0activeServer()\0updateActions()\0"
    "ServerViewNode*\0id\0addItem(QString)\0"
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
        case 1: addStep(); break;
        case 2: deleteItem(); break;
        case 3: activeServer(); break;
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
