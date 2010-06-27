#include "settingsmanager.h"

SettingsManager * SettingsManager::m_settingsManager = 0;

SettingsManager::SettingsManager()
{
}

SettingsManager * SettingsManager::settingsManager()
{
    if(!m_settingsManager)
    {
        m_settingsManager = new SettingsManager();
    }
    return m_settingsManager;
}

bool SettingsManager::isImagesEnabled() const
{
    return QWebSettings::globalSettings()->testAttribute(QWebSettings::AutoLoadImages);
}

void SettingsManager::setImagesEnabled(bool enabled)
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::AutoLoadImages, enabled);
}

bool SettingsManager::isJavascriptEnabled() const
{
    return QWebSettings::globalSettings()->testAttribute(QWebSettings::JavascriptEnabled);
}

void SettingsManager::setJavascriptEnabled(bool enabled)
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavascriptEnabled, enabled);
}

bool SettingsManager::isJavaEnabled() const
{
    return QWebSettings::globalSettings()->testAttribute(QWebSettings::JavaEnabled);
}

void SettingsManager::setJavaEnabled(bool enabled)
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::JavaEnabled, enabled);
}

bool SettingsManager::isPluginsEnabled() const
{
    return QWebSettings::globalSettings()->testAttribute(QWebSettings::PluginsEnabled);
}

void SettingsManager::setPluginsEnabled(bool enabled)
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PluginsEnabled, enabled);
}

bool SettingsManager::isPrivateBrowsingEnabled() const
{
    return QWebSettings::globalSettings()->testAttribute(QWebSettings::PrivateBrowsingEnabled);
}

void SettingsManager::setPrivateBrowsingEnabled(bool enabled)
{
    QWebSettings::globalSettings()->setAttribute(QWebSettings::PrivateBrowsingEnabled, enabled);
}

QRect SettingsManager::mainWindowGeometry() const
{
    return m_mainWindowGeometry;
}

void SettingsManager::setMainWindowGeometry(QRect geometry)
{
    m_mainWindowGeometry = geometry;
}

QRect SettingsManager::historyDialogGeometry() const
{
    return m_historyDialogGeometry;
}

void SettingsManager::setHistoryDialogGeometry(QRect geometry)
{
    m_historyDialogGeometry = geometry;
}

QRect SettingsManager::bookmarksDialogGeometry() const
{
    return m_bookmarksDialogGeometry;
}

void SettingsManager::setBookmarksDialogGeometry(QRect geometry)
{
    m_bookmarksDialogGeometry = geometry;
}

QRect SettingsManager::settingsDialogGeometry() const
{
    return m_settingsDialogGeometry;
}

void SettingsManager::setSettingsDialogGeometry(QRect geometry)
{
    m_settingsDialogGeometry = geometry;
}

QRect SettingsManager::downloadDialogGeometry() const
{
    return m_downloadDialogGeometry;
}

void SettingsManager::setDownloadDialogGeometry(QRect geometry)
{
    m_downloadDialogGeometry = geometry;
}

qint64 SettingsManager::maximumCacheSize() const
{
    return m_maximumCacheSize;
}

void SettingsManager::setMaximumCacheSize(qint64 size)
{
    m_maximumCacheSize = size;
}

int SettingsManager::historyExpirationDays() const
{
    return m_historyExpirationDays;
}

void SettingsManager::setHistoryExpirationDays(int days)
{
    m_historyExpirationDays = days;
}

QString SettingsManager::downloadPath() const
{
    return m_downloadPath;
}

void SettingsManager::setDownloadPath(QString path)
{
    m_downloadPath = path;
}

QString SettingsManager::sansFontFamily() const
{
    return QWebSettings::globalSettings()->fontFamily(QWebSettings::StandardFont);
}

void SettingsManager::setSansFontFamily(QString fontFamily)
{
    QWebSettings::globalSettings()->setFontFamily(QWebSettings::StandardFont, fontFamily);
}

QString SettingsManager::serifFontFamily() const
{
    return QWebSettings::globalSettings()->fontFamily(QWebSettings::SerifFont);
}

void SettingsManager::setSerifFontFamily(QString fontFamily)
{
    QWebSettings::globalSettings()->setFontFamily(QWebSettings::SerifFont, fontFamily);
}

