/***************************************************************
 * Name:      HT.cpp
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
xTID ME::HTRoot(void) {	return HT->GetRootItem(); }
xTID ME::HTRoot(xTID& i) {
	xTID c, r = HTRoot();
	if (i.IsOk() && i != r) { c = HT->GetItemParent(i); }
	else { c = r; }
	return c;
}
void ME::HTSet(void) {
	xStr d = hexSlash, p = wxGetCwd(), s;
	DBI* k = (DBI*)DB->GetItemData(di);
	p << d + wxT("db");
	dir.Open(p);
	s32 i = group_D->GetSelection();
	PLATFORM* pf = (PLATFORM*)group_D->GetClientData( i );
	p << d + pf->file;
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s = p + d + k->afp + wxT(".hexcl");
	if (!checkFile.Exists(s)) {
		htf.Create(s);
	} htf.Open(s);
}
xTID ME::HTFind(u16 j) {
	xTID r = HTRoot();
	return HTFind(j, r);
}
xTID ME::HTFind(u16 j, xTID& r) {
	xTID i, c; xTIDV v;
	HACK* d = getIH(r);
	if (j != d->hid) {
		i = HT->GetFirstChild(r, v);
		while (i.IsOk() && !c.IsOk()) {
			c = HTFind(j, i);
			i = HT->GetNextChild(r, v);
		}
	} else { c = r; }
	return c;
}
xTID ME::HTFind(xTID& r, xStr l) {
	xTID i, c; xTIDV v;
	c = HT->GetFirstChild(r, v);
	while (c) {
		if (HT->GetItemText(c) == l) {
			return c;
		} c = HT->GetNextChild(r, v);
	} return i;
}
void ME::HTLoad(void) {
	HWB = 0; xStr s;
	di = DB->GetSelection();
	xTID r, i;
	/*HT->DeleteAllItems();
	HT->Destroy();
	HT = new wxTreeCtrl( HTP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_EDIT_LABELS );
	HTTL->Insert( 1, HT, 0, wxALL|wxEXPAND, 5 );
	HTP->Layout();*/
	r = HTRoot();
	HTDel(r);
	HTJ = 0;
	r = HTRoot();
	//HTDel(r); r = HTRoot();//*/
	if (di.IsOk()) {
		HTSet();
		//if (HTFT) {
			i = HTAdd(r, wxT("(m)"), 3);
			//HTFT = false;
		//}
		if (i.IsOk()) {
			s = htf.GetFirstLine();
			HTLoad(i, s);
			HT->SelectItem(i);
		}
	} htf.Close();
}
xStr ME::HTLoad(xTID& r, xStr s) {
	xTID i, p; u16 k = 0, n;
	xStr s1, s2, s3, t; xStrT st;
	s32 xl; u8 m = 2, sl; bool use = false;
	HACK *d = new HACK, *h = getIH(r), *ph; ph = h;
	while (!htf.Eof()) {
		switch (m) {
		case 1:
			ht1 = s.SubString(0, 3);
			ht2 = s.SubString(4, 7);
			ht3 = s.SubString(9, 12);
			ht4 = s.SubString(13, 16);
			n = (u16)getHEX(ht2);
			k = (u16)getHEX(ht4);
			if (t.Cmp(wxT("(m)")) == 0) { i = r; }
			else if (k != h->hid) {
				if (!p.IsOk() || k != ph->hid) {
					p = HTFind(k);
					ph = getIH(p);
				} i = HTAdd(p, t, 3);
			} else { i = HTAdd(r, t, 3); }
			d = getIH(i);
			d->use = use;
			d->hid = n;
			setIH(i, d);
			m = 3; break;
		case 2: case 3:
			s3 = s.SubString(0, 0);
			if ( s3.Cmp( wxT( '"' ) ) == 0 )
			{
				s1 = s.SubString( s.length() - 1, s.length() - 1 );
				t = s.SubString( 1, s.length() - 3 );
				m = 1; use = (s1 == wxT( "1" )) ? true : false;
				break;
			}
		default:
			if (m > 2) {
				if (s.length() > 16) {
					st.SetString(s, wxT(";"));
					s1 = st.GetNextToken();
					s1 = st.GetNextToken();
					xl = (u8)getHEX(s1);
					s1 = st.GetNextToken();
					sl = (s32)getHEX(s1);
				} else { xl = 0; sl = 0; }
				s1 = s.SubString(0, 7);
				s2 = s.SubString(9, 16);
				d->cPart1.Add(s1);
				d->cPart2.Add(s2);
				d->cLines.Add(xl);
				d->sLines.Add(sl);
				setIH(i, d);
			}
		} if (!htf.Eof()) { s = htf.GetNextLine(); }
	} HTJ = HT->GetCount();
	return s;
}
void ME::HTChange(void) { HTChange(ti); }
void ME::HTChange(xTID& i) {
	pti = i;
	xStr s, t;
	HACK* td = getIH(i);
	u8 j, l = td->GetLen();
	ClearGrid(HCG);
	HCUseC->SetValue(td->use);
	for (j = 0;j < l;j++) {
		HCG->AppendRows(1, false);
		HCG->SetCellValue(j, 0, td->cPart1[j]);
		HCG->SetCellValue(j, 1, td->cPart2[j]);
		t.Printf(wxT("%i"), td->cLines[j]);
		HCG->SetCellValue(j, 2, t);
		t.Printf(wxT("%i"), td->sLines[j]);
		HCG->SetCellValue(j, 3, t);
	}
}
void ME::HTSave(void) {
	u16 j = 0x0001, m = 0x0000;
	xTID r = HTRoot();
	HTSet(); htf.Clear();
	while (r.IsOk()) {
		j = HTSave(r, j, m);
		r = HT->GetNextSibling(r);
	} htf.Write(wxTextFileType_Dos); htf.Close();
}
u16 ME::HTSave(xTID& r, u16 j, u16 l) {
	xTID i; s32 tmp;
	xTIDV v;
	xStr s, t; u16 m = j;
	HACK* h = (HACK*)HT->GetItemData(r);
	DBI* d = (DBI*)DB->GetItemData(di); s32 k;
	t.Printf(wxT("%i"), h->use);
	s << wxT("\"") << HT->GetItemText(r) << wxT("\"") << t;
	htf.AddLine(s, wxTextFileType_Dos); s.Clear();
	s.Printf(wxT("%04X%04X 0000%04X"), d->afi, j, l);
	htf.AddLine(s, wxTextFileType_Dos); s.Clear(); j++;
	for (k = 0;k < h->GetLen();k++) {
		tmp = h->cLines[k];
		if (tmp > 0) { t.Printf(wxT(";%i"), tmp); }
		else { t = wxT(""); }
		s << h->cPart1[k] << wxT(" ") << h->cPart2[k] << t;
		htf.AddLine(s); s.Clear();
	} i = HT->GetFirstChild(r, v);
	while (i.IsOk()) {
		j = HTSave(i, j, m);
		i = HT->GetNextChild(r, v);
	} return j;
}
xTID ME::HTAdd(xTID& r, xStr l, s32 where,
	xTID& i, HACK d) { return HTAdd(r, l, where, i, &d); }
