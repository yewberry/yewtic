#ifndef EMULEMANAGER_H
#define EMULEMANAGER_H

#include <QtGui/QMainWindow>
#include "ui_EmuleManager.h"

class EmuleManager : public QMainWindow
{
	Q_OBJECT

public:
	EmuleManager(QWidget *parent = 0, Qt::WFlags flags = 0);
	~EmuleManager();

private:
	Ui::EmuleManagerClass ui;
};

#endif // EMULEMANAGER_H
