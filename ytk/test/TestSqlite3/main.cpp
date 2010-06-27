#include <iostream>

#include "sqlite3/sqlite3.h"

int callback(void* data, int ncols, char** values, char** headers);

int main(int argc, char *argv[]){
	sqlite3 *db;
	char *zErr;
	int rc;
	char *sql;

	//open db
	rc = sqlite3_open("test.db", &db);
	if(rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		exit(1);
	}

	//create table
	sql = "create table episodes(id int, name text)";
	rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			fprintf(stderr, "SQL error: %s\n", zErr);
			sqlite3_free(zErr);
		}
	}

	//insert
	sql = "insert into episodes values (10, 'The Dinner Party')";
	rc = sqlite3_exec(db, sql, NULL, NULL, &zErr);

	//select
	sql = "insert into episodes (id, name) values (11,'Mackinaw Peaches');"
		"select * from episodes;";
	const char* data = "Callback function called";
	rc = sqlite3_exec(db, sql, callback, (void*)data, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			fprintf(stderr, "SQL error: %s\n", zErr);
			sqlite3_free(zErr);
		}
	}

	//select by sqlite3_get_table
	/**
	name               | id
	-----------------------
	The Junior Mint    | 43
	The Smelly Car     | 28
	The Fusilli Jerry  | 21

	result [0] = "name";
	result [1] = "id";
	result [2] = "The Junior Mint";
	result [3] = "43";
	result [4] = "The Smelly Car";
	result [5] = "28";
	result [6] = "The Fusilli Jerry";
	result [7] = "21";


	char *result[];
	int row;
	int col;
	sql = "select * from episodes;";
	rc = sqlite3_get_table(db, sql, &result, &row, &col, &zErr);
	sqlite3_free_table(result);
	*/


	//prepared sql stetement
	sqlite3_stmt *stmt;
	const char *tail;
	sql = "select * from episodes;";
	rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);
	if(rc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
	}
	rc = sqlite3_step(stmt);
	int ncols = sqlite3_column_count(stmt); 
	while(rc == SQLITE_ROW) {
		for(int i=0; i < ncols; i++) {
			fprintf(stderr, "'%s' ", sqlite3_column_text(stmt, i));
		}
		fprintf(stderr, "\n");
		rc = sqlite3_step(stmt);
	}
	//prepared sql of multiple SQL statements
	/*while(sqlite3_complete(sql) {
		rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);
		// Process query results
		// Skip to next command in string.
		sql = tail;
	}*/
	//or int sqlite3_reset(sqlite3_stmt *pStmt); for future use.
	sqlite3_finalize(stmt);

	/* Parameterized Queries
const char* sql = "insert into foo values(?,?,?)";
sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);
sqlite3_bind_int(stmt,    1, 2);
sqlite3_bind_text(stmt,   2, "pi");
sqlite3_bind_double(stmt, 3, 3.14);
sqlite3_step(stmt);
sqlite3_finalize(stmt);
*/
	/* Transaction
	db = open('foods.db')
db.exec('BEGIN')
db.exec('SELECT * FROM episodes')
db.exec('SELECT * FROM episodes')
db.exec('COMMIT')
db.close()
	*/


	//close db
	sqlite3_close(db);

	std::cin.get();
	return 0;
}

int callback(void* data, int ncols, char** values, char** headers)
{
	int i;
	fprintf(stderr, "%s: ", (const char*)data);
	for(i=0; i < ncols; i++) {
		fprintf(stderr, "%s=%s ", headers[i], values[i]);
	}
	fprintf(stderr, "\n");
	return 0;
}