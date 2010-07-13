#include "TableModel.h"
#include "CollMgr.h"

TableModel::TableModel(void):m_pBufTbl(0)
{
}

TableModel::~TableModel(void)
{
	if( 0 != m_pBufTbl)delete m_pBufTbl;
}

void TableModel::refresh(){
	CppSQLite3DB *db = CollMgr::getDB();

	if( 0!= m_pBufTbl)delete m_pBufTbl;
	m_pBufTbl = new CppSQLite3Table( db->getTable("select * from cm_file;") );

	return;

	    for (int fld = 0; fld < m_pBufTbl->numFields(); fld++)
        {
			std::cout << m_pBufTbl->fieldName(fld) << "|";
        }
		std::cout << std::endl;
        for (int row = 0; row < m_pBufTbl->numRows(); row++)
        {
            m_pBufTbl->setRow(row);
            for (int fld = 0; fld < m_pBufTbl->numFields(); fld++)
            {
                if (!m_pBufTbl->fieldIsNull(fld))
					std::cout << m_pBufTbl->fieldValue(fld)<< "|";
                else
					std::cout << "NULL" << "|";
            }
			std::cout << std::endl;
        }
}

const char* TableModel::getFieldValue(int row, int col){
	m_pBufTbl->setRow(row);
	return m_pBufTbl->fieldValue(col);
}