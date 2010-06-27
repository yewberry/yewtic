#include "tabwidget.h"
#include "tabbar.h"
#include "tabmanager.h"

TabWidget::TabWidget(QWidget * parent)
        : QTabWidget(parent)
{
    m_tabBar = new TabBar(this);
    setTabBar(m_tabBar);

    setDocumentMode(true);

    QToolBar * toolBar = new QToolBar(this);
    m_openTabAction = toolBar->addAction(QIcon(":/openTab.png"), trUtf8("Open new tab"));
    m_openTabAction->setShortcut(Qt::CTRL + Qt::Key_T);
    connect(m_openTabAction, SIGNAL(triggered()), TabManager::tabManager(), SLOT(addTab()));
    setCornerWidget(toolBar);

    m_closeTabShortcut = new QShortcut(QKeySequence::Close, this);
    connect(m_closeTabShortcut, SIGNAL(activated()),
            TabManager::tabManager(), SLOT(removeCurrentTab()));

    setMovable(true);

    setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(int)), TabManager::tabManager(), SLOT(removeTab(int)));
}
