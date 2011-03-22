/*
 * ServerViewNode.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */
#include <QtGui>
#include "ServerView.h"
#include "ServerViewNode.h"
#include "ServerViewLink.h"
#include "ServerForm.h"
#include "Comm.h"
#include "qjson/parser.h"

ServerViewNode::ServerViewNode(QString id, NodeType t, QMenu *ctxMenu, ServerView *servView) :
	ServerViewItem(id),
	m_txtColor(Qt::darkGreen), m_outlineColor(Qt::blue),
	m_bgColor(Qt::white), m_pContextMenu(ctxMenu), m_pServerView(servView)
{
	setFlags(ItemIsMovable | ItemIsSelectable);
	ServerModel model;
	QSqlRecord rec = model.getRecordById(m_id);
	QString ip = rec.value(ServerModel::IP).toString();
	QString name = rec.value(ServerModel::NAME).toString();

	m_text = QString("%1\n%2").arg(ip).arg(name);
	m_storedPosition = model.getUiScenePos(m_id);
	setPos(m_storedPosition);

	m_blinkTimer = startTimer(500);
}

ServerViewNode::~ServerViewNode() {
	killTimer(m_blinkTimer);
	foreach(ServerViewLink *link, m_links)
			delete link;
}

void ServerViewNode::editItem(){
	ServerForm form(m_id, ServerForm::EDIT);
	form.exec();
	m_text = QString("%1\n%2").arg(form.getIp()).arg(form.getName());
	update(outlineRect());
}

void ServerViewNode::deleteItem(){
	if( QMessageBox::question(0, tr("Confirm?"), tr("Confirm to delete \"%1\"?").arg(text()),
			QMessageBox::Yes|QMessageBox::Cancel, QMessageBox::Cancel) == QMessageBox::Yes ){
		ServerModel model;
		model.deleteRecordById(m_id);
		delete this;
	}
}

void ServerViewNode::addLink(ServerViewLink *link) {
	m_links.insert(link);
}

void ServerViewNode::removeLink(ServerViewLink *link) {
	m_links.remove(link);
}

QRectF ServerViewNode::boundingRect() const {
	const int Margin = 1;
	return outlineRect().adjusted(-Margin, -Margin, +Margin, +Margin);
}

QPainterPath ServerViewNode::shape() const {
	QRectF rect = outlineRect();

	QPainterPath path;
	path.addRoundRect(rect, roundness(rect.width()), roundness(rect.height()));
	return path;
}

void ServerViewNode::paint(QPainter *painter,
		const QStyleOptionGraphicsItem *option, QWidget * /* widget */) {
	QPen pen(m_outlineColor);
	if (option->state & QStyle::State_Selected) {
		pen.setStyle(Qt::DotLine);
		pen.setWidth(2);
	}
	painter->setPen(pen);
	QRectF rect = outlineRect();
	painter->setBrush(m_bgColor);
	painter->drawRoundRect(rect, roundness(rect.width()), roundness(
			rect.height()));

	painter->setPen(m_txtColor);
	painter->drawText(rect, Qt::AlignCenter, m_text);
}

void ServerViewNode::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
	QList<QAction*> acts = m_pServerView->getActions();
	QAction *act = 0;
	Q_FOREACH(QAction *p, acts){
		int s = p->data().toInt();
		if(s != 0){
			act = p;
			break;
		}
	}

	if(act != 0){
		if(isActive()){
			act->setText( tr("Stop monitor") );
			act->setIcon(QIcon(":/images/desable_server.png"));
		} else {
			act->setText( tr("Start monitor") );
			act->setIcon(QIcon(":/images/enable_server.png"));
		}
	}

	scene()->clearSelection();
	setSelected(true);
	m_pContextMenu->exec(event->screenPos());
}

void ServerViewNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
	editItem();
}

QVariant ServerViewNode::itemChange(GraphicsItemChange change,
		const QVariant &value) {
	if (change == ItemPositionHasChanged) {
		foreach (ServerViewLink *link, m_links)
				link->trackNodes();
	}
	return QGraphicsItem::itemChange(change, value);
}

QRectF ServerViewNode::outlineRect() const {
	const int Padding = 8;
	QFontMetricsF metrics = qApp->font();
	QRectF rect = metrics.boundingRect(m_text);
	rect.adjust(-Padding, -Padding, +Padding, +Padding);
	rect.translate(-rect.center());
	return rect;
}

int ServerViewNode::roundness(double size) const {
	const int Diameter = 12;
	return 100 * Diameter / int(size);
}

void ServerViewNode::timerEvent(QTimerEvent *event){
	bool act = isActive();
	bool warning = isWarning();
	if(act && warning){
		m_bgColor == Qt::white ? m_bgColor = Qt::red : m_bgColor = Qt::white;
	} else if(act){
		m_bgColor == Qt::white ? m_bgColor = Qt::green : m_bgColor = Qt::white;
	}else if(m_bgColor != Qt::white){
		m_bgColor = Qt::white;
	}

	ServerModel model(this);
	QString jsonStr = model.stepStatus(m_id);
	if(warning && !jsonStr.isEmpty()){
		bool ok;
		QJson::Parser parser;
		QVariantMap stepStatus = parser.parse(jsonStr.toLocal8Bit(), &ok).toMap();
		QString tip = "<ul>";

		if (ok) {
			QList<QString> keys = stepStatus.keys();
			Q_FOREACH(QString key, keys){
				QVariantMap hm = stepStatus[key].toMap();
				if( hm.contains("status") && hm["status"].toBool() == false ){
					QString stepNm = key;
					QString msg = hm.contains("msg") ? hm["msg"].toString() : "";
					tip.append( QString("<li>%1: %2</li>").arg(stepNm).arg(msg) );
				}
			}

		} else {
			yERROR( QString("An error occurred during parsing JSON: %1").arg(jsonStr) );
		}

		tip.append("</ul>");
		setToolTip(tip);
	}

	update(outlineRect());
}

void ServerViewNode::saveNodePos(){
	ServerModel model(this);
	model.uiScenePos(m_id, scenePos());
}

QString ServerViewNode::text() const {
	return m_text;
}

QPointF ServerViewNode::storedPosition() const {
	return m_storedPosition;
}

bool ServerViewNode::isActive(){
	ServerModel model(this);
	return model.isActive(m_id);
}

bool ServerViewNode::isWarning(){
	ServerModel model(this);
	return model.isWarning(m_id);
}
