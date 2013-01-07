#include "wx_pch.h"
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
