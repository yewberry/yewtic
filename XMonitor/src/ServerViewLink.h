/*
 * ServerViewLink.h
 *
 *  Created on: 2011-2-26
 *      Author: Yewberry
 */

#ifndef SERVERVIEWLINK_H_
#define SERVERVIEWLINK_H_

#include <QGraphicsLineItem>

class ServerViewNode;

class ServerViewLink  : public QGraphicsLineItem
{
public:
	ServerViewLink(ServerViewNode *fromNode, ServerViewNode *toNode);
    ~ServerViewLink();

    ServerViewNode *fromNode() const;
    ServerViewNode *toNode() const;

    void trackNodes();

private:
    ServerViewNode *m_fromNode;
    ServerViewNode *m_toNode;
};

#endif /* SERVERVIEWLINK_H_ */
