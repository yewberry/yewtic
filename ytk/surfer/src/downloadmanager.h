#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class NetworkAccessManager;
class DownloadItem;

class DownloadManager
        : public QAbstractListModel
{
    Q_OBJECT

public:
    DownloadManager();
    static DownloadManager * downloadManager();
    DownloadItem * item(int index) const;
    int count() const;
    DownloadItem * download(const QUrl & from, const QUrl & to);
    static QString sizeString(qint64 bytes);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    static DownloadManager * m_downloadManager;
    QList<DownloadItem *> m_items;

public slots:
    void clearFinished();
    void load();
    void save();

signals:
    void newItem();
    void itemDeleted(int index);
};

#endif // DOWNLOADMANAGER_H
