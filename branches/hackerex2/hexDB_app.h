#include "hex2_global.h"
#ifndef HACKEREX_DLL_APP
#define HACKEREX_DLL_APP

#ifdef xsMSW
#include <tlhelp32.h>
#include <psapi.h>
PROCESSENTRY32 xsDLL mswGetPE32( DWORD appID );
#endif
Text xsDLL GetAppExe( DWORD appID );
#endif // HACKEREX_DLL_GLOBAL
