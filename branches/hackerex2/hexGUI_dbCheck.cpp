#include "hexGUI_G.hpp"
bool G::CheckDirs( Text& path, Text& leaf, int inMode )
{
	TxtA dirA;
	const Text orgFN = wxT("org");
	const Text pfmFN = m_org.fileOld;
	const Text binFN = m_pfm.fileOld;
	const Text pflFN = m_bin.fileOld;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
			leaf = wxT("hex");
			break;
		case HEX_LIST_PFM:
			dirA.Add( orgFN );
			leaf = pfmFN;
			break;
		case HEX_LIST_BIN:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			leaf = binFN;
			break;
		case HEX_LIST_PFL:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			dirA.Add( binFN );
			leaf = pflFN;
			break;
		case HEX_LIST_HCK:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			dirA.Add( binFN );
			dirA.Add( pflFN );
			leaf = m_pfl.fileOld;
			break;
		default: return false;
	}
	bool b = true;
	int i, iSize = dirA.GetCount();
	for ( i = 0; i < iSize; ++i )
	{
		path += m_sep + dirA[ i ];
		b = wxDirExists( path );
		b = b ? b : wxMkdir( path );
		if ( !b ) return false;
	}
	return true;
}
bool G::CheckFilesT( Text& path, Text& leaf, int inMode )
{
	Text subP;
	return CheckFilesT( path, leaf, subP, inMode );
}
bool G::CheckFilesT( Text& path, Text& leaf, Text& subP, int inMode )
{
// FIXME(awsdert) 0: Refine G::CheckPaths();
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		inMode = m_ListNow;
	const Text dirParent = m_sep + wxT("..");
	path = m_ListCwd ? wxGetCwd() + dirParent : wxGetDataDir();
	bool b = CheckDirs( path, leaf, inMode );
	if ( !b ) return false;
	Text ext, oldP, oldE, msg;
	wxDir dir;
	TxtA dirFA;
	int i, iEnd;
	switch ( inMode )
	{
	case HEX_LIST_ORG:
		ext  = wxT( ".ini" );
		break;
	case HEX_LIST_PFM:
		ext  = wxT( ".hexp" );
		break;
	case HEX_LIST_BIN:
		ext  = wxT( ".hexb" );
		break;
	case HEX_LIST_PFL:
		ext  = wxT( ".hexdb" );
		break;
	case HEX_LIST_HCK:
		oldE = wxT( "*.hexcl" );
		ext  = wxT( ".hexc" );
		oldP = path + dirParent;
		dir.GetAllFiles( oldP, &dirFA, oldE );
		iEnd = dirFA.GetCount();
		msg = oldP;
		for ( i = 0; i < iEnd; ++i )
		{
			subP = m_sep + dirFA[ i ];
			msg += wxT("\n") + subP + wxT(" = ") + subP.Left( subP.Length() - 2 ) + wxT("1");
			/*
			if ( !wxRenameFile( oldP + subP, path + subP.Left( subP.Length() - 2 ) + wxT("1") ) )
				return false;
			*/
		}
		wxMessageBox( msg );
		return false;
		//break;
	}
	leaf += ext;
	return b;
}
