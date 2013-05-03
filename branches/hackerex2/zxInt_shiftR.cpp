#include "zxInt.h"
void zxInt::m_shiftR( zxInt& source, ui16 bits )
{
	if ( bits > source.m_bits )
	{
		if ( source.m_signed )
			source = zxSInt( 0 );
		else
			source = zxUInt( 0u );
		return;
	}
	zxInt value = source;
	ui08 s = 0u, v = 0u,
		size = source.m_size,
		last = size - 1,
		*src = source.m_data,
		*val = value.m_data;
	ui16
		mov = bits,
		rem = zxBITS_PER_BYTE,
		tmp = 0u;
	for ( ; mov >= rem; ++v, mov -= rem );
	for ( ; v < size; ++v, ++s )
	{
		if ( v < last )
		{
			tmp = val[ v + 1 ];
			tmp <<= rem;
		}
		else
			tmp = 0u;
		tmp |= val[ v ];
		tmp >>= mov;
		src[ s ] = ( tmp & 0xFF );
	}
	for ( ; s < size; ++s )
		src[ s ] = 0u;
}
zxInt	zxInt::operator>>	( ui16 bits )
{
	zxInt obj( *this );
	m_shiftR( obj, bits );
	return obj;
}
zxInt&	zxInt::operator>>=	( ui16 bits )
{
	m_shiftR( *this, bits );
	return *this;
}