#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include "BatDown.h"

class WebPage;

class WebView : public QWebView, public BatDownBase
{
    Q_OBJECT

public:
    WebView(BatDown *app, QWidget *parent = 0);

protected:
    QWebView * createWindow(QWebPage::WebWindowType type);

private:
	void openUrl(const QString &url);
	void openUrl(const QString &url, const QString &scriptFilename);
	void evalStepScript(const QString &stepName);

public slots:
	void procPostList(const QString &jsonStr);
	QString openPageSilently(const QString &url, const QString &step, const QString &retProp);

	void setProperty(const QString &name, const QString &value);
	QString getProperty(const QString &name);
	void removeProperty(const QString &name);

	void logInfo(const QString &msg);
	void logDebug(const QString &msg);
	void populateJavaScriptWindowObject();

protected slots:
	void finishLoading(bool);
	
private:
	void evalScript(const QString &script);

private:
	QString		m_jsLib;
	QString		m_scriptFilename;
	QString		m_script;
	QMap<QString, QString> m_props;

	WebPage		*m_pWebPage;
};

#endif // WEBVIEW_H
