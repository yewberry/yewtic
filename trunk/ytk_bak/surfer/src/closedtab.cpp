#include "closedtab.h"

ClosedTab::ClosedTab(const QUrl & url, const QString & title, QObject * parent)
        : QObject(parent)
        , m_url(url)
        , m_title(title)
{
}

QUrl ClosedTab::url() const
{
    return m_url;
}

QString ClosedTab::title() const
{
    return m_title;
}
