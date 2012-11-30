#include "hexGUI_G.hpp"
bool G::CheckTmpBin( Text& path, int inMode )
{
	if ( inMode < 0 || inMode >= HEX_LIST_COUNT )
		return false;
	bool isCfg = false;
	Text hackPath;
	TxtA dirA;
	int listMode = m_ListNow;
	m_ListNow = inMode;
	if ( !CheckPaths( isCfg, path, hackPath, dirA ) )
		return false;
	m_ListNow = listMode;
	return true;
}
bool G::SaveDatB( void* vDat, ui08 aSize, int inMode )
{
	Size bSize = 0u;
	Text path, text;
	switch ( inMode )
	{
		case HEX_LIST_ORG:
			bSize = sizeof( Org );
			break;
		case HEX_LIST_PFM:
			bSize = sizeof( Pfm );
			break;
		case HEX_LIST_BIN:
			bSize = sizeof( Bin );
			break;
		case HEX_LIST_PFL:
			bSize = sizeof( Pfl );
			break;
		case HEX_LIST_HCK:
			bSize = sizeof( Hack );
			break;
		default: return false;
	}
	if ( !CheckTmpBin( path, inMode ) )
		return false;
	path += wxT(".bin~");
	wxFile file;
	bSize *= aSize;/*
	text.Printf( wxT( "%u" ), aSize );
	if ( wxMessageBox( path, text, wxOK | wxCANCEL ) == wxCANCEL )
		return false;//*/
	if ( !file.Create( path, true ) )
		return false;
	if ( file.Write( vDat, bSize ) != bSize )
		return false;
	return file.Close();
}
