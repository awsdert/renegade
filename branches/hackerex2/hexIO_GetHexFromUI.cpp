#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize )
{
	int b = tSize - 1;
	ui08 *data = reinterpret_cast< ui08* >( to );
	if ( tSize > 10u )
	{
		for ( ; b >= 0; --b )
			data[ b ] = 0u;
		return false;
	}
	bool r = true;
	ui16 d = 0u;
	ui08 v = 0u;
	wxChar c;
	from.UpperCase();
	int iEnd = from.Length();
	int i = 0, j = 0, k = 0, t = 0;
	if ( from[ 0 ] == cPos )
	{
		--iEnd;
		from = from.Right( iEnd );
	}
	for ( ; b >= 0; ++i )
	{
		if ( i < iEnd )
		{
			c = from[ i ];
			if ( c >= c0 && c <= c9 )
				t = c - c0;
			else
			{
				r = false;
				continue;
			}
			d *= 10;
			d += t;
			v = ( d & 0xFF );
			if ( d > 0xFFF )
				++k;
		}
		else
			++k;
		data[ j ] = v;
		if ( j < k )
		{
			--b;
			j = k;
			d >>= 8u;
			v = d;
		}
	}
	return r;
}
