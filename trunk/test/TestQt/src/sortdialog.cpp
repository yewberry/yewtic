#include <QtGui>

#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    setupUi(this);

    /*
     * set hide first and setVisible when button click (see ui file)
     */
    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();

    layout()->setSizeConstraint(QLayout::SetFixedSize);
}
