#include "common.h"

/*****************************************************************************
 * Test string_algo START
 *****************************************************************************/

/*****************************************************************************
 * Test string_algo END
 *****************************************************************************/

/*****************************************************************************
 * Test lexical_cast START
 *****************************************************************************/
#include <boost/lexical_cast.hpp>
void testLexicalCast(void) {
	cout << setw(60) << setfill('=') << ">testLexicalCast" << endl;
	using namespace boost;
	// To char
	assert('1' == lexical_cast<char>(1));
	assert('9' == lexical_cast<char>(9));
	try {
		lexical_cast<char>(10);
	} catch (bad_lexical_cast&) {
		cout << "Only can convert 1 digital to char! \n";
	}
	assert('A' == lexical_cast<char>("A"));
	assert('A' == lexical_cast<char>(std::string("A")));
	assert('1' == lexical_cast<char>(true));
	assert('0' == lexical_cast<char>(false));
	try {
		lexical_cast<char>("Test");
	} catch (bad_lexical_cast&) {
		cout << "Only can convert 1 char string to char! \n";
	}

	// To string
	assert("A" == lexical_cast<std::string>('A'));
	assert("Test" == lexical_cast<std::string>("Test"));
	assert("123" == lexical_cast<std::string>(123));
	assert("1.23" == lexical_cast<std::string>(1.23));
	assert("1" == lexical_cast<std::string>(true));

	// To number
	assert(123 == lexical_cast<int>("123"));
	try {
		lexical_cast<char>("1.23");
	} catch (bad_lexical_cast&) {
		cout << "Only can convert int string to int! \n";
	}
	try {
		lexical_cast<char>(" 123");
	} catch (bad_lexical_cast&) {
		cout << "Don't like space bef or aft! \n";
	}
	assert(1.23 == lexical_cast<double>("1.23"));

	// To bool
	assert(true == lexical_cast<bool>("+1"));
	assert(false == lexical_cast<bool>("+0"));
	assert(false == lexical_cast<bool>("-0"));
	try {
		lexical_cast<bool>("--0");
	} catch (bad_lexical_cast&) {
		cout << "Only can convert simple int to bool, --0 seems not that simple! \n";
	}
}
/*****************************************************************************
 * Test lexical_cast END
 *****************************************************************************/

/*****************************************************************************
 * Test format START
 *****************************************************************************/
#include "boost/format.hpp"
void testFormat() {
	cout << setw(60) << setfill('=') << ">testLexicalCast" << endl;
	using boost::format;
	using boost::io::group;

    // Reordering :
    cout << format("%1% %2% %3% %2% %1% \n") % "o" % "oo" % "O"; // 'simple' style.
    //          prints  "o oo O oo o \n"
    cout << format("(x,y) = (%1$+5d,%2$+5d) \n") % -23 % 35;     // Posix-Printf style

    // No reordering :
    cout << format("writing %s,  x=%s : %d-th step \n") % "toto" % 40.23 % 50;
    //          prints  "writing toto,  x=40.23 : 50-th step \n"

    cout << format("(x,y) = (%+5d,%+5d) \n") % -23 % 35;
    cout << format("(x,y) = (%|+5|,%|+5|) \n") % -23 % 35;
    cout << format("(x,y) = (%|1$+5|,%|2$+5|) \n") % -23 % 35;
    //   all those are the same,  it prints  "(x,y) = (  -23,  +35) \n"

    // Using manipulators, via 'group' :
    cout << format("%2% %1% %2%\n")  % 1   % group(setfill('X'), hex, setw(4), 16+3) ;
    // prints "XX13 1 XX13\n"

    // printf directives's type-flag can be used to pass formatting options :
    cout <<  format("_%1$4d_ is : _%1$#4x_, _%1$#4o_, and _%1$s_ by default\n")  % 18;
    //          prints  "_  18_ is : _0x12_, _ 022_, and _18_ by default\n"

    // Taking the string value :
    std::string s;
    s= str( format(" %d %d ") % 11 % 22 );
    assert( s == " 11 22 ");

    // -----------------------------------------------
    //  %% prints '%'
    cout << format("%%##%#x ") % 20 << endl;
    //          prints  "%##0x14 "
}
/*****************************************************************************
 * Test format END
 *****************************************************************************/

