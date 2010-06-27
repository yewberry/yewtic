#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class NetworkAccessManager;
class DownloadManager;
class SettingsManager;
class AuthenticationDialog;

class WebPage
        : public QWebPage
{
    Q_OBJECT

public:
    WebPage(QObject * parent = 0);

protected:
    QString chooseFile(QWebFrame * parentFrame, const QString & suggestedFile);
    bool acceptNavigationRequest(QWebFrame * frame, const QNetworkRequest & request,
                                 NavigationType type);

private slots:
    void handleUnsupportedContent(QNetworkReply * reply);
    void download(const QNetworkRequest & request);
    void handleHeaders();
    void authenticate(QNetworkReply * reply, QAuthenticator * authenticator);
    void authenticate(const QNetworkProxy & proxy, QAuthenticator * authenticator);
    void handleSslErrors(QNetworkReply * reply, const QList<QSslError> & errors);
};

#endif // WEBPAGE_H
