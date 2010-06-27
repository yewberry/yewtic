#include "toolbar.h"
#include "adressbar.h"
#include "tabmanager.h"
#include "historydialog.h"
#include "bookmarksmanager.h"
#include "bookmarksitem.h"
#include "tab.h"
#include "webview.h"
#include "bookmarksdialog.h"
#include "settingsdialog.h"
#include "downloaddialog.h"
#include "closedtab.h"
#include "bookmarksfolderdialog.h"
#include "historymanager.h"
#include "historyitem.h"

HistoryDialog * ToolBar::m_historyDialog = 0;
BookmarksDialog * ToolBar::m_bookmarksDialog = 0;
DownloadDialog * ToolBar::m_downloadDialog = 0;
SettingsDialog * ToolBar::m_settingsDialog = 0;
BookmarksFolderDialog * ToolBar::m_addBookmarkDialog = 0;
int ToolBar::m_count = 0;

ToolBar::ToolBar(QWebHistory * history, const QUrl & url, QWidget * parent)
        : QToolBar(parent)
{
    setIconSize(QSize(22, 22));

    m_goBackAction = new QAction(QIcon(":/goBack.png"), trUtf8("Go back"), this);
    m_goBackAction->setEnabled(false);
    m_goBackAction->setShortcut(QKeySequence::Back);
    m_backMenu = new QMenu(this);
    m_goBackAction->setMenu(m_backMenu);
    addAction(m_goBackAction);
    m_goForwardAction = new QAction(QIcon(":/goForward.png"), trUtf8("Go forward"), this);
    m_goForwardAction->setEnabled(false);
    m_goForwardAction->setShortcut(QKeySequence::Forward);
    m_forwardMenu = new QMenu(this);
    m_goForwardAction->setMenu(m_forwardMenu);
    addAction(m_goForwardAction);
    m_reloadAction = addAction(QIcon(":/reload.png"), trUtf8("Reload"));
    m_reloadAction->setShortcut(QKeySequence::Refresh);
    m_stopAction = addAction(QIcon(":/stop.png"), trUtf8("Stop"));
    m_stopAction->setEnabled(url != QUrl("about:blank"));
    m_stopAction->setShortcut(Qt::CTRL + Qt::Key_S);
    m_adressBar = new AdressBar(url, this);
    addWidget(m_adressBar);
    m_restoreAction = new QAction(QIcon(":/restore.png"), trUtf8("Restore closed tab"), this);
    m_restoreAction->setShortcut(QKeySequence::Undo);
    m_restoreMenu = new QMenu(this);
    m_restoreAction->setMenu(m_restoreMenu);
    addAction(m_restoreAction);
    m_bookmarksAction = new QAction(QIcon(":/bookmarks.png"), trUtf8("Bookmarks") + "...", this);
    m_bookmarksAction->setShortcut(Qt::CTRL + Qt::Key_B);
    m_bookmarksMenu = new QMenu(this);
    m_bookmarksAction->setMenu(m_bookmarksMenu);
    addAction(m_bookmarksAction);
    m_history = history;
    m_showHistoryAction = new QAction(QIcon(":/history.png"), trUtf8("History") + "...", this);
    m_showHistoryAction->setShortcut(Qt::CTRL + Qt::Key_H);
    m_historyMenu = new QMenu(this);
    m_showHistoryAction->setMenu(m_historyMenu);
    addAction(m_showHistoryAction);
    m_downloadAction = addAction(QIcon(":/download.png"), trUtf8("Downloads") + "...");
    m_downloadAction->setShortcut(Qt::CTRL + Qt::Key_D);
    m_settingsAction = addAction(QIcon(":/settings.png"), trUtf8("Settings") + "...");
    m_count++;
    if(m_count == 1)
    {
        m_historyDialog = new HistoryDialog();
        m_bookmarksDialog = new BookmarksDialog();
        m_downloadDialog = new DownloadDialog();
        m_settingsDialog = new SettingsDialog();
        m_addBookmarkDialog = new BookmarksFolderDialog();
    }

    connect(m_goBackAction, SIGNAL(triggered()), this, SIGNAL(goBackRequsted()));
    connect(m_backMenu, SIGNAL(aboutToShow()), this, SLOT(updateBackMenu()));
    connect(m_goForwardAction, SIGNAL(triggered()), this, SIGNAL(goForwardRequsted()));
    connect(m_forwardMenu, SIGNAL(aboutToShow()), this, SLOT(updateForwardMenu()));
    connect(m_reloadAction, SIGNAL(triggered()), this, SIGNAL(reloadRequsted()));
    connect(m_stopAction, SIGNAL(triggered()), this, SIGNAL(stopRequsted()));
    connect(m_adressBar, SIGNAL(loadRequsted(const QUrl &)),
            this, SIGNAL(loadRequsted(const QUrl &)));
    connect(m_restoreAction, SIGNAL(triggered()), TabManager::tabManager(), SLOT(restoreTab()));
    connect(m_restoreMenu, SIGNAL(aboutToShow()), this, SLOT(updateRestoreMenu()));
    connect(m_bookmarksAction, SIGNAL(triggered()), m_bookmarksDialog, SLOT(show()));
    connect(m_bookmarksMenu, SIGNAL(aboutToShow()), this, SLOT(updateBookmarksMenu()));
    connect(m_showHistoryAction, SIGNAL(triggered()), m_historyDialog, SLOT(show()));
    connect(m_historyMenu, SIGNAL(aboutToShow()), this, SLOT(updateHistoryMenu()));
    connect(m_downloadAction, SIGNAL(triggered()), m_downloadDialog, SLOT(show()));
    connect(m_settingsAction, SIGNAL(triggered()), m_settingsDialog, SLOT(show()));
}

