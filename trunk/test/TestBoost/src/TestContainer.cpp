#include "common.h"

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

