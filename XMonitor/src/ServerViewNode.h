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
#include <QMenu>

class ServerViewLink;

class ServerViewNode: public QGraphicsItem {

public:
	enum NodeType {
		GeneralServer
	};

	ServerViewNode(NodeType t = GeneralServer, QMenu *ctxMenu = 0);
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
	void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
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

	QMenu* m_pContextMenu;
};

#endif /* SERVERVIEWNODE_H_ */
