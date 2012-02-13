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
		s = p << d << t;
		//if (!qbf.Exists(s)) { qbf.Create(s); }
		qbf.Create(s);//qbf.Open(s);
	} t.Printf(wxT("search%04i.hexq"), q);
	s = p << d << t;
	//if (!qbt.Exists(s)) { qbt.Create(s); }
	qbt.Create(s, true); // qbt.Open(s);
	//qbt.Clear();
}
void ME::Dump8(void) {
	u8 qs = 1, *ramBuffer;
	u32 x, xi;
	u64 *buffer, bsize, ii, ll;
	DWORD ram = GARS(0), rj, sv;
	u64 results = 0, re = GARM(0);
	xStr s; HANDLE p = GAP();
	ramBuffer = HCReadM8(p, ram, re);
	wxChar *nofr = wxT("Results: %i");
	ll = sizeof(ramBuffer);
	xi = ceil((double)(re / 100));
	if (xi % 2 > 0) { xi++; }
	buffer = new u64[xi];
	bsize = sizeof(buffer);
	for (x = 0, rj = 0, ii = 0;rj < re;rj += qs, ii++) {
		sv = ramBuffer[ii];
		buffer[x] = rj; x++;
		buffer[x] = sv; x++;
		results++;
		if (x == xi) {
			qbt.Write(buffer, bsize);
			pbQAct->SetValue(rj);
			delete buffer; x = 0;
			buffer = new u64[xi];
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
	}
}
void ME::bQActSOnClick(wxCommandEvent& event) {
	u8 ss = QSizeD->GetSelection();
	u16 sn = QCompareD->GetSelection();
	u64 re = GARM(0);
	QSet(sn, ss);
	if (sn > 0) {
		qbf.Close(); qbt.Close();
	} else {
		pbQAct->SetRange(re);
		Dump8();
		qbt.Close();
	}
}
