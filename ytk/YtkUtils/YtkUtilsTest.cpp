#include <gtest/gtest.h>
#include "YtkUtils.h"
#include "SqliteDb.h"

using namespace std;

TEST(YtkUtils, JsonFunc)
{
	json_t* root = YtkUtils::readJsonFromFile("test.json");

	//map op
	YtkUtils::map_t map = YtkUtils::jsonToMap(root);
	map["fuck"] = "ÄãfuckÁË";
	json_t* json = YtkUtils::mapToJson(map);
	YtkUtils::writeJsonToFile(json, "test2.json");
	json_free_value(&json);

	//str op
	string str = YtkUtils::jsonToString(root);

	json_free_value(&root);
	ASSERT_TRUE(true);

}

TEST(YtkUtils, DbMgr)
{
	DbMgr* dbMgr = new SqliteDb();
	bool open = dbMgr->open("abc");
	string nm = dbMgr->dbName();
	string ver = dbMgr->dbVersion();
}