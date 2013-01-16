#include "wx_pch.h"
#include "hexDB_hack.h"
Code::Code( void ) { resize( 0u, 0uLL ); }
void Code::clearCode( void )
{
	int i;
	for ( i = 0; i < 2; ++i )
		addr[ i ] = 0uLL;
	type	= 0u;
	bytes	= 0u;
	ram		= 0u;
	depth	= 0u;
	loop	= 0u;
	hex		= 0u;
	mode	= 0u;
	info	= 0u;
	resize( 0u, 0uLL );
}
Codes::Codes()
{
	m_count = 0u;
	codeOld = 0;
	codeNow = 0;
}