xTID ME::HTAdd(xTID& r, xStr l, s32 where, xTID& i, HACK* d) {
	xTID c;
	switch (where) {
	case 0: c = HT->PrependItem(r, l); break;
	case 1:
		if (i.IsOk()) {
			i = HT->GetPrevSibling(i);
			if (!i.IsOk()) {
				c = HT->PrependItem(r, l);
				break;
			}
		}
	case 2:
		if (i.IsOk()) {
			c = HT->InsertItem(r, i, l);
			break;
		}
	default:
		c = HT->AppendItem(r, l);
	} setIH(c, d); HT->Expand(r);
	HT->SelectItem(c); return c;
}
HACK* ME::newH(void) {
	HACK *d = new HACK;
	d->hid = HTJ; HTJ++;
	return d;
}
xTID ME::HTAdd(xTID& r, xStr l, s32 where,
	xTID& i) { HACK* d = newH(); return HTAdd(r, l, where, i, d); }
xTID ME::HTAdd(xTID& r, xStr l, s32 where,
	HACK d) { xTID i; return HTAdd(r, l, where, i, d); }
xTID ME::HTAdd(xTID& r, xStr l, s32 where) {
	xTID i; HACK* d = newH(); return HTAdd(r, l, where, i, d); }
void ME::HTDel(xTID& i) {
	xTID c; xTIDV v;
	while (HT->ItemHasChildren(i)) {
		c = HT->GetFirstChild(i, v);
		HTDel(c);
	} HT->SetItemHasChildren(i, false);
	HT->Delete(i);
}
void ME::HTDelAll(void) { HT->CollapseAndReset(rti); }
s32 ME::HTCount(xTID& r) { return HT->GetChildrenCount(r, false); }
HACK* copyH(HACK* h, HACK* d) {
	h->use = d->use;
	h->cLines = d->cLines;
	h->cPart1 = d->cPart1;
	h->cPart2 = d->cPart2;
	h->sLines = h->sLines;
	return h;
}
HACK* ME::getIH(xTID& i) { return (HACK*)HT->GetItemData(i); }
void ME::setIH(xTID& i, HACK* h) { HT->SetItemData(i, h); }
xTID ME::HTMove(xTID& r, xTID& nr) {
	xTID c, nc; xTIDV v;
	HACK *h = getIH(nr), *d = getIH(r);
	u16 HJ = d->hid;
	h = copyH(h, d);
	while (c.IsOk()) {
		c = HT->GetFirstChild(r, v);
		nc = HTAdd(nr, HT->GetItemText(c), 3);
		nc = HTMove(c, nc);
		r = HTFind(d->hid);
	} HTDel(r);
	nr = HTFind(h->hid);
	h->hid = HJ;
	setIH(nr, h);
	return nr;
}
void ME::HTMove(s32 direction) {
	xTID c, i = ti, ni, p, r;
	HWB = 0; u16 HJR = HTJ;
	if (i == HTRoot()) { return; }
	xStr s = HT->GetItemText(i), s2, s3 = wxT("(m)");
	bool ir = (s.Cmp(s3) != 0) ? true : false;
	s32 w = HTAddD->GetSelection();
	r = HTRoot(i);
	switch (direction) {
	case 1: // Down
		if (ir == true) {
			c = HT->GetNextSibling(i);
			ni = HTAdd(r, s, 2, c);
		} break;
	case 2: // Left
		s2 = HT->GetItemText(r);
		if (ir == true && s2.Cmp(s3) == 0) {
			p = HTRoot(r);
			ni = HTAdd(p, s, w, r);
		} break;
	case 3: // Right
		if (ir == true) {
			s2.Printf(wxT("New Hack %i"), HTJ);
			p = HTAdd(r, s2, 2);
			ni = HTAdd(p, s, 0);
			HJR++;
		} break;
	default: // Up
		if (ir == true) {
			c = HT->GetPrevSibling(i);
			ni = HTAdd(r, s, 1, c);
		}
	}
	if (ir && ni.IsOk()) {
		ni = HTMove(i, ni);
		HT->SelectItem(ni);
		HTJ = HJR;
	}
}
