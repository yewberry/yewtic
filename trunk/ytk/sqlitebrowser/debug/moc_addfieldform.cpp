/****************************************************************************
** Meta object code from reading C++ file 'addfieldform.h'
**
** Created: Tue Dec 29 21:09:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../addfieldform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addfieldform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_addFieldForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      24,   14,   13,   13, 0x0a,
      58,   13,   13,   13, 0x0a,
      76,   13,   13,   13, 0x0a,
      92,   13,   13,   13, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_addFieldForm[] = {
    "addFieldForm\0\0name,type\0"
    "setInitialValues(QString,QString)\0"
    "confirmAddField()\0getCustomType()\0"
    "languageChange()\0"
};

const QMetaObject addFieldForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addFieldForm,
      qt_meta_data_addFieldForm, 0 }
};

const QMetaObject *addFieldForm::metaObject() const
{
    return &staticMetaObject;
}

void *addFieldForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_addFieldForm))
        return static_cast<void*>(const_cast< addFieldForm*>(this));
    if (!strcmp(_clname, "Ui::addFieldForm"))
        return static_cast< Ui::addFieldForm*>(const_cast< addFieldForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int addFieldForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setInitialValues((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: confirmAddField(); break;
        case 2: getCustomType(); break;
        case 3: languageChange(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
