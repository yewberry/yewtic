#include "bookmarksmanager.h"
#include "bookmarksitem.h"

BookmarksManager * BookmarksManager::m_bookmarksManager = 0;

BookmarksManager::BookmarksManager()
{
    m_rootFolderItem = new BookmarksItem(trUtf8("Bookmarks"), QUrl(), this);
}

BookmarksManager * BookmarksManager::bookmarksManager()
{
    if(!m_bookmarksManager)
    {
        m_bookmarksManager = new BookmarksManager();
    }
    return m_bookmarksManager;
}

int BookmarksManager::count() const
{
    return m_rootFolderItem->childrenCount();
}

BookmarksItem * BookmarksManager::item(int index) const
{
    return m_rootFolderItem->child(index);
}

BookmarksItem * BookmarksManager::item(const QList<QVariant> & indexes) const
{
    BookmarksItem * item = m_rootFolderItem;
    for(int i = 0; i < indexes.count(); i++)
    {
        item = item->child(indexes.at(i).toInt());
    }
    return item;
}

QModelIndex BookmarksManager::index(BookmarksItem * item) const
{
    QModelIndex index = this->index(0, 0, QModelIndex());
    QList<QVariant> indexes;
    while(item != m_rootFolderItem && item)
    {
        int i = item->index();
        if(i == -1)
        {
            return QModelIndex();
        }
        indexes.prepend(i);
        item = qobject_cast<BookmarksItem *>(item->parent());
    }
    for(int i = 0; i < indexes.count(); i++)
    {
        index = this->index(indexes.at(i).toInt(), 0, index);
    }
    return index;
}

QList<QVariant> BookmarksManager::indexes(const QModelIndex & index) const
{
    QList<QVariant> indexes;
    BookmarksItem * item = static_cast<BookmarksItem *>(index.internalPointer());
    while(item != m_rootFolderItem && item)
    {
        int i = item->index();
        if(i == -1)
        {
            return QList<QVariant>();
        }
        indexes.prepend(i);
        item = qobject_cast<BookmarksItem *>(item->parent());
    }
    return indexes;
}

BookmarksItem * BookmarksManager::addItem(QString title, QUrl url,
                                          const QList<QVariant> & parentIndexes)
{
    BookmarksItem * item = new BookmarksItem(title, url);
    BookmarksItem * parent = this->item(parentIndexes);
    QModelIndex parentIndex = index(parent);
    beginInsertRows(parentIndex, rowCount(parentIndex), rowCount(parentIndex));
    parent->addChild(item);
    endInsertRows();
    return item;
}

BookmarksItem * BookmarksManager::insertItem(int index, QString title, QUrl url,
                                             const QList<QVariant> & parentIndexes)
{
    BookmarksItem * item = new BookmarksItem(title, url);
    BookmarksItem * parent = this->item(parentIndexes);
    QModelIndex parentIndex = this->index(parent);
    if(index < 0)
    {
        index = 0;
    }
    if(index > rowCount(parentIndex))
    {
        index = rowCount(parentIndex);
    }
    beginInsertRows(parentIndex, index, index);
    parent->insertChild(index, item);
    endInsertRows();
    return item;
}

void BookmarksManager::removeItem(const QList<QVariant> & indexes)
{
    BookmarksItem * item = this->item(indexes);
    if(item != m_rootFolderItem)
    {
        BookmarksItem * parent = qobject_cast<BookmarksItem *>(item->parent());
        beginRemoveRows(index(parent), indexes.last().toInt(), indexes.last().toInt());
        parent->removeChild(indexes.last().toInt());
        endRemoveRows();
    }
}

QModelIndex BookmarksManager::index(int row, int column, const QModelIndex & parent) const
{
    BookmarksItem * item = 0;
    if(parent.isValid())
    {
        item = static_cast<BookmarksItem *>(parent.internalPointer())->child(row);
    }
    else if(!row)
    {
        item = m_rootFolderItem;
    }
    if(!item || column > 1)
    {
        return QModelIndex();
    }
    else
    {
        return createIndex(row, column, item);
    }
}

