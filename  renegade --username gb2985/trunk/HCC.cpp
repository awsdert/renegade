#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <math.h>
CL ME::HCSet(HACK* h, int row) {
	CL code;
	if (h->GetLen() > 0) {
		int l = h->cLines[row], i = row, il = h->cLines.GetCount();
		u8 t, s, r, tl;
		u16 j0 = 0, j1, j2, j3, i1, i2;
		u32 x = 0, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d7 = 0, v = 0;
		xStr s1 = h->cPart1[i], s2 = h->cPart2[i], s3, s4, s5, s6, s7 = wxT("00000000"), c;
		if (l > 1 && il >= (i + 1)) {
			s3 = h->cPart1[i + 1];
			s4 = h->cPart2[i + 1];
			if (l > 2 && il >= (i + 2)) {
				s5 = h->cPart1[i + 2];
				s6 = h->cPart2[i + 2];
			} else { s5 = s7; s6 = s7; }
		} else { s3 = s7; s4 = s7; s5 = s7; s6 = s7; }
		j1 = (u16)getHEX(s2.SubString(2, 5));
		j2 = (u16)getHEX(s4.SubString(2, 5));
		j3 = (u16)getHEX(s5.SubString(2, 5));
		d1 = getHEX(s1); d2 = getHEX(s2);
		d3 = getHEX(s3); d4 = getHEX(s4);
		r = (u8)getHEX(s2.SubString(6, 7));
		if (d1 >= 0xE0000000) {
			if (d1 >= 0xE0E00000) {
				x = d2;
				t = (u8)getHEX(s1.GetChar(4));
				s = (u8)getHEX(s1.GetChar(5));
				r = (u8)getHEX(s1.SubString(6, 7));
				tl = (u8)getHEX(s3.SubString(0, 1));
				i1 = d3; i2 = d3;
			} else {
				x = getHEX(s1.SubString(4, 7));
				t = (u8)getHEX(s1.GetChar(2));
				s = (u8)getHEX(s1.GetChar(3));
				tl = (u8)getHEX(s5.SubString(0, 1));
				i1 = getHEX(s2.SubString(0, 3));
				i2 = getHEX(s2.SubString(2, 3));
				d7 = 0x00010000; //j3 = j2;
			}
		} else {
			x = getHEX(s1.SubString(2, 7));
			t = (u8)getHEX(s1.GetChar(0));
			s = (u8)getHEX(s1.GetChar(1));
			tl = (u8)getHEX(s2.SubString(0, 1));
			d7 = 0x01000000; j0 = j1;
		} // Setup
		code.x = x;
		code.i = d3;
		code.l = tl;
		// Code Type
		switch (t) {
		case 0x01: // Write
		case 0x03: // Copy
		case 0x05: // Test
		case 0x07: // Increment
		case 0x09: // Decrement
		case 0x0B: // List Write
			code.f = false;
		} code.t = floor(t / 2);
		// Code Size
		if (l > 1 || code.t == 0x05) { v = d4; }
		else { v = d2; }
		switch (s) {
		case 0x01: case 0x05: case 0x09: case 0x0D:
			code.x += d7; break;
		case 0x03: case 0x07: case 0x0B: case 0x0F:
			code.x += d7;
		case 0x02: case 0x06: case 0x0A: case 0x0E:
			code.r = r; }
		if (s > 0x0B) { code.s = 0x08; }
		else if (s > 0x07) { code.s = 0x04; }
		else if (s > 0x03) { code.s = 0x02; v = (u16)v; }
		else { code.s = 0x01; v = (u8)v; }
		if (code.t == 2) {
			if (code.s < 8) {
				j0 = j1;
				v = getHEX(s2.SubString(0, 3));
			} else { j0 = j3; } j0 = (u16)j0;
		} code.v = v; code.j = j0;
		// List Values
		for (i = 1;i < l;i++) {
			code.ca.Add(h->cPart1[row + i]);
			code.ca.Add(h->cPart2[row + i]);
		}
	} return code;
}
void ME::HCAddBOnClick(wxCommandEvent& event) {
	ti = HT->GetSelection(); bool p1 = true, u0 = true;
	xStr s, s1 = tHackA->GetValue(), s2 = tHackV->GetValue(), s3; HACK* d = getIH(ti);
	wxArrayString da1, da2;
	xStrT st(s2, wxT("|"));
	while ( st.HasMoreTokens() ) {
		s = st.GetNextToken();
		if (p1) { da1.Add(s); p1 = false; }
		else { da2.Add(s); p1 = true; }
	} unsigned int t0, ct, cs, rows = 1, cr = (unsigned int)HCRN->GetValue(); bool t3 = HCRC->GetValue();
	int l = d->GetLen();
	u32 d0 = getHEX(s1), d1 = 0, d2 = getHEX(s2), d3 = getHEX(HCVT->GetValue()), d4 = 0, d5 = 0, d6 = 0;
	u32 v2 = 0;
	t0 = HCRAMD->GetSelection();
	ct = HCCD->GetSelection();
	cs = mHackV->GetSelection();
	u8 repeat = HCRN->GetValue(), test = 0;
	s.Printf(wxT("00%04X%02X"), getHEX(HCAT->GetValue()), repeat);
	v2 = getHEX(s);
	if (d0 > 0x01FFFFFF || (t0 > 0 && d0 > 0x0001FFFF)) {
		u0 = false;
		rows = 2;
		d1 = 0xE0E00000 + (t0 * 0x10000) + cr;
		d4 = d2; d2 = d0;
		d1 += ct * 0x2000;
		d1 += cs * 0x400;
		d5 = v2;
		if (t3) { d1 += 0x200; }
	} else {
		if (t0 > 0) {
			d1 = 0xE0000000 + (t0 * 0x1000000) + d0;
			d1 += ct * 0x200000;
			d1 += cs * 0x40000;
			if (t3) { d1 += 0x20000; }
		} else {
			d1 = d0;
			d1 += ct * 0x20000000;
			d1 += cs * 0x4000000;
			if (t3) { d1 += 0x2000000; }
		}
		if (ct != 2 && ct != 5 && repeat > 0) {
			d4 = d2; d2 = v2;
			rows = 2;
		} else if (ct == 2) {
			if (cs < 2) {
				s3.Printf(wxT("%04X%02X%02X"), d2, test, repeat);
				d2 = getHEX(s3);
			} else {
				s3.Printf(wxT("0000%02X%02X"), test, repeat);
				d4 = d2; d2 = getHEX(s3);
			}
		}
	}
	if (ct == 5) {
		d2 = d0;
		if (u0) { d1 -= d0; }
	} HCG->AppendRows(1);
	s.Printf(wxT("%08X"), d1);
	HCG->SetCellValue(l, 0, s);
	d->cPart1.Add(s);
	s.Printf(wxT("%08X"), d2);
	HCG->SetCellValue(l, 1, s);
	d->cPart2.Add(s);
	s.Printf(wxT("%i"), rows);
	HCG->SetCellValue(l, 2, s);
	d->cLines.Add(rows);
	l++;
	if (ct == 5) {
		unsigned int i, j = 1, l1 = da1.GetCount(), l2 = da2.GetCount(), x, x2, x3;
		switch (cs) {
		case 3:
		case 2: x2 = 2; s = wxT("00000000"); break;
		case 1: x2 = 4; s = wxT("0000"); break;
		default: x2 = 8; s = wxT("00"); }
		rows = floor(cr / 2); x = l; x2 = x2 / 2;
		for (i = 0, x3 = 0;(i < cr && x3 < rows);i++) {
			s1.Clear(); s2.Clear();
			if (i < l1) { s1 << da1[i]; }
			else { s1 << s; }
			if (i < l2) { s2 << da2[i]; }
			else { s2 << s; } j++;
			if (j > x2) {
				HCG->AppendRows(1);
				HCG->SetCellValue(x, 0, s1);
				d->cPart1.Add(s1);
				HCG->SetCellValue(x, 1, s2);
				d->cPart2.Add(s2);
				HCG->SetCellValue(x, 2, wxT("0"));
				d->cLines.Add(0);
				x++;
				j = 1; x3++;
			}
		} s.Printf(wxT("%i"), rows);
		HCG->SetCellValue(l - 1, 2, s);
		d->cLines[l - 1] = rows;
	} else if (rows > 1) {
		HCG->AppendRows(1);
		s.Printf(wxT("%08X"), d3);
		HCG->SetCellValue(l, 0, s);
		d->cPart1.Add(s);
		s.Printf(wxT("%08X"), d4);
		HCG->SetCellValue(l, 1, s);
		d->cPart2.Add(s);
		HCG->SetCellValue(l, 2, wxT("0"));
		d->cLines.Add(0);
		l++;
		if (rows > 2) {
			HCG->AppendRows(1);
			s.Printf(wxT("%08X"), d5);
			HCG->SetCellValue(l, 0, s);
			d->cPart1.Add(s);
			s.Printf(wxT("%08X"), d6);
			HCG->SetCellValue(l, 1, s);
			d->cPart2.Add(s);
			HCG->SetCellValue(l, 2, wxT("0"));
			d->cLines.Add(0);
			l++;
		}
	} HT->SetItemData(ti, d);
}
