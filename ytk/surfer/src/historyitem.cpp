#include "historyitem.h"

HistoryItem::HistoryItem(const QUrl & url, const QString & title, const QDateTime & visitTime,
                         int counter, QObject * parent)
        : QObject(parent)
        , m_url(url)
        , m_title(title)
        , m_visitTime(visitTime)
        , m_counter(counter)
{
}

QUrl HistoryItem::url() const
{
    return m_url;
}

QString HistoryItem::title() const
{
    return m_title;
}

QDateTime HistoryItem::visitTime() const
{
    return m_visitTime;
}

int HistoryItem::counter() const
{
    return m_counter;
}
