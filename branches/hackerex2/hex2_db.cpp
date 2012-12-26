#include "hex2_db.h"
Text getGlobalName( void ) { return _("(Default)"); }
State::State() { clear(); }
void State::clear()
{
	Text tmp	= getGlobalName();
	nameNow		= tmp;
	nameOld		= tmp;
	orgName		= tmp;
	pfmName		= tmp;
	binName		= tmp;
	pflName		= tmp;
	hckFormat	= wxT("HEX1");
}
//*/
Org::Org( void )
{
	Text tmp1	= getGlobalName();
	Text tmp2	= wxT("default");
	fileNow		= tmp2;
	fileOld		= tmp2;
	nameNow		= tmp1;
	nameOld		= tmp1;
}
Pfm::Pfm( void ) : Org() {};
Ram::Ram( void ) { clear(); };
void Ram::clear( void )
{
	name	= _("All Memory");
	depth	= 0u;
	addr	= 0uLL;
	bytes	= 0uLL;
}
Bin::Bin( void ) : Org()
{
	m_count = 1u;
};
Ram& Bin::at( ui08 i ) { return ram[ i ]; }
ui16 Bin::size( void ) { return m_count; }
ui16 Bin::resize( ui16 count, bool clearAll )
{
	ui16 i = clearAll ? 0u : count;
	ui16 c = 16u;
	if ( count == 0u )
		count = 1u;
	else if ( count > 16u )
		count = 16u;
	if ( !clearAll && count >= m_count )
		c = 0u;
	for ( ; i < c; ++i )
		ram[ i ].clear();
	m_count = count;
	return count;
}
Ram& Bin::operator[]( ui08 i ) { return ram[ i ]; }
