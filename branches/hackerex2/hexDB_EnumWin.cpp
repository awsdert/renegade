#include "hexDB_main.h"
#include "hexDB_enum.h"
#ifdef xsMSW
BOOL CALLBACK mswEnumWin( HWND hWin, LPARAM ptr2hexdb )
{
	hexDB* db = (hexDB*)ptr2hexdb;
	bool show = ( db->tmpMode == HEX_LIST_APP ) ? true : IsWindowVisible( hWin );
	if ( show )
	{
		LBox* lb = db->appsLB;
		DWORD pid;
		GetWindowThreadProcessId( hWin, &pid );
        TCHAR title[ MAXCHAR ];
		SendMessage( hWin, WM_GETTEXT, MAXBYTE, (LPARAM)(void*)title );
		Text txt, exe = GetAppExe( pid );
		txt.Printf( wxT(" (%s) %04X"), title, pid );
		exe.Left( exe.Length() - 5 );
		lb->Append( exe + txt );
		lb->SetSelection( -1 );
	}
	return TRUE;
}
#endif // xsMSW
