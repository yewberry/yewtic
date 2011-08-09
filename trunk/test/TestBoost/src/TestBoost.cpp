#include "common.h"

extern void testArray();
extern void testUnordered();
extern void testCircularBuffer();
extern void testICL();

extern void testDate();
extern void testTime();

extern void testLexicalCast();
extern void testFormat();

int main() {
	testArray();
	testUnordered();
	testCircularBuffer();
	testDate();
	testTime();
	testICL();
	testLexicalCast();
	testFormat();

	return 0;
}





