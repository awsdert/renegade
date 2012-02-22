#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
// Hook
void ME::setAWait(s32 i) { AW = i; }
void ME::setApps(void) {
	s32 i = APPG->GetNumberRows();
	if (i > -1) {
		APPG->DeleteRows(0, i, false);
	} appLen = -1;
	AWU = wxGetLocalTimeMillis() + AWB;
#ifdef WIN32
	EnumWindows(listApps, NULL);
#endif
}
// Platform
void ME::PFSet(void) {
	xStr d = hexSlash, p = wxGetCwd(), s;
	p << d + wxT("pf");
	dir.Open(p);
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s = p + d + DBFA[HDTI] + wxT(".hexpf");
	if (!pff.Open(s)) {
		pff.Create(s);
		pff.Open(s);
	}
}
void ME::PFLoad(void) {
	HDTI = PFD->GetSelection(); PFSet();
	u8 m = 0, i = 0, ram = 0; s32 l = -1;
	APPD->Clear(); PFEA.Clear();
	xStr s, t, x; xStrT st;
	ClearGrid(RAMG);
	EMD->Clear();
	for (s = pff.GetFirstLine();!pff.Eof();s = pff.GetNextLine()) {
		switch (m) {
		case 0:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT("[")) == 0) {
				t = s.SubString(1, s.length() - 2);
				APPD->Append(t);
				m = 1;
			} break;
		case 1:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT(";")) == 0) {
				t = s.SubString(1, -1);
				appName.Add(t);
				appNum.Add(ram);
				appEnd.Add(ram);
				m = 2; l++;
			} break;
		case 2:
			t = s.SubString(0, 0);
			if (t.Cmp(wxT("[")) == 0) {
				t = s.SubString(1, s.length() - 2);
				APPD->Append(t);
				m = 1;
			} else {
				t = s.SubString(2, -1);
				st.SetString(t, wxT(";"));
				x = st.GetNextToken(); // Name
				ramName.Add(x);
				x = st.GetNextToken(); // Fixed?
				ramFixed.Add(x);
				x = st.GetNextToken(); // Address
				ramStart.Add(x);
				x = st.GetNextToken(); // Size
				ramSize.Add(x);
				ram++; appEnd[l]++;
				i++; m = 1;
			} break;
		}
	}
	pff.Close();
	APPD->SetSelection(0);
	PresetOnChange();
	DBLoad();
}
void ME::PresetOnChange(void)
{
	u8 ai = APPD->GetSelection();
	u16 i, l = appEnd[ai], j; xStr s;
	APPT->SetValue(appName[ai]);
	ClearGrid(RAMG);
	for (i = appNum[ai], j = 0;i < l;i++, j++) {
		RAMG->AppendRows(1, false);
		RAMG->SetCellValue(j, 0, ramName[i]);
		RAMG->SetCellValue(j, 1, ramFixed[i]);
		RAMG->SetCellValue(j, 2, ramStart[i]);
		RAMG->SetCellValue(j, 3, ramSize[i]);
		s.Printf(wxT("%X"), j); // ID to use in Codes
		RAMG->SetRowLabelValue(i, s);
	}
}
