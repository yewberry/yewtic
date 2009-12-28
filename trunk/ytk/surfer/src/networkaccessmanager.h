#ifndef NETWORKACCESSMANAGER_H
#define NETWORKACCESSMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class NetworkCookieJar;
class NetworkDiskCache;

class NetworkAccessManager
        : public QNetworkAccessManager
{
    Q_OBJECT

public:
    NetworkAccessManager();
    static NetworkAccessManager * networkAccessManager();
    void addTrustedDomain(const QUrl & url);
    void addTempTrustedDomain(const QUrl & url);
    bool isTrustedDomain(const QUrl & url) const;
    void addTempRejectedDomain(const QUrl & url);
    bool isRejectedDomain(const QUrl & url) const;

private:
    static NetworkAccessManager * m_networkAccessManager;
    NetworkCookieJar * m_cookieJar;
    NetworkDiskCache * m_diskCache;
    QList<QUrl> m_trustedDomains;
    QList<QUrl> m_tempTrustedDomains;
    QList<QUrl> m_tempRejectedDomains;

public slots:
    void load();
    void save();

private slots:
};

#endif // NETWORKACCESSMANAGER_H
