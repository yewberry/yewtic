/*
 * ServerView.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#include <QtGui>
#include "ServerView.h"
#include "ServerViewNode.h"
#include "ServerForm.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include   <unistd.h>

void *TaskCode(void *argument) {
	int tid;

	tid = *((int *) argument);
	printf("Hello World! It's me, thread %d!\n", tid);

	while(true){
		printf("thread %d do work\n", tid);
		printf("thread %d do sleep\n", tid);
		usleep(5000);

	}

	return NULL;
}

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
	createItemMenus();
	connect(m_pScene, SIGNAL(selectionChanged()), this, SLOT(updateActions()));

}

ServerView::~ServerView() {
	// TODO Auto-generated destructor stub
}

void ServerView::contextMenuEvent(QContextMenuEvent * event) {
	m_pCtxMenu->exec(QCursor::pos());
}

void ServerView::loadFromDb() {
	ServerForm form;
	QSqlTableModel *model = form.model();
	for (int row = 0; row < model->rowCount(); ++row) {
		QSqlRecord record = model->record(row);
		ServerViewNode *node = addItem(record.value(ServerForm::ID).toString(), record.value(
				ServerForm::IP).toString(),
				record.value(ServerForm::NAME).toString());
		activeServer(node);
	}
}

void ServerView::addServer() {
	ServerForm form("", ServerForm::ADD);
	form.exec();
	addItem(form.id(), form.ip(), form.name());
}

void ServerView::activeServer(ServerViewNode *node){
	ServerForm form(node->id());

	if(form.isServerActive()){
		yINFO( QString("Monitor server: %1(%2).").arg(form.name()).arg(form.ip()) );
		node->startBlink();
		int NUM_THREADS = 5;
		pthread_t threads[NUM_THREADS];
		int thread_args[NUM_THREADS];
		int rc, i;

		/* create all threads */
		for (i = 0; i < NUM_THREADS; ++i) {
			thread_args[i] = i;
			printf("In main: creating thread %d\n", i);
			rc = pthread_create(&threads[i], NULL, TaskCode, (void *) &thread_args[i]);
			assert(0 == rc);
		}
	}
}

void ServerView::activeServer(){
	ServerViewNode *node = selectedNode();
	ServerForm form(node->id());
	if(form.isServerActive()){
		yINFO( QString("De-Active server: %1(%2).").arg(form.name()).arg(form.ip()) );
		node->stopBlink();
		form.setServerActive(false);
		form.save();

	} else {
		yINFO( QString("Active server: %1(%2).").arg(form.name()).arg(form.ip()) );
		node->startBlink();
		form.setServerActive(true);
		form.save();
	}
}



//TODO this function is temp
ServerViewNode* ServerView::addItem(QString id, QString ip, QString name) {
	ServerViewNode *node = new ServerViewNode(ServerViewNode::GeneralServer, m_pItemCtxMenu);
	node->id(id);
	node->text(QString("%1\n%2").arg(ip).arg(name));
	node->setPos(QPoint(0 + (120 * (m_itemCount % 5)), 0 + (50 * ((m_itemCount
			/ 5) % 7))));
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

	m_pDeActiveServerAct = new QAction(tr("De-Active Monito&r"), this);
	//m_pActiveServerAct->setIcon(QIcon(":/images/delete.png"));
	m_pDeActiveServerAct->setShortcut(tr("Ctrl+R"));
	connect(m_pDeActiveServerAct, SIGNAL(triggered()), this, SLOT(activeServer()));
}

void ServerView::createMenus() {
	m_pCtxMenu = new QMenu(this);
	m_pCtxMenu->addAction(m_pAddServerAct);
	m_pCtxMenu->addAction(m_pEditServerAct);
	m_pCtxMenu->addSeparator();
	m_pCtxMenu->addAction(m_pDeleteItemAct);
}

void ServerView::createItemMenus(){
	m_pItemCtxMenu = new QMenu(this);
	m_pItemCtxMenu->addAction(m_pActiveServerAct);
	m_pItemCtxMenu->addAction(m_pDeActiveServerAct);
}

void ServerView::updateActions() {
	/*
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
