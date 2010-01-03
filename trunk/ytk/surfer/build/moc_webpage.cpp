/****************************************************************************
** Meta object code from reading C++ file 'webpage.h'
**
** Created: Sun Jan 3 14:58:20 2010
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/webpage.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'webpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WebPage[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,    9,    8,    8, 0x08,
      64,   56,    8,    8, 0x08,
      90,    8,    8,    8, 0x08,
     126,  106,    8,    8, 0x08,
     191,  171,    8,    8, 0x08,
     248,  235,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WebPage[] = {
    "WebPage\0\0reply\0handleUnsupportedContent(QNetworkReply*)\0"
    "request\0download(QNetworkRequest)\0"
    "handleHeaders()\0reply,authenticator\0"
    "authenticate(QNetworkReply*,QAuthenticator*)\0"
    "proxy,authenticator\0"
    "authenticate(QNetworkProxy,QAuthenticator*)\0"
    "reply,errors\0"
    "handleSslErrors(QNetworkReply*,QList<QSslError>)\0"
};

const QMetaObject WebPage::staticMetaObject = {
    { &QWebPage::staticMetaObject, qt_meta_stringdata_WebPage,
      qt_meta_data_WebPage, 0 }
};

const QMetaObject *WebPage::metaObject() const
{
    return &staticMetaObject;
}

void *WebPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WebPage))
        return static_cast<void*>(const_cast< WebPage*>(this));
    return QWebPage::qt_metacast(_clname);
}

int WebPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleUnsupportedContent((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: download((*reinterpret_cast< const QNetworkRequest(*)>(_a[1]))); break;
        case 2: handleHeaders(); break;
        case 3: authenticate((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 4: authenticate((*reinterpret_cast< const QNetworkProxy(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 5: handleSslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
