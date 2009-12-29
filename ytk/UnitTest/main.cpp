#include <tut/tut.hpp>
#include <tut/tut_reporter.h>
#include <iostream>

using std::exception;
using std::cerr;
using std::endl;

namespace tut
{
	test_runner_singleton runner;
}

int main()
{
	tut::console_reporter reporter;
	tut::runner.get().set_callback(&reporter);

	//tut::runner.get().run_tests();
	tut::runner.get().run_tests("SqliteDB");

	std::cin.get();
	return !reporter.all_ok();
}
