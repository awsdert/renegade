#include "hex2_global.h"

#ifdef xsMSW
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#endif

#ifndef HACKEREX_DLL_APP
#define HACKEREX_DLL_APP

#ifdef xsMSW
typedef HANDLE osHdl;
typedef HMODULE osMod;
const Text osDotExe = wxT(".exe");
xsDLL PROCESSENTRY32 mswGetPE32( DWORD appID );
#else
typedef void* osHdl;
struct osMod
{
	Text name;
};
const Text osDotExe;
#endif
osMod xsDLL AddLib( Text name );
osMod xsDLL RemLib( Text name );
xsDLL ui32 GetAppRam( osHdl hApp, ui64 address, void* value, ui32 bytes );
xsDLL ui32 SetAppRam( osHdl hApp, ui64 address, void* value, ui32 bytes );
xsDLL osHdl NewAppHandle( Text exe );
xsDLL bool NewAppHandle( osHdl hApp, Text exe );
xsDLL void DelAppHandle( osHdl hApp );
xsDLL bool IsAppAlive( osHdl hApp );
xsDLL Text GetAppExe( DWORD appID );

#endif // HACKEREX_DLL_APP
