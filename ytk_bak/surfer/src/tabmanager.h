#ifndef TABMANAGER_H
#define TABMANAGER_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class Tab;
class ClosedTab;

class TabManager
        : public QObject
{
    Q_OBJECT

public:
    TabManager();
    static TabManager * tabManager();
    void setTabWidget(QTabWidget * tabWidget);
    QList<ClosedTab *> closedTabs(int count) const;
    int count() const;
    int currentIndex() const;
    Tab * tab(int index) const;
    Tab * currentTab() const;

private:
    static TabManager * m_tabManager;
    QTabWidget * m_tabWidget;
    QList<ClosedTab *> m_closedTabs;

public slots:
    void setCurrentIndex(int index);
    Tab * addTab(const QUrl & url = QUrl("about:blank"));
    Tab * insertTab(int index, const QUrl & url = QUrl("about:blank"));
    void removeCurrentTab();
    void removeTab(int index);
    void removeAllTabs();
    void restoreTab(int index = 0);
    void clearRestoreList();
    void load();
    void save();
};

#endif // TABMANAGER_H
