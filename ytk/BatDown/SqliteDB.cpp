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

void SqliteDB::exec(QString &sql){
	char *zErr;
	int rc = sqlite3_exec(m_db, (const char *)sql.toUtf8(), NULL, NULL, &zErr);
	if(rc != SQLITE_OK) {
		if (zErr != NULL) {
			m_lastErrMsg = QString(zErr);
			sqlite3_free(zErr);
		}
	}
}

recList_t SqliteDB::query(const QString &sql){
	sqlite3_stmt *stmt;
	const char *tail;

	bool addHeaderflag = false;
	QStringList header;
	int ncol;
	int rc = 0;
	QStringList r;
	recList_t browseRecs;
	rc = sqlite3_prepare(m_db,(const char *)sql.toUtf8(),sql.length(), &stmt, &tail);
	if( SQLITE_OK == rc ){
		while ( sqlite3_step(stmt) == SQLITE_ROW ){
			r.clear();
			ncol = sqlite3_data_count(stmt);
			for(int i=0; i<ncol; ++i){
				if(!addHeaderflag){
					const char *headerName = sqlite3_column_name(stmt, i);
					QString rv = QString::fromUtf8(headerName);
					header << rv;
				}
				char *strresult = 0;
				strresult = (char *)sqlite3_column_text(stmt, i);
				QString rv = QString::fromUtf8(strresult);
				r << rv;
			}
			if(!addHeaderflag){
				browseRecs.append(header);
				addHeaderflag = true;
			}
			browseRecs.append(r);
		}
		sqlite3_finalize(stmt);

	} else {
		m_lastErrMsg = QString ("could not get fields");
	}

	return browseRecs;
}

recList_t SqliteDB::queryTable(const QString &tablename){
	QString sql = "SELECT rowid, *  FROM ";
	sql.append(tablename);
	sql.append(" ORDER BY rowid; ");
	return query(sql);
}

void SqliteDB::updateRecord(
			record_t &data,
			const QString &cond,
			const QString &tablename)
{
	QStringList hdr = data.keys();
	QString values;
	QMapIterator<QString, QString> iter(data);
	while(iter.hasNext()){
		iter.next();
		values.append(iter.key()+"=\'"+iter.value()+"\',");
	}
	values.remove(values.size()-1, 1);

	QString statement = "UPDATE ";
	statement.append( tablename );
	statement.append(" SET ");
	statement.append( values );
	statement.append(" WHERE ");
	statement.append( cond );

	exec(statement);
}

void SqliteDB::insertRecord(
			record_t &data,
			const QString &tablename)
{
	QStringList hdr = data.keys();
	QString fields;
	QString values;

	fields.append("(");
	values.append("(");
	QMapIterator<QString, QString> iter(data);
	while(iter.hasNext()){
		iter.next();
		fields.append(iter.key()+",");
		values.append("\'"+iter.value()+"\',");
	}
	fields.remove(fields.size()-1, 1);
	values.remove(values.size()-1, 1);
	fields.append(")");
	values.append(")");

	QString statement = "INSERT INTO ";
	statement.append( tablename );
	statement.append( fields );
	statement.append(" VALUES ");
	statement.append( values );

	exec(statement);
}

/*
const char *c = (const char *)db.toUtf8();
sqlite3_open( c, &m_db );
Óë
sqlite3_open( (const char *)db.toUtf8(), &m_db );
Çø±ð£¿£¿£¿
*/
const char* SqliteDB::getEncodedQString(const QString &input){
	if(m_curEncoding == kEncodingUTF8) return (const char *)input.toUtf8();
	if(m_curEncoding == kEncodingLatin1) return (const char *)input.toLatin1();

	return (const char *)input.toUtf8();
}

void SqliteDB::begin(){
	exec( QString("BEGIN") );
}
void SqliteDB::commit(){
	exec( QString("COMMIT") );
}
void SqliteDB::rollback(){
	exec( QString("ROLLBACK") );
}

QString SqliteDB::getLastErrMsg(){
	return m_lastErrMsg;
}