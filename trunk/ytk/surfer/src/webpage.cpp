#include "webpage.h"
#include "networkaccessmanager.h"
#include "downloadmanager.h"
#include "settingsmanager.h"
#include "authenticationdialog.h"

WebPage::WebPage(QObject * parent)
        : QWebPage(parent)
{
    setForwardUnsupportedContent(true);

    NetworkAccessManager * manager = NetworkAccessManager::networkAccessManager();
    setNetworkAccessManager(manager);
    manager->setParent(0);

    connect(this, SIGNAL(unsupportedContent(QNetworkReply *)),
            this, SLOT(handleUnsupportedContent(QNetworkReply *)));
    connect(this, SIGNAL(downloadRequested(const QNetworkRequest &)),
            this, SLOT(download(const QNetworkRequest &)));
    connect(manager, SIGNAL(authenticationRequired(QNetworkReply *, QAuthenticator *)),
            this, SLOT(authenticate(QNetworkReply *, QAuthenticator *)));
    connect(manager, SIGNAL(proxyAuthenticationRequired(const QNetworkProxy &, QAuthenticator *)),
            this, SLOT(authenticate(const QNetworkProxy &, QAuthenticator *)));
    connect(manager, SIGNAL(sslErrors(QNetworkReply*, const QList<QSslError> &)),
            this, SLOT(handleSslErrors(QNetworkReply *, const QList<QSslError> &)));
}

QString WebPage::chooseFile(QWebFrame * /*parentFrame*/, const QString & suggestedFile)
{
    QWebView * webView = qobject_cast<QWebView *>(parent());
    return QFileDialog::getOpenFileName(webView, trUtf8("Upload file"),
                                        QDir::homePath() + "/" + suggestedFile);
}

bool WebPage::acceptNavigationRequest(QWebFrame * frame, const QNetworkRequest & request,
                                      NavigationType type)
{
    QUrl url = request.url();
    QString scheme = url.scheme();
    if(scheme != "http" && scheme != "https" && scheme != "file" && scheme != "ftp" &&
        scheme != "data" && scheme != "about" && scheme != "javascript")
    {
        QDesktopServices::openUrl(url);
        return false;
    }
    else if(scheme == "ftp")
    {
        download(QNetworkRequest(request));
        return false;
    }
    else
    {
        return QWebPage::acceptNavigationRequest(frame, request, type);
    }
}

void WebPage::handleUnsupportedContent(QNetworkReply * reply)
{
    QWebView * webView = qobject_cast<QWebView *>(parent());
    QNetworkReply::NetworkError error = reply->error();
    QUrl url = reply->url();
    if(error != QNetworkReply::NoError && error != QNetworkReply::AuthenticationRequiredError &&
       error != QNetworkReply::ProxyAuthenticationRequiredError &&
       error != QNetworkReply::SslHandshakeFailedError && webView)
    {
        QString errorHtml = "<html><head><title>" + trUtf8("Error") + "</title></head><body>";
        errorHtml += "<table align=\"center\" width=\"300\" height=\"100%\"><tr valign=\"middle\">";
        errorHtml += "<td>" + trUtf8("Surfer can't open") + " <a href=\"" + url.toString() + "\">";
        errorHtml += trUtf8("this page") + "</a>.<br>" + trUtf8("Possible reasons are");
        errorHtml += ":<br><ul><li>" + trUtf8("Network connection problem") + "</li><li>";
        errorHtml += trUtf8("Page doesn't exist") + "</li><li>";
        errorHtml += trUtf8("You made error when you typed adress") + "</li>";
        errorHtml += "</ul></td></tr></table></body></html>";
        webView->setHtml(errorHtml, url);
    }
    else if(error == QNetworkReply::NoError)
    {
        download(QNetworkRequest(url));
    }
}

void WebPage::download(const QNetworkRequest & request)
{
    QNetworkReply * reply = NetworkAccessManager::networkAccessManager()->head(request);
    connect(reply, SIGNAL(finished()), this, SLOT(handleHeaders()));
}

