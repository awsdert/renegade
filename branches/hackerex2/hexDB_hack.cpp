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
	first	= 0xFFFFF;
	next	= 0xFFFFF;
	info	= 0u;
	line	= 0;
}
Hacks::Hacks()
{
	m_count = 0u;
	clear();
}
ui32 Hacks::find( Text name, ui32 parent )
{
	Hack obj;
	for ( ui32 i = 0; i < m_count; ++i )
	{
		obj = m_data[ i ];
		if ( parent == obj.parent && name == obj.name )
			return i;
	}
	return 0xFFFFFF;
}