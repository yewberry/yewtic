#include "historyfiltermodel.h"
#include "historymanager.h"

HistoryFilterModel::HistoryFilterModel(QObject * parent)
        : QSortFilterProxyModel(parent)
{
    setSourceModel(HistoryManager::historyManager());

    setDynamicSortFilter(true);
    setFilterKeyColumn(-1);
}
