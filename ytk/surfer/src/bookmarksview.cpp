#include "bookmarksview.h"
#include "tabmanager.h"
#include "bookmarksmanager.h"
#include "bookmarksdelegate.h"

BookmarksView::BookmarksView(QWidget * parent)
        : QTreeView(parent)
{
    header()->setResizeMode(QHeaderView::Stretch);

    setModel(BookmarksManager::bookmarksManager());
    setCurrentIndex(model()->index(0, 0, QModelIndex()));
    expand(model()->index(0, 0, QModelIndex()));

    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);

    setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_delegate = new BookmarksDelegate(this);
    setItemDelegate(m_delegate);

    m_editTitleShortcut = new QShortcut(Qt::Key_F2, this);
    connect(m_editTitleShortcut, SIGNAL(activated()), this, SLOT(editTitle()));

    m_editUrlShortcut = new QShortcut(Qt::Key_F3, this);
    connect(m_editUrlShortcut, SIGNAL(activated()), this, SLOT(editUrl()));

    m_removeShortcut = new QShortcut(QKeySequence::Delete, this);
    connect(m_removeShortcut, SIGNAL(activated()), this, SLOT(removeCurrentItem()));

    m_itemMenu = new QMenu(this);
}

void BookmarksView::mousePressEvent(QMouseEvent * event)
{
    QModelIndex index = indexAt(event->pos());
    if(event->button() == Qt::RightButton && index.isValid())
    {
        setCurrentIndex(index);
        BookmarksManager * manager = BookmarksManager::bookmarksManager();
        QUrl url(manager->index(index.row(), 1, index.parent()).data(Qt::DisplayRole).toString());

        m_itemMenu->clear();

        if(url != QUrl())
        {
            m_openAction =
                    m_itemMenu->addAction(QIcon(":/openTab.png"), trUtf8("Open in new tab"));
            connect(m_openAction, SIGNAL(triggered()), this, SLOT(addTabToCurrentItem()));
        }
        else
        {
            m_createFolderAction =
                    m_itemMenu->addAction(QIcon(":/createFolder.png"), trUtf8("Create folder"));
            connect(m_createFolderAction, SIGNAL(triggered()), this, SLOT(createFolder()));
        }

        if(index.parent().isValid())
        {
            m_itemMenu->addSeparator();

            m_editTitleAction = m_itemMenu->addAction(QIcon(":/edit.png"), trUtf8("Edit title"));
            connect(m_editTitleAction, SIGNAL(triggered()), this, SLOT(editTitle()));

            if(url != QUrl())
            {
                m_editUrlAction = m_itemMenu->addAction(QIcon(":/edit.png"), trUtf8("Edit address"));
                connect(m_editUrlAction, SIGNAL(triggered()), this, SLOT(editUrl()));

                m_copyUrlAction = m_itemMenu->addAction(QIcon(":/copy.png"), trUtf8("Copy address"));
                connect(m_copyUrlAction, SIGNAL(triggered()), this, SLOT(copyCurrentItemUrl()));
            }

            m_itemMenu->addSeparator();

            m_removeAction = m_itemMenu->addAction(QIcon(":/delete.png"), trUtf8("Delete"));
            connect(m_removeAction, SIGNAL(triggered()), this, SLOT(removeCurrentItem()));
        }

        m_itemMenu->popup(event->globalPos());
        event->accept();
    }
    else
    {
        QTreeView::mousePressEvent(event);
    }
}

void BookmarksView::mouseDoubleClickEvent(QMouseEvent * event)
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

void BookmarksView::addTabToCurrentItem()
{
    BookmarksManager * manager = BookmarksManager::bookmarksManager();
    QModelIndex index = manager->index(currentIndex().row(), 1, currentIndex().parent());
    QUrl url(index.data(Qt::DisplayRole).toString());
    if(url != QUrl())
    {
        TabManager::tabManager()->addTab(url);
    }
}

void BookmarksView::createFolder()
{
    BookmarksManager * manager = BookmarksManager::bookmarksManager();
    QModelIndex index = manager->index(currentIndex().row(), 1, currentIndex().parent());
    QUrl url(index.data(Qt::DisplayRole).toString());
    if(url == QUrl())
    {
        QList<QVariant> indexes = manager->indexes(index);
        bool ok;
        QString title =
                QInputDialog::getText(this, trUtf8("Create bookmarks folder"),
                                      trUtf8("Title:"),
                                      QLineEdit::Normal, QString(), &ok);
        if(ok && !title.isEmpty())
        {
            manager->addItem(title, QUrl(), indexes);
        }
    }
}

void BookmarksView::editTitle()
{
    QModelIndex index = currentIndex();
    if(index.parent().isValid())
    {
        index = model()->index(index.row(), 0, index.parent());
        edit(index);
    }
}

void BookmarksView::editUrl()
{
    QModelIndex index = currentIndex();
    if(index.parent().isValid())
    {
        index = model()->index(index.row(), 1, index.parent());
        QUrl url = QUrl(index.data(Qt::DisplayRole).toString());
        if(url != QUrl())
        {
            edit(index);
        }
    }
}

void BookmarksView::copyCurrentItemUrl()
{
    QModelIndex index = currentIndex();
    if(index.parent().isValid())
    {
        index = model()->index(index.row(), 1, index.parent());
        QUrl url = QUrl(index.data(Qt::DisplayRole).toString());
        if(url != QUrl())
        {
            QApplication::clipboard()->setText(url.toString());
        }
    }
}

void BookmarksView::removeCurrentItem()
{
    BookmarksManager * manager = BookmarksManager::bookmarksManager();
    manager->removeItem(manager->indexes(currentIndex()));
}
