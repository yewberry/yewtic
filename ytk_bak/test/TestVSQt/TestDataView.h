#ifndef TESTDATAVIEW_H
#define TESTDATAVIEW_H

#include "common.h"
#include <QtGui/QDialog>

class QListWidgetItem;
class QListWidget;
class QStackedWidget;

class TestDataView : public QDialog
{
	Q_OBJECT

public:
	TestDataView(QWidget *parent = 0, Qt::WFlags flags = 0);
	~TestDataView(void);

private:
	void createList();
	void createPages();

public slots:
	void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
	QListWidget *list;
	QStackedWidget *pages;

};

class DirModelPage : public QWidget
{
	Q_OBJECT
public:
	DirModelPage(QWidget *parent = 0);
};

class ListViewPage : public QWidget
{
	Q_OBJECT
public:
	ListViewPage(QWidget *parent = 0);
};

#endif // TESTDATAVIEW_H