#include "zxText.h"
zxText zxText::operator= ( zxText text )
{
	clear();
	append( text );
	return *this;
}
zxText zxText::operator+ ( zxText text )
{
	zxText val( *this );
	val.append( text );
	return val;
}
zxText zxText::operator+= ( zxText text )
{
	append( text );
	return *this;
}
zxText zxText::operator<< ( zxText text )
{
	zxText val( *this );
	val.append( text );
	return val;
}
zxText zxText::operator<<= ( zxText text )
{
	append( text );
	return *this;
}
bool zxText::operator== ( zxText text )
{
	if ( m_count != text.m_count )
		return false;
	for ( int i = 0; i < m_count; ++i )
	{
		if ( m_data[ i ] != text.m_data[ i ] )
			return false;
	}
	return true;
}
bool zxText::operator!= ( zxText text )
{
	if ( m_count != text.m_count )
		return true;
	for ( int i = 0; i < m_count; ++i )
	{
		if ( m_data[ i ] != text.m_data[ i ] )
			return true;
	}
	return true;
}