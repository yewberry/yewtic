#ifndef AUTHENTICATIONDIALOG_H
#define AUTHENTICATIONDIALOG_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class AuthenticationDialog
        : public QDialog
{
    Q_OBJECT

public:
    AuthenticationDialog();
    QString user();
    QString password();

private:
    QLabel * m_userLabel;
    QLineEdit * m_userEdit;
    QLabel * m_passwordLabel;
    QLineEdit * m_passwordEdit;
    QPushButton * m_okButton;
    QPushButton * m_cancelButton;
};

#endif // AUTHENTICATIONDIALOG_H
