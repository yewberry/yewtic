#include "DBManager.h"
#include "exception.h"
#include <QtCore/QString>

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

std::vector<std::string> DBManager::queryAsVector(
	std::string sql,
	std::vector<std::vector<std::string> >& vec) throw(ytk::SqlException)
{
	int nRow;
	int nCol;
	char **result;
	char *zErr;

	int rc = sqlite3_get_table(db, sql.c_str(), &result, &nRow, &nCol, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			std::string es(zErr);
			sqlite3_free(zErr);
			throw ytk::SqlException(es);
		}
	}

	std::vector<std::string> colNms;
	for(int i=0; i<nCol; ++i){
		colNms.push_back(result[i]);
	}

	for(int i=1; i<nRow+1; ++i){
		std::vector<std::string> arr;
		for(int j=0; j<nCol; ++j){
			arr.push_back(result[i*nCol+j]);
		}
		vec.push_back(arr);
	}
	sqlite3_free_table(result);

	return colNms;
}

void DBManager::queryAsArray(
	char *sql,
	char ***result,
	int *pnRow,
	int *pnColumn
) throw(ytk::SqlException) {
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