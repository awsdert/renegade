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
ui32 G::CheckRegion( Text region )
{
	region.UpperCase();
	ui32 r = 0u;
	Text comma = wxT(',');
	TxtT txtT;
	txtT.SetString( region, comma );
	if ( !txtT.HasMoreTokens() )
		return 0u;
	Text val;
	const Text uk	= wxT("UK");
	const Text us	= wxT("US");
	const Text aus	= wxT("AUS");
	const Text de	= wxT("DE");
	const Text jp	= wxT("JP");
	for
	(
		val = txtT.GetNextToken();
		txtT.HasMoreTokens();
		val = txtT.GetNextToken()
	)
	{
		if ( val == uk )
			r |= REGION_UK;
		else if ( val == us )
			r |= REGION_US;
		else if ( val == aus )
			r |= REGION_AUS;
		else if ( val == de )
			r |= REGION_DE;
		else if ( val == jp )
			r |= REGION_JP;
	}
	return r;
}
Text G::CheckRegion( ui32 region )
{
	Text txt;
	const wxChar comma = wxT(',');
	if ( region & REGION_UK )
		txt += comma + wxT("UK");
	if ( region & REGION_US )
		txt += comma + wxT("US");
	if ( region & REGION_AUS )
		txt += comma + wxT("AUS");
	if ( region & REGION_DE )
		txt += comma + wxT("DE");
	if ( region & REGION_JP )
		txt += comma + wxT("JP");
	return txt.Right( txt.Length() - 2 );
}
