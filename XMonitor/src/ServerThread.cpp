/*
 * ServerThread.cpp
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#include "ServerThread.h"
#include <QtSql>
#include <QtScript>

#include "Comm.h"
#include "SSH2Utils.h"
#include "XMonitor.h"
#include "ServerView.h"
#include "ServerViewNode.h"
#include "ServerModel.h"
#include "StepModel.h"

#include "qjson/parser.h"
#include "qjson/serializer.h"

//#define YDEBUG 1

ServerThread::ServerThread(QObject *parent, int inter)
	: XThread(parent, inter)
{
}
void ServerThread::run()
{
    while (!m_stopped){
    	ServerModel model;
    	QVector<QSqlRecord> svrs = model.getRecords();

    	//yTDEBUG(QString("Serv count %1").arg(recs.count()));
		for (int i = 0; i < svrs.count(); ++i) {
			QSqlRecord svr = svrs.at(i);
			bool act = svr.value(ServerModel::ACTIVE).toBool();

			if(!act) continue;

			QString nm = svr.value(ServerModel::NAME).toString();
			QString ip = svr.value(ServerModel::IP).toString();
			QString usr = svr.value(ServerModel::USR).toString();
			QString pwd = svr.value(ServerModel::PWD).toString();

			yTINFO( QString("Inspecting server %1(%2)...").arg(nm).arg(ip) );
			QString svrId = svr.value(ServerModel::ID).toString();
			StepModel stepModel(this);
			stepModel.setModelBySvrId(svrId);
			QVector<QSqlRecord> steps = stepModel.getRecords();

			yTINFO( QString("%1 step(s) found.").arg(steps.count()) );
			SSH2Utils* pSsh = getSsh(ip, usr, pwd);
			if(pSsh != 0){
				QVariantMap stepCtx;
				bool svrStat = true;
				for(int j=0; j<steps.count(); ++j){
					QSqlRecord step = steps.at(j);
					QVariantMap hm = runStepScript(step, pSsh, stepCtx);
					if( hm.contains("server_failure") ){
						svrStat = hm.value("server_failure").toBool();
						/*
						if(!ok){
							QString stepNm = step.value(StepModel::NAME).toString();
							yTERROR(tr("Server status property (%1) in step %2 can't convert to int.").arg(svrStat).arg(stepNm));
						}
						*/
					}
				}

				QJson::Serializer serializer;
				QString xCtx = QString(serializer.serialize(stepCtx));
				yTDEBUG(QString("ALL STEPS: %1").arg(xCtx));
				svr.setValue(ServerModel::STATUS, svrStat);
				svr.setValue(ServerModel::STEP_STATUS, xCtx);
				model.editRecordById(svrId, svr);
			}
			delete pSsh;
		}//SERVERS END

    	msleep(m_threadInter);
    }
    m_stopped = false;

	//XMonitor *app = (XMonitor*)this->parent();
	//ServerViewNode *item = dynamic_cast<ServerViewNode *>(app->serverView()->getItemById(id));

}

SSH2Utils* ServerThread::getSsh(QString ip, QString usr, QString pwd) {
	SSH2Utils *pSsh = new SSH2Utils;
	if (pSsh->init() < 0) {
		yTERROR(pSsh->errMsg());
		delete pSsh;
		return 0;
	}
	int rc = 0;
	std::string _ip = ip.toStdString();
	std::string _usr = usr.toStdString();
	std::string _pwd = pwd.toStdString();
	yTINFO(QString("Connecting to %1@%2").arg(_ip.c_str()).arg(_usr.c_str()));
	rc = pSsh->connect(_ip.c_str(), _usr.c_str(), _pwd.c_str());

	if (rc == 0) {
		return pSsh;

	} else {
		yTERROR(pSsh->errMsg());
#ifdef YDEBUG
		return pSsh;
#else
		delete pSsh;
		return 0;
#endif
	}
}

QVariantMap ServerThread::runStepScript(QSqlRecord stepRec, SSH2Utils* pSsh, QVariantMap &stepCtx){
	QString stepNm = stepRec.value(StepModel::NAME).toString();
	QString stepCmd = stepRec.value(StepModel::CMD).toString();
	QString script = stepRec.value(StepModel::SCRIPT).toString();

	yTINFO( QString("Run step: %1...").arg(stepNm) );
	std::string str = "";
	if(!stepCmd.isEmpty()){
		std::string cmdstr = stepCmd.toStdString();
		yTDEBUG( QString("Execute command: %1").arg(cmdstr.c_str()) );
#ifdef YDEBUG
		std::string str = stepRec.value(StepModel::CMD_RESULT).toString().toStdString();
#else
		int rc = pSsh->exec( cmdstr.c_str() );
		str = pSsh->execResultStr();
#endif
	}
	QScriptEngine engine;

	QJson::Serializer serializer;
	QString xCtx = QString( serializer.serialize(stepCtx) );
	engine.globalObject().setProperty("xCtx", QString("var xCtx=%1").arg(xCtx));

	QString result = QString::fromStdString(str);
	engine.globalObject().setProperty("xIn", result);

	QVariantMap rtn;
	rtn.insert("status", -1);
	QScriptValue res = engine.evaluate(script);
	if (engine.hasUncaughtException()) {
		yTERROR(engine.uncaughtException().toString());
		yTERROR(engine.uncaughtExceptionBacktrace().join("\n"));

	} else {
		QString scriptReturn = res.toString();
		yTDEBUG( QString("Script Result:%1").arg(scriptReturn) );
		QJson::Parser parser;
		bool ok;
		rtn = parser.parse(scriptReturn.toLocal8Bit(), &ok).toMap();
		if (!ok) {
			yTERROR( QString("An error occurred during parsing JSON: %1").arg(scriptReturn) );
		}
		stepCtx.insert(stepNm, rtn);
	}

	return rtn;
}
