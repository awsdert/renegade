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
	u64 v = value, a = against, t = to;
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
	const wxChar* resultText = wxT("Results: %i");
	int valSize = sizeof(u8);
	HANDLE appHandle = GAP();
	// RAM
	DWORD ramAddress = GARS(0);
	u64 rmSize = GARM(0);
	u8* ramBuff = HCReadM8(appHandle, ramAddress, rmSize);
	u64 i = 0;
	// Results
	u64 resultNo = 0;
	u64 xLength = (valSize == 1) ? rmSize : ceil(rmSize / valSize);
	u64 resultTotal = ceil(xLength / 100);
	// Code
	u64 newIndex = 0;
	u64 address = 0;
	if (oldSearchNo > -1) { delete oldBuff; }
	newBuff = new u64[rmSize * 2];
	xStr text;
	for ( ;i < xLength; i++, address += valSize )
	{
		resultNo++;
		newBuff[newIndex] = address; newIndex++;
		newBuff[newIndex] = ramBuff[i]; newIndex++;
		if ( resultNo == resultTotal )
		{
			resultTotal += resultTotal;
			pbQAct->SetValue(address);
			text.Printf(resultText, resultNo);
			sQNo->SetLabel(text);
		}
	}
	qbt.Write( newBuff, newIndex );
	pbQAct->SetValue( address );
	text.Printf(resultText, resultNo);
	sQNo->SetLabel(text);
	oldBuff = new u64[newIndex];
	oldLength = newIndex;
	for (i = 0;i < newIndex;i++) { oldBuff[i] = newBuff[i]; }
	delete newBuff; oldSearchNo = 0;
	QCompareD->Clear();
	QCompareD->Append(wxT("Dump"));
	QCompareD->Append(wxT("Search 1"));
	QCompareD->Select(1);
}
void ME::Dump16(void) {
	int valSize = sizeof(u16);
	DUMP1; u16* ramBuff = HCReadM16(appHandle, ramAddress, rmSize); DUMP2;
}
void ME::Dump32(void) {
	int valSize = sizeof(u32);
	DUMP1; u32* ramBuff = HCReadM32(appHandle, ramAddress, rmSize); DUMP2;
}
void ME::Dump64(void) {
	int valSize = sizeof(u64);
	DUMP1; u64* ramBuff = HCReadM64(appHandle, ramAddress, rmSize); DUMP2;
}
u64* ME::OldV(int sn, bool update) {
	u64* buff; u64 i;
	if (sn == oldSearchNo + 1) {
		buff = new u64[oldLength];
		for (i = 0;i < oldLength;i++)
			{ buff[i] = oldBuff[i]; }
		return buff;
	} int vs = sizeof(u64);
	int bp = 2; u64 len = qbf.Length();
	u64 bj, bl = len / vs;
	buff = new u64[bl];
	for (i = 0, bj = 0;bj < bl;bj++, i += bp) {
		qbf.Read(&buff[bj], vs); bj++;
		qbf.Read(&buff[bj], vs);
	}
	if (update) {
		if (oldSearchNo > -1) { delete oldBuff; }
		oldSearchNo = sn; oldLength = bl; oldBuff = buff;
	} return buff;
}
void ME::Find8(u8 mode) {
	int varSize = sizeof( u8 );
	const wxChar* resultText = wxT( "Results: %i" );
	const wxChar* searchText = wxT( "Search %i" );
	HANDLE appHandle = GAP();
	int searchNo = QCompareD->GetSelection();
	u64 oldIndex = 0;
	xStr text;
	// RAM
	DWORD ramAddress = GARS( 0 ); // Number indicates which RAM, implimented later
	u64 rmSize = GARM( 0 );
	u64 ramIndex = 0;
	u64 address = 0;
	// Result
	u64 resultTotal = ceil( rmSize / 10 );
	u64 resultNo = 0;
	// New Buffer
	u64 newIndex = 0;
	u64 newBuffLength = ( varSize == 1 ) ? rmSize : ceil(rmSize / varSize);
	// Test modes
	TESTM vMode = TM_EQUAL; // Will impliment control usage later
	TESTM testResult = TM_FALSE;
	// Buffers
	u64* buff = OldV(searchNo, false);
	delete oldBuff;
	u8* ramBuff = HCReadM8( appHandle, ramAddress, rmSize );
	newBuff = new u64[ newBuffLength * 2 ];
	// Code
	text.Printf( resultText, 0 );
	pbQAct->SetRange( rmSize );
	pbQAct->SetValue( 0 );
	sQNo->SetLabel( text );
	u64 testRAM, testBuffer;
	for (;oldIndex < oldLength;address += varSize, ramIndex++)
	{
		testBuffer = buff[oldIndex];
		if (address == testBuffer )
		{
			oldIndex++;
			testRAM = ramBuff[ramIndex];
			if (vMode != TM_FALSE)
			{
				testResult = Test(vMode, ramBuff[ramIndex], buff[oldIndex]);
				testResult = (testResult) ? Test(TM_NOTE, ramBuff[ramIndex], 0xFF) : testResult;
				testResult = (testResult) ? Test(TM_NOTE, ramBuff[ramIndex], 0) : testResult;
			}
			else
			{
				testResult = TM_TRUE;
			}
			if (testResult)
			{
				resultNo++;
				newBuff[newIndex] = address; newIndex++;
				newBuff[newIndex] = ramBuff[ ramIndex ]; newIndex++;
				if ( resultNo == resultTotal )
				{
					resultTotal += resultTotal;
					text.Printf( resultText, resultNo );
					sQNo->SetLabel( text );
					pbQAct->SetValue( address );
					//s.Printf(wxT("%02X, %d\n%02X, %d"), ramB[i], i, ramV[oldData], oldData); MB(s);
				}
				testResult = TM_FALSE;
			}
			oldIndex++;
		}
	}
	delete ramBuff;
	text.Printf(resultText, resultNo);
	pbQAct->SetValue(rmSize);
	sQNo->SetLabel(text);
	QCompareD->Clear();
	u64 xLength = searchNo + 1;
	u64 xIndex;
	QCompareD->Append(wxT("Dump"));
	for (xIndex = 1;xIndex < (xLength + 1);xIndex++)
	{
		text.Printf(searchText, xIndex);
		QCompareD->Append(text);
	}
	QCompareD->Select( xLength );
	delete buff;
	oldBuff = new u64[ newIndex ];
	for (ramIndex = 0;ramIndex < newIndex;ramIndex++)
	{
		oldBuff[ramIndex] = newBuff[ramIndex];
	}
	delete newBuff;
	oldSearchNo = searchNo;
	oldLength = newIndex;
	resultTotal = newIndex;
	if ( newIndex > 0 )
	{
		qbt.Write( oldBuff, newIndex );
		if ( newIndex < 100 )
		{
			ClearGrid(RG);
			ClearGridCols(RG);
			const wxChar* ramValueText = wxT( "%02X" );
			const wxChar* ramAddressText = wxT( "%08X" );
			int c, tmp = searchNo - 5, k;
			tmp = ( tmp < 0 ) ? 0 : tmp;
			RG->AppendCols( 2, false );
			for ( oldIndex = 0;oldIndex < newIndex;oldIndex += 2 )
			{
				RG->AppendRows(1, false);
				text.Printf( ramAddressText, oldBuff[ oldIndex ] );
				RG->SetCellValue( oldIndex, 0, text );
				text.Printf( ramValueText, oldBuff[ oldIndex + 1 ] );
				RG->SetCellValue( oldIndex, 1, text );
			}
			for ( c = 2, k = searchNo;k > tmp;k--, c++ )
			{
				qbf.Close();
				qbt.Close();
				QSet( k, 0, false );
				RG->AppendCols( 1, false );
				buff = OldV( k, false );
				xLength = qbf.Length() / sizeof( u64 );
				oldIndex = 0;
				for ( xIndex = 0;( xIndex < xLength && oldIndex < newIndex );xIndex += 2 )
				{
					if ( buff[ xIndex ] == oldBuff[ oldIndex ] )
					{
						text.Printf( ramValueText, buff[ xIndex + 1 ] );
						RG->SetCellValue( oldIndex, c, text );
						oldIndex += 2;
					}
				}
				delete buff;
			}
		}
	}
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
