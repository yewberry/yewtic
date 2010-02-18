#include "IconvMgr.h"

IconvMgr::IconvMgr(const char* fromCharset, const char* toCharset)
{
	m_cd = iconv_open(toCharset, fromCharset);
	if( (iconv_t)-1 == m_cd ){
		m_cd = 0;
	}
}

IconvMgr::~IconvMgr(void)
{
	if( m_cd )iconv_close(m_cd);
}

std::string IconvMgr::wcs2utf8(std::wstring& src)
{
	std::string ret;

	for(int i=0,len=src.size(); i<len; i+=IconvMgr::WCS_UTF8_STEP){
		std::wstring sub = src.substr(i, IconvMgr::WCS_UTF8_STEP);
		const wchar_t* ws = sub.c_str();
		char mbsBuff[(IconvMgr::WCS_UTF8_STEP+1)<<1];
		char utfBuff[IconvMgr::BUFF_SIZE];
		
		setlocale(LC_ALL,"");
		size_t cn = 0;
		wcstombs_s( &cn, mbsBuff, (IconvMgr::WCS_UTF8_STEP+1)<<1, ws, _TRUNCATE);
		setlocale(LC_ALL,"C");

		IconvMgr cvt("", "UTF-8");
		cvt.convert(mbsBuff, strlen(mbsBuff), utfBuff, IconvMgr::BUFF_SIZE);

		ret.append(utfBuff);
	}

	return ret;
}

std::wstring IconvMgr::utf82wcs(std::string& src)
{
	std::wstring ret;

	for(int i=0,len=src.size(); i<len; i+=IconvMgr::UTF8_WCS_STEP){
		std::string sub = src.substr(i, IconvMgr::UTF8_WCS_STEP);
		const char* str = sub.c_str();
		char mbsBuff[IconvMgr::BUFF_SIZE];
		wchar_t wcsBuff[IconvMgr::BUFF_SIZE];
		
		IconvMgr cvt("UTF-8", "");
		cvt.convert(str, strlen(str), mbsBuff, IconvMgr::BUFF_SIZE);

		setlocale(LC_ALL,"");
		size_t cn = 0;
		mbstowcs_s( &cn, wcsBuff, IconvMgr::BUFF_SIZE, mbsBuff, _TRUNCATE);
		setlocale(LC_ALL,"C");
		
		ret.append(wcsBuff);
	}

	return ret;
}

size_t IconvMgr::convert(const char* src, size_t srcLen, char* dest, size_t destLen)
{
	if( m_cd ){
		const char **inbuf = &src;
		char **outbuf = &dest;
		memset(dest, 0, destLen);
		return iconv(m_cd, inbuf, &srcLen, outbuf, &destLen);
	} else {
		return 0;
	}
}

int IconvMgr::setCharset(const char* fromCharset, const char* toCharset)
{
	if( m_cd )iconv_close(m_cd);
	m_cd = iconv_open(toCharset, fromCharset);
	if( (iconv_t)-1 == m_cd ){
		m_cd = 0;
		return 1;
	} else {
		return 0;
	}

}