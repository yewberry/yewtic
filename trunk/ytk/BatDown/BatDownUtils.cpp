#include "BatDownUtils.h"
#include "QtCore"

json_t* BatDownUtils::readJsonFromFile(const QString &fn)
{
	QFile file(fn);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text) )
		return 0;
	QByteArray ba = file.readAll();
	char *json = ba.data();
	json_t *root = 0;
	if( JSON_OK != json_parse_document(&root, json) ){
		root = 0;
	}
	return root;
}
