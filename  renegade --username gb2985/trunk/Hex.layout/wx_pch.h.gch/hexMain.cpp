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
	if (appWaitB > 0) {
		appWait = wxGetLocalTimeMillis();
		if (appWait >= appWaitU) {
			setApps();
		} event.RequestMore(true);
	}
}
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
wxTreeItemId hexWin::treeHackRoot(void) { return treeHack->GetRootItem(); }
wxTreeItemId hexWin::treeHackRoot(wxTreeItemId i) {
	if (i) { return treeHack->GetItemParent(i); }
	else { return treeHack->GetRootItem(); }
}
wxTreeItemId hexWin::treeHackAdd(const wxTreeItemId r, const wxString l, int where, wxTreeItemId i, wxTreeItemData* d) {
	wxTreeItemId p, c;
	switch (where) {
	case 0: c = treeHack->PrependItem(r, l, -1, -1, d); break;
	case 1:
		if (i) {
			p = treeHack->GetPrevSibling(i);
			if (!p) {
				c = treeHack->PrependItem(r, l, -1, -1, d);
				break;
			} i = p;
		}
	case 2:
		if (i) {
			c = treeHack->InsertItem(r, i, l, -1, -1, d);
			break;
		}
	default:
		c = treeHack->AppendItem(r, l, -1, -1, d);
	} treeHack->Expand(r); treeHack->SelectItem(c);
	return c;
}
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId r, wxString l, int where) {
	wxTreeItemId i; wxTreeItemData* d = NULL;
	return treeHackAdd(r, l, where, i, d);
}
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId r, wxString l, int where, wxTreeItemData* d) {
	wxTreeItemId i;
	return treeHackAdd(r, l, where, i, d);
}
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId r, wxString l, int where, wxTreeItemId i) {
	wxTreeItemData* d = NULL;
	return treeHackAdd(r, l, where, i, d);
}
void hexWin::bAddHackOnClick(wxCommandEvent& event) {
	wxTreeItemId i = treeHack->GetSelection(), p, r;
	wxTreeItemData* d = NULL;
	wxString s; r = treeHackRoot(i); int w = cbAddHack->GetSelection();
	if (cAddHack->GetValue() == false) {
		s.Printf(wxT("New Hack %i"), treeHack->GetChildrenCount(r, false)+1);
		treeHackAdd(r, s, w, i, d);
	} else {
		s.Printf(wxT("New Hack %i"), treeHack->GetChildrenCount(i, false)+1);
		treeHackAdd(i, s, w);
	}
}
void hexWin::treeHackDel(void) {
	wxTreeItemId i = treeHack->GetSelection();
	if (i) { treeHack->Delete(i); }
}
wxTreeItemId hexWin::treeHackFind(wxTreeItemId r, wxString l) {
	wxTreeItemId i, c; wxTreeItemIdValue v;
	c = treeHack->GetFirstChild(i, v);
	while (c) {
		if (treeHack->GetItemText(c) == l) {
			return c;
		} c = treeHack->GetNextChild(c, v);
	} return i;
}
void hexWin::treeHackMove(int direction) {
	wxTreeItemId c, i = treeHack->GetSelection(), p, r;
	if (i != treeHackRoot()) {
		wxTreeItemData* d = treeHack->GetItemData(i);
		wxString s = treeHack->GetItemText(i), s2;
		int w = cbAddHack->GetSelection(), t;
		r = treeHackRoot(i); p = treeHackRoot(r);
		treeHackDel();
		switch (direction) {
		case 1:
			c = treeHack->GetNextSibling(i);
			if (c) { treeHackAdd(r, s, 2, c, d); }
			else { treeHackAdd(r, s, 3, d); }
			break;
		case 2: treeHackAdd(p, s, w, d); break;
		case 3:
			t = treeHack->GetChildrenCount(r, false);
			s2.Printf(wxT("New Hack %i"), t);
			c = treeHackFind(r, s2);
			while (c) {
				t++;
				s2.Printf(wxT("New Hack %i"), t);
				c = treeHackFind(r, s2);
			} r = treeHackAdd(r, s2, w);
			treeHackAdd(r, s, 3, d);
			break;
		default:
			c = treeHack->GetPrevSibling(i);
			if (c) { treeHackAdd(r, s, 1, c, d); }
			else { treeHackAdd(r, s, 0, d); }
		}
	}
}
void hexWin::bDelHackOnClick(wxCommandEvent& event) { treeHackDel(); }
void hexWin::treeHackOnKeyDown(wxKeyEvent& event) {
	switch (event.GetKeyCode()) {
	case WXK_DELETE: treeHackDel(); break;
	case WXK_UP:
		if (event.ControlDown()) {
			treeHackMove(0);
		} break;
	case WXK_DOWN:
		if (event.ControlDown()) {
			treeHackMove(1);
		} break;
	case WXK_LEFT:
		if (event.ControlDown()) {
			treeHackMove(2);
		} break;
	case WXK_RIGHT:
		if (event.ControlDown()) {
			treeHackMove(3);
		} break;
	}
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
