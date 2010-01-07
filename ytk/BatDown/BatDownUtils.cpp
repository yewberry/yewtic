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