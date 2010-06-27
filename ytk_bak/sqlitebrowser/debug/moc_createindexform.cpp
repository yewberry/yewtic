/****************************************************************************
** Meta object code from reading C++ file 'createindexform.h'
**
** Created: Sun Jan 3 14:58:46 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../createindexform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createindexform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_createIndexForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x0a,
      46,   16,   16,   16, 0x0a,
      67,   62,   16,   16, 0x0a,
      91,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_createIndexForm[] = {
    "createIndexForm\0\0entry\0tableSelected(QString)\0"
    "confirmCreate()\0rmap\0populateTable(tableMap)\0"
    "languageChange()\0"
};

const QMetaObject createIndexForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_createIndexForm,
      qt_meta_data_createIndexForm, 0 }
};

const QMetaObject *createIndexForm::metaObject() const
{
    return &staticMetaObject;
}

void *createIndexForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_createIndexForm))
        return static_cast<void*>(const_cast< createIndexForm*>(this));
    if (!strcmp(_clname, "Ui::createIndexForm"))
        return static_cast< Ui::createIndexForm*>(const_cast< createIndexForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int createIndexForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: tableSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: confirmCreate(); break;
        case 2: populateTable((*reinterpret_cast< tableMap(*)>(_a[1]))); break;
        case 3: languageChange(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
