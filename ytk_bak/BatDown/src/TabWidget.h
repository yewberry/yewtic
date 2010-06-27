#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QtGui/QTabWidget>
#include "BatDown.h"

class TabWidget : public QTabWidget, public BatDownBase
{
    Q_OBJECT

public:
    TabWidget(BatDown* app, QWidget *parent = 0);

};

#endif // TABWIDGET_H
