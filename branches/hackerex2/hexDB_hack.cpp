#include "wx_pch.h"
#include "hexDB_hack.h"
#include "hex2_global.h"
TrID::TrID( int i ) : wxTreeItemData() { index = i; }
Fmt::Fmt( int f ) { clear( f ); }
void Fmt::clear( int format )
{
	fmt		= format;
	name	= getFormatName( fmt );
	ext		= name;
}
Hack::Hack( void )
{
	m_txt = NULL;
	clear();
}
void Hack::clear( void )
{
	if ( m_txt != NULL )
	{
		m_txt->GetLine( id );
		m_txt->Write( _( "Hack" ) );
	}
	parent   = -1;
	first    = -1;
	next     = -1;
	isActive = false;
	isRadio  = false;
}
Hacks::Hacks()
{
	m_count = 0u;
}
si32 Hacks::find( Text name, si32 parent )
{
	if ( m_names.IsOpened() )
	{
		Hack obj;
		si32 i;
		if ( parent >= 0 )
		{
			for ( i = m_hacks[ parent ].first; i >= 0; i = m_data[ i ].next )
			{
				if ( m_names.GetLine( i ) == name )
					return i;
			}
		}
		else
		{
			for ( si32 i = 0; i < m_count; ++i )
			{
				if ( m_names.GetLine( i ) == name )
					return i;
			}
		}
	}
	return -1;
}