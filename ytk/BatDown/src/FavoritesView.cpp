#include "FavoritesView.h"
#include "FavoritesModel.h"
#include "TreeNode.h"
#include "WebPage.h"

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

	//TODO change to full functional web browser
	WebPage *wb = m_pApp->getWebPage();
	wb->openUrl(node->getUrl(), node->getScriptFilename());
}