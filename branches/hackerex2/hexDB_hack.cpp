#include "hexDB_hack.h"
#include "hex2_global.h"
xsDLL Format::Format( int f ) { clear( f ); }
void xsDLL Format::clear( int theFormat )
{
	format	= theFormat;
	name	= getFormatName( format );
}
xsDLL Hack::Hack(  void ) { clear(); }
void xsDLL Hack::clear( void )
{
	name	= _( "Hack" );
	parent	= 0u;
	info	= 0u;
	line	= 0;
}
int xsDLL Hacks::find( Text name )
{
	int iEnd = size();
	for ( int i = 0; i < iEnd; ++i )
	{
		if ( name == at( i ).name )
			return i;
	}
	return -1;
}
