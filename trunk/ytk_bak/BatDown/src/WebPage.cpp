#include "WebPage.h"
#include "NetworkAccessManager.h"

WebPage::WebPage(QObject *parent)
        : QWebPage(parent)
{
    NetworkAccessManager *manager = NetworkAccessManager::networkAccessManager();
    setNetworkAccessManager(manager);
}