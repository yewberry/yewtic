/****************************************************************************
** Meta object code from reading C++ file 'editform.h'
**
** Created: Tue Dec 29 21:09:42 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editform.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      25,   22,    9,    9, 0x05,
      59,   22,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     102,    9,    9,    9, 0x0a,
     124,  110,    9,    9, 0x0a,
     150,  142,    9,    9, 0x0a,
     169,  142,    9,    9, 0x0a,
     199,  192,    9,    9, 0x0a,
     232,  222,    9,    9, 0x0a,
     253,    9,    9,    9, 0x0a,
     291,  278,    9,    9, 0x0a,
     317,    9,    9,    9, 0x0a,
     330,    9,    9,    9, 0x0a,
     343,    9,    9,    9, 0x0a,
     355,    9,    9,    9, 0x0a,
     369,    9,    9,    9, 0x0a,
     387,    9,    9,    9, 0x0a,
     403,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_editForm[] = {
    "editForm\0\0goingAway()\0,,\0"
    "updateRecordText(int,int,QString)\0"
    "updateRecordBinary(int,int,unsigned char*)\0"
    "reset()\0modifiedstate\0setModified(bool)\0"
    "enabled\0enableExport(bool)\0"
    "enableTextEditor(bool)\0format\0"
    "setTextFormat(QString)\0type,size\0"
    "setDataType(int,int)\0closeEvent(QCloseEvent*)\0"
    "text,row,col\0loadText(QString,int,int)\0"
    "importData()\0exportData()\0clearData()\0"
    "saveChanges()\0editTextChanged()\0"
    "editorClicked()\0languageChange()\0"
};

const QMetaObject editForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_editForm,
      qt_meta_data_editForm, 0 }
};

const QMetaObject *editForm::metaObject() const
{
    return &staticMetaObject;
}

void *editForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editForm))
        return static_cast<void*>(const_cast< editForm*>(this));
    if (!strcmp(_clname, "Ui::editForm"))
        return static_cast< Ui::editForm*>(const_cast< editForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int editForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: goingAway(); break;
        case 1: updateRecordText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: updateRecordBinary((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< unsigned char*(*)>(_a[3]))); break;
        case 3: reset(); break;
        case 4: setModified((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: enableExport((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: enableTextEditor((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setTextFormat((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: setDataType((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 10: loadText((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: importData(); break;
        case 12: exportData(); break;
        case 13: clearData(); break;
        case 14: saveChanges(); break;
        case 15: editTextChanged(); break;
        case 16: editorClicked(); break;
        case 17: languageChange(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void editForm::goingAway()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void editForm::updateRecordText(int _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void editForm::updateRecordBinary(int _t1, int _t2, unsigned char * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
