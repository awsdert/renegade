#include "hexDB_hack.hpp"
xsDLL Hack::Hack(  void ) { hckClear(); }
xsDLL Hack::~Hack( void ) { hckClear(); }
void xsDLL Hack::hckClear( void )
{
	hckName		= _( "Hack" );
	hckParent	= 0u;
	hckUse		= 0u;
	clear();
}
