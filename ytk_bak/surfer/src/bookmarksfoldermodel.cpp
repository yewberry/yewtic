#include "bookmarksfoldermodel.h"
#include "bookmarksmanager.h"

BookmarksFolderModel::BookmarksFolderModel(QObject * parent)
        : QSortFilterProxyModel(parent)
{
    setSourceModel(BookmarksManager::bookmarksManager());

    setDynamicSortFilter(true);
}

bool BookmarksFolderModel::filterAcceptsColumn(int source_column,
                                               const QModelIndex & /*source_parent*/) const
{
    if(source_column == 0)
    {
        return true;
    }
    return false;
}

bool BookmarksFolderModel::filterAcceptsRow(int source_row,
                                            const QModelIndex & source_parent) const
{
    QModelIndex index = sourceModel()->index(source_row, 1, source_parent);
    return sourceModel()->data(index).toString().isEmpty();
}
