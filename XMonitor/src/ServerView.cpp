/*
 * ServerView.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#include <QtGui>
#include "ServerView.h"
#include "ServerViewNode.h"

ServerView::ServerView(QWidget *parent) :
	QWidget(parent) {
	m_pScene = new QGraphicsScene(0, 0, 5000, 5000);

	m_pView = new QGraphicsView;
	m_pView->setScene(m_pScene);
	m_pView->setDragMode(QGraphicsView::RubberBandDrag);
	m_pView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
	m_pView->setContextMenuPolicy(Qt::ActionsContextMenu);

	QHBoxLayout *hLay = new QHBoxLayout(this);
	hLay->addWidget(m_pView);
	this->setLayout(hLay);

	createActions();
	connect(m_pScene, SIGNAL(selectionChanged()), this, SLOT(updateActions()));

}

ServerView::~ServerView() {
	// TODO Auto-generated destructor stub
}

void ServerView::addNode(const Server &svr) {
	ServerViewNode *node = new ServerViewNode;
	node->text("haha");
	m_pScene->addItem(node);
}

void ServerView::addServer(){

}

void ServerView::deleteItem(){

}

void ServerView::createActions() {
	m_pAddServerAct = new QAction(tr("Add &Node"), this);
	m_pAddServerAct->setIcon(QIcon(":/images/add_server.png"));
	m_pAddServerAct->setShortcut(tr("Ctrl+N"));
	connect(m_pAddServerAct, SIGNAL(triggered()), this, SLOT(addServer()));

	m_pDeleteItemAct = new QAction(tr("&Delete"), this);
	m_pDeleteItemAct->setIcon(QIcon(":/images/delete.png"));
	m_pDeleteItemAct->setShortcut(tr("Ctrl+D"));
	connect(m_pDeleteItemAct, SIGNAL(triggered()), this, SLOT(deleteItem()));
}

void ServerView::createMenus()
{
    m_pEditMenu = new QMenu;
    m_pEditMenu->addAction(m_pAddServerAct);
    m_pEditMenu->addAction(m_pDeleteItemAct);
    m_pEditMenu->addSeparator();

}

void ServerView::updateActions() {
	bool hasSelection = !m_pScene->selectedItems().isEmpty();
	bool isNode = (selectedNode() != 0);

	m_pDeleteItemAct->setEnabled(hasSelection);
	foreach (QAction *action, m_pView->actions()){
		m_pView->removeAction(action);
	}

	foreach (QAction *action, m_pEditMenu->actions()){
		if (action->isEnabled())
			m_pView->addAction(action);
	}
}

ServerViewNode* ServerView::selectedNode() const {
	QList<QGraphicsItem *> items = m_pScene->selectedItems();
	if (items.count() == 1) {
		return dynamic_cast<ServerViewNode *> (items.first());
	} else {
		return 0;
	}
}
