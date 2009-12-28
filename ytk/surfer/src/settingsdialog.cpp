#include "settingsdialog.h"
#include "settingsmanager.h"

SettingsDialog::SettingsDialog()
{
    setupUi(this);
    QRect geometry = SettingsManager::settingsManager()->settingsDialogGeometry();
    if(geometry != QRect())
    {
        setGeometry(geometry);
    }

    m_historyExpirationComboBox->setItemData(0, 1);
    m_historyExpirationComboBox->setItemData(1, 3);
    m_historyExpirationComboBox->setItemData(2, 7);
    m_historyExpirationComboBox->setItemData(3, 14);
    m_historyExpirationComboBox->setItemData(4, 30);
    m_historyExpirationComboBox->setItemData(5, 90);
    m_historyExpirationComboBox->setItemData(6, 180);
    m_historyExpirationComboBox->setItemData(7, 360);

    connect(m_defaultsButton, SIGNAL(clicked()), this, SLOT(defaults()));
    connect(m_okButton, SIGNAL(clicked()), this, SLOT(ok()));
    connect(m_applyButton, SIGNAL(clicked()), this, SLOT(apply()));
    connect(m_cancelButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(m_downloadCheckBox, SIGNAL(toggled(bool)), m_downloadToolButton, SLOT(setEnabled(bool)));
    connect(m_downloadToolButton, SIGNAL(clicked()), this, SLOT(openNewDirectory()));
}

void SettingsDialog::showEvent(QShowEvent * /*event*/)
{
    SettingsManager * manager = SettingsManager::settingsManager();
    m_imagesCheckBox->setChecked(manager->isImagesEnabled());
    m_javascriptCheckBox->setChecked(manager->isJavascriptEnabled());
    m_javaCheckBox->setChecked(manager->isJavaEnabled());
    m_pluginsCheckBox->setChecked(manager->isPluginsEnabled());
    m_privateBrowsingCheckBox->setChecked(manager->isPrivateBrowsingEnabled());
    m_cacheSizeSpinBox->setValue(manager->maximumCacheSize() / 1024 / 1024);
    m_historyExpirationComboBox->setCurrentIndex(2);
    for(int i = 0; i < 8; i++)
    {
        if(m_historyExpirationComboBox->itemData(i).toInt() == manager->historyExpirationDays())
        {
            m_historyExpirationComboBox->setCurrentIndex(i);
            break;
        }
    }
    QString path = manager->downloadPath();
    if(path.isEmpty())
    {
        m_downloadCheckBox->setChecked(false);
    }
    else
    {
        m_downloadCheckBox->setChecked(true);
        m_downloadLineEdit->setText(path);
    }
    m_standardFontSpinBox->setValue(manager->standardFontSize());
    m_monoFontSpinBox->setValue(manager->monoFontSize());
}

void SettingsDialog::resizeEvent(QResizeEvent * /*event*/)
{
    SettingsManager::settingsManager()->setSettingsDialogGeometry(geometry());
}

void SettingsDialog::moveEvent(QMoveEvent * /*event*/)
{
    SettingsManager::settingsManager()->setSettingsDialogGeometry(geometry());
}

void SettingsDialog::openNewDirectory()
{
    QString path = m_downloadLineEdit->text();
    if(path.isEmpty())
    {
        path = QDir::homePath();
    }
    path = QFileDialog::getExistingDirectory(this, trUtf8("Choose directory"), path);
    if(!path.isEmpty())
    {
        m_downloadLineEdit->setText(path);
    }
}

void SettingsDialog::defaults()
{
    m_imagesCheckBox->setChecked(true);
    m_javascriptCheckBox->setChecked(true);
    m_javaCheckBox->setChecked(true);
    m_pluginsCheckBox->setChecked(true);
    m_privateBrowsingCheckBox->setChecked(false);
    m_cacheSizeSpinBox->setValue(50);
    m_historyExpirationComboBox->setCurrentIndex(2);
    m_downloadCheckBox->setChecked(false);
    m_standardFontSpinBox->setValue(12);
    m_monoFontSpinBox->setValue(12);
}

void SettingsDialog::ok()
{
    apply();
    close();
}
void SettingsDialog::apply()
{
    SettingsManager * manager = SettingsManager::settingsManager();
    manager->setImagesEnabled(m_imagesCheckBox->isChecked());
    manager->setJavascriptEnabled(m_javascriptCheckBox->isChecked());
    manager->setJavaEnabled(m_javaCheckBox->isChecked());
    manager->setPluginsEnabled(m_pluginsCheckBox->isChecked());
    manager->setPrivateBrowsingEnabled(m_privateBrowsingCheckBox->isChecked());
    manager->setMaximumCacheSize(m_cacheSizeSpinBox->value() * 1024 * 1024);
    int index = m_historyExpirationComboBox->currentIndex();
    int days = m_historyExpirationComboBox->itemData(index).toInt();
    manager->setHistoryExpirationDays(days);
    QString path;
    if(m_downloadCheckBox->isChecked())
    {
        path = m_downloadLineEdit->text();
    }
    else
    {
        path = "";
    }
    manager->setDownloadPath(path);
    manager->setSansFontFamily(m_sansFontComboBox->currentFont().family());
    manager->setSerifFontFamily(m_serifFontComboBox->currentFont().family());
    manager->setMonoFontFamily(m_monoFontComboBox->currentFont().family());
    manager->setStandardFontSize(m_standardFontSpinBox->value());
    manager->setMonoFontSize(m_monoFontSpinBox->value());
}
