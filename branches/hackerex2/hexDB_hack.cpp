#include "hexDB_hack.h"
#include "hex2_global.h"
xsDLL TrID::TrID( int i ) : wxTreeItemData() { index = i; }
xsDLL Format::Format( int f ) { clear( f ); }
void xsDLL Format::clear( int theFormat )
{
	format	= theFormat;
	name	= getFormatName( format );
	fileOld = name;
	fileNow = name;
}
xsDLL Hack::Hack(  void ) { clear(); }
void xsDLL Hack::clear( void )
{
	name	= _( "Hack" );
	parent	= 0u;
	info	= 0u;
	line	= 0;
}
xsDLL Hacks::Hacks()
{
	hackNow = 0;
	hackOld = 0;
	resize(1);
}
int xsDLL Hacks::find( Text name, ui16 parent )
{
	Hack obj;
	int iEnd = size();
	for ( int i = 0; i < iEnd; ++i )
	{
		obj = at( i );
		if ( parent == obj.parent && name == obj.name )
			return i;
	}
	return -1;
}
