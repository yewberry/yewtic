#include "adressbar.h"
#include "historymanager.h"

AdressBar::AdressBar(const QUrl & url, QWidget * parent)
        : QLineEdit(parent)
{
    m_view = new QTreeView(this);
    m_view->header()->setResizeMode(QHeaderView::Stretch);
    m_view->setRootIsDecorated(false);

    QCompleter * completer = new QCompleter(this);
    completer->setModel(HistoryManager::historyManager());
    completer->setPopup(m_view);
    setCompleter(completer);

    if(url != QUrl("about:blank"))
    {
        setUrl(url);
        load();
    }

    connect(this, SIGNAL(returnPressed()), this, SLOT(load()));
}

QUrl AdressBar::url() const
{
    return QUrl(text());
}

void AdressBar::setUrl(const QUrl & url)
{
    setText(url.toString());
}

void AdressBar::load()
{
    QString text(this->text().toLower());
    if(text.startsWith("g "))
    {
        text.remove(0, 2);
        text = "http://www.google.com/search?q=" + text;
    }
    else if(text.startsWith("w "))
    {
        text.remove(0, 2);
        text = "http://en.wikipedia.org/w/index.php?search=" + text;
    }
    else if(text.startsWith("y "))
    {
        text.remove(0, 2);
        text = "http://www.youtube.com/results?search_query=" + text;
    }
    else if(QUrl(text).scheme().isEmpty())
    {
        text = "http://" + text;
    }
    QUrl url(text);
    setUrl(url);
    emit loadRequsted(url);
}
