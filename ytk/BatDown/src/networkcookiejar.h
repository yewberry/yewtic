#ifndef NETWORKCOOKIEJAR_H
#define NETWORKCOOKIEJAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class NetworkCookieJar : public QNetworkCookieJar
{
    Q_OBJECT

public:
    NetworkCookieJar(QObject * parent = 0);

public slots:
    void load();
    void save();
};

#endif // NETWORKCOOKIEJAR_H
