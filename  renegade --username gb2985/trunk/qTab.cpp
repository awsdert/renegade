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
bool ME::Test(u8 mode, u64 value, u64 against) {
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
bool ME::Test(u8 mode, u64 value, u64 from, u64 to) {
	u64 v = value, f = from, t = to;
	switch (mode) {
	case TM_INSIDE: return (v > f && v < t) ? true : false;
	case TM_OUTSITE: return (v < f || v > t) ? true : false;
	default: return Test(mode, v, f); }
}
void ME::QSet(u16 q, u8 size) {
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
		t.Printf(wxT("search%04i.hexq"), q - 1);
		s = p + d + t;
		//if (!qbf.Exists(s)) { qbf.Create(s); }
		qbf.Open(s);//qbf.Open(s);
	} t.Printf(wxT("search%04i.hexq"), q);
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
u64* ME::OldA(u8 sn) {
	u64 rn = (sn + 2), i, l = qbf.Length(), rl, rj;
	rl = ceil(l / rn); u8 vs = sizeof(u64);
	u64* buffer = new u64[rl];
	for (i = 0;i < rl;i++) {
		rj = i * rn;
		qbf.Seek(rj);
		qbf.Read(&buffer[i], vs);
	} return buffer;
}
u8* ME::OldV8(u8 sn) {
	u64 rn = (sn + 2), i, l = qbf.Length(), rl, rj;
	rl = l / rn; u8 vs = sizeof(u64);
	u8* buffer = new u8[rl];
	for (i = 0;i < rl;i++) {
		rj = (i * rn) + vs;
		qbf.Seek(rj);
		qbf.Read(&buffer[i], vs);
	} return buffer;
}
void ME::Find8(u8 mode) {
	HANDLE p = GAP();
	u8 qs = 1, qn = QCompareD->GetSelection();
	u64 re = GARM(0), i, k = 0, l, rn, rj, x = 0, xi;
	DWORD ramS = GARS(0); xi = ceil(re / 100);
	if (xi % 2 > 0) { xi++; }
	bool use; l = ceil(re / qs);
	u64 *ramA = OldA(qn);
	u8 *ramO = OldV8(qn);
	u8 *ramB = HCReadM8(p, ramS, re);
	xStr s; s.Printf(wxT("%d"), ramA[1]); MB(s);
	u64 *buffer = new u64[xi], bsize; bsize = sizeof(buffer);
	pbQAct->SetRange(re);
	for (rj = 0, i = 0;i < l;rj += qs, i++) {
		if (rj == ramA[k]) {
			use = Test(0, ramB[i], ramO[k]);
			if (use) {
				rn++;
				buffer[x] = rj; x++;
				buffer[x] = ramB[i]; x++;
				if (x == xi) {
					qbt.Write(buffer, bsize);
					pbQAct->SetValue(rj);
					x = 0; delete buffer;
					buffer = new u64[xi];
				}
			} k++;
		}
	} QCompareD->Clear(); l = qn + 1;
	QCompareD->Append(wxT("Dump"));
	for (i = 1;i < (l + 1);i++) {
		s.Printf(wxT("Search %i"), i);
		QCompareD->Append(s);
	} QCompareD->Select(l);
	if (x > 0) {
		qbt.Write(buffer, bsize);
		pbQAct->SetValue(rj);
		x = 0;
	} delete ramA; delete buffer;
	ramA = OldA(l); xi = sizeof(ramA) / 8;
	if (xi < 100) {
		ClearGrid(RG);
		const wxChar* hexv = wxT("%02X");
		for (x = 0;x < xi;x++) {
			RG->AppendRows(1, false);
			s.Printf(hexv, ramA[x]);
			RG->SetCellValue(x, 0, s);
		}
		for (i = 1;i < l;i++) {
			delete ramO;
			ramO = OldV8(i);
			for (x = 0;x < xi;x++) {
				s.Printf(hexv, ramO[x]);
				RG->SetCellValue(x, i, s);
			}
		}
	}
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
