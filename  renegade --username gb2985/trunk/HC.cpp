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
//DWORD FlipAddress(DWORD x, int s = 0, int e = 0) {
	// 0 = LITTLE_ENDIAN_SYS
	// 2 = BIG_ENDIAN
	// 1 = LITTLE_ENDIAN_BIG_SYS
#define FlipAddress(a, x, s, e) { \
	if (e == 1) { \
		switch (s) { \
		case 1: a = x^3; \
		case 2: a = x^2; \
		default: a = x; } \
	} else { a = x; } \
}
void ME::HCWrite(HANDLE p, DWORD x, int s, DWORD v) {
	DWORD a; FlipAddress(a, x, s, endian);
	WriteProcessMemory(p, (void*)a, &v, s, NULL);
}
xStr ME::HCRead(HANDLE p, DWORD x, int s) {
	DWORD a, v = 0; FlipAddress(a, x, s, endian);
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	xStr t; t.Printf(wxT("%X"), v);
	return t;
}
DWORD ME::HCReadH(HANDLE p, DWORD x, int s) {
	DWORD a, v = 0; FlipAddress(a, x, s, endian);
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	return v;
}
u8* ME::HCReadM8(HANDLE p, DWORD x, u64 s) {
	DWORD a; FlipAddress(a, x, s, endian); u8 *v = new u8[s];
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	return v;
}
u16* ME::HCReadM16(HANDLE p, DWORD x, u64 s) {
	DWORD a; FlipAddress(a, x, s, endian); u16 *v = new u16[s];
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	return v;
}
u32* ME::HCReadM32(HANDLE p, DWORD x, u64 s) {
	DWORD a; FlipAddress(a, x, s, endian); u32 *v = new u32[s];
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	return v;
}
u64* ME::HCReadM64(HANDLE p, DWORD x, u64 s) {
	DWORD a; FlipAddress(a, x, s, endian); u64 *v = new u64[s];
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	return v;
}
void ME::HCUse(xTID& r, HANDLE p, int j, int stop) {
	HACK* h = getIH(r);
	DWORD ram = GARS(0), xa, xv;
	u32 rv; int j2, j3 = 0; bool ut, uc = true;
	if (h->use && r.IsOk()) {
		int s, l = h->GetLen(), k; CL c; xStr t, t2;
		xTID i; xTIDV v;
		// Use CL
		if (stop > 0) { uc = false; }
		else { stop = l; }
		while (j < stop) {
			c = HCSet(h, j);
			s = (int)c.s;
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
	int i = HCCD->GetSelection();
	if (i != 2 && i != 5) {
		bool r = HCRC->GetValue();
		HCAW->Show(r);
	} HCP->Layout();
}
void ME::HCCDOnChange(wxCommandEvent& event) {
	int i = HCCD->GetSelection();
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
	int c = event.GetCol(), r = event.GetRow();
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
void ME::HCChange(int r) {
	if (r != HCRow) {
		if (r < HCRow || (r > HCRow + HCRows)) {
			xStr s = HCG->GetCellValue(r, 2);
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
void ME::HCChangeC(wxGridEvent& event) {
	int r = event.GetRow();
	HCChange(r); event.Skip();
}
void ME::HCChangeR(wxGridEvent& event) {
	int r = event.GetRow();
	HCChange(r); event.Skip();
}
