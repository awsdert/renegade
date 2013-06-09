#include "wx_pch.h"
#include "hexG_db.h"
/* *
void hexDB::SetGui( hexGui* gui ) { m_gui = gui; m_eGrid.gui = gui; }
Text hexDB::getDefN( int inMode, bool forRoot )
{
	switch ( inMode )
	{
		case HEX_LIST_RAM:	return _("Memory Part");
		case HEX_LIST_HACK: return forRoot ? _("(m)") : _("Hack");
		case HEX_LIST_CODE: return _("(Codelist)");
		default: return getGlobalName();
	}
}
Text hexDB::getNowN( int inMode )
{
	int hn = hacks.hackNow;
	switch ( inMode )
	{
	case HEX_LIST_SESSION:
		return state.nameNow;
	case HEX_LIST_ORG:
		return org.nameNow;
	case HEX_LIST_PFM:
		return pfm.nameNow;
	case HEX_LIST_BIN:
		return bin.nameNow;
	case HEX_LIST_APP:
	case HEX_LIST_WIN:
		return bin.name;
	case HEX_LIST_RAM:
		if ( bin.ramNo >= 0)
			return bin[ bin.ramNo ].name;
		break;
	case HEX_LIST_PFL:
		return pfl.nameNow;
	case HEX_LIST_FORMAT:
		return format.name;
	case HEX_LIST_HACK:
		if ( hn >= 0 )
			return hacks[ hn ].name;
	}
	return getDefN( inMode, true );
}
Text hexDB::m_getDir( void )
{
	Text path = nowP[ HEX_LIST_HACK ] + wxT("_files~");
	if ( !path.IsEmpty() && !wxDirExists( path ) )
		wxMkdir( path );
	return path;
}
Text hexDB::m_getPath( ui32 h )
{
	Text path = m_getDir(), name;
	if ( h <= 0xFFFF )
		name.Printf( wxT("%04X.bin"), h );
	else
		name = wxT("temp.bin");
	path += xsDirSep + name;
	return path;
}
/* */