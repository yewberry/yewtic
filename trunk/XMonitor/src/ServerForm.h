#ifndef SERVERFORM_H
#define SERVERFORM_H

#include <QDialog>

class QSqlTableModel;
class QDataWidgetMapper;
class QLineEdit;
class QTextEdit;

class ServerForm: public QDialog {
	Q_OBJECT

public:
	enum OpType{ADD, EDIT};
	enum { ID = 0, IP = 1, NAME = 2, DESC = 3, USR = 4, PWD = 5 };
	ServerForm(OpType op, QString id, QWidget *parent = 0);
	~ServerForm();

	QString ip();
	QString name();

private slots:
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

};

#endif // SERVERFORM_H
