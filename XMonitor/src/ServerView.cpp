/*
 * ServerView.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#include <QtGui>
#include "ServerView.h"
#include "ServerForm.h"
#include "StepForm.h"
#include "StepScriptDialog.h"
#include <iostream>

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

void ServerView::activeServer(){
	ServerViewNode *node = selectedNode();
	ServerModel model;
	QString svrId = node->id();
	QSqlRecord rec = model.getRecordById( svrId );
	QString name = rec.value(ServerModel::NAME).toString();
	QString ip = rec.value(ServerModel::IP).toString();
	bool isAct = rec.value(ServerModel::ACTIVE).toBool();

	if(isAct){
		yINFO( QString("De-Active server: %1(%2).").arg(name).arg(ip) );
		model.editRecFldById(svrId, ServerModel::ACTIVE, false);

	} else {
		yINFO( QString("Active server: %1(%2).").arg(name).arg(ip) );
		model.editRecFldById(svrId, ServerModel::ACTIVE, true);
	}
}

void ServerView::activeAllServer(){
	ServerModel model;
	QVector<QSqlRecord> recs = model.getRecords();
	Q_FOREACH(QSqlRecord rec, recs){
		QString svrId = rec.value(ServerModel::ID).toString();
		model.editRecFldById(svrId, ServerModel::ACTIVE, true);
	}
	yINFO("All Server monitor started.");
}

void ServerView::deActiveAllServer(){
	ServerModel model;
	QVector<QSqlRecord> recs = model.getRecords();
	Q_FOREACH(QSqlRecord rec, recs){
		QString svrId = rec.value(ServerModel::ID).toString();
		model.editRecFldById(svrId, ServerModel::ACTIVE, false);
	}
	yINFO("All Server monitor stopped.");
}

void ServerView::addServer() {
	ServerForm form("", ServerForm::ADD, this);
	if( form.exec()  == QDialog::Accepted ){
		addItem( form.getId() );
	}
}

void ServerView::browserSteps() {
	ServerViewNode *svr = selectedNode();
	if(svr != 0){
		StepScriptDialog dlg(StepScriptDialog::EDIT_SVR_STEPS, svr->id(), this);
		dlg.exec();
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

void ServerView::editItem() {
	ServerViewItem *item = selectedItem();
	item->editItem();
}

void ServerView::deleteItem() {
	ServerViewItem *item = selectedItem();
	item->deleteItem();
	m_itemCount--;
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

void ServerView::clearScene() {
	m_pScene->clear();
	m_itemCount = 0;
}

void ServerView::createActions() {
	m_pAddServerAct = new QAction(tr("Add Server"), this);
	m_pAddServerAct->setIcon(QIcon(":/images/add_server.png"));
	//m_pAddServerAct->setShortcut(tr("Ctrl+S"));
	connect(m_pAddServerAct, SIGNAL(triggered()), this, SLOT(addServer()));

	m_pEditServerAct = new QAction(tr("&Edit"), this);
	m_pEditServerAct->setIcon(QIcon(":/images/edit.png"));
	m_pEditServerAct->setShortcut(tr("Ctrl+E"));
	connect(m_pEditServerAct, SIGNAL(triggered()), this, SLOT(editItem()));

	m_pDeleteItemAct = new QAction(tr("&Delete"), this);
	m_pDeleteItemAct->setIcon(QIcon(":/images/delete.png"));
	m_pDeleteItemAct->setShortcut(tr("Ctrl+D"));
	connect(m_pDeleteItemAct, SIGNAL(triggered()), this, SLOT(deleteItem()));

	m_pActiveServerAct = new QAction(tr("Active &Monitor"), this);
	m_pActiveServerAct->setShortcut(tr("Ctrl+M"));
	m_pActiveServerAct->setData(ACTIVE_SVR_ACT);
	connect(m_pActiveServerAct, SIGNAL(triggered()), this, SLOT(activeServer()));

	m_pActiveAllServerAct = new QAction(tr("Active All"), this);
	//m_pActiveAllServerAct->setShortcut(tr("Ctrl+M"));
	connect(m_pActiveAllServerAct, SIGNAL(triggered()), this, SLOT(activeAllServer()));

	m_pDeActiveAllServerAct = new QAction(tr("De-Active All"), this);
	//m_pDeActiveAllServerAct->setShortcut(tr("Ctrl+M"));
	connect(m_pDeActiveAllServerAct, SIGNAL(triggered()), this, SLOT(deActiveAllServer()));

	m_pBrowserStepsAct = new QAction(tr("Browser Steps"), this);
	m_pBrowserStepsAct->setIcon(QIcon(":/images/browser.png"));
	//m_pBrowserStepsAct->setShortcut(tr("Ctrl+S"));
	connect(m_pBrowserStepsAct, SIGNAL(triggered()), this, SLOT(browserSteps()));
}

void ServerView::createMenus() {
	m_pCtxMenu = new QMenu(this);
	m_pCtxMenu->addAction(m_pAddServerAct);
	m_pCtxMenu->addAction(m_pActiveAllServerAct);
	m_pCtxMenu->addAction(m_pDeActiveAllServerAct);

	m_pItemCtxMenu = new QMenu(this);
	m_pItemCtxMenu->addAction(m_pEditServerAct);
	m_pItemCtxMenu->addAction(m_pDeleteItemAct);
	m_pItemCtxMenu->addSeparator();
	m_pItemCtxMenu->addAction(m_pBrowserStepsAct);
	m_pItemCtxMenu->addSeparator();
	m_pItemCtxMenu->addAction(m_pActiveServerAct);
}

QList<QAction *> ServerView::getActions(){
	QList<QAction *> ls;
	ls.append(m_pCtxMenu->actions());
	ls.append(m_pItemCtxMenu->actions());
	return ls;
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

void ServerView::loadFromDb() {
	yDEBUG("Load server nodes...");
	ServerModel model(this);
	QVector<QSqlRecord> recs = model.getRecords();
	for (int row = 0; row < recs.count(); ++row) {
		QSqlRecord record = recs.at(row);
		ServerViewNode *node = addItem( record.value(ServerModel::ID).toString() );
	}
}

ServerViewItem* ServerView::selectedItem() const {
	QList<QGraphicsItem *> items = m_pScene->selectedItems();
	if (items.count() == 1) {
		return dynamic_cast<ServerViewItem *> (items.first());
	} else {
		return 0;
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

ServerViewItem* ServerView::getItemById(QString id){
	QList<QGraphicsItem *> items = m_pScene->items();
	Q_FOREACH(QGraphicsItem *item, items){
		ServerViewItem *si = dynamic_cast<ServerViewItem *>(item);
		if(si != 0 && si->id().compare(id) == 0)
			return si;
	}
	return 0;
}
