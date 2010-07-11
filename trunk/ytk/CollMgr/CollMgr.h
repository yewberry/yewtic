#ifndef _COLL_MGR_H
#define _COLL_MGR_H

#include "CppSQLite3.h"

class CollMgr
{
public:
	CollMgr(void);
	~CollMgr(void);

	static CppSQLite3DB* getDB();
private:
	static char *DB_NAME = "ytk_cm.db";
	static CppSQLite3DB *db;
};

#endif