//============================================================================
// Name        : TestBoost.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
#include <iomanip>
#include <boost/foreach.hpp>
#include <numeric>
using namespace std;

template <class T>
inline void print_elements (const T& coll, const char* optcstr="") {
    typename T::const_iterator pos;

    cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        cout << *pos << ' ';
    }
    cout << endl;
}


/*****************************************************************************
 * Test array START
 *****************************************************************************/
#include <boost/array.hpp>
void testArray() {
	cout << setw(60) << setfill('=') << ">testArray" << endl;
	typedef boost::array<int,10> Array;
    // create and initialize array
	Array a = { { 1, 2, 3, 4, 5 } };
    print_elements(a);

    // modify elements directly
    for (unsigned i=0; i<a.size(); ++i) {
        ++a[i];
    }
    print_elements(a);

    // change order using an STL algorithm
    reverse(a.begin(),a.end());
    print_elements(a);

    // negate elements using STL framework
    transform(a.begin(),a.end(),    // source
              a.begin(),            // destination
              negate<int>());       // operation
    print_elements(a);

    // check copy constructor and assignment operator
    Array b(a);
    Array c;
    c = a;
    if (a==b && a==c) {
        cout << "copy construction and copy assignment are OK"
                  << endl;
    } else {
        cout << "copy construction and copy assignment FAILED"
                  << endl;
    }

    // try reverse iterators
    cout << " reverse:   ";
    for (Array::reverse_iterator pos
    		= b.rbegin(); pos<b.rend(); ++pos) {
    	++*pos;
        cout << " " << *pos;
    }

    // try constant reverse iterators
    cout << " reverse:   ";
    for (Array::const_reverse_iterator pos
           = b.crbegin(); pos<b.crend(); ++pos) {
        cout << " " << *pos;
    }
    cout << endl;

    // swap it
    cout << "Bef swap:" << endl;
    print_elements(a);
    print_elements(b);
    swap(a,b);
    cout << "Aft swap:" << endl;
    print_elements(a);
    print_elements(b);

    // fill it
    cout << "Fill:" << endl;
    c.fill(9);
    print_elements(c);

    // 2D array
    boost::array<boost::array<string,4>,2> seasons_i18n =
    { {
    	{ { "spring", "summer", "autumn", "winter", } },
    	{ { "Fruehling", "Sommer", "Herbst", "Winter" } }
    } };

    for (unsigned i=0; i<seasons_i18n.size(); ++i) {
        boost::array<string,4> seasons = seasons_i18n[i];
        for (unsigned j=0; j<seasons.size(); ++j) {
            cout << seasons[j] << " ";
        }
        cout << endl;
    }
    // print first element of first array
    cout << "first element of first array: "
              << seasons_i18n[0][0] << endl;
    // print last element of last array
    cout << "last element of last array: "
              << seasons_i18n[seasons_i18n.size()-1][seasons_i18n[0].size()-1]
              << endl;
}
/*****************************************************************************
 * Test array END
 *****************************************************************************/


/*****************************************************************************
 * Test unordered START
 *****************************************************************************/
#include <boost/unordered_map.hpp>
void testUnordered() {
	cout << setw(60) << setfill('=') << ">testUnordered" << endl;
	typedef boost::unordered_map<string, int> HashMap;
	HashMap hm;
	hm["one"] = 1;
	hm["two"] = 2;
	hm["three"] = 3;
	/*
	BOOST_FOREACH(HashMap::value_type i, hm) {
	    cout<<i.first<<","<<i.second<<"\n";
	}
	*/

}
/*****************************************************************************
 * Test unordered START
 *****************************************************************************/

/*****************************************************************************
 * Test circular_buffer START
 *****************************************************************************/
#include <boost/circular_buffer.hpp>
void testCircularBuffer() {
	cout << setw(60) << setfill('=') << ">testCircularBuffer" << endl;
	boost::circular_buffer<int> cb(3);

	// insert some elements into the circular buffer
	cb.push_back(1);
	cb.push_back(2);
	print_elements(cb);
	cout << "is full: " << boolalpha << cb.full()
			<< ", size: "<< cb.size()
			<< ", capacity: " << cb.capacity() << endl;


	// insert some other elements
	cb.push_back(3);
	cb.push_back(4);
	print_elements(cb);
	cout << "is full: " << boolalpha << cb.full()
			<< ", size: "<< cb.size()
			<< ", capacity: " << cb.capacity() << endl;

	// evaluate the sum
	int sum = accumulate(cb.begin(), cb.end(), 0);
	assert(*cb.begin() == 2);
	assert(cb.front() == 2);
	assert(cb.back() == 4);
	assert(sum == 9);

}

/*****************************************************************************
 * Test circular_buffer END
 *****************************************************************************/

/*****************************************************************************
 * Test date_time START
 *****************************************************************************/
#include "boost/date_time/gregorian/gregorian.hpp"

