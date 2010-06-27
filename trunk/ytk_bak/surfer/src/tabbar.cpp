#include "tabbar.h"
#include "tabmanager.h"
#include "tab.h"
#include "bookmarksmanager.h"
#include "bookmarksfolderdialog.h"

TabBar::TabBar(QWidget * parent)
        : QTabBar(parent)
{
    setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);

    m_tabMenu = new QMenu(this);
    m_reloadTabAction = m_tabMenu->addAction(QIcon(":/reload-small.png"), trUtf8("Reload tab"));
    m_copyAction =
            m_tabMenu->addAction(QIcon(":/copy.png"), trUtf8("Copy tab address"));
    m_createBookmarkAction =
            m_tabMenu->addAction(QIcon(":/createBookmark.png"), trUtf8("Add bookmark to tab") + "...");
    m_tabMenu->addSeparator();
    m_closeTabAction = m_tabMenu->addAction(QIcon(":/closeTab.png"), trUtf8("Close tab"));
    m_closeAllTabsAction = m_tabMenu->addAction(QIcon(":/closeTab.png"), trUtf8("Close all tabs"));
    m_dialog = new BookmarksFolderDialog();

    connect(m_reloadTabAction, SIGNAL(triggered()), this, SLOT(reloadTab()));
    connect(m_closeTabAction, SIGNAL(triggered()), this, SLOT(closeTab()));
    connect(m_closeAllTabsAction, SIGNAL(triggered()),
            TabManager::tabManager(), SLOT(removeAllTabs()));
    connect(m_copyAction, SIGNAL(triggered()), this, SLOT(copyTabUrl()));
    connect(m_createBookmarkAction, SIGNAL(triggered()), this, SLOT(createBookmark()));
}

TabBar::~TabBar()
{
    m_dialog->deleteLater();
}

void TabBar::mousePressEvent(QMouseEvent * event)
{
    int index = tabAt(event->pos());
    if(event->button() == Qt::RightButton && index != -1)
    {
        m_reloadTabAction->setData(index);
        m_closeTabAction->setData(index);
        m_copyAction->setData(index);
        m_createBookmarkAction->setData(index);
        m_tabMenu->popup(event->globalPos());
        event->accept();
    }
    else
    {
        QTabBar::mousePressEvent(event);
    }
}

void TabBar::mouseReleaseEvent(QMouseEvent * event)
{
    int index = tabAt(event->pos());
    if(event->button() == Qt::MidButton)
    {
        if(index != -1)
        {
            TabManager::tabManager()->removeTab(index);
        }
        else
        {
            TabManager::tabManager()->addTab();
        }
        event->accept();
    }
    else
    {
        QTabBar::mouseReleaseEvent(event);
    }
}

void TabBar::mouseDoubleClickEvent(QMouseEvent * event)
{
    int index = tabAt(event->pos());
    if(event->button() == Qt::LeftButton)
    {
        if(index != -1)
        {
            TabManager::tabManager()->removeTab(index);
        }
        else
        {
            TabManager::tabManager()->addTab();
        }
        event->accept();
    }
    else
    {
        QTabBar::mouseDoubleClickEvent(event);
    }
}

void TabBar::reloadTab()
{
    TabManager::tabManager()->tab(m_reloadTabAction->data().toInt())->reload();
}

void TabBar::closeTab()
{
    TabManager::tabManager()->removeTab(m_closeTabAction->data().toInt());
}

void TabBar::copyTabUrl()
{
    Tab * tab = TabManager::tabManager()->tab(m_copyAction->data().toInt());
    QApplication::clipboard()->setText(tab->url().toString());
}

void TabBar::createBookmark()
{
    Tab * tab = TabManager::tabManager()->tab(m_createBookmarkAction->data().toInt());
    m_dialog->setTitle(tab->title());
    if(m_dialog->exec() == QDialog::Accepted && !m_dialog->title().isEmpty())
    {
        BookmarksManager * manager = BookmarksManager::bookmarksManager();
        manager->addItem(m_dialog->title(), tab->url(), manager->indexes(m_dialog->parentIndex()));
    }
}
