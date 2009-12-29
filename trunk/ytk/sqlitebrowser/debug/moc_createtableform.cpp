/****************************************************************************
** Meta object code from reading C++ file 'createtableform.h'
**
** Created: Tue Dec 29 21:09:43 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../createtableform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createtableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_createTableForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      33,   16,   16,   16, 0x0a,
      44,   16,   16,   16, 0x0a,
      58,   16,   16,   16, 0x0a,
      82,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_createTableForm[] = {
    "createTableForm\0\0confirmCreate()\0"
    "addField()\0deleteField()\0"
    "fieldSelectionChanged()\0languageChange()\0"
};

const QMetaObject createTableForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_createTableForm,
      qt_meta_data_createTableForm, 0 }
};

const QMetaObject *createTableForm::metaObject() const
{
    return &staticMetaObject;
}

void *createTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_createTableForm))
        return static_cast<void*>(const_cast< createTableForm*>(this));
    if (!strcmp(_clname, "Ui::createTableForm"))
        return static_cast< Ui::createTableForm*>(const_cast< createTableForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int createTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: confirmCreate(); break;
        case 1: addField(); break;
        case 2: deleteField(); break;
        case 3: fieldSelectionChanged(); break;
        case 4: languageChange(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
