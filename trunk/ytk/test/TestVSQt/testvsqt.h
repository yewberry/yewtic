#ifndef TESTVSQT_H
#define TESTVSQT_H

#include <QtGui/QDialog>
#include "ui_testvsqt.h"

class TestVSQt : public QDialog
{
	Q_OBJECT

public:
	TestVSQt(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestVSQt();

private slots:
	void testLogClicked();
	void testWebKitClicked();
	void testDbusClicked();

private:
	void testLog();

private:
	Ui::TestVSQtClass ui;
};

#endif // TESTVSQT_H
