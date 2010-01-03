#include "FavoritesView.h"
#include "FavoritesModel.h"
#include "TreeNode.h"
#include "WebBrowser.h"

FavoritesView::FavoritesView(BatDown *app, QWidget *parent)
: QTreeView(parent), BatDownBase(app)
{
	FavoritesModel *favModel = new FavoritesModel(app);
	this->setModel(favModel);

	connect( this, SIGNAL(doubleClicked(const QModelIndex &)),this, SLOT(onDblClick(const QModelIndex &)) );
}

FavoritesView::~FavoritesView()
{

}

void FavoritesView::onDblClick(const QModelIndex &idx)
{
	TreeNode *node = static_cast<TreeNode*>(idx.internalPointer());
	QString msg = QString::fromLocal8Bit("´ò¿ªµØÖ·:%1").arg(node->getUrl());
	yINFO((const char *)msg.toLocal8Bit());
	WebBrowser *wb = m_pApp->getWebBrowser();
	wb->openUrl(node->getUrl());
}