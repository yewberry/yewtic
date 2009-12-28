#ifndef BOOKMARKSVIEW_H
#define BOOKMARKSVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class TabManager;
class BookmarksManager;
class BookmarksDelegate;

class BookmarksView
        : public QTreeView
{
    Q_OBJECT

public:
    BookmarksView(QWidget * parent = 0);

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseDoubleClickEvent(QMouseEvent * event);

private:
    BookmarksDelegate * m_delegate;
    QShortcut * m_editTitleShortcut;
    QShortcut * m_editUrlShortcut;
    QShortcut * m_removeShortcut;
    QMenu * m_itemMenu;
    QAction * m_openAction;
    QAction * m_createFolderAction;
    QAction * m_editTitleAction;
    QAction * m_editUrlAction;
    QAction * m_copyUrlAction;
    QAction * m_removeAction;

private slots:
    void addTabToCurrentItem();
    void createFolder();
    void editTitle();
    void editUrl();
    void copyCurrentItemUrl();
    void removeCurrentItem();
};

#endif // BOOKMARKSVIEW_H
