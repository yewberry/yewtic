/********************************************************************************
** Form generated from reading ui file 'settingsdialog.ui'
**
** Created: Wed Jan 13 16:25:54 2010
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QTabWidget *m_tabWidget;
    QWidget *m_contentsTab;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *m_imagesCheckBox;
    QCheckBox *m_javascriptCheckBox;
    QCheckBox *m_javaCheckBox;
    QCheckBox *m_pluginsCheckBox;
    QSpacerItem *verticalSpacer;
    QWidget *m_fontsTab;
    QGridLayout *gridLayout_2;
    QFontComboBox *m_serifFontComboBox;
    QFontComboBox *m_monoFontComboBox;
    QLabel *m_serifFontLabel;
    QLabel *m_sansFontLabel;
    QFontComboBox *m_sansFontComboBox;
    QSpinBox *m_standardFontSpinBox;
    QLabel *m_monoFontLabel;
    QSpinBox *m_monoFontSpinBox;
    QSpacerItem *verticalSpacer_2;
    QWidget *m_historyTab;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *m_privateBrowsingCheckBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_historyExpirationLabel;
    QComboBox *m_historyExpirationComboBox;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QWidget *m_diskTab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_downloadCheckBox;
    QLineEdit *m_downloadLineEdit;
    QToolButton *m_downloadToolButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_cacheSizeLabel;
    QSpinBox *m_cacheSizeSpinBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *m_defaultsButton;
    QSpacerItem *m_horizontalSpacer;
    QPushButton *m_okButton;
    QPushButton *m_applyButton;
    QPushButton *m_cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QString::fromUtf8("SettingsDialog"));
        SettingsDialog->resize(624, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/surfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsDialog->setWindowIcon(icon);
        verticalLayout_4 = new QVBoxLayout(SettingsDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_tabWidget = new QTabWidget(SettingsDialog);
        m_tabWidget->setObjectName(QString::fromUtf8("m_tabWidget"));
        m_contentsTab = new QWidget();
        m_contentsTab->setObjectName(QString::fromUtf8("m_contentsTab"));
        verticalLayout_2 = new QVBoxLayout(m_contentsTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_imagesCheckBox = new QCheckBox(m_contentsTab);
        m_imagesCheckBox->setObjectName(QString::fromUtf8("m_imagesCheckBox"));

        verticalLayout_2->addWidget(m_imagesCheckBox);

        m_javascriptCheckBox = new QCheckBox(m_contentsTab);
        m_javascriptCheckBox->setObjectName(QString::fromUtf8("m_javascriptCheckBox"));

        verticalLayout_2->addWidget(m_javascriptCheckBox);

        m_javaCheckBox = new QCheckBox(m_contentsTab);
        m_javaCheckBox->setObjectName(QString::fromUtf8("m_javaCheckBox"));

        verticalLayout_2->addWidget(m_javaCheckBox);

        m_pluginsCheckBox = new QCheckBox(m_contentsTab);
        m_pluginsCheckBox->setObjectName(QString::fromUtf8("m_pluginsCheckBox"));

        verticalLayout_2->addWidget(m_pluginsCheckBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        m_tabWidget->addTab(m_contentsTab, QString());
        m_fontsTab = new QWidget();
        m_fontsTab->setObjectName(QString::fromUtf8("m_fontsTab"));
        gridLayout_2 = new QGridLayout(m_fontsTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        m_serifFontComboBox = new QFontComboBox(m_fontsTab);
        m_serifFontComboBox->setObjectName(QString::fromUtf8("m_serifFontComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_serifFontComboBox->sizePolicy().hasHeightForWidth());
        m_serifFontComboBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Liberation Serif"));
        m_serifFontComboBox->setCurrentFont(font);

        gridLayout_2->addWidget(m_serifFontComboBox, 1, 1, 1, 1);

        m_monoFontComboBox = new QFontComboBox(m_fontsTab);
        m_monoFontComboBox->setObjectName(QString::fromUtf8("m_monoFontComboBox"));
        sizePolicy.setHeightForWidth(m_monoFontComboBox->sizePolicy().hasHeightForWidth());
        m_monoFontComboBox->setSizePolicy(sizePolicy);
        m_monoFontComboBox->setFontFilters(QFontComboBox::MonospacedFonts);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Liberation Mono"));
        m_monoFontComboBox->setCurrentFont(font1);

        gridLayout_2->addWidget(m_monoFontComboBox, 6, 1, 1, 1);

        m_serifFontLabel = new QLabel(m_fontsTab);
        m_serifFontLabel->setObjectName(QString::fromUtf8("m_serifFontLabel"));

        gridLayout_2->addWidget(m_serifFontLabel, 1, 0, 1, 1);

        m_sansFontLabel = new QLabel(m_fontsTab);
        m_sansFontLabel->setObjectName(QString::fromUtf8("m_sansFontLabel"));

        gridLayout_2->addWidget(m_sansFontLabel, 0, 0, 1, 1);

        m_sansFontComboBox = new QFontComboBox(m_fontsTab);
        m_sansFontComboBox->setObjectName(QString::fromUtf8("m_sansFontComboBox"));
        sizePolicy.setHeightForWidth(m_sansFontComboBox->sizePolicy().hasHeightForWidth());
        m_sansFontComboBox->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(m_sansFontComboBox, 0, 1, 1, 1);

        m_standardFontSpinBox = new QSpinBox(m_fontsTab);
        m_standardFontSpinBox->setObjectName(QString::fromUtf8("m_standardFontSpinBox"));
        m_standardFontSpinBox->setMinimum(5);
        m_standardFontSpinBox->setMaximum(25);
        m_standardFontSpinBox->setValue(12);

        gridLayout_2->addWidget(m_standardFontSpinBox, 0, 2, 1, 1);

        m_monoFontLabel = new QLabel(m_fontsTab);
        m_monoFontLabel->setObjectName(QString::fromUtf8("m_monoFontLabel"));

        gridLayout_2->addWidget(m_monoFontLabel, 6, 0, 1, 1);

        m_monoFontSpinBox = new QSpinBox(m_fontsTab);
        m_monoFontSpinBox->setObjectName(QString::fromUtf8("m_monoFontSpinBox"));
        m_monoFontSpinBox->setMinimum(5);
        m_monoFontSpinBox->setMaximum(25);
        m_monoFontSpinBox->setValue(12);

        gridLayout_2->addWidget(m_monoFontSpinBox, 6, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 0, 1, 3);

        m_tabWidget->addTab(m_fontsTab, QString());
        m_historyTab = new QWidget();
        m_historyTab->setObjectName(QString::fromUtf8("m_historyTab"));
        verticalLayout_3 = new QVBoxLayout(m_historyTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_privateBrowsingCheckBox = new QCheckBox(m_historyTab);
        m_privateBrowsingCheckBox->setObjectName(QString::fromUtf8("m_privateBrowsingCheckBox"));

        verticalLayout_3->addWidget(m_privateBrowsingCheckBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_historyExpirationLabel = new QLabel(m_historyTab);
        m_historyExpirationLabel->setObjectName(QString::fromUtf8("m_historyExpirationLabel"));

        horizontalLayout_3->addWidget(m_historyExpirationLabel);

        m_historyExpirationComboBox = new QComboBox(m_historyTab);
        m_historyExpirationComboBox->setObjectName(QString::fromUtf8("m_historyExpirationComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_historyExpirationComboBox->sizePolicy().hasHeightForWidth());
        m_historyExpirationComboBox->setSizePolicy(sizePolicy1);
        m_historyExpirationComboBox->setFrame(true);

        horizontalLayout_3->addWidget(m_historyExpirationComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        m_tabWidget->addTab(m_historyTab, QString());
        m_diskTab = new QWidget();
        m_diskTab->setObjectName(QString::fromUtf8("m_diskTab"));
        verticalLayout = new QVBoxLayout(m_diskTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_downloadCheckBox = new QCheckBox(m_diskTab);
        m_downloadCheckBox->setObjectName(QString::fromUtf8("m_downloadCheckBox"));

        horizontalLayout->addWidget(m_downloadCheckBox);

        m_downloadLineEdit = new QLineEdit(m_diskTab);
        m_downloadLineEdit->setObjectName(QString::fromUtf8("m_downloadLineEdit"));
        m_downloadLineEdit->setEnabled(true);
        m_downloadLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(m_downloadLineEdit);

        m_downloadToolButton = new QToolButton(m_diskTab);
        m_downloadToolButton->setObjectName(QString::fromUtf8("m_downloadToolButton"));
        m_downloadToolButton->setEnabled(false);
        m_downloadToolButton->setText(QString::fromUtf8("..."));

        horizontalLayout->addWidget(m_downloadToolButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_cacheSizeLabel = new QLabel(m_diskTab);
        m_cacheSizeLabel->setObjectName(QString::fromUtf8("m_cacheSizeLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(m_cacheSizeLabel->sizePolicy().hasHeightForWidth());
        m_cacheSizeLabel->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(m_cacheSizeLabel);

        m_cacheSizeSpinBox = new QSpinBox(m_diskTab);
        m_cacheSizeSpinBox->setObjectName(QString::fromUtf8("m_cacheSizeSpinBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m_cacheSizeSpinBox->sizePolicy().hasHeightForWidth());
        m_cacheSizeSpinBox->setSizePolicy(sizePolicy3);
        m_cacheSizeSpinBox->setMinimum(10);
        m_cacheSizeSpinBox->setMaximum(500);
        m_cacheSizeSpinBox->setSingleStep(10);
        m_cacheSizeSpinBox->setValue(50);

        horizontalLayout_2->addWidget(m_cacheSizeSpinBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        m_tabWidget->addTab(m_diskTab, QString());

        verticalLayout_4->addWidget(m_tabWidget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_defaultsButton = new QPushButton(SettingsDialog);
        m_defaultsButton->setObjectName(QString::fromUtf8("m_defaultsButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/defaults.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_defaultsButton->setIcon(icon1);

        horizontalLayout_4->addWidget(m_defaultsButton);

        m_horizontalSpacer = new QSpacerItem(144, 22, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(m_horizontalSpacer);

        m_okButton = new QPushButton(SettingsDialog);
        m_okButton->setObjectName(QString::fromUtf8("m_okButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_okButton->setIcon(icon2);

        horizontalLayout_4->addWidget(m_okButton);

        m_applyButton = new QPushButton(SettingsDialog);
        m_applyButton->setObjectName(QString::fromUtf8("m_applyButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/apply.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_applyButton->setIcon(icon3);

        horizontalLayout_4->addWidget(m_applyButton);

        m_cancelButton = new QPushButton(SettingsDialog);
        m_cancelButton->setObjectName(QString::fromUtf8("m_cancelButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_cancelButton->setIcon(icon4);

        horizontalLayout_4->addWidget(m_cancelButton);


        verticalLayout_4->addLayout(horizontalLayout_4);


        retranslateUi(SettingsDialog);

        m_tabWidget->setCurrentIndex(0);
        m_historyExpirationComboBox->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", 0, QApplication::UnicodeUTF8));
        m_imagesCheckBox->setText(QApplication::translate("SettingsDialog", "Images", 0, QApplication::UnicodeUTF8));
        m_javascriptCheckBox->setText(QApplication::translate("SettingsDialog", "Javascript scenarios", 0, QApplication::UnicodeUTF8));
        m_javaCheckBox->setText(QApplication::translate("SettingsDialog", "Java applets", 0, QApplication::UnicodeUTF8));
        m_pluginsCheckBox->setText(QApplication::translate("SettingsDialog", "Plugins (flash, etc)", 0, QApplication::UnicodeUTF8));
        m_tabWidget->setTabText(m_tabWidget->indexOf(m_contentsTab), QApplication::translate("SettingsDialog", "Contents", 0, QApplication::UnicodeUTF8));
        m_serifFontLabel->setText(QApplication::translate("SettingsDialog", "Serif Font", 0, QApplication::UnicodeUTF8));
        m_sansFontLabel->setText(QApplication::translate("SettingsDialog", "Sans Font", 0, QApplication::UnicodeUTF8));
        m_monoFontLabel->setText(QApplication::translate("SettingsDialog", "Monospace Font", 0, QApplication::UnicodeUTF8));
        m_tabWidget->setTabText(m_tabWidget->indexOf(m_fontsTab), QApplication::translate("SettingsDialog", "Fonts", 0, QApplication::UnicodeUTF8));
        m_privateBrowsingCheckBox->setText(QApplication::translate("SettingsDialog", "Private Browsing (visited pages will be not written to history)", 0, QApplication::UnicodeUTF8));
        m_historyExpirationLabel->setText(QApplication::translate("SettingsDialog", "Store each history item during", 0, QApplication::UnicodeUTF8));
        m_historyExpirationComboBox->clear();
        m_historyExpirationComboBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsDialog", "1 day", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "3 days", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "1 week", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "2 weeks", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "1 month", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "3 month", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "6 month", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsDialog", "1 year", 0, QApplication::UnicodeUTF8)
        );
        m_tabWidget->setTabText(m_tabWidget->indexOf(m_historyTab), QApplication::translate("SettingsDialog", "History", 0, QApplication::UnicodeUTF8));
        m_downloadCheckBox->setText(QApplication::translate("SettingsDialog", "Download everything to", 0, QApplication::UnicodeUTF8));
        m_cacheSizeLabel->setText(QApplication::translate("SettingsDialog", "Disk cache size", 0, QApplication::UnicodeUTF8));
        m_cacheSizeSpinBox->setSuffix(QApplication::translate("SettingsDialog", " Mb", 0, QApplication::UnicodeUTF8));
        m_tabWidget->setTabText(m_tabWidget->indexOf(m_diskTab), QApplication::translate("SettingsDialog", "Disk", 0, QApplication::UnicodeUTF8));
        m_defaultsButton->setText(QApplication::translate("SettingsDialog", "Return to defaults", 0, QApplication::UnicodeUTF8));
        m_okButton->setText(QApplication::translate("SettingsDialog", "OK", 0, QApplication::UnicodeUTF8));
        m_applyButton->setText(QApplication::translate("SettingsDialog", "Apply", 0, QApplication::UnicodeUTF8));
        m_cancelButton->setText(QApplication::translate("SettingsDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(SettingsDialog);
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
