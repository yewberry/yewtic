#include "TestLayout.h"

#include <QtGui/QListWidgetItem>
#include <QtGui/QListWidget>
#include <QtGui/QStackedWidget>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>

TestLayout::TestLayout(QWidget *parent, Qt::WFlags flags)
	: QDialog( parent, flags)
{
	createList();
	createPages();

	QHBoxLayout *lay = new QHBoxLayout;
	lay->addWidget(list, 1);
	lay->addWidget(pages, 2);

	setLayout(lay);
	setWindowTitle(tr("Data View"));
	resize(600, 400);
}

TestLayout::~TestLayout(){
}

void TestLayout::createList()
{
	list = new QListWidget;
	list->addItem("Grid Layout");

	connect(
		list, SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
		this, SLOT(changePage(QListWidgetItem *, QListWidgetItem*))
	);
}

void TestLayout::createPages(){
	pages = new QStackedWidget;
	pages->addWidget(new GridLayoutPage);

}

void TestLayout::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
	if (!current)
		current = previous;

	pages->setCurrentIndex(list->row(current));
}


GridLayoutPage::GridLayoutPage(QWidget *parent)
{
    QGridLayout *lay = new QGridLayout(this);
    QTextEdit *txt = new QTextEdit(this);
	lay->addWidget(txt, 0, 0, 1, 2);

	QPushButton *btn = new QPushButton("BTN", this);
	lay->addWidget(btn, 1, 1);
	lay->setColumnStretch(0, 1);
}