ToolBar::~ToolBar()
{
    m_count--;
    if(m_count == 0)
    {
        m_historyDialog->deleteLater();
        m_bookmarksDialog->deleteLater();
        m_downloadDialog->deleteLater();
        m_settingsDialog->deleteLater();
        m_addBookmarkDialog->deleteLater();
    }
}

QUrl ToolBar::url() const
{
    return m_adressBar->url();
}

AdressBar * ToolBar::adressBar() const
{
    return m_adressBar;
}

void ToolBar::fillBookmarksMenuPart(QMenu * menu, const QList<QVariant> & indexes)
{
    if(menu == m_bookmarksMenu)
    {
        QAction * createBookmarkAction =
                menu->addAction(QIcon(":/createBookmark.png"), trUtf8("Add bookmark to page") + "...");
        connect(createBookmarkAction, SIGNAL(triggered()), this, SLOT(createBookmark()));

        menu->addSeparator();
    }

    BookmarksItem * item = BookmarksManager::bookmarksManager()->item(indexes);

    for(int i = 0; i < item->childrenCount(); i++)
    {
        BookmarksItem * newItem = item->child(i);
        QUrl url = newItem->url();
        QString title = newItem->title();
        if(title.length() > 30)
        {
            title.truncate(27);
            title += "...";
        }
        if(url != QUrl())
        {
            QIcon icon = QWebSettings::iconForUrl(url);
            if(icon.isNull())
            {
                icon = QIcon(":/defaultPageIcon.png");
            }
            QAction * action = menu->addAction(icon, title);
            action->setData(url);
            connect(action, SIGNAL(triggered()), this, SLOT(openItem()));
        }
        else
        {
            QList<QVariant> newIndexes = indexes;
            newIndexes += i;
            QMenu * newMenu = menu->addMenu(QIcon(":/folder.png"), title);
            fillBookmarksMenuPart(newMenu, newIndexes);
        }
    }
    if(!item->childrenCount())
    {
        QAction * action = menu->addAction(QString("(") + trUtf8("Empty") + ")");
        action->setEnabled(false);
    }
}

void ToolBar::setUrl(const QUrl & url)
{
    m_adressBar->setUrl(url);
}

void ToolBar::updateActions()
{
    m_goBackAction->setEnabled(m_history->canGoBack());
    m_goForwardAction->setEnabled(m_history->canGoForward());
}

void ToolBar::enableStopAction()
{
    m_stopAction->setEnabled(true);
}

void ToolBar::disableStopAction()
{
    m_stopAction->setEnabled(false);
}

