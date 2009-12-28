#include "historyview.h"
#include "historyfiltermodel.h"
#include "tabmanager.h"
#include "historymanager.h"

HistoryView::HistoryView(QWidget * parent)
        : QTreeView(parent)
{
    header()->setResizeMode(QHeaderView::Stretch);
    setRootIsDecorated(false);

    m_model = new HistoryFilterModel(this);
    setModel(m_model);
    setCurrentIndex(model()->index(0, 0, QModelIndex()));

    m_removeShortcut = new QShortcut(QKeySequence::Delete, this);
    connect(m_removeShortcut, SIGNAL(activated()), this, SLOT(removeCurrentItem()));

    m_itemMenu = new QMenu(this);

    m_openAction =
            m_itemMenu->addAction(QIcon(":/openTab.png"), trUtf8("Open in new tab"));
    connect(m_openAction, SIGNAL(triggered()), this, SLOT(addTabToCurrentItem()));

    m_itemMenu->addSeparator();

    m_copyUrlAction = m_itemMenu->addAction(QIcon(":/copy.png"), trUtf8("Copy address"));
    connect(m_copyUrlAction, SIGNAL(triggered()), this, SLOT(copyCurrentItemUrl()));

    m_itemMenu->addSeparator();

    m_removeAction = m_itemMenu->addAction(QIcon(":/delete.png"), trUtf8("Delete"));
    connect(m_removeAction, SIGNAL(triggered()), this, SLOT(removeCurrentItem()));
}

HistoryFilterModel * HistoryView::model() const
{
    return m_model;
}

void HistoryView::mousePressEvent(QMouseEvent * event)
{
    QModelIndex index = indexAt(event->pos());
    if(event->button() == Qt::RightButton && index.isValid())
    {
        setCurrentIndex(index);
        m_itemMenu->popup(event->globalPos());
        event->accept();
    }
    else
    {
        QTreeView::mousePressEvent(event);
    }
}

void HistoryView::mouseDoubleClickEvent(QMouseEvent * event)
{
    QModelIndex index = indexAt(event->pos());
    if(event->button() == Qt::LeftButton && index.isValid())
    {
        setCurrentIndex(index);
        addTabToCurrentItem();
        event->accept();
    }
    else
    {
        QTreeView::mouseDoubleClickEvent(event);
    }
}

void HistoryView::addTabToCurrentItem()
{
    QModelIndex index = m_model->index(currentIndex().row(), 1);
    TabManager::tabManager()->addTab(QUrl(index.data(Qt::DisplayRole).toString()));
}

void HistoryView::copyCurrentItemUrl()
{
    QModelIndex index = m_model->index(currentIndex().row(), 1);
    QApplication::clipboard()->setText(index.data(Qt::DisplayRole).toString());
}

void HistoryView::removeCurrentItem()
{
    QModelIndex current = m_model->mapToSource(currentIndex());
    HistoryManager::historyManager()->removeItem(current.row());
}
