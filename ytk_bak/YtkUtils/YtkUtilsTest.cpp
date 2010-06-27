#include <gtest/gtest.h>
#include "YtkUtils.h"
#include "SqliteDb.h"
#include "INIReader.h"

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
	bool open = dbMgr->open("test.db");
	string nm = dbMgr->dbName();
	string ver = dbMgr->dbVersion();

	ASSERT_TRUE( 0 == nm.compare("sqlite")  && 0 == ver.compare("3.6.21") );
}

TEST(YtkUtils, INIReader)
{
    INIReader reader("test.ini");

    if (reader.ParseError() < 0) {
        std::cout << "Can't load 'test.ini'\n";
    }
    std::cout << "Config loaded from 'test.ini': version="
              << reader.GetInteger("protocol", "version", -1) << ", name="
              << reader.Get("user", "name", "UNKNOWN") << ", email="
              << reader.Get("user", "email", "UNKNOWN") << "\n";
}