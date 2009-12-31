#include "EntryModel.h"
#include "BatDown.h"

EntryModel::EntryModel(QWidget *parent)
{
	entries = BatDown::dbMgr.query(
		"SELECT title,res_type,file_ext,url,url AS id FROM btdl_entry");
	int s = entries.size();
	headers<<tr("Title")<<tr("Type")<<tr("File Ext.")<<tr("URL");
}

EntryModel::~EntryModel(void)
{
}


QVariant EntryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal) {
		if (role == Qt::DisplayRole) {
			return headers.at(section);
		}
	}
	return QAbstractTableModel::headerData(section, orientation, role);
}

int EntryModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return entries.size();
}

int EntryModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return headers.size();
}

QVariant EntryModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	QStringList entry = entries.at(index.row());
	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		return entry.at(index.column());
	}
	if (role == Qt::ToolTipRole) {
		QString tip, key, value;
		tip = "<table>";
		for (int i=0,len=headers.count(); i<len; ++i) {
			key = headerData(i, Qt::Horizontal, Qt::DisplayRole).toString();
			value = entry.at(i);
			if (!value.isEmpty()) 
				tip += QString("<tr><td><b>%1</b>: %2</td></tr>").arg(key, value);
		}
		tip += "</table>";
		return tip;
	}
	return QVariant();

}

Qt::ItemFlags EntryModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

bool EntryModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if( index.isValid() && (role == Qt::EditRole || role == Qt::DisplayRole) ){
			// add 1 to the row index to skip over the header
		entries.value(index.row()).replace(index.column(), value.toString());
		emit dataChanged(index, index);
		return true;
	}
	return false;
}