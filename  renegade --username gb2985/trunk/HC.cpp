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
	DWORD buff = 0;
	FlipAddress;
	ReadProcessMemory(appHandle, (void*)address, &buff, size, NULL);
	xStr t; t.Printf(wxT("%X"), buff);
	return t;
}
DWORD ME::HCReadH(ReadWriteApp) {
	DWORD buff = 0;
	FlipAddress;
	ReadAddress;
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
void ME::HCUse(xTID& r, HANDLE p, s32 j, s32 stop) {
	HACK* h = getIH(r);
	DWORD ram = GARS(0), xa, xv;
	u32 rv; s32 j2, j3 = 0; bool ut, uc = true;
	if (h->use && r.IsOk()) {
		s32 s, l = h->GetLen(), k; CL c; xStr t, t2;
		xTID i; xTIDV v;
		// Use CL
		if (stop > 0) { uc = false; }
		else { stop = l; }
		while (j < stop) {
			c = HCSet(h, j);
			s = (s32)c.s;
			xa = ram + c.x;
			switch (c.t) {
			case 0x01: // Copy
				xv = ram + c.v; k = 0;
				do {
					t = HCRead(p, xa, s);
					HCWrite(p, xv, s, getHEX(t));
					xa += (c.j * s); xv += (c.j * s);
					k++;
				} while (k < c.r);
				break;
			case 0x02: // Test
				rv = HCReadH(p, c.x, s);
				ut = Test(c.j, rv, c.v);
				if (ut) {
					if (c.r > 0) {
						/* Move up call stack with new stop line and tell this
						instance to skip the specified lines */
						j2 = j;
						for (k = 0;k < c.r;k++) {
							c.r += h->sLines[j]; // Support embeded IF statements
							j3 = j; j += h->cLines[j]; // Ensure we get valid stop point
						} HCUse(r, p, j2, j);
						j = j3; // Ensure we have valid continue point
					} // Continue normally
				} else {
					if (c.r > 0) { // Skip the specified lines
						for (k = 0;k < c.r;k++) {
							j3 = j; j += h->cLines[j];
						} j = j3;
					} else { j = stop; uc = ut; } // Break out of code set and stop children being used
				} break;
			case 0x03: // Increment
				k = 0;
				do {
					xv = getHEX(HCRead(p, xa, s));
					HCWrite(p, xa, s, xv + c.i);
					xa += (c.j * s); k++;
				} while (k < c.r);
				break;
			case 0x04: // Decrement
				k = 0;
				do {
					xv = getHEX(HCRead(p, xa, s));
					HCWrite(p, xa, s, xv - c.i);
					xa += (c.j * s); k++;
				} while (k < c.r);
				break;
			case 0x05: // List Write
				for (k = 0;k < c.r;k++) {
					HCWrite(p, xa, s, getHEX(c.ca[k]));
					xa += (c.j * s);
				} break;
			default: // Write
				xv = c.v; k = 0;
				do {
					HCWrite(p, xa, s, xv);
					xa += (c.j * s); xv += c.i;
					k++;
				} while (k < c.r);
			} j += h->cLines[j];
		}
		// Recurse through children
		if (uc) {
			i = HT->GetFirstChild(r, v);
			while (i.IsOk()) {
				HCUse(i, p);
				i = HT->GetNextChild(r, v);
			}
		}
	}
}
//* Only for testing new code formats, comment out for releases
void ME::HCTest(CL code) {
	xStr s;
	s.Printf(wxT("Address: %08X\nValue: %08X"), code.x, code.v);
	DBNotes->SetValue(s);
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
void ME::HCLoad(void) {}
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
