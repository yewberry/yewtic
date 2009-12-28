#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryItem;
class SettingsManager;

class HistoryManager
        : public QAbstractListModel
{
    Q_OBJECT

public:
    HistoryManager();
    static HistoryManager * historyManager();
    HistoryItem * addItem(const QUrl & url, const QString & title);
    HistoryItem * addItem(const QUrl & url, const QString & title, const QDateTime & visitTime);
    HistoryItem * item(int index) const;
    int count() const;
    void removeItem(int index);
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    static HistoryManager * m_historyManager;
    QList<HistoryItem *> m_items;

public slots:
    void clear();
    void load();
    void save();
};

#endif // HISTORYMANAGER_H
