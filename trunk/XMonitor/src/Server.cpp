/*
 * Server.cpp
 *
 *  Created on: 2011-2-25
 *      Author: Yewberry
 */

#include "Server.h"

Server::Server() {
	// TODO Auto-generated constructor stub

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

void Server::name(QString n) {
	m_name = n;
}
QString Server::name() {
	return m_name;
}
void Server::ip(QString i) {
	m_ip = i;
}
QString Server::ip() {
	return m_ip;
}
void Server::desc(QString d) {
	m_desc = d;
}
QString Server::desc() {
	return m_desc;
}
void Server::usr(QString u) {
	m_usr = u;
}
QString Server::usr() {
	return m_usr;
}
void Server::pwd(QString p) {
	m_pwd = p;
}
QString Server::pwd() {
	return m_pwd;
}
