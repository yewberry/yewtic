#include "TabWidget.h"
#include "TabManager.h"

TabWidget::TabWidget(BatDown* app, QWidget *parent)
: QTabWidget(parent), BatDownBase(app)
{
    setDocumentMode(true);
    setMovable(true);
    setTabsClosable(true);
    connect(this, SIGNAL(tabCloseRequested(int)), TabManager::tabManager(), SLOT(removeTab(int)));
}
