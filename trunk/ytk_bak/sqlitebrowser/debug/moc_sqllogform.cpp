/****************************************************************************
** Meta object code from reading C++ file 'sqllogform.h'
**
** Created: Sun Jan 3 14:58:42 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../sqllogform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqllogform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sqlLogForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      30,   24,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   11,   11,   11, 0x0a,
      87,   69,   11,   11, 0x0a,
     105,   24,   11,   11, 0x0a,
     127,   11,   11,   11, 0x0a,
     138,   11,   11,   11, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_sqlLogForm[] = {
    "sqlLogForm\0\0goingAway()\0dirty\0"
    "dbState(bool)\0closeEvent(QCloseEvent*)\0"
    "statement,msgtype\0log(QString&,int)\0"
    "msgDBDirtyState(bool)\0clearLog()\0"
    "languageChange()\0"
};

const QMetaObject sqlLogForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_sqlLogForm,
      qt_meta_data_sqlLogForm, 0 }
};

const QMetaObject *sqlLogForm::metaObject() const
{
    return &staticMetaObject;
}

void *sqlLogForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sqlLogForm))
        return static_cast<void*>(const_cast< sqlLogForm*>(this));
    if (!strcmp(_clname, "Ui::sqlLogForm"))
        return static_cast< Ui::sqlLogForm*>(const_cast< sqlLogForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int sqlLogForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goingAway(); break;
        case 1: dbState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: log((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: msgDBDirtyState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: clearLog(); break;
        case 6: languageChange(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void sqlLogForm::goingAway()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void sqlLogForm::dbState(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
