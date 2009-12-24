#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <iostream>
#include <vector>

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
	std::vector<std::string> queryAsVector(
		std::string sql,
		std::vector<std::vector<std::string> >& vec
	);
	void begin();
	void commit();
	void rollback();

	void queryAsArray(char *sql, char ***result, int *pnRow, int *pnColumn);
	void freeQueryArray(char **azResult);

private:
	sqlite3 *db;
};


#endif // DBMANAGER_H