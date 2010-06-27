#include "downloaditem.h"

DownloadItem::DownloadItem(QNetworkReply * reply, const QUrl & to, QObject * parent)
        : QObject(parent)
        , m_reply(reply)
        , m_isFinished(false)
        , m_progress(0)
        , m_received(0)
        , m_total(0)
        , m_to(to)
        , m_file(to.toString())
{
    if(!m_file.open(QIODevice::WriteOnly))
    {
        abort();
    }

    connect(m_reply, SIGNAL(downloadProgress(qint64, qint64)),
            this, SLOT(setProgress(qint64, qint64)));
    connect(m_reply, SIGNAL(finished()), this, SLOT(afterFinish()));
}

bool DownloadItem::isFinished() const
{
    return m_isFinished;
}

int DownloadItem::progress() const
{
    return m_progress;
}

qint64 DownloadItem::received() const
{
    return m_received;
}

qint64 DownloadItem::total() const
{
    return m_total;
}

QUrl DownloadItem::from() const
{
    return m_reply->url();
}

QUrl DownloadItem::to() const
{
    return m_to;
}

void DownloadItem::abort()
{
    m_reply->abort();
}

void DownloadItem::afterFinish()
{
    if(m_reply->error() == QNetworkReply::NoError)
    {
        m_progress = 100;
        m_received = m_total;
        emit progressChanged(m_progress);
    }
    m_isFinished = true;
    emit finished();
    m_file.write(m_reply->readAll());
    m_file.close();
}

void DownloadItem::setProgress(qint64 received, qint64 total)
{
    m_progress = received * 100 / total;
    m_received = received;
    m_total = total;
    emit progressChanged(m_progress);
    m_file.write(m_reply->readAll());
}
