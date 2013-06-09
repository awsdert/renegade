#include "hexObjs_main.h"

zxDLL_EXP Text getGlobalName( void ) { return _("Default"); }

State::State() { clear(); }

dName::dName( void )
{
	name = getGlobalName();
}

dFile::dFile( void )
	: dName()
{
	file = wxT("default");
}

Org::Org( void )
	: dFile() {}

Pfm::Pfm( void )
	: dFile()
{
	endian = 0u;
}

Ram::Ram( void ) { clear(); };

Bin::Bin( void )
	: dFile()
{
	ramNo = 0u;
	type  = 0u;
	resize( 1u );
}

Pfl::Pfl( void )
	: dFile()
{
	profile = 0u;
	region = 0u;
}

Fmt::Fmt( void )
	: dFile() {}

TrID::TrID( int i ) : wxTreeItemData() { index = i; }

Code::Code( void ) { resize( 0u, 0uLL ); }

Hack::Hack( void )
{
	clear();
}
Hacks::Hacks( void )
{
	hackNow = -1;
	hackOld = -1;
}