#include "SqliteDB.h"
#include "exception.h"

#include <tut/tut.hpp> 
using namespace std;

namespace tut 
{ 
	struct data
	{ 
	};

	typedef test_group<data> tg;
	tg test_group("SqliteDB");

	typedef tg::object testobject;

	template<> 
	template<> 
	void testobject::test<1>(){ 
		set_test_name("open db");
		
		SqliteDB db;
		db.open("ytk.db");
		recList_t rs = db.getTableRecords("btdl_conf");
		char *sql = "create table test(id int, name text)";
	}
};