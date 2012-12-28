#include "hexDB_main.h"
#include "hexDB_enum.h"

void xsDLL ListApps( hexDB& db )
{
	/* TODO: Implement G::ListApps(TxtA&, bool)
		Format:
		exe/name "Title" - process id
		Format Example:
		example "Hello World" - 0000
		*/
#ifdef xsWIN
	EnumWindows( mswEnumWin, (void*)&db );
#endif // xsWIN
}