void ToolBar::updateBackMenu()
{
    QAction * action;

    m_backMenu->clear();

    QList<QWebHistoryItem> list = m_history->backItems(10);
    for(int i = list.count() - 1; i >= 0; i--)
    {
        QWebHistoryItem item = list.at(i);
        QString title = item.title();
        if(title.length() > 30)
        {
            title.truncate(27);
            title += "...";
        }
        action = m_backMenu->addAction(item.icon(), title);
        action->setData(- list.count() + i);
        connect(action, SIGNAL(triggered()), this, SLOT(navigate()));
    }
}

void ToolBar::updateForwardMenu()
{
    QAction * action;

    m_forwardMenu->clear();

    QList<QWebHistoryItem> list = m_history->forwardItems(10);
    for(int i = 0; i < list.count(); i++)
    {
        QWebHistoryItem item = list.at(i);
        QString title = item.title();
        if(title.length() > 30)
        {
            title.truncate(27);
            title += "...";
        }
        action = m_forwardMenu->addAction(item.icon(), title);
        action->setData(i + 1);
        connect(action, SIGNAL(triggered()), this, SLOT(navigate()));
    }
}

void ToolBar::updateRestoreMenu()
{
    QAction * action;

    m_restoreMenu->clear();

    QList<ClosedTab *> tabs = TabManager::tabManager()->closedTabs(10);
    for(int i = 0; i < tabs.count(); i++)
    {
        QIcon icon = QWebSettings::iconForUrl(tabs.at(i)->url());
        if(icon.isNull())
        {
            icon = QIcon(":/defaultPageIcon.png");
        }
        QString title = tabs.at(i)->title();
        if(title.length() > 30)
        {
            title.truncate(27);
            title += "...";
        }
        action = m_restoreMenu->addAction(icon, title);
        action->setData(i);
        connect(action, SIGNAL(triggered()), this, SLOT(restore()));
    }
    m_restoreMenu->addSeparator();
    QAction * clearListAction =
            m_restoreMenu->addAction(QIcon(":/clear.png"), trUtf8("Clear closed tabs list"));
    connect(clearListAction, SIGNAL(triggered()),
            TabManager::tabManager(), SLOT(clearRestoreList()));
}

void ToolBar::updateBookmarksMenu()
{
    m_bookmarksMenu->clear();

    fillBookmarksMenuPart(m_bookmarksMenu, QList<QVariant>());
}

void ToolBar::updateHistoryMenu()
{
    m_historyMenu->clear();

    HistoryManager * manager = HistoryManager::historyManager();

    for(int i = 0; i < 10 && i < manager->count(); i++)
    {
        HistoryItem * item = manager->item(i);
        QIcon icon = QWebSettings::iconForUrl(item->url());
        if(icon.isNull())
        {
            icon = QIcon(":/defaultPageIcon.png");
        }
        QString title = item->title();
        if(title.length() > 30)
        {
            title.truncate(27);
            title += "...";
        }
        QAction * action = m_historyMenu->addAction(icon, title);
        action->setData(item->url());
        connect(action, SIGNAL(triggered()), this, SLOT(openItem()));
    }
}

void ToolBar::navigate()
{
    QAction * action = qobject_cast<QAction *>(sender());
    if(action)
    {
        int index = action->data().toInt();
        if(index > 0)
        {
            m_history->goToItem(m_history->forwardItems(index).last());
        }
        else
        {
            m_history->goToItem(m_history->backItems(-index).first());
        }
    }
}

void ToolBar::restore()
{
    QAction * action = qobject_cast<QAction *>(sender());
    if(action)
    {
        int index = action->data().toInt();
        TabManager::tabManager()->restoreTab(index);
    }
}

void ToolBar::openItem()
{
    QAction * action = qobject_cast<QAction *>(sender());
    if(action)
    {
        TabManager::tabManager()->addTab(action->data().toUrl());
    }
}

void ToolBar::createBookmark()
{
    BookmarksManager * manager = BookmarksManager::bookmarksManager();
    Tab * tab = TabManager::tabManager()->currentTab();
    if(tab)
    {
        m_addBookmarkDialog->setTitle(tab->title());
        if(m_addBookmarkDialog->exec() == QDialog::Accepted &&
           !m_addBookmarkDialog->title().isEmpty())
        {
            QString title = m_addBookmarkDialog->title();
            QModelIndex index = m_addBookmarkDialog->parentIndex();
            manager->addItem(title, tab->url(), manager->indexes(index));
        }
    }
}

