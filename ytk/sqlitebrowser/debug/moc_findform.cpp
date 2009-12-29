/****************************************************************************
** Meta object code from reading C++ file 'findform.h'
**
** Created: Tue Dec 29 21:09:41 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../findform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_findForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      13,   10,    9,    9, 0x05,
      46,    9,    9,    9, 0x05,
      62,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   74,    9,    9, 0x0a,
     102,    9,    9,    9, 0x0a,
     119,  109,    9,    9, 0x0a,
     144,    9,    9,    9, 0x0a,
     165,  159,    9,    9, 0x0a,
     197,    9,    9,    9, 0x0a,
     222,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_findForm[] = {
    "findForm\0\0,,\0lookfor(QString,QString,QString)\0"
    "showrecord(int)\0goingAway()\0rmap\0"
    "showResults(resultMap)\0find()\0fieldlist\0"
    "resetFields(QStringList)\0resetResults()\0"
    "witem\0recordSelected(Q3ListViewItem*)\0"
    "closeEvent(QCloseEvent*)\0languageChange()\0"
};

const QMetaObject findForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_findForm,
      qt_meta_data_findForm, 0 }
};

const QMetaObject *findForm::metaObject() const
{
    return &staticMetaObject;
}

void *findForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_findForm))
        return static_cast<void*>(const_cast< findForm*>(this));
    if (!strcmp(_clname, "Ui::findForm"))
        return static_cast< Ui::findForm*>(const_cast< findForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int findForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lookfor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: showrecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: goingAway(); break;
        case 3: showResults((*reinterpret_cast< resultMap(*)>(_a[1]))); break;
        case 4: find(); break;
        case 5: resetFields((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: resetResults(); break;
        case 7: recordSelected((*reinterpret_cast< Q3ListViewItem*(*)>(_a[1]))); break;
        case 8: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: languageChange(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void findForm::lookfor(const QString & _t1, const QString & _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void findForm::showrecord(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void findForm::goingAway()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
