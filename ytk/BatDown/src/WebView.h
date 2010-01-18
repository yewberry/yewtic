#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include "BatDown.h"

class QWebPage;
class Tab;

class WebView : public QWebView, public BatDownBase
{
    Q_OBJECT

public:
    WebView(BatDown *app, QWidget *parent = 0);
	void openUrl(const QUrl &url);
	void openUrl(const QUrl &url, const QString &scriptFilename);

protected:
    QWebView * createWindow(QWebPage::WebWindowType type);

private:
	void evalStepScript(const QString &stepName);

public slots:
	void procPostList(const QString &jsonStr);
	void openSubTabs(const QString &jsonStr, const QString &step, int numOfTabsATime = 1);

	void setProperty(const QString &name, const QString &value);
	QString getProperty(const QString &name);
	void removeProperty(const QString &name);

	void logInfo(const QString &msg);
	void logDebug(const QString &msg);
	void logError(const QString &msg);
	
	void populateJavaScriptWindowObject();

protected slots:
	void finishLoading(bool);
	
private:
	void evalScript(const QString &script);

private:
	QString		m_jsLib;
	QString		m_scriptFilename;
	QString		m_script;
	QMap<QString, QString>
				m_props;

	QWebPage	*m_pWebPage;
	QMap<QString, Tab*>
				m_subTabs;
};

#endif // WEBVIEW_H
