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
	xStr xAddressText = editorAddress_TXT->GetValue(), trs = GARAM(0, 3), t, txt, text;
	HANDLE appHandle = GAP();
	if ( appHandle == NULL ) { EWB = 0; }
	u64 xAddress = getHEX( xAddressText );
	u64 ramAddress = GARS(0) + xAddress;
	u64 ramEnd = GARM(0);
	if (ramEnd < 1)
	{
		ramEnd = getAppSize( appHandle ) - ramAddress;
	}
	u32 row = 0;
	u32 col = 0;
	wxChar tc;
	u8 tmp = 0;
	ClearGrid(EG);
	u32 i = 0;
	u32 buffLen = 32 * 0x10;
	u8 buff[ buffLen ];
	HCReadM8(appHandle, ramAddress, buffLen, buff);
	for ( ; ( i < buffLen && row < 32 && xAddress < ramEnd ); i++, row++, xAddress++ )
	{
		EG->AppendRows(1, false);
		t.Printf(wxT("%016llX"), xAddress);
		EG->SetRowLabelValue(row, t);
		for ( col = 0; ( col < 16 && xAddress < ramEnd ); col++, i++, xAddress++) {
			t.Printf( wxT( "%02X" ), buff[ i ] );
			EG->SetCellValue(row, col, t);
			tc = buff[ i ];
			txt << tc;
			if (tmp > 0) { tmp = 0; }
			else {
				t.Printf( wxT("%02X%02X"), buff[ i ], buff[ i + 1 ] );
				tc = getHEX(t);
				text << tc;
				tmp = 1;
			}
		}
		i--;
		xAddress--;
		EG->SetCellValue(row, 16, txt);
		EG->SetCellValue(row, 17, text);
		txt.Clear();
		text.Clear();
	} EG->SetColMinimalAcceptableWidth(50);
	EG->AutoSizeColumns(0);
}
void ME::EV(void) { xStr tv = EVT->GetValue(); }
