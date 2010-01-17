#include "MusicModel.h"
#include "BatDown.h"

MusicModel::MusicModel(BatDown* app, QObject *parent)
: BaseTableModel(app, parent)
{
	m_table = "btdl_music";
	m_dbFields = QString("title,artist,album,md5,file_path,music_url,post_url,track,genre,year,notes").split(",");
	m_headers<<tr("Title")<<tr("Artist")<<tr("Album")<<tr("MD5");
	m_entries = m_pApp->getDbMgr().queryAsMap( QString("SELECT %1 FROM %2").arg(m_dbFields.join(",")).arg(m_table) );
}

QVariant MusicModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	record_t entry = m_entries.at(index.row());
	if (role == Qt::ToolTipRole) {
		QString tip, key, value;
		tip = "<table>";
		tip += QString("<tr><td><b>Path</b>: %1</td></tr>\
					   <tr><td><b>Music URL</b>: %2</td></tr>\
					   <tr><td><b>Post URL</b>: %3</td></tr>\
					   <tr><td><b>MD5</b>: %4</td></tr>\
					   ").arg(entry.value("file_path"))\
					   .arg(entry.value("music_url"))\
					   .arg(entry.value("post_url"))\
					   .arg(entry.value("md5"));

		tip += "</table>";
		return tip;
	}

	return BaseTableModel::data(index, role);

}
