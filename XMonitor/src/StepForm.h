#ifndef STEPFORM_H
#define STEPFORM_H

#include <QDialog>
#include <QtSql>
#include "../ui_StepForm.h"

class QDataWidgetMapper;

class StepForm: public QDialog {
	Q_OBJECT

public:
	enum OpType{INQ, ADD, EDIT, DEL};
	enum { ID = 0, SVR_ID = 1, NAME = 2, DESC = 3, CMD = 4, SCRIPT = 5, CMD_RESULT = 6, SEQ = 7 };
	StepForm(QString id = "", OpType op = INQ, QWidget *parent = 0);

	QSqlTableModel* model();
	QString id();
	QString svrId();
	void svrId(QString sId);
	QString name();
	QString desc();

public slots:
	void save();

private:
	void drawUi();
	void mapping();

private:
	Ui::StepFormClass ui;

	OpType 				m_opType;
	QSqlRelationalTableModel*
						m_pModel;
	QDataWidgetMapper*	m_pMapper;
	QString 			m_id;


};

#endif // STEPFORM_H
