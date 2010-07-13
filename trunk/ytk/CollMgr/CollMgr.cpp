#include "CollMgr.h"
#include "common.h"

CollMgr::CollMgr(void)
{
}

CollMgr::~CollMgr(void)
{
}


CppSQLite3DB *CollMgr::db = 0;

CppSQLite3DB* CollMgr::getDB(){
	if(0 == db){
		db = new CppSQLite3DB();
		db->open(CollMgr::DB_FILE);
	}
	return db;
}

char* CollMgr::DB_FILE		= "etc/ytk_cm.db";