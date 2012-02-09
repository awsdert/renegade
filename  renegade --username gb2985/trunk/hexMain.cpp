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
	int i;
    SB->SetStatusText(_("Hacker Tool"), 0);
    SB->SetStatusText(wxbuildinfo(long_f), 1);
	HDT.Add(0); HSTR.Add(wxT("Never"));
	HDT.Add(500); HSTR.Add(wxT("Every 500 Miliseconds"));
	HDT.Add(1000); HSTR.Add(wxT("Every Second"));
	HDT.Add(5000); HSTR.Add(wxT("Every 5 Seconds"));
	HDT.Add(30000); HSTR.Add(wxT("Every 30 Seconds"));
	HDT.Add(60000); HSTR.Add(wxT("Every Minute"));
	HDT.Add(300000); HSTR.Add(wxT("Every 5 Minutes"));
	HDT.Add(1800000); HSTR.Add(wxT("Every 30 Minutes"));
	HDT.Add(3600000); HSTR.Add(wxT("Every Hour"));
	HDTL = HDT.GetCount();
	for (i = 0;i < HDTL;i++) {
		HKWD->Append(HSTR[i]);
		EUD->Append(HSTR[i]);
	}
	HKWD->SetSelection(0);
	EUD->SetSelection(0);
	DBFA.Add(wxT("UNKOWN"), HPFL);
	OSNA.Add(wxT("UNKOWN"), HPFL);
	DBFA[PC32] = wxT("pc32");
	OSNA[PC32] = wxT("PC 32bit");
	DBFA[PC64] = wxT("pc64");
	OSNA[PC64] = wxT("PC 64bit");
	DBFA[PS1] = wxT("sony_ps1");
	OSNA[PS1] = wxT("Sony PS1");
	DBFA[PS2] = wxT("sony_ps2");
	OSNA[PS2] = wxT("Sony PS2");
	DBFA[N64] = wxT("nintendo_64");
	OSNA[N64] = wxT("Nintendo 64");
	DBFA[NGB] = wxT("nintendo_gb");
	OSNA[NGB] = wxT("Nintendo GameBoy");
	DBFA[NDS] = wxT("nintendo_ds");
	OSNA[NDS] = wxT("Nintendo DS / DSi / 3DS");
	DBFA[NWII] = wxT("nintendo_wii");
	OSNA[NWII] = wxT("Nintendo Wii");
	for (i = 0;i < HPFL;i++) { cbGroup->Append(OSNA[i]); }
	dl = 0; appLen = -1; endian = 0;
	AW = 0; AWU = 0; AWB = 0;
	HW = 0; HWU = 0; HWB = 0;
	EW = 0; EWU = 0; EWB = 0;
	HTJ = 0; HTFT = true;
	rdi = DBRoot(); rti = HTRoot();
	cbGroup->SetSelection(PS2);
}
ME::~ME() {}
void ME::setApps(void) {
	int i = gApp->GetNumberRows();
	if (i > -1) {
		gApp->DeleteRows(0, i, false);
	} appLen = -1;
	AWU = wxGetLocalTimeMillis() + AWB;
#ifdef WIN32
	EnumWindows(appList3, NULL);
#endif
}
void ME::setWait(int i) { AW = i; }
int ME::getAppLen(void) { return appLen; }
void ME::PFSet(void) {
	xStr d = myDiv, p = wxGetCwd(), s;
	p << d << wxT("pf");
	dir.Open(p);
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s = p << d << DBFA[HDTI] << wxT(".hexpf");
	if (!pff.Open(s)) {
		pff.Create(s);
		pff.Open(s);
	}
}
u32 ME::getHEX(xStr s) {
	long unsigned int v;
	s = (!s) ? wxT("00000000") : s;
	s.ToULong(&v, 16);
	return (unsigned int)v;
}
void ME::addApp(int row, xStr id, xStr app, xStr title) {
	int i = row; appLen = i;
	if (i > -1) {
		gApp->AppendRows(1);
		gApp->SetCellValue(i, 0, app);
		gApp->SetCellValue(i, 1, title);
		gApp->SetRowLabelValue(i, id);
		gApp->AutoSizeColumns(50);
	}
}
HANDLE ME::GAP(void) { return getAppId(tApp->GetValue()); }
u32 ME::GAR(void) { return getHEX(tRAMStart->GetValue()); }
u32 ME::GAR(u8 i) { return getHEX(RAMG->GetCellValue(i, 2)); }
