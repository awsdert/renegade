#include "wx_pch.h"
#include "hexLib_app.h"
zxDLL_EXP bool IsAppAlive( zxPHandle hApp )
{
#ifdef zxMSW
	DWORD ec;
	if ( GetExitCodeProcess( hApp, &ec ) )
		return ( ec == STILL_ACTIVE );
	else
		return false;
#else
	return false;
#endif
}