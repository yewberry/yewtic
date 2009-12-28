#include "downloadview.h"
#include "downloadmanager.h"
#include "downloaditem.h"
#include "downloaditemdelegate.h"
#include "downloaditemwidget.h"

DownloadView::DownloadView(QWidget * parent)
        : QListView(parent)
{
    setModel(DownloadManager::downloadManager());

    m_delegate = new DownloadItemDelegate(this);
    setItemDelegate(m_delegate);

    connect(DownloadManager::downloadManager(), SIGNAL(newItem()), this, SLOT(handleNewItem()));
    connect(DownloadManager::downloadManager(), SIGNAL(itemDeleted(int)),
            this, SLOT(handleDeletedItem(int)));
}

void DownloadView::handleNewItem()
{
    DownloadItem * item = DownloadManager::downloadManager()->item(0);
    DownloadItemWidget * itemWidget = new DownloadItemWidget(item, this);
    m_widgets.prepend(itemWidget);
    setIndexWidget(model()->index(0, 0, QModelIndex()), itemWidget);
}

void DownloadView::handleDeletedItem(int index)
{
    m_widgets.at(index)->deleteLater();
    m_widgets.removeAt(index);
}
