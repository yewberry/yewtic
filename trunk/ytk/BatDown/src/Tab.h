#ifndef TAB_H
#define TAB_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class ToolBar;
class AdressBar;
class WebView;

class Tab : public QWidget
{
    Q_OBJECT

public:
    Tab(const QUrl & url, QWidget * parent = 0);
    QUrl url() const;
    QString title() const;
    WebView * webView() const;

private:
    ToolBar * m_toolBar;
    WebView * m_webView;
    SearchBar * m_searchBar;
    StatusBar * m_statusBar;
    QVBoxLayout * m_layout;
    QShortcut * m_showSearchShortcut;
    QShortcut * m_focusAdressShortcut;

public slots:
    void reload();
    void load(const QUrl & url);

private slots:
    void updateTitle();
    void updateIcon();
};

#endif // TAB_H
