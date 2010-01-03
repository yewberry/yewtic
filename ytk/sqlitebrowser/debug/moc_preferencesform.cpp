/****************************************************************************
** Meta object code from reading C++ file 'preferencesform.h'
**
** Created: Sun Jan 3 14:58:42 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../preferencesform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'preferencesform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_preferencesForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x0a,
      47,   17,   16,   16, 0x0a,
      71,   17,   16,   16, 0x0a,
      92,   16,   16,   16, 0x0a,
     109,   16,   16,   16, 0x0a,
     124,   16,   16,   16, 0x0a,
     139,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_preferencesForm[] = {
    "preferencesForm\0\0which\0defaultDataChanged(int)\0"
    "defaultTextChanged(int)\0encodingChanged(int)\0"
    "chooseLocation()\0loadSettings()\0"
    "saveSettings()\0languageChange()\0"
};

const QMetaObject preferencesForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_preferencesForm,
      qt_meta_data_preferencesForm, 0 }
};

const QMetaObject *preferencesForm::metaObject() const
{
    return &staticMetaObject;
}

void *preferencesForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_preferencesForm))
        return static_cast<void*>(const_cast< preferencesForm*>(this));
    if (!strcmp(_clname, "Ui::preferencesForm"))
        return static_cast< Ui::preferencesForm*>(const_cast< preferencesForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int preferencesForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: defaultDataChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: defaultTextChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: encodingChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: chooseLocation(); break;
        case 4: loadSettings(); break;
        case 5: saveSettings(); break;
        case 6: languageChange(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
