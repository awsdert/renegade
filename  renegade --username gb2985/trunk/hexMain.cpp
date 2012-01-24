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
HACK::HACK() : wxTreeItemData() { length = 0; }
HACK::HACK(wxTreeItemData*) : wxTreeItemData() {}
HACK::~HACK() {
	length = 0;
	cPart1.Empty();
	cPart2.Empty();
} //HACK* Hack() { return new HACK(); }
hexWin::hexWin(wxFrame *frame) : HEXFRM(frame) {
#if wxUSE_STATUSBAR
    SB->SetStatusText(_("Hacker Tool"), 0);
    SB->SetStatusText(wxbuildinfo(long_f), 1);
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
wxTreeItemId hexWin::treeHackRoot(wxTreeItemId& i) {
	if (i) { return treeHack->GetItemParent(i); }
	else { return treeHack->GetRootItem(); }
}
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId& r, wxString l, int where,
	wxTreeItemId& i, HACK d) { return treeHackAdd(r, l, where, i, &d); }
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK* d) {
	wxTreeItemId c;
	switch (where) {
	case 0: c = treeHack->PrependItem(r, l, -1, -1, d); break;
	case 1:
		if (!!i) {
			i = treeHack->GetPrevSibling(i);
			if (!i) {
				c = treeHack->PrependItem(r, l, -1, -1, d);
				break;
			}
		}
	case 2:
		if (!!i) {
			c = treeHack->InsertItem(r, i, l, -1, -1, d);
			break;
		}
	default:
		c = treeHack->AppendItem(r, l, -1, -1, d);
	} treeHack->Expand(r); treeHack->SelectItem(c);
	return c;
}
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId& r, wxString l, int where,
	wxTreeItemId& i) { HACK* d = new HACK; return treeHackAdd(r, l, where, i, d); }
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId& r, wxString l, int where,
	HACK d) { wxTreeItemId i; return treeHackAdd(r, l, where, i, d); }
wxTreeItemId hexWin::treeHackAdd(wxTreeItemId& r, wxString l, int where) {
	wxTreeItemId i; HACK* d = new HACK; return treeHackAdd(r, l, where, i, d); }
void hexWin::bAddHackOnClick(wxCommandEvent& event) {
	wxTreeItemId i = treeHack->GetSelection(), p, r; HACK* d = new HACK;
	wxString s; r = treeHackRoot(i); int w = cbAddHack->GetSelection();
	if (cAddHack->GetValue() == false) {
		s.Printf(wxT("New Hack %i"), treeHackCount(r));
		treeHackAdd(r, s, w, i, d);
	} else {
		s.Printf(wxT("New Hack %i"), treeHackCount(i));
		treeHackAdd(i, s, w);
	}
}
void hexWin::treeHackDel(void) { treeHackDel(treeHack->GetSelection()); }
void hexWin::treeHackDel(wxTreeItemId i) {	if (i) { treeHack->Delete(i); } }
wxTreeItemId hexWin::treeHackFind(wxTreeItemId& r, wxString l) {
	wxTreeItemId i, c; wxTreeItemIdValue v;
	c = treeHack->GetFirstChild(r, v);
	while (c) {
		if (treeHack->GetItemText(c) == l) {
			return c;
		} c = treeHack->GetNextChild(r, v);
	} return i;
}
int hexWin::treeHackCount(wxTreeItemId& r)
	{ return treeHack->GetChildrenCount(r, false); }
