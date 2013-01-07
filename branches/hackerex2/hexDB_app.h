#include "hex2_global.h"

#ifdef xsMSW
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#endif

#ifndef HACKEREX_DLL_APP
#define HACKEREX_DLL_APP

#ifdef xsMSW
xsDLL PROCESSENTRY32 mswGetPE32( DWORD appID );
#endif

xsDLL Text GetAppExe( DWORD appID );

#endif // HACKEREX_DLL_APP
