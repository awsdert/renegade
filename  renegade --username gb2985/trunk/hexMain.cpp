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
ME::ME(wxFrame *frame) : HEXFRM(frame) {
    SB->SetStatusText(_("Hacker Tool"), 0);
    SB->SetStatusText(wxbuildinfo(long_f), 1);
/*#if WXDEBUG
	myExe << wxT("hex_dbg.exe");
#else
	myExe << wxT("hex.exe");
#endif*/
	int i;
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
	cbGroup->SetSelection(PS2);
	dl = 0;
	appLen = -1; endian = 0;
	AW = 0; AWU = 0; AWB = 0;
	HW = 0; HWU = 0; HWB = 0;
	EW = 0; EWU = 0; EWB = 0;
	HTJ = 0; HDTI = PS2; HTFT = true;
	rdi = DBRoot(); rti = HTRoot();
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
void ME::HCHookOnClick(wxCommandEvent& event) { HWB = 1000; HCHook(); }
void ME::setWait(int i) { AW = i; }
int ME::getAppLen(void) { return appLen; }
void ME::bAppListOnClick(wxCommandEvent& event) { setApps(); }
void ME::bAppUseOnClick(wxCommandEvent& event) {
	wxArrayInt a = gApp->GetSelectedRows();
	wxString s;
	if (a.GetCount() > 0) {
		s = gApp->GetCellValue(a[0], 0);
		tApp->SetValue(s);
	} DBLoad();
}
void ME::bAddHackOnClick(wxCommandEvent& event) {
	wxTreeItemId i = HT->GetSelection(), p, r; HACK* d = new HACK;
	wxString s; r = HTRoot(i); int w = HTAddD->GetSelection();
	if (HTAddC->GetValue() == false) {
		s.Printf(wxT("New Hack %i"), HTCount(r));
		HTAdd(r, s, w, i, d);
	} else {
		s.Printf(wxT("New Hack %i"), HTCount(i));
		HTAdd(i, s, w);
	} HTChange();
}
void ME::PFSet(void) {
	wxString d = myDiv, p = wxGetCwd(), s;
	p << d << wxT("pf");
	dir.Open(p);
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s = p << d << DBFA[HDTI] << wxT(".hexpf");
	if (!pff.Open(s)) {
		pff.Create(s);
		pff.Open(s);
	}
}
void ME::PFOnChange(wxCommandEvent& event) { HDTI = cbGroup->GetSelection(); }
void ME::bDelHackOnClick(wxCommandEvent& event) { HTDel(ti); }
u32 ME::getHEX(wxString s) {
	long unsigned int v;
	s = (!s) ? wxT("00000000") : s;
	s.ToULong(&v, 16);
	return (unsigned int)v;
}
void ME::groupOnBlur(wxFocusEvent& event) {
	HDTI = cbGroup->GetSelection(); PFSet();
	u8 m = 0, i; APFD->Clear(); PFEA.Clear();
	wxString s, t, x; wxStringTokenizer st;
	for (s = pff.GetFirstLine();!pff.Eof();s = pff.GetNextLine()) {
		switch (m) {
		case 0:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT("[")) == 0) {
				t = s.SubString(1, s.length() - 2);
				APFD->Append(t);
				m = 1;
			} break;
		case 1:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT(";")) == 0) {
				t = s.SubString(1, -1);
				PFEA.Add(t);
				m = 2;
			} break;
		case 2:
			if (i == 0) {
				t = s.SubString(2, -1);
				st.SetString(t, wxT(";"));
				x = st.GetNextToken();
				x = st.GetNextToken();
				tRAMStart->SetValue(x);
				x = st.GetNextToken();
				tRAMSize->SetValue(x);
				i++; m = 1;
			} break;
		}
	} APFD->SetSelection(0);
}
void ME::groupOnClick(wxCommandEvent& event) {}
void ME::mWaitOnChange(wxCommandEvent& event) {
	AWB = HDT[HKWD->GetSelection()];
}
void ME::addApp(int row, wxString id, wxString app, wxString title) {
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
void ME::HEXFORMCLOSE(wxCloseEvent& event) { AWB = 0; HWB = 0; EWB = 0; Destroy(); }
void ME::HEXFORMIDLE(wxIdleEvent& event) {
	bool rm = false;
	if (AWB > 0) {
		AW = wxGetLocalTimeMillis();
		if (AW >= AWU) {
			setApps();
		} rm = true;
	}
	if (HWB > 0) {
		HW = wxGetLocalTimeMillis();
		if (HW >= HWU) { HCHook();
			HWU = wxGetLocalTimeMillis() + HWB;
		} rm = true;
	}
	if (EWB > 0 && EP->IsShownOnScreen()) {
		EW = wxGetLocalTimeMillis();
		if (EW >= EWU) { EA();
			EWU = wxGetLocalTimeMillis() + EWB;
		} rm = true;
	}
	event.RequestMore(rm);
}
