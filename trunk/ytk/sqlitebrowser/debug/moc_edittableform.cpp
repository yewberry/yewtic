/****************************************************************************
** Meta object code from reading C++ file 'edittableform.h'
**
** Created: Tue Dec 29 21:09:42 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../edittableform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edittableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editTableForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      31,   15,   14,   14, 0x0a,
      68,   14,   14,   14, 0x0a,
      85,   14,   14,   14, 0x0a,
      99,   14,   14,   14, 0x0a,
     111,   14,   14,   14, 0x0a,
     122,   14,   14,   14, 0x0a,
     136,   14,   14,   14, 0x0a,
     160,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_editTableForm[] = {
    "editTableForm\0\0thedb,tableName\0"
    "setActiveTable(DBBrowserDB*,QString)\0"
    "populateFields()\0renameTable()\0"
    "editField()\0addField()\0removeField()\0"
    "fieldSelectionChanged()\0languageChange()\0"
};

const QMetaObject editTableForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_editTableForm,
      qt_meta_data_editTableForm, 0 }
};

const QMetaObject *editTableForm::metaObject() const
{
    return &staticMetaObject;
}

void *editTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editTableForm))
        return static_cast<void*>(const_cast< editTableForm*>(this));
    if (!strcmp(_clname, "Ui::editTableForm"))
        return static_cast< Ui::editTableForm*>(const_cast< editTableForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int editTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setActiveTable((*reinterpret_cast< DBBrowserDB*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: populateFields(); break;
        case 2: renameTable(); break;
        case 3: editField(); break;
        case 4: addField(); break;
        case 5: removeField(); break;
        case 6: fieldSelectionChanged(); break;
        case 7: languageChange(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
