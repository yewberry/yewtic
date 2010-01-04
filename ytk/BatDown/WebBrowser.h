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
	void evalJS(const QString &code);
	void evalScripts();

public slots:
	void populateJavaScriptWindowObject();
	void setProperty(const QString &name, const QString &value);
	QString getProperty(const QString &name);

protected slots:
	void finishLoading(bool);
	
private:
	QString		m_jsLib;
	QMap<QString, QString> m_props;
	QMap<QString, QString> m_steps;
	QStringList	m_stepSeq;

	QWebView	*m_pWebView;
	QLineEdit	*m_pAddrBar;
};


#endif // WEBBROWSER_H