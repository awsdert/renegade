#include "zxInt.h"
void zxInt::m_and( zxInt& source, zxInt& value )
{
	ui08 i = 0u,
		sEnd = source.m_size,
		vEnd = value.m_size,
		end = ( vEnd < sEnd ) ? vEnd : sEnd,
		*src = source.m_data,
		*val = value.m_data;
	for ( ; i < end; ++i )
		src[ i ] &= val[ i ];
	for ( ; i < sEnd; ++i )
		src[ i ] = 0u;
}
zxInt	zxInt::operator&	( zxInt value )
{
	zxInt obj( *this );
	m_and( obj, value );
	return obj;
}
zxInt&	zxInt::operator&=	( zxInt value )
{
	m_and( *this, value );
	return *this;
}
/* Unsigned */
zxUInt	zxUInt::operator&	( zxUInt value )
{
	zxUInt obj( *this );
	m_and( obj, value );
	return obj;
}
zxUInt&	zxUInt::operator&=	( zxUInt value )
{
	m_and( *this, value );
	return *this;
}