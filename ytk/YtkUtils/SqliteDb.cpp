#include "SqliteDb.h"
#include <fstream>

SqliteDb::~SqliteDb(void)
{
}

bool
SqliteDb::open(const std::string& db)
{
	if( isOpen() )close();

	//try to verify the SQLite version 3 file header
	std::ifstream file(db.c_str());
	if ( file.good() ) {
		char buffer[16+1];
		file.read(buffer, 16);
		std::string contents(buffer);
		file.close();

		if (contents.find_first_of("SQLite format 3") != 0) {
			m_lastErrMsg ="File is not a SQLite 3 database";
			return false;
		}
	} else {
		m_lastErrMsg = "File could not be read";
		return false;
	}
	m_lastErrMsg = "no error";

	int rc;
	rc = sqlite3_open( db.c_str(), &m_db );
	if( rc ) {
		m_lastErrMsg = sqlite3_errmsg(m_db);
		close();
		return false;
	}

	bool ret = false;
	if( m_db ){
		rc = sqlite3_exec(m_db,"PRAGMA empty_result_callbacks = ON;",NULL,NULL,NULL);
		if (SQLITE_OK==rc){
			rc = sqlite3_exec(m_db,"PRAGMA show_datatypes = ON;",NULL,NULL,NULL);
			if (SQLITE_OK==rc){
				ret = true;
			}
			m_dbFn = db;
		}
	}
	return ret;
}

bool
SqliteDb::isOpen()
{
	return m_db!=0; 
}

void
SqliteDb::close()
{
	if(m_db){
		sqlite3_close(m_db);
	}
	m_db = 0;
}

DbMgr::recordList_t
SqliteDb::query(const std::string &sql)
{
	DbMgr::recordList_t ret;
	return ret;
}
