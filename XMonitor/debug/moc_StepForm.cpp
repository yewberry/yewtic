/****************************************************************************
** Meta object code from reading C++ file 'StepForm.h'
**
** Created: Thu Mar 17 14:56:13 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/StepForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StepForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StepForm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      17,    9,    9,    9, 0x0a,
      30,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_StepForm[] = {
    "StepForm\0\0save()\0delCurStep()\0"
    "editScript()\0"
};

const QMetaObject StepForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StepForm,
      qt_meta_data_StepForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StepForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StepForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StepForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StepForm))
        return static_cast<void*>(const_cast< StepForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int StepForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: save(); break;
        case 1: delCurStep(); break;
        case 2: editScript(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
