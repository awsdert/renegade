#include <tchar.h>
#include <string>
#include "zxVector.h"

#ifndef zxText_h
#define zxText_h

#ifdef _UNICODE
#define zxT( m_txt ) __T( m_txt )
#else
#define zxT( m_txt ) m_txt
#endif

typedef TCHAR zxChar;

struct zxDLL zxText : zxVector< zxChar >
{
	void m_printf( zxText fmt, ... );
	zxText( void );
	zxText( char* text, sint iLength = 0 );
	zxText( wchar_t* text, sint iLength = 0 );
	zxText( const char* text, sint iLength = 0 );
	zxText( const wchar_t* text, sint iLength = 0 );
	zxText( const char c );
	zxText( const wchar_t c );
	void append( zxText text );
	void insertBefore( zxText text, si32 pos = -1 );
	void insertAfter( zxText text, si32 pos = -1 );
	char* dataAsChar( void );
	wchar_t* dataAsWChar_t( void );
	sint length( void ) { return m_count; }
	zxText substr( si32 iStart = 0, si32 iEnd = -1 );
	void toLowerCase( void );
	void toUpperCase( void );
	zxText	operator=	( zxText text );
	zxText	operator+	( zxText text );
	zxText	operator+=	( zxText text );
	zxText	operator<<	( zxText text );
	zxText	operator<<=	( zxText text );
	bool	operator==	( zxText text );
	bool	operator!=	( zxText text );
};
zxDLL zxText zxPrintf( zxText fmt, ... );
zxDLL zxText zxUtoa( unsigned long long int value, ui08 base = 10u );
zxDLL zxText zxItoa( signed long long int value, ui08 base = 10u );
zxDLL uill	 zxAtou( zxText text, ui08 base = 10u );
zxDLL sill	 zxAtoi( zxText text, ui08 base = 10u );
zxDLL zxText zxGetHex(	uill	source );
zxDLL uill	 zxGetHex(	zxText	source );
zxDLL zxText zxGetUI(	uill	source );
zxDLL uill	 zxGetUI(	zxText	source );
zxDLL zxText zxGetSI(	sill	source );
zxDLL sill	 zxGetSI(	zxText	source );

#endif