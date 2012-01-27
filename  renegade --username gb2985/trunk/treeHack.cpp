/***************************************************************
 * Name:      treeHack.cpp
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
void hexWin::treeHackChange(void) {
	ti = treeHack->GetSelection();
	if (ti != pti) {
		pti = ti;
		HACK* td = (HACK*)treeHack->GetItemData(ti);
		int i, l = td->GetLen(); wxString s;
		gCodelist->DeleteRows(0, gCodelist->GetRows(), true);
		for (i = 0;i < l;i++) {
			gCodelist->AppendRows(1, false);
			gCodelist->SetCellValue(i, 0, td->cPart1[i]);
			gCodelist->SetCellValue(i, 1, td->cPart2[i]);
		}
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
	treeHackChange();
}
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
void hexWin::treeHackOnChangeSelT(wxTreeEvent& event) { treeHackChange(); }
void hexWin::treeHackOnChangeSelM(wxMouseEvent& event) { treeHackChange(); }
void hexWin::treeHackOnChangeSel(wxCommandEvent& event) { treeHackChange(); }