QModelIndex BookmarksManager::parent(const QModelIndex & index) const
{
    if(!index.isValid())
    {
        return QModelIndex();
    }
    else
    {
        BookmarksItem * item = static_cast<BookmarksItem *>(index.internalPointer());
        BookmarksItem * parent = qobject_cast<BookmarksItem *>(item->parent());
        if(parent)
        {
            int i = parent->index();
            if(i != -1)
            {
                return createIndex(i, 0, parent);
            }
            else if(parent == m_rootFolderItem)
            {
                return createIndex(0, 0, parent);
            }
        }
        return QModelIndex();
    }
}

int BookmarksManager::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

int BookmarksManager::rowCount(const QModelIndex & parent) const
{
    if(parent.column() > 0)
    {
        return 0;
    }
    else if(parent.isValid())
    {
        BookmarksItem * item = static_cast<BookmarksItem *>(parent.internalPointer());
        return item->childrenCount();
    }
    else
    {
        return 1;
    }
}

QVariant BookmarksManager::data(const QModelIndex & index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    BookmarksItem * item = static_cast<BookmarksItem *>(index.internalPointer());
    if(role == Qt::DecorationRole && index.column() == 0)
    {
        QUrl url = item->url();
        if(url != QUrl())
        {
            QIcon icon = QWebSettings::iconForUrl(url);
            if(icon.isNull())
            {
                icon = QIcon(":/defaultPageIcon.png");
            }
            return icon;
        }
        else if(item != m_rootFolderItem)
        {
            return QIcon(":/folder.png");
        }
        else
        {
            return QIcon(":/folder-bookmark.png");
        }
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

QVariant BookmarksManager::headerData(int section, Qt::Orientation orientation, int role) const
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

Qt::DropActions BookmarksManager::supportedDropActions() const
{
    return Qt::MoveAction;
}

Qt::ItemFlags BookmarksManager::flags(const QModelIndex & index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
    if(!index.isValid())
    {
        return flags;
    }
    BookmarksItem * item = static_cast<BookmarksItem *>(index.internalPointer());
    if(item->url() == QUrl())
    {
        return flags | Qt::ItemIsDropEnabled;
    }
    else
    {
        return flags | Qt::ItemIsDragEnabled;
    }
}

QStringList BookmarksManager::mimeTypes() const
{
    QStringList types;
    types += "text/plain";
    return types;
}

QMimeData * BookmarksManager::mimeData(const QModelIndexList & indexes) const
{
    QMimeData * mimeData = new QMimeData();
    QString text;
    foreach(QModelIndex index, indexes)
    {
        if(index.isValid() && !index.column())
        {
            QList<QVariant> indexList = this->indexes(index);
            foreach(QVariant ind, indexList)
            {
                text += QString::number(ind.toInt());
                text += ";";
            }
            text += "\n";
        }
    }
    mimeData->setText(text);
    return mimeData;
}

bool BookmarksManager::dropMimeData(const QMimeData * data, Qt::DropAction action,
                                    int row, int /*column*/, const QModelIndex & parent)
{
    if(action == Qt::IgnoreAction)
    {
        return true;
    }
    else if(!data->hasText())
    {
        return false;
    }
    else
    {
        QList<QVariant> parentIndexes = indexes(parent);
        QStringList indexesStrings = data->text().split("\n", QString::SkipEmptyParts);
        foreach(QString indexesString, indexesStrings)
        {
            QStringList indexStrings = indexesString.split(";", QString::SkipEmptyParts);
            QList<QVariant> indexes;
            foreach(QString index, indexStrings)
            {
                indexes += QVariant(index.toInt());
            }
            BookmarksItem * item = this->item(indexes);
            if(row != -1)
            {
                insertItem(row, item->title(), item->url(), parentIndexes);
                row++;
            }
            else
            {
                addItem(item->title(), item->url(), parentIndexes);
            }
        }
        return true;
    }
}

bool BookmarksManager::removeRows(int row, int count, const QModelIndex & parent)
{
    QList<QVariant> parentIndexes = indexes(parent);
    parentIndexes += row;
    for(int i = 0; i < count; i++)
    {
        removeItem(parentIndexes);
    }
    return true;
}

bool BookmarksManager::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if(!index.parent().isValid())
    {
        return false;
    }
    BookmarksItem * item = static_cast<BookmarksItem *>(index.internalPointer());
    if(role == Qt::DisplayRole && index.column() == 0)
    {
        item->setTitle(value.toString());
        emit dataChanged(index, index);
        return true;
    }
    else if(role == Qt::DisplayRole && index.column() == 1 && item->url() != QUrl())
    {
        item->setUrl(QUrl(value.toString()));
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

void BookmarksManager::loadBookmark(QXmlStreamReader & xml, const QList<QVariant> & parentIndexes)
{
    QUrl url(xml.attributes().value("href").toString());
    QString title;
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isEndElement())
        {
            break;
        }
        if(xml.isStartElement())
        {
            if(xml.name() == "title")
            {
                title = xml.readElementText();
            }
        }
    }
    addItem(title, url, parentIndexes);
}

void BookmarksManager::loadFolder(QXmlStreamReader & xml, const QList<QVariant> & parentIndexes)
{
    BookmarksItem * item = addItem(QString(), QUrl(), parentIndexes);
    QList<QVariant> newParentIndexes = parentIndexes;
    newParentIndexes += item->index();
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isEndElement())
        {
            break;
        }
        if(xml.isStartElement())
        {
            if(xml.name() == "title")
            {
                item->setTitle(xml.readElementText());
            }
            else if(xml.name() == "folder")
            {
                loadFolder(xml, newParentIndexes);
            }
            else if(xml.name() == "bookmark")
            {
                loadBookmark(xml, newParentIndexes);
            }
        }
    }
}

