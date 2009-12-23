#include "DBManager.h"
#include "exception.h"

#include <tut/tut.hpp> 
namespace tut 
{ 
	struct data
	{ 
	};

	typedef test_group<data> tg;
	tg test_group("BatDownTest");

	typedef tg::object testobject;

	template<> 
	template<> 
	void testobject::test<1>() 
	{ 
		set_test_name("DB Excpetion");

		std::string s;
		DBManager dbMgr("batdown.db");
		char *sql = "create table test(id int, name text)";
		try {
			dbMgr.exec(sql);
		} catch(ytk::SqlException e) {
			s = e.what();
		}
		ensure_equals("check exception", s, "table test already exists");

		try {
			sql = "insert into test values (00, 'ROLLBACK')";
			dbMgr.begin();
			dbMgr.exec(sql);
			dbMgr.rollback();

			sql = "insert into test values (99, 'COMMIT')";
			dbMgr.begin();
			dbMgr.exec(sql);
			dbMgr.commit();

			sql = "delete from test where num=99";
			dbMgr.exec(sql);

			char **result;
			int row;
			int col;
			dbMgr.queryAsArray("select * from test", &result, &row, &col);
			result[0];
			result[1];
			result[2];
			result[3];
			result[4];
			result[5];
			std::cerr<<row<<" "<<col;
			int a = 0;
			dbMgr.freeQueryArray(result);

		} catch(ytk::SqlException e) {
			std::cerr<< e.what();
			ensure_equals("Exception", 1, 0);
		}

	}
};