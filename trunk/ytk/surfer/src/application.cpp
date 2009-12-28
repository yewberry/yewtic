#include "application.h"
#include "mainwindow.h"
#include "tabmanager.h"

Application::Application(int & argc, char ** argv)
        : QApplication(argc, argv)
        , m_urlsSocket(0)
        , m_window(0)
{
    setApplicationName("Surfer");
    setApplicationVersion("0.7");

    QTranslator * translator = new QTranslator(this);
    translator->load(QLocale::system().name(), QApplication::applicationDirPath());
    installTranslator(translator);

    for(int i = 0; i < argc; i++)
    {
        QUrl url(argv[i]);
        if(!url.scheme().isEmpty())
        {
            m_clUrls += url;
        }
    }

    m_urlsServer = new QTcpServer(this);
    bool isFirstRun = m_urlsServer->listen(QHostAddress::LocalHost, 7777);

    if(isFirstRun)
    {
        connect(m_urlsServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
        m_window = new MainWindow();
        m_window->show();
    }

    m_initialSocket = new QTcpSocket(this);
    m_initialSocket->connectToHost(QHostAddress::LocalHost, 7777);
    connect(m_initialSocket, SIGNAL(connected()), this, SLOT(writeUrls()));
    if(!isFirstRun)
    {
        connect(m_initialSocket, SIGNAL(disconnected()), qApp, SLOT(quit()));
    }
}

Application::~Application()
{
    if(m_window)
    {
        m_window->deleteLater();
    }
}

void Application::writeUrls()
{
    QByteArray data;
    foreach(QUrl url, m_clUrls)
    {
        data += url.toString().toUtf8();
        data += "\n";
    }
    m_initialSocket->write(data);
    m_initialSocket->disconnectFromHost();
}

void Application::acceptConnection()
{
    if(m_urlsSocket)
    {
        m_urlsSocket->deleteLater();
    }
    m_urlsSocket = m_urlsServer->nextPendingConnection();
    connect(m_urlsSocket, SIGNAL(readyRead()), this, SLOT(openUrls()));
}

void Application::openUrls()
{
    QByteArray array;
    while(!(array = m_urlsSocket->readLine()).isEmpty())
    {
        QString urlString = QString::fromUtf8(array.data()).trimmed();
        TabManager::tabManager()->addTab(QUrl(urlString));
    }
}
