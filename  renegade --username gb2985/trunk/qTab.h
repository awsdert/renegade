#ifndef QTAB_H
#define QTAB_H
#define BLANK(blank_argument)
// Ignore his for now, part of an attempt to reduce repeated code
#define DUMP00 BLANK(0) \
	u32 x, xi; \
	DWORD ram = GARS(0), rj, sv; \
	u64 re = GARM(0), results = 0; \
	xStr s; HANDLE p = GAP(); \
	wxChar *nofr = wxT("Results: %i"); \
	xi = ceil((double)(re / 100)); \
	if (xi % 2 > 0) { xi++; } \
	u0 *buffer = new u0[xi], bsize; \
	bsize = sizeof(buffer);
#define DUMP01 BLANK(0) \
	for (x = 0, rj = 0, i = 0;rj < re;rj += qs, i++) { \
		sv = ramBuffer[i]; \
		buffer[x] = rj; x++; \
		buffer[x] = sv; x++; \
		results++; \
		if (x == xi) { \
			qbt.Write(buffer, bsize); \
			pbQAct->SetValue(rj); \
			delete buffer; x = 0; \
			buffer = new u0[xi]; \
			s.Printf(nofr, results); \
			sQNo->SetLabel(s); \
		} \
	} \
	if (x > 0) { \
		qbt.Write(buffer, bsize); \
		pbQAct->SetValue(rj); \
		delete buffer; \
		s.Printf(nofr, results); \
		sQNo->SetLabel(s); \
	}
#define DUMP1 BLANK(0) \
	u64 re = GARM(0), qn = 0; \
	u32 x, xi = ceil((double)(re / 100)); \
	if (xi % 2 > 0) { xi++; } \
	DWORD ram = GARS(0), rj, sv; \
	u64 *buffer = new u64[xi], bsize; \
	xStr s; HANDLE p = GAP(); \
	const wxChar *nofr = wxT("Results: %i"); \
	u64 i, l = ceil(re / qs); \
	if (qs == 1) { l = re; } \
	if (l % 2 > 0) { l++; }
#define DUMP2 BLANK(0) \
	bsize = sizeof(buffer);
#define DUMP_LOOP0 BLANK(0) \
	x = 0, rj = 0, i = 0;i < l;rj += qs, i++
#define DUMP_LOOP1 \
		sv = ramBuffer[i]; \
		buffer[x] = rj; x++; \
		buffer[x] = sv; x++;
#define DUMP_LOOP2 BLANK(0) \
			qbt.Write(buffer, bsize); \
			pbQAct->SetValue(rj); \
			delete buffer; x = 0;
#define DUMP_LOOP3 BLANK(0) \
			s.Printf(nofr, i + 1); \
			sQNo->SetLabel(s);
#define DUMP3 BLANK(0) \
	if (x > 0) { \
		qbt.Write(buffer, bsize); \
		pbQAct->SetValue(rj); \
		delete buffer; \
		s.Printf(nofr, l + 1); \
		sQNo->SetLabel(s); \
	} QCompareD->Clear(); l = qn + 1; \
	QCompareD->Append(wxT("Dump")); \
	const wxChar* fin = wxT("Search %i"); \
	for (i = 1;i < (l + 1);i++) { \
		s.Printf(fin, i); \
		QCompareD->Append(s); \
	} QCompareD->Select(l);
#endif
