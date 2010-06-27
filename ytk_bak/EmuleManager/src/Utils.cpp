#include "BatDownUtils.h"
#include "QtCore"

json_t* BatDownUtils::readJsonFromFile(const QString &fn)
{
	QFile file(fn);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text) ){
		file.close();
		return 0;
	}
	QByteArray ba = file.readAll();
	file.close();

	char *json = ba.data();
	json_t *root = 0;
	if( JSON_OK != json_parse_document(&root, json) ){
		root = 0;
	}
	return root;
}

bool BatDownUtils::writeJsonToFile(json_t *root, const QString &fn)
{
	char *text;
	if( JSON_OK != json_tree_to_string (root, &text) )
		return false;

	const char *o = json_format_string(text);
	QFile file(fn);
	if( !file.open(QIODevice::WriteOnly | QIODevice::Text) ){
		file.close();
		return false;
	}
	if( file.write(o) == -1 ){
		file.close();
		return false;
	}

	return true;
}

json_t* BatDownUtils::parseJsonFromString(const QString &str)
{
	json_t* root = 0;
	if( JSON_OK != json_parse_document(&root, str.toLocal8Bit().data()) )
		return 0;

	return root;
}

recs_t BatDownUtils::jsonStringToRecordList(const QString &jsonStr)
{
	recs_t recs;

	json_t *root = BatDownUtils::parseJsonFromString(jsonStr);
	if(root == 0)return recs;

	json_t *item = root->child;
	while( item ){
		record_t rec;
		json_t *prop = item->child;
		while( prop ){
			rec.insert( prop->text, QString::fromLocal8Bit(prop->child->text) );
			prop = prop->next;
		}
		recs.append(rec);
		item = item->next;
	}
	json_free_value(&root);
	return recs;
}

QMap<QString, QString> BatDownUtils::jsonToMap(json_t *root)
{
	QMap<QString, QString> map;
	json_t *item = root->child;
	while( item ){
		json_value_type type = item->type;
		if(type != json_value_type::JSON_OBJECT && type != json_value_type::JSON_ARRAY){
			QString n = QString::fromLocal8Bit(item->text);
			QString v = QString::fromLocal8Bit(item->child->text);
			map.insert(n, v);
		}
		item = item->next;
	}
	return map;
}

json_t* BatDownUtils::mapToJson(const QMap<QString, QString> &map)
{
	json_t *root = json_new_object();
	QMapIterator<QString, QString> iter(map);
	while(iter.hasNext()){
		iter.next();
		QByteArray ba_k = iter.key().toLocal8Bit();
		const char *k = (const char*)ba_k;
		QByteArray ba_v = iter.value().toLocal8Bit();
		char *v = ba_v.data();

		v = json_escape(v);
		json_t *vn = json_new_string( v );
		json_insert_pair_into_object(root, k, vn);
	}

	return root;
}

QMap<QString, QString> BatDownUtils::readJsonFileToMap(const QString &fn)
{
	json_t *root = BatDownUtils::readJsonFromFile(fn);
	QMap<QString, QString> map = BatDownUtils::jsonToMap(root);
	json_free_value(&root);
	return map;
}

void BatDownUtils::writeMapToJsonFile(const QMap<QString, QString> &map, const QString &fn)
{
	json_t *root = BatDownUtils::mapToJson(map);
	BatDownUtils::writeJsonToFile(root, fn);
	json_free_value(&root);
}

QStringList BatDownUtils::intListToStringList(QList<int> &ls)
{
	QStringList l;
	for(int i=0, len=ls.size(); i<len; ++i){
		l << QString::number(ls.at(i));
	}
	return l;
}
QList<int> BatDownUtils::stringListToIntList(QStringList &ls)
{
	QList<int> l;
	for(int i=0, len=ls.size(); i<len; ++i){
		l << ls.at(i).toInt();
	}
	return l;
}