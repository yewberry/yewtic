/*
 * ServerThread.cpp
 *
 *  Created on: 2011-3-4
 *      Author: Yewberry
 */

#include "ReportThread.h"
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

ReportThread::ReportThread(QObject *parent, int inter)
	: XThread(parent, inter)
{
}
void ReportThread::run()
{
    while (!m_stopped){
    	ServerModel model(this);
    	QVector<QSqlRecord> svrs = model.getRecords();
    	QString rpt;
    	rpt.append("<html><table style=\"padding:3\">");
    	rpt.append("<tr><td>服务器名</td><td>服务器IP</td><td>监控状态</td><td>业务状态</td><td>检查项通过情况</td></tr>");
		for (int i = 0; i < svrs.count(); ++i) {
			QSqlRecord svr = svrs.at(i);

			QString svrId = svr.value(ServerModel::ID).toString();
			QString svrName = svr.value(ServerModel::NAME).toString();
			QString svrIp = svr.value(ServerModel::IP).toString();
			QString svrStepStatusJson = svr.value(ServerModel::STEP_STATUS).toString();

			bool active = svr.value(ServerModel::ACTIVE).toBool();
			bool status = svr.value(ServerModel::STATUS).toBool();
			QString bgColor = "white";
			QString text;

			if(active){
				text.append("监控中");
				bgColor = "green";
			} else {
				text.append("未监控");
				bgColor = "red";
			}
			QString monStatus = QString("<td style=\"background-color:%1\">%2</td>").arg(bgColor).arg(text);
			text = "";
			bgColor = "white";

			if(status){
				text.append("业务故障");
				bgColor = "red";
			} else {
				text.append("业务正常");
				bgColor = "green";
			}
			QString svrStatus = QString("<td style=\"background-color:%1\">%2</td>").arg(bgColor).arg(text);
			text = "";
			bgColor = "white";

			QString stepStatus = "<ul>";
			QJson::Parser parser;
			bool ok;
			QVariantMap hm = parser.parse(svrStepStatusJson.toLocal8Bit(), &ok).toMap();
			if (!ok) {
				stepStatus = QString("An error occurred during parsing JSON: %1").arg(svrStepStatusJson);
				yTERROR( stepStatus );
			} else {
				QList<QString> keys = hm.keys();
				Q_FOREACH(QString key, keys){
					QVariantMap vals = hm.value(key).toMap();
					bool st = vals.value("status").toBool();
					bgColor = st==true?"green":"red";
					QString t = st==true?"PASS":"FAIL";
					QString msg;
					if(vals.contains("msg"))msg = vals.value("msg").toString();

					stepStatus.append(QString("<li style=\"background-color:%1\">%2:%3&nbsp%4</li>").arg(bgColor).arg(key).arg(t).arg(msg));
				}
			}
			stepStatus.append("</ul>");

			rpt.append(QString("<tr><td>%1</td><td>%2</td>%3%4<td>%5</td></tr>").arg(svrName).arg(svrIp).arg(monStatus).arg(svrStatus).arg(stepStatus));

		}//SERVERS END
		rpt.append("</table></html>");
		QFile file("report.html");
		if (!file.open(QIODevice::WriteOnly | QIODevice::Text)){
			yTERROR(QString("Can't write to report file: %1").arg(file.fileName()));
		} else {
			QTextStream out(&file);
			out << rpt;
		}
		file.close();



    	msleep(m_threadInter);
    }
    m_stopped = false;

}

