/****************************************************************************
** Meta object code from reading C++ file 'deletetableform.h'
**
** Created: Tue Dec 29 21:09:43 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../deletetableform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deletetableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_deleteTableForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      41,   33,   16,   16, 0x0a,
      70,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_deleteTableForm[] = {
    "deleteTableForm\0\0confirmDelete()\0"
    "entries\0populateOptions(QStringList)\0"
    "languageChange()\0"
};

const QMetaObject deleteTableForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_deleteTableForm,
      qt_meta_data_deleteTableForm, 0 }
};

const QMetaObject *deleteTableForm::metaObject() const
{
    return &staticMetaObject;
}

void *deleteTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_deleteTableForm))
        return static_cast<void*>(const_cast< deleteTableForm*>(this));
    if (!strcmp(_clname, "Ui::deleteTableForm"))
        return static_cast< Ui::deleteTableForm*>(const_cast< deleteTableForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int deleteTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: confirmDelete(); break;
        case 1: populateOptions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: languageChange(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
