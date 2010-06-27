#include "zoomslider.h"

ZoomSlider::ZoomSlider(QWidget * parent)
        : QSlider(parent)
{
    setOrientation(Qt::Horizontal);
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    setRange(20, 500);
    setSingleStep(10);
    setValue(100);
    setToolTip(100);

    connect(this, SIGNAL(valueChanged(int)), this, SLOT(setToolTip(int)));
}

void ZoomSlider::increaseValue()
{
    setValue(value() + singleStep());
}

void ZoomSlider::decreaseValue()
{
    setValue(value() - singleStep());
}

void ZoomSlider::returnToOriginalValue()
{
    setValue(100);
}

void ZoomSlider::setToolTip(int value)
{
    QWidget::setToolTip(trUtf8("Zoom") + ": " + QString::number(value) + "%");
}