void BookmarksManager::saveItem(QXmlStreamWriter & xml, BookmarksItem * item)
{
    if(item->url() == QUrl())
    {
        xml.writeStartElement("folder");
        xml.writeTextElement("title", item->title());
        for(int i = 0; i < item->childrenCount(); i++)
        {
            saveItem(xml, item->child(i));
        }
        xml.writeEndElement();
    }
    else
    {
        xml.writeStartElement("bookmark");
        xml.writeAttribute("href", item->url().toString());
        xml.writeTextElement("title", item->title());
        xml.writeEndElement();
    }
}

void BookmarksManager::load()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "bookmarks");
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    QXmlStreamReader xml(&file);
    while(!xml.atEnd())
    {
        xml.readNext();
        if(xml.isStartElement() && xml.name() == "xbel" &&
           xml.attributes().value("version") == "1.0")
        {
            while(!xml.atEnd())
            {
                xml.readNext();
                if(xml.isEndElement())
                {
                    break;
                }
                if(xml.isStartElement())
                {
                    if(xml.name() == "folder")
                    {
                        loadFolder(xml);
                    }
                    else if(xml.name() == "bookmark")
                    {
                        loadBookmark(xml);
                    }
                }
            }
        }
    }
    file.close();
}

void BookmarksManager::save()
{
    QString path = QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/";
    QDir dir;
    if(!dir.mkpath(path))
    {
        return;
    }
    QFile file(path + "bookmarks");
    if(!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QXmlStreamWriter xml(&file);
    xml.setAutoFormatting(true);
    xml.writeStartDocument();
    xml.writeStartElement("xbel");
    xml.writeAttribute("version", "1.0");
    for(int i = 0; i < count(); i++)
    {
        BookmarksItem * item = this->item(i);
        saveItem(xml, item);
    }
    xml.writeEndDocument();
    file.close();
}
