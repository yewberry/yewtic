/****************************************************************************
** Meta object code from reading C++ file 'renametableform.h'
**
** Created: Sun Jan 3 14:58:42 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../renametableform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'renametableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_renameTableForm[] = {

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
      38,   33,   16,   16, 0x0a,
      60,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_renameTableForm[] = {
    "renameTableForm\0\0renameClicked()\0name\0"
    "setTableName(QString)\0languageChange()\0"
};

const QMetaObject renameTableForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_renameTableForm,
      qt_meta_data_renameTableForm, 0 }
};

const QMetaObject *renameTableForm::metaObject() const
{
    return &staticMetaObject;
}

void *renameTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_renameTableForm))
        return static_cast<void*>(const_cast< renameTableForm*>(this));
    if (!strcmp(_clname, "Ui::renameTableForm"))
        return static_cast< Ui::renameTableForm*>(const_cast< renameTableForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int renameTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: renameClicked(); break;
        case 1: setTableName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: languageChange(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
