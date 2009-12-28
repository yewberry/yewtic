#include "bookmarksfolderview.h"
#include "bookmarksfoldermodel.h"
#include "bookmarksmanager.h"

BookmarksFolderView::BookmarksFolderView(QWidget * parent)
        : QTreeView(parent)
{
    setHeaderHidden(true);

    m_model = new BookmarksFolderModel(this);
    setModel(m_model);
    setCurrentIndex(model()->index(0, 0, QModelIndex()));
    expand(model()->index(0, 0, QModelIndex()));
}

QModelIndex BookmarksFolderView::currentSourceIndex() const
{
    return m_model->mapToSource(currentIndex());
}

void BookmarksFolderView::createFolder()
{
    BookmarksManager * manager = BookmarksManager::bookmarksManager();
    QModelIndex index = m_model->mapToSource(currentIndex());
    if(index.isValid())
    {
        QList<QVariant> indexes = manager->indexes(index);
        bool ok;
        QString title =
                QInputDialog::getText(this, trUtf8("Create bookmarks folder"),
                                      trUtf8("Title") + ":",
                                      QLineEdit::Normal, QString(), &ok);
        if(ok && !title.isEmpty())
        {
            manager->addItem(title, QUrl(), indexes);
        }
    }
}
