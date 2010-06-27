#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class TabBar;
class TabManager;

class TabWidget
        : public QTabWidget
{
    Q_OBJECT

public:
    TabWidget(QWidget * parent = 0);

private:
    TabBar * m_tabBar;
    QAction * m_openTabAction;
    QShortcut * m_closeTabShortcut;
};

#endif // TABWIDGET_H
