#include "TreeNode.h"

TreeNode::TreeNode(const QList<QVariant> &data, TreeNode *parent)
{
	nodeData = data;
	parentNode = parent;
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