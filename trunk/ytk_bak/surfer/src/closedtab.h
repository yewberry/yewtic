#ifndef CLOSEDTAB_H
#define CLOSEDTAB_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class ClosedTab
        : public QObject
{
    Q_OBJECT

public:
    ClosedTab(const QUrl & url, const QString & title, QObject * parent = 0);
    QUrl url() const;
    QString title() const;

private:
    QUrl m_url;
    QString m_title;
};

#endif // CLOSEDTAB_H
