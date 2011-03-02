#include "MyQtLog.h"

MyQtLog *MyQtLog::log = 0;
pthread_mutex_t MyQtLog::m_mutex = PTHREAD_MUTEX_INITIALIZER;

MyQtLog::MyQtLog(QWidget *parent)
    : QWidget(parent), file(0), filename("")
{
	ui.setupUi(this);
	brs = ui.logBrs;

}

MyQtLog::~MyQtLog(void)
{
	if(file != 0){
		file->close();
		delete file;
	}
}

MyQtLog* MyQtLog::init(QString path, QWidget *parent){
	if(log == 0){
		log = new MyQtLog(parent);
		if(!path.isEmpty()){
			QFile *f = new QFile(path);
			if (f->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append | QIODevice::Unbuffered)){
				log->file = f;
				log->filename = path;
			} else {
				yERROR(QString("Can't open log file: %1").arg(path));
			}
		}
	}
	return log;
}

void MyQtLog::d(QString msg, char *file, int line){
	write(QString("<span style=\"color:gray\">[DEBUG] %1 (%2:%3)</span>").arg(msg).arg(file).arg(line));
}
void MyQtLog::i(QString msg, char *file, int line){
	write(QString("<span style=\"color:blue\">[INFO ] %1 (%2:%3)</span>").arg(msg).arg(file).arg(line));
}
void MyQtLog::w(QString msg, char *file, int line){
	write(QString("<span style=\"color:orange\"><b>[WARN ] %1 (%2:%3)</></span>").arg(msg).arg(file).arg(line));
}
void MyQtLog::e(QString msg, char *file, int line){
	write(QString("<span style=\"color:red\"><b>[ERROR] %1 (%2:%3)</b></span>").arg(msg).arg(file).arg(line));
}
void MyQtLog::f(QString msg, char *file, int line){
	write(QString("<span style=\"color:red\"><b>[FATAL] %1 (%2:%3)</b></span>").arg(msg).arg(file).arg(line));
}

void MyQtLog::write(QString msg){
	brs->append(msg.toLocal8Bit());
	QTextStream out(file);
	out<<msg<<"<br>\n";
}
