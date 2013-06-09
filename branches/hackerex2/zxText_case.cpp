#include "zxText.h"
void zxText::toLowerCase( void )
{
	zxChar c;
	for ( int i = 0; i < m_count; ++i )
	{
		c = m_data[ i ];
		if ( c >= zxT('A') && c <= zxT('Z') )
			m_data += 32;
	}
}
void zxText::toUpperCase( void )
{
	zxChar c;
	for ( int i = 0; i < m_count; ++i )
	{
		c = m_data[ i ];
		if ( c >= zxT('a') && c <= zxT('z') )
			m_data -= 32;
	}
}