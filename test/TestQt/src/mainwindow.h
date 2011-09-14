#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void updateStatusBar();
    void about();

    void on_action_New_triggered();
    void other_action_callback();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void createToolBars();
    void createStatusBar();

    void readSettings();
    void writeSettings();

    bool okToContinue();

    enum { MaxRecentFiles = 5 };
};

#endif
