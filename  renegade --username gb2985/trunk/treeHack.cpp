/***************************************************************
 * Name:      HT.cpp
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
wxTreeItemId hexWin::HTRoot(void) { return HT->GetRootItem(); }
wxTreeItemId hexWin::HTRoot(wxTreeItemId& i) {
	if (i.IsOk()) { i = HT->GetItemParent(i); }
	if (!i.IsOk()) { i = HT->GetRootItem(); }
	return i;
}
void hexWin::HTSet(void) {
	wxString d = myDiv, p = wxGetCwd(), s;
	DBI* k = (DBI*)DB->GetItemData(di);
	int afi = cbGroup->GetSelection();
	if (afi < 0) { afi = PS2; }
	p << d << wxT("db");
	dir.Open(p);
	p << d << dbFile[afi];
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	treeFile = p << d << k->afp << wxT(".hexcl");
	s = treeFile;
	if (!htf.Open(s)) {
		htf.Create(s);
		htf.Open(s);
	}
}
wxTreeItemId hexWin::HTFind(WORD j) {
	wxTreeItemId r = HTRoot();
	return HTFind(j, r);
}
wxTreeItemId hexWin::HTFind(WORD j, wxTreeItemId& r) {
	wxTreeItemId i, c;
	wxTreeItemIdValue v;
	HACK* d = (HACK*)HT->GetItemData(r);
	if (j != d->hid) {
		i = HT->GetFirstChild(r, v);
		while (i.IsOk() && !c.IsOk()) {
			c = HTFind(j, i);
			i = HT->GetNextChild(r, v);
		}
	} else { c = r; }
	return c;
}
void hexWin::HTLoad(void) {
	wxTreeItemId r = HTRoot(), i = DB->GetSelection();
	if (i.IsOk()) {
		di = i;
		wxString s; HTSet();
		HT->DeleteAllItems();
		i = HTAdd(r, wxT("(m)"), 3);
		r = HTRoot(i);
		s = htf.GetFirstLine();
		HTLoad(r, s, 0);
	}
}
wxString hexWin::HTLoad(wxTreeItemId& r, wxString s, int m) {
	wxTreeItemId i, p; bool u = false;
	wxString s1, s2, s3, t; WORD k = 0x0000, n;
	int l = 0;
	HACK *d = new HACK, *h = (HACK*)HT->GetItemData(r);
	while (!htf.Eof()) {
		switch (m) {
		case 1:
			ht1 = s.SubString(0, 3);
			ht2 = s.SubString(4, 7);
			ht3 = s.SubString(9, 12);
			ht4 = s.SubString(13, 16);
			n = (WORD)getHEX(ht2);
			k = (WORD)getHEX(ht4);
			if (k != h->hid) {
				p = HTFind(k);
				u = true;
			} d->hid = n;
			d->SetLen(0);
			HT->SetItemData(i, d);
			l = 0; m = 2;
			break;
		case 2:
			s3 = s.SubString(0, 0);
			if (s3.Cmp(wxT('"')) == 0) {
				if (u) { HTLoad(p, s, 0); u = false; }
				else {
					t = s.SubString(1, s.length() - 2);
					if (t.Cmp(wxT("(m)")) == 0) { i = HTRoot(); }
					else { i = HTAdd(r, t, 3); }
					m = 1; d = new HACK;
				}
			} else {
				s1 = s.SubString(0, 7);
				s2 = s.SubString(9, 16);
				d->cPart1.Add(s1);
				d->cPart2.Add(s2);
				l++; d->SetLen(l);
				HT->SetItemData(i, d);
			} break;
		default:
			s3 = s.SubString(0, 0);
			if (s3.Cmp(wxT("\"")) == 0) {
				t = s.SubString(1, s.length() - 2);
				if (t.Cmp(wxT("(m)")) == 0) { i = HTRoot(); }
				else { i = HTAdd(r, t, 3); }
				m = 1; d = new HACK;
			}
		} if (!htf.Eof()) { s = htf.GetNextLine(); }
	} return s;
}
void hexWin::HTChange(void) {
	wxTreeItemId i = HT->GetSelection();
	HTChange(i);
}
void hexWin::HTChange(wxTreeItemId& i) {
	if (i != pti) {
		pti = i;
		HACK* td = (HACK*)HT->GetItemData(i);
		int j, l = td->GetLen(); wxString s;
		HCG->DeleteRows(0, HCG->GetRows(), false);
		for (j = 0;j < l;j++) {
			HCG->AppendRows(1, false);
			HCG->SetCellValue(j, 0, td->cPart1[j]);
			HCG->SetCellValue(j, 1, td->cPart2[j]);
		}
	}
}
void hexWin::HTSave(void) {
	WORD j = 0x0001, m = 0x0000;
	wxTreeItemId r = HTRoot();
	HTSet(); htf.Clear();
	while (r.IsOk()) {
		j = HTSave(r, j, m);
		r = HT->GetNextSibling(r);
	} htf.Write(wxTextFileType_Dos); htf.Close();
}
WORD hexWin::HTSave(wxTreeItemId& r, WORD j, WORD l) {
	wxTreeItemId i;
	wxTreeItemIdValue v;
	wxString s; WORD m = j;
	HACK* h = (HACK*)HT->GetItemData(r);
	DBI* d = (DBI*)DB->GetItemData(di); int k;
	s << wxT("\"") << HT->GetItemText(r) << wxT("\"");
	htf.AddLine(s, wxTextFileType_Dos); s.Clear();
	s.Printf(wxT("%04X%04X 0000%04X"), d->afi, j, l);
	htf.AddLine(s, wxTextFileType_Dos); s.Clear(); j++;
	for (k = 0;k < (int)h->length;k++) {
		s << h->cPart1[k] << wxT(" ") << h->cPart2[k];
		htf.AddLine(s); s.Clear();
	} i = HT->GetFirstChild(r, v);
	while (i.IsOk()) {
		j = HTSave(i, j, m);
		i = HT->GetNextChild(r, v);
	} return j;
}
void hexWin::bHTSaveOnClick(wxCommandEvent& event) { HTSave(); }
void hexWin::bHTLoadOnClick(wxCommandEvent& event) { HTLoad(); }
wxTreeItemId hexWin::HTAdd(wxTreeItemId& r, wxString l, int where,
	wxTreeItemId& i, HACK d) { return HTAdd(r, l, where, i, &d); }
wxTreeItemId hexWin::HTAdd(wxTreeItemId& r, wxString l, int where, wxTreeItemId& i, HACK* d) {
	wxTreeItemId c;
	switch (where) {
	case 0: c = HT->PrependItem(r, l, -1, -1, d); break;
	case 1:
		if (!!i) {
			i = HT->GetPrevSibling(i);
			if (!i) {
				c = HT->PrependItem(r, l, -1, -1, d);
				break;
			}
		}
	case 2:
		if (!!i) {
			c = HT->InsertItem(r, i, l, -1, -1, d);
			break;
		}
	default:
		c = HT->AppendItem(r, l, -1, -1, d);
	} HT->Expand(r); HT->SelectItem(c);
	return c;
}
wxTreeItemId hexWin::HTAdd(wxTreeItemId& r, wxString l, int where,
	wxTreeItemId& i) { HACK* d = new HACK; return HTAdd(r, l, where, i, d); }
wxTreeItemId hexWin::HTAdd(wxTreeItemId& r, wxString l, int where,
	HACK d) { wxTreeItemId i; return HTAdd(r, l, where, i, d); }
wxTreeItemId hexWin::HTAdd(wxTreeItemId& r, wxString l, int where) {
	wxTreeItemId i; HACK* d = new HACK; return HTAdd(r, l, where, i, d); }
void hexWin::HTDel(void) { HTDel(HT->GetSelection()); }
void hexWin::HTDel(wxTreeItemId i) {	if (i) { HT->Delete(i); } }
wxTreeItemId hexWin::HTFind(wxTreeItemId& r, wxString l) {
	wxTreeItemId i, c; wxTreeItemIdValue v;
	c = HT->GetFirstChild(r, v);
	while (c) {
		if (HT->GetItemText(c) == l) {
			return c;
		} c = HT->GetNextChild(r, v);
	} return i;
}
int hexWin::HTCount(wxTreeItemId& r)
	{ return HT->GetChildrenCount(r, false); }
void hexWin::HTMove(wxTreeItemId& r, wxTreeItemId& nr) {
	wxTreeItemId c, nc; wxTreeItemIdValue v;
	while (HTCount(r) > 0) {
		c = HT->GetFirstChild(r, v);
		nc = HTAdd(nr, HT->GetItemText(c), 3, (HACK*)HT->GetItemData(c));
		HTMove(c, nc);
	} HTDel(r);
}
void hexWin::HTMove(int direction) {
	wxTreeItemId c, i = HT->GetSelection(), ni, p, r;
	if (i == HTRoot()) { return; }
	HACK* d = (HACK*)HT->GetItemData(i);
	wxString s = HT->GetItemText(i), s2;
	int w = HTAddD->GetSelection(), t;
	r = HTRoot(i); p = HTRoot(r);
	switch (direction) {
	case 1:
		c = HT->GetNextSibling(i);
		if (c) { ni = HTAdd(r, s, 2, c, d); }
		else { ni = HTAdd(r, s, 3, d); }
		break;
	case 2:
		if (r == HTRoot()) { p = r; }
		ni = HTAdd(p, s, w, d);
		break;
	case 3:
		t = HTCount(r);
		do {
			s2.Printf(wxT("New Hack %i"), t);
			c = HTFind(r, s2); t++;
		} while (!c == false);
		r = HTAdd(r, s2, w);
		ni = HTAdd(r, s, 3, d);
		break;
	default:
		c = HT->GetPrevSibling(i);
		if (c) { ni = HTAdd(r, s, 1, c, d); }
		else { ni = HTAdd(r, s, 0, d); }
	} HTMove(i, ni);
	HT->SelectItem(ni);
	HTChange();
}
void hexWin::HTOnKeyDown(wxKeyEvent& event) {
	wxTreeItemId r, i = HT->GetSelection();
	wxTreeItemIdValue v; wxString s;
	int kc = event.GetKeyCode();
	if (event.ControlDown()) {
		switch (kc) {
		case WXK_SPACE: HTAddC->SetValue(!HTAddC->GetValue()); break;
		case WXK_EXECUTE: case WXK_ADD: case WXK_NUMPAD_ADD:
			r = HTRoot(i);
			s.Printf(wxT("New Hack %i"), HTCount(r));
			HTAdd(r, s, HTAddD->GetSelection(), i);
		break;
		case WXK_DELETE: case WXK_SUBTRACT: case WXK_NUMPAD_SUBTRACT:
			HTDel(i); break;
		case WXK_UP: HTMove(0); break;
		case WXK_DOWN: HTMove(1); break;
		case WXK_LEFT: HTMove(2); break;
		case WXK_RIGHT: HTMove(3); break;
		default: break; }
	} else {
		switch (kc) {
		case WXK_SPACE: HTAddC->SetValue(!HTAddC->GetValue()); break;
		case WXK_UP:
			r = HT->GetPrevSibling(i);
			if (!r) { r = HTRoot(i); }
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_DOWN:
			r = HT->GetNextSibling(i);
			if (!r) { r = HT->GetFirstChild(i, v); }
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_LEFT:
			r = HTRoot(i);
			if (r) { HT->SelectItem(r); }
		break;
		case WXK_RIGHT:
			r = HT->GetFirstChild(i, v);
			if (r) { HT->SelectItem(r); }
		break;
		default: break; }
	}
}
void hexWin::HTOnChangeSelT(wxTreeEvent& event) {
	wxTreeItemId i = event.GetItem();
	HTChange(i);
}
void hexWin::HCLoad(void) {}
void hexWin::HCChange(int r) {
	if (r != HCRow) {
		if (r < HCRow || (r > HCRow + HCRows)) {
			wxString s = HCG->GetCellValue(r, 2);
			long int v;
			while (r > 0) {
				if (s.Cmp(wxT("0")) != 0) { break; }
				r--; s = HCG->GetCellValue(r, 2);
			} s.ToLong(&v, 10);
			HCRows = (int)v;
			HCRow = r;
			HCLoad();
		}
	}
}
void hexWin::HCChangeC(wxGridEvent& event) {
	int r = event.GetRow();
	HCChange(r); event.Skip();
}
void hexWin::HCChangeR(wxGridEvent& event) {
	int r = event.GetRow();
	HCChange(r); event.Skip();
}
