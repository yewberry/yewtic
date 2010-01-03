/****************************************************************************
** Meta object code from reading C++ file 'editformwindow.h'
**
** Created: Sun Jan 3 14:58:44 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editformwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editformwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_editFormWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,
      26,   15,   15,   15, 0x0a,
      37,   15,   15,   15, 0x0a,
      48,   15,   15,   15, 0x0a,
      61,   15,   15,   15, 0x0a,
      73,   15,   15,   15, 0x0a,
      84,   15,   15,   15, 0x0a,
      95,   15,   15,   15, 0x0a,
     106,   15,   15,   15, 0x0a,
     116,   15,   15,   15, 0x0a,
     127,   15,   15,   15, 0x0a,
     139,   15,   15,   15, 0x0a,
     150,   15,   15,   15, 0x0a,
     162,   15,   15,   15, 0x0a,
     177,   15,   15,   15, 0x0a,
     189,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_editFormWindow[] = {
    "editFormWindow\0\0fileNew()\0fileOpen()\0"
    "fileSave()\0fileSaveAs()\0filePrint()\0"
    "fileExit()\0editUndo()\0editRedo()\0"
    "editCut()\0editCopy()\0editPaste()\0"
    "editFind()\0helpIndex()\0helpContents()\0"
    "helpAbout()\0languageChange()\0"
};

const QMetaObject editFormWindow::staticMetaObject = {
    { &Q3MainWindow::staticMetaObject, qt_meta_stringdata_editFormWindow,
      qt_meta_data_editFormWindow, 0 }
};

const QMetaObject *editFormWindow::metaObject() const
{
    return &staticMetaObject;
}

void *editFormWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_editFormWindow))
        return static_cast<void*>(const_cast< editFormWindow*>(this));
    if (!strcmp(_clname, "Ui::editFormWindow"))
        return static_cast< Ui::editFormWindow*>(const_cast< editFormWindow*>(this));
    return Q3MainWindow::qt_metacast(_clname);
}

int editFormWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileNew(); break;
        case 1: fileOpen(); break;
        case 2: fileSave(); break;
        case 3: fileSaveAs(); break;
        case 4: filePrint(); break;
        case 5: fileExit(); break;
        case 6: editUndo(); break;
        case 7: editRedo(); break;
        case 8: editCut(); break;
        case 9: editCopy(); break;
        case 10: editPaste(); break;
        case 11: editFind(); break;
        case 12: helpIndex(); break;
        case 13: helpContents(); break;
        case 14: helpAbout(); break;
        case 15: languageChange(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
