#include "zxInt.h"
void zxInt::m_shiftL( zxInt& source, ui16 bits )
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
	ui08
		size = source.m_size,
		last = size - 1,
		s = 0u, v = 0u, l,
		*src = source.m_data,
		*val = value.m_data;
	ui16
		mov = bits,
		rem = zxBITS_PER_BYTE,
		tmp = 0u;
	src[ 0 ] = ( mov < rem ) ? src[ 0 ] << mov : 0u;
	for ( ; mov >= rem; ++s, mov -= rem );
	l = s;
	for ( ; s < size; ++v, ++s )
	{
		tmp = val[ v ];
		tmp <<= rem;
		if ( v > 0u )
			tmp |= val[ v - 1 ];
		tmp <<= mov;
		src[ s ] = ( tmp >> rem );
		if ( v < l )
			src[ v ] = 0u;
	}
}
zxInt	zxInt::operator<<	( ui16 bits )
{
	zxInt obj( *this );
	m_shiftL( obj, bits );
	return obj;
}
zxInt&	zxInt::operator<<=	( ui16 bits )
{
	m_shiftL( *this, bits );
	return *this;
}