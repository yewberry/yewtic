#include "FavoritesModel.h"
#include "TreeNode.h"

FavoritesModel::FavoritesModel(BatDown* app, QObject *parent)
: QAbstractItemModel(parent), BatDownBase(app)
{
	QList<QVariant> rootData;
	rootData<<tr("Bookmark");
	rootNode = new TreeNode(rootData);
	setupModelData();
}

FavoritesModel::~FavoritesModel()
{
	delete rootNode;
}

QModelIndex FavoritesModel::index(int row, int column, const QModelIndex &parent) const
{
	if(!hasIndex(row, column, parent))
		return QModelIndex();

	TreeNode *parentNode;
	if(!parent.isValid())
		parentNode = rootNode;
	else
		parentNode = static_cast<TreeNode*>(parent.internalPointer());

	TreeNode *childNode = parentNode->child(row);
	if(childNode)
		return createIndex(row, column, childNode);
	else
		return QModelIndex();
}

QModelIndex FavoritesModel::parent(const QModelIndex &index) const
{
	if(!index.isValid())
		return QModelIndex();

	TreeNode *childNode = static_cast<TreeNode*>(index.internalPointer());
	TreeNode *parentNode = childNode->parent();

	if(parentNode == rootNode)
		return QModelIndex();

	return createIndex(parentNode->row(), 0, parentNode);
}

QVariant FavoritesModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
		return rootNode->data(section);

	return QVariant();
}

QVariant FavoritesModel::data(const QModelIndex &index, int role) const
{
	if(!index.isValid())
		return QVariant();

	//refer to FavoritesModel::setupModelData for data field order.
	if(role == Qt::DisplayRole){
		TreeNode *node = static_cast<TreeNode*>(index.internalPointer());
		return node->getText();
	}
	if(role == Qt::ToolTipRole){
		TreeNode *node = static_cast<TreeNode*>(index.internalPointer());
		QStringList headers;
		headers<<"Title"<<"Url";
		QString tip, key, value;
		tip = "<table>";
		for (int i=0,len=headers.count(); i<len; ++i) {
			key = headers.at(i);
			value = node->data(i+2).toString();
			if (!value.isEmpty()) 
				tip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(key, value);
		}
		tip += "</table>";
		return tip;
	}

	return QVariant();
}

int FavoritesModel::rowCount(const QModelIndex &parent) const
{
	TreeNode *parentNode;
	if(parent.column() > 0)
		return 0;

	if (!parent.isValid())
		parentNode = rootNode;
	else
		parentNode = static_cast<TreeNode*>(parent.internalPointer());

	return parentNode->childCount();
}

int FavoritesModel::columnCount(const QModelIndex &parent) const
{
	if(parent.isValid())
		return static_cast<TreeNode*>(parent.internalPointer())->columnCount();
	else
		return rootNode->columnCount();
}

Qt::ItemFlags FavoritesModel::flags(const QModelIndex &index) const
{
	if(!index.isValid())
		return 0;

	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

void FavoritesModel::setupModelData()
{
	records = m_pApp->getDbMgr().query("SELECT id,pid,title,url,type,script_file FROM btdl_favs");

	QMap<QString, TreeNode*> map;
	for(int i=0,len=records.size(); i<len; ++i){
		QStringList dat = records.at(i);
		QString id = dat.at(0);
		QList<QVariant> _d;
		for(int j=0,len=dat.count(); j<len; ++j){
			_d<<dat.at(j);
		}
		TreeNode *node = new TreeNode(_d);
		map.insert(id, node);
	}

	for(int i=0,len=records.size(); i<len; ++i){
		QStringList dat = records.at(i);
		QString id = dat.at(0);
		QString pid = dat.at(1);

		TreeNode *node = map.value(id);
		TreeNode *parentNode = pid==id?rootNode:map.value(pid);
		parentNode->appendChild(node);
		node->setParent(parentNode);
	}
}