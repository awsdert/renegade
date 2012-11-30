#include "hexDB_hack.hpp"
xsDLL Code::Code(	 void ) { cdeClear(); }
xsDLL Code::~Code( void ) { cdeClear(); }
void xsDLL Code::cdeClear( void )
{
	clear();
	cdeAddr[ 0u ] = 0u;
	cdeAddr[ 1u ] = 0u;
	cdeType	 = 0u;
	cdeSize	 = 0u;
	cdeRam	 = 0u;
	cdeDepth = 0u;
	cdeLoop	 = 0u;
	cdeHex	 = 0u;
	cdeMode	 = 0u;
	cdeInfo	 = 0u;
}
