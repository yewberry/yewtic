#include "IconvMgr.h"
#include <string>
#include <fstream>
#include <locale>

#define MAX 255

using namespace std;

void test1()
{
	string str = "i大量需要转换的编码";
	int size = strlen(str.c_str());
	char d[MAX];

	IconvMgr cvt("GBK", "UTF-8");
	cvt.convert(str.c_str(), size, d, MAX);

	fstream file("temp.txt", ios::in|ios::out|ios::trunc);
	file<<d;

	string s;
	file.seekg(0,ios::beg);
	file>>s;
	IconvMgr cvt1("UTF-8", "GBK");
	size = strlen(s.c_str());
	cvt1.convert(s.c_str(), size, d, MAX);

	file.close();

	wchar_t* ws = L"宽字符a";
	size_t cn = 0;
	int wslen = wcslen(ws)*2;
	char* dd = new char[wslen];
	setlocale(LC_ALL,"");
	wcstombs_s( &cn, dd, wslen, ws, _TRUNCATE);
	setlocale(LC_ALL,"C");

	IconvMgr cvt2("", "UTF-8");
	cvt2.convert(dd, strlen(dd), d, MAX);
	delete[] dd;

	fstream file2("temp2.txt", ios::in|ios::out|ios::trunc);
	file2<<d;
	file2.close();
}

int main() 
{
	wstring str = L"一二三四五六七八九十一二三四五六七八九十a";
	string s = IconvMgr::wcs2utf8(str);
	fstream file("temp.txt", ios::in|ios::out|ios::trunc);
	file<<s;

	string s1;
	file.seekg(0,ios::beg);
	file>>s1;
	wstring ws = IconvMgr::utf82wcs(s1);

	file.close();
	
	return 0;
}