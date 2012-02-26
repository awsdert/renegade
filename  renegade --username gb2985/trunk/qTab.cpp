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
bool ME::Test(u32 mode, u64 value, u64 against, u64 to)
{
	u32 m = mode;
	u64 v = value, a = against, t = to;
	bool r = false, rf = false, rt = true;
	/*xStr text;
	text.Printf(wxT("%X\n%llX\n%llX\n%llX"), mode, value, against, to);
	MB(text);*/
	if ( (m & TM_EQUAL) != 0 )
	{
		r = (v == a) ? rt : rf;
		if (r && (m & TM_GT) != 0) { r = (v > a) ? rt : rf; }
		if (r && (m & TM_GTE) != 0) { r = (v >= a) ? rt : rf; }
		if (r && (m & TM_INSIDE) != 0) { r = (v > a && v < t) ? rt : rf; }
		if (r && (m & TM_NOTE) != 0) { r = (v != a) ? rt : rf; }
		if (r && (m & TM_LT) != 0) { r = (v < a) ? rt : rf; }
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ( (m & TM_GT) != 0 )
	{
		r = (v > a) ? rt : rf;
		if (r && (m & TM_GTE) != 0) { r = (v >= a) ? rt : rf; }
		if (r && (m & TM_INSIDE) != 0) { r = (v > a && v < t) ? rt : rf; }
		if (r && (m & TM_NOTE) != 0) { r = (v != a) ? rt : rf; }
		if (r && (m & TM_LT) != 0) { r = (v < a) ? rt : rf; }
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ( (m & TM_GTE) != 0 )
	{
		r = (v >= a) ? rt : rf;
		if (r && (m & TM_INSIDE) != 0) { r = (v > a && v < t) ? rt : rf; }
		if (r && (m & TM_NOTE) != 0) { r = (v != a) ? rt : rf; }
		if (r && (m & TM_LT) != 0) { r = (v < a) ? rt : rf; }
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if (r && (m & TM_INSIDE) != 0)
	{
		r = (v > a && v < t) ? rt : rf;
		if (r && (m & TM_NOTE) != 0) { r = (v != a) ? rt : rf; }
		if (r && (m & TM_LT) != 0) { r = (v < a) ? rt : rf; }
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ( (m & TM_NOTE) != 0 )
	{
		r = (v != a) ? rt : rf;
		if (r && (m & TM_LT) != 0) { r = (v < a) ? rt : rf; }
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ((m & TM_LT) != 0)
	{
		r = (v < a) ? rt : rf;
		if (r && (m & TM_LTE) != 0) { r = (v <= a) ? rt : rf; }
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ((m & TM_LTE) != 0)
	{
		r = (v <= a) ? rt : rf;
		if (r && (m & TM_OUTSIDE) != 0) { r = (v < a || v > t) ? rt : rf; }
	}
	else if ( (m & TM_OUTSIDE) != 0 )
	{
		r = (v < a || v > t) ? rt : rf;
	}
	return r;
}
void ME::QSet(s32 searchNo, s32 size, bool overwrite)
{
	xStr dirPath = wxGetCwd(), filePath, tmp;
	//DBI* k = (DBI*)DB->GetItemData(di);
	dirPath += hexSlash + wxT( "find" );
	if ( !dir.Exists( dirPath ) )
	{
		wxMkdir( dirPath );
	}
	dir.Open( dirPath );
	switch ( size )
	{
		case 1: tmp = wxT( "WORD" ); break;
		case 2: tmp = wxT( "DWORD" ); break;
		case 3: tmp = wxT( "QWORD" ); break;
		default: tmp = wxT( "CHAR" );
	}
	dirPath += hexSlash + tmp;
	if ( !dir.Exists( dirPath ) )
	{
		wxMkdir( dirPath );
	}
	dir.Open( dirPath );
	dirPath << hexSlash;
	if (searchNo > 0)
	{
		tmp.Printf( wxT( "search%02i.hexq" ), searchNo - 1);
		filePath = dirPath + tmp;
		qbf.Open( filePath, qbf.read_write );
	}
	tmp.Printf( wxT( "search%02i.hexq" ), searchNo);
	filePath = dirPath + tmp;
	if (overwrite || !qbt.Exists( filePath ) ) {
		qbt.Create( filePath, true );
	}
	qbt.Open(filePath, qbt.read_write);
}
u64* ME::OldV(s32 searchNo, bool update)
{
	u64* buff;
	u64 i;
	if ( searchNo == oldSearchNo + 1 )
	{
		buff = new u64[oldLength];
		for (i = 0;i < oldLength;i++)
		{
			buff[i] = oldBuff[i];
		}
		return buff;
	}
	s32 valSize = 8;
	/*s32 indexInc = 2;
	u64 address;//*/
	u64 len = qbf.Length();
	u64 buffLength = len / valSize;
	buff = new u64[ buffLength ];
	qbf.Read( buff, len );
	if ( update )
	{
		delete [] oldBuff;
		oldSearchNo = searchNo;
		oldBuff = new u64[ buffLength ];
		for ( i = 0; i < buffLength; i++ )
		{
			oldBuff[ i ] = buff [ i ];
		}
		oldLength = i;
	} return buff;
}
void ME::Dump8( void )
{
	const wxChar* resultText = wxT( "Results: %i" );
	s32 valSize = 1;
	HANDLE appHandle = GAP();
	// RAM
	DWORD ramAddress = GARS( 0 );
	u64 rmSize = GARM( 0 );
	u8* ramBuff = HCReadM8( DUMP );
	u64 i = 0;
	// Results
	u64 resultNo = 0;
	u64 xLength = ( valSize == 1 ) ? rmSize : ceil(rmSize / valSize);
	u64 resultTotal = ceil( xLength / 100 );
	// Code
	u64 newIndex = 0;
	u64 newSize = 0;
	u64 address = 0;
	if ( oldSearchNo > -1 )
	{
		delete [] oldBuff;
	}
	newBuff = new u64[ rmSize * 2 ];
	xStr text;
	for ( ; i < xLength; i++, address += valSize )
	{
		resultNo++;
		newBuff[ newIndex ] = address; newIndex++;
		newBuff[ newIndex ] = ramBuff[ i ]; newIndex++;
		newSize += 16;
		if ( resultNo == resultTotal )
		{
			resultTotal += resultTotal;
			pbQAct->SetValue( address );
			text.Printf( resultText, resultNo );
			result_S->SetLabel( text );
		}
	}
	qbt.Write( newBuff, newSize );
	pbQAct->SetValue( address );
	text.Printf(resultText, resultNo);
	result_S->SetLabel(text);
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
	s32 valSize = sizeof(u16);
	DUMP1;
	u16* ramBuff = HCReadM16( DUMP );
	DUMP2;
}
void ME::Dump32(void) {
	s32 valSize = sizeof(u32);
	DUMP1;
	u32* ramBuff = HCReadM32( DUMP );
	DUMP2;
}
void ME::Dump64(void) {
	s32 valSize = sizeof( u64 );
	DUMP1;
	u64* ramBuff = HCReadM64( DUMP );
	DUMP2;
}
u32 ME::GetTests( void )
{
	u32 valMode = 0;
	switch (useTest_D->GetSelection())
	{
		case TMU_EQUAL: valMode = TM_EQUAL; break;
		case TMU_NOTE: valMode = TM_NOTE; break;
		case TMU_GT: valMode = TM_GT; break;
		case TMU_GTE: valMode = TM_GTE; break;
		case TMU_LT: valMode = TM_LT; break;
		case TMU_LTE: valMode = TM_LTE; break;
	}
	return valMode;
}
u32 ME::GetRest(void)
{
	u32 testValues = 0;
	value1 = getHEX(value1_TXT->GetValue());
	value2 = getHEX(value2_TXT->GetValue());
	switch (useTest_D->GetSelection())
	{
		case TMU_VEQUAL: testValues = TM_EQUAL; break;
		case TMU_VNOTE: testValues = TM_NOTE; break;
		case TMU_VGT: testValues = TM_GT; break;
		case TMU_VGTE: testValues = TM_GTE; break;
		case TMU_VLT: testValues = TM_LT; break;
		case TMU_VLTE: testValues = TM_LTE; break;
		case TMU_INSIDE: testValues = TM_INSIDE; break;
		case TMU_OUTSIDE: testValues = TM_OUTSIDE; break;
	}
	return testValues;
}
u32 ME::GetIgnore(void)
{
	u32 ignoreValues = 0;
	if (ignore0_CB->GetValue()) { ignoreValues += TM_00; }
	if (ignoreF_CB->GetValue())
	{
		ignoreValues += TM_FF;
		switch ( searchSize_D->GetSelection() )
		{
			case 1: ignoreF = 0xFFFF; break;
			case 2: ignoreF = 0xFFFFFFFF; break;
			case 3: ignoreF = 0 - 1; break;
			default: ignoreF = 0xFF;
		}
	}
	if ( ignoreValue_CB->GetValue() )
	{
		ignoreValues += TM_NOTE;
		ignoreValue = getHEX( ignoreValue_TXT->GetValue() );
	}
	if ( ignoreInside_CB->GetValue() )
	{
		ignoreValues += TM_INSIDE;
		ignoreInsideFrom = getHEX( ignoreInsideFrom_TXT->GetValue() );
		ignoreInsideTo = getHEX( ignoreInsideTo_TXT->GetValue() );
	}
	if ( ignoreOutside_CB->GetValue() )
	{
		ignoreValues += TM_OUTSIDE;
		ignoreOutsideFrom = getHEX( ignoreOutsideFrom_TXT->GetValue() );
		ignoreOutsideTo = getHEX( ignoreOutsideTo_TXT->GetValue() );
	}
	return ignoreValues;
}
void ME::showResults( s32 searchNo, u32 valSize )
{
	ClearGrid(RG);
	ClearGridCols(RG);
	wxString text, tmp;
	tmp.Printf( wxT( "%%0%iX" ), valSize * 2 );
	const wxChar* ramValueText = tmp.data();
	const wxChar* ramAddressText = wxT( "%08X" );
	const wxChar* searchNoText = wxT( "Search %u" );
	s32 c, until = searchNo - 5, k;
	u64 oldIndex = 0, xIndex, xLength, row = 0;
	until = ( until < 0 ) ? 0 : until;
	RG->AppendCols( 2, false );
	text.Printf( searchNoText, searchNo );
	RG->SetColLabelValue( 0, wxT( "Address" ) );
	RG->SetColLabelValue( 1, text );
	for ( ; oldIndex < oldLength; oldIndex += 2, row++ )
	{
		RG->AppendRows(1, false);
		text.Printf( ramAddressText, oldBuff[ oldIndex ] );
		RG->SetCellValue( row, 0, text );
		text.Printf( ramValueText, oldBuff[ oldIndex + 1 ] );
		RG->SetCellValue( row, 1, text );
	}
	u64* buff;
	for ( c = 2, k = searchNo;k > until;k--, c++ )
	{
		qbf.Close();
		qbt.Close();
		QSet( k, 0, false );
		buff = OldV( k, false );
		RG->AppendCols( 1, false );
		text.Printf( searchNoText, k );
		RG->SetColLabelValue( c, text );
		xLength = qbf.Length() / sizeof( u64 );
		oldIndex = 0;
		xIndex = 0;
		row = 0;
		for ( ; (xIndex < xLength && oldIndex < oldLength) ;  )
		{
			if ( buff[ xIndex ] == oldBuff[ oldIndex ] )
			{
				text.Printf( ramValueText, buff[ (xIndex + 1) ] );
				RG->SetCellValue( row, c, text );
				oldIndex += 2;
				row++;
			}
			xIndex += 2;
		}
		delete [] buff;
	}
}
void ME::Find8( u32 mode )
{
	u32 valSize = 1;
	// All changes here onwards must be ported into the FIND definitions once stable
	const wxChar* resultText = wxT( "Results: %i" );
	const wxChar* searchText = wxT( "Search %i" );
	HANDLE appHandle = GAP();
	s32 searchNo = QCompareD->GetSelection();
	u64 oldIndex = 0;
	xStr text;//, title;
	// RAM
	u64 ramAddress = GARS( 0 ); // Number indicates which RAM, implimented later
	u64 rmSize = GARM( 0 );
	u64 ramIndex = 0;
	u64 address = 0;
	// Result
	u64 resultTotal = ceil( rmSize / 10 );
	u64 resultNo = 0;
	// New Buffer
	u64 newIndex = 0;
	u64 newSize = 0;
	u64 newBuffLength = ( valSize == 1 ) ? rmSize : ceil( rmSize / valSize );
	// Test modes
	u32 valMode = GetTests();
	u32 testMode = GetRest();
	u32 ignoreMode = GetIgnore();
	bool testResult = 0;
	// Buffers
	u64* buff = OldV( searchNo );
	delete [] oldBuff;
	u8* ramBuff = HCReadM8( appHandle, ramAddress, rmSize );
	newBuff = new u64[ newBuffLength * 2 ];
	// Code
	text.Printf( resultText, 0 );
	pbQAct->SetRange( rmSize );
	pbQAct->SetValue( 0 );
	result_S->SetLabel( text );
	u64 testRAM;
	text.Printf( wxT( "%%0%iX" ), valSize * 2 );
	//const wxChar* logAText = wxT( "%02X" );
	//const wxChar* logVText = text.data();
	for (;oldIndex < oldLength;address += valSize, ramIndex++)
	{
		if ( address == buff[ oldIndex ] )
		{
			oldIndex++;
			testRAM = ramBuff[ ramIndex ];
			if ( valMode != 0 )
			{
				testResult = Test( valMode, testRAM, buff[ oldIndex ] );
			}
			else
			{
				testResult = true;
			}
			if ( testResult && testMode != 0)
			{
				testResult = Test( testMode, testRAM, value1, value2 );
			}
			if ( testResult && ( ignoreMode & TM_FF ) != 0 )
			{
				testResult = Test( TM_NOTE, testRAM, ignoreF );
			}
			if ( testResult && ( ignoreMode & TM_00 ) != 0 )
			{
				testResult = Test( TM_NOTE, testRAM, 0 );
			}
			if ( testResult && ( ignoreMode & TM_NOTE ) != 0 )
			{
				testResult = Test( TM_NOTE, testRAM, ignoreValue );
			}
			if ( testResult && ( ignoreMode & TM_INSIDE ) != 0 )
			{
				testResult = Test( TM_INSIDE, testRAM, ignoreInsideFrom, ignoreInsideTo );
			}
			if ( testResult && ( ignoreMode & TM_OUTSIDE ) != 0 )
			{
				testResult = Test( TM_OUTSIDE, testRAM, ignoreOutsideFrom, ignoreOutsideTo );
			}
			if ( testResult )
			{
				resultNo++;
				newBuff[ newIndex ] = address; newIndex++;
				newBuff[ newIndex ] = testRAM; newIndex++;
				newSize += 16;
				if ( resultNo == resultTotal )
				{
					resultTotal += resultTotal;
					text.Printf( resultText, resultNo );
					result_S->SetLabel( text );
					pbQAct->SetValue( address );
				}
				testResult = false;
			}
			oldIndex++;
		}
	}
	delete [] ramBuff;
	text.Printf( resultText, resultNo );
	pbQAct->SetValue( rmSize );
	result_S->SetLabel( text );
	QCompareD->Clear();
	u64 xLength = searchNo + 1;
	u64 xIndex;
	QCompareD->Append( wxT("Dump") );
	for (xIndex = 1; xIndex < ( xLength + 1 ); xIndex++)
	{
		text.Printf( searchText, xIndex );
		QCompareD->Append( text );
	}
	QCompareD->Select( xLength );
	delete [] buff;
	oldBuff = new u64[ newIndex ];
	for ( ramIndex = 0; ramIndex < newIndex; ramIndex++ )
	{
		oldBuff[ ramIndex ] = newBuff[ ramIndex ];
	}
	delete [] newBuff;
	oldSearchNo = searchNo;
	oldLength = newIndex;
	resultTotal = newIndex;
	if ( newIndex > 0 )
	{
		qbt.Write( oldBuff, newSize );
		if ( newIndex < 100 )
		{
			showResults( searchNo, valSize );
		}
	}
}
void ME::Find16(u32 mode) {
	s32 valSize = 2;
	FIND1;
	u16* ramBuff = HCReadM16( appHandle, ramAddress, rmSize );
	FIND2;
}
void ME::Find32(u32 mode) {
	s32 valSize = 4;
	FIND1;
	u32* ramBuff = HCReadM32( appHandle, ramAddress, rmSize );
	FIND2;
}
void ME::Find64(u32 mode) {
	s32 valSize = 8;
	FIND1;
	u64* ramBuff = HCReadM64( appHandle, ramAddress, rmSize );
	FIND2;
}
void ME::bQActSOnClick(wxCommandEvent& event)
{
	s32 searchSize = searchSize_D->GetSelection();
	s32 searchNo = QCompareD->GetSelection();
	u64 rmSize = GARM( 0 );
	QSet(searchNo, searchSize);
	if (searchNo > 0)
	{
		switch (searchSize)
		{
			case 1: Find16(); break;
			case 2: Find32(); break;
			case 3: Find64(); break;
			default: Find8();
		}
		qbf.Close();
		qbt.Close();
	}
	else
	{
		pbQAct->SetRange( rmSize );
		switch ( searchSize )
		{
			case 1: Dump16(); break;
			case 2: Dump32(); break;
			case 3: Dump64(); break;
			default: Dump8();
		}
		qbt.Close();
	}
}
