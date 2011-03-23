/****************************************************************************
** Meta object code from reading C++ file 'ReportView.h'
**
** Created: Wed Mar 23 18:02:08 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/ReportView.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReportView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ReportView[] = {

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

static const char qt_meta_stringdata_ReportView[] = {
    "ReportView\0"
};

const QMetaObject ReportView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ReportView,
      qt_meta_data_ReportView, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReportView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReportView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReportView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReportView))
        return static_cast<void*>(const_cast< ReportView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ReportView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_ReportListWidget[] = {

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

static const char qt_meta_stringdata_ReportListWidget[] = {
    "ReportListWidget\0"
};

const QMetaObject ReportListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_ReportListWidget,
      qt_meta_data_ReportListWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ReportListWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ReportListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ReportListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ReportListWidget))
        return static_cast<void*>(const_cast< ReportListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int ReportListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
