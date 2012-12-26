#include "hexDB_hack.h"
TxtA l_formats;
bool l_setFormats = false;
void setFormats( void )
{
	l_formats.SetCount( HL_COUNT );
	l_formats[ HL_HEX1 ] = wxT("HEX1");
	l_formats[ HL_HEX2 ] = wxT("HEX2");
	l_formats[ HL_SONY_PS2_ARMAX_RAW ] = wxT("SONY_PS2_ARMAX_RAW");
	l_setFormats = true;
}
Text xsDLL getFormatName( int	format )
{
	if ( !l_setFormats )
		setFormats();
	return l_formats[ format ];
}
int  xsDLL getFormat( Text	name )
{
	if ( !l_setFormats )
		setFormats();
	for ( int i = 0; i < HL_COUNT; ++i )
	{
		if ( name == l_formats[ i ] )
			return i;
	}
	return -1;
}
