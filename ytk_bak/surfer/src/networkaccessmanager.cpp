#include "networkaccessmanager.h"
#include "networkcookiejar.h"
#include "networkdiskcache.h"

NetworkAccessManager * NetworkAccessManager::m_networkAccessManager = 0;

NetworkAccessManager::NetworkAccessManager()
{
    m_cookieJar = new NetworkCookieJar(this);
    setCookieJar(m_cookieJar);
    m_diskCache = new NetworkDiskCache(this);
    setCache(m_diskCache);
}

NetworkAccessManager * NetworkAccessManager::networkAccessManager()
{
    if(!m_networkAccessManager)
    {
        m_networkAccessManager = new NetworkAccessManager();
    }
    return m_networkAccessManager;
}

void NetworkAccessManager::addTrustedDomain(const QUrl & url)
{
    m_trustedDomains += url;
}

void NetworkAccessManager::addTempTrustedDomain(const QUrl & url)
{
    m_tempTrustedDomains += url;
}

bool NetworkAccessManager::isTrustedDomain(const QUrl & url) const
{
    for(int i = 0; i < m_trustedDomains.count(); i++)
    {
        if(m_trustedDomains.at(i) == url)
        {
            return true;
        }
    }
    for(int i = 0; i < m_tempTrustedDomains.count(); i++)
    {
        if(m_tempTrustedDomains.at(i) == url)
        {
            return true;
        }
    }
    return false;
}

void NetworkAccessManager::addTempRejectedDomain(const QUrl & url)
{
    m_tempRejectedDomains += url;
}

bool NetworkAccessManager::isRejectedDomain(const QUrl & url) const
{
    for(int i = 0; i < m_tempRejectedDomains.count(); i++)
    {
        if(m_tempRejectedDomains.at(i) == url)
        {
            return true;
        }
    }
    return false;
}

void NetworkAccessManager::load()
{
    m_cookieJar->load();
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "trustedDomains");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QByteArray array;
    while(!(array = file.readLine()).isEmpty())
    {
        QString urlString = QString::fromUtf8(array.data()).trimmed();
        addTrustedDomain(QUrl(urlString));
    }
    file.close();

	//YEW
	QNetworkProxy proxy;
	proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("10.39.100.2");
    proxy.setPort(8080);
	this->setProxy(proxy);

}

void NetworkAccessManager::save()
{
    m_cookieJar->save();
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "trustedDomains");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QByteArray array;
    for(int i = 0; i < m_trustedDomains.count(); i++)
    {
        array += m_trustedDomains.at(i).toString().toUtf8();
        array += "\n";
    }
    file.write(array);
    file.close();
}
