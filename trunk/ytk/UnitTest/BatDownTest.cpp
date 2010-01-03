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
	tg test_group("BatDownTest");

	typedef tg::object testobject;

	template<> 
	template<> 
	void testobject::test<1>(){
		set_test_name("Sqlite db");
		
		SqliteDB db;
		db.open("ytk.db");
		recList_t rs = db.queryTable("btdl_conf");
		QStringList b = rs.at(0);
		QString str = b.join(",");
		b = rs.at(1);
		str = b.join(",");

		/*
		for(int i=0; i<30; ++i){
			record_t rec;
			rec["url"]		= "http://www.xxx.com/"+QString("%1").arg(i)+".mp3";
			rec["title"]	= QString::fromLocal8Bit("¸èÇú£º")+QString("%1").arg(i)+"_MP3";
			rec["res_type"]	= "MUSIC";
			rec["file_ext"]	= "mp3";

			db.insertRecord(rec, "btdl_entry");
		}
		*/

		std::cerr<<(const char*)db.getLastErrMsg().toLatin1();
		db.close();
	}
};