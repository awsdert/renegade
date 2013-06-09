#include "wx_pch.h"
#include "hexLib_enum.h"

zxDLL_EXP void ListApps( hexLib& lib )
{
	/* TODO: Implement G::ListApps(TxtA&, bool)
		Format:
		exe/name "Title" - process id
		Format Example:
		example "Hello World" - 0000
		*/
#ifdef zxMSW
	EnumWindows( mswEnumWin, reinterpret_cast< LPARAM >( &lib ) );
#endif // xsMSW
}
