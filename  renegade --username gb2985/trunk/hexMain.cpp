/***************************************************************
 * Name:      hexMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <string.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>
enum wxbuildinfoformat {
    short_f, long_f };

xStr wxbuildinfo(wxbuildinfoformat format) {
	xStr wxbuild(wxVERSION_STRING);
	if (format == long_f ) {
#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
		wxbuild << _T("-Mac");
#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
#endif
#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
#else
		wxbuild << _T("-ANSI build");
#endif
	} return wxbuild;
}
ME::ME(wxFrame *frame) : HEXFRM(frame) {
	xAStr HSTR; // Hook Time Label List
	hexPath = wxGetCwd();
	hexSlash = ( hexPath.Contains( wxT("\\") ) ) ? wxT("\\") : wxT("/");
	dumpPath = hexPath + hexSlash + wxT("ram");
	if ( !dir.Exists( dumpPath ) )
	{
		wxMkdir( dumpPath );
	}
	bytePath = dumpPath + hexSlash + wxT("byte%02i.bin");
	dumpPath << hexSlash + wxT("dump%02i.bin");
    SB->SetStatusText( wxT("Hacker Tool") );
    SB->SetStatusText( wxbuildinfo( long_f ), 1 );
	HDT.Add(0); HSTR.Add(wxT("Never"));
	HDT.Add(500); HSTR.Add(wxT("Every 500 Miliseconds"));
	HDT.Add(1000); HSTR.Add(wxT("Every Second"));
	HDT.Add(5000); HSTR.Add(wxT("Every 5 Seconds"));
	HDT.Add(30000); HSTR.Add(wxT("Every 30 Seconds"));
	HDT.Add(60000); HSTR.Add(wxT("Every Minute"));
	HDT.Add(300000); HSTR.Add(wxT("Every 5 Minutes"));
	HDT.Add(1800000); HSTR.Add(wxT("Every 30 Minutes"));
	HDT.Add(3600000); HSTR.Add(wxT("Every Hour"));
	// Fill different Choice Menus with choices
	APPCheck->Append( HSTR );
	EUD->Append( HSTR );
	APPCheck->SetSelection(0);
	EUD->SetSelection(0);
	readSize = getReadSize();
	//readSize = 0x20000000;
	PLATFORM_SIZE.Add(4, HPFL);
	addPlatform( wxT("PC 32bit"), wxT("pc32") );
	addPlatform( wxT("PC 64bit"), wxT("pc64") );
	addPlatform( wxT("Sony PS1"), wxT("sony_ps1") );
	addPlatform( wxT("Sony PS2"), wxT("sony_ps2") );
	addPlatform( wxT("Nintendo 64"), wxT("nintendo_64") );
	addPlatform( wxT("Nintendo GameBoy"), wxT("nintendo_gb") );
	addPlatform( wxT("Nintendo DS / DSi / 3DS"), wxT("nintendo_ds") );
	addPlatform( wxT("Nintendo Wii"), wxT("nintendo_wii") );
	PLATFORM_SIZE[PC64] = 8;
	// Fill Platform Choice menu with choices
	group_D->SetSelection( 0 );
	PFLoad();
	dl = 0; appLen = -1; endian = 0;
	// Time based variables
	AW = 0; AWU = 0; AWB = 0; // Capture Windows variables
	HW = 0; HWU = 0; HWB = 0; // Hack variables
	EW = 0; EWU = 0; EWB = 0; // Update Memory Editor variables
	// Hack Tree
	HTJ = 0; // New Hack Item's ID (incremented after use, reset when loading file
	// HTFT = true; // Hack Tree is being used for first time
	rdi = DBRoot(); rti = HTRoot();
	// Set default profile list
	// Buffers are clear
	oldSearchNo = -1; oldLength = 0;
	// Find Tab
	TMU.SetCount(TMU_LENGTH);
	TMU[TMU_DUMP] = wxT( "Dump" );
	TMU[TMU_EQUAL] = wxT("Equal to ( = )");
	TMU[TMU_NOTE] = wxT("Not Equal to ( != )");
	TMU[TMU_GT] = wxT("More than ( > )");
	TMU[TMU_GTE] = wxT("More than or Equal to ( >= )");
	TMU[TMU_LT] = wxT("Less than ( < )");
	TMU[TMU_LTE] = wxT("Less than or Equal to ( <= )");
	// Ready Menu
	searchType_D->Clear();
	searchType_D->Append( TMU );
	searchType_D->Select(0);
} ME::~ME() {}
s32 ME::addPlatform( xStr title, xStr file, u32 endian )
{
	PLATFORM* pf = new PLATFORM;
	pf->file = file;
	pf->endian = endian;
	return group_D->Append( title, pf );
}
s32 ME::getAppLen( void ) { return appLen; }
void ME::StartLog( void )
{
	const xStr hexLogPath = hexPath + hexSlash + wxT("hex.log");
	if ( !checkFile.Exists( hexLogPath ) )
	{
		checkFile.Create( hexLogPath );
		checkFile.Close();
	}
	logFile.Open( hexLogPath );
}
void ME::Log( xStr text, xStr title )
{
	title = ( title.length() > 0 ) ? wxT("=== ") + title + wxT(" ===\n") : wxT("");
	logFile.AddLine( title + text, wxTextFileType_Dos );
}
void ME::EndLog( void )
{
	logFile.Write(wxTextFileType_Dos);
	logFile.Close();
}
void ME::ClearGrid(wxGrid*& grid) {
	s32 l = grid->GetNumberRows();
	if (l > 0) { grid->DeleteRows(0, l, false); }
}
void ME::ClearGridCols(wxGrid*& grid) {
	s32 l = grid->GetNumberCols();
	if (l > 0) { grid->DeleteCols(0, l, false); }
}
void ME::addApp(s32 row, xStr id, xStr app, xStr title) {
	s32 i = row; appLen = i;
	if (i > -1) {
		APPG->AppendRows(1);
		APPG->SetCellValue(i, 0, app);
		APPG->SetCellValue(i, 1, title);
		APPG->SetRowLabelValue(i, id);
		APPG->SetColMinimalAcceptableWidth(100);
		APPG->AutoSizeColumns(false);
	}
}
HANDLE ME::GAP( void )
{
	return getAppId( appName_TXT->GetValue() );
}
// Get RAM Data
xStr ME::GARAM(s32 r, s32 c) { return RAMG->GetCellValue(r, c); }
bool ME::GART(s32 r) { return (bool)getHEX(GARAM(r, 1)); } // Is RAM Address Fixed?
u64 ME::GARS(s32 r) { return getHEX(GARAM(r, 2)); } // Get RAM Start
u32 ME::GARM(s32 r)
{
	u64 value = getHEX( GARAM( r, 3 ) );
	if ( value == 0u )
	{
		HANDLE appHandle = getAppId( appName_TXT->GetValue() );
		value = getAppSize( appHandle ) - getHEX( GARAM( r, 2 ) );
	}
	return value;
}
