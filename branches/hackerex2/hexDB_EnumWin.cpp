#include "wx_pch.h"
#include "hexDB_main.h"
#include "hexDB_enum.h"
#ifdef xsMSW
xsDLL BOOL CALLBACK mswEnumWin( HWND hWin, LPARAM ptr2hexdb )
{
	hexDB* db = reinterpret_cast< hexDB* >( ptr2hexdb );
	if ( db->showAllApps || IsWindowVisible( hWin ) )
		return TRUE;
	LBox* lb = db->appsLB;
	DWORD pid = 0u;
	GetWindowThreadProcessId( hWin, &pid );
	TCHAR title[ MAXCHAR ];
	SendMessage( hWin, WM_GETTEXT, MAXBYTE, reinterpret_cast< LPARAM >( &title ) );
	Text txt, exe = GetAppExe( pid );
	txt.Printf( wxT(" (%s) %04X"), title, pid );
	exe.Left( exe.Length() - 5 );
	lb->Append( exe + txt );
	lb->SetSelection( -1 );
	return TRUE;
}
#endif // xsMSW
