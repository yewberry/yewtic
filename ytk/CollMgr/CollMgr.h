#ifndef _COLL_MGR_H
#define _COLL_MGR_H

#include <iostream>
#include "CppSQLite3.h"

class CollMgr
{
public:
	CollMgr(void);
	~CollMgr(void);

	static CppSQLite3DB* getDB();
private:
	static CppSQLite3DB *db;

public:
	static char *DB_FILE;
};

#endif