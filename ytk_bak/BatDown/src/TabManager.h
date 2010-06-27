#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class Tab;
class TabWidget;

class TabManager : public QObject
{
	Q_OBJECT

public:
	TabManager();
	static TabManager* tabManager();
	void setTabWidget(TabWidget *tabWidget);

	int count() const;
	int currentIndex() const;
	Tab* tab(int index) const;
	Tab* currentTab() const;

public slots:
	void setCurrentIndex(int index);

	Tab * addTab(const QUrl &url=QUrl("about:blank"), const QString &scriptFilename=QString());
	Tab * insertTab(int index, const QUrl &url=QUrl("about:blank"), const QString &scriptFilename=QString());
	void removeCurrentTab();
	void removeTab(int index);
	void removeAllTabs();

private:
	static TabManager	*m_pTabManager;
	TabWidget			*m_pTabWidget;
};

#endif // TABMANAGER_H
