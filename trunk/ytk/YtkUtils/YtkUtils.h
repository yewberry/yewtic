#ifndef YTK_UTILS_H
#define YTK_UTILS_H

#include "json.h"
#include <map>
#include <string>

class YtkUtils
{
public:
	typedef std::map<std::string, std::string> map_t;

	//you should json_free_value(&) the return (json_t*) of these funcs manully.
	static json_t* readJsonFromFile(const char* fn);
	static int writeJsonToFile(json_t* root, const char* fn, bool format = true);

	static void jsonToMap(YtkUtils::map_t& map, json_t* root);
	static YtkUtils::map_t jsonToMap(json_t* root);
	static json_t* mapToJson(const YtkUtils::map_t& map);

	static json_t* stringToJson(const std::string& str);
	static std::string jsonToString(json_t* root, bool format = true);

};

#endif // YTK_UTILS_H