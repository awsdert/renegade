#include "wx_pch.h"
#include "hexDB_hack.h"
#include "hex2_global.h"
TrID::TrID( int i ) : wxTreeItemData() { index = i; }
Format::Format( int f ) { clear( f ); }
void Format::clear( int theFormat )
{
	format	= theFormat;
	name	= getFormatName( format );
	fileOld = name;
	fileNow = name;
}
Hack::Hack(  void ) { clear(); }
void Hack::clear( void )
{
	name	= _( "Hack" );
	parent	= 0u;
	info	= 0u;
	line	= 0;
}
Hacks::Hacks()
{
	hackNow = 0;
	hackOld = 0;
	resize(1);
}
int Hacks::find( Text name, ui16 parent )
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
