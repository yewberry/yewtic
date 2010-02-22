#ifndef DB_MGR_H
#define DB_MGR_H

#include <string>
#include <map>
#include <list>

class DbMgr
{
public:
	typedef std::map<std::string, std::string> record_t;
	typedef std::list<record_t> recordList_t;

	DbMgr(const char* dbName, const char* dbVer);

	virtual bool open(const std::string& db) = 0;
	virtual bool isOpen() = 0;
	virtual void close() = 0;

	virtual recordList_t query(const std::string& sql) = 0;

	const std::string dbName() const;
	const std::string dbVersion() const;

private:
	std::string m_dbName;
	std::string m_dbVersion;
};

#endif // DB_MGR_H