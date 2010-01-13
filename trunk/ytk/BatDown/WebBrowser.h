#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QtGui/QWidget>
#include "BatDown.h"

class QWebView;
class QLineEdit;

class WebBrowser : public QWidget, public BatDownBase
{
	Q_OBJECT

public:
	WebBrowser(BatDown* app, QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebBrowser(void);

	void openUrl(const QString &url);
	void openUrl(const QString &url, const QString &scriptFilename);

public slots:
	void procPostLists(const QString &jsonStr);
	//void procPostMusic

	void setProperty(const QString &name, const QString &value);
	QString getProperty(const QString &name);
	void removeProperty(const QString &name);

	void logInfo(const QString &msg);
	void logDebug(const QString &msg);
	void populateJavaScriptWindowObject();

protected slots:
	void setProgress(int);
	void adjustLocation();
	void finishLoading(bool);
	
private:
	void evalStepScript(const QString &stepName);
	void evalScript(const QString &script);

	QMap<QString, QString> getScripts(const QString &scriptFilename);

private:
	QString		m_jsLib;
	QString		m_script;
	QMap<QString, QString> m_props;

	QWebView	*m_pWebView;
	QLineEdit	*m_pAddrBar;
};


#endif // WEBBROWSER_H