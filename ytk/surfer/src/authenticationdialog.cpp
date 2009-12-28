#include "authenticationdialog.h"

AuthenticationDialog::AuthenticationDialog()
{
    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle(trUtf8("Authentication required"));
    resize(300, 200);

    QVBoxLayout * vboxlayout = new QVBoxLayout(this);
    m_userLabel = new QLabel(trUtf8("User") + ":", this);
    vboxlayout->addWidget(m_userLabel);
    m_userEdit = new QLineEdit(this);
    vboxlayout->addWidget(m_userEdit);
    m_passwordLabel = new QLabel(trUtf8("Password") + ":", this);
    vboxlayout->addWidget(m_passwordLabel);
    m_passwordEdit = new QLineEdit(this);
    m_passwordEdit->setEchoMode(QLineEdit::Password);
    vboxlayout->addWidget(m_passwordEdit);
    QHBoxLayout * hboxlayout = new QHBoxLayout();
    m_okButton = new QPushButton(this);
    m_okButton->setText(trUtf8("OK"));
    m_okButton->setIcon(QIcon(":/ok.png"));
    hboxlayout->addWidget(m_okButton);
    m_cancelButton = new QPushButton(this);
    m_cancelButton->setText(trUtf8("Cancel"));
    m_cancelButton->setIcon(QIcon(":/cancel.png"));
    hboxlayout->addWidget(m_cancelButton);
    vboxlayout->addLayout(hboxlayout);

    connect(m_okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

QString AuthenticationDialog::user()
{
    return m_userEdit->text();
}

QString AuthenticationDialog::password()
{
    return m_passwordEdit->text();
}
