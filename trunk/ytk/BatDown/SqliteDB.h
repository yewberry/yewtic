#ifndef SQLITEDB_H
#define SQLITEDB_H

#include <QtCore/QStringList>
#include <QtCore/QString>
#include "sqlite3/sqlite3.h"

typedef QList<QStringList> recList_t;
enum
{
kEncodingUTF8,
kEncodingLatin1,
kEncodingNONE
};

class QString;

class SqliteDB
{
public:
	SqliteDB(): m_db(0), m_curEncoding(kEncodingUTF8){};
	~SqliteDB(){close();};

	bool open(const QString &db);
	bool isOpen();
	void close();

	recList_t getTableRecords(const QString &tablename);

private:
	QByteArray getEncodedQString(const QString &input);

private:
	sqlite3 *m_db;
	int m_curEncoding;
	QString m_curDBFilename;
	QString m_lastErrMsg;
};

#endif //SQLITEDB_H