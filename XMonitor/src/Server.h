/*
 * Server.h
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <QObject>

class Server : public QObject
{
	Q_OBJECT

public:
	Server();
	virtual ~Server();

	void name(QString n);
	QString name();
	void ip(QString i);
	QString ip();
	void desc(QString d);
	QString desc();
	void usr(QString u);
	QString usr();
	void pwd(QString p);
	QString pwd();

private:
	QString m_id;
	QString m_name;
	QString m_ip;
	QString m_desc;
	QString m_usr;
	QString m_pwd;
};

#endif /* SERVER_H_ */
