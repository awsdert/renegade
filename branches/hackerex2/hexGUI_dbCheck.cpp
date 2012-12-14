#include "hexGUI_G.hpp"
bool G::CheckDirs( Text& path, Text& leaf, int inMode )
{
	TxtA dirA;
	const Text orgFN = wxT("org");
	const Text pfmFN = m_org.fileOld;
	const Text binFN = m_pfm.fileOld;
	const Text hckFN = m_pfl.fileOld;
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
		case HEX_LIST_RAM:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			leaf = binFN;
			break;
		case HEX_LIST_PFL:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			dirA.Add( binFN );
			leaf = m_bin.fileOld;
			break;
		case HEX_LIST_HACK:
		case HEX_LIST_CODE:
			dirA.Add( orgFN );
			dirA.Add( pfmFN );
			dirA.Add( binFN );
			leaf = hckFN;
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
bool G::CheckFilesT( Text& path, Text& leaf, Text& subP, int inMode )
{
// FIXME(awsdert) 0: Refine G::CheckPaths();
	if ( inMode < 0 || inMode > HEX_LIST_COUNT )
		return false;
	path = m_ListCwd ? wxGetCwd() + m_sep + wxT("..") : wxGetDataDir();
	if ( !CheckDirs( path, leaf, inMode ) )
		return false;
	Text txt, ext;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
			ext  = wxT( ".ini" );
			break;
		case HEX_LIST_PFM:
			ext  = wxT( ".hexp" );
			break;
		case HEX_LIST_BIN:
		case HEX_LIST_RAM:
			ext  = wxT( ".hexb" );
			break;
		case HEX_LIST_PFL:
			ext  = wxT( ".hexdb" );
			break;
		case HEX_LIST_HACK:
		case HEX_LIST_CODE:
		{
			ext  = wxT( ".hexc" );
			subP = path + m_sep + m_bin.fileOld;
			Text oldE = wxT( ".hexcl" );
			Text oldP = path + m_sep + leaf + oldE;
			Text hckP = subP + m_sep + leaf;
			Text nowP = hckP + m_sep + leaf + oldE;
			if ( !wxDirExists( subP ) )
				wxMkdir( subP );
			if ( !wxDirExists( hckP ) )
				wxMkdir( hckP );
			if ( wxFileExists( oldP ) )
			{
				TxtF temp;
				wxRenameFile( oldP, nowP, true );
				nowP = hckP + ext;
				if ( !wxFileExists( nowP ) )
					temp.Create( nowP );
				temp.Open( nowP );
				temp.Clear();
				temp.Write( wxTextFileType_Dos );
				temp.AddLine( wxT("HL_HEX1=HEXCL"), wxTextFileType_Dos );
				temp.Write( wxTextFileType_Dos );
				temp.Close();
			}
			path = subP;
			subP = hckP;
			break;
		}
	}
	leaf += ext;
	return true;
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
