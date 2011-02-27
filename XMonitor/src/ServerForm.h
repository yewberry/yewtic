#ifndef SERVERFORM_H
#define SERVERFORM_H

#include <QDialog>
#include <QtSql>

class QDataWidgetMapper;
class QLineEdit;
class QTextEdit;
class QCheckBox;

class ServerForm: public QDialog {
	Q_OBJECT

public:
	enum OpType{INQ, ADD, EDIT};
	enum { ID = 0, IP = 1, NAME = 2, DESC = 3, USR = 4, PWD = 5, ACTIVE = 6 };
	ServerForm(QString id = "", OpType op = INQ, QWidget *parent = 0);
	~ServerForm();

	QSqlTableModel* model();
	QString id();
	QString ip();
	QString name();
	bool isServerActive();
	void setServerActive(bool c);

public slots:
	void save();

private:
	void drawUi();
	void mapping();

private:
	OpType 				m_opType;
	QSqlTableModel* 	m_pModel;
	QDataWidgetMapper*	m_pMapper;
	QString 			m_id;

	QLineEdit* m_uiID;
	QLineEdit* m_uiIP;
	QLineEdit* m_uiName;
	QLineEdit* m_uiUsr;
	QLineEdit* m_uiPwd;
	QTextEdit* m_uiDesc;
	QCheckBox* m_uiIsActive;

};

#endif // SERVERFORM_H
