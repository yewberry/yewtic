#include "SqliteDB.h"

#include "QtCore/QFile"

bool SqliteDB::open(const QString &db){
	bool ok=false;
	int rc;
	if (isOpen()) close();

	//try to verify the SQLite version 3 file header
	QFile dbfile(db);
	if ( dbfile.open( QIODevice::ReadOnly ) ) {
		char buffer[16+1];
		dbfile.readLine(buffer, 16);
		QString contents = QString(buffer);
		dbfile.close();
		if (!contents.startsWith("SQLite format 3")) {
			m_lastErrMsg = QString("File is not a SQLite 3 database");
			return false;
		}
	} else {
		m_lastErrMsg = QString("File could not be read");
		return false;
	}

	m_lastErrMsg = QString("no error");

	rc = sqlite3_open( (const char *)db.toUtf8(), &m_db );
	if( rc ) {
		m_lastErrMsg = sqlite3_errmsg(m_db);
		sqlite3_close(m_db);
		m_db = 0;
		return false;
	}

	if( m_db ){
		rc = sqlite3_exec(m_db,"PRAGMA empty_result_callbacks = ON;",NULL,NULL,NULL);
		if (SQLITE_OK==rc){
			rc = sqlite3_exec(m_db,"PRAGMA show_datatypes = ON;",NULL,NULL,NULL);
			if (SQLITE_OK==rc){
				ok=true;
			}
			m_curDBFilename = db;
		}
	}
	return ok;
}

bool SqliteDB::isOpen(){
	return m_db!=0; 
}

void SqliteDB::close(){
	if (m_db){
		sqlite3_close(m_db);
	}
	m_db = 0;
}

recList_t SqliteDB::getTableRecords(const QString &tablename){
	sqlite3_stmt *stmt;
	const char *tail;
	int rc = 0;
	recList_t browseRecs;

	QString statement = "SELECT rowid, *  FROM ";
	statement.append(tablename);
	statement.append(" ORDER BY rowid; ");

	int ncol;
	int nrow = 0;
	QStringList r;
	rc = sqlite3_prepare(m_db,(const char *)statement.toUtf8(),statement.length(), &stmt, &tail);
	if( SQLITE_OK == rc ){
		while ( sqlite3_step(stmt) == SQLITE_ROW ){
			r.clear();
			ncol = sqlite3_data_count(stmt);
			for(int i=0; i<ncol; ++i){
				char *strresult = 0;
				strresult = (char *)sqlite3_column_text(stmt, i);
				QString rv = QString::fromUtf8(strresult);
				r << rv;
			}
			browseRecs.append(r);
			nrow++;
		}
		sqlite3_finalize(stmt);

	} else {
		m_lastErrMsg = QString ("could not get fields");
	}

	QStringList b = browseRecs.at(0);
	return browseRecs;
}