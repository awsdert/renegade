#ifndef QTAB_H
#define QTAB_H
#define BLANK(blank_argument)
#define DUMP1 BLANK(0) \
	u64 re = GARM(0), qn = 0; \
	u32 x = 0, xi = ceil(re / 100); \
	if (xi % 2 > 0) { xi++; } \
	DWORD ram = GARS(0), rj; \
	if (oldb > -1) { delete oldbuff; } \
	u64 i, l = (qs == 1) ? re : ceil(re / qs), j; \
	u64 *buff = new u64[re * 2], bsize = sizeof(u64) * (re * 2); \
	xStr s; HANDLE p = GAP(); \
	const wxChar *nofr = wxT("Results: %i"); \
	bsize = sizeof(u64) * xi;
#define DUMP2 BLANK(0) \
	for (i = 0, rj = 0, j = 0;i < l;i++,rj += qs) { \
		buff[j] = rj; x++; j++; \
		buff[j + 1] = ramBuffer[i]; x++; j++; \
		if (x == xi) { \
			qbt.Write(buff, bsize); \
			pbQAct->SetValue(rj); \
			s.Printf(nofr, i); \
			sQNo->SetLabel(s); x = 0; \
		} \
	} oldbuff = buff; oldb = 0; oldbl = re * 2; \
	if (x > 0) { \
		qbt.Write(buff, bsize); \
		pbQAct->SetValue(rj); \
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
