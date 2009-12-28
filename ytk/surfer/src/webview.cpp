#include "webview.h"
#include "tabmanager.h"
#include "historymanager.h"
#include "historyitem.h"
#include "tab.h"
#include "settingsmanager.h"
#include "webpage.h"

WebView::WebView(const QUrl & url, QWidget * parent)
        : QWebView(parent)
{
    m_webPage = new WebPage(this);
    setPage(m_webPage);

    m_initialUrl = url;

    load(url);

    m_copyShortcut = new QShortcut(QKeySequence::Copy, this);

    connect(this, SIGNAL(urlChanged(const QUrl &)), this, SLOT(updateHistory()));
    connect(m_copyShortcut, SIGNAL(activated()), this, SLOT(copySelectedText()));
}

QUrl WebView::url()
{
    QUrl url = QWebView::url();
    if(url != QUrl())
    {
        return url;
    }
    else
    {
        return m_initialUrl;
    }
}

QWebView * WebView::createWindow(QWebPage::WebWindowType /*type*/)
{
    return TabManager::tabManager()->addTab(QUrl())->webView();
}

void WebView::load(const QUrl & url)
{
    QWebView::load(url);
}

void WebView::setZoom(int percent)
{
    setZoomFactor(percent / 100.0);
}

void WebView::find(const QString & text, bool forward, bool caseSensitive)
{
    QWebPage::FindFlags flags = QWebPage::FindWrapsAroundDocument;
    if(!forward)
    {
        flags = flags | QWebPage::FindBackward;
    }
    if(caseSensitive)
    {
        flags = flags | QWebPage::FindCaseSensitively;
    }
    findText(text, flags);
}

void WebView::updateHistory()
{
    if(!SettingsManager::settingsManager()->isPrivateBrowsingEnabled())
    {
        QWebHistoryItem webItem = history()->currentItem();
        HistoryManager::historyManager()->addItem(webItem.url(), webItem.title());
    }
}

void WebView::copySelectedText()
{
    triggerPageAction(QWebPage::Copy);
}
