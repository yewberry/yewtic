#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <QtCore/QStringList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include "sqlite3/sqlite3.h"

enum
{
kEncodingUTF8,
kEncodingLatin1,
kEncodingNONE
};
typedef QList<QStringList> recList_t;
typedef QMap<QString, QString> record_t;

class QString;

class SqliteDB
{
public:
	SqliteDB(): m_db(0), m_curEncoding(kEncodingUTF8){};
	~SqliteDB(){close();};

	bool open(const QString &db);
	bool isOpen();
	void close();

	recList_t query(const QString &sql);
	recList_t queryTable(const QString &tablename);
	void updateRecord(record_t &data, const QString &condition, const QString &tablename);
	void insertRecord(record_t &data, const QString &tablename);

	void exec(QString &sql);
	void begin();
	void commit();
	void rollback();

	QString getLastErrMsg();
private:
	const char* getEncodedQString(const QString &input);
private:
	sqlite3 *m_db;

	int m_curEncoding;
	QString m_curDBFilename;
	QString m_lastErrMsg;
};

#endif //SQLITEDB_H