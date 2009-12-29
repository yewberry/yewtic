/****************************************************************************
** Meta object code from reading C++ file 'choosetableform.h'
**
** Created: Tue Dec 29 21:09:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../choosetableform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choosetableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_chooseTableForm[] = {

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
      39,   31,   16,   16, 0x0a,
      68,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_chooseTableForm[] = {
    "chooseTableForm\0\0editPressed()\0entries\0"
    "populateOptions(QStringList)\0"
    "languageChange()\0"
};

const QMetaObject chooseTableForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_chooseTableForm,
      qt_meta_data_chooseTableForm, 0 }
};

const QMetaObject *chooseTableForm::metaObject() const
{
    return &staticMetaObject;
}

void *chooseTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_chooseTableForm))
        return static_cast<void*>(const_cast< chooseTableForm*>(this));
    if (!strcmp(_clname, "Ui::chooseTableForm"))
        return static_cast< Ui::chooseTableForm*>(const_cast< chooseTableForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int chooseTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: editPressed(); break;
        case 1: populateOptions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: languageChange(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
