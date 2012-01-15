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
#include "hexM.h"
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
hexWin::hexWin(wxFrame *frame)
    : HEXFRM(frame)
{
#if wxUSE_STATUSBAR
    SB->SetStatusText(_("Hacker Tool"), 0);
    SB->SetStatusText(wxbuildinfo(short_f), 1);
#endif
	gLen = 7; pLen = 1; appLen = -1;
	appWait = 0; appWaitU = 0;
	groups = new wxString [gLen];
	group = new int [pLen];
	preset = new wxString [pLen];
	groups[0] = wxT("Nintendo 64");
	groups[1] = wxT("Nintendo DS / DSi / 3DS");
	groups[2] = wxT("Nintendo Gameboy");
	groups[3] = wxT("Nintendo Wii");
	groups[4] = wxT("PC");
	groups[5] = wxT("Sony Playstation 1");
	groups[6] = wxT("Sony Playstation 2");
	group[0] = 6;
	preset[0] = wxT("PCSX2 0.9.7+");
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
void hexWin::setWait(int i) { appWait = i; }
void hexWin::HEXFORMIDLE(wxIdleEvent& event) {
	appWait = wxGetLocalTimeMillis();
	if (appWaitB > 0 && appWait >= appWaitU) {
		setApps();
	} event.RequestMore(true);
}
int hexWin::getAppLen(void) { return appLen; }
void hexWin::bAppListOnClick(wxCommandEvent& event) { setApps(); }
void hexWin::bAppUseOnClick(wxCommandEvent& event) {
	wxArrayInt a = gApp->GetSelectedRows();
	wxString s;
	if (a.GetCount() > 0) { s = gApp->GetCellValue(a[0], 0); }
	tApp->SetValue(s);
}
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
//#ifdef WIN32
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
//#endif
void hexWin::OnClose(wxCloseEvent &event) { Destroy(); }
void hexWin::OnQuit(wxCommandEvent &event) { Destroy(); }
void hexWin::OnAbout(wxCommandEvent &event) {
	wxString msg = wxbuildinfo(long_f);
	wxMessageBox(msg, _("Welcome to..."));
}
