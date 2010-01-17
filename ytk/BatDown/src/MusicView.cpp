#include "MusicView.h"
#include "QHeaderView.h"

MusicView::MusicView(BatDown *app, QWidget *parent)
: QTableView(parent), BatDownBase(app)
{
	m_pModel = new MusicModel(app);
	setModel(m_pModel);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	horizontalHeader()->setStretchLastSection(true);
	setAlternatingRowColors(true);
	setColumnWidth(0, 300);
	setColumnWidth(1, 45);

	connect( this, SIGNAL(doubleClicked(const QModelIndex &)),this, SLOT(onDblClick(const QModelIndex &)) );
}

MusicView::~MusicView()
{

}

void MusicView::onDblClick(const QModelIndex &idx)
{
}