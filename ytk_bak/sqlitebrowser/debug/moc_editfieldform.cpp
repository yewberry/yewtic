/****************************************************************************
** Meta object code from reading C++ file 'editfieldform.h'
**
** Created: Sun Jan 3 14:58:45 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editfieldform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editfieldform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editFieldForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   15,   14,   14, 0x0a,
      59,   14,   14,   14, 0x0a,
      73,   14,   14,   14, 0x0a,
      86,   14,   14,   14, 0x0a,
     102,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_editFieldForm[] = {
    "editFieldForm\0\0name,type\0"
    "setInitialValues(QString,QString)\0"
    "confirmEdit()\0enableSave()\0getCustomType()\0"
    "languageChange()\0"
};

const QMetaObject editFieldForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_editFieldForm,
      qt_meta_data_editFieldForm, 0 }
};

const QMetaObject *editFieldForm::metaObject() const
{
    return &staticMetaObject;
}

void *editFieldForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editFieldForm))
        return static_cast<void*>(const_cast< editFieldForm*>(this));
    if (!strcmp(_clname, "Ui::editFieldForm"))
        return static_cast< Ui::editFieldForm*>(const_cast< editFieldForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int editFieldForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setInitialValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: confirmEdit(); break;
        case 2: enableSave(); break;
        case 3: getCustomType(); break;
        case 4: languageChange(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
