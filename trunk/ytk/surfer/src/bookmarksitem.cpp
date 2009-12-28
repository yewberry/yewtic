#include "bookmarksitem.h"
#include "bookmarksmanager.h"

BookmarksItem::BookmarksItem(const QString & title, const QUrl & url, QObject * parent)
        : QObject(parent)
        , m_title(title)
        , m_url(url)
{
}

QString BookmarksItem::title() const
{
    return m_title;
}

void BookmarksItem::setTitle(const QString & title)
{
    m_title = title;
}

QUrl BookmarksItem::url() const
{
    return m_url;
}

void BookmarksItem::setUrl(const QUrl & url)
{
    m_url = url;
}

int BookmarksItem::childrenCount()
{
    return m_children.count();
}

BookmarksItem * BookmarksItem::child(int index)
{
    return m_children.value(index);
}

int BookmarksItem::index()
{
    BookmarksItem * item = qobject_cast<BookmarksItem *>(parent());
    if(item)
    {
        for(int i = 0; i < item->childrenCount(); i++)
        {
            if(item->child(i) == this)
            {
                return i;
            }
        }
    }
    return -1;
}

void BookmarksItem::addChild(BookmarksItem * child)
{
    insertChild(childrenCount(), child);
}

void BookmarksItem::insertChild(int index, BookmarksItem * child)
{
    child->setParent(this);
    if(index < 0)
    {
        index = 0;
    }
    if(index > childrenCount())
    {
        index = childrenCount();
    }
    m_children.insert(index, child);
}

void BookmarksItem::removeChild(int index)
{
    if(index >= 0 && index < childrenCount())
    {
        m_children.at(index)->deleteLater();
        m_children.removeAt(index);
    }
}
