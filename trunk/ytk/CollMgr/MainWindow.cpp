#include "MainWindow.h"
#include "MainWindowUI.h"

MainWindow::MainWindow(void)
{
}

MainWindow::~MainWindow(void)
{
}

void MainWindow::show(int argc, char **argv){
	ui = new MainWindowUI;
	ui->init(this);
	ui->treeView->load("etc/catalog.xml");
	ui->show(argc, argv);
}

void MainWindow::log_switch_cb(){
	if(LogIsVisible()){
		LogHide();
	} else {
		LogShow();
	}
}

void MainWindow::test_cb(){
	std::cout<<"haha"<<std::endl;
	std::cerr<<"xixi";
	char s[20];
	char* str = "´ó¹úÑ§A";
	std::cout<<strlen(str)<<std::endl;
	fl_utf8from_mb(s, 20,str,strlen(str));
	LogInfo((s));
}

Log* MainWindow::getLogWindow(){
	return m_pLog;
}

void MainWindow::setLogWindow(Log *log){
	m_pLog = log;
}