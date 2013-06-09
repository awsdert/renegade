#include "zxInt.h"
void zxInt::m_mul( zxInt& source, zxInt& value )
{
	ui16 v = 0u,
		sBits = source.m_bits,
		vBits = value.m_bits,
		end = ( vBits < sBits ) ? vBits : sBits;
	zxUInt src = source, val = value, var = 0u;
	for ( ; v < end; ++v )
	{
		if ( val[ 0 ] & 1u )
			var += src << v;
		val >>= 1u;
	}
	source = var;
}
zxInt	zxInt::operator*	( zxInt value )
{
	zxInt newValue = *this;
	m_mul( newValue, value );
	return newValue;
}
zxInt&	zxInt::operator*=	( zxInt value )
{
	m_mul( *this, value );
	return *this;
}
/* Unsigned */
zxUInt	zxUInt::operator*	( zxUInt value )
{
	zxUInt newValue = *this;
	m_mul( newValue, value );
	return newValue;
}
zxUInt&	zxUInt::operator*=	( zxUInt value )
{
	m_mul( *this, value );
	return *this;
}