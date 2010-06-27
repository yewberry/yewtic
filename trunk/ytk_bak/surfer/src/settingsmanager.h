#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class SettingsManager
        : public QObject
{
    Q_OBJECT

public:
    SettingsManager();
    static SettingsManager * settingsManager();
    bool isImagesEnabled() const;
    void setImagesEnabled(bool enabled);
    bool isJavascriptEnabled() const;
    void setJavascriptEnabled(bool enabled);
    bool isJavaEnabled() const;
    void setJavaEnabled(bool enabled);
    bool isPluginsEnabled() const;
    void setPluginsEnabled(bool enabled);
    bool isPrivateBrowsingEnabled() const;
    void setPrivateBrowsingEnabled(bool enabled);
    QRect mainWindowGeometry() const;
    void setMainWindowGeometry(QRect geometry);
    QRect historyDialogGeometry() const;
    void setHistoryDialogGeometry(QRect geometry);
    QRect bookmarksDialogGeometry() const;
    void setBookmarksDialogGeometry(QRect geometry);
    QRect settingsDialogGeometry() const;
    void setSettingsDialogGeometry(QRect geometry);
    QRect downloadDialogGeometry() const;
    void setDownloadDialogGeometry(QRect geometry);
    qint64 maximumCacheSize() const;
    void setMaximumCacheSize(qint64 size);
    int historyExpirationDays() const;
    void setHistoryExpirationDays(int days);
    QString downloadPath() const;
    void setDownloadPath(QString path);
    QString sansFontFamily() const;
    void setSansFontFamily(QString fontFamily);
    QString serifFontFamily() const;
    void setSerifFontFamily(QString fontFamily);
    QString monoFontFamily() const;
    void setMonoFontFamily(QString fontFamily);
    int standardFontSize() const;
    void setStandardFontSize(int fontSize);
    int monoFontSize() const;
    void setMonoFontSize(int fontSize);

private:
    static SettingsManager * m_settingsManager;
    QRect m_mainWindowGeometry;
    QRect m_historyDialogGeometry;
    QRect m_bookmarksDialogGeometry;
    QRect m_settingsDialogGeometry;
    QRect m_downloadDialogGeometry;
    qint64 m_maximumCacheSize;
    int m_historyExpirationDays;
    QString m_downloadPath;

public slots:
    void reset();
    void load();
    void save();
};

#endif // SETTINGSMANAGER_H
