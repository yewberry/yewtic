/*
 * ServerView.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#include <QtGui>
#include "ServerView.h"
#include "ServerForm.h"

ServerView::ServerView(QWidget *parent) :
	QWidget(parent), m_pCtxMenu(0), m_itemCount(0) {
	m_pScene = new QGraphicsScene(0, 0, 300, 200);

	m_pView = new QGraphicsView;
	m_pView->setScene(m_pScene);
	m_pView->setDragMode(QGraphicsView::RubberBandDrag);
	m_pView->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

	QHBoxLayout *hLay = new QHBoxLayout(this);
	hLay->addWidget(m_pView);
	this->setLayout(hLay);

	createActions();
	createMenus();

	connect(m_pScene, SIGNAL(selectionChanged()), this, SLOT(updateActions()));

}

ServerView::~ServerView() {
	// TODO Auto-generated destructor stub
}

void ServerView::contextMenuEvent(QContextMenuEvent * event) {
	m_pCtxMenu->exec(QCursor::pos());
}

void ServerView::loadFromDb() {
	yDEBUG("Load server nodes...");
	ServerForm form;
	QSqlTableModel *model = form.model();
	for (int row = 0; row < model->rowCount(); ++row) {
		QSqlRecord record = model->record(row);
		ServerViewNode *node = addItem( record.value(ServerForm::ID).toString() );
	}
}

void ServerView::saveScene() {
	yDEBUG("Save server scene...");
	QList<QGraphicsItem *> items = m_pScene->items();
	Q_FOREACH(QGraphicsItem *item, items){
		ServerViewNode * svrNode = dynamic_cast<ServerViewNode *> (item);
		if(svrNode != 0){
			svrNode->saveNodePos();
		}
	}
}

void ServerView::addServer() {
	ServerForm form("", ServerForm::ADD, this);
	form.exec();
	addItem( form.id() );
}

void ServerView::activeServer(){
	ServerViewNode *node = selectedNode();
	ServerForm form(node->id());
	if(form.isServerActive()){
		yINFO( QString("De-Active server: %1(%2).").arg(form.name()).arg(form.ip()) );
		form.setServerActive(false);

	} else {
		yINFO( QString("Active server: %1(%2).").arg(form.name()).arg(form.ip()) );
		form.setServerActive(true);
	}
}



//TODO this function is temp
ServerViewNode* ServerView::addItem(QString id) {
	ServerViewNode *node = new ServerViewNode(id, ServerViewNode::GeneralServer, m_pItemCtxMenu, this);
	if(node->storedPosition().isNull())
		node->setPos(QPoint(0 + (120 * (m_itemCount % 5)), 0 + (50 * ((m_itemCount / 5) % 7))));
	m_pScene->addItem(node);
	m_itemCount++;
	return node;
}

void ServerView::deleteItem() {

	m_itemCount--;
}

void ServerView::clearScene() {
	m_pScene->clear();
	m_itemCount = 0;
}

void ServerView::createActions() {
	m_pAddServerAct = new QAction(tr("Add &Server"), this);
	m_pAddServerAct->setIcon(QIcon(":/images/add_server.png"));
	m_pAddServerAct->setShortcut(tr("Ctrl+S"));
	connect(m_pAddServerAct, SIGNAL(triggered()), this, SLOT(addServer()));

	m_pEditServerAct = new QAction(tr("&Edit Server"), this);
	m_pEditServerAct->setIcon(QIcon(":/images/add_server.png"));
	m_pEditServerAct->setShortcut(tr("Ctrl+E"));
	connect(m_pEditServerAct, SIGNAL(triggered()), this, SLOT(addServer()));

	m_pDeleteItemAct = new QAction(tr("&Delete"), this);
	m_pDeleteItemAct->setIcon(QIcon(":/images/delete.png"));
	m_pDeleteItemAct->setShortcut(tr("Ctrl+D"));
	connect(m_pDeleteItemAct, SIGNAL(triggered()), this, SLOT(deleteItem()));

	m_pActiveServerAct = new QAction(tr("Active &Monitor"), this);
	//m_pActiveServerAct->setIcon(QIcon(":/images/delete.png"));
	m_pActiveServerAct->setShortcut(tr("Ctrl+M"));
	connect(m_pActiveServerAct, SIGNAL(triggered()), this, SLOT(activeServer()));

}

void ServerView::createMenus() {
	m_pCtxMenu = new QMenu(this);
	m_pCtxMenu->addAction(m_pAddServerAct);

	m_pItemCtxMenu = new QMenu(this);
	m_pItemCtxMenu->addAction(m_pEditServerAct);
	m_pItemCtxMenu->addAction(m_pDeleteItemAct);
	m_pItemCtxMenu->addSeparator();
	m_pItemCtxMenu->addAction(m_pActiveServerAct);
}

void ServerView::updateActions() {
	bool hasSelection = !m_pScene->selectedItems().isEmpty();
	bool isNode = (selectedNode() != 0);

	m_pDeleteItemAct->setEnabled(hasSelection);
	if(isNode){
		ServerViewNode *svrNode = selectedNode();
	}
	/*
	Q_FOREACH(QAction *action, m_pView->actions()){
		m_pView->removeAction(action);
	}

	Q_FOREACH(QAction *action, m_pEditMenu->actions()){
		if (action->isEnabled())
			m_pView->addAction(action);
	}
	*/
}

ServerViewNode* ServerView::selectedNode() const {
	QList<QGraphicsItem *> items = m_pScene->selectedItems();
	if (items.count() == 1) {
		return dynamic_cast<ServerViewNode *> (items.first());
	} else {
		return 0;
	}
}

ServerViewItem* ServerView::getItemById(QString id){
	QList<QGraphicsItem *> items = m_pScene->items();
	Q_FOREACH(QGraphicsItem *item, items){
		ServerViewItem *si = dynamic_cast<ServerViewItem *>(item);
		if(si != 0 && si->id().compare(id) == 0)
			return si;
	}
	return 0;
}

QAction* ServerView::activeServerAction(){
	return m_pActiveServerAct;
}
