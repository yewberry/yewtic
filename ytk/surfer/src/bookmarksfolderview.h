#ifndef BOOKMARKSFOLDERVIEW_H
#define BOOKMARKSFOLDERVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class BookmarksFolderModel;
class BookmarksManager;

class BookmarksFolderView
        : public QTreeView
{
    Q_OBJECT

public:
    BookmarksFolderView(QWidget * parent = 0);
    QModelIndex currentSourceIndex() const;

private:
    BookmarksFolderModel * m_model;

private slots:
    void createFolder();
};

#endif // BOOKMARKSFOLDERVIEW_H
