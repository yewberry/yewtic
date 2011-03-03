/*
 * ServerView.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef SERVERVIEW_H_
#define SERVERVIEW_H_

#include <QDialog>
#include <QMenu>
#include "Comm.h"
#include <QGraphicsScene>
#include <QGraphicsView>

#include "ServerViewItem.h"
#include "ServerViewNode.h"

class ServerView : public QWidget
{
	Q_OBJECT
public:
	ServerView(QWidget *parent = 0);
	~ServerView();

	void loadFromDb();
	void clearScene();
	void saveScene();
	ServerViewItem* getItemById(QString id);

protected:
	void contextMenuEvent(QContextMenuEvent * event);

private slots:
    void addServer();
    void deleteItem();
    void activeServer();
    void activeServer(ServerViewNode* node);

    void updateActions();
    ServerViewNode* addItem(QString id);

private:
	void createActions();
	void createMenus();
	void createItemMenus();

	ServerViewNode* selectedNode() const;

private:
    QGraphicsScene*	m_pScene;
    QGraphicsView*	m_pView;

    QAction* m_pAddServerAct;
    QAction* m_pEditServerAct;
    QAction* m_pDeleteItemAct;
    QAction* m_pActiveServerAct;
    QAction* m_pDeActiveServerAct;

    QMenu*	m_pCtxMenu;
    QMenu*	m_pItemCtxMenu;

    int m_itemCount;

};

#endif /* SERVERVIEW_H_ */
