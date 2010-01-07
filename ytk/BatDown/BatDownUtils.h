#ifndef BATDOWNUTILS_H
#define BATDOWNUTILS_H

#include <QtCore/QString>
#include "json.h"
#include "SqliteDB.h"

class BatDownUtils
{
public:
	//you should json_free_value what you get by return of
	//this func manully.
	static json_t* readJsonFromFile(const QString &fn);
	static bool writeJsonToFile(json_t *root, const QString &fn);
	static json_t* parseJsonFromString(const QString &str);
	static recs_t jsonStringToRecordList(const QString &jsonStr);
};

#endif //BATDOWNUTILS_H