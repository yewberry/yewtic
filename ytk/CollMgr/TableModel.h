#ifndef _TABLE_MODEL_H
#define _TABLE_MODEL_H

class CppSQLite3Table;

class TableModel
{
public:
	TableModel(void);
	~TableModel(void);

	void refresh();
	const char* getFieldValue(int row, int col);

private:
	CppSQLite3Table *m_pBufTbl;
};

#endif