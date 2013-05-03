#include "wx_pch.h"
#include "hexG_db.h"
hexDB::hexDB() :
	wxEvtHandler(),
	m_codeBytes( 2100 )
{
	ini = NULL;
	killThreads = false;
	showHacks	= true;
	showAllApps	= true;
	tmpCfg		= false;
	m_hooked	= false;
	//m_MouseW	= false;
	nowL = HEX_LIST_SESSION; oldL = -1;
	m_addrSize	= sizeof( size_t );
	m_eGrid.db = this;
	cwd = wxGetCwd();
	tmpCwd = true;
	switch ( m_addrSize )
	{
	case 8: m_moveAddr = 0; break;
	case 4: m_moveAddr = 32u; break;
	default: m_moveAddr = 64u; break;
	}
	tmpMode		= -1;
	codeNo		= -1;
	hacks.hackNow = -1;
	hacks.hackOld = -1;
	nowP.SetCount( HEX_LIST_COUNT );
	oldP.SetCount( HEX_LIST_COUNT );
	mode[ HEX_LIST_THEME	] = HEX_LIST_ORG;
	mode[ HEX_LIST_SESSION	] = HEX_LIST_ORG;
	mode[ HEX_LIST_ORG		] = HEX_LIST_ORG;
	mode[ HEX_LIST_PFM		] = HEX_LIST_PFM;
	mode[ HEX_LIST_BIN		] = HEX_LIST_BIN;
	mode[ HEX_LIST_APP		] = HEX_LIST_BIN;
	mode[ HEX_LIST_WIN		] = HEX_LIST_BIN;
	mode[ HEX_LIST_RAM		] = HEX_LIST_BIN;
	mode[ HEX_LIST_PFL		] = HEX_LIST_PFL;
	mode[ HEX_LIST_FORMAT	] = HEX_LIST_FORMAT;
	mode[ HEX_LIST_HACK		] = HEX_LIST_HACK;
	mode[ HEX_LIST_CODE		] = HEX_LIST_HACK;
	mode[ HEX_LIST_FIND		] = HEX_LIST_BIN;
	mode[ HEX_LIST_OUT		] = HEX_LIST_BIN;
	mode[ HEX_LIST_EDIT		] = HEX_LIST_BIN;
	for ( int i = 0; i < HEX_LIST_COUNT; ++i )
		nowM[ i ] = false;
}
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