void WebPage::handleHeaders()
{
    QWebView * webView = qobject_cast<QWebView *>(parent());
    QNetworkReply * reply = qobject_cast<QNetworkReply *>(sender());
    if(reply)
    {
        QUrl url = reply->url();
        QString name;
        if(reply->hasRawHeader("Content-Disposition"))
        {
            QString disposition = reply->rawHeader("Content-Disposition");
            foreach(QString section, disposition.split("; "))
            {
                if(section.startsWith("filename=\"", Qt::CaseInsensitive) && section.endsWith("\""))
                {
                    name = section.replace("filename=", "", Qt::CaseInsensitive);
                    name = name.replace("\"", "");
                }
            }
        }
        if(name.isEmpty())
        {
            name = url.toString().section('/', -1, -1, QString::SectionSkipEmpty).section('?', 0, 0);
        }
        QString type =
                reply->header(QNetworkRequest::ContentTypeHeader).toString().section("; ", 0, 0);
        if(type == "application/x-shockwave-flash")
        {
            return;
        }
        if(type.isEmpty())
        {
            type = trUtf8("Unavailable");
        }
        int bytes = reply->header(QNetworkRequest::ContentLengthHeader).toInt();
        QString size;
        if(bytes)
        {
            size = DownloadManager::sizeString(bytes);
        }
        else
        {
            size = trUtf8("Unavailable");
        }
        QString text = trUtf8("Name") + ": " + name + "\n" + trUtf8("Type") + ": " + type + "\n";
        text += trUtf8("Size") + ": " + size + "\n\n";
        text += trUtf8("What do you want to do with this file") + "?";
        QMessageBox question(QMessageBox::Question, trUtf8("Download file"), text);
        QPushButton * downloadButton =
                new QPushButton(QIcon(":/download-small.png"), trUtf8("Download"), &question);
        question.addButton(downloadButton, QMessageBox::AcceptRole);
        QPushButton * openButton =
                new QPushButton(QIcon(":/open-remote.png"), trUtf8("Open"),
                                &question);
        question.addButton(openButton, QMessageBox::AcceptRole);
        question.addButton(QMessageBox::Cancel);
        question.exec();
        if(question.clickedButton() == downloadButton)
        {
            QString path;
            if(SettingsManager::settingsManager()->downloadPath().isEmpty())
            {
                path = QDir::homePath() + "/" + name;
                path = QFileDialog::getSaveFileName(webView, trUtf8("Download file"), path);
            }
            else
            {
                path = SettingsManager::settingsManager()->downloadPath() + "/" + name;
            }
            if(!path.isEmpty())
            {
                DownloadManager::downloadManager()->download(url, QUrl(path));
            }
        }
        else if(question.clickedButton() == openButton)
        {
            QDesktopServices::openUrl(url);
        }
    }
}

void WebPage::authenticate(QNetworkReply * /*reply*/, QAuthenticator * authenticator)
{
    AuthenticationDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        authenticator->setUser(dialog.user());
        authenticator->setPassword(dialog.password());
    }
}

void WebPage::authenticate(const QNetworkProxy & /*proxy*/, QAuthenticator * authenticator)
{
    authenticate(0, authenticator);
}

void WebPage::handleSslErrors(QNetworkReply * reply, const QList<QSslError> & errors)
{
    Q_UNUSED(reply);Q_UNUSED(errors);
    /*
    NetworkAccessManager * manager = NetworkAccessManager::networkAccessManager();
    QString domain = reply->url().toString().section("/", 0, 2);
    if(manager->isTrustedDomain(QUrl(domain)))
    {
        reply->ignoreSslErrors();
    }
    else if(manager->isRejectedDomain(QUrl(domain)))
    {
        triggerAction(QWebPage::Stop);
    }
    else
    {
        QString text = trUtf8("Certificate of page") + " \"" + domain + "\" ";
        text += trUtf8("is incorrect") +".\n";
        text += trUtf8("Visiting this page may cause damage to your computer") + "!\n\n";
        text += trUtf8("Do you really trust this page") + "?";
        QString detailedText;
        for(int i = 0; i < errors.count(); i++)
        {
            QSslCertificate certificate = errors.at(i).certificate();
            QString issuerName = certificate.issuerInfo(QSslCertificate::CommonName);
            QString subjectName = certificate.subjectInfo(QSslCertificate::CommonName);
            detailedText += QString("----------------------------------------Error #%1").arg(i + 1);
            detailedText += "---------------------------------------\n";
            detailedText += trUtf8("Certificate issuer") + ": \"" + issuerName + "\"\n";
            detailedText += trUtf8("Certificate subject") + ": \"" + subjectName + "\"\n";
            detailedText += trUtf8("Error") + ": \"" + errors.at(i).errorString() + "\"\n";
            detailedText += "----------------------------------------------";
            detailedText += "------------------------------------------\n";
        }
        QMessageBox question(QMessageBox::Question, trUtf8("Security error"), text);
        question.setDetailedText(detailedText);
        QPushButton * trustButton =
                new QPushButton(QIcon(":/ok.png"), trUtf8("Only for this session"), &question);
        question.addButton(trustButton, QMessageBox::AcceptRole);
        QPushButton * trustAlwaysButton =
                new QPushButton(QIcon(":/ok.png"), trUtf8("Always"), &question);
        question.addButton(trustAlwaysButton, QMessageBox::AcceptRole);
        QPushButton * noButton = new QPushButton(QIcon(":/cancel.png"), trUtf8("No"), &question);
        question.addButton(noButton, QMessageBox::RejectRole);
        question.exec();
        if(question.clickedButton() == trustButton)
        {
            reply->ignoreSslErrors();
            manager->addTempTrustedDomain(QUrl(domain));
        }
        else if(question.clickedButton() == trustAlwaysButton)
        {
            reply->ignoreSslErrors();
            manager->addTrustedDomain(QUrl(domain));
        }
        else
        {
            triggerAction(QWebPage::Stop);
            manager->addTempRejectedDomain(QUrl(domain));
        }
    }
    */
}
