#include "mainwindow.h"
#include "tabwidget.h"
#include "tabmanager.h"
#include "historymanager.h"
#include "bookmarksmanager.h"
#include "settingsmanager.h"
#include "downloadmanager.h"
#include "networkaccessmanager.h"

MainWindow::MainWindow()
{
    m_centralWidget = new QWidget(this);
    setCentralWidget(m_centralWidget);

    SettingsManager::settingsManager()->load();

    m_tabWidget = new TabWidget(m_centralWidget);
    QVBoxLayout * layout = new QVBoxLayout(m_centralWidget);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_tabWidget, 1);

    m_exitShortcut = new QShortcut(Qt::CTRL + Qt::Key_Q, this);
    m_exitShortcut->setContext(Qt::ApplicationShortcut);
    connect(m_exitShortcut, SIGNAL(activated()), qApp, SLOT(closeAllWindows()));

    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle("Surfer");
    resize(900, 600);
    QRect geometry = SettingsManager::settingsManager()->mainWindowGeometry();
    if(geometry != QRect())
    {
        setGeometry(geometry);
    }

    NetworkAccessManager::networkAccessManager()->load();
    TabManager::tabManager()->setTabWidget(m_tabWidget);
    TabManager::tabManager()->load();
    HistoryManager::historyManager()->load();
    BookmarksManager::bookmarksManager()->load();
    DownloadManager::downloadManager()->load();

    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(saveAllManagers()));
    timer->start(10000);
}

MainWindow::~MainWindow()
{
    DownloadManager::downloadManager()->deleteLater();
    BookmarksManager::bookmarksManager()->deleteLater();
    HistoryManager::historyManager()->deleteLater();
    TabManager::tabManager()->deleteLater();
    NetworkAccessManager::networkAccessManager()->deleteLater();
    SettingsManager::settingsManager()->deleteLater();
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    saveAllManagers();

    foreach(QWidget * window, qApp->topLevelWidgets())
    {
        if(window != this)
        {
            window->close();
        }
    }
    event->accept();
}

void MainWindow::resizeEvent(QResizeEvent * /*event*/)
{
    SettingsManager::settingsManager()->setMainWindowGeometry(geometry());
}

void MainWindow::moveEvent(QMoveEvent * /*event*/)
{
    SettingsManager::settingsManager()->setMainWindowGeometry(geometry());
}

void MainWindow::saveAllManagers()
{
    DownloadManager::downloadManager()->save();
    BookmarksManager::bookmarksManager()->save();
    HistoryManager::historyManager()->save();
    TabManager::tabManager()->save();
    NetworkAccessManager::networkAccessManager()->save();
    SettingsManager::settingsManager()->save();
}
