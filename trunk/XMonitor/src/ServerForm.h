#ifndef SERVERFORM_H
#define SERVERFORM_H

#include <QDialog>
#include <QtSql>
#include "../ui_ServerForm.h"

class QDataWidgetMapper;

class ServerForm: public QDialog {
	Q_OBJECT

public:
	enum OpType{INQ, ADD, EDIT};
	enum { ID = 0, IP = 1, NAME = 2, DESC = 3, USR = 4, PWD = 5, ACTIVE = 6, UI_SCENE_POS = 7 };
	ServerForm(QString id = "", OpType op = INQ, QWidget *parent = 0);

	QSqlTableModel* model();
	QString id();
	QString getIp();
	QString name();
	QString getUser();
	QString getPwd();

	QPointF uiScenePos();
	void uiScenePos(QPointF pos);

	bool isServerActive();
	void setServerActive(bool c);

public slots:
	void save();

private:
	void drawUi();
	void mapping();

private:
	Ui::ServerFormClass ui;

	OpType 				m_opType;
	QSqlTableModel*
						m_pModel;
	QDataWidgetMapper*	m_pMapper;
	QString 			m_id;
};

#endif // SERVERFORM_H
