/****************************************************************************
** Meta object code from reading C++ file 'webview.h'
**
** Created: Sun Jan 3 14:58:20 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/webview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,    9,    8,    8, 0x0a,
      32,   24,    8,    8, 0x0a,
      72,   45,    8,    8, 0x0a,
      96,    8,    8,    8, 0x08,
     112,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebView[] = {
    "WebView\0\0url\0load(QUrl)\0percent\0"
    "setZoom(int)\0text,forward,caseSensitive\0"
    "find(QString,bool,bool)\0updateHistory()\0"
    "copySelectedText()\0"
};

const QMetaObject WebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_WebView,
      qt_meta_data_WebView, 0 }
};

const QMetaObject *WebView::metaObject() const
{
    return &staticMetaObject;
}

void *WebView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebView))
        return static_cast<void*>(const_cast< WebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int WebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: load((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 1: setZoom((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: find((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: updateHistory(); break;
        case 4: copySelectedText(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
