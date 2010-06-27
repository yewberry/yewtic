#ifndef TREENODE_H
#define TREENODE_H

#include <QList>
#include <QVariant>

class TreeNode
{
public:
	TreeNode(const QList<QVariant> &data = QList<QVariant>() , TreeNode *parent = 0);
	~TreeNode(void);

	void appendChild(TreeNode *child);
	void setParent(TreeNode *parent);
	TreeNode* child(int row);
	TreeNode* parent();

	int childCount() const;
	int columnCount() const;
	int row() const;

	QVariant data(int column) const;
	QString getId() const;
	QString getPid() const;
	QString getText() const;
	QString getUrl() const;
	QString getType() const;
	QString getScriptFilename() const;

private:
	QList<TreeNode*> children;
	QList<QVariant> nodeData;
	TreeNode *parentNode;

	QString	m_id;
	QString m_pid;
	QString m_text;
	QString m_url;
	QString	m_type;
	QString m_script;
};

#endif //TREENODE_H