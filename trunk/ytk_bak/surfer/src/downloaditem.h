#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class DownloadItem
        : public QObject
{
    Q_OBJECT

public:
    DownloadItem(QNetworkReply * reply, const QUrl & to, QObject * parent = 0);
    bool isFinished() const;
    int progress() const;
    qint64 received() const;
    qint64 total() const;
    QUrl from() const;
    QUrl to() const;

private:
    QNetworkReply * m_reply;
    bool m_isFinished;
    int m_progress;
    qint64 m_received;
    qint64 m_total;
    QUrl m_to;
    QFile m_file;

public slots:
    void abort();

private slots:
    void afterFinish();
    void setProgress(qint64 received, qint64 total);

signals:
    void progressChanged(int progress);
    void finished();
};

#endif // DOWNLOADITEM_H
