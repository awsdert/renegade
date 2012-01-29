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
HACK::HACK() : wxTreeItemData() { length = 0; }
HACK::HACK(wxTreeItemData*) : wxTreeItemData() { length = 0; }
HACK::~HACK() {
	hid = 0x0000;
	length = 0;
	cPart1.Empty();
	cPart2.Empty();
}
wxTreeItemId hexWin::treeHackRoot(void) { return treeHack->GetRootItem(); }
wxTreeItemId hexWin::treeHackRoot(wxTreeItemId& i) {
	if (i.IsOk()) { i = treeHack->GetItemParent(i); }
	if (!i.IsOk()) { i = treeHack->GetRootItem(); }
	return i;
}
void hexWin::HTSet(void) {
	wxString d = myDiv, p = wxGetCwd(), s;
	DBI* k = (DBI*)dbList->GetItemData(di);
	int afi = cbGroup->GetSelection();
	if (afi < 0) { afi = PS2; }
	p << d << wxT("db");
	dir.Open(p);
	p << d << dbFile[afi];
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	treeFile = p << d << k->afp << wxT(".hexcl");
	s = treeFile;
	if (!ht.Open(s)) {
		ht.Create(s);
		ht.Open(s);
	}
}
wxTreeItemId hexWin::HTFind(WORD j) {
	wxTreeItemId r = treeHackRoot();
	return HTFind(j, r);
}
wxTreeItemId hexWin::HTFind(WORD j, wxTreeItemId& r) {
	wxTreeItemId i, c;
	wxTreeItemIdValue v;
	HACK* d = (HACK*)treeHack->GetItemData(r);
	if (j != d->hid) {
		i = treeHack->GetFirstChild(r, v);
		while (i.IsOk() && !c.IsOk()) {
			c = HTFind(j, i);
			i = treeHack->GetNextChild(r, v);
		}
	} else { c = r; }
	return c;
}
void hexWin::HTLoad(void) {
	wxString s; HTSet();
	WORD k = 0x0000;
	treeHack->DeleteAllItems();
	wxTreeItemId r = treeHackRoot(), i;
	i = treeHackAdd(r, wxT("(m)"), 3);
	r = treeHackRoot(i);
	s = ht.GetFirstLine();
	HTLoad(r, k, s, 0);
}
wxString hexWin::HTLoad(wxTreeItemId& r, WORD j, wxString s, int m) {
	wxTreeItemId i, p; bool u = false;
	wxString s1, s2, s3, t; WORD k = 0x0000, n;
	int l = 0; HACK* d = new HACK;
	while (!ht.Eof()) {
		switch (m) {
		case 1:
			ht1 = s.SubString(0, 3);
			ht2 = s.SubString(4, 7);
			ht3 = s.SubString(9, 12);
			ht4 = s.SubString(13, 16);
			n = (WORD)getHEX(ht2);
			k = (WORD)getHEX(ht4);
			if (k != j) {
				p = HTFind(k);
				u = true;
			} d->hid = n;
			d->SetLen(0);
			treeHack->SetItemData(i, d);
			l = 0; m = 2;
			break;
		case 2:
			s3 = s.SubString(0, 0);
			if (s3.Cmp(wxT('"')) == 0) {
				if (u) { HTLoad(p, k, s, 0); u = false; }
				else {
					t = s.SubString(1, s.length() - 2);
					if (t.Cmp(wxT("(m)")) == 0) { i = treeHackRoot(); }
					else { i = treeHackAdd(r, t, 3); }
					m = 1; d = new HACK;
				}
			} else {
				s1 = s.SubString(0, 7);
				s2 = s.SubString(9, 16);
				d->cPart1.Add(s1);
				d->cPart2.Add(s2);
				l++; d->SetLen(l);
				treeHack->SetItemData(i, d);
			} break;
		default:
			s3 = s.SubString(0, 0);
			if (s3.Cmp(wxT("\"")) == 0) {
				t = s.SubString(1, s.length() - 2);
				if (t.Cmp(wxT("(m)")) == 0) { i = treeHackRoot(); }
				else { i = treeHackAdd(r, t, 3); }
				m = 1; d = new HACK;
			}
		} if (!ht.Eof()) { s = ht.GetNextLine(); }
	} return s;
}
void hexWin::treeHackChange(void) {
	ti = treeHack->GetSelection();
	if (ti != pti) {
		pti = ti;
		HACK* td = (HACK*)treeHack->GetItemData(ti);
		int i, l = td->GetLen(); wxString s;
		gCodelist->DeleteRows(0, gCodelist->GetRows(), false);
		for (i = 0;i < l;i++) {
			gCodelist->AppendRows(1, false);
			gCodelist->SetCellValue(i, 0, td->cPart1[i]);
			gCodelist->SetCellValue(i, 1, td->cPart2[i]);
		}
	}
}
void hexWin::HTSave(void) {
	WORD j = 0x0001, m = 0x0000;
	wxTreeItemId r = treeHackRoot();
	HTSet(); ht.Clear();
	while (r.IsOk()) {
		j = HTSave(r, j, m);
		r = treeHack->GetNextSibling(r);
	} ht.Write(wxTextFileType_Dos); ht.Close();
}
WORD hexWin::HTSave(wxTreeItemId& r, WORD j, WORD l) {
	wxTreeItemId i;
	wxTreeItemIdValue v;
	wxString s; WORD m = j;
	HACK* h = (HACK*)treeHack->GetItemData(r);
	DBI* d = (DBI*)dbList->GetItemData(di); int k;
	s << wxT("\"") << treeHack->GetItemText(r) << wxT("\"");
	ht.AddLine(s, wxTextFileType_Dos); s.Clear();
	s.Printf(wxT("%04X%04X 0000%04X"), d->afi, j, l);
	ht.AddLine(s, wxTextFileType_Dos); s.Clear(); j++;
	for (k = 0;k < (int)h->length;k++) {
		s << h->cPart1[k] << wxT(" ") << h->cPart2[k];
		ht.AddLine(s); s.Clear();
	} i = treeHack->GetFirstChild(r, v);
	while (i.IsOk()) {
		j = HTSave(i, j, m);
		i = treeHack->GetNextChild(r, v);
	} return j;
}
void hexWin::bHTSaveOnClick(wxCommandEvent& event) { HTSave(); }
void hexWin::bHTLoadOnClick(wxCommandEvent& event) { HTLoad(); }
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
