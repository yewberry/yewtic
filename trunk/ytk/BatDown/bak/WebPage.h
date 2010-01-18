#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QtWebKit>

class WebPage : public QWebPage
{
    Q_OBJECT

public:
    WebPage(QObject * parent = 0);

};

#endif // WEBPAGE_H
