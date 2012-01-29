/***************************************************************
 * Name:      hexMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-01-11
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <string.h>
#include <wx/string.h>
#include <wx/dynarray.h>
#include <wx/arrimpl.cpp>

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
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
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}
hexWin::hexWin(wxFrame *frame) : HEXFRM(frame) {
#if wxUSE_STATUSBAR
    SB->SetStatusText(_("Hacker Tool"), 0);
    SB->SetStatusText(wxbuildinfo(long_f), 1);
#endif
#if WXDEBUG
	myExe << wxT("hex_dbg.exe");
#else
	myExe << wxT("hex.exe");
#endif
	dbFile.Add(wxT("UNKOWN"), HPFL);
	osName.Add(wxT("UNKOWN"), HPFL);
	dbFile[PC32] = wxT("pc32");
	osName[PC32] = wxT("PC 32bit");
	dbFile[PC64] = wxT("pc64");
	osName[PC64] = wxT("PC 64bit");
	dbFile[PS1] = wxT("sony_ps1");
	osName[PS1] = wxT("Sony PS1");
	dbFile[PS2] = wxT("sony_ps2");
	osName[PS2] = wxT("Sony PS2");
	dbFile[N64] = wxT("nintendo_64");
	osName[N64] = wxT("Nintendo 64");
	dbFile[NGB] = wxT("nintendo_gb");
	osName[NGB] = wxT("Nintendo GameBoy");
	dbFile[NDS] = wxT("nintendo_ds");
	osName[NDS] = wxT("Nintendo DS / DSi / 3DS");
	dbFile[NWII] = wxT("nintendo_wii");
	osName[NWII] = wxT("Nintendo Wii");
	pfName = new wxArrayString[HPFL];
	pfName[PS2].Add(wxT("PCSX2 0.9.7+"));
	int i;
	for (i = 0;i < HPFL;i++) { cbGroup->Append(osName[i]); }
	dl = 0;// rdi = dbList->GetRootItem();
	appLen = -1;
	appWait = 0; appWaitU = 0;
	appWaitB = 0;
}
hexWin::~hexWin() {}
void hexWin::setApps(void) {
	int i = gApp->GetNumberRows();
	if (i > -1) {
		gApp->DeleteRows(0, i, false);
	} appLen = -1;
	appWaitU = wxGetLocalTimeMillis() + appWaitB;
#ifdef WIN32
	EnumWindows(appList3, NULL);
#endif
}
void hexWin::afHook(void) { DBLoad(); }
void hexWin::afHookBClick(wxCommandEvent& event) { afHook(); }
void hexWin::setWait(int i) { appWait = i; }
int hexWin::getAppLen(void) { return appLen; }
void hexWin::bAppListOnClick(wxCommandEvent& event) { setApps(); }
void hexWin::bAppUseOnClick(wxCommandEvent& event) {
	wxArrayInt a = gApp->GetSelectedRows();
	wxString s;
	if (a.GetCount() > 0) {
		s = gApp->GetCellValue(a[0], 0);
		tApp->SetValue(s);
	}
}
void hexWin::bAddHackOnClick(wxCommandEvent& event) {
	wxTreeItemId i = treeHack->GetSelection(), p, r; HACK* d = new HACK;
	wxString s; r = treeHackRoot(i); int w = cbAddHack->GetSelection();
	if (cAddHack->GetValue() == false) {
		s.Printf(wxT("New Hack %i"), treeHackCount(r));
		treeHackAdd(r, s, w, i, d);
	} else {
		s.Printf(wxT("New Hack %i"), treeHackCount(i));
		treeHackAdd(i, s, w);
	} treeHackChange();
}
void hexWin::bDelHackOnClick(wxCommandEvent& event) { treeHackDel(); }
int HACK::GetLen() { return (int)length; }
void HACK::SetLen(int l) {
	/*wxString s; s.Printf(wxT("%i"), (unsigned int)l);
	wxMessageBox(s);//*/
	length = (unsigned int)l;
}
DWORD32 hexWin::getHEX(wxString s) {
	long unsigned int v;
	s = (!s) ? wxT("00000000") : s;
	s.ToULong(&v, 16);
	return (unsigned int)v;
}
void hexWin::groupOnBlur(wxFocusEvent& event) {
	unsigned int i = cbGroup->GetSelection(), j;
	cbApp->Clear();
	for (j = 0;j < pfName[i].GetCount();j++) {
		cbApp->Append(pfName[i][j]);
	}
}
void hexWin::groupOnClick(wxCommandEvent& event) {}
void hexWin::bHackCAddOnClick(wxCommandEvent& event) {
	ti = treeHack->GetSelection();
	wxString s; HACK* d = (HACK*)treeHack->GetItemData(ti);
	unsigned int t0, t1, t2; bool t3 = cHackR->GetValue(); int l = d->GetLen();
	DWORD32 cp0 = getHEX(tHackA->GetValue()), cp1 = 0x00000000,
		cp2 = getHEX(tHackV->GetValue()), cp3 = 0x00000000, cp4 = 0x00000000,
		cp5 = 0x00000000, cp6 = 0x00000000;
	t0 = mHackRAM->GetSelection();
	t1 = mHackType->GetSelection();
	t2 = mHackV->GetSelection();
	// Comments within these if statements indicate max lines per code (excludes List code)
	if (cp0 > 0x01FFFFFF || (t0 > 0 && cp0 > 0x0001FFFF)) {
		// E0EXXX00 YYYYYYYY TTTTTTTT 00000000 VVVVVVVV IIIIIIII
		cp1 = 0xE0E00000 + (t0 * 0x00010000);
		cp5 = cp3; cp3 = cp0;
		cp6 = cp4; cp4 = 0x00000000;
		cp1 += t1 * 0x00002000;
		cp1 += t2 * 0x00000400;
		if (t3) { cp1 += 0x00000200; }
	} else {
		if (t0 > 0) {
			// EXXXTTTT YYYYYYYY VVVVVVVV IIIIIIII
			cp1 = 0xE0000000 + (t0 * 0x01000000) + cp0;
			cp1 += t1 * 0x00200000;
			cp1 += t1 * 0x00040000;
			if (t3) { cp1 += 0x00020000; }
		} else {
			// XXTTTTTT YYYYYYYY VVVVVVVV IIIIIIII
			cp1 += t1 * 0x20000000;
			cp1 += t2 * 0x04000000;
			if (t3) { cp1 += 0x02000000; }
		}
	} gCodelist->AppendRows(1);
	s.Printf(wxT("%08X"), cp1);
	d->cPart1.Add(s);
	gCodelist->SetCellValue(l, 0, s);
	s.Printf(wxT("%08X"), cp2);
	d->cPart2.Add(s);
	gCodelist->SetCellValue(l, 1, s);
	l++; d->SetLen(l);
	if (cp3 > 0x00000000) {
		gCodelist->AppendRows(1);
		s.Printf(wxT("%08X"), cp3);
		gCodelist->SetCellValue(l, 0, s);
		s.Printf(wxT("%08X"), cp4);
		gCodelist->SetCellValue(l, 0, s);
		l++; d->SetLen(l);
	} treeHack->SetItemData(ti, d);
}
void hexWin::bHackCDelOnClick(wxCommandEvent& event) {}
void hexWin::mWaitOnChange(wxCommandEvent& event) {
	int i, sec = 1000, min = 60000;
	switch (mWait->GetSelection()) {
	case 1: i = 500; break;
	case 2: i = sec; break;
	case 3: i = sec * 5; break;
	case 4: i = sec * 30; break;
	case 5: i = min; break;
	case 6: i = min * 5; break;
	case 7: i = min * 30; break;
	case 8: i = 360000; break;
	default: i = 0; } appWaitB = i;
}
void hexWin::addApp(int row, wxString id, wxString app, wxString title) {
	int i = row; appLen = i;
	if (i > -1) {
		gApp->AppendRows(1);
		gApp->SetCellValue(i, 0, app);
		gApp->SetCellValue(i, 1, title);
		gApp->SetRowLabelValue(i, id);
		gApp->AutoSizeColumns(50);
	}
}
void hexWin::HEXFORMCLOSE(wxCloseEvent& event) { Destroy(); }
void hexWin::HEXFORMIDLE(wxIdleEvent& event) {
	if (appWaitB > 0) {
		appWait = wxGetLocalTimeMillis();
		if (appWait >= appWaitU) {
			setApps();
		} event.RequestMore(true);
	}
}
