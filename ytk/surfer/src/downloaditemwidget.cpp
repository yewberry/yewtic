#include "downloaditemwidget.h"
#include "downloadmanager.h"
#include "downloaditem.h"

DownloadItemWidget::DownloadItemWidget(DownloadItem * item, QWidget * parent)
        : QWidget(parent)
        , m_item(item)
{
    m_fromEdit = new QLineEdit(this);
    m_fromEdit->setReadOnly(true);
    m_fromEdit->setText(m_item->from().toString());

    m_toEdit = new QLineEdit(this);
    m_toEdit->setReadOnly(true);
    m_toEdit->setText(m_item->to().toString());

    m_progressBar = new QProgressBar(this);

    QToolBar * toolBar = new QToolBar(this);
    m_abortAction = toolBar->addAction(QIcon(":/delete.png"), trUtf8("Abort"));

    QHBoxLayout * hlayout = new QHBoxLayout();
    hlayout->setMargin(0);
    hlayout->setSpacing(0);
    hlayout->addWidget(m_progressBar, 1);
    hlayout->addWidget(toolBar, 0);

    QVBoxLayout * vlayout = new QVBoxLayout(this);
    vlayout->setMargin(0);
    vlayout->setSpacing(0);
    vlayout->addWidget(m_fromEdit, 0);
    vlayout->addWidget(m_toEdit, 0);
    vlayout->addLayout(hlayout, 0);

    connect(m_item, SIGNAL(finished()), this, SLOT(updateProgress()));
    connect(m_item, SIGNAL(progressChanged(int)), this, SLOT(updateProgress()));
    connect(m_abortAction, SIGNAL(triggered()), m_item, SLOT(abort()));
}

void DownloadItemWidget::updateProgress()
{
    DownloadManager * manager = DownloadManager::downloadManager();
    QString text = manager->sizeString(m_item->received()) + " / ";
    text += manager->sizeString(m_item->total()) + " (";
    if(m_item->isFinished())
    {
        if(m_item->progress() == 100)
        {
            text += trUtf8("Finished");
        }
        else
        {
            text += trUtf8("Aborted");
        }
        m_abortAction->setEnabled(false);
    }
    else
    {
        text += QString::number(m_item->progress()) + "%";
    }
    text += ")";
    m_progressBar->setValue(m_item->progress());
    m_progressBar->setFormat(text);
}
