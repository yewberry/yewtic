#ifndef DOWNLOADVIEW_H
#define DOWNLOADVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class DownloadManager;
class DownloadItem;
class DownloadItemDelegate;
class DownloadItemWidget;

class DownloadView
        : public QListView
{
    Q_OBJECT

public:
    DownloadView(QWidget * parent = 0);

private:
    DownloadItemDelegate * m_delegate;
    QList<DownloadItemWidget *> m_widgets;

private slots:
    void handleNewItem();
    void handleDeletedItem(int index);
};

#endif // DOWNLOADVIEW_H
