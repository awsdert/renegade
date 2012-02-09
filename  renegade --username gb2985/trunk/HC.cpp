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
u32 FlipAddress(u32 x, int s = 0, int e = 0) {
	switch (e) {
	case 0: // LITTLE_ENDIAN_SYS
	case 2: // BIG_ENDIAN
		return x;
		break;
	default: // LITTLE_ENDIAN_BIG_SYS
		switch (s) {
		case 1: return x^3;
		case 2: return x^2;
		default: return x; }
	}
}
void ME::HCWrite(HANDLE p, DWORD x, int s, u32 v) {
	u32 a = FlipAddress((u32)x, s, endian);
	WriteProcessMemory(p, (void*)a, &v, s, NULL);
}
xStr ME::HCRead(HANDLE p, DWORD x, int s) {
	u32 a = FlipAddress((u32)x, s, endian), v = 0;
	ReadProcessMemory(p, (void*)a, &v, s, NULL);
	xStr t; t.Printf(wxT("%X"), v);
	return t;
}
void ME::HCUse(xTID& r, HANDLE p, int j, int stop) {
	HACK* h = getIH(r);
	DWORD ram = getHEX(tRAMStart->GetValue());
	u32 xa, xv, rv; int j2, j3 = 0; bool ut;
	if (h->use && r.IsOk()) {
		int s, l = h->GetLen(), k; CL c; xStr t, t2;
		xTID i; xTIDV v;
		// Use CL
		if (stop < 1) { stop = l; }
		while (j < stop) {
			c = HCSet(h, j);
			s = (int)c.s;
			xa = ram + c.x;
			switch (c.t) {
			case 0x01: // Copy
				xv = ram + c.v;
				if (c.r > 0) {
					for (k = 0;k < c.r;k++) {
						t = HCRead(p, xa, s);
						HCWrite(p, xv, s, getHEX(t));
						xa += (c.j * s); xv += (c.j * s);
					}
				} else {
					t = HCRead(p, xa, s);
					HCWrite(p, xv, s, getHEX(t));
				} break;
			case 0x02: // Test
				t = HCRead(p, c.x, s);
				t2.Printf(wxT("%X"), c.v);
				rv = getHEX(t); ut = false;
				switch (c.j) {
				case 1: ut = (rv < c.v) ? true : ut; break;
				case 2: ut = (rv > c.v) ? true : ut; break;
				default: ut = (t.Cmp(t2) == 0) ? true : ut; }
				if (ut) {
					if (c.r > 0) {
						j2 = j;
						for (k = 0;k < (int)c.r;k++) {
							j3 = j; j += h->cLines[j];
						} HCUse(r, p, j2, j);
						j = j3;
					}
				} else {
					if (c.r > 0) {
						for (k = 0;k < (int)c.r;k++) {
							j3 = j; j += h->cLines[j];
						} j = j3;
					} else { j = stop; }
				} break;
			/*case 0x03: // Increment
				switch (c.s) {
				case 0x01: // u16
				case 0x02: // DWORD
				case 0x03: // u64
				default: // u8
				} break;
			case 0x04: // Decrement
				switch (c.s) {
				case 0x01: // u16
				case 0x02: // DWORD
				case 0x03: // u64
				default: // u8
				} break;
			case 0x05: // List Write
				switch (c.s) {
				case 0x01: // u16
				case 0x02: // DWORD
				case 0x03: // u64
				default: // u8
				} break;*/
			default:
				xv = c.v;
				if (c.r > 0) {
					for (k = 0;k < c.r;k++) {
						HCWrite(p, xa, s, xv);
						xa += (c.j * s); xv += c.i;
						/*t.Printf(wxT("%x, %x, %x"), s, c.j, (c.j * s));
						t2 = HT->GetItemText(r);
						wxMessageBox(t, t2);*/
					}
				} else { HCWrite(p, xa, s, xv); }
			} j += h->cLines[j];
		}
		// Recurse through children
		i = HT->GetFirstChild(r, v);
		while (i.IsOk()) {
			HCUse(i, p);
			i = HT->GetNextChild(r, v);
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
