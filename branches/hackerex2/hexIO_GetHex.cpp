#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHex( void* to, Text  from, ui08 bytes, ui08 tType )
{
	int b = bytes - 1;
	ui08 *data = reinterpret_cast< ui08* >( to );
	if ( tType != HEX_TYPE_HEX || bytes > 32u )
	{
		switch ( tType )
		{
			case HEX_TYPE_UI: return GetHexFromUI( to, from, bytes );
			case HEX_TYPE_SI: return GetHexFromSI( to, from, bytes );
			case HEX_TYPE_SF_IEEE754:
				return GetHexFromSF_IEEE754( to, from, bytes );
			default:
				for ( ; b >= 0; --b )
					data[ b ] = 0u;
				return false;
		}
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
void xsDLL GetTxt( Text& to, void* from, ui08 bytes, ui08 fType )
{
	int B = ( bytes > 0u ) ? bytes - 1u : 0u;
	ui08 *data = reinterpret_cast< ui08* >( from );
	if ( fType != HEX_TYPE_HEX )
	{
		switch ( fType )
		{
			case HEX_TYPE_UI:
			case HEX_TYPE_SI:
			case HEX_TYPE_SF_IEEE754:
			default:
				for ( ; B >= 0; --B )
					data[ B ] = 0u;
				to = wxT("0");
				return;
		}
	}
	int b;
	to.Clear();
	ui08 d, c, t = 0u;
	for ( ; B >= 0; --B )
	{
		d = data[ B ];
		for ( b = 0; b < 8; b += 4 )
		{
			c = ( d & 0xF0 ) >> 4u;
			d <<= 4u;
			if ( c < 0xA )
			{
				if ( c == 0u && t == 0u )
					continue;
				to += ( c0 + c );
				++t;
			}
			else
			{
				c -= 0xA;
				to += ( cA + c );
				++t;
			}
		}
	}
	if ( t == 0u )
		to = wxT("0");
}