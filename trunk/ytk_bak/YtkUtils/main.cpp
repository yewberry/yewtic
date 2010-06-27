#include <gtest/gtest.h>

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	// Runs all tests using Google Test.
	int ret = RUN_ALL_TESTS();
	std::cin.get();

	return ret;
}
