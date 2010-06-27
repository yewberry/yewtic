#include "networkdiskcache.h"
#include "settingsmanager.h"

NetworkDiskCache::NetworkDiskCache(QObject * parent)
        : QNetworkDiskCache(parent)
{
    QString path =
            QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/cache";
    setCacheDirectory(path);

    setMaximumCacheSize(SettingsManager::settingsManager()->maximumCacheSize());
}
