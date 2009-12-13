#include "TestDataView.h"

#include <QtGui/QListWidgetItem>
#include <QtGui/QListWidget>
#include <QtGui/QStackedWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>

TestDataView::TestDataView(QWidget *parent, Qt::WFlags flags)
	: QDialog( parent, flags)
{
	createList();
	createPages();

	QHBoxLayout *lay = new QHBoxLayout;
	lay->addWidget(list);
	lay->addWidget(pages, 1);

	setLayout(lay);
	setWindowTitle(tr("Data View"));
}

TestDataView::~TestDataView(){
}

void TestDataView::createList()
{
	list = new QListWidget;
	list->addItem("Dir Model");
	list->addItem("Other");

	connect(
		list, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
		this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*))
	);
}

void TestDataView::createPages(){
	pages = new QStackedWidget;
	pages->addWidget(new DirModelPage);
	pages->addWidget(new ListViewPage);
}

void TestDataView::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
		current = previous;

	pages->setCurrentIndex(list->row(current));
}


DirModelPage::DirModelPage(QWidget *parent)
{
    QLabel *serverLabel = new QLabel(tr("Server:"));
    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);

    setLayout(serverLayout);
}

ListViewPage::ListViewPage(QWidget *parent)
{
    QLabel *serverLabel = new QLabel(tr("List View:"));
    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(serverLabel);

    setLayout(serverLayout);
}