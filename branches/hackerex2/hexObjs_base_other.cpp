#include "hexObjs_main.h"

void State::clear()
{
	Text tmp	= getGlobalName();
	name		= tmp;
	orgName		= tmp;
	pfmName		= tmp;
	binName		= tmp;
	pflName		= tmp;
	fmtName		= wxT("HEX1");
}

void Ram::clear( void )
{
	name	= _("All Memory");
	depth	= 0u;
	addr	= 0uLL;
	bytes	= 0uLL;
}

Text getFormatName( Text id )
{
	Text path = ( ( wxGetCwd() + xsDirSep ) + wxT("formats") ) + id + wxT(".dll"), name = wxT("?????"), *ptr;
	if ( wxFileExists( path ) )
	{
#ifdef zxMSW
		HMODULE lib = LoadLibrary( path.data() );
		FARPROC addr = GetProcAddress( lib, "getName" );
		if ( addr != NULL )
		{
			ptr = (Text*)addr();
			if ( ptr != NULL )
			{
				name = *ptr;
				delete ptr;
			}
		}
		FreeLibrary( lib );
#endif
	}
	return name;
}

void Code::clearCode( void )
{
	addr[ 0u ] = 0u;
	addr[ 1u ] = 0u;
	type	= 0u;
	bytes	= 0u;
	ram		= 0u;
	depth	= 0u;
	loop	= 0u;
	hex		= 0u;
	mode	= 0u;
	info	= 0u;
	resize( 0u, 0u );
}

void Hack::clear( void )
{
	parent   = -1;
	first    = -1;
	next     = -1;
	isActive = false;
	isRadio  = false;
}
si32 Hacks::find( Text name, si32 parent )
{
	sint i = -1;
	if ( parent >= 0 )
	{
		for ( i = m_data[ parent ].first; i >= 0; i = m_data[ i ].next )
		{
			if ( m_data[ i ].name == name )
				break;
		}
	}
	else
	{
		sint j = 0u;
		for ( ; j < m_count; ++j )
		{
			if ( m_data[ j ].name == name )
				break;
		}
		i = ( j == m_count ) ? -1 : j;
	}
	return i;
}