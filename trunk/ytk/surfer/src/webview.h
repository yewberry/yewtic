#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class TabManager;
class Tab;
class HistoryManager;
class HistoryItem;
class SettingsManager;
class WebPage;

class WebView
        : public QWebView
{
    Q_OBJECT

public:
    WebView(const QUrl & url, QWidget * parent = 0);
    QUrl url();

protected:
    QWebView * createWindow(QWebPage::WebWindowType type);

private:
    QUrl m_initialUrl;
    WebPage * m_webPage;
    QShortcut * m_copyShortcut;

public slots:
    void load(const QUrl & url);
    void setZoom(int percent);
    void find(const QString & text, bool forward, bool caseSensitive);

private slots:
    void updateHistory();
    void copySelectedText();
};

#endif // WEBVIEW_H
