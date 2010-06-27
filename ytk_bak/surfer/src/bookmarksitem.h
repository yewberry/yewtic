#ifndef BOOKMARKSITEM_H
#define BOOKMARKSITEM_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksManager;

class BookmarksItem
        : public QObject
{
    Q_OBJECT

public:
    BookmarksItem(const QString & title, const QUrl & url = QUrl(), QObject * parent = 0);
    QString title() const;
    void setTitle(const QString & title);
    QUrl url() const;
    void setUrl(const QUrl & url);
    int childrenCount();
    BookmarksItem * child(int index);
    int index();
    void addChild(BookmarksItem * child);
    void insertChild(int index, BookmarksItem * child);
    void removeChild(int index);

private:
    QString m_title;
    QUrl m_url;
    QList<BookmarksItem *> m_children;
};

#endif // BOOKMARKSITEM_H
