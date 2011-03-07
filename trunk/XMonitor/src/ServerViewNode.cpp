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

ServerViewNode::ServerViewNode(QString id, NodeType t, QMenu *ctxMenu, ServerView *servView) :
	ServerViewItem(id),
	m_txtColor(Qt::darkGreen), m_outlineColor(Qt::darkBlue),
	m_bgColor(Qt::white), m_pContextMenu(ctxMenu), m_pServerView(servView)
{
	setFlags(ItemIsMovable | ItemIsSelectable);
	ServerForm form(m_id, ServerForm::INQ);
	m_text = QString("%1\n%2").arg(form.ip()).arg(form.name());
	m_storedPosition = form.uiScenePos();
	setPos(m_storedPosition);

	m_blinkTimer = startTimer(500);
}

ServerViewNode::~ServerViewNode() {
	killTimer(m_blinkTimer);
	foreach(ServerViewLink *link, m_links)
			delete link;
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
	painter->setBrush(m_bgColor);

	QRectF rect = outlineRect();
	painter->drawRoundRect(rect, roundness(rect.width()), roundness(
			rect.height()));

	painter->setPen(m_txtColor);
	painter->drawText(rect, Qt::AlignCenter, m_text);
}

void ServerViewNode::contextMenuEvent(QGraphicsSceneContextMenuEvent *event) {
	QAction *act = m_pServerView->activeServerAction();
	QString t = isActive()? tr("Stop monitor") : tr("Start monitor");
	act->setText(t);
	scene()->clearSelection();
	setSelected(true);
	m_pContextMenu->exec(event->screenPos());
}

void ServerViewNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
	ServerForm form(m_id, ServerForm::EDIT);
	form.exec();
	m_text = QString("%1\n%2").arg(form.ip()).arg(form.name());
	update(outlineRect());
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
	if(act){
		m_bgColor == Qt::white ? m_bgColor = Qt::green : m_bgColor = Qt::white;
		update(outlineRect());
	} else if(m_bgColor != Qt::white){
		m_bgColor = Qt::white;
		update(outlineRect());
	}
}

void ServerViewNode::saveNodePos(){
	ServerForm form(m_id, ServerForm::EDIT);
	form.uiScenePos( scenePos() );
}

QString ServerViewNode::text() const {
	return m_text;
}

QPointF ServerViewNode::storedPosition() const {
	return m_storedPosition;
}

bool ServerViewNode::isActive(){
	ServerForm form(m_id, ServerForm::INQ);
	return form.isServerActive();
}
