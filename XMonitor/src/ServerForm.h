#ifndef SERVERFORM_H
#define SERVERFORM_H

#include <QDialog>
#include "ServerModel.h"
#include "../ui_ServerForm.h"

class QDataWidgetMapper;

class ServerForm: public QDialog {
	Q_OBJECT

public:
	enum OpType{ADD, EDIT};
	ServerForm(QString id = "", OpType op = ADD, QWidget *parent = 0);

	QString getId();
	QString getIp();
	QString getName();
	QString getUser();
	QString getPwd();


public slots:
	void save();

private:
	void drawUi();
	void mapping();

private:
	Ui::ServerFormClass ui;

	OpType 				m_opType;
	ServerModel*		m_pModel;
	QDataWidgetMapper*	m_pMapper;
	QString 			m_id;
};

#endif // SERVERFORM_H
