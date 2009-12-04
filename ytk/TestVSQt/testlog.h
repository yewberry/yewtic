#ifndef TESTLOG_H
#define TESTLOG_H

#include <QtGui/QDialog>

class TestLog : public QDialog
{
	Q_OBJECT

public:
	TestLog(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestLog();

private:
};

#endif // TESTLOG_H
