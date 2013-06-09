#include "wx_pch.h"
#include "hexLib_main.h"
zxDLL_EXP bool GetHexFromSF_IEEE754( void* to, Text  from, ui08 tSize )
{
	zxUInt des, val;
	des.setPtr( to, tSize );
	/* Rip out exponent */
	Text exp;
	wxChar cE = wxT('E');
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
	val = parseInt( from.data() );
	if ( val == 0u )
	{
		des = 0u;
		return false;
	}
	return false;
}
zxDLL_EXP void GetTxtFromSF_IEEE754( Text& to, void* from, ui08 fSize ) {}
