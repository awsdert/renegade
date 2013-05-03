#include "wx_pch.h"
#include "hexG_db.h"
/* *
bool hexDB::m_checkDir( Text& path, Text& leaf )
{
	TxtA dirA;
	const Text orgFN = wxT("org");
	const Text pfmFN = org.fileOld;
	const Text binFN = pfm.fileOld;
	const Text hckFN = pfl.fileOld;
	switch ( tmpMode )
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
			leaf = bin.fileOld;
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
bool hexDB::m_checkFiles( Text& path, Text& leaf, Text& ext, Text& subP )
{
	path = tmpCwd ? cwd : stdPaths.GetUserDataDir();
	if ( !m_checkDir( path, leaf ) )
		return false;
	Text txt;
	switch ( tmpMode )
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
			subP = path + xsDirSep + bin.fileOld;
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
			format.name		= getFormatName( HL_HEX1 );
			format.format	= HL_HEX1;
			format.fileOld	= wxT("hexcl");
			format.fileNow	= wxT("hexcl");
			break;
		}
	}
	return true;
}
/* */