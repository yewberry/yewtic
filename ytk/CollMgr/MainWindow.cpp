#include "MainWindow.h"

MainWindow::MainWindow(void)
{
}

MainWindow::~MainWindow(void)
{
}

void MainWindow::init(){
}

void MainWindow::buildTree(Fl_Tree *tree){
	tree->add("eMuleDl");
	char s[20];
	char* str = "大国学A";
	std::cout<<strlen(str)<<std::endl;
	fl_utf8from_mb(s, 20,str,strlen(str));
	tree->add(s);
	tree->add("eMuleDl/IT");
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
	char* str = "大国学A";
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