#include "tabmanager.h"
#include "tab.h"
#include "closedtab.h"

TabManager * TabManager::m_tabManager = 0;

TabManager::TabManager()
        : m_tabWidget(0)
{
}

TabManager * TabManager::tabManager()
{
    if(!m_tabManager)
    {
        m_tabManager = new TabManager();
    }
    return m_tabManager;
}

void TabManager::setTabWidget(QTabWidget * tabWidget)
{
    m_tabWidget = tabWidget;
}

QList<ClosedTab *> TabManager::closedTabs(int count) const
{
    return m_closedTabs.mid(0, count);
}

int TabManager::count() const
{
    if(m_tabWidget)
    {
        return m_tabWidget->count();
    }
    return -1;
}

int TabManager::currentIndex() const
{
    if(m_tabWidget)
    {
        return m_tabWidget->currentIndex();
    }
    return -1;
}

Tab * TabManager::tab(int index) const
{
    return qobject_cast<Tab *>(m_tabWidget->widget(index));
}

Tab * TabManager::currentTab() const
{
    return tab(currentIndex());
}

void TabManager::setCurrentIndex(int index)
{
    if(m_tabWidget)
    {
        m_tabWidget->setCurrentIndex(index);
    }
}

Tab * TabManager::addTab(const QUrl & url)
{
    if(m_tabWidget)
    {
        return insertTab(count(), url);
    }
    return 0;
}

Tab * TabManager::insertTab(int index, const QUrl & url)
{
    if(m_tabWidget)
    {
        Tab * tab = new Tab(url, m_tabWidget);
        QIcon icon = QWebSettings::iconForUrl(url);
        if(icon.isNull())
        {
            icon = QIcon(":/defaultPageIcon.png");
        }
        m_tabWidget->insertTab(index, tab, icon, trUtf8("New tab"));
        m_tabWidget->setTabToolTip(index, trUtf8("New tab"));
        setCurrentIndex(index);
        return tab;
    }
    return 0;
}

void TabManager::removeCurrentTab()
{
    removeTab(currentIndex());
}

void TabManager::removeTab(int index)
{
    if(m_tabWidget)
    {
        Tab * tab = qobject_cast<Tab *>(this->tab(index));
        if(tab)
        {
            ClosedTab * closedTab = new ClosedTab(tab->url(), tab->title(), this);
            m_closedTabs.prepend(closedTab);
            m_tabWidget->removeTab(index);
            tab->deleteLater();
        }

        if(m_tabWidget->count() == 0)
        {
            addTab();
        }
    }
}

void TabManager::removeAllTabs()
{
    if(m_tabWidget)
    {
        for(int i = count() - 1; i >=0 ; i--)
        {
            removeTab(i);
        }
    }
}

void TabManager::restoreTab(int index)
{
    int count = m_closedTabs.count();
    if(index >= 0 && index < count)
    {
        addTab(m_closedTabs.at(index)->url());
        m_closedTabs.removeAt(index);
    }
}

void TabManager::clearRestoreList()
{
    foreach(ClosedTab * tab, m_closedTabs)
    {
        tab->deleteLater();
    }
    m_closedTabs.clear();
}

void TabManager::load()
{
    QSettings settings("PayableOnDeath", "Surfer");
    QList<QUrl> urls;
    int current = settings.value("current", 0).toInt();
    int size = settings.beginReadArray("tabs");
    for(int i = 0; i < size; i++)
    {
        settings.setArrayIndex(i);
        urls += settings.value("url", QUrl("about:blank")).value<QUrl>();
    }
    settings.endArray();

    foreach(QUrl url, urls)
    {
        addTab(url);
    }
    setCurrentIndex(current);
    if(size == 0)
    {
        addTab();
    }
}

void TabManager::save()
{
    QSettings settings("PayableOnDeath", "Surfer");
    settings.setValue("current", currentIndex());
    settings.remove("tabs");
    settings.beginWriteArray("tabs");
    for(int i = 0; i < count(); i++)
    {
        Tab * tab = qobject_cast<Tab *>(this->tab(i));
        settings.setArrayIndex(i);
        settings.setValue("url", tab->url());
    }
    settings.endArray();
}

