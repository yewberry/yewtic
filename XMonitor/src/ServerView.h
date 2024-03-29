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
	enum {ACTIVE_SVR_ACT = 1};

	ServerView(QWidget *parent = 0);
	~ServerView();

	void loadFromDb();
	void clearScene();
	void saveScene();
	ServerViewItem* getItemById(QString id);

	QList<QAction*> getActions();

protected:
	void contextMenuEvent(QContextMenuEvent * event);

private slots:
    void addServer();
    void activeServer();
    void activeAllServer();
    void deActiveAllServer();
    void browserSteps();

    void editItem();
    void deleteItem();

    void updateActions();
    ServerViewNode* addItem(QString id);

private:
	void createActions();
	void createMenus();
	void createItemMenus();

	ServerViewItem* selectedItem() const;
	ServerViewNode* selectedNode() const;

private:
    QGraphicsScene*	m_pScene;
    QGraphicsView*	m_pView;

    QAction* m_pAddServerAct;
    QAction* m_pEditServerAct;
    QAction* m_pDeleteItemAct;
    QAction* m_pActiveServerAct;
    QAction* m_pActiveAllServerAct;
    QAction* m_pDeActiveAllServerAct;

    QAction* m_pBrowserStepsAct;

    QMenu*	m_pCtxMenu;
    QMenu*	m_pItemCtxMenu;

    int m_itemCount;

};

#endif /* SERVERVIEW_H_ */
