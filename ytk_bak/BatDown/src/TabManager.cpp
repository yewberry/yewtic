#include "TabManager.h"
#include "Tab.h"
#include "TabWidget.h"

TabManager* TabManager::m_pTabManager = 0;

TabManager::TabManager()
: m_pTabWidget(0)
{
}

TabManager* TabManager::tabManager()
{
	if(!m_pTabManager)
	{
		m_pTabManager = new TabManager;
	}
	return m_pTabManager;
}

void TabManager::setTabWidget(TabWidget *tabWidget)
{
	m_pTabWidget = tabWidget;
}

int TabManager::count() const
{
	if(m_pTabWidget){
		return m_pTabWidget->count();
	}
	return -1;
}

int TabManager::currentIndex() const
{
	if(m_pTabWidget){
		return m_pTabWidget->currentIndex();
	}
	return -1;
}

Tab* TabManager::tab(int index) const
{
	return qobject_cast<Tab *>(m_pTabWidget->widget(index));
}

Tab* TabManager::currentTab() const
{
	return tab(currentIndex());
}

void TabManager::setCurrentIndex(int index)
{
	if(m_pTabWidget){
		m_pTabWidget->setCurrentIndex(index);
	}
}

Tab* TabManager::addTab(const QUrl &url, const QString &scriptFilename)
{
	if(m_pTabWidget){
		return insertTab(count(), url, scriptFilename);
	}
	return 0;
}

Tab* TabManager::insertTab(int index, const QUrl &url, const QString &scriptFilename)
{
	if(m_pTabWidget){
		Tab *tab = new Tab(m_pTabWidget->getApp(), m_pTabWidget);
		QIcon icon = QWebSettings::iconForUrl(url);
		if( icon.isNull() ){
			icon = QIcon(":/BatDown/defaultPageIcon.png");
		}
		m_pTabWidget->insertTab(index, tab, icon, tr("New tab"));
		m_pTabWidget->setTabToolTip(index, tr("New tab"));
		setCurrentIndex(index);
		tab->load(url, scriptFilename);

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
	if(m_pTabWidget){
		Tab *tab = qobject_cast<Tab *>(this->tab(index));
		if(tab){
			m_pTabWidget->removeTab(index);
			tab->deleteLater();
		}

		if(m_pTabWidget->count() == 0){
			addTab();
		}
	}
}

void TabManager::removeAllTabs()
{
	if(m_pTabWidget){
		for(int i = count() - 1; i >=0 ; --i){
			removeTab(i);
		}
	}
}

