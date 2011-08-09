#include "common.h"

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

