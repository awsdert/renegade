#include "hexGUI_db.hpp"
Org::Org( void )
{
	Text Tmp = wxT("Default"), tmp = wxT("default");
	fileNow = tmp;
	fileOld = tmp;
	nameNow = Tmp;
	nameOld = Tmp;
}
Pfm::Pfm( void ) : Org() {};
Ram::Ram( void ) { Clear(); };
void Ram::Clear( void )
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
		ram[ i ].Clear();
	m_count = count;
	return count;
}
Ram& Bin::operator[]( ui16 i ) { return ram[ i ]; }