QString SettingsManager::monoFontFamily() const
{
    return QWebSettings::globalSettings()->fontFamily(QWebSettings::FixedFont);
}

void SettingsManager::setMonoFontFamily(QString fontFamily)
{
    QWebSettings::globalSettings()->setFontFamily(QWebSettings::FixedFont, fontFamily);
}

int SettingsManager::standardFontSize() const
{
    return QWebSettings::globalSettings()->fontSize(QWebSettings::DefaultFontSize);
}

void SettingsManager::setStandardFontSize(int fontSize)
{
    QWebSettings::globalSettings()->setFontSize(QWebSettings::DefaultFontSize, fontSize);
}

int SettingsManager::monoFontSize() const
{
    return QWebSettings::globalSettings()->fontSize(QWebSettings::DefaultFixedFontSize);
}

void SettingsManager::setMonoFontSize(int fontSize)
{
    QWebSettings::globalSettings()->setFontSize(QWebSettings::DefaultFixedFontSize, fontSize);
}

void SettingsManager::reset()
{
    setImagesEnabled(true);
    setJavascriptEnabled(true);
    setJavaEnabled(true);
    setPluginsEnabled(true);
    setPrivateBrowsingEnabled(false);
    setMaximumCacheSize(50 * 1024 * 1024);
    setHistoryExpirationDays(7);
    setDownloadPath("");
    setStandardFontSize(12);
    setMonoFontSize(12);
}

void SettingsManager::load()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QWebSettings::setIconDatabasePath(path);
    QSettings settings("PayableOnDeath", "Surfer");
    setImagesEnabled(settings.value("webkit/images", true).toBool());
    setJavascriptEnabled(settings.value("webkit/javascript", true).toBool());
    setJavaEnabled(settings.value("webkit/java", true).toBool());
    setPluginsEnabled(settings.value("webkit/plugins", true).toBool());
    setPrivateBrowsingEnabled(settings.value("webkit/private_browsing", false).toBool());
    setMainWindowGeometry(settings.value("geometry/main_window").toRect());
    setHistoryDialogGeometry(settings.value("geometry/history_dialog").toRect());
    setBookmarksDialogGeometry(settings.value("geometry/bookmarks_dialog").toRect());
    setSettingsDialogGeometry(settings.value("geometry/settings_dialog").toRect());
    setDownloadDialogGeometry(settings.value("geometry/download_dialog").toRect());
    setMaximumCacheSize(settings.value("extension/cache/maximum_size", 50 * 1024 * 1024).toLongLong());
    setHistoryExpirationDays(settings.value("extension/history/expiration_days", 7).toInt());
    setDownloadPath(settings.value("extension/download/path", "").toString());
    setSansFontFamily(settings.value("font/sans/family").toString());
    setSerifFontFamily(settings.value("font/serif/family").toString());
    setMonoFontFamily(settings.value("font/mono/family").toString());
    setStandardFontSize(settings.value("font/standard/size", 12).toInt());
    setMonoFontSize(settings.value("font/mono/size", 12).toInt());
}

void SettingsManager::save()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QSettings settings("PayableOnDeath", "Surfer");
    settings.setValue("webkit/images", isImagesEnabled());
    settings.setValue("webkit/javascript", isJavascriptEnabled());
    settings.setValue("webkit/java", isJavaEnabled());
    settings.setValue("webkit/plugins", isPluginsEnabled());
    settings.setValue("webkit/private_browsing", isPrivateBrowsingEnabled());
    settings.setValue("geometry/main_window", mainWindowGeometry());
    settings.setValue("geometry/history_dialog", historyDialogGeometry());
    settings.setValue("geometry/bookmarks_dialog", bookmarksDialogGeometry());
    settings.setValue("geometry/settings_dialog", settingsDialogGeometry());
    settings.setValue("geometry/download_dialog", downloadDialogGeometry());
    settings.setValue("extension/cache/maximum_size", maximumCacheSize());
    settings.setValue("extension/history/expiration_days", historyExpirationDays());
    settings.setValue("extension/download/path", downloadPath());
    settings.setValue("font/sans/family", sansFontFamily());
    settings.setValue("font/serif/family", serifFontFamily());
    settings.setValue("font/mono/family", monoFontFamily());
    settings.setValue("font/standard/size", standardFontSize());
    settings.setValue("font/mono/size", monoFontSize());
}
