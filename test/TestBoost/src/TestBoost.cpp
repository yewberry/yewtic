//============================================================================
// Name        : TestBoost.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <string>
#include <iostream>
using namespace std;

/*
 * boost::array
 */
#include <boost/array.hpp>
void testArray();



int main() {
	testArray();
	return 0;
}


/*****************************************************************************
 * Test array START
 *****************************************************************************/
template <class T>
inline void print_elements (const T& coll, const char* optcstr="")
{
    typename T::const_iterator pos;

    std::cout << optcstr;
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

void testArray(){

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
        std::cout << "copy construction and copy assignment are OK"
                  << std::endl;
    } else {
        std::cout << "copy construction and copy assignment FAILED"
                  << std::endl;
    }

    // try reverse iterators
    std::cout << " reverse:   ";
    for (Array::reverse_iterator pos
    		= b.rbegin(); pos<b.rend(); ++pos) {
    	++*pos;
        std::cout << " " << *pos;
    }

    // try constant reverse iterators
    std::cout << " reverse:   ";
    for (Array::const_reverse_iterator pos
           = b.crbegin(); pos<b.crend(); ++pos) {
        std::cout << " " << *pos;
    }
    std::cout << std::endl;

    // swap it
    std::cout << "Bef swap:" << std::endl;
    print_elements(a);
    print_elements(b);
    std::swap(a,b);
    std::cout << "Aft swap:" << std::endl;
    print_elements(a);
    print_elements(b);

    // fill it
    std::cout << "Fill:" << std::endl;
    c.fill(9);
    print_elements(c);

    // 2D array
    boost::array<boost::array<std::string,4>,2> seasons_i18n =
    { {
    	{ { "spring", "summer", "autumn", "winter", } },
    	{ { "Fruehling", "Sommer", "Herbst", "Winter" } }
    } };

    for (unsigned i=0; i<seasons_i18n.size(); ++i) {
        boost::array<std::string,4> seasons = seasons_i18n[i];
        for (unsigned j=0; j<seasons.size(); ++j) {
            std::cout << seasons[j] << " ";
        }
        std::cout << std::endl;
    }
    // print first element of first array
    std::cout << "first element of first array: "
              << seasons_i18n[0][0] << std::endl;
    // print last element of last array
    std::cout << "last element of last array: "
              << seasons_i18n[seasons_i18n.size()-1][seasons_i18n[0].size()-1]
              << std::endl;
}
/*****************************************************************************
 * Test array END
 *****************************************************************************/
