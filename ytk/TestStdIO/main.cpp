#include <iostream>

using namespace std;

void fmtFlags(){
	ios_base::fmtflags ori_flags = cout.flags();
	
	cout<<812<<'|';
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.width(10);
	cout<<813<<815<<"|\n";

	cout.unsetf(ios_base::adjustfield);
	streamsize ori_pre = cout.precision(2);
	cout.setf(ios_base::uppercase | ios_base::scientific);
	cout<<831.0<<' '<<8e2;

	cout.flags(ori_flags);
	cout.precision(ori_pre);

	cout<<'\n';
	int i = 123;
	char* s = "abc";
	cout.width(10);
	cout<<i<<s;
}

int main(){
	fmtFlags();
	cin.get();
	return 0;
}