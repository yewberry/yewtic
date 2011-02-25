#ifndef XMONITOR_H
#define XMONITOR_H

#include <QtGui/QMainWindow>
#include "../ui_XMonitor.h"

class TopHeader;
class QToolButton;

class XMonitor : public QMainWindow
{
    Q_OBJECT

public:
    XMonitor(QWidget *parent = 0);
    ~XMonitor();

private:
    void drawUi();

private:
    Ui::XMonitorClass ui;

    TopHeader* 		m_pTopHeader;
    QToolButton*	m_pSvrBtn;
    QToolButton*	m_pRptBtn;
    QToolButton*	m_pHelpBtn;
};

#endif // XMONITOR_H
