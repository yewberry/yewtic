#include "CollMgr.h"

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
		db->open("ytk_cm.db");
		return db;
	}
}