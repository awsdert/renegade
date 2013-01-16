#include "wx_pch.h"
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
	wxStandardPaths stdPaths;
	path = m_bCwd ? wxGetCwd() : stdPaths.GetUserDataDir();
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
const int  l_regionCount = 5;
TxtA l_regionData;
ui32 l_regions[ l_regionCount ];
bool l_regionsSet = false;
void l_setRegions( void )
{
	TxtA txt;
	txt.SetCount( l_regionCount );
	ui32 bit[ l_regionCount ];
	txt[0] = wxT("UK");  bit[0] = REGION_UK;
	txt[1] = wxT("US");  bit[1] = REGION_US;
	txt[2] = wxT("AUS"); bit[2] = REGION_AUS;
	txt[3] = wxT("DE");  bit[3] = REGION_DE;
	txt[4] = wxT("JP");  bit[4] = REGION_JP;
	l_regionData = txt;
	for ( int i = 0; i < l_regionCount; ++i )
		l_regions[ i ] = bit[ i ];
	l_regionsSet = true;
}
int  G::getRegionCount( void ) { return l_regionCount; }
void G::getRegions( ui32* data )
{
	if ( !l_regionsSet )
		l_setRegions();
	for ( int i = 0; i < l_regionCount; ++i )
		data[ i ] = l_regions[ i ];
}
void G::getRegionData( TxtA& data ) {
	if ( !l_regionsSet )
		l_setRegions();
	data = l_regionData;
}
ui32 G::CheckRegion( Text region )
{
	if ( !l_regionsSet )
		l_setRegions();
	int i;
	region.UpperCase();
	ui32 r = 0u;
	Text comma = wxT(',');
	Text txt;
	if ( region.Contains( comma ) )
	{
		TxtT tzr;
		tzr.SetString( region, comma );
		do
		{
			txt = tzr.GetNextToken();
			for ( i = 0; i < l_regionCount; ++i )
			{
				if ( txt == l_regionData[i] )
					r |= l_regions[i];
			}
		}
		while ( tzr.HasMoreTokens() );
	}
	else
	{
		txt = region;
		for ( i = 0; i < l_regionCount; ++i )
		{
			if ( txt == l_regionData[i] )
				r |= l_regions[i];
		}
	}
	return r;
}
Text G::CheckRegion( ui32 region )
{
	if ( !l_regionsSet )
		l_setRegions();
	Text txt;
	const wxChar comma = wxT(',');
	for ( int i = 0; i < l_regionCount; ++i )
	{
		if ( region & l_regions[i] )
			txt += comma + l_regionData[i];
	}
	return txt.Right( txt.Length() - 2 );
}
