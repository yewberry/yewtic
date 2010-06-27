#include "bookmarksdialog.h"
#include "bookmarksview.h"
#include "settingsmanager.h"

BookmarksDialog::BookmarksDialog()
{
    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle(trUtf8("Bookmarks"));
    resize(600, 400);
    QRect geometry = SettingsManager::settingsManager()->bookmarksDialogGeometry();
    if(geometry != QRect())
    {
        setGeometry(geometry);
    }

    m_view = new BookmarksView(this);
    QVBoxLayout * vlayout = new QVBoxLayout(this);
    vlayout->addWidget(m_view, 1);
}

void BookmarksDialog::resizeEvent(QResizeEvent * /*event*/)
{
    SettingsManager::settingsManager()->setBookmarksDialogGeometry(geometry());
}

void BookmarksDialog::moveEvent(QMoveEvent * /*event*/)
{
    SettingsManager::settingsManager()->setBookmarksDialogGeometry(geometry());
}
