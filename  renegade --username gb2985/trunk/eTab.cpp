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
	wxString tv = EAT->GetValue(), trs = tRAMSize->GetValue(), t, txt, text;
	HANDLE p = GAP();
	if (p == NULL) { EWB = 0; }
	u32 s = getHEX(tv), i, r, c, k = 0, ram = GAR(), re, rs;
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
void ME::EV(void) { wxString tv = EVT->GetValue(); }
void ME::EAOnClick(wxCommandEvent& event) { EA(); }
void ME::EVOnClick(wxCommandEvent& event) { EV(); }
void ME::EUOnChange(wxCommandEvent& event) { EWB = HDT[EUD->GetSelection()]; }
void ME::EGOnChange(wxGridEvent& event) {
	int r = event.GetRow(), c = event.GetCol();
	wxString s = EG->GetCellValue(r, 0);
	if (c > 0) {
		u32 i = getHEX(s) + GAR() + c - 1, v = getHEX(EG->GetCellValue(r, c));
		HANDLE p = GAP(); HCWrite(p, i, 1, v);
	} else { EAT->SetValue(s); EA(); }
}
