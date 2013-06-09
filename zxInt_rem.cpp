#include "zxInt.h"
void zxInt::m_rem( zxInt& source, zxInt& value )
{
	ui16 s, v = 0u,
		vBits = value.m_bits,
		sBits = source.m_bits,
		end = ( vBits < sBits ) ? vBits : sBits;
	ui08 tmp, vBit = 1u, V = 0u, S, sBit,
		*src = source.m_data,
		*val = value.m_data;
	for ( ; v < end; ++v )
	{
		if ( ( val[ V ] & vBit ) > 0u )
		{
			tmp = 0u;
			for ( sBit = 1u; sBit < vBit; sBit <<= 1u )
				tmp |= ( src[ V ] & sBit );
			for ( s = v, S = V; ( s < sBits && ( src[ S ] & sBit ) == 0u ); ++s )
			{
				tmp |= sBit;
				sBit <<= 1u;
				if ( sBit == 0u )
				{
					sBit = 1u;
					src[ S ] = tmp;
					tmp = 0u;
					++S;
				}
			}
			if ( s < sBits )
			{
				for ( sBit <<= 1u; sBit > 0u; sBit <<= 1u )
					tmp |= ( src[ S ] & sBit );
				src[ S ] = tmp;
			}
		}
		vBit <<= 1u;
		if ( vBit == 0u )
		{
			vBit = 1u;
			++V;
		}
	}
}
zxInt	zxInt::operator-	( zxInt value )
{
	zxInt newValue = *this;
	m_rem( newValue, value );
	return newValue;
}
zxInt&	zxInt::operator-=	( zxInt value )
{
	m_rem( *this, value );
	return *this;
}
zxInt&	zxInt::operator--	( void )
{
	m_rem( *this, zxUInt( 1u ) );
	return *this;
}
/* Unsigned */
zxUInt	zxUInt::operator-	( zxUInt value )
{
	zxUInt newValue = *this;
	m_rem( newValue, value );
	return newValue;
}
zxUInt&	zxUInt::operator-=	( zxUInt value )
{
	m_rem( *this, value );
	return *this;
}