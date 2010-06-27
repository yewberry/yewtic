#ifndef TESTQTWEBKIT_H
#define TESTQTWEBKIT_H

#include "common.h"
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE
class QWebView;
class QLineEdit;
QT_END_NAMESPACE

class TestQtWebKit : public QDialog
{
	Q_OBJECT

public:
	TestQtWebKit(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestQtWebKit(void);


public slots:
	void populateJavaScriptWindowObject();
	void setValues(const QString &value);

protected slots:
	void finishLoading(bool);

private slots:
	void evalJS();

private:
	void initLogger();
	Logger logger;

private:
	QString extjs;
	QWebView *view;
	QLineEdit *locationEdit;

	QPushButton *gooBtn;
};


#endif // TESTQTWEBKIT_H