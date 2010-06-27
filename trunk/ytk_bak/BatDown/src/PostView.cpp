#include "PostView.h"
#include "QHeaderView.h"

PostView::PostView(BatDown *app, QWidget *parent)
: QTableView(parent), BatDownBase(app)
{
	m_pModel = new PostModel(app);
	setModel(m_pModel);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	horizontalHeader()->setStretchLastSection(true);
	setAlternatingRowColors(true);
	setColumnWidth(0, 45);
	setColumnWidth(1, 300);
	setColumnWidth(2, 45);

	connect( this, SIGNAL(doubleClicked(const QModelIndex &)),this, SLOT(onDblClick(const QModelIndex &)) );
}

PostView::~PostView()
{

}

void PostView::onDblClick(const QModelIndex &idx)
{
}