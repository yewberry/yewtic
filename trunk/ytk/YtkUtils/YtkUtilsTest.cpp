#include <gtest/gtest.h>
#include "YtkUtils.h"

TEST(YtkUtils, readJsonFromFile)
{
	json_t* root = YtkUtils::readJsonFromFile("test.json");
	int a = 0;
}