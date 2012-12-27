#include "hexDB_hexIO.h"
bool xsDLL GetHex( void* to, Text  from, ui08 tSize, ui08 tType )
{
	switch ( tType )
	{
		case HEX_TYPE_UI: return GetHexFromUI( to, from, tSize );
		case HEX_TYPE_SI: return GetHexFromSI( to, from, tSize );
		case HEX_TYPE_SF_IEEE754:
			return GetHexFromSF_IEEE754( to, from, tSize );
	}
	int b = tSize - 1;
	ui08 *data = reinterpret_cast< ui08* >( to );
	if ( tSize > 32u )
	{
		for ( ; b >= 0; --b )
			data[ b ] = 0u;
		return false;
	}
	bool r = true;
	ui08 bit = 0u, d, v = 0u;
	wxChar c;
	from.UpperCase();
	int i = from.Length() - 1, j = 0;
	for ( ; b >= 0; --i )
	{
		if ( i >= 0 )
		{
			c = from[ i ];
			if ( c >= c0 && c <= c9 )
				d = c - c0;
			else if ( c >= cA && c <= cF )
			{
				d = c - cA;
				d += 10u;
			}
			else
			{
				r = false;
				continue;
			}
			if ( bit > 0u )
				d <<= 4u;
			v += d;
		}
		data[ j ] = v;
		bit += 4u;
		if ( bit == 8u )
		{
			--b; ++j;
			bit = 0u;
			v = 0u;
		}
	}
	return r;
}
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize )
{
	ui08 b, *data = reinterpret_cast< ui08* >( to );
	if ( tSize > 8u )
	{
		for ( b = 0u; b < tSize; ++b )
			data[ b ] = 0u;
		return false;
	}
	ui64 val = 0u, bNxt = 0xFF, vPrev = 0u, vMax = 0u;
	for ( b = 0u; b < tSize; b++ )
	{
		vMax <<= 8u;
		vMax += 0xFF;
	}
	wxChar c;
	int i, iEnd = from.Length();
	for ( i = 0, b = 0u; ( i < iEnd && b < tSize ); ++i )
	{
		c = from[ i ];
		if ( c >= c0 && c <= c9 )
			c -= c0;
		else
			break;
		val *= 10u;
		val += c;
		if ( val > vMax || val < vPrev )
		{
			val = vMax;
			break;
		}
		vPrev = val;
		if ( val > bNxt )
		{
			++b;
			bNxt <<= 8u;
			bNxt += 0xFF;
		}
	}
	ui08 *d64 = reinterpret_cast< ui08* >( &val );
	int k = tSize - 1u;
	for ( int j = 7; k >= 0; --j, --k )
		data[ k ] = d64[ j ];
	return ( b < tSize );
}
bool xsDLL GetHexFromSI( void* to, Text  from, ui08 tSize )
{
	ui08 b, *data = reinterpret_cast< ui08* >( to );
	if ( tSize > 8u )
	{
		for ( b = 0u; b < tSize; ++b )
			data[ b ] = 0u;
		return false;
	}
	ui64 val = 0u, bNxt = 0xFF, vMax = 0x7FLL;
	for ( b = 1u; b < tSize; b++ )
	{
		vMax <<= 8u;
		vMax += 0xFF;
	}
	wxChar c = from[ 0u ];
	bool isNeg = ( c == cNeg );
	int i, iEnd = from.Length();
	if ( !isNeg && c != cPos && ( c < c0 || c > c9 ) )
		i = iEnd;
	for ( i = 0, b = 0u; ( i < iEnd && b < tSize ); ++i )
	{
		c = from[ i ];
		if ( c >= c0 && c <= c9 )
			c -= c0;
		else
			break;
		val *= 10u;
		val += c;
		if ( val > vMax )
		{
			val = vMax;
			break;
		}
		if ( val > bNxt )
		{
			++b;
			bNxt <<= 8u;
			bNxt += 0xFF;
		}
	}
	ui08 *d64 = reinterpret_cast< ui08* >( &val );
	int k = tSize - 1u;
	for ( int j = 7; k >= 0; --j, --k )
		data[ k ] = d64[ j ];
	if ( !isNeg )
		data[ 0u ] |= 0x80;
	return ( b < tSize );
}
// TODO(awsdert) Script IEEE754 functions
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize ) { return false; }
bool xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) { return false; }
