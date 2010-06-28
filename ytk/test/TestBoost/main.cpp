#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

//S test Boost.PropertyTree
#include "Boost.PropertyTree.cpp"
//E

using namespace std; 
using namespace boost::posix_time;
using namespace boost::gregorian;

void testDatetime();
void testPropertyTree();

int main() {
	testDatetime();
	testPropertyTree();

	cin.get();
	return 0;
}

void testDatetime(){
	cout<<"[START TEST Datetime]\n";

	ptime t(second_clock::local_time());
	string s = to_iso_extended_string(t);
	cout<<s<<endl;

	string ts("2010-01-08 02:10");
	ptime tt(time_from_string(ts));
	string ss = to_iso_extended_string(tt);
	cout<<ss<<endl;

	cout<<"[END Datetime]\n";
}
 
void testPropertyTree(){
	cout<<"[START TEST PropertyTree]\n";
	
	try {
		debug_settings ds;
		ds.load("etc/Boost.PropertyTree.xml");
		cout<<ds.m_level<<endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << "\n";
	}

	cout<<"[START PropertyTree]\n";
}