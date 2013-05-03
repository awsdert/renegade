#include "wx_pch.h"
#include "hex2_db.h"
xsDLL Text getGlobalName( void ) { return _("(Default)"); }
State::State() { clear(); }
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
//*/
Org::Org( void )
{
	name = getGlobalName();
	file = wxT("default");
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
	ramNo = 0u;
	type  = 0u;
	resize( 1u );
};
Pfl::Pfl( void ) : Org()
{
	profile = 0u;
	region = 0u;
}
