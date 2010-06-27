#include "historymanager.h"
#include "historyitem.h"
#include "settingsmanager.h"

HistoryManager * HistoryManager::m_historyManager = 0;

HistoryManager::HistoryManager()
{
}

HistoryManager * HistoryManager::historyManager()
{
    if(!m_historyManager)
    {
        m_historyManager = new HistoryManager();
    }
    return m_historyManager;
}

HistoryItem * HistoryManager::addItem(const QUrl & url, const QString & title)
{
    return addItem(url, title, QDateTime::currentDateTime());
}

HistoryItem * HistoryManager::addItem(const QUrl & url, const QString & title, const QDateTime & visitTime)
{
    HistoryItem * oldItem;
    int index;
    for(index = 0; index < count(); index++)
    {
        oldItem = m_items.at(index);
        if(oldItem->url() == url)
        {
            break;
        }
    }
    int counter = 1;
    if(index < count())
    {
        counter = oldItem->counter() + 1;
        removeItem(index);
    }
    HistoryItem * item = new HistoryItem(url, title, visitTime, counter, this);
    beginInsertRows(QModelIndex(), 0, 0);
    m_items.prepend(item);
    endInsertRows();
    return item;
}

HistoryItem * HistoryManager::item(int index) const
{
    return m_items.value(index);
}

int HistoryManager::count() const
{
    return m_items.count();
}

void HistoryManager::removeItem(int index)
{
    if(index >= 0 && index < count())
    {
        beginRemoveRows(QModelIndex(), index, index);
        m_items.at(index)->deleteLater();
        m_items.removeAt(index);
        endRemoveRows();
    }
}

int HistoryManager::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

int HistoryManager::rowCount(const QModelIndex & /*parent*/) const
{
    return count();
}

QVariant HistoryManager::data(const QModelIndex & index, int role) const
{
    HistoryItem * item = this->item(index.row());
    if(!index.isValid() || index.column() >= 2 || index.row() >= count())
    {
        return QVariant();
    }
    else if(role == Qt::EditRole && index.column() == 0)
    {
        return item->url().toString();
    }
    else if(role == Qt::DecorationRole && index.column() == 0)
    {
        QIcon icon = QWebSettings::iconForUrl(item->url());
        if(icon.isNull())
        {
            icon = QIcon(":/defaultPageIcon.png");
        }
        return icon;
    }
    else if(role == Qt::DisplayRole && index.column() == 0)
    {
        return item->title();
    }
    else if(role == Qt::DisplayRole && index.column() == 1)
    {
        return item->url().toString();
    }
    else
    {
        return QVariant();
    }
}

QVariant HistoryManager::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if(section == 0)
        {
            return trUtf8("Title");
        }
        else if(section == 1)
        {
            return trUtf8("Address");
        }
        else
        {
            return QVariant();
        }
    }
    else
    {
        return QVariant();
    }
}

void HistoryManager::clear()
{
    beginRemoveRows(QModelIndex(), 0, count() - 1);
    foreach(HistoryItem * item, m_items)
    {
        item->deleteLater();
    }
    m_items.clear();
    endRemoveRows();
}

void HistoryManager::load()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "history");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QByteArray array;
    while(!(array = file.readLine()).isEmpty())
    {
        QString title = QString::fromUtf8(array.data()).trimmed();
        array = file.readLine();
        QString urlString = QString::fromUtf8(array.data()).trimmed();
        array = file.readLine();
        QString dateString = QString::fromUtf8(array.data()).trimmed();
        QDateTime date = QDateTime::fromString(dateString, "dd.MM.yyyy hh:mm");
        int days = SettingsManager::settingsManager()->historyExpirationDays();
        if(date.daysTo(QDateTime::currentDateTime()) < days)
        {
            addItem(QUrl(urlString), title, date);
        }
    }
    file.close();
}

void HistoryManager::save()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "history");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QByteArray array;
    for(int i = count() - 1; i >= 0; i--)
    {
        HistoryItem * item = m_items.at(i);
        array += item->title().toUtf8();
        array += "\n";
        array += item->url().toString().toUtf8();
        array += "\n";
        array += item->visitTime().toString("dd.MM.yyyy hh:mm").toUtf8();
        array += "\n";
    }
    file.write(array);
    file.close();
}
