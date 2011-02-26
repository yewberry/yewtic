/*
 * ServerViewNode.cpp
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */
#include <QtGui>
#include "ServerViewNode.h"
#include "ServerViewLink.h"

ServerViewNode::ServerViewNode() {
	m_txtColor = Qt::darkGreen;
	m_outlineColor = Qt::darkBlue;
	m_bgColor = Qt::white;
	setFlags(ItemIsMovable | ItemIsSelectable);

}

ServerViewNode::~ServerViewNode() {
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
	painter->drawText(rect, Qt::AlignCenter, "Server");
}

void ServerViewNode::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
	QString txt = QInputDialog::getText(event->widget(), "Edit Text",
			"Enter new text:", QLineEdit::Normal, m_text);
	if (!txt.isEmpty())
		text(txt);
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

void ServerViewNode::text(const QString& t){
	m_text = t;
}

QString ServerViewNode::text() const {
	return m_text;
}
