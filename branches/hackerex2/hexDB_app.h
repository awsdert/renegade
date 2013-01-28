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
const Text osDotExe = wxT(".exe");
xsDLL PROCESSENTRY32 mswGetPE32( DWORD appID );
#else
typedef void* osHdl;
const Text osDotExe;
#endif
xsDLL size_t GetAppRam( osHdl hApp, size_t address, void* value, ui32 bytes );
xsDLL size_t SetAppRam( osHdl hApp, size_t address, void* value, ui32 bytes );
xsDLL osHdl NewAppHandle( Text exe );
xsDLL bool NewAppHandle( osHdl hApp, Text exe );
xsDLL void DelAppHandle( osHdl hApp );
xsDLL Text GetAppExe( DWORD appID );

#endif // HACKEREX_DLL_APP
