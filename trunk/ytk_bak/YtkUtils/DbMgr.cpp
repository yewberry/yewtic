#include "DbMgr.h"

DbMgr::DbMgr(const char* dbName, const char* dbVer)
: m_dbName(dbName), m_dbVersion(dbVer)
{}

const std::string
DbMgr::dbName() const
{
	return m_dbName;
}

const std::string
DbMgr::dbVersion() const
{
	return m_dbVersion;
}