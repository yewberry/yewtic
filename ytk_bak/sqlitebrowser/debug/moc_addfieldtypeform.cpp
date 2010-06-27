/****************************************************************************
** Meta object code from reading C++ file 'addfieldtypeform.h'
**
** Created: Sun Jan 3 14:58:47 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addfieldtypeform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfieldtypeform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addFieldTypeForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_addFieldTypeForm[] = {
    "addFieldTypeForm\0\0languageChange()\0"
};

const QMetaObject addFieldTypeForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addFieldTypeForm,
      qt_meta_data_addFieldTypeForm, 0 }
};

const QMetaObject *addFieldTypeForm::metaObject() const
{
    return &staticMetaObject;
}

void *addFieldTypeForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addFieldTypeForm))
        return static_cast<void*>(const_cast< addFieldTypeForm*>(this));
    if (!strcmp(_clname, "Ui::addFieldTypeForm"))
        return static_cast< Ui::addFieldTypeForm*>(const_cast< addFieldTypeForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int addFieldTypeForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: languageChange(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
