#ifndef QTAB_H
#define QTAB_H
#define DUMP1 BLANK(0) \
	const wxChar* resultText = wxT("Results: %i"); \
	HANDLE appHandle = GAP(); \
	DWORD ramAddress = GARS(0); \
	u64 rmSize = GARM(0);
#define DUMP appHandle, ramAddress, rmSize
#define DUMP2 BLANK(0) \
	u64 i = 0; \
	u64 resultNo = 0; \
	u64 xLength = (valSize == 1) ? rmSize : ceil(rmSize / valSize); \
	u64 resultTotal = ceil(xLength / 100); \
	u64 newIndex = 0; \
	u64 newSize = 0; \
	u64 address = 0; \
	if (oldSearchNo > -1) { delete oldBuff; } \
	newBuff = new u64[rmSize * 2]; \
	xStr text; \
	for ( ;i < xLength; i++, address += valSize ) \
	{ \
		resultNo++; \
		newBuff[newIndex] = address; newIndex++; \
		newBuff[newIndex] = ramBuff[i]; newIndex++; \
		newSize += 16; \
		if ( resultNo == resultTotal ) \
		{ \
			resultTotal += resultTotal; \
			pbQAct->SetValue(address); \
			text.Printf(resultText, resultNo); \
			result_S->SetLabel(text); \
		} \
	} \
	qbt.Write( newBuff, newSize ); \
	pbQAct->SetValue( address ); \
	text.Printf(resultText, resultNo); \
	result_S->SetLabel(text); \
	oldBuff = new u64[newIndex]; \
	oldLength = newIndex; \
	for (i = 0;i < newIndex;i++) { oldBuff[i] = newBuff[i]; } \
	delete newBuff; oldSearchNo = 0; \
	QCompareD->Clear(); \
	QCompareD->Append(wxT("Dump")); \
	QCompareD->Append(wxT("Search 1")); \
	QCompareD->Select(1);
#define FIND1 BLANK(0) \
	const wxChar* resultText = wxT( "Results: %i" ); \
	const wxChar* searchText = wxT( "Search %i" ); \
	HANDLE appHandle = GAP(); \
	s32 searchNo = QCompareD->GetSelection(); \
	u64 oldIndex = 0; \
	xStr text; \
	DWORD ramAddress = GARS( 0 ); \
	u64 rmSize = GARM( 0 ); \
	u64 ramIndex = 0; \
	u64 address = 0; \
	u64 resultTotal = ceil( rmSize / 10 ); \
	u64 resultNo = 0; \
	u64 newIndex = 0; \
	u64 newSize = 0; \
	u64 newBuffLength = ( varSize == 1 ) ? rmSize : ceil( rmSize / varSize ); \
	u32 valMode = GetTests(); \
	u32 ignoreMode = GetIgnore(); \
	bool testResult = 0; \
	u64* buff = OldV( searchNo ); \
	delete [] oldBuff;
