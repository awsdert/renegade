#ifndef QTAB_H
#define QTAB_H
#define DUMP1 BLANK(0) \
	const wxChar* resultText = wxT("Results: %i"); \
	HANDLE appHandle = GAP(); \
	DWORD ramAddress = GARS(0); \
	u64 rmSize = GARM(0);
#define DUMP2 BLANK(0) \
	u64 i = 0; \
	u64 resultNo = 0; \
	u64 xLength = (valSize == 1) ? rmSize : ceil(rmSize / valSize); \
	u64 resultTotal = ceil(xLength / 100); \
	u64 newIndex = 0; \
	u64 address = 0; \
	if (oldSearchNo > -1) { delete oldBuff; } \
	newBuff = new u64[rmSize * 2]; \
	xStr text; \
	for ( ;i < xLength; i++, address += valSize ) \
	{ \
		resultNo++; \
		newBuff[newIndex] = address; newIndex++; \
		newBuff[newIndex] = ramBuff[i]; newIndex++; \
		if ( resultNo == resultTotal ) \
		{ \
			resultTotal += resultTotal; \
			pbQAct->SetValue(address); \
			text.Printf(resultText, resultNo); \
			sQNo->SetLabel(text); \
		} \
	} \
	qbt.Write( newBuff, newIndex ); \
	pbQAct->SetValue( address ); \
	text.Printf(resultText, resultNo); \
	sQNo->SetLabel(text); \
	oldBuff = new u64[newIndex]; \
	oldLength = newIndex; \
	for (i = 0;i < newIndex;i++) { oldBuff[i] = newBuff[i]; } \
	delete newBuff; oldSearchNo = 0; \
	QCompareD->Clear(); \
	QCompareD->Append(wxT("Dump")); \
	QCompareD->Append(wxT("Search 1")); \
	QCompareD->Select(1);
#endif
