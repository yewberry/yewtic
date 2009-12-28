#ifndef APPLICATION_H
#define APPLICATION_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class MainWindow;
class TabManager;

class Application
        : public QApplication
{
    Q_OBJECT

public:
    Application(int & argc, char ** argv);
    ~Application();

private:
    QTcpSocket * m_initialSocket;
    QTcpServer * m_urlsServer;
    QTcpSocket * m_urlsSocket;
    MainWindow * m_window;
    QList<QUrl> m_clUrls;

private slots:
    void writeUrls();
    void acceptConnection();
    void openUrls();
};

#endif // APPLICATION_H
