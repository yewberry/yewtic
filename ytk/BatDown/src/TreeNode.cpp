#include "TreeNode.h"

TreeNode::TreeNode(const QList<QVariant> &data, TreeNode *parent)
{
	nodeData = data;
	parentNode = parent;

	//refer to FavoritesModel::setupModelData for data field order.
	//SELECT id,pid,title,url FROM btdl_favs
	if(!data.isEmpty() && data.count()>3){
		m_id		= data.at(0).toString();
		m_pid		= data.at(1).toString();
		m_text		= data.at(2).toString();
		m_url		= data.at(3).toString();
		m_type		= data.at(4).toString();
		m_script	= data.at(5).toString();
	}
}

TreeNode::~TreeNode(void)
{
	qDeleteAll(children);
}

void TreeNode::appendChild(TreeNode *child)
{
	children.append(child);
}

void TreeNode::setParent(TreeNode *parent)
{
	parentNode = parent;
}

TreeNode* TreeNode::child(int row)
{
	return children.value(row);
}

TreeNode* TreeNode::parent()
{
	return parentNode;
}

int TreeNode::childCount() const
{
	return children.count();
}

int TreeNode::columnCount() const
{
	return nodeData.count();
}

 int TreeNode::row() const
 {
     if (parentNode)
         return parentNode->children.indexOf(const_cast<TreeNode*>(this));

     return 0;
 }

QVariant TreeNode::data(int column) const
{
	return nodeData.value(column);
}

QString TreeNode::getId() const
{
	return m_id;
}

QString TreeNode::getPid() const
{
	return m_pid;
}
QString TreeNode::getText() const
{
	return m_text;
}
QString TreeNode::getUrl() const
{
	return m_url;
}
QString TreeNode::getType() const
{
	return m_type;
}
QString TreeNode::getScriptFilename() const
{
	return m_script;
}