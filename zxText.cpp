#include "zxText.h"

zxText::zxText( void )
{
	m_clear();
}
/*
zxText::zxText( const zxText& text )
{
	m_clear();
	resize( text.m_count );
	for ( int i = 0; i < m_count; ++i )
		m_data[ i ] = text.m_data[ i ];
}
*/
zxText::zxText( const char c )
{
	m_clear();
	resize( 1u );
	m_data[ 0u ] = c;
}
zxText::zxText( const wchar_t c )
{
	m_clear();
	resize( 1u );
#ifndef _UNICODE
	m_data[ 0u ] = ( c & 0xFF );
#else
	m_data[ 0u ] = c;
#endif
}
zxText::zxText( char* text, int iLength )
{
	m_clear();
	if ( text == NULL )
		return;
	int i = iLength;
	if ( i < 1 )
		for ( ; text[ i ] != NULL; ++i );
	resize( i );
	for ( i = 0u; i < m_count; ++i )
		m_data[ i ] = text[ i ];
}
zxText::zxText( wchar_t* text, int iLength )
{
	m_clear();
	wchar_t c;
	if ( text == NULL )
		return;
	int i = iLength;
	if ( i < 1 )
		for ( ; text[ i ] != NULL; ++i );
	resize( m_count + i );
	for ( i = 0u; i < m_count; ++i )
	{
		c = text[ i ];
#ifndef _UNICODE
		if ( c > 127 )
			c = 0;
		m_data[ i ] = (c & 0xFF);
#else
		m_data[ i ] = c;
#endif
	}
}
zxText::zxText( const char* text, int iLength )
{
	m_clear();
	if ( text == NULL )
		return;
	int i = iLength;
	if ( i < 1 )
		for ( ; text[ i ] != NULL; ++i );
	resize( i );
	for ( i = 0u; i < m_count; ++i )
		m_data[ i ] = text[ i ];
}
zxText::zxText( const wchar_t* text, int iLength )
{
	m_clear();
	wchar_t c;
	if ( text == NULL )
		return;
	int i = iLength;
	if ( i < 1 )
		for ( ; text[ i ] != NULL; ++i );
	resize( m_count + i );
	for ( i = 0u; i < m_count; ++i )
	{
		c = text[ i ];
#ifndef _UNICODE
		if ( c > 127 )
			c = 0;
		m_data[ i ] = (c & 0xFF);
#else
		m_data[ i ] = c;
#endif
	}
}