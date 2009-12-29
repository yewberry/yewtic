/****************************************************************************
** Meta object code from reading C++ file 'form1.h'
**
** Created: Tue Dec 29 21:09:41 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../form1.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'form1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainForm[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      49,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      19,   10,    9,    9, 0x0a,
      37,    9,    9,    9, 0x0a,
      48,    9,    9,    9, 0x0a,
      58,    9,    9,    9, 0x0a,
      88,   78,    9,    9, 0x0a,
     111,    9,    9,    9, 0x0a,
     126,    9,    9,    9, 0x0a,
     138,    9,    9,    9, 0x0a,
     149,    9,    9,    9, 0x0a,
     174,    9,    9,    9, 0x0a,
     186,    9,    9,    9, 0x0a,
     214,  201,    9,    9, 0x0a,
     235,  201,    9,    9, 0x0a,
     256,    9,    9,    9, 0x0a,
     275,    9,    9,    9, 0x0a,
     290,    9,    9,    9, 0x0a,
     305,    9,    9,    9, 0x0a,
     330,  325,    9,    9, 0x0a,
     347,    9,    9,    9, 0x0a,
     393,  364,    9,    9, 0x0a,
     430,  426,    9,    9, 0x0a,
     446,    9,    9,    9, 0x0a,
     460,    9,    9,    9, 0x0a,
     474,    9,    9,    9, 0x0a,
     484,    9,    9,    9, 0x0a,
     498,    9,    9,    9, 0x0a,
     510,    9,    9,    9, 0x0a,
     524,    9,    9,    9, 0x0a,
     531,    9,    9,    9, 0x0a,
     539,    9,    9,    9, 0x0a,
     555,    9,    9,    9, 0x0a,
     583,  567,    9,    9, 0x0a,
     617,    9,    9,    9, 0x0a,
     630,    9,    9,    9, 0x0a,
     652,  644,    9,    9, 0x0a,
     696,  670,    9,    9, 0x0a,
     733,    9,    9,    9, 0x0a,
     756,  748,    9,    9, 0x0a,
     788,  781,    9,    9, 0x0a,
     810,    9,    9,    9, 0x0a,
     831,    9,    9,    9, 0x0a,
     856,  850,    9,    9, 0x0a,
     870,    9,    9,    9, 0x0a,
     881,    9,    9,    9, 0x0a,
     894,    9,    9,    9, 0x0a,
     916,    9,    9,    9, 0x0a,
     940,    9,    9,    9, 0x0a,
     958,    9,    9,    9, 0x0a,
     978,    9,    9,    9, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_mainForm[] = {
    "mainForm\0\0fileName\0fileOpen(QString)\0"
    "fileOpen()\0fileNew()\0populateStructure()\0"
    "tablename\0populateTable(QString)\0"
    "resetBrowser()\0fileClose()\0fileExit()\0"
    "closeEvent(QCloseEvent*)\0addRecord()\0"
    "deleteRecord()\0lineToSelect\0"
    "updateTableView(int)\0selectTableLine(int)\0"
    "navigatePrevious()\0navigateNext()\0"
    "navigateGoto()\0setRecordsetLabel()\0"
    "open\0browseFind(bool)\0browseFindAway()\0"
    "wfield,woperator,wsearchterm\0"
    "lookfor(QString,QString,QString)\0dec\0"
    "showrecord(int)\0createTable()\0"
    "createIndex()\0compact()\0deleteTable()\0"
    "editTable()\0deleteIndex()\0copy()\0"
    "paste()\0helpWhatsThis()\0helpAbout()\0"
    "row,col,newtext\0updateRecordText(int,int,QString)\0"
    "logWinAway()\0editWinAway()\0row,col\0"
    "editText(int,int)\0row,col,button,mousepoint\0"
    "doubleClickTable(int,int,int,QPoint)\0"
    "executeQuery()\0tabname\0mainTabSelected(QString)\0"
    "enable\0toggleLogWindow(bool)\0"
    "importTableFromCSV()\0exportTableToCSV()\0"
    "dirty\0dbState(bool)\0fileSave()\0"
    "fileRevert()\0exportDatabaseToSQL()\0"
    "importDatabaseFromSQL()\0openPreferences()\0"
    "updatePreferences()\0languageChange()\0"
};

const QMetaObject mainForm::staticMetaObject = {
    { &Q3MainWindow::staticMetaObject, qt_meta_stringdata_mainForm,
      qt_meta_data_mainForm, 0 }
};

const QMetaObject *mainForm::metaObject() const
{
    return &staticMetaObject;
}

void *mainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainForm))
        return static_cast<void*>(const_cast< mainForm*>(this));
    if (!strcmp(_clname, "Ui::mainForm"))
        return static_cast< Ui::mainForm*>(const_cast< mainForm*>(this));
    return Q3MainWindow::qt_metacast(_clname);
}

int mainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Q3MainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileOpen((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: fileOpen(); break;
        case 2: fileNew(); break;
        case 3: populateStructure(); break;
        case 4: populateTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: resetBrowser(); break;
        case 6: fileClose(); break;
        case 7: fileExit(); break;
        case 8: closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 9: addRecord(); break;
        case 10: deleteRecord(); break;
        case 11: updateTableView((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: selectTableLine((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: navigatePrevious(); break;
        case 14: navigateNext(); break;
        case 15: navigateGoto(); break;
        case 16: setRecordsetLabel(); break;
        case 17: browseFind((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: browseFindAway(); break;
        case 19: lookfor((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 20: showrecord((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: createTable(); break;
        case 22: createIndex(); break;
        case 23: compact(); break;
        case 24: deleteTable(); break;
        case 25: editTable(); break;
        case 26: deleteIndex(); break;
        case 27: copy(); break;
        case 28: paste(); break;
        case 29: helpWhatsThis(); break;
        case 30: helpAbout(); break;
        case 31: updateRecordText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 32: logWinAway(); break;
        case 33: editWinAway(); break;
        case 34: editText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 35: doubleClickTable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QPoint(*)>(_a[4]))); break;
        case 36: executeQuery(); break;
        case 37: mainTabSelected((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: toggleLogWindow((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: importTableFromCSV(); break;
        case 40: exportTableToCSV(); break;
        case 41: dbState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 42: fileSave(); break;
        case 43: fileRevert(); break;
        case 44: exportDatabaseToSQL(); break;
        case 45: importDatabaseFromSQL(); break;
        case 46: openPreferences(); break;
        case 47: updatePreferences(); break;
        case 48: languageChange(); break;
        default: ;
        }
        _id -= 49;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
