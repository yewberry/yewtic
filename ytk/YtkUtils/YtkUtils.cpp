#include "YtkUtils.h"
#include <fstream>
#include "IconvMgr.h"

json_t*
YtkUtils::readJsonFromFile(const char* fn)
{
	std::ifstream file(fn);
	std::string str;
	std::string s;  
    while( getline(file,s) ){    
		str.append(s);
    }
	file.close();

	int size = str.size();
	char* json = new char[size+1];
	strcpy( json, str.c_str() );
	json_t *root = 0;
	if( JSON_OK != json_parse_document(&root, json) ){
		root = 0;
	}

	return root;
}

int
YtkUtils::writeJsonToFile(json_t *root, const char* fn)
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

void
YtkUtils::jsonToMap(YtkUtils::map_t& map, json_t *root)
{
	json_t *item = root->child;
	while( item ){
		json_value_type type = item->type;
		if(type != json_value_type::JSON_OBJECT && type != json_value_type::JSON_ARRAY){
			map[std::string(item->text)] = std::string(item->child->text);
		}
		item = item->next;
	}
}

YtkUtils::map_t
YtkUtils::jsonToMap(json_t *root)
{
	YtkUtils::map_t map;
	YtkUtils::jsonToMap(map, root);
	return map;
}

json_t*
YtkUtils::mapToJson(const YtkUtils::map_t& map)
{
	json_t* root = json_new_object();
	YtkUtils::map_t::const_iterator pos;
	for(pos = map.begin(); pos != map.end(); ++pos){
		const char* k = pos->first.c_str();
		const char* val = pos->second.c_str();
		char* t = new char[strlen(val)+1];
		strcpy(t, val);
		char* s = json_escape( t );
		delete[] t;

		json_t *v = json_new_string(s);
		json_insert_pair_into_object(root, k, v);
	}
	return root;
}