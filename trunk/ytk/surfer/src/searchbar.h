#ifndef SEARCHBAR_H
#define SEARCHBAR_H

#include <QtCore>
#include <QtGui>
#include <QtWebKit>

class SearchBar
        : public QToolBar
{
    Q_OBJECT

public:
    SearchBar(QWidget * parent = 0);

protected:
    void showEvent(QShowEvent * event);

private:
    QLineEdit * m_lineEdit;
    QAction * m_closeAction;
    QAction * m_previousAction;
    QAction * m_nextAction;
    QCheckBox * m_checkBox;

private slots:
    void changeSearchData();

signals:
    void searchDataChanged(const QString & text, bool forward, bool caseSensitive);
    void closeRequested();
};

#endif // SEARCHBAR_H
