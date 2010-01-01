#ifndef TREENODE_H
#define TREENODE_H

#include <QList>
#include <QVariant>

class TreeNode
{
public:
	TreeNode(const QList<QVariant> &data, TreeNode *parent = 0);
	~TreeNode(void);

	void appendChild(TreeNode *child);
	void setParent(TreeNode *parent);
	TreeNode* child(int row);
	TreeNode* parent();

	int childCount() const;
	int columnCount() const;
	int row() const;
	QVariant data(int column) const;

private:
	QList<TreeNode*> children;
	QList<QVariant> nodeData;
	TreeNode *parentNode;
};

#endif //TREENODE_H