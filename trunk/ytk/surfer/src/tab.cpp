#include "tab.h"
#include "toolbar.h"
#include "adressbar.h"
#include "webview.h"
#include "searchbar.h"
#include "statusbar.h"

Tab::Tab(const QUrl & url, QWidget * parent)
        : QWidget(parent)
{
    m_webView = new WebView(url, this);
    m_toolBar = new ToolBar(m_webView->history(), url, this);
    m_searchBar = new SearchBar(this);
    m_statusBar = new StatusBar(this);
    m_layout = new QVBoxLayout(this);
    m_layout->setMargin(0);
    m_layout->setSpacing(0);
    m_layout->addWidget(m_toolBar, 0);
    m_layout->addWidget(m_webView, 1);
    m_layout->addWidget(m_searchBar, 0);
    m_layout->addWidget(m_statusBar, 0);

    m_showSearchShortcut = new QShortcut(QKeySequence::Find, this);
    m_focusAdressShortcut = new QShortcut(Qt::Key_F6, this);

    m_searchBar->hide();

    connect(m_toolBar, SIGNAL(goBackRequsted()), m_webView, SLOT(back()));
    connect(m_toolBar, SIGNAL(goForwardRequsted()), m_webView, SLOT(forward()));
    connect(m_toolBar, SIGNAL(reloadRequsted()), m_webView, SLOT(reload()));
    connect(m_toolBar, SIGNAL(stopRequsted()), m_webView, SLOT(stop()));
    connect(m_toolBar, SIGNAL(loadRequsted(const QUrl &)), m_webView, SLOT(load(const QUrl &)));
    connect(m_toolBar, SIGNAL(loadRequsted(const QUrl &)), m_webView, SLOT(setFocus()));
    connect(m_webView, SIGNAL(urlChanged(const QUrl &)), m_toolBar, SLOT(setUrl(const QUrl &)));
    connect(m_webView, SIGNAL(urlChanged(const QUrl &)), m_toolBar, SLOT(updateActions()));
    connect(m_webView, SIGNAL(loadStarted()), m_toolBar, SLOT(enableStopAction()));
    connect(m_webView, SIGNAL(loadFinished(bool)), m_toolBar, SLOT(disableStopAction()));
    connect(m_webView, SIGNAL(titleChanged(const QString &)), this, SLOT(updateTitle()));
    connect(m_webView, SIGNAL(iconChanged()), this, SLOT(updateIcon()));
    connect(m_searchBar, SIGNAL(searchDataChanged(const QString &, bool, bool)),
            m_webView, SLOT(find(const QString &, bool, bool)));
    connect(m_searchBar, SIGNAL(closeRequested()), m_searchBar, SLOT(hide()));
    connect(m_searchBar, SIGNAL(closeRequested()), m_webView, SLOT(setFocus()));
    connect(m_webView->page(), SIGNAL(linkHovered(const QString &,const QString &,const QString &)),
            m_statusBar, SLOT(showMessage(const QString &)));
    connect(m_webView, SIGNAL(loadProgress(int)), m_statusBar->progressBar(), SLOT(setValue(int)));
    connect(m_statusBar->slider(), SIGNAL(valueChanged(int)), m_webView, SLOT(setZoom(int)));
    connect(m_showSearchShortcut, SIGNAL(activated()), m_searchBar, SLOT(show()));
    connect(m_focusAdressShortcut, SIGNAL(activated()), m_toolBar->adressBar(), SLOT(setFocus()));
}

QUrl Tab::url() const
{
    return m_webView->url();
}

QString Tab::title() const
{
    return m_webView->title();
}

WebView * Tab::webView() const
{
    return m_webView;
}

void Tab::reload()
{
    m_webView->reload();
}

void Tab::load(const QUrl & url)
{
    m_webView->load(url);
}

void Tab::updateTitle()
{
    QTabWidget * widget = qobject_cast<QTabWidget *>(parentWidget()->parentWidget());
    if(widget)
    {
        QString text = m_webView->title();
        if(text.length() > 30)
        {
            text.truncate(27);
            text += "...";
        }
        widget->setTabText(widget->indexOf(this), text);
        widget->setTabToolTip(widget->indexOf(this), m_webView->title());
    }
}

void Tab::updateIcon()
{
    QTabWidget * widget = qobject_cast<QTabWidget *>(parentWidget()->parentWidget());
    if(widget)
    {
        QIcon icon = m_webView->icon();
        if(icon.isNull())
        {
            icon = QIcon(":/defaultPageIcon.png");
        }
        widget->setTabIcon(widget->indexOf(this), icon);
    }
}
