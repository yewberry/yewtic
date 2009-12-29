/****************************************************************************
** Meta object code from reading C++ file 'importcsvform.h'
**
** Created: Tue Dec 29 21:09:40 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../importcsvform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'importcsvform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_importCSVForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      26,   15,   14,   14, 0x0a,
      60,   14,   14,   14, 0x0a,
      82,   14,   14,   14, 0x0a,
      92,   14,   14,   14, 0x0a,
     116,   14,   14,   14, 0x0a,
     143,  135,   14,   14, 0x0a,
     174,   14,   14,   14, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_importCSVForm[] = {
    "importCSVForm\0\0csvfile,db\0"
    "initialize(QString&,DBBrowserDB*)\0"
    "createButtonPressed()\0preview()\0"
    "fieldSeparatorChanged()\0textQuoteChanged()\0"
    "enabled\0extractFieldNamesChanged(bool)\0"
    "languageChange()\0"
};

const QMetaObject importCSVForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_importCSVForm,
      qt_meta_data_importCSVForm, 0 }
};

const QMetaObject *importCSVForm::metaObject() const
{
    return &staticMetaObject;
}

void *importCSVForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_importCSVForm))
        return static_cast<void*>(const_cast< importCSVForm*>(this));
    if (!strcmp(_clname, "Ui::importCSVForm"))
        return static_cast< Ui::importCSVForm*>(const_cast< importCSVForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int importCSVForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: initialize((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< DBBrowserDB*(*)>(_a[2]))); break;
        case 1: createButtonPressed(); break;
        case 2: preview(); break;
        case 3: fieldSeparatorChanged(); break;
        case 4: textQuoteChanged(); break;
        case 5: extractFieldNamesChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: languageChange(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
