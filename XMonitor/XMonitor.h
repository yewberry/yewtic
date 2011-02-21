#ifndef XMONITOR_H
#define XMONITOR_H

#include <QtGui/QMainWindow>
#include "ui_XMonitor.h"

class XMonitor : public QMainWindow
{
    Q_OBJECT

public:
    XMonitor(QWidget *parent = 0);
    ~XMonitor();

private:
    Ui::XMonitorClass ui;
};

#endif // XMONITOR_H
