/****************************************************************************
** Meta object code from reading C++ file 'exporttablecsvform.h'
**
** Created: Sun Jan 3 14:58:44 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../exporttablecsvform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'exporttablecsvform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_exportTableCSVForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x0a,
      44,   36,   19,   19, 0x0a,
      73,   19,   19,   19, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_exportTableCSVForm[] = {
    "exportTableCSVForm\0\0exportPressed()\0"
    "entries\0populateOptions(QStringList)\0"
    "languageChange()\0"
};

const QMetaObject exportTableCSVForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_exportTableCSVForm,
      qt_meta_data_exportTableCSVForm, 0 }
};

const QMetaObject *exportTableCSVForm::metaObject() const
{
    return &staticMetaObject;
}

void *exportTableCSVForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_exportTableCSVForm))
        return static_cast<void*>(const_cast< exportTableCSVForm*>(this));
    if (!strcmp(_clname, "Ui::exportTableCSVForm"))
        return static_cast< Ui::exportTableCSVForm*>(const_cast< exportTableCSVForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int exportTableCSVForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: exportPressed(); break;
        case 1: populateOptions((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: languageChange(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
