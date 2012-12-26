#include "hexG_db.h"

hexDB::hexDB()
{
	nowP.SetCount( HEX_LIST_COUNT );
	oldP.SetCount( HEX_LIST_COUNT );
	mode[ HEX_LIST_SESSION ]	= HEX_LIST_ORG;
	mode[ HEX_LIST_ORG ]		= HEX_LIST_ORG;
	mode[ HEX_LIST_PFM ]		= HEX_LIST_PFM;
	mode[ HEX_LIST_BIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_APP ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_WIN ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_RAM ]		= HEX_LIST_BIN;
	mode[ HEX_LIST_PFL ]		= HEX_LIST_PFL;
}
Text hexDB::getNowN( int inMode )
{
	Text name;
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
		name = state.nameNow;
		break;
	case HEX_LIST_ORG:
		name = org.nameNow;
		break;
	case HEX_LIST_PFM:
		name = pfm.nameNow;
		break;
	case HEX_LIST_BIN:
		name = bin.nameNow;
		break;
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
		name = bin.name;
		break;
	case HEX_LIST_RAM:
		name = bin[ ramNo ].name;
		break;
	case HEX_LIST_PFL:
		name = pfl.nameNow;
		break;
	case HEX_LIST_FORMAT:
		name = format.name;
		break;
	case HEX_LIST_HACK:
		name = hacks[ hackNo ].name;
		break;
	default:
		name = getGlobalName();
	}
	return name;
}

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
