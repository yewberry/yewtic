#include "BaseTableModel.h"
#include "BatDown.h"

BaseTableModel::BaseTableModel(BatDown* app, QObject *parent)
: QAbstractTableModel(parent), BatDownBase(app)
{
}

BaseTableModel::~BaseTableModel(void)
{
}


QVariant BaseTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (orientation == Qt::Horizontal) {
		if (role == Qt::DisplayRole) {
			return m_headers.at(section);
		}
	}
	return QAbstractTableModel::headerData(section, orientation, role);
}

int BaseTableModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_entries.size();
}

int BaseTableModel::columnCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_headers.size();
}

QVariant BaseTableModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid()) return QVariant();

	record_t entry = m_entries.at(index.row());
	if (role == Qt::DisplayRole || role == Qt::EditRole) {
		QString fld = m_dbFields.at(index.column());
		return entry.value(fld);
	}

	return QVariant();

}

Qt::ItemFlags BaseTableModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return 0;

	return QAbstractItemModel::flags(index);// | Qt::ItemIsEditable;
}

bool BaseTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if( index.isValid() && (role == Qt::EditRole || role == Qt::DisplayRole) ){
		// add 1 to the row index to skip over the header
		//m_entries.value(index.row()).replace(index.column(), value.toString());
		emit dataChanged(index, index);
		return true;
	}
	return false;
}

void BaseTableModel::insertRecord(record_t &rec, int position)
{
	m_pApp->getDbMgr().insertRecord(rec, m_table);
	m_entries.insert(position, rec);
	insertRows(position, 1);
}

bool BaseTableModel::insertRows( int row, int count, const QModelIndex & parent )
{
	Q_UNUSED(parent);
	beginInsertRows( QModelIndex(), row, row+count-1 );

	endInsertRows();
	return true;
}

bool BaseTableModel::removeRows( int row, int count, const QModelIndex &parent )
{
	Q_UNUSED(parent);
	beginRemoveRows(QModelIndex(), row, row+count-1);

	endRemoveRows();
	return true;
}