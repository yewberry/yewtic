#ifndef ADRESSBAR_H
#define ADRESSBAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class HistoryManager;

class AdressBar
        : public QLineEdit
{
    Q_OBJECT

public:
    AdressBar(const QUrl & url, QWidget * parent = 0);
    QUrl url() const;

private:
    QTreeView * m_view;

public slots:
    void setUrl(const QUrl & url);

private slots:
    void load();

signals:
    void loadRequsted(const QUrl & url);
};

#endif // ADRESSBAR_H
