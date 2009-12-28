#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class AdressBar;
class TabManager;
class HistoryDialog;
class BookmarksManager;
class BookmarksItem;
class Tab;
class WebView;
class BookmarksDialog;
class SettingsDialog;
class DownloadDialog;
class ClosedTab;
class BookmarksFolderDialog;
class HistoryManager;
class HistoryItem;

class ToolBar
        : public QToolBar
{
    Q_OBJECT

public:
    ToolBar(QWebHistory * history, const QUrl & url, QWidget * parent = 0);
    ~ToolBar();
    QUrl url() const;
    AdressBar * adressBar() const;

private:
    QAction * m_goBackAction;
    QMenu * m_backMenu;
    QAction * m_goForwardAction;
    QMenu * m_forwardMenu;
    QAction * m_reloadAction;
    QAction * m_stopAction;
    AdressBar * m_adressBar;
    QAction * m_restoreAction;
    QMenu * m_restoreMenu;
    QAction * m_bookmarksAction;
    QMenu * m_bookmarksMenu;
    QWebHistory * m_history;
    QAction * m_showHistoryAction;
    QMenu * m_historyMenu;
    QAction * m_downloadAction;
    QAction * m_settingsAction;
    static HistoryDialog * m_historyDialog;
    static BookmarksDialog * m_bookmarksDialog;
    static DownloadDialog * m_downloadDialog;
    static SettingsDialog * m_settingsDialog;
    static BookmarksFolderDialog * m_addBookmarkDialog;
    static int m_count;
    void fillBookmarksMenuPart(QMenu * menu, const QList<QVariant> & indexes);

public slots:
    void setUrl(const QUrl & url);
    void updateActions();
    void enableStopAction();
    void disableStopAction();

private slots:
    void updateBackMenu();
    void updateForwardMenu();
    void updateRestoreMenu();
    void updateBookmarksMenu();
    void updateHistoryMenu();
    void navigate();
    void restore();
    void openItem();
    void createBookmark();

signals:
    void goBackRequsted();
    void goForwardRequsted();
    void reloadRequsted();
    void stopRequsted();
    void loadRequsted(const QUrl & url);
};

#endif // TOOLBAR_H
