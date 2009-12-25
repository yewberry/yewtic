#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include "common.h"
#include <QtGui/QWidget>

class QWebView;
class QLineEdit;
class QPushButton;

class WebBrowser : public QWidget
{
	Q_OBJECT

public:
	WebBrowser(QWidget *parent = 0, Qt::WFlags flags = 0);
	~WebBrowser(void);


public slots:
	void populateJavaScriptWindowObject();
	void setValues(const QString &value);

protected slots:
	void finishLoading(bool);

private slots:
	void evalJS();

private:
	Logger logger;

private:
	QString extjs;
	QWebView *view;
	QLineEdit *locationEdit;

	QPushButton *gooBtn;
};


#endif // WEBBROWSER_H