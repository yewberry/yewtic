/*
 * ServerViewNode.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef SERVERVIEWNODE_H_
#define SERVERVIEWNODE_H_

#include <QApplication>
#include <QGraphicsItem>
#include <QSet>
#include <QColor>

class ServerViewLink;

class ServerViewNode: public QGraphicsItem {

public:
	ServerViewNode();
	~ServerViewNode();

	void addLink(ServerViewLink *link);
	void removeLink(ServerViewLink *link);

	QRectF boundingRect() const;
	QPainterPath shape() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
			QWidget *widget);

	void text(const QString& t);
	QString text() const;

protected:
	void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
	QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
	QRectF outlineRect() const;
	int roundness(double size) const;

	QSet<ServerViewLink *> m_links;

	QString m_text;
    QColor m_txtColor;
    QColor m_bgColor;
    QColor m_outlineColor;
};

#endif /* SERVERVIEWNODE_H_ */
