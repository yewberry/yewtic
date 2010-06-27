#include "NetworkCookieJar.h"

NetworkCookieJar::NetworkCookieJar(QObject * parent)
        : QNetworkCookieJar(parent)
{
}

void NetworkCookieJar::load()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "cookies");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QList<QNetworkCookie> cookies;
    QByteArray cookie;
    while(!(cookie = file.readLine()).isEmpty())
    {
        cookies += QNetworkCookie::parseCookies(cookie);
    }
    file.close();
    setAllCookies(cookies);
}

void NetworkCookieJar::save()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "cookies");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QByteArray cookiesData;
    QList<QNetworkCookie> cookies = allCookies();
    foreach(QNetworkCookie cookie, cookies)
    {
        cookiesData += cookie.toRawForm(QNetworkCookie::Full);
        cookiesData += "\n";
    }
    file.write(cookiesData);
    file.close();
}