void hexWin::treeHackMove(wxTreeItemId& r, wxTreeItemId& nr) {
	wxTreeItemId c, nc; wxTreeItemIdValue v;
	while (treeHackCount(r) > 0) {
		c = treeHack->GetFirstChild(r, v);
		nc = treeHackAdd(nr, treeHack->GetItemText(c), 3, (HACK*)treeHack->GetItemData(c));
		treeHackMove(c, nc);
	} treeHackDel(r);
}
void hexWin::treeHackMove(int direction) {
	wxTreeItemId c, i = treeHack->GetSelection(), ni, p, r;
	if (i == treeHackRoot()) { return; }
	HACK* d = (HACK*)treeHack->GetItemData(i);
	wxString s = treeHack->GetItemText(i), s2;
	int w = cbAddHack->GetSelection(), t;
	r = treeHackRoot(i); p = treeHackRoot(r);
	switch (direction) {
	case 1:
		c = treeHack->GetNextSibling(i);
		if (c) { ni = treeHackAdd(r, s, 2, c, d); }
		else { ni = treeHackAdd(r, s, 3, d); }
		break;
	case 2:
		if (r == treeHackRoot()) { p = r; }
		ni = treeHackAdd(p, s, w, d);
		break;
	case 3:
		t = treeHackCount(r);
		do {
			s2.Printf(wxT("New Hack %i"), t);
			c = treeHackFind(r, s2); t++;
		} while (!c == false);
		r = treeHackAdd(r, s2, w);
		ni = treeHackAdd(r, s, 3, d);
		break;
	default:
		c = treeHack->GetPrevSibling(i);
		if (c) { ni = treeHackAdd(r, s, 1, c, d); }
		else { ni = treeHackAdd(r, s, 0, d); }
	} treeHackMove(i, ni);
	treeHack->SelectItem(ni);
}
void hexWin::bDelHackOnClick(wxCommandEvent& event) { treeHackDel(); }
void hexWin::treeHackOnKeyDown(wxKeyEvent& event) {
	wxTreeItemId r, i = treeHack->GetSelection();
	wxTreeItemIdValue v; wxString s;
	int kc = event.GetKeyCode();
	if (event.ControlDown()) {
		switch (kc) {
		case WXK_SPACE: cHackUse->SetValue(!cHackUse->GetValue()); break;
		case WXK_EXECUTE: case WXK_ADD: case WXK_NUMPAD_ADD:
			r = treeHackRoot(i);
			s.Printf(wxT("New Hack %i"), treeHackCount(r));
			treeHackAdd(r, s, cbAddHack->GetSelection(), i);
		break;
		case WXK_DELETE: case WXK_SUBTRACT: case WXK_NUMPAD_SUBTRACT:
			treeHackDel(i); break;
		case WXK_UP: treeHackMove(0); break;
		case WXK_DOWN: treeHackMove(1); break;
		case WXK_LEFT: treeHackMove(2); break;
		case WXK_RIGHT: treeHackMove(3); break;
		default: break; }
	} else {
		switch (kc) {
		case WXK_SPACE: cHackUse->SetValue(!cHackUse->GetValue()); break;
		case WXK_UP:
			r = treeHack->GetPrevSibling(i);
			if (!r) { r = treeHackRoot(i); }
			if (r) { treeHack->SelectItem(r); }
		break;
		case WXK_DOWN:
			r = treeHack->GetNextSibling(i);
			if (!r) { r = treeHack->GetFirstChild(i, v); }
			if (r) { treeHack->SelectItem(r); }
		break;
		case WXK_LEFT:
			r = treeHackRoot(i);
			if (r) { treeHack->SelectItem(r); }
		break;
		case WXK_RIGHT:
			r = treeHack->GetFirstChild(i, v);
			if (r) { treeHack->SelectItem(r); }
		break;
		default: break; }
	}
}
int HACK::GetLen() { return length; }
void HACK::SetLen(int l) { length = l; }
DWORD32 hexWin::getHEX(wxString s) {
	long unsigned int v;
	s = (!s) ? wxT("00000000") : s;
	s.ToULong(&v, 16);
	return (unsigned int)v;
}
void hexWin::bHackCAddOnClick(wxCommandEvent& event) {
	wxTreeItemId ti = treeHack->GetSelection();
	wxString s; HACK* d = (HACK*)treeHack->GetItemData(ti);
	unsigned int t; int l = d->GetLen();
	DWORD32 cp1 = getHEX(tHackA->GetValue()), cp2 = getHEX(tHackV->GetValue()),
		cp3 = 0x00000000, cp4 = 0x00000000;
	t = mHackType->GetSelection(); cp1 += t * 0x20000000;
	t = mHackV->GetSelection(); cp1 += t * 0x04000000;
	if (cHackR->GetValue()) { cp1 += 0x02000000; }
	gCodelist->AppendRows(1);
	s.Printf(wxT("%08X"), cp1);
	gCodelist->SetCellValue(l, 0, s);
	s.Printf(wxT("%08X"), cp2);
	gCodelist->SetCellValue(l, 1, s);
	l++; d->SetLen(l);
	if (cp3 > 0x00000000) {
		gCodelist->AppendRows(1);
		s.Printf(wxT("%08X"), cp3);
		gCodelist->SetCellValue(l, 0, s);
		s.Printf(wxT("%08X"), cp4);
		gCodelist->SetCellValue(l, 0, s);
		l++; d->SetLen(l);
	}
}
void hexWin::bHackCDelOnClick(wxCommandEvent& event) {

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
