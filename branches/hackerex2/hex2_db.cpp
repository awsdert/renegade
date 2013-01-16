#include "wx_pch.h"
#include "hex2_db.h"
xsDLL Text getGlobalName( void ) { return _("(Default)"); }
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
	ramNo = 0u;
	type  = 0u;
	resize( 1u );
};
Pfl::Pfl( void ) : Org()
{
	profile = 0u;
	region = 0u;
}
