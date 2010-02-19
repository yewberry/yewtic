#ifndef YTK_UTILS_H
#define YTK_UTILS_H

#include "json.h"
#include <map>
#include <string>

class YtkUtils
{
public:
	typedef std::map<std::string, std::string> map_t;

	//you should json_free_value(&) the return of these funcs manully.
	static json_t* readJsonFromFile(const char* fn);
	static int writeJsonToFile(json_t *root, const char* fn);

	static void jsonToMap(YtkUtils::map_t& map, json_t *root);
	static YtkUtils::map_t jsonToMap(json_t *root);
	static json_t* mapToJson(const YtkUtils::map_t& map);

	/*
	static json_t* parseJsonFromString(const QString &str);
	static recs_t jsonStringToRecordList(const QString &jsonStr);
	

	*/
};

#endif // YTK_UTILS_H