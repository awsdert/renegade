#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <math.h>
void ME::HCHook(void) {
	xTID r = HTRoot();
	HANDLE p = GAP();
	if (p != NULL) { HCUse(r, p); }
	else { HWB = 0; }
}
//DWORD FlipAddress(DWORD x, s32 s = 0, s32 e = 0) {
	// 0 = LITTLE_ENDIAN_SYS
	// 2 = BIG_ENDIAN
	// 1 = LITTLE_ENDIAN_BIG_SYS
#define FlipAddress BLANK(0) \
	DWORD address; \
	if (endian == 1) { \
		switch (size) { \
		case 1: address = xAddress^3; break; \
		case 2: address = xAddress^2; break; \
		default: address = xAddress; } \
	} else { address = xAddress; }
#define ReadAddress BLANK(0) \
	ReadProcessMemory(appHandle, (void*)address, (void*)buff, size, NULL); \
	return buff;
void ME::HCWrite(ReadWriteApp, DWORD buff) {
	FlipAddress;
	WriteProcessMemory(appHandle, (void*)address, &buff, size, NULL);
}
xStr ME::HCRead(ReadWriteApp) {
	u64 buff = 0;
	FlipAddress;
	ReadProcessMemory(appHandle, (void*)address, &buff, size, NULL);
	xStr t; t.Printf(wxT("%X"), buff);
	return t;
}
u64 ME::HCReadH(ReadWriteApp) {
	u64 buff = 0;
	FlipAddress;
	ReadProcessMemory(appHandle, (void*)address, &buff, size, NULL);
	return buff;
}
u8* ME::HCReadM8(ReadWriteApp) {
	u8* buff = new u8[size];
	FlipAddress;
	ReadAddress;
}
u16* ME::HCReadM16(ReadWriteApp) {
	u16* buff = new u16[size];
	FlipAddress;
	ReadAddress;
}
u32* ME::HCReadM32(ReadWriteApp) {
	u32* buff = new u32[size];
	FlipAddress;
	ReadAddress;
}
u64* ME::HCReadM64(ReadWriteApp) {
	u64* buff = new u64[size];
	FlipAddress;
	ReadAddress;
}
void ME::HCUse(xTID& r, HANDLE appHandle, s32 line, s32 stop) {
	HACK* hack = getIH(r);
	u64 ramAddress = GARS(0);
	u64 xAddress, xValue;
	u64 ramValue;
	u32 incAddress;
	s32 startLine, endLine = 0;
	bool useTest, useKids = true;
	xStr text;
	if (hack->use && r.IsOk()) {
		u32 s;
		u32 k;
		CL code;
		xStr t, t2;
		xTID i; xTIDV v;
		// Use CL
		if (stop > 0) { useKids = false; }
		else { stop = hack->GetLen(); }
		while (line < stop) {
			code = HCSet(hack, line);
			s = code.size;
			xAddress = ramAddress + code.address;
			incAddress = code.inc_address * s;
			xValue = code.value;
			switch (code.codeType) {
			case 0x01: // Copy
				xValue = ramAddress + code.value;
				k = 0;
				do {
					ramValue = HCReadH(appHandle, xAddress, s);
					HCWrite( appHandle, xValue, s, ramValue );
					xAddress += incAddress;
					xValue += incAddress;
					k++;
				} while (k < code.reiterate);
				break;
			case 0x02: // Test
				ramValue = HCReadH( appHandle, xAddress, s );
				useTest = Test( code.test, ramValue, code.value );
				if ( useTest ) {
					if (code.reiterate > 0)
					{
						/* Move up call stack with new stop line and tell this
						instance to skip the specified lines */
						startLine = line;
						endLine = line;
						for ( k = 0; k < code.reiterate; k++ )
						{
							line = endLine;
							code.reiterate += hack->sLines[ endLine ]; // Support embeded IF statements
							endLine += hack->cLines[ endLine ]; // Ensure we get valid stop point
						}
						HCUse(r, appHandle, startLine, endLine );
					} // Continue normally
				} else {
					if (code.reiterate > 0)
					{ // Skip the specified lines
						endLine = line;
						for ( k = 0; k < code.reiterate; k++ )
						{
							line = endLine;
							code.reiterate += hack->sLines[ endLine ];
							endLine += hack->cLines[ endLine ];
						}
					}
					else
					{
						line = stop;
						useKids = false; // Break out of code set and stop children being used
					}
				} break;
			case 0x03: // Increment
				k = 0;
				do
				{
					xValue = HCReadH( appHandle, xAddress, s );
					HCWrite( appHandle, xAddress, s, xValue + code.inc_value );
					xAddress += incAddress;
					k++;
				}
				while ( k < code.reiterate );
				break;
			case 0x04: // Decrement
				k = 0;
				do
				{
					xValue = HCReadH( appHandle, xAddress, s);
					HCWrite( appHandle, xAddress, s, xValue - code.inc_value );
					xAddress += incAddress;
					k++;
				}
				while ( k < code.reiterate );
				break;
			case 0x05: // List Write
				for ( k = 0; k < code.reiterate; k++ )
				{
					HCWrite( appHandle, xAddress, s, getHEX( code.valueArray[ k ] ) );
					xAddress += incAddress;
				}
				break;
			default: // Write
				k = 0;
				//HCTest(code);
				do
				{
					HCWrite( appHandle, xAddress, s, xValue );
					xAddress += incAddress;
					xValue += code.inc_value;
					k++;
				}
				while ( k < code.reiterate );
			}
			line += hack->cLines[ line ];
		}
		// Recurse through children
		if (useKids)
		{
			i = HT->GetFirstChild( r, v );
			while ( i.IsOk() ) {
				HCUse( i, appHandle );
				i = HT->GetNextChild( r, v );
			}
		}
	}
}
//* Only for testing new code formats, comment out for releases
void ME::HCTest(CL code) {
	xStr text;
	text.Printf( wxT("Code Type:\t0x%X\
\nCode Size:\t\t0x%X\
\nTest:\t\t0x%02X\
\nReiterate:\t\t0x%02X\
\nAddress:\t\t0x%016llX\
\nIncrement Address:\t0x%08X\
\nValue:\t\t0x%016llX\
\nIncrement Value:\t0x%016llX"),
		code.codeType, code.size, code.test, code.reiterate,
		code.address, code.inc_address,
		code.value, code.inc_value );
	//DBNotes->SetValue(text);
	MB(text);
}//*/
void ME::HCUChange(void) {
	xTID i = HT->GetSelection();
	HACK* h = getIH(i);
	h->use = HCUseC->GetValue();
	HT->SetItemData(i, h);
}
void ME::HCUOnChange(wxCommandEvent& event) { HCUChange(); }
void ME::HCDelBOnClick(wxCommandEvent& event) {}
void ME::HCRCOnChange(wxCommandEvent& event) {
	s32 i = HCCD->GetSelection();
	if (i != 2 && i != 5) {
		bool r = HCRC->GetValue();
		HCAW->Show(r);
	} HCP->Layout();
}
void ME::HCCDOnChange(wxCommandEvent& event) {
	s32 i = HCCD->GetSelection();
	bool r = HCRC->GetValue();
	if (r) {
		if (i == 2 || i == 5) { HCAW->Hide(); }
		else { HCAW->Show(); }
	}
	if (i == 2) { HCTW->Show(); }
	else { HCTW->Hide(); }
	if (i == 3 || i == 4) {
		HCVW->Show();
		if (i == 3) { HCVS1->SetLabel(wxT("Add")); }
		else { HCVS1->SetLabel(wxT("Minus")); }
	} else { HCVW->Hide(); }
	HCP->Layout();
}
void ME::HCChangeD(wxGridEvent& event) {
	s32 c = event.GetCol(), r = event.GetRow();
	xStr d = HCG->GetCellValue(r, c);
	xTID i = HT->GetSelection();
	HACK* h = (HACK*)HT->GetItemData(i);
	switch (c) {
	case 0: h->cPart1[r] = d; break;
	case 1: h->cPart2[r] = d; break;
	case 2:
		d.Printf(wxT("%i"), h->cLines[r]);
		HCG->SetCellValue(r, c, d);
	}
}
int ME::GetGridRow( wxGrid* grid )
{
	int row = 0;
	if ( grid->IsSelection() )
	{
		xAInt rows = grid->GetSelectedRows();
		if ( rows.GetCount() > 0 )
		{
			row = rows[0];
		}
		else
		{
			wxGridCellCoords cell = grid->GetSelectedCells()[0];
			row = cell.GetRow();
		}
	}
	return row;
}
void ME::HCLoad( void ) {
	xTID i = HT->GetSelection();
	CL code = HCSet( getIH(i), GetGridRow( HCG ) );
	HCTest( code );
}
void ME::HCChange(s32 r) {
	if (r != HCRow) {
		if (r < HCRow || (r > HCRow + HCRows)) {
			xStr s = HCG->GetCellValue(r, 2);
			signed long int v;
			while (r > 0) {
				if (s.Cmp(wxT("0")) != 0) { break; }
				r--; s = HCG->GetCellValue(r, 2);
			} s.ToLong(&v, 10);
			HCRows = (s32)v;
			HCRow = r;
			HCLoad();
		}
	}
}
void ME::HCChangeC(wxGridEvent& event) {
	s32 r = event.GetRow();
	HCChange(r); event.Skip();
}
void ME::HCChangeR(wxGridEvent& event) {
	s32 r = event.GetRow();
	HCChange(r); event.Skip();
}
