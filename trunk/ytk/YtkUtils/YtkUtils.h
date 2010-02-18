#ifndef YTK_UTILS_H
#define YTK_UTILS_H

#include "json.h"

class YtkUtils
{
public:
	//you should json_free_value the return of these funcs manully.
	static json_t* readJsonFromFile(const char* fn);
	static int writeJsonToFile(json_t *root, const char* fn);

	/*
	static json_t* parseJsonFromString(const QString &str);
	static recs_t jsonStringToRecordList(const QString &jsonStr);
	
	static QMap<QString, QString> jsonToMap(json_t *root);
	static json_t* mapToJson(const QMap<QString, QString> &map);
	*/
};

#endif // YTK_UTILS_H