#define FIND2 BLANK(0) \
	newBuff = new u64[ newBuffLength * 2 ]; \
	text.Printf( resultText, 0 ); \
	pbQAct->SetRange( rmSize ); \
	pbQAct->SetValue( 0 ); \
	result_S->SetLabel( text ); \
	u64 testRAM; \
	u64 testBuffer; \
	for (;oldIndex < oldLength;address += varSize, ramIndex++) \
	{ \
		testBuffer = buff[ oldIndex ]; \
		if ( address == testBuffer ) \
		{ \
			oldIndex++; \
			testRAM = ramBuff[ ramIndex ]; \
			if ( valMode != 0 ) \
			{ \
				testResult = Test( valMode, testRAM, buff[ oldIndex ] ); \
			} \
			else \
			{ \
				testResult = true; \
			} \
			if ( testResult && testMode != 0) \
			{ \
				testResult = Test( testMode, testRAM, value1, value2 ); \
			} \
			if ( testResult && ( ignoreMode & TM_FF ) != 0 ) \
			{ \
				testResult = Test( TM_NOTE, testRAM, ignoreF ); \
			} \
			if ( testResult && ( ignoreMode & TM_00 ) != 0 ) \
			{ \
				testResult = Test( TM_NOTE, testRAM, 0 ); \
			} \
			if ( testResult && ( ignoreMode & TM_NOTE ) != 0 ) \
			{ \
				testResult = Test( TM_NOTE, testRAM, ignoreValue ); \
			} \
			if ( testResult && ( ignoreMode & TM_INSIDE ) != 0 ) \
			{ \
				testResult = Test( TM_INSIDE, testRAM, ignoreInsideFrom, ignoreInsideTo ); \
			} \
			if ( testResult && ( ignoreMode & TM_OUTSIDE ) != 0 ) \
			{ \
				testResult = Test( TM_OUTSIDE, testRAM, ignoreOutsideFrom, ignoreOutsideTo ); \
			} \
			if ( testResult ) \
			{ \
				resultNo++; \
				newBuff[ newIndex ] = address; newIndex++; \
				newBuff[ newIndex ] = testRAM; newIndex++; \
				newSize += 16; \
				if ( resultNo == resultTotal ) \
				{ \
					resultTotal += resultTotal; \
					text.Printf( resultText, resultNo ); \
					result_S->SetLabel( text ); \
					pbQAct->SetValue( address ); \
				} \
				testResult = false; \
			} \
			oldIndex++; \
		} \
	} \
	delete [] ramBuff; \
	text.Printf( resultText, resultNo ); \
	pbQAct->SetValue( rmSize ); \
	result_S->SetLabel( text ); \
	QCompareD->Clear(); \
	u64 xLength = searchNo + 1; \
	u64 xIndex; \
	QCompareD->Append( wxT("Dump") ); \
	for (xIndex = 1; xIndex < ( xLength + 1 ); xIndex++) \
	{ \
		text.Printf( searchText, xIndex ); \
		QCompareD->Append( text ); \
	} \
	QCompareD->Select( xLength ); \
	delete [] buff; \
	oldBuff = new u64[ newIndex ]; \
	for ( ramIndex = 0; ramIndex < newIndex; ramIndex++ ) \
	{ \
		oldBuff[ ramIndex ] = newBuff[ ramIndex ]; \
	} \
	delete [] newBuff; \
	oldSearchNo = searchNo; \
	oldLength = newIndex; \
	resultTotal = newIndex; \
	if ( newIndex > 0 ) \
	{ \
		qbt.Write( oldBuff, newSize ); \
		if ( newIndex < 100 ) \
		{ \
			ClearGrid(RG); \
			ClearGridCols(RG); \
			const wxChar* ramValueText = wxT( "%02X" ); \
			const wxChar* ramAddressText = wxT( "%08X" ); \
			s32 c, tmp = searchNo - 5, k; \
			tmp = ( tmp < 0 ) ? 0 : tmp; \
			RG->AppendCols( 2, false ); \
			for ( oldIndex = 0;oldIndex < newIndex;oldIndex += 2 ) \
			{ \
				RG->AppendRows(1, false); \
				text.Printf( ramAddressText, oldBuff[ oldIndex ] ); \
				RG->SetCellValue( oldIndex, 0, text ); \
				text.Printf( ramValueText, oldBuff[ oldIndex + 1 ] ); \
				RG->SetCellValue( oldIndex, 1, text ); \
			} \
			for ( c = 2, k = searchNo;k > tmp;k--, c++ ) \
			{ \
				qbf.Close(); \
				qbt.Close(); \
				QSet( k, 0, false ); \
				RG->AppendCols( 1, false ); \
				buff = OldV( k, false ); \
				xLength = qbf.Length() / sizeof( u64 ); \
				oldIndex = 0; \
				for ( xIndex = 0;( xIndex < xLength && oldIndex < newIndex );xIndex += 2 ) \
				{ \
					if ( buff[ xIndex ] == oldBuff[ oldIndex ] ) \
					{ \
						text.Printf( ramValueText, buff[ xIndex + 1 ] ); \
						RG->SetCellValue( oldIndex, c, text ); \
						oldIndex += 2; \
					} \
				} \
				delete [] buff; \
			} \
		} \
	}
#endif
