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
	xAStr HSTR, OSNA; // Hook Time Label List
	hexPath = wxGetCwd();
	hexSlash = ( hexPath.Contains( wxT("\\") ) ) ? wxT("\\") : wxT("/");
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
	APPCheck->Append(HSTR);
	EUD->Append(HSTR);
	APPCheck->SetSelection(0);
	EUD->SetSelection(0);
	DBFA.Add(wxT("UNKOWN"), HPFL);
	OSNA.Add(wxT("UNKOWN"), HPFL);
	PLATFORM_SIZE.Add(4, HPFL);
	DBFA[ PC32 ] = wxT("pc32");
	OSNA[ PC32 ] = wxT("PC 32bit");
	DBFA[ PC64 ] = wxT("pc64");
	OSNA[ PC64 ] = wxT("PC 64bit");
	PLATFORM_SIZE[PC64] = 8;
	DBFA[ PS1 ] = wxT("sony_ps1");
	OSNA[ PS1 ] = wxT("Sony PS1");
	DBFA[ PS2 ] = wxT("sony_ps2");
	OSNA[ PS2 ] = wxT("Sony PS2");
	DBFA[ N64 ] = wxT("nintendo_64");
	OSNA[ N64 ] = wxT("Nintendo 64");
	DBFA[ NGB ] = wxT("nintendo_gb");
	OSNA[ NGB ] = wxT("Nintendo GameBoy");
	DBFA[ NDS ] = wxT("nintendo_ds");
	OSNA[ NDS ] = wxT("Nintendo DS / DSi / 3DS");
	DBFA[ NWII ] = wxT("nintendo_wii");
	OSNA[ NWII ] = wxT("Nintendo Wii");
	// Fill Platform Choice menu with choices
	group_D->Append( OSNA );
	group_D->SetSelection(PS2);
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
	const xStr TMU_VAL1 = _(" Value 1");
	const xStr TMU_VAL2 = _(" Value 2");
	TMU.SetCount(TMU_LENGTH);
	TMU[TMU_DUMP] = _( "Dump" );
	TMU[TMU_EQUAL] = _("Equal To");
	TMU[TMU_NOTE] = _("Not Equal To");
	TMU[TMU_GT] = _("Greater Than");
	TMU[TMU_GTE] = _("Greater Than or Equal To");
	TMU[TMU_LT] = _("Less Than");
	TMU[TMU_LTE] = _("Less Than or Equal To");
	TMU[TMU_VEQUAL] = _("Equal To") + TMU_VAL1;
	TMU[TMU_VNOTE] = _("Not Equal To") + TMU_VAL1;
	TMU[TMU_VGT] = _("Greater Than") + TMU_VAL1;
	TMU[TMU_VGTE] = _("Greater Than or Equal To") + TMU_VAL1;
	TMU[TMU_VLT] = _("Less Than") + TMU_VAL1;
	TMU[TMU_VLTE] = _("Less Than or Equal To") + TMU_VAL1;
	TMU[TMU_INSIDE] = _("Between") + TMU_VAL1 + _(" and") + TMU_VAL2;
	TMU[TMU_OUTSIDE] = _("Not Between") + TMU_VAL1 + _(" and") + TMU_VAL2;
	useTest_D->Clear();
	useTest_D->Append( TMU );
	useTest_D->Select(0);
} ME::~ME() {}
s32 ME::getAppLen(void) { return appLen; }
u64 ME::getHEX(xStr s)
{
	u32 i = 0u;
	u64 value = 0u;
	s = s.Upper();
	wxChar c;
	const wxChar n0 = wxT('0');
	const wxChar n9 = wxT('9');
	const wxChar nA = wxT('A');
	const wxChar nF = wxT('F');
	while ( ( c = s[ i ] ) )
	{
		value <<= 4u;
		if ( c >= n0 && c <= n9 )
		{
			value += ( c - n0 );
		}
		else if ( c >= nA && c <= nF )
		{
			value += ( ( c - nA ) + 10u );
		}
		i++;
	}
	return value;
}
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
void ME::Log(xStr text, xStr title)
{
	logFile.AddLine( text, wxTextFileType_Dos );
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
	return getHEX(GARAM(r, 3));
}
