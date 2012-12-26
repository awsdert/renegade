#include "hexDB_main.h"
TxtA l_hlTypes;
bool l_hlTypesSet = false;
const TxtA gHL_TEXT_LIST = l_hlTypes;
void xsDLL SetHLTypes( void )
{
	if ( l_hlTypesSet )
		return;
	l_hlTypes.SetCount( HL_COUNT );
	l_hlTypes[ HL_HEX1 ] = wxT("HEX1");
	l_hlTypes[ HL_HEX2 ] = wxT("HEX2");
	l_hlTypes[ HL_SONY_PS2_ARMAX_RAW ] = wxT("SONY_PS2_ARMAX_RAW");
}
int xsDLL GetHLType( Text txt )
{
	if ( !l_hlTypesSet )
		SetHLTypes();
	txt.UpperCase();
	for ( int i = 0; i < HL_COUNT; ++i )
	{
		if ( txt == gHL_TEXT_LIST[ i ] )
			return i;
	}
	return -1;
}
