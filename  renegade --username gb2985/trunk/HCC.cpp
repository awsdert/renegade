#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <math.h>
// Analyse the code string/s
CL ME::HCSet( HACK* hack, u32 line )
{
	CL code;
	if ( hack->GetLen() > 0 )
	{
		xStr text;
		// Line
		u32 line1 = line + 1;
		u32 line2 = line + 2;
		u32 line3 = line + 3;
		u32 stop = hack->cLines[ line ];
		u32 endLine = hack->GetLen();
		// Code pieces
		u32 xType = 0;
		u32 xSize = 0;
		xStr cPart_blank  = wxT( "00000000" );
		xStr cPart_1 = hack->cPart1[ line ];
		xStr cPart_2 = hack->cPart2[ line ];
		xStr cPart_3 = hack->cPart1[ line1 ];
		xStr cPart_4 = hack->cPart2[ line1 ];
		xStr cPart_5 = cPart_blank, cPart_6 = cPart_blank,
			cPart_7 = cPart_blank, cPart_8 = cPart_blank, c;
		// Address
		u32 xRAM = 0;
		u64 xAddress = 0;
		// Increment Value
		u64 xValue = 0;
		u64 xIncrement;
		// Code
		if ( stop > 2 && endLine >= line2 )
		{
			cPart_4 = hack->cPart1[ line2 ];
			cPart_5 = hack->cPart2[ line2 ];
			if ( stop > 3 && endLine >= line3 )
			{
				cPart_6 = hack->cPart1[ line3 ];
				cPart_7 = hack->cPart2[ line3 ];
			}
		}
		code.reiterate = getHEX( cPart_1.SubString( 6, 7 ) );
		code.test = getHEX( cPart_1.SubString( 4, 5 ) );
		code.inc_address = getHEX( cPart_2 );
		if ( getHEX( cPart_1 ) >= 0xE0000000 )
		{
			xRAM = getHEX( cPart_1.GetChar( 1 ) );
			xType = getHEX( cPart_1.GetChar( 2 ) );
			xSize = getHEX( cPart_1.GetChar( 3 ) );
		}
		else
		{
			xType = getHEX( cPart_1.GetChar( 0 ) );
			xSize = getHEX( cPart_1.GetChar( 1 ) );
		}
		// Setup
		if ( xSize >= 0xC )
		{
			xAddress = getHEX( cPart_3 + cPart_4 );
			xValue = getHEX( cPart_5 + cPart_6 );
			xIncrement = getHEX( cPart_7 + cPart_8 );
		}
		else
		{
			xAddress = getHEX( cPart_3 );
			xValue = getHEX( cPart_4 );
			xIncrement = getHEX( cPart_6 );
		}
		code.address = xAddress;
		code.inc_value = xIncrement;
		code.ram = xRAM;
		switch ( xType )
		{
			case 0x1: // Write
			case 0x3: // Copy
			case 0x5: // Test
			case 0x7: // Increment
			case 0x9: // Decrement
			case 0xB: // List Write
				code.fixed = true;
			default:
				code.codeType = floor(xType / 2);
		}
		// List Values
		for ( u64 i = 1; i < stop; i++ )
		{
			code.valueArray.Add( hack->cPart1[ line + i ] );
			code.valueArray.Add( hack->cPart2[ line + i ] );
		}
	}
	return code;
}
// Build the code string/s
void ME::HCAddBOnClick(wxCommandEvent& event) {
	ti = HT->GetSelection(); bool p1 = true, u0 = true;
	xStr s, s1 = tHackA->GetValue(), s2 = tHackV->GetValue(), s3; HACK* d = getIH(ti);
	xAStr da1, da2;
	xStrT st(s2, wxT("|"));
	while ( st.HasMoreTokens() ) {
		s = st.GetNextToken();
		if (p1) { da1.Add(s); p1 = false; }
		else { da2.Add(s); p1 = true; }
	} u32 t0, ct, cs, rows = 1, cr = (u32)HCRN->GetValue();
	bool t3 = HCRC->GetValue();
	s32 l = d->GetLen();
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
		u32 i, j = 1, l1 = da1.GetCount(), l2 = da2.GetCount(), x, x2, x3;
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
