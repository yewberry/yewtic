#include "Tab.h"
#include "WebView.h"

Tab::Tab(BatDown *app, QWidget *parent)
: QWidget(parent), BatDownBase(app)
{
    m_pWebView = new WebView(m_pApp, this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(m_pWebView);
	setLayout(layout);

    connect(m_pWebView, SIGNAL(titleChanged(const QString &)), this, SLOT(updateTitle()));
    connect(m_pWebView, SIGNAL(iconChanged()), this, SLOT(updateIcon()));
    connect(m_pWebView, SIGNAL(loadProgress(int)), this, SLOT(updateProgress(int)));
}

QUrl Tab::url() const
{
    return m_pWebView->url();
}

QString Tab::title() const
{
    return m_pWebView->title();
}

WebView* Tab::webView() const
{
    return m_pWebView;
}

void Tab::reload()
{
    m_pWebView->reload();
}

void Tab::load(const QUrl &url, const QString &scriptFilename)
{
	m_pWebView->openUrl(url, scriptFilename);
}

void Tab::updateTitle()
{
    QTabWidget *widget = qobject_cast<QTabWidget *>(parentWidget()->parentWidget());
    if(widget){
        QString text = m_pWebView->title();
        if(text.length() > 30){
            text.truncate(27);
            text += "...";
        }
        widget->setTabText(widget->indexOf(this), text);
        widget->setTabToolTip(widget->indexOf(this), m_pWebView->title());
    }
}

void Tab::updateIcon()
{
    QTabWidget *widget = qobject_cast<QTabWidget *>(parentWidget()->parentWidget());
    if(widget)
    {
        QIcon icon = m_pWebView->icon();
        if(icon.isNull()){
            icon = QIcon(":/BatDown/defaultPageIcon.png");
        }
        widget->setTabIcon(widget->indexOf(this), icon);
    }
}

void Tab::updateProgress(int p)
{
	QLabel *statusBarField = this->m_pApp->getWebProgress();
	if(p <= 0 || p >= 100){
		statusBarField->setText("Done");
	} else {
		statusBarField->setText(QString("%1%").arg(p));
	}
}