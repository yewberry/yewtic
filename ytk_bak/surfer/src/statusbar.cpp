#include "statusbar.h"
#include "zoomslider.h"

StatusBar::StatusBar(QWidget * parent)
        : QToolBar(parent)
{
    m_label = new QLabel(this);
    m_label->setMargin(1);
    m_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    addWidget(m_label);

    m_zoomOutAction = addAction(QIcon(":/zoom-out.png"), trUtf8("Zoom out"));
    m_zoomOutAction->setShortcut(QKeySequence::ZoomOut);

    m_slider = new ZoomSlider(this);
    addWidget(m_slider);

    m_zoomInAction = addAction(QIcon(":/zoom-in.png"), trUtf8("Zoom in"));
    m_zoomInAction->setShortcut(QKeySequence::ZoomIn);
    m_zoomOriginalAction = addAction(QIcon(":/zoom-original.png"), trUtf8("Original zoom"));
    m_zoomOriginalAction->setShortcut(Qt::CTRL + Qt::Key_0);

    m_progressBar = new QProgressBar(this);
    m_progressBar->setFixedHeight(16);
    m_progressBar->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    addWidget(m_progressBar);

    connect(m_zoomOutAction, SIGNAL(triggered()), m_slider, SLOT(decreaseValue()));
    connect(m_zoomInAction, SIGNAL(triggered()), m_slider, SLOT(increaseValue()));
    connect(m_zoomOriginalAction, SIGNAL(triggered()), m_slider, SLOT(returnToOriginalValue()));
}

QProgressBar * StatusBar::progressBar()
{
    return m_progressBar;
}

QSlider * StatusBar::slider()
{
    return m_slider;
}

void StatusBar::showMessage(const QString & message)
{
    QString m = message;
    if(m.length() > 120)
    {
        m.truncate(118);
        m += "..";
    }
    m_label->setText(m);
}
