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


class ServerViewNode;

class ServerView : public QWidget
{
	Q_OBJECT
public:
	ServerView(QWidget *parent = 0);
	~ServerView();

	void loadFromDb();
	void clearScene();

protected:
	void contextMenuEvent(QContextMenuEvent * event);

private slots:
    void addServer();
    void deleteItem();
    void activeServer();
    void activeServer(ServerViewNode* node);

    void updateActions();
    ServerViewNode* addItem(QString id, QString ip, QString name);

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
