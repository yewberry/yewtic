/****************************************************************************
** Meta object code from reading C++ file 'aboutform.h'
**
** Created: Tue Dec 29 21:09:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../aboutform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aboutform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_aboutForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_aboutForm[] = {
    "aboutForm\0\0languageChange()\0"
};

const QMetaObject aboutForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_aboutForm,
      qt_meta_data_aboutForm, 0 }
};

const QMetaObject *aboutForm::metaObject() const
{
    return &staticMetaObject;
}

void *aboutForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_aboutForm))
        return static_cast<void*>(const_cast< aboutForm*>(this));
    if (!strcmp(_clname, "Ui::aboutForm"))
        return static_cast< Ui::aboutForm*>(const_cast< aboutForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int aboutForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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