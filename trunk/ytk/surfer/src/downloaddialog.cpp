#include "downloaddialog.h"
#include "downloadview.h"
#include "downloadmanager.h"
#include "settingsmanager.h"

DownloadDialog::DownloadDialog()
{
    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle(trUtf8("Downloads"));
    resize(600, 400);
    QRect geometry = SettingsManager::settingsManager()->downloadDialogGeometry();
    if(geometry != QRect())
    {
        setGeometry(geometry);
    }

    m_view = new DownloadView(this);
    m_clearButton = new QPushButton(this);
    m_clearButton->setIcon(QIcon(":/clear.png"));
    m_clearButton->setText(trUtf8("Clear finished downloads list"));
    QHBoxLayout * hboxlayout = new QHBoxLayout();
    hboxlayout->addStretch(1);
    hboxlayout->addWidget(m_clearButton, 0);
    QVBoxLayout * vboxlayout = new QVBoxLayout(this);
    vboxlayout->addWidget(m_view, 1);
    vboxlayout->addLayout(hboxlayout, 0);

    connect(m_clearButton, SIGNAL(clicked()), DownloadManager::downloadManager(), SLOT(clearFinished()));
}

void DownloadDialog::resizeEvent(QResizeEvent * /*event*/)
{
    SettingsManager::settingsManager()->setDownloadDialogGeometry(geometry());
}

void DownloadDialog::moveEvent(QMoveEvent * /*event*/)
{
    SettingsManager::settingsManager()->setDownloadDialogGeometry(geometry());
}
