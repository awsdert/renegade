/***************************************************************
 * Name:      eTab.cpp
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
void ME::EA(void) {
	xStr tv = EAT->GetValue(), trs = GARAM(0, 3), t, txt, text;
	HANDLE p = GAP();
	if (p == NULL) { EWB = 0; }
	u32 s = getHEX(tv), i, r, c, k = 0, ram = GARS(0), re, rs;
	rs = ram + s; re = ram + getHEX(trs) + (u32)1;
	wxChar tc; u8 tmp = 0;
	EG->DeleteRows(0, EG->GetNumberRows(), false);
	for (i = rs, r = 0;(r < 32 && i < re);r++) {
		EG->AppendRows(1, false);
		t.Printf(wxT("%X"), i - ram);
		EG->SetCellValue(r, 0, t);
		for (c = 0;c < 16;c++) {
			k = i + c;
			if (k >= re) { break; }
			t = HCRead(p, k, 1);
			EG->SetCellValue(r, c + 1, t);
			tc = getHEX(t);
			txt << tc;
			if (tmp > 0) { tmp = 0; }
			else {
				t = HCRead(p, k, 2);
				tc = getHEX(t);
				text << tc;
			}
		} i = k + 1;
		EG->SetCellValue(r, 17, txt);
		EG->SetCellValue(r, 18, text);
		txt = wxT(""); text = wxT("");
	} EG->SetColMinimalAcceptableWidth(50);
	EG->AutoSizeColumns(0);
}
void ME::EV(void) { xStr tv = EVT->GetValue(); }
