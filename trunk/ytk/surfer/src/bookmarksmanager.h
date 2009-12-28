#ifndef BOOKMARKSMANAGER_H
#define BOOKMARKSMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksItem;

class BookmarksManager
        : public QAbstractItemModel
{
    Q_OBJECT

public:
    BookmarksManager();
    static BookmarksManager * bookmarksManager();
    int count() const;
    BookmarksItem * item(int index) const;
    BookmarksItem * item(const QList<QVariant> & indexes) const;
    QModelIndex index(BookmarksItem * item) const;
    QList<QVariant> indexes(const QModelIndex & index) const;
    BookmarksItem * addItem(QString title, QUrl url, const QList<QVariant> & parentIndexes);
    BookmarksItem * insertItem(int index, QString title, QUrl url,
                               const QList<QVariant> & parentIndexes);
    void removeItem(const QList<QVariant> & indexes);
    QModelIndex index(int row, int column, const QModelIndex & parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex & index) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    QStringList mimeTypes() const;
    QMimeData * mimeData(const QModelIndexList & indexes) const;
    bool dropMimeData(const QMimeData * data, Qt::DropAction action,
                      int row, int column, const QModelIndex & parent);
    bool removeRows(int row, int count, const QModelIndex & parent);
    bool setData(const QModelIndex & index, const QVariant & value, int role);

private:
    static BookmarksManager * m_bookmarksManager;
    BookmarksItem * m_rootFolderItem;
    void loadBookmark(QXmlStreamReader & xml,
                      const QList<QVariant> & parentIndexes = QList<QVariant>());
    void loadFolder(QXmlStreamReader & xml,
                    const QList<QVariant> & parentIndexes = QList<QVariant>());
    void saveItem(QXmlStreamWriter & xml, BookmarksItem * item);

public slots:
    void load();
    void save();
};

#endif // BOOKMARKSMANAGER_H
