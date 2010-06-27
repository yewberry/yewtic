#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include "ui_settingsdialog.h"

class SettingsManager;

class SettingsDialog
        : public QDialog
        , private Ui::SettingsDialog
{
    Q_OBJECT

public:
    SettingsDialog();

protected:
    void showEvent(QShowEvent * event);
    void resizeEvent(QResizeEvent * event);
    void moveEvent(QMoveEvent * event);

private slots:
    void openNewDirectory();

public slots:
    void defaults();
    void ok();
    void apply();
};

#endif // SETTINGSDIALOG_H
