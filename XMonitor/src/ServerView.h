/*
 * ServerView.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef SERVERVIEW_H_
#define SERVERVIEW_H_

#include <QWidget>
#include <QMenu>
#include "Server.h"

#include <QGraphicsScene>
#include <QGraphicsView>

class ServerViewNode;

class ServerView : public QWidget
{
	Q_OBJECT
public:
	ServerView(QWidget *parent = 0);
	~ServerView();

	void addNode(const Server &svr);

private slots:
    void addServer();
    void deleteItem();
    void updateActions();

private:
	void createActions();
	void createMenus();

	ServerViewNode* selectedNode() const;

private:
    QGraphicsScene*	m_pScene;
    QGraphicsView*	m_pView;

    QAction* m_pAddServerAct;
    QAction* m_pDeleteItemAct;

    QMenu*	m_pEditMenu;
};

#endif /* SERVERVIEW_H_ */
