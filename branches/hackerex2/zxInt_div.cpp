#include "zxInt.h"
zxInt zxInt::m_div( zxInt& source, ui08 value )
{
	ui08 size = source.m_size,
		*src = source.m_data,
		*tmp = (ui08*)malloc( size );
	si08 s, last = ( size - 1u );
	ui16 vn = 2u, tn, shift = 0u;
	zxInt vz, by;
	vz.setPtr( &vn, 2u );
	by.setPtr( &value, 1u );
	zxUInt r = source;
	switch ( value )
	{
	case 0u:
		for ( s = last; s >= 0; --s )
			src[ s ] = 0u;
	case 1u: break;
	default:
		for ( s = last; s >= 0; --s )
		{
			tmp[ s ] = src[ s ];
			src[ s ] = 0u;
		}
		if ( ( value & 1u ) == 0u )
		{
			tn = 1u;
			for ( shift = 1u; vn < value; vn <<= 1u, ++shift, tn <<= 1u, tn += 1u );
			if ( vn == value )
			{
				r = src[ 0 ] & tn;
				source >>= shift;
			}
			else
				shift = 0u;
		}
		if ( shift == 0u )
		{
			for ( s = last; ( s >= 0 && tmp[ s ] == 0u ); --s );
			vn = 0u;
			for ( ; s >= 0; --s )
			{
				tn = vn << zxBITS_PER_BYTE;
				vn = tmp[ s ];
				vn |= tn;
				for ( tn = 0u; vn >= value; ++tn )
					m_rem( vz, by );
				src[ s ] = ( tn & 0xFF );
			}
			r = vn;
		}
	}
	return r;
}
zxInt	zxInt::operator%	( ui08 value )
{
	zxInt newValue = *this;
	return m_div( newValue, value );
}
zxInt	zxInt::operator/	( ui08 value )
{
	zxInt newValue = *this;
	m_div( newValue, value );
	return newValue;
}
zxInt&	zxInt::operator/=	( ui08 value )
{
	m_div( *this, value );
	return *this;
}