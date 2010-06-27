#ifndef BOOKMARKSFOLDERMODEL_H
#define BOOKMARKSFOLDERMODEL_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksManager;

class BookmarksFolderModel
        : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    BookmarksFolderModel(QObject * parent = 0);

protected:
    bool filterAcceptsColumn(int source_column, const QModelIndex & source_parent) const;
    bool filterAcceptsRow(int source_row, const QModelIndex & source_parent) const;
};

#endif // BOOKMARKSFOLDERMODEL_H
