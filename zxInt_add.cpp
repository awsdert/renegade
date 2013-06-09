#include "zxInt.h"
void zxInt::m_add( zxInt& source, zxInt& value )
{
	ui08 tmp = 0u,
		cBit = 0u,
		vBit = 1u,
		*src = source.m_data,
		*val = value.m_data,
		V = 0u;
	ui16 v = 0u,
		sBits	= source.m_bits,
		vBits	= value.m_bits,
		end = ( vBits < sBits ) ? vBits : sBits;
	for ( ; v < end; ++v )
	{
		if ( cBit > 0u )
		{
			if ( src[ V ] & cBit )
				src[ V ] &= ~cBit;
			else
			{
				src[ V ] |= cBit;
				cBit = 0u;
			}
		}
		if ( val[ V ] & vBit )
		{
			if ( src[ V ] & vBit )
			{
				src[ V ] &= ~vBit;
				cBit = vBit;
			}
			else
				src[ V ] |= vBit;
		}
		vBit <<= 1u;
		if ( cBit > 0u )
		{
			cBit <<= 1u;
			if ( cBit == 0u )
				cBit = 1u;
		}
		if ( vBit == 0u )
		{
			++V;
			vBit = 1u;
		}
	}
	if ( cBit > 0u && source.grow( 1u ) )
		source.m_data[ V ] = 1u;
}
zxInt	zxInt::operator+	( zxInt value )
{
	zxInt newValue = *this;
	m_add( newValue, value );
	return newValue;
}
zxInt&	zxInt::operator+=	( zxInt value )
{
	m_add( *this, value );
	return *this;
}
zxInt&	zxInt::operator++	( void )
{
	m_add( *this, zxUInt( 1u ) );
	return *this;
}
// Unsigned
zxUInt	zxUInt::operator+	( zxUInt value )
{
	zxUInt newValue = *this;
	m_add( newValue, zxUInt( value ) );
	return newValue;
}
zxUInt&	zxUInt::operator+=	( zxUInt value )
{
	m_add( *this, value );
	return *this;
}