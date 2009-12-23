#include "DBManager.h"

#include <tut/tut.hpp> 
namespace tut 
{ 
	struct data
	{ 
	};

	typedef test_group<data> tg;
	tg test_group("my first test");

	typedef tg::object testobject;

	template<> 
	template<> 
	void testobject::test<1>() 
	{ 
		set_test_name("dbmanger");

		DBManager *dbMgr = new DBManager;
		ensure_equals("has no elements",0,0);   
		ensure_equals("has no elements",1,0);    
	}   
}; 