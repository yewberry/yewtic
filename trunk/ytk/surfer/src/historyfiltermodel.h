#ifndef HISTORYFILTERMODEL_H
#define HISTORYFILTERMODEL_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryManager;

class HistoryFilterModel
        : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    HistoryFilterModel(QObject * parent = 0);
};

#endif // HISTORYFILTERMODEL_H
