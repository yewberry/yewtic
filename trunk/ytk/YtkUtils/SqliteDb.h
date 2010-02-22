#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include "DbMgr.h"
#include "sqlite3/sqlite3.h"

class SqliteDb : public DbMgr
{
public:
	SqliteDb(void) : DbMgr("sqlite","3.6.21"){};
	~SqliteDb(void);

	bool open(const std::string& db);
	bool isOpen();
	void close();

	DbMgr::recordList_t query(const std::string& sql);

private:
	sqlite3*	m_db;
	std::string	m_dbFn;
	std::string	m_lastErrMsg;
};

#endif // SQLITE_DB_H