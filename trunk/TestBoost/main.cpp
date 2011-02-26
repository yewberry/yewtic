/*
 * main.cpp
 *
 *  Created on: 2011-2-23
 *      Author: Yewberry
 */

#include <iostream>
using namespace std;

void verifyBoost();
int testDateTime();
void testUuid();

int main() {
	//verifyBoost();
	//testDateTime();
	testUuid();
	return 0;
}

/****************************/
#include <boost/foreach.hpp>
void verifyBoost() {
	cout << "Boost Demo" << endl;
	int a[10];
	for (int i = 0; i < 10; i++) {
		a[i] = i + 10;
	}
	BOOST_FOREACH(int k, a)
				{
					cout << "\t" << k;
				}
}

/****************************/
#include "boost/date_time/gregorian/gregorian.hpp"
#include <iostream>
#include <string>

int testDateTime() {

	using namespace boost::gregorian;

	try {
		// The following date is in ISO 8601 extended format (CCYY-MM-DD)
		std::string s("2001-10-9"); //2001-October-09
		date d(from_simple_string(s));
		std::cout << to_simple_string(d) << std::endl;

		//Read ISO Standard(CCYYMMDD) and output ISO Extended
		std::string ud("20011009"); //2001-Oct-09
		date d1(from_undelimited_string(ud));
		std::cout << to_iso_extended_string(d1) << std::endl;

		//Output the parts of the date - Tuesday October 9, 2001
		date::ymd_type ymd = d1.year_month_day();
		greg_weekday wd = d1.day_of_week();
		std::cout << wd.as_long_string() << " " << ymd.month.as_long_string()
				<< " " << ymd.day << ", " << ymd.year << std::endl;

		//Let's send in month 25 by accident and create an exception
		std::string bad_date("20012509"); //2001-??-09
		std::cout << "An expected exception is next: " << std::endl;
		date wont_construct(from_undelimited_string(bad_date));
		//use wont_construct so compiler doesn't complain, but you wont get here!
		std::cout << "oh oh, you shouldn't reach this line: " << to_iso_string(
				wont_construct) << std::endl;
	} catch (std::exception& e) {
		std::cout << "  Exception: " << e.what() << std::endl;
	}

	return 0;
}

/****************************/
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/algorithm/string.hpp>

void testUuid(){
	boost::uuids::random_generator uuid_gen;
	boost::uuids::uuid uu = uuid_gen();
	std::string str = boost::uuids::to_string(uu);
	boost::erase_all(str, "-");
	std::cout<<str<<"|"<<str.size()<<std::endl;
}
