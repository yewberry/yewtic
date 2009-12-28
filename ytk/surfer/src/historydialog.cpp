#include "historydialog.h"
#include "historyview.h"
#include "mainwindow.h"
#include "historymanager.h"
#include "historyfiltermodel.h"
#include "settingsmanager.h"

HistoryDialog::HistoryDialog()
{
    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle(trUtf8("History"));
    resize(600, 400);
    QRect geometry = SettingsManager::settingsManager()->historyDialogGeometry();
    if(geometry != QRect())
    {
        setGeometry(geometry);
    }

    m_view = new HistoryView(this);
    QLabel * label = new QLabel(trUtf8("Search"), this);
    m_lineEdit = new QLineEdit(this);
    m_clearButton = new QPushButton(this);
    m_clearButton->setIcon(QIcon(":/clear.png"));
    m_clearButton->setText(trUtf8("Clear history") + "...");
    QHBoxLayout * hlayout = new QHBoxLayout();
    hlayout->addWidget(label, 0);
    hlayout->addWidget(m_lineEdit, 1);
    hlayout->addWidget(m_clearButton, 0);
    QVBoxLayout * vlayout = new QVBoxLayout(this);
    vlayout->addWidget(m_view, 1);
    vlayout->addLayout(hlayout, 0);

    connect(m_lineEdit, SIGNAL(textChanged(const QString &)),
            m_view->model(), SLOT(setFilterFixedString(const QString &)));
    connect(m_clearButton, SIGNAL(clicked()),
            this, SLOT(clear()));
}

void HistoryDialog::resizeEvent(QResizeEvent * /*event*/)
{
    SettingsManager::settingsManager()->setHistoryDialogGeometry(geometry());
}

void HistoryDialog::moveEvent(QMoveEvent * /*event*/)
{
    SettingsManager::settingsManager()->setHistoryDialogGeometry(geometry());
}


void HistoryDialog::clear()
{
    if(QMessageBox::question(this, trUtf8("History"),
                             trUtf8("Do you really want to clear history?"),
                             QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
    {
        HistoryManager::historyManager()->clear();
    }
}
