#ifndef DOWNLOADDIALOG_H
#define DOWNLOADDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class DownloadView;
class DownloadManager;
class SettingsManager;

class DownloadDialog
        : public QDialog
{
    Q_OBJECT

public:
    DownloadDialog();

protected:
    void resizeEvent(QResizeEvent * event);
    void moveEvent(QMoveEvent * event);

private:
    DownloadView * m_view;
    QPushButton * m_clearButton;
};

#endif // DOWNLOADDIALOG_H
