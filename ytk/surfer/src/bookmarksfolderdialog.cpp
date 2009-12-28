#include "bookmarksfolderdialog.h"
#include "bookmarksfolderview.h"

BookmarksFolderDialog::BookmarksFolderDialog()
{
    setWindowIcon(QIcon(":/surfer.png"));
    setWindowTitle(trUtf8("Add bookmark"));
    resize(300, 300);

    m_titleLabel = new QLabel(trUtf8("Title") + ":", this);
    m_titleEdit = new QLineEdit(this);
    m_folderLabel = new QLabel(trUtf8("Folder") + ":");
    m_view = new BookmarksFolderView(this);
    m_createFolderButton =
            new QPushButton(QIcon(":/createFolder.png"), trUtf8("Create folder") + "...", this);
    m_okButton = new QPushButton(QIcon(":/ok.png"), trUtf8("OK"), this);
    m_cancelButton = new QPushButton(QIcon(":/cancel.png"), trUtf8("Cancel"), this);
    QHBoxLayout * hboxlayout = new QHBoxLayout();
    hboxlayout->addWidget(m_createFolderButton, 0);
    hboxlayout->addWidget(m_okButton, 0);
    hboxlayout->addWidget(m_cancelButton, 0);
    hboxlayout->addStretch(1);
    QVBoxLayout * vboxlayout = new QVBoxLayout(this);
    vboxlayout->addWidget(m_titleLabel, 0);
    vboxlayout->addWidget(m_titleEdit, 0);
    vboxlayout->addWidget(m_folderLabel, 0);
    vboxlayout->addWidget(m_view, 1);
    vboxlayout->addLayout(hboxlayout, 0);

    connect(m_createFolderButton, SIGNAL(clicked()), m_view, SLOT(createFolder()));
    connect(m_okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

QString BookmarksFolderDialog::title() const
{
    return m_titleEdit->text();
}

void BookmarksFolderDialog::setTitle(const QString & title)
{
    m_titleEdit->setFocus();
    m_titleEdit->setText(title);
    m_titleEdit->selectAll();
}

QModelIndex BookmarksFolderDialog::parentIndex() const
{
    return m_view->currentSourceIndex();
}
