#include "ServerForm.h"
#include <QtGui>
#include "Comm.h"

ServerForm::ServerForm(QString id, OpType op, QWidget *parent) :
	QDialog(parent), m_id(id), m_opType(op) {
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
	m_pMapper->addMapping(m_uiID, ID);
	m_pMapper->addMapping(m_uiIP, IP);
	m_pMapper->addMapping(m_uiName, NAME);
	m_pMapper->addMapping(m_uiDesc, DESC);
	m_pMapper->addMapping(m_uiUsr, USR);
	m_pMapper->addMapping(m_uiPwd, PWD);
	m_pMapper->addMapping(m_uiIsActive, ACTIVE);


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
        m_uiID->setText( QString::fromStdString(Comm::uuid()) );
    }
}

void ServerForm::drawUi() {
	m_uiID = new QLineEdit;
	m_uiID->setEnabled(false);
	QLabel *idLabel = new QLabel(tr("&ID:"));
	idLabel->setBuddy(m_uiID);

	m_uiIP = new QLineEdit;
	QLabel *ipLabel = new QLabel(tr("I&P:"));
	ipLabel->setBuddy(m_uiIP);

	m_uiName = new QLineEdit;
	QLabel *nmLabel = new QLabel(tr("Na&me:"));
	nmLabel->setBuddy(m_uiName);

	m_uiUsr = new QLineEdit;
	QLabel *usrLabel = new QLabel(tr("&User:"));
	usrLabel->setBuddy(m_uiUsr);

	m_uiPwd = new QLineEdit;
	m_uiPwd->setEchoMode(QLineEdit::Password);
	QLabel *pwdLabel = new QLabel(tr("&Password:"));
	pwdLabel->setBuddy(m_uiPwd);

	m_uiDesc = new QTextEdit;
	QLabel *descLabel = new QLabel(tr("&Description:"));
	descLabel->setBuddy(m_uiDesc);

	m_uiIsActive = new QCheckBox;
	QLabel *activeLabel = new QLabel(tr("&Active?:"));
	activeLabel->setBuddy(m_uiIsActive);

	QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok
			| QDialogButtonBox::Cancel);

	connect(buttonBox, SIGNAL(accepted()), this, SLOT(save()));
	connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(idLabel, 0, 0);
	mainLayout->addWidget(m_uiID, 0, 1);

	mainLayout->addWidget(ipLabel, 1, 0);
	mainLayout->addWidget(m_uiIP, 1, 1);

	mainLayout->addWidget(nmLabel, 2, 0);
	mainLayout->addWidget(m_uiName, 2, 1);

	mainLayout->addWidget(descLabel, 3, 0);
	mainLayout->addWidget(m_uiDesc, 3, 1);

	mainLayout->addWidget(usrLabel, 4, 0);
	mainLayout->addWidget(m_uiUsr, 4, 1);

	mainLayout->addWidget(pwdLabel, 5, 0);
	mainLayout->addWidget(m_uiPwd, 5, 1);

	mainLayout->addWidget(activeLabel, 6, 0);
	mainLayout->addWidget(m_uiIsActive, 6, 1);

	mainLayout->addWidget(buttonBox, 7, 0, 1, 2);
	setLayout(mainLayout);

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
	return m_uiID->text();
}

QString ServerForm::ip(){
	return m_uiIP->text();
}

QString ServerForm::name(){
	return m_uiName->text();
}

bool ServerForm::isServerActive(){
	return m_uiIsActive->isChecked();
}

void ServerForm::setServerActive(bool c){
	m_uiIsActive->setChecked(c);
}
