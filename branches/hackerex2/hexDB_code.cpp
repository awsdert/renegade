#include "hexDB_hack.h"
xsDLL Code::Code( void ) { clear(); }
void xsDLL Code::clear( void )
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
	for ( int i = 0; i < 2040; ++i )
		data[ i ] = 0u;
}
ui16 xsDLL Code::size( void ) { return m_count; }
ui16 xsDLL Code::resize( ui16 count )
{
	if ( count > 256u )
		count = 256u;
	ui32 i = count * 8u;
	if ( count >= m_count )
		i = 2040u;
	for ( ; i < 2040u; ++i )
		data[ i ] = 0u;
	m_count = count;
	return count;
}
ui08& xsDLL Code::operator[] ( ui08 i ) { return data[ i *  bytes ]; }
xsDLL Codes::Codes() { clear(); }
