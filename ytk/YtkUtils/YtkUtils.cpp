#include "YtkUtils.h"
#include <fstream>
#include "IconvMgr.h"

json_t* YtkUtils::readJsonFromFile(const char* fn)
{
	std::ifstream file(fn);
	std::string str;
	std::string s;  
    while( getline(file,s) ){    
		str.append(s);
    }
	file.close();

	int size = str.size();
	char* json = new char[size];
	strcpy( json, str.c_str() );
	json_t *root = 0;
	if( JSON_OK != json_parse_document(&root, json) ){
		root = 0;
	}

	return root;
}

int YtkUtils::writeJsonToFile(json_t *root, const char* fn)
{
	char *text = 0;
	if( JSON_OK != json_tree_to_string (root, &text) )
		return 1;

	const char *o = json_format_string(text);
	std::ofstream file(fn);
	file<<o;
	file.close();

	return 0;
}