void testDate() {
	cout << setw(60) << setfill('=') << ">testDate" << endl;
	using namespace boost::gregorian;

    date birthday(from_simple_string("1982-7-12"));
	date today = day_clock::local_day();
	date myDt(1983, Feb, 17);
	date otherDt(from_undelimited_string("19821212"));
	cout << to_simple_string(otherDt) << endl;

	// Date Duration (aka Days) example
	days days_alive = today - birthday;
	days youAndMe = myDt - birthday;
	days one_day(1);
	if (days_alive == one_day) {
		cout << "Born yesterday, very funny" << endl;
	} else if (days_alive < days(0)) {
		cout << "Not born yet, hmm: " << days_alive.days() << " days" << endl;
	} else {
		cout << "Days alive: " << days_alive.days() << endl;
	}
	cout << "Days between you and my: " << youAndMe << endl;
	cout << "You born in " << birthday.day_of_week() <<
			" and I born in " << myDt.day_of_week() << endl;
	years ys(30);
	cout << "Day of week of my birthday after 30 years: "
			<< (myDt + ys).day_of_week() << endl;

	// Date Period example
	date_period dp(birthday, myDt);
	cout << otherDt << " is contains in date period ("<< dp <<")?: "
			<< boolalpha << dp.contains(otherDt) << endl;

	// Iterators example
	month_iterator miter(birthday);
	unsigned c = 0;
	while( *miter < myDt ) {
		++miter;
		++c;
	}
	cout << "How many months between you and me? " << c << endl;

	// Date Generators/Algorithms example
	cout << "Last Saturday overwork: " << endl;
	date::ymd_type ymd = day_clock::local_day_ymd();
	months_of_year m = ymd.month.as_enum();
	months_of_year ms[] =
		{Jan,Feb,Mar,Apr,May,Jun,Jul,Aug,Sep,Oct,Nov,Dec,NotAMonth};
	while( m != NotAMonth ) {
		last_day_of_the_week_in_month lwdm(Saturday, m);
		date d = lwdm.get_date(ymd.year);
		cout << d << endl;
		m = ms[m];
	}
}

#include "boost/date_time/posix_time/posix_time.hpp"
void testTime() {
	cout << setw(60) << setfill('=') << ">testTime" << endl;
	using namespace boost::posix_time;
	using namespace boost::gregorian;

	std::string wwts("1982-07-12 22:22:22.000");
	ptime wwPt(time_from_string(wwts));
	std::string zwts("19830217T121010");
	ptime zwPt(from_iso_string(zwts));
	cout << "You and me: " << to_iso_string(wwPt) << " " << zwPt << endl;

	ptime now = microsec_clock::local_time();
	cout << "local time(now): " << now << endl;
	date today = now.date();
    ptime t1(today, hours(5)+minutes(4)+seconds(2)+millisec(1));
    //construct a new time by subtracting some times
    ptime t2 = t1 - hours(5)- minutes(4)- seconds(2)- millisec(1);
    time_duration td = t2 - t1;
    std::cout << to_simple_string(t2) << " - "
              << to_simple_string(t1) << " = "
              << to_simple_string(td) << std::endl;

    // Time Duration example
    std::string cryDur("1:15:30.000");
    time_duration tdCryDur(duration_from_string(cryDur));
    cout << "I stop cry at " << zwPt + tdCryDur << endl;

    // Time Period example
    time_period tp(zwPt, zwPt + tdCryDur);
    cout << "Is there anything happened in: " << tp << endl;
}

/*****************************************************************************
 * Test date_time START
 *****************************************************************************/

/*****************************************************************************
 * Test ICL START
 *****************************************************************************/
#include <boost/icl/ptime.hpp>
#include <boost/icl/interval_map.hpp>

void testICL() {
	cout << setw(60) << setfill('=') << ">testICL" << endl;
	using namespace boost::posix_time;
	using namespace boost::icl;
	typedef std::set<string> GuestSetT;


    GuestSetT mary_harry;
    mary_harry.insert("Mary");
    mary_harry.insert("Harry");

    GuestSetT diana_susan;
    diana_susan.insert("Diana");
    diana_susan.insert("Susan");

    GuestSetT peter;
    peter.insert("Peter");

    // A party is an interval map that maps time intervals to sets of guests
    interval_map<ptime, GuestSetT> party;

    party.add( // add and element
      make_pair(
        interval<ptime>::right_open(
          time_from_string("2008-05-20 19:30"),
          time_from_string("2008-05-20 23:00")),
        mary_harry));

    party += // element addition can also be done via operator +=
      make_pair(
        interval<ptime>::right_open(
          time_from_string("2008-05-20 20:10"),
          time_from_string("2008-05-21 00:00")),
        diana_susan);

    party +=
      make_pair(
        interval<ptime>::right_open(
          time_from_string("2008-05-20 22:15"),
          time_from_string("2008-05-21 00:30")),
        peter);


    interval_map<ptime, GuestSetT>::iterator it = party.begin();
    cout << "----- History of party guests -------------------------\n";
    while(it != party.end())
    {
        interval<ptime>::type when = it->first;
        // Who is at the party within the time interval 'when' ?
        GuestSetT who = (*it++).second;
        cout << when << ": " << who << endl;
    }
}
/*****************************************************************************
 * Test ICL END
 *****************************************************************************/

int main() {
	testArray();
	testUnordered();
	testCircularBuffer();
	testDate();
	testTime();
	testICL();

	return 0;
}





