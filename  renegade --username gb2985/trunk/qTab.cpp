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
bool ME::Test(int mode, u64 value, u64 against) {
	u64 v = value, a = against;
	switch (mode) {
	case TM_EQUAL: return (v == a) ? true : false;
	case TM_LT: return (v < a) ? true : false;
	case TM_GT: return (v > a) ? true : false;
	case TM_LTEQUAL: return (v <= a) ? true : false;
	case TM_GTEQUAL: return (v >= a) ? true : false;
	case TM_NOTEQUAL: return (v != a) ? true : false;
	default: return false; }
}
bool ME::Test(int mode, u64 value, u64 from, u64 to) {
	u64 v = value, f = from, t = to;
	switch (mode) {
	case TM_INSIDE: return (v > f && v < t) ? true : false;
	case TM_OUTSITE: return (v < f || v > t) ? true : false;
	default: return Test(mode, v, f); }
}
void ME::QSet(int q, int size) {
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
	qbt.Create(s, true); // qbt.Open(s);
	//qbt.Clear();
}
void ME::Dump8(void) {
	//typedef u64 u0;
	u8 qs = 1; DUMP1;
	//DUMP00;
	//u8 *ramBuffer = HCReadM64(p, ram, re);
	//DUMP01;
	/*/
	u64 i, l = sizeof(ramBuffer) / sizeof(u0);
	for (x = 0, rj = 0, i = 0;i < l;rj += qs, i++) {
		sv = ramBuffer[i];
		buffer[x] = rj; x++;
		buffer[x] = sv; x++;
		results++;
		if (x == xi) {
			qbt.Write(buffer, bsize);
			pbQAct->SetValue(rj);
			delete buffer; x = 0;
			buffer = new u0[xi];
			s.Printf(nofr, results);
			sQNo->SetLabel(s);
		}
	}
	if (x > 0) {
		qbt.Write(buffer, bsize);
		pbQAct->SetValue(rj);
		delete buffer;
		s.Printf(nofr, results);
		sQNo->SetLabel(s);
	}//*/
	u8 *ramBuffer = HCReadM8(p, ram, l); DUMP2;
	for (DUMP_LOOP0) {
		DUMP_LOOP1;
		if (x == xi) {
			DUMP_LOOP2;
			buffer = new u64[xi];
			DUMP_LOOP3;
		}
	} DUMP3;//*/
}
void ME::Dump16(void) {
	u8 qs = 2; DUMP1;
	u16 *ramBuffer = HCReadM16(p, ram, l); DUMP2;
	for (DUMP_LOOP0) {
		DUMP_LOOP1;
		if (x == xi) {
			DUMP_LOOP2;
			buffer = new u64[xi];
			DUMP_LOOP3;
		}
	} DUMP3;
}
void ME::Dump32(void) {
	u8 qs = 4; DUMP1;
	u32 *ramBuffer = HCReadM32(p, ram, l); DUMP2;
	for (DUMP_LOOP0) {
		DUMP_LOOP1;
		if (x == xi) {
			DUMP_LOOP2;
			buffer = new u64[xi];
			DUMP_LOOP3;
		}
	} DUMP3;
}
void ME::Dump64(void) {
	u8 qs = 8;
	DUMP1;
	u64 *ramBuffer = HCReadM64(p, ram, l); DUMP2;
	for (DUMP_LOOP0) {
		DUMP_LOOP1;
		if (x == xi) {
			DUMP_LOOP2;
			buffer = new u64[xi];
			DUMP_LOOP3;
		}
	} DUMP3;//*/
}
u64* ME::OldA(int sn) {
	u64 len = qbf.Length();
	int vs = sizeof(u64);
	int i = 0, bi, bl = len / vs, bp = sn + 1;
	int l = bl / bp;
	//xStr s; s.Printf(wxT("%d - %d - %d"), bl, l, bp); MB(s);
	u64 *buff = new u64[bl];
	u64 *buffer = new u64[l];
	for (bi = 0;bi < bl;bi++) {
		qbf.Read(&buff[bi], vs);
	}
	for (bi = 0;bi < bl;bi += bp) {
		buffer[i] = buff[bi]; i++;
		//s.Printf(wxT("%d - %d"), bi, i); MB(s);
	} //s.Printf(wxT("%08X"), buffer[1]); MB(s);
	delete buff; return buffer;
}
u8* ME::OldV8(int sn) {
	u64 len = qbf.Length();
	int vs = sizeof(u64);
	int i = 0, j, bi, bl = len / vs, bp = sn + 1;
	int l = bl - (bl / bp), js = bp - 1;
	//xStr s, t; s.Printf(wxT("%d - %d"), bl, l); MB(s);
	u64 *buff = new u64[bl];
	u8 *buffer = new u8[l];
	for (bi = 0;bi < bl;bi++) {
		qbf.Read(&buff[bi], vs);
	}
	for (bi = 0;bi < bl;bi += bp) {
		for (j = js;j > 0;j--) {
			buffer[i] = buff[bi + j]; i++;
			//t.Printf(wxT("\n%d"), j);
			//s << t;
		} // MB(s); s.Clear();
	} //s.Printf(wxT("%08X"), buffer[1]); MB(s);
	delete buff; return buffer;
}
void ME::Find8(u8 mode) {
	HANDLE p = GAP();
	int qs = 1;
	int qn = QCompareD->GetSelection(), i, l, k = 0, m = 0, x = 0, xi;
	u64 re = GARM(0), rn = 0, rj;
	DWORD ramS = GARS(0); xi = ceil(re / 100);
	if (xi % 2 > 0) { xi++; }
	bool use; l = ceil(re / qs);
	xStr s, s1, s2; //s.Printf(wxT("%d"), qn); MB(s);
	const wxChar *result = wxT("Results: %i");
	u64 *ramA = OldA(qn);
	u8 *ramO = OldV8(qn);
	u8 *ramB = HCReadM8(p, ramS, re);
	u64 *buffer = new u64[xi], bsize; bsize = sizeof(buffer);
	pbQAct->SetRange(re);
	pbQAct->SetValue(0);
	s.Printf(result, 0);
	sQNo->SetLabel(s);
	for (rj = 0, i = 0;i < l;rj += qs, i++) { // rj = Address, i = buffer index, qs = value size
		s1.Printf(wxT("%08X"), rj);
		s2.Printf(wxT("%08X"), ramA[k]);
		if (s1.Cmp(s2) == 0) { //rj == ramA[k]) { // k = Old address index
			use = Test(0, ramB[i], ramO[(m + qn) - 1]); // m = Old value index
			if (use) {
				rn++; // result number
				buffer[x] = rj; x++; // Set Address
				for (;m < qn;m++) { // Add old values
					buffer[x] = ramO[m]; x++;
				} // Add new value
				buffer[x] = ramB[i]; x++;
				if (x == xi) {
					qbt.Write(buffer, bsize);
					x = 0; delete buffer;
					buffer = new u64[xi];
					s.Printf(result, rn);
					sQNo->SetLabel(s);
					pbQAct->SetValue(rj);
				}
			} else { m += qn; } k++;
		}
	} pbQAct->SetValue(re);
	s.Printf(result, rn);
	sQNo->SetLabel(s);
	QCompareD->Clear(); l = qn + 1;
	QCompareD->Append(wxT("Dump"));
	for (i = 1;i < (l + 1);i++) {
		s.Printf(wxT("Search %i"), i);
		QCompareD->Append(s);
	} QCompareD->Select(l);
	if (x > 0) {
		qbt.Write(buffer, bsize); x = 0;
	} delete ramA; delete buffer; qn++;
	qbf.Close(); qbt.Close();
	QSet(qn, 0);
	ramA = OldA(qn); xi = sizeof(ramA) / 8;
	if (xi < 100) {
		ClearGrid(RG);
		delete ramO;
		ramO = OldV8(qn);
		const wxChar* hexv = wxT("%02X");
		for (x = 0;x < xi;x++) {
			RG->AppendRows(1, false);
			s.Printf(hexv, ramA[x]);
			RG->SetCellValue(x, 0, s);
		} int c;
		for (c = 1, i = 0;c < qn;c++, i++) {
			for (x = 0;x < xi;x++) {
				s.Printf(hexv, ramO[i + x]);
				RG->SetCellValue(x, c, s);
			}
		}
	} delete ramO;
}
void ME::Find16(u8 mode) {}
void ME::Find32(u8 mode) {}
void ME::Find64(u8 mode) {}
void ME::bQActSOnClick(wxCommandEvent& event) {
	u8 ss = QSizeD->GetSelection();
	u16 sn = QCompareD->GetSelection();
	u64 re = GARM(0);
	QSet(sn, ss);
	if (sn > 0) {
		switch (ss) {
		case 1: Find16(); break;
		case 2: Find32(); break;
		case 3: Find64(); break;
		default: Find8(); }
		qbf.Close(); qbt.Close();
	} else {
		pbQAct->SetRange(re);
		switch (ss) {
		case 1: Dump16(); break;
		case 2: Dump32(); break;
		case 3: Dump64(); break;
		default: Dump8(); }
		qbt.Close();
	}
}
