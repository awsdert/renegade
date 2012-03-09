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
void ME::QSet(s32 findNo, s32 valueSize, bool overwrite)
{
	xStr dirPath = wxGetCwd(), filePath, tmp;
	dirPath += hexSlash + wxT( "find" );
	if ( !dir.Exists( dirPath ) )
	{
		wxMkdir( dirPath );
	}
	dir.Open( dirPath );
	switch ( valueSize )
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
	if (findNo > 0)
	{
		tmp.Printf( wxT( "search%02i.hexq" ), findNo - 1);
		filePath = dirPath + tmp;
		qbf.Open( filePath, qbf.read_write );
	}
	tmp.Printf( wxT( "search%02i.hexq" ), findNo);
	filePath = dirPath + tmp;
	if (overwrite || !qbt.Exists( filePath ) ) {
		qbt.Create( filePath, true );
	}
	qbt.Open(filePath, qbt.read_write);
}
u64* ME::OldV(s32 findNo, bool update)
{
	u64* buff;
	u64 i;
	if ( findNo == oldSearchNo + 1 )
	{
		buff = new u64[oldLength];
		for (i = 0;i < oldLength;i++)
		{
			buff[i] = oldBuff[i];
		}
		return buff;
	}
	s32 valSize = 8;
	u64 len = qbf.Length();
	u64 buffLength = len / valSize;
	buff = new u64[ buffLength ];
	qbf.Read( buff, len );
	if ( update )
	{
		delete [] oldBuff;
		oldSearchNo = findNo;
		oldBuff = new u64[ buffLength ];
		for ( i = 0; i < buffLength; i++ )
		{
			oldBuff[ i ] = buff [ i ];
		}
		oldLength = i;
	} return buff;
}
void ME::Dump( u32 findNo, u32 valSize )
{
	HANDLE appHandle = GAP();
	u32 findRAM = findRAM_D->GetSelection();
	if ( findRAM > 0xF ) { findRAM = 0u; }
	u64 ramAddress = GARS( findRAM );
	u64 ramSize = GARM( findRAM );
	u64 i = 0u;
	u32 ramMode = 1u;
	// Results
	const wxChar* resultText = wxT( "Results: %i" );
	u64 resultNo = 0u;
	u64 resultTotal = ceil( ramSize / 100u );
	u8* ramBuff8 = new u8[ramSize];
	HCReadM8( appHandle, ramAddress, ramSize, ramBuff8 );
	u16* ramBuff16 = reinterpret_cast < u16* > ( ramBuff8 );
	u32* ramBuff32 = reinterpret_cast < u32* > ( ramBuff8 );
	u64* ramBuff64 = reinterpret_cast < u64* > ( ramBuff8 );
	u64 ramIndex = 0u;
	// Code
	u64 newIndex = 0u;
	u64 newSize = 0u;
	u64 address = 0u;
	u64 testRAM = 0u;
	if ( oldSearchNo > -1 )
	{
		delete [] oldBuff;
	}
	newBuff = new u64[ ramSize * 2u ];
	u32 delSize = valSize - 1u;
	xStr text, title;
	for ( ; address < ramSize; address++, ramMode++ )
	{
		if ( ramMode == valSize )
		{
			resultNo++;
			switch ( valSize )
			{
				case 2u:
					testRAM = ramBuff16[ ramIndex ];
					break;
				case 4u:
					testRAM = ramBuff32[ ramIndex ];
					break;
				case 8u:
					testRAM = ramBuff64[ ramIndex ];
					break;
				default:
					testRAM = ramBuff8[ address ];
					break;
			}
			newBuff[ newIndex ] = address - delSize; newIndex++;
			newBuff[ newIndex ] = testRAM; newIndex++;
			newSize += 16;
			if ( resultNo == resultTotal )
			{
				resultTotal += resultTotal;
				find_PB->SetValue( address );
				text.Printf( resultText, resultNo );
				result_S->SetLabel( text );
			}
			ramMode = 0u;
			ramIndex++;
		}
	}
	qbt.Write( newBuff, newSize );
	find_PB->SetValue( address );
	text.Printf( resultText, resultNo );
	result_S->SetLabel( text );
	oldBuff = new u64[ newIndex ];
	oldLength = newIndex;
	for ( i = 0u; i < newIndex; i++ )
	{
		oldBuff[i] = newBuff[i];
	}
	delete [] newBuff;
	oldSearchNo = findNo;
	findNo_D->Clear();
	findNo_D->Append(wxT("Dump"));
	findNo_D->Append(wxT("Search 1"));
	findNo_D->Select(1);
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
		switch ( valueSize_D->GetSelection() )
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
void ME::showResults( s32 findNo, u32 valSize )
{
	ClearGrid(RG);
	ClearGridCols(RG);
	wxString text, tmp;
	tmp.Printf( wxT( "%%0%iX" ), valSize * 2 );
	const wxChar* ramValueText = tmp.data();
	const wxChar* ramAddressText = wxT( "%08X" );
	const wxChar* searchNoText = wxT( "Search %u" );
	s32 c, until = findNo - 5, k;
	u64 oldIndex = 0, xIndex, xLength, row = 0;
	until = ( until < 0 ) ? 0 : until;
	RG->AppendCols( 2, false );
	text.Printf( searchNoText, findNo );
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
	for ( c = 2, k = findNo;k > until;k--, c++ )
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
void ME::Find( u32 mode, u32 valSize )
{
	// All changes here onwards must be ported into the FIND definitions once stable
	const wxChar* resultText = wxT( "Results: %i" );
	const wxChar* searchText = wxT( "Search %i" );
	HANDLE appHandle = GAP();
	s32 findNo = findNo_D->GetSelection();
	u64 oldIndex = 0u;
	xStr text, title;
	// RAM
	u32 findRAM = findRAM_D->GetSelection();
	if ( findRAM > 0xF ) { findRAM = 0u; }
	u64 ramAddress = GARS( findRAM ); // Number indicates which RAM, implimented later
	u64 ramSize = GARM( findRAM );
	u64 ramIndex = 0u;
	u64 address = 0u;
	u8* ramBuff8 = new u8[ ramSize ];
	HCReadM8( appHandle, ramAddress, ramSize, ramBuff8 );
	u16* ramBuff16 = reinterpret_cast < u16* > ( ramBuff8 );
	u32* ramBuff32 = reinterpret_cast < u32* > ( ramBuff8 );
	u64* ramBuff64 = reinterpret_cast < u64* > ( ramBuff8 );
	// Result
	u64 resultTotal = ceil( ramSize / 10u );
	u64 resultNo = 0u;
	u32 ramMode = 1u;
	// New Buffer
	u64 newIndex = 0u;
	u64 newSize = 0u;
	u64 newBuffLength = ( valSize == 1u ) ? ramSize : ceil( ramSize / valSize );
	// Test modes
	u32 valMode = GetTests();
	u32 testMode = GetRest();
	u32 ignoreMode = GetIgnore();
	bool testResult = 0u;
	// Buffers
	u64* buff = OldV( findNo );
	delete [] oldBuff;
	newBuff = new u64[ newBuffLength * 2u ];
	// Code
	text.Printf( resultText, 0u );
	find_PB->SetRange( ramSize );
	find_PB->SetValue( 0u );
	result_S->SetLabel( text );
	u64 testRAM;
	text.Printf( wxT( "%%0%iX" ), valSize * 2u );
	for ( ; (address < ramSize && oldIndex < oldLength); address++, ramMode++ )
	{
		if ( address == buff[ oldIndex ] )
		{
			switch ( valSize )
			{
				case 2u:
					testRAM = ramBuff16[ ramIndex ];
					break;
				case 4u:
					testRAM = ramBuff32[ ramIndex ];
					break;
				case 8u:
					testRAM = ramBuff64[ ramIndex ];
					break;
				default:
					testRAM = ramBuff8[ address ];
					break;
			}
			oldIndex++;
			if ( valMode != 0 )
			{
				testResult = Test( valMode, testRAM, buff[ oldIndex ] );
			}
			else
			{
				testResult = true;
			}
			if ( testResult && testMode != 0 )
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
					find_PB->SetValue( address );
				}
				testResult = false;
			}
			oldIndex++;
		}
		if ( ramMode == valSize )
		{
			ramIndex++;
			ramMode = 0u;
		}
	}
	delete [] ramBuff8;
	text.Printf( resultText, resultNo );
	find_PB->SetValue( ramSize );
	result_S->SetLabel( text );
	findNo_D->Clear();
	u64 xLength = findNo + 1;
	u64 xIndex;
	findNo_D->Append( wxT("Dump") );
	for (xIndex = 1; xIndex < ( xLength + 1 ); xIndex++)
	{
		text.Printf( searchText, xIndex );
		findNo_D->Append( text );
	}
	findNo_D->Select( xLength );
	delete [] buff;
	oldBuff = new u64[ newIndex ];
	for ( ramIndex = 0u; ramIndex < newIndex; ramIndex++ )
	{
		oldBuff[ ramIndex ] = newBuff[ ramIndex ];
	}
	delete [] newBuff;
	oldSearchNo = findNo;
	oldLength = newIndex;
	resultTotal = newIndex;
	if ( newIndex > 0u )
	{
		qbt.Write( oldBuff, newSize );
		if ( newIndex < 100u )
		{
			showResults( findNo, valSize );
		}
	}
}
void ME::dump_BOnClick( wxCommandEvent& event )
{
	u32 valueSize = valueSize_D->GetSelection();
	Dump( 0, valueSize );
}
void ME::find_BOnClick( wxCommandEvent& event )
{
	s32 findNo = findNo_D->GetSelection();
	u32 valueSize = valueSize_D->GetSelection();
	QSet( findNo, valueSize );
	switch ( valueSize )
	{
		case 1u: valueSize = 2u; break;
		case 2u: valueSize = 4u; break;
		case 3u: valueSize = 8u; break;
		default: valueSize = 1u;
	}
	if ( findNo > 0 )
	{
		Find( findNo, valueSize );
		qbf.Close();
	}
	else
	{
		Dump( 0, valueSize );
	}
	qbt.Close();
}
void ME::findNo_DOnChange( wxCommandEvent& event )
{
	s32 findNo = findNo_D->GetSelection();
	if ( findNo > 0 )
	{
		findRAM_D->Disable();
	}
	else
	{
		findRAM_D->Enable();
	}
}
void ME::undoFind_BOnClick( wxCommandEvent& event )
{
	s32 findNo = findNo_D->GetSelection();
	findNo--;
	if ( findNo > 0 )
	{
		delete [] oldBuff;
		u64* buff = OldV( findNo );
		delete [] buff;
	}
}
