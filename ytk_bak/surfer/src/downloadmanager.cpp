#include "downloadmanager.h"
#include "networkaccessmanager.h"
#include "downloaditem.h"

DownloadManager * DownloadManager::m_downloadManager = 0;

DownloadManager::DownloadManager()
{
}

DownloadManager * DownloadManager::downloadManager()
{
    if(!m_downloadManager)
    {
        m_downloadManager = new DownloadManager();
    }
    return m_downloadManager;
}

DownloadItem * DownloadManager::item(int index) const
{
    return m_items.value(index);
}

int DownloadManager::count() const
{
    return m_items.count();
}

DownloadItem * DownloadManager::download(const QUrl & from, const QUrl & to)
{
    NetworkAccessManager * manager = NetworkAccessManager::networkAccessManager();
    DownloadItem * item = new DownloadItem(manager->get(QNetworkRequest(from)), to, this);
    beginInsertRows(QModelIndex(), 0, 0);
    m_items.prepend(item);
    endInsertRows();
    emit newItem();
    return item;
}

QString DownloadManager::sizeString(qint64 bytes)
{
    if(bytes >= 1024 * 1024 * 1024)
    {
        return QString::number((double) bytes / (1024 * 1024 * 1024), 'f', 1) + " " + trUtf8("Gb");
    }
    else if(bytes >= 1024 * 1024)
    {
        return QString::number((double) bytes / (1024 * 1024), 'f', 1) + " " + trUtf8("Mb");
    }
    else if(bytes >= 1024)
    {
        return QString::number((double) bytes / 1024, 'f', 1) + " " + trUtf8("Kb");
    }
    else
    {
        return QString::number(bytes) + " " + trUtf8("b");
    }
}

int DownloadManager::rowCount(const QModelIndex & /*parent*/) const
{
    return count();
}

QVariant DownloadManager::data(const QModelIndex & /*index*/, int /*role*/) const
{
    return QVariant();
}

void DownloadManager::clearFinished()
{
    for(int i = count() - 1; i >= 0; i--)
    {
        DownloadItem * item = m_items.at(i);
        if(item->isFinished())
        {
            beginRemoveRows(QModelIndex(), i, i);
            item->deleteLater();
            m_items.removeAt(i);
            endRemoveRows();
            emit itemDeleted(i);
        }
    }
}

void DownloadManager::load()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "downloads");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QByteArray array;
    while(!(array = file.readLine()).isEmpty())
    {
        QString fromString = QString::fromUtf8(array.data()).trimmed();
        array = file.readLine();
        QString toString = QString::fromUtf8(array.data()).trimmed();
        download(QUrl(fromString), QUrl(toString));
    }
    file.close();
}

void DownloadManager::save()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "downloads");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QByteArray array;
    for(int i = count() - 1; i >= 0; i--)
    {
        DownloadItem * item = m_items.at(i);
        if(!item->isFinished())
        {
            array += item->from().toString().toUtf8();
            array += "\n";
            array += item->to().toString().toUtf8();
            array += "\n";
        }
    }
    file.write(array);
    file.close();
}
