#ifndef TESTLAYOUT_H
#define TESTLAYOUT_H

#include "common.h"
#include <QtGui/QDialog>

class QListWidgetItem;
class QListWidget;
class QStackedWidget;

class TestLayout : public QDialog
{
	Q_OBJECT

public:
	TestLayout(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestLayout(void);

private:
	void createList();
	void createPages();

public slots:
	void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
	QListWidget *list;
	QStackedWidget *pages;

};

class GridLayoutPage : public QWidget
{
	Q_OBJECT
public:
	GridLayoutPage(QWidget *parent = 0);
};


#endif // TESTLAYOUT_H