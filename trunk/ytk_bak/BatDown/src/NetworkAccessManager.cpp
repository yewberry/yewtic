#include "NetworkAccessManager.h"
#include "NetworkCookieJar.h"

NetworkAccessManager * NetworkAccessManager::m_pNetworkAccessManager = 0;

NetworkAccessManager::NetworkAccessManager(QObject * parent)
: QNetworkAccessManager(parent)
{
    m_pCookieJar = new NetworkCookieJar(this);
    setCookieJar(m_pCookieJar);
}

NetworkAccessManager * NetworkAccessManager::networkAccessManager()
{
    if(!m_pNetworkAccessManager){
        m_pNetworkAccessManager = new NetworkAccessManager();
    }
    return m_pNetworkAccessManager;
}

void NetworkAccessManager::load()
{
    m_pCookieJar->load();
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";

	/*
	QNetworkProxy proxy;
	proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("10.39.100.2");
    proxy.setPort(8080);
	this->setProxy(proxy);
	*/
}

void NetworkAccessManager::save()
{
    m_pCookieJar->save();
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
}
