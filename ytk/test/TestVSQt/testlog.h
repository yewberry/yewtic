#ifndef TESTLOG_H
#define TESTLOG_H

#include "common.h"
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE
class QPushButton;
class QTextEdit;
QT_END_NAMESPACE

class TestLog : public QDialog
{
	Q_OBJECT

public:
	TestLog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestLog();

private slots:
	void dbgBtnClicked();
	void infoBtnClicked();
	void warnBtnClicked();
	void errBtnClicked();
	void fatalBtnClicked();

private:
	void initLogger();
	Logger logger;

	QPushButton *dbgBtn;
	QPushButton *infoBtn;
	QPushButton *warnBtn;
	QPushButton *errBtn;
	QPushButton *fatalBtn;
	QTextEdit	*text;
};

#endif // TESTLOG_H
