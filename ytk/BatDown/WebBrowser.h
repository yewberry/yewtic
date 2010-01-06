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
	void setProperty(const QString &name, const QString &value);
	QString getProperty(const QString &name);
	void logInfo(const QString &msg);

protected slots:
	void setProgress(int);
	void adjustLocation();
	void finishLoading(bool);
	
private:
	void evalJS(const QString &code);
	void evalStepScript(const QString &stepName);
	QString curStep();

private:
	QString		m_jsLib;
	QMap<QString, QString> m_props;

	QMap<QString, QString> m_steps;
	QMap<QString, QString> m_stepTests;
	QString m_stepFuncs;
	QStringList	m_stepSeq;

	QWebView	*m_pWebView;
	QLineEdit	*m_pAddrBar;
};


#endif // WEBBROWSER_H