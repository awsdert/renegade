#include "zxInt.h"
void zxInt::m_xor( zxInt& source, zxInt& value )
{
	ui08 i = 0u,
		sEnd = source.m_size,
		vEnd = value.m_size,
		end = ( vEnd < sEnd ) ? vEnd : sEnd,
		*src = source.m_data,
		*val = value.m_data;
	for ( ; i < end; ++i )
		src[ i ] ^= val[ i ];
}
zxInt	zxInt::operator^	( zxInt value )
{
	zxInt obj( *this );
	m_xor( obj, value );
	return obj;
}
zxInt&	zxInt::operator^=	( zxInt value )
{
	m_xor( *this, value );
	return *this;
}
/* Unsigned */
zxUInt	zxUInt::operator^	( zxUInt value )
{
	zxUInt obj( *this );
	m_xor( obj, value );
	return obj;
}
zxUInt&	zxUInt::operator^=	( zxUInt value )
{
	m_xor( *this, value );
	return *this;
}