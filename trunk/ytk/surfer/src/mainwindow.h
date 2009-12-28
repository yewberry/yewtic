#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class TabWidget;
class TabManager;
class HistoryManager;
class BookmarksManager;
class SettingsManager;
class DownloadManager;
class NetworkAccessManager;

class MainWindow
        : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event);
    void resizeEvent(QResizeEvent * event);
    void moveEvent(QMoveEvent * event);

private:
    QWidget * m_centralWidget;
    TabWidget * m_tabWidget;
    QShortcut * m_exitShortcut;

private slots:
    void saveAllManagers();
};

#endif // MAINWINDOW_H
