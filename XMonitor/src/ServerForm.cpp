#include "ServerForm.h"
#include <QtGui>
#include "ServerModel.h"
#include "Comm.h"

ServerForm::ServerForm(QString id, OpType op, QWidget *parent)
	: QDialog(parent), m_id(id), m_opType(op)
{
	ui.setupUi(this);
	drawUi();
	mapping();
}

void ServerForm::mapping() {
	m_pModel = new ServerModel(this);

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	//m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(ui.id, ServerModel::ID);
	m_pMapper->addMapping(ui.ip, ServerModel::IP);
	m_pMapper->addMapping(ui.name, ServerModel::NAME);
	m_pMapper->addMapping(ui.desc, ServerModel::DESC);
	m_pMapper->addMapping(ui.usr, ServerModel::USR);
	m_pMapper->addMapping(ui.pwd, ServerModel::PWD);
	m_pMapper->addMapping(ui.isActive, ServerModel::ACTIVE);
	m_pMapper->addMapping(ui.itemPos, ServerModel::UI_SCENE_POS);

	if(m_opType == ADD){
        int row = m_pModel->rowCount();
        m_pModel->insertRow(row);
        m_pMapper->setCurrentIndex(row);
        ui.id->setText( QString::fromStdString(Comm::uuid()) );

    } else if( m_opType == EDIT && !m_id.isEmpty() ) {
        for (int row = 0; row < m_pModel->rowCount(); ++row) {
            QSqlRecord record = m_pModel->record(row);
            if (record.value(ServerModel::ID).toString() == m_id) {
                m_pMapper->setCurrentIndex(row);
                break;
            }
        }
    }
}

void ServerForm::drawUi() {

	QDialogButtonBox *buttonBox = ui.buttonBox;

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(save()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	switch (m_opType) {
	case ADD:
		setWindowTitle(tr("Add Server"));
		break;
	case EDIT:
		setWindowTitle(tr("Edit Server"));
		break;
	default:
		setWindowTitle(tr("Server Infomation"));
	}

}

void ServerForm::save(){
	m_pMapper->submit();
	accept();
}

QString ServerForm::getId(){
	return ui.id->text();
}

QString ServerForm::getIp(){
	return ui.ip->text();
}

QString ServerForm::getName(){
	return ui.name->text();
}

QString ServerForm::getUser(){
	return ui.usr->text();
}

QString ServerForm::getPwd(){
	return ui.pwd->text();
}

