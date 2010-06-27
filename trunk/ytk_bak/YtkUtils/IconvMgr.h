#ifndef ICONV_MGR_H
#define ICONV_MGR_H

#include "iconv/iconv.h"
#include <string>

class IconvMgr
{
public:
	IconvMgr(void):m_cd(0){}
	IconvMgr(const char* fromCharset, const char* toCharset);
	~IconvMgr(void);

	static std::string wcs2utf8(std::wstring& src);
	static std::wstring utf82wcs(std::string& src);

	size_t convert(const char *src, size_t srcLen, char *dest, size_t destLen);
	int setCharset(const char* fromCharset, const char* toCharset);

public:
	//A wchar_t will consume 6 byte in utf8 at most.
	static const int BUFF_SIZE = 102;
	static const int WCS_UTF8_STEP = 17;
	static const int UTF8_WCS_STEP = 51;
private:
	iconv_t	m_cd;
};

#endif // ICONV_MGR_H