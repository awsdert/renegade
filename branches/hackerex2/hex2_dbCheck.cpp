#include "hex2_G.h"
bool G::CheckDirs( hexDB& db, Text& path, Text& leaf )
{
	TxtA dirA;
	const Text orgFN = wxT("org");
	const Text pfmFN = db.org.fileOld;
	const Text binFN = db.pfm.fileOld;
	const Text hckFN = db.pfl.fileOld;
	switch ( db.tmpMode )
	{
		case HEX_LIST_SESSION:
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
			leaf = db.bin.fileOld;
			break;
		case HEX_LIST_FORMAT:
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
		path += xsDirSep + dirA[ i ];
		b = wxDirExists( path );
		b = b ? b : wxMkdir( path );
		if ( !b ) return false;
	}
	return true;
}
bool G::CheckFilesT( hexDB& db, Text& path, Text& leaf, Text& ext, Text& subP )
{
// TODO(awsdert) Refine G::CheckPaths();
	path = m_bCwd ? wxGetCwd() + xsDirUp : wxGetDataDir();
	if ( !CheckDirs( db, path, leaf ) )
		return false;
	Text txt;
	switch ( db.tmpMode )
	{
		case HEX_LIST_SESSION:
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
		case HEX_LIST_FORMAT:
		case HEX_LIST_HACK:
		case HEX_LIST_CODE:
		{
			ext  = wxT( ".hexf" );
			subP = path + xsDirSep + db.bin.fileOld;
			Text oldE = wxT( ".hexcl" );
			Text oldP = path + xsDirSep + leaf + oldE;
			Text hckP = subP + xsDirSep + leaf;
			Text nowP = hckP + xsDirSep + leaf + oldE;
			if ( !wxDirExists( subP ) )
				wxMkdir( subP );
			path = subP;
			subP = hckP;
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
				temp.AddLine( wxT("HEX1=HEXCL"), wxTextFileType_Dos );
				temp.Write( wxTextFileType_Dos );
				temp.Close();
			}
			db.format.name		= getFormatName( HL_HEX1 );
			db.format.format	= HL_HEX1;
			db.format.fileOld	= wxT("hexcl");
			db.format.fileNow	= wxT("hexcl");
			break;
		}
	}
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
	int i, iEnd = 5;
	Text txt[ iEnd ];
	ui32 bit[ iEnd ];
	txt[0] = wxT("UK");  bit[0] = REGION_UK;
	txt[1] = wxT("US");  bit[1] = REGION_US;
	txt[2] = wxT("AUS"); bit[2] = REGION_AUS;
	txt[3] = wxT("DE");  bit[3] = REGION_DE;
	txt[4] = wxT("JP");  bit[4] = REGION_JP;
	for
	(
		val = txtT.GetNextToken();
		txtT.HasMoreTokens();
		val = txtT.GetNextToken()
	)
	{
		for ( i = 0; i < iEnd; ++i )
		{
			if ( val == txt[i] )
				r |= bit[i];
		}
	}
	return r;
}
Text G::CheckRegion( ui32 region )
{
	Text text;
	int i, iEnd = 5;
	Text txt[ iEnd ];
	ui32 bit[ iEnd ];
	const wxChar comma = wxT(',');
	txt[0] = wxT("UK");  bit[0] = REGION_UK;
	txt[1] = wxT("US");  bit[1] = REGION_US;
	txt[2] = wxT("AUS"); bit[2] = REGION_AUS;
	txt[3] = wxT("DE");  bit[3] = REGION_DE;
	txt[4] = wxT("JP");  bit[4] = REGION_JP;
	for ( i = 0; i < iEnd; ++i )
	{
		if ( region & bit[i] )
			text += comma + txt[i];
	}
	return text.Right( text.Length() - 2 );
}
