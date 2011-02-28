#include "ServerForm.h"
#include <QtGui>
#include "Comm.h"

ServerForm::ServerForm(QString id, OpType op, QWidget *parent) :
	QDialog(parent), m_id(id), m_opType(op) {
	ui.setupUi(this);
	drawUi();
	mapping();
}

ServerForm::~ServerForm() {

}

void ServerForm::mapping() {
	m_pModel = new QSqlTableModel(this);
	m_pModel->setTable("server");
	m_pModel->select();

	m_pMapper = new QDataWidgetMapper(this);
	m_pMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
	m_pMapper->setModel(m_pModel);
	m_pMapper->setItemDelegate(new QSqlRelationalDelegate(this));
	m_pMapper->addMapping(ui.id, ID);
	m_pMapper->addMapping(ui.ip, IP);
	m_pMapper->addMapping(ui.name, NAME);
	m_pMapper->addMapping(ui.desc, DESC);
	m_pMapper->addMapping(ui.usr, USR);
	m_pMapper->addMapping(ui.pwd, PWD);
	m_pMapper->addMapping(ui.isActive, ACTIVE);


    if( !m_id.isEmpty() ) {
        for (int row = 0; row < m_pModel->rowCount(); ++row) {
            QSqlRecord record = m_pModel->record(row);
            if (record.value(ID).toString() == m_id) {
                m_pMapper->setCurrentIndex(row);
                break;
            }
        }

    } else if(m_opType == ADD){
        int row = m_pModel->rowCount();
        m_pModel->insertRow(row);
        m_pMapper->setCurrentIndex(row);
        ui.id->setText( QString::fromStdString(Comm::uuid()) );
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
	this->close();
}

QSqlTableModel* ServerForm::model(){
	return m_pModel;
}

QString ServerForm::id(){
	return ui.id->text();
}

QString ServerForm::ip(){
	return ui.ip->text();
}

QString ServerForm::name(){
	return ui.name->text();
}

bool ServerForm::isServerActive(){
	return ui.isActive->isChecked();
}

void ServerForm::setServerActive(bool c){
	ui.isActive->setChecked(c);
}
