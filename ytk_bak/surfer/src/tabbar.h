#ifndef TABBAR_H
#define TABBAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class TabManager;
class Tab;
class BookmarksManager;
class BookmarksFolderDialog;

class TabBar
        : public QTabBar
{
    Q_OBJECT

public:
    TabBar(QWidget * parent = 0);
    ~TabBar();

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void mouseDoubleClickEvent(QMouseEvent * event);

private:
    QMenu * m_tabMenu;
    QAction * m_reloadTabAction;
    QAction * m_copyAction;
    QAction * m_createBookmarkAction;
    QAction * m_closeTabAction;
    QAction * m_closeAllTabsAction;
    BookmarksFolderDialog * m_dialog;

private slots:
    void reloadTab();
    void closeTab();
    void copyTabUrl();
    void createBookmark();
};

#endif // TABBAR_H
