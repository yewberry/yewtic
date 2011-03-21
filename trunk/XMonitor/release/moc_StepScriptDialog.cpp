/****************************************************************************
** Meta object code from reading C++ file 'StepScriptDialog.h'
**
** Created: Mon Mar 21 09:20:26 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/StepScriptDialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StepScriptDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StepScriptDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   17,   17,   17, 0x0a,
      58,   17,   17,   17, 0x08,
      65,   17,   17,   17, 0x08,
      79,   74,   17,   17, 0x08,
     115,   74,   17,   17, 0x08,
     157,   17,   17,   17, 0x08,
     169,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StepScriptDialog[] = {
    "StepScriptDialog\0\0stepOrderChanged()\0"
    "onStepOrderChanged()\0save()\0runCmd()\0"
    "item\0onStepListClicked(QListWidgetItem*)\0"
    "onStepListDoubleClicked(QListWidgetItem*)\0"
    "onAddStep()\0onDelStep()\0"
};

const QMetaObject StepScriptDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StepScriptDialog,
      qt_meta_data_StepScriptDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StepScriptDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StepScriptDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StepScriptDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StepScriptDialog))
        return static_cast<void*>(const_cast< StepScriptDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StepScriptDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: stepOrderChanged(); break;
        case 1: onStepOrderChanged(); break;
        case 2: save(); break;
        case 3: runCmd(); break;
        case 4: onStepListClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: onStepListDoubleClicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 6: onAddStep(); break;
        case 7: onDelStep(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void StepScriptDialog::stepOrderChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_StepListWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_StepListWidget[] = {
    "StepListWidget\0"
};

const QMetaObject StepListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_StepListWidget,
      qt_meta_data_StepListWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StepListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StepListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StepListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StepListWidget))
        return static_cast<void*>(const_cast< StepListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int StepListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
