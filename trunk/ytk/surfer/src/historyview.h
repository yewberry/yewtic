#ifndef HISTORYVIEW_H
#define HISTORYVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryFilterModel;
class TabManager;
class HistoryManager;

class HistoryView
        : public QTreeView
{
    Q_OBJECT

public:
    HistoryView(QWidget * parent = 0);
    HistoryFilterModel * model() const;

protected:
    void mousePressEvent(QMouseEvent * event);
    void mouseDoubleClickEvent(QMouseEvent * event);

private:
    HistoryFilterModel * m_model;
    QShortcut * m_removeShortcut;
    QMenu * m_itemMenu;
    QAction * m_openAction;
    QAction * m_copyUrlAction;
    QAction * m_removeAction;

private slots:
    void addTabToCurrentItem();
    void copyCurrentItemUrl();
    void removeCurrentItem();
};

#endif // HISTORYVIEW_H
