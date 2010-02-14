#ifndef UTILS_H
#define UTILS_H

#include <QtCore>
#include "json.h"
#include "SqliteDB.h"

class Utils
{
public:
	//you should json_free_value what you get by return of
	//this func manully.
	static json_t* readJsonFromFile(const QString &fn);
	static bool writeJsonToFile(json_t *root, const QString &fn);
	static json_t* parseJsonFromString(const QString &str);

	static recs_t jsonStringToRecordList(const QString &jsonStr);

	static QMap<QString, QString> jsonToMap(json_t *root);
	static json_t* mapToJson(const QMap<QString, QString> &map);

	static QMap<QString, QString> readJsonFileToMap(const QString &fn);
	static void writeMapToJsonFile(const QMap<QString, QString> &map, const QString&fn);

	static QStringList intListToStringList(QList<int> &ls);
	static QList<int> stringListToIntList(QStringList &ls);
};

#endif //UTILS_H