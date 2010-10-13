#include <python.h>
#include <iostream>
int main()
{
	Py_Initialize();

	PyRun_SimpleString("print 'Hello worldAAA!'"); 

	Py_Finalize();

	std::cin.get();
	return 0;
}