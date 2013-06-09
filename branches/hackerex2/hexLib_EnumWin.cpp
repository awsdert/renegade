#include "wx_pch.h"
#include "hexLib_main.h"

#ifdef zxMSW
hexLibDLL BOOL CALLBACK mswEnumWin( HWND hWin, LPARAM ptr2lib )
{
	hexLib* lib = reinterpret_cast< hexLib* >( ptr2lib );
	if ( lib->m__bin.m_now.type == 2u && !IsWindowVisible( hWin ) )
		return TRUE;
	LBox* lb = lib->m__bin.lbox_main;
	DWORD pid = 0u;
	GetWindowThreadProcessId( hWin, &pid );
	TCHAR title[ MAXCHAR ];
	SendMessage( hWin, WM_GETTEXT, MAXBYTE, reinterpret_cast< LPARAM >( &title ) );
	zxProc proc;
	proc.zxGetPE32( pid );
	Text txt, exe = proc.m_name.data();
	txt.Printf( wxT(" (%s) %04X"), title, pid );
	exe.Left( exe.Length() - 5 );
	lb->Append( exe + txt );
	lb->SetSelection( -1 );
	return TRUE;
}
#endif // xsMSW
