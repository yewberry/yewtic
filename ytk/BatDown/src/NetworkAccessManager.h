#ifndef NETWORKACCESSMANAGER_H
#define NETWORKACCESSMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class NetworkCookieJar;

class NetworkAccessManager: public QNetworkAccessManager
{
    Q_OBJECT

public:
    NetworkAccessManager(QObject *parent = 0);
    static NetworkAccessManager* networkAccessManager();

private:
    static NetworkAccessManager *m_pNetworkAccessManager;
    NetworkCookieJar *m_pCookieJar;

public slots:
    void load();
    void save();

private slots:
};

#endif // NETWORKACCESSMANAGER_H
