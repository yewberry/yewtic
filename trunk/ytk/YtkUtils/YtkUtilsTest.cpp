#include <gtest/gtest.h>
#include "YtkUtils.h"

TEST(YtkUtils, JsonFunc)
{
	json_t* root = YtkUtils::readJsonFromFile("test.json");

	YtkUtils::map_t map = YtkUtils::jsonToMap(root);
	map["fuck"] = "ƒ„fuck¡À";
	json_t* json = YtkUtils::mapToJson(map);
	YtkUtils::writeJsonToFile(json, "test2.json");
	json_free_value(&json);

	json_free_value(&root);

}