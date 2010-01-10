#include "PostModel.h"
#include "BatDown.h"

PostModel::PostModel(BatDown* app, QObject *parent)
: QAbstractTableModel(parent), BatDownBase(app)
{
	m_table = "btdl_post";
	m_dbFields = QString("cata,title,rank,url,post_by,post_dt,reply_num,view_num,last_reply_dt,last_index_dt").split(",");
	m_headers<<tr("Cata")<<tr("Title")<<tr("Rank")<<tr("URL");
	m_entries = m_pApp->getDbMgr().queryAsMap( QString("SELECT %1 FROM %2").arg(m_dbFields.join(",")).arg(m_table) );
}

PostModel::~PostModel(void)
{
}


QVariant PostModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal) {
		if (role == Qt::DisplayRole) {
			return m_headers.at(section);
		}
	}
	return QAbstractTableModel::headerData(section, orientation, role);
}

int PostModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_entries.size();
}

int PostModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_headers.size();
}

QVariant PostModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	record_t entry = m_entries.at(index.row());
	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		QString fld = m_dbFields.at(index.column());
		return entry.value(fld);
	}

	/*
	if (role == Qt::ToolTipRole) {
	QString tip, key, value;
	tip = "<table>";
	for (int i=0,len=m_headers.size(); i<len; ++i) {
	key = headerData(i, Qt::Horizontal, Qt::DisplayRole).toString();
	value = entry.at(i);
	if (!value.isEmpty()) 
	tip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(key, value);
	}
	tip += "</table>";
	return tip;
	}
	*/
	return QVariant();

}

Qt::ItemFlags PostModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);// | Qt::ItemIsEditable;
}

bool PostModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if( index.isValid() && (role == Qt::EditRole || role == Qt::DisplayRole) ){
		// add 1 to the row index to skip over the header
		//m_entries.value(index.row()).replace(index.column(), value.toString());
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void PostModel::insertRecord(record_t &rec, int position)
{
	m_pApp->getDbMgr().insertRecord(rec, m_table);
	m_entries.insert(position, rec);
	insertRows(position, 1);
}

bool PostModel::insertRows( int row, int count, const QModelIndex & parent )
{
	Q_UNUSED(parent);
	beginInsertRows( QModelIndex(), row, row+count-1 );

	endInsertRows();
	return true;
}

bool PostModel::removeRows( int row, int count, const QModelIndex &parent )
{
	Q_UNUSED(parent);
	beginRemoveRows(QModelIndex(), row, row+count-1);

	endRemoveRows();
	return true;
}