#ifndef TAB_H
#define TAB_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>
#include "BatDown.h"

class WebView;

class Tab : public QWidget, public BatDownBase
{
    Q_OBJECT

public:
    Tab(BatDown *app, QWidget *parent = 0);
    QUrl url() const;
    QString title() const;
    WebView* webView() const;

public slots:
    void reload();
    void load(const QUrl &url, const QString &scriptFilename);

private slots:
    void updateTitle();
    void updateIcon();
	void updateProgress(int);

private:
    WebView		*m_pWebView;
};

#endif // TAB_H
