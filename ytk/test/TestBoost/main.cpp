#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream> 

using namespace std; 
using namespace boost::posix_time;
using namespace boost::gregorian;

int main() {
	ptime t(second_clock::local_time());
	string s = to_iso_extended_string(t);
	cout<<s<<endl;

	string ts("2010-01-08 02:10");
	ptime tt(time_from_string(ts));
	string ss = to_iso_extended_string(tt);
	cout<<ss<<endl;

	cin.get();
	return 0;
}