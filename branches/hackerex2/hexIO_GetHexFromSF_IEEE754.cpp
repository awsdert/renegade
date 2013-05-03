#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize )
{
	zxUInt des, val;
	des.setPtr( to, tSize );
	/* Rip out exponent */
	Text exp;
	from.UpperCase();
	ui32 i = 0u, end = from.length();
	for ( ; i < end; ++i )
	{
		if ( from[ i ] == cE )
			break;
	}
	if ( i < end )
	{
		exp = from.SubString( i, end );
		from = from.SubString( 0u, i );
	}
	/* Get Mantissa */
	val = parseInt( from );
	if ( val == 0u )
	{
		des = 0u;
		return false;
	}
	return false;
}
void xsDLL GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) {}
