#ifndef HISTORYITEM_H
#define HISTORYITEM_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryItem
        : public QObject
{
    Q_OBJECT

public:
    HistoryItem(const QUrl & url, const QString & title, const QDateTime & visitTime,
                int counter, QObject * parent);
    QUrl url() const;
    QString title() const;
    QDateTime visitTime() const;
    int counter() const;

private:
    QUrl m_url;
    QString m_title;
    QDateTime m_visitTime;
    int m_counter;
};

#endif // HISTORYITEM_H
