#include "main.h"
// This is just in case data of some sort needs initialising first, avoid if you can since the DLL is never attached for long term
void l_init( void );
void l_term( void );
#ifdef zxMSW
#include <windows.h>
zxC_EXT int WINAPI DllMain( HANDLE hMod, DWORD reason, LPVOID ignore )
{
	switch ( reason )
	{
		case DLL_PROCESS_ATTACH:
			l_init();
			break;
		case DLL_PROCESS_DETACH:
			l_term();
			break;
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
			return 0;
		default: return -1;
	}
}
#else
zxC_EXT void __attribute__ ((constructor)) g_init( void )
{
	l_init();
}
zxC_EXT void __attribute__ ((destructor)) g_term( void )
{
	l_term();
}
#endif
void l_init( void ) {}
void l_term( void ) {}