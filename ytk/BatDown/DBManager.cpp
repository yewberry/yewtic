#include "DBManager.h"
#include "exception.h"

DBManager::DBManager(void){
}

DBManager::DBManager(char *fn){
	//open db
	int rc = sqlite3_open(fn, &db);
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
	}
}

DBManager::~DBManager(void){
	if(db != 0)
		sqlite3_close(db);
}

void DBManager::exec(const char *sql) throw(ytk::SqlException){
	char *zErr;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			std::string es(zErr);
			sqlite3_free(zErr);
			throw ytk::SqlException(es);
		}
	}
}

void DBManager::queryAsArray(
	char *sql,
	char ***result,
	int *pnRow,
	int *pnColumn
){
	char *zErr;
	int rc = sqlite3_get_table(db, sql, result, pnRow, pnColumn, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			std::string es(zErr);
			sqlite3_free(zErr);
			throw ytk::SqlException(es);
		}
	}
}

void DBManager::freeQueryArray(char **azResult){
	sqlite3_free_table(azResult);
}


void DBManager::begin() throw(ytk::SqlException){
	exec("BEGIN");
}
void DBManager::commit() throw(ytk::SqlException){
	exec("COMMIT");
}
void DBManager::rollback() throw(ytk::SqlException){
	exec("ROLLBACK");
}