#ifndef DOWNLOADITEMWIDGET_H
#define DOWNLOADITEMWIDGET_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class DownloadManager;
class DownloadItem;

class DownloadItemWidget
        : public QWidget
{
    Q_OBJECT

public:
    DownloadItemWidget(DownloadItem * item, QWidget * parent = 0);

private:
    DownloadItem * m_item;
    QLineEdit * m_fromEdit;
    QLineEdit * m_toEdit;
    QProgressBar * m_progressBar;
    QAction * m_abortAction;

public slots:
    void updateProgress();
};

#endif // DOWNLOADITEMWIDGET_H
