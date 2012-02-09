#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
// Hook
void ME::setAWait(int i) { AW = i; }
void ME::setApps(void) {
	int i = APPG->GetNumberRows();
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
	xStr d = myDiv, p = wxGetCwd(), s;
	p << d << wxT("pf");
	dir.Open(p);
	if (!dir.Exists(p)) { wxMkdir(p); dir.Open(p); }
	s = p << d << DBFA[HDTI] << wxT(".hexpf");
	if (!pff.Open(s)) {
		pff.Create(s);
		pff.Open(s);
	}
}
void ME::PFLoad(void) {
	HDTI = PFD->GetSelection(); PFSet();
	u8 m = 0, i = 0; APPD->Clear(); PFEA.Clear();
	xStr s, t, x; xStrT st;
	RAMG->DeleteRows(0, RAMG->GetRows(), false);
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
				PFEA.Add(t);
				m = 2;
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
				RAMG->AppendRows(1);
				x = st.GetNextToken();
				RAMG->SetCellValue(i, 0, x);
				x = st.GetNextToken();
				RAMG->SetCellValue(i, 1, x);
				x = st.GetNextToken();
				RAMG->SetCellValue(i, 2, x);
				x = st.GetNextToken();
				RAMG->SetCellValue(i, 3, x);
				x.Printf(wxT("%X"), i);
				RAMG->SetRowLabelValue(i, x);
				i++; m = 1;
			} break;
		}
	} APPD->SetSelection(0);
}
