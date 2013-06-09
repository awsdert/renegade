#include "hexObjs_main.h"
#include "hexLib_base.h"

#ifdef zxMSW
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#endif

#ifndef hexLib_app_h
#define hexLib_app_h

#ifdef zxMSW
typedef HMODULE osMod;
#else
struct hexLibDLL osMod
{
	Text name;
};
const Text osDotExe;
#endif
hexLibDLL osMod AddLib( Text name );
hexLibDLL osMod RemLib( Text name );
hexLibDLL bool IsAppAlive( zxPHandle hApp );

#endif // HACKEREX_DLL_APP
