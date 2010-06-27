#include "searchbar.h"

SearchBar::SearchBar(QWidget * parent)
        : QToolBar(parent)
{
    m_closeAction = addAction(QIcon(":/close.png"), trUtf8("Hide search bar"));
    m_closeAction->setShortcut(Qt::Key_Escape);
    QLabel * label = new QLabel(trUtf8("Search"), this);
    addWidget(label);
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    addWidget(m_lineEdit);
    m_previousAction = addAction(QIcon(":/previous.png"), trUtf8("Find previous"));
    m_previousAction->setShortcut(QKeySequence::FindPrevious);
    m_nextAction = addAction(QIcon(":/next.png"), trUtf8("Find next"));
    m_nextAction->setShortcut(QKeySequence::FindNext);
    m_checkBox = new QCheckBox(trUtf8("Case-sensitive"), this);
    addWidget(m_checkBox);

    connect(m_closeAction, SIGNAL(triggered()), this, SIGNAL(closeRequested()));
    connect(m_lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(changeSearchData()));
    connect(m_previousAction, SIGNAL(triggered()), this, SLOT(changeSearchData()));
    connect(m_nextAction, SIGNAL(triggered()), this, SLOT(changeSearchData()));
}

void SearchBar::showEvent(QShowEvent * /*event*/)
{
    m_lineEdit->setFocus();
}

void SearchBar::changeSearchData()
{
    QAction * action = qobject_cast<QAction *>(sender());
    if(!action || action == m_nextAction)
    {
        emit searchDataChanged(m_lineEdit->text(), true, m_checkBox->isChecked());
    }
    else if(action == m_previousAction)
    {
        emit searchDataChanged(m_lineEdit->text(), false, m_checkBox->isChecked());
    }
}
