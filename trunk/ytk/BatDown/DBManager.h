#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>

extern "C" {
#include "sqlite3/sqlite3.h"
}



class DBManager
{
public:
	DBManager(void);
	DBManager(char *db);
	~DBManager(void);

	void exec(const char *sql);
	void queryAsArray(char *sql, char ***result, int *pnRow, int *pnColumn);
	void freeQueryArray(char **azResult);

	void begin();
	void commit();
	void rollback();

private:
	sqlite3 *db;
};


#endif // DBMANAGER_H