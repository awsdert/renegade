/***************************************************************
 * Name:      qTab.cpp
 * Purpose:   Code for Application Frame
 * Author:    awsdert ()
 * Created:   2012-02-13
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include "qTab.h"
TESTM ME::Test(u16 mode, u64 value, u64 against, u64 to) {
	u64& v = value, a = against, t = to;
	TESTM rf = TM_FALSE, rt = TM_TRUE;
	switch(mode) {
	case TM_EQUAL: return (v == a) ? rt : rf;
	case TM_GT: return (v > a) ? rt : rf;
	case TM_GTE: return (v >= a) ? rt : rf;
	case TM_INSIDE: return (v > a && v < t) ? rt : rf;
	case TM_NOTE: return (v != a) ? rt : rf;
	case TM_LT: return (v < a) ? rt : rf;
	case TM_LTE: return (v <= a) ? rt : rf;
	case TM_OUTSITE: return (v < a || v > t) ? rt : rf;
	default: return rf; }
}
void ME::QSet(int q, int size, bool overwrite) {
	xStr d = myDiv, p = wxGetCwd(), s, t;
	//DBI* k = (DBI*)DB->GetItemData(di);
	u8 i = HDTI;
	if (i < 0) { i = PS2; }
	p << d << wxT("find");
	if (!dir.Exists(p)) { wxMkdir(p); }
	dir.Open(p);
	switch (size) {
	case 1: t = wxT("WORD"); break;
	case 2: t = wxT("DWORD"); break;
	case 3: t = wxT("QWORD"); break;
	default: t = wxT("CHAR"); }
	p << d << t;
	if (!dir.Exists(p)) { wxMkdir(p); }
	dir.Open(p);
	if (q > 0) {
		t.Printf(wxT("search%02i.hexq"), q - 1);
		s = p + d + t;
		//if (!qbf.Exists(s)) { qbf.Create(s); }
		qbf.Open(s);//qbf.Open(s);
	} t.Printf(wxT("search%02i.hexq"), q);
	s = p + d + t;
	//if (qbt.Exists(s)) { qbt.Create(s, true); }
	if (overwrite) {
		qbt.Create(s, true);
	} else { qbt.Open(s); }
}
void ME::Dump8(void) {
	int qs = sizeof(u8);
	DUMP1; u8 *ramBuffer = HCReadM8(p, ram, l); DUMP2;
}
void ME::Dump16(void) {
	int qs = sizeof(u16);
	DUMP1; u16 *ramBuffer = HCReadM16(p, ram, l); DUMP2;
}
void ME::Dump32(void) {
	int qs = sizeof(u32);
	DUMP1; u32 *ramBuffer = HCReadM32(p, ram, l); DUMP2;
}
void ME::Dump64(void) {
	int qs = sizeof(u64);
	DUMP1; u64 *ramBuffer = HCReadM64(p, ram, l); DUMP2;
}
u64* ME::OldV(int sn, bool update) {
	u64* buff;
	if (sn == oldb + 1) {
		buff = new u64[oldbl];
		for (int i = 0;i < oldbl;i++)
			{ buff[i] = oldbuff[i]; }
		return buff;
	} int vs = sizeof(u64);
	int bi, bp = 2;
	u64 bj, bl = qbf.Length() / vs;
	buff = new u64[bl];
	for (bi = 0, bj = 0;bj < bl;bj++, bi += bp) {
		qbf.Read(&buff[bj], vs); bj++;
		qbf.Read(&buff[bj], vs);
	}
	if (update) {
		if (oldb > -1) { delete oldbuff; }
		oldb = sn; oldbl = bl; oldbuff = buff;
	} return buff;
}
void ME::Find8(u8 mode) {
	HANDLE p = GAP();
	int qs = sizeof(u8);
	int qn = QCompareD->GetSelection(), i, l, x = 0, xi;
	u64 rmSize = GARM(0), rn = 0, rj, j = 0;
	DWORD ramS = GARS(0); xi = ceil(rmSize / 10);
	if (xi % 2 > 0) { xi++; }
	bool use = true; l = (qs == 1) ? rmSize : ceil(rmSize / qs);
	TESTM vMode = TM_EQUAL, tm = TM_FALSE;
	xStr s, s1, s2; //s.Printf(wxT("%d"), qn); MB(s);
	const wxChar *result = wxT("Results: %i");
	u64* ramV = OldV(qn);
	delete oldbuff;
	u8 *ramB = HCReadM8(p, ramS, rmSize);
	u64 *buff = new u64[rmSize * 2];
	pbQAct->SetRange(rmSize);
	pbQAct->SetValue(0);
	s.Printf(result, 0);
	sQNo->SetLabel(s); //int oldItem = qn - 1, nextItem;
	s2.Printf(wxT("%08X"), ramV[0]);
	int oldData = 0;
	for (rj = 0, i = 0;oldData < oldbl;rj += qs, i++) { // rj = Address, i = buffer index, qs = value size
		if (rj == ramV[oldData]) {
			oldData++;
			if (use) {
				tm = Test(vMode, ramB[i], ramV[oldData]);
			} else { tm = TM_TRUE; }
			if (tm == TM_TRUE) {
				rn++; x++; // result number
				buff[j] = rj; j++; // Set Address
				buff[j] = ramB[i]; j++;
				if (x == xi) {
					x = 0;
					s.Printf(result, rn);
					sQNo->SetLabel(s);
					pbQAct->SetValue(rj);
				} tm = TM_FALSE;
			} oldData++;
		}
	} pbQAct->SetValue(rmSize);
	s.Printf(result, rn);
	sQNo->SetLabel(s);
	QCompareD->Clear(); l = qn + 1;
	QCompareD->Append(wxT("Dump"));
	for (i = 1;i < (l + 1);i++) {
		s.Printf(wxT("Search %i"), i);
		QCompareD->Append(s);
	} QCompareD->Select(l);
	if (j > 0) {
		qbt.Write(buff, j); x = 0;
	} oldbuff = buff;
	oldb = qn; oldbl = j; xi = j;
	//qbf.Close(); qbt.Close();
	delete ramB;
	if (j > 0 && j < 100) {
		ClearGrid(RG);
		ClearGridCols(RG);
		s.Printf(wxT("%i"), j); MB(s);
		const wxChar* hexv = wxT("%02X");
		const wxChar* hexa = wxT("%08X");
		for (x = 0;x < xi;x += 2) {
			RG->AppendRows(1, false);
			RG->AppendCols(2, false);
			s.Printf(hexa, oldbuff[x]);
			RG->SetCellValue(x, 0, s);
			s.Printf(hexv, oldbuff[x + 1]);
			RG->SetCellValue(x, 1, s);
		} int c, tmp = qn - 5, k;
		if (tmp < 0) { tmp = 0; }
		for (c = 2, k = qn;k > tmp;k--, c++) {
			delete ramV;
			qbt.Close(); qbf.Close();
			QSet(k, 0, false); x = 0;
			RG->AppendCols(1, false);
			ramV = OldV(k, false);
			l = qbf.Length() / sizeof(u64);
			for (i = 0;(i < l && x < xi);i += 2) {
				if (ramV[i] == oldbuff[x]) {
					s.Printf(hexv, ramV[i + 1]);
					RG->SetCellValue(x, c, s); x+=2;
				}
			}
		}
	} delete ramV;
}
void ME::Find16(u8 mode) {}
void ME::Find32(u8 mode) {}
void ME::Find64(u8 mode) {}
void ME::bQActSOnClick(wxCommandEvent& event) {
	int ss = QSizeD->GetSelection();
	int sn = QCompareD->GetSelection();
	u64 rmSize = GARM(0);
	QSet(sn, ss);
	if (sn > 0) {
		switch (ss) {
		case 1: Find16(); break;
		case 2: Find32(); break;
		case 3: Find64(); break;
		default: Find8(); }
		qbf.Close(); qbt.Close();
	} else {
		pbQAct->SetRange(rmSize);
		switch (ss) {
		case 1: Dump16(); break;
		case 2: Dump32(); break;
		case 3: Dump64(); break;
		default: Dump8(); }
		qbt.Close();
	}
}
