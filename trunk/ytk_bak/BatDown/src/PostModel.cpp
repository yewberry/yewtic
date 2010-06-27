#include "PostModel.h"
#include "BatDown.h"

PostModel::PostModel(BatDown* app, QObject *parent)
: BaseTableModel(app, parent)
{
	m_table = "btdl_post";
	m_dbFields = QString("cata,title,rank,last_index_dt,url,post_by,post_dt,reply_num,view_num,last_reply_dt").split(",");
	m_headers<<tr("Cata")<<tr("Title")<<tr("Rank")<<tr("Index Date");
	m_entries = m_pApp->getDbMgr().queryAsMap( QString("SELECT %1 FROM %2 ORDER BY last_index_dt DESC").arg(m_dbFields.join(",")).arg(m_table) );
}

QVariant PostModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	record_t entry = m_entries.at(index.row());
	if (role == Qt::ToolTipRole) {
		QString tip, key, value;
		tip = "<table>";
		tip += QString("<tr><td><b>Title</b>: %1</td></tr>\
					   <tr><td><b>Post By</b>: %2</td></tr>\
					   <tr><td><b>Post Date</b>: %3</td></tr>\
					   <tr><td><b>URL</b>: %4</td></tr>\
					   ").arg(entry.value("title"))\
					   .arg(entry.value("post_by"))\
					   .arg(entry.value("post_dt"))\
					   .arg(entry.value("url"));

		tip += "</table>";
		return tip;
	}

	return BaseTableModel::data(index, role);

}