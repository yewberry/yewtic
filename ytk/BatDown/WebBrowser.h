#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QtGui/QWidget>
#include "BatDown.h"

class QWebView;
class QLineEdit;
class QPushButton;

class WebBrowser : public QWidget, public BatDownBase
{
	Q_OBJECT

public:
	WebBrowser(BatDown* app, QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebBrowser(void);

	void openUrl(const QString &url);
	void openUrl(const QString &url, const QString &scriptFilename);

public slots:
	void populateJavaScriptWindowObject();
	void setValues(const QString &value);

protected slots:
	void finishLoading(bool);

private slots:
	void evalJS();

private:
	QString		m_jsLib;
	QWebView	*m_pWebView;
	QLineEdit	*m_pAddrBar;
};


#endif // WEBBROWSER_H