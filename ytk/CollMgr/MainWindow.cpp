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
	ui->totalFiles->value("abc");;
	
	TableView *table1 = ui->tableView;
	table1->selection_color(FL_YELLOW);
    table1->when(FL_WHEN_RELEASE);	// handle table events on release
    table1->rows(10000);
    table1->cols(10000);
    table1->col_header(1);		// enable col header
    table1->col_resize(4);		// enable col resizing
    table1->row_header(1);		// enable row header
    table1->row_resize(4);		// enable row resizing
    table1->when(FL_WHEN_CHANGED|FL_WHEN_RELEASE);
    table1->end();
	
	CppSQLite3DB db;
	std::cout<<db.SQLiteVersion()<<std::endl;
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