/***************************************************************
 * Name:      qTab.cpp
 * Purpose:   Code for Search Tab
 * Author:    awsdert ()
 * Created:   2012-02-13
 * Copyright: awsdert ()
 * License:
 **************************************************************/

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
void ME::Seek( s32 findNo )
{
	if ( findNo >= 0 )
	{
		xStr text;
		HANDLE appHandle = GAP();
		u32 valueSize;
		switch( searchSize_D->GetSelection() )
		{
			case 1: valueSize = 2u; break;
			case 2: valueSize = 4u; break;
			case 3: valueSize = 8u; break;
			default: valueSize = 1u;
		}
		byte_PB->SetValue( 0u );
		// RAM
		s32 ramNo = searchRAM_D->GetSelection();
		u64 ramStart = GARS( ramNo );
		u64 ramSize = GARM( ramNo );
		u32 readRAM = ( ramSize > 0x10000000 ) ? 0x10000000 : ramSize;
		u64 ramAddress = 0u;
		u64 address = 0u;
		u64 nextAddress = 0u;
		// File
		wxFile ramTo, ramFrom, byteTo, byteFrom;
		text.Printf( dumpPath, findNo );
		ramTo.Create( text, true );
		ramTo.Open( text, ramTo.write );
		text.Printf( bytePath, findNo );
		byteTo.Create( text, true );
		byteTo.Open( text, byteTo.write );
		// Current RAM
		u32 i = 0u, j = 0u;
		bool useAddress = false;
		u64 nowValue;
		u8* nowBuff8 = new u8[ readRAM ];
		u8* nowAddress = new u8[ readRAM ];
		u16* nowBuff16 = reinterpret_cast< u16* >( nowBuff8 );
		u32* nowBuff32 = reinterpret_cast< u32* >( nowBuff8 );
		u64* nowBuff64 = reinterpret_cast< u64* >( nowBuff8 );
		// Old RAM
		u64 oldValue;
		u8* oldBuff8 = new u8[ readRAM ];
		u8* oldAddress = new u8[ readRAM ];
		if ( findNo > 0 )
		{
			text.Printf( dumpPath, findNo - 1 );
			ramFrom.Open( text );
			text.Printf( bytePath, findNo - 1 );
			byteFrom.Open( text );
		}
		u16* oldBuff16 = reinterpret_cast< u16* >( oldBuff8 );
		u32* oldBuff32 = reinterpret_cast< u32* >( oldBuff8 );
		u64* oldBuff64 = reinterpret_cast< u64* >( oldBuff8 );
		// Result
		u64 resultNo = 0u;
		u64 resultTotal = ramSize / 10u;
		u64 nextTotal = resultTotal;
		const wxChar* resultText = wxT("Results: %u");
		text.Printf( resultText, resultNo );
		total_S->SetLabel( text );
		byte_PB->SetRange( ramSize );
		// Tests
		GetValues();
		u32 testOld = GetOld();
		u32 testOldBinary = GetOldBinary();
		u32 testGood = GetGood();
		u32 testGoodBinary = GetGoodBinary();
		u32 testGoodByte = GetGoodByte();
		u32 testBad = GetBad();
		u32 testBadBinary = GetBadBinary();
		u32 testBadByte = GetBadByte();
		// Loop
		for ( ; address < ramSize; address++, j++ )
		{
			// Update buffers if RAM is larger than supported
			if ( address == nextAddress )
			{
				if ( address > 0u )
				{
					ramTo.SeekEnd( 0 );
					byteTo.SeekEnd( 0 );
					ramTo.Write( nowBuff8, readRAM );
					byteTo.Write( nowAddress, readRAM );
				}
				nextAddress += readRAM;
				if ( nextAddress > ramSize )
				{
					nextAddress -= readRAM;
					readRAM = ramSize - nextAddress;
					nextAddress += readRAM;
				}
				i = 0u; j = 0u;
				HCReadM8( appHandle, ramStart + address, readRAM, nowBuff8 );
				if ( findNo > 0 )
				{
					ramFrom.Seek( 0u, wxFromCurrent );
					byteFrom.Seek( 0u, wxFromCurrent );
					ramFrom.Read( oldBuff8, readRAM );
					byteFrom.Read( oldAddress, readRAM );
				}
				if ( address >= nextTotal )
				{
					nextTotal += resultTotal;
					text.Printf( resultText, resultNo );
					total_S->SetLabel( text );
					byte_PB->SetValue( address );
				}
			}
			if ( address == ramAddress )
			{
				switch ( valueSize )
				{
					case 2u: nowValue = nowBuff16[ i ]; break;
					case 4u: nowValue = nowBuff32[ i ]; break;
					case 8u: nowValue = nowBuff64[ i ]; break;
					default: nowValue = nowBuff8[ i ];
				}
				// Do we have old data?
				if ( findNo > 0 )
				{
					useAddress = ( oldAddress[ j ] > 0u );
					// Check against old data?
					if ( useAddress && ( testOld > 0u || testOldBinary > 0u ) )
					{
						switch ( valueSize )
						{
							case 2u: oldValue = oldBuff16[ i ]; break;
							case 4u: oldValue = oldBuff32[ i ]; break;
							case 8u: oldValue = oldBuff64[ i ]; break;
							default: oldValue = oldBuff8[ i ];
						}
						switch ( testOld )
						{
							case TM_EQUAL: useAddress = ( nowValue == oldValue ); break;
							case TM_NOTE: useAddress = ( nowValue != oldValue ); break;
							case TM_GT: useAddress = ( nowValue > oldValue ); break;
							case TM_GTE: useAddress = ( nowValue >= oldValue ); break;
							case TM_LT: useAddress = ( nowValue < oldValue ); break;
							case TM_LTE: useAddress = ( nowValue <= oldValue ); break;
						}
						switch ( testOldBinary )
						{
							case TM_EQUAL: useAddress = ( ( nowValue & oldValue ) == oldValue ); break;
							case TM_NOTE: useAddress = ( ( nowValue & oldValue ) != oldValue ); break;
							case TM_GT: useAddress = ( ( nowValue & oldValue ) > oldValue ); break;
							case TM_GTE: useAddress = ( ( nowValue & oldValue ) >= oldValue ); break;
							case TM_LT: useAddress = ( ( nowValue & oldValue ) < oldValue ); break;
							case TM_LTE: useAddress = ( ( nowValue & oldValue ) <= oldValue ); break;
						}
					}
				}
				else
				{
					useAddress = true;
				}
				// Check address range
				if ( useAddress && testGoodByte > 0u )
				{
					if ( ( testGoodByte & TM_GT ) > 0u )
					{
						useAddress = ( address > goodAGT );
					}
					if ( useAddress && ( testGoodByte & TM_GTE ) > 0u )
					{
						useAddress = ( address >= goodAGTE );
					}
					if ( useAddress && ( testGoodByte & TM_LT ) > 0u )
					{
						useAddress = ( address < goodALT );
					}
					if ( useAddress && ( testGoodByte & TM_LTE ) > 0u )
					{
						useAddress = ( address <= goodALTE );
					}
				}
				if ( useAddress && testBadByte > 0u )
				{
					if ( ( testBadByte & TM_GT ) > 0u )
					{
						useAddress = !( address > badAGT );
					}
					if ( useAddress && ( testBadByte & TM_GTE ) > 0u )
					{
						useAddress = !( address >= badAGTE );
					}
					if ( useAddress && ( testBadByte & TM_LT ) > 0u )
					{
						useAddress = !( address < badALT );
					}
					if ( useAddress && ( testBadByte & TM_LTE ) > 0u )
					{
						useAddress = !( address <= badALTE );
					}
				}
				// Good value/s
				if ( useAddress && testGood > 0u )
				{
					if ( ( testGood & TM_EQUAL ) > 0u )
					{
						useAddress = ( nowValue == goodVEqual );
					}
					if ( useAddress && ( testGood & TM_NOTE ) > 0u )
					{
						useAddress = ( nowValue != goodVNOTE );
					}
					if ( useAddress && ( testGood & TM_GT ) > 0u )
					{
						useAddress = ( nowValue > goodVGT );
					}
					if ( useAddress && ( testGood & TM_GTE ) > 0u )
					{
						useAddress = ( nowValue >= goodVGTE );
					}
					if ( useAddress && ( testGood & TM_LT ) > 0u )
					{
						useAddress = ( nowValue < goodVLT );
					}
					if ( useAddress && ( testGood & TM_LTE ) > 0u )
					{
						useAddress = ( nowValue <= goodVLTE );
					}
				}
				if ( useAddress && testGoodBinary > 0u )
				{
					if ( ( testGoodBinary & TM_EQUAL ) > 0u )
					{
						useAddress = ( ( nowValue & goodVEqual ) == goodVEqual );
					}
					if ( useAddress && ( testGoodBinary & TM_NOTE ) > 0u )
					{
						useAddress = ( ( nowValue & goodVNOTE ) != goodVNOTE );
					}
					if ( useAddress && ( testGoodBinary & TM_GT ) > 0u )
					{
						useAddress = ( ( nowValue & goodVGT ) > goodVGT );
					}
					if ( useAddress && ( testGoodBinary & TM_GTE ) > 0u )
					{
						useAddress = ( ( nowValue & goodVGTE ) >= goodVGTE );
					}
					if ( useAddress && ( testGoodBinary & TM_LT ) > 0u )
					{
						useAddress = ( ( nowValue & goodVLT ) < goodVLT );
					}
					if ( useAddress && ( testGoodBinary & TM_LTE ) > 0u )
					{
						useAddress = ( ( nowValue & goodVLTE ) <= goodVLTE );
					}
				}
				// Bad value/s
				if ( useAddress && testBad > 0u )
				{
					if ( ( testBad & TM_EQUAL ) > 0u )
					{
						useAddress = !( nowValue == badVEqual );
					}
					if ( useAddress && ( testBad & TM_NOTE ) > 0u )
					{
						useAddress = !( nowValue != badVNOTE );
					}
					if ( useAddress && ( testBad & TM_GT ) > 0u )
					{
						useAddress = !( nowValue > badVGT );
					}
					if ( useAddress && ( testBad & TM_GTE ) > 0u )
					{
						useAddress = !( nowValue >= badVGTE );
					}
					if ( useAddress && ( testBad & TM_LT ) > 0u )
					{
						useAddress = !( nowValue < badVLT );
					}
					if ( useAddress && ( testBad & TM_LTE ) > 0u )
					{
						useAddress = !( nowValue <= badVLTE );
					}
				}
				if ( useAddress && testBadBinary > 0u )
				{
					if ( ( testBadBinary & TM_EQUAL ) > 0u )
					{
						useAddress = ( ( nowValue & badVEqual ) == badVEqual );
					}
					if ( useAddress && ( testBadBinary & TM_NOTE ) > 0u )
					{
						useAddress = ( ( nowValue & badVNOTE ) != badVNOTE );
					}
					if ( useAddress && ( testBadBinary & TM_GT ) > 0u )
					{
						useAddress = ( ( nowValue & badVGT ) > badVGT );
					}
					if ( useAddress && ( testBadBinary & TM_GTE ) > 0u )
					{
						useAddress = ( ( nowValue & badVGTE ) >= badVGTE );
					}
					if ( useAddress && ( testBadBinary & TM_LT ) > 0u )
					{
						useAddress = ( ( nowValue & badVLT ) < badVLT );
					}
					if ( useAddress && ( testBadBinary & TM_LTE ) > 0u )
					{
						useAddress = ( ( nowValue & badVLTE ) <= badVLTE );
					}
				}
				// Make sure we know whether to use the address or not on later search
				if ( useAddress )
				{
					resultNo++;
				}
				ramAddress += valueSize;
				i++;
			}
			else
			{
				useAddress = false;
			}
			nowAddress[ j ] = useAddress ? 1u : 0u;
		}
		text.Printf( resultText, resultNo );
		total_S->SetLabel( text );
		byte_PB->SetValue( address );
		if ( address <= nextAddress )
		{
			ramTo.SeekEnd( 0 );
			byteTo.SeekEnd( 0 );
			ramTo.Write( nowBuff8, readRAM );
			byteTo.Write( nowAddress, readRAM );
		}
		ramTo.Close();
		byteTo.Close();
		if ( findNo > 0 )
		{
			ramFrom.Close();
			byteFrom.Close();
		}
		// Clear Memory
		delete [] nowBuff8;
		delete [] nowAddress;
		delete [] oldBuff8;
		delete [] oldAddress;
		// Select next search
		compare_D->Clear();
		u64 xLength = findNo + 1;
		u64 xIndex;
		const wxChar* searchText = wxT("Search %i");
		compare_D->Append( wxT("Dump") );
		for (xIndex = 1; xIndex < ( xLength + 1 ); xIndex++ )
		{
			text.Printf( searchText, xIndex );
			compare_D->Append( text );
		}
		compare_D->Select( xLength );
		if ( resultNo > 0u && resultNo < 100u )
		{
			showResults( findNo, valueSize );
		}
	}
}
void ME::showResults( s32 findNo, u32 valSize )
{
	if ( findNo >= 0 )
	{
		ClearGrid( RG );
		ClearGridCols( RG );
		xStr text, tmp;
		text = hexPath + hexSlash;
		wxFile ramFrom, byteFrom;
		// Byte
		xStr fromText = text + wxT("ram") + hexSlash + wxT("byte%02i.bin");
		tmp.Printf( fromText, findNo );
		byteFrom.Open( tmp );
		// Dump
		fromText = text + wxT("ram") + hexSlash + wxT("dump%02i.bin");
		tmp.Printf( fromText, findNo );
		ramFrom.Open( tmp );
		// RAM
		const s32 ramNo = searchRAM_D->GetSelection();
		const u64 ramSize = GARM( ramNo );
		const u32 readRAM2 = ( ramSize > 0x10000000 ) ? 0x10000000 : ramSize;
		u32 readRAM = readRAM2;
		u32 i = 0u;
		s32 r = 0, rLimit = 100, c = 0, k = findNo - 1, kLimit = findNo - 5;
		kLimit = ( kLimit < 0 ) ? 0 : kLimit;
		u64 address = 0u;
		u32 j = 0u;
		u64 nextAddress = 0u;
		u64 nextRAM = 0u;
		u64 value;
		xStr valueText;
		switch ( valSize )
		{
			case 2u: valueText = wxT("%04llX"); break;
			case 4u: valueText = wxT("%08llX"); break;
			case 8u: valueText = wxT("%016llX"); break;
			default: valueText = wxT("%02llX"); break;
		}
		u8* oldByte = new u8[ readRAM ];
		u8* ramBuff8 = new u8[ readRAM ];
		u16* ramBuff16 = reinterpret_cast< u16* >( ramBuff8 );
		u32* ramBuff32 = reinterpret_cast< u32* >( ramBuff8 );
		u64* ramBuff64 = reinterpret_cast< u64* >( ramBuff8 );
		RG->AppendCols( 1, false );
		for ( ; ( address < ramSize && r < rLimit ); address++, j++ )
		{
			if ( address == nextAddress )
			{
				nextAddress += readRAM;
				if ( nextAddress > ramSize )
				{
					nextAddress -= readRAM;
					readRAM = ramSize - nextAddress;
					nextAddress = ramSize;
				}
				ramFrom.Seek( 0u, wxFromCurrent );
				ramFrom.Read( ramBuff8, readRAM );
				byteFrom.Seek( 0u, wxFromCurrent );
				byteFrom.Read( oldByte, readRAM );
				i = 0u; j = 0u;
			}
			if ( address == nextRAM )
			{
				if ( oldByte[ j ] > 0u )
				{
					switch ( valSize )
					{
						case 2u: value = ramBuff16[ i ]; break;
						case 4u: value = ramBuff32[ i ]; break;
						case 8u: value = ramBuff64[ i ]; break;
						default: value = ramBuff8[ i ]; break;
					}
					RG->AppendRows(1, false );
					text.Printf( wxT("%016llX"), address );
					RG->SetRowLabelValue( r, text );
					text.Printf( valueText, value );
					RG->SetCellValue( r, 0, text );
					r++;
				}
				nextRAM += valSize;
				i++;
			}
		}
		ramFrom.Close();
		for ( c = 1; k > kLimit; k--, c++ )
		{
			nextRAM = 0u;
			readRAM = readRAM2;
			address = 0u;
			nextAddress = 0u;
			tmp.Printf( fromText, k );
			ramFrom.Open( tmp );
			byteFrom.Seek( 0u, wxFromStart );
			RG->AppendCols( 1, false );
			for ( r = 0; ( r < rLimit && address < ramSize ); address++ )
			{
				if ( address == nextAddress )
				{
					nextAddress += readRAM;
					if ( nextAddress > ramSize )
					{
						nextAddress -= readRAM;
						readRAM = ramSize - nextAddress;
						nextAddress = ramSize;
					}
					ramFrom.Seek( 0u, wxFromCurrent );
					ramFrom.Read( ramBuff8, readRAM );
					byteFrom.Seek( 0u, wxFromCurrent );
					byteFrom.Read( oldByte, readRAM );
					i = 0u;
				}
				if ( address == nextRAM )
				{
					if ( oldByte[ i ] )
					{
						switch ( valSize )
						{
							case 2u: value = ramBuff16[ i ]; break;
							case 4u: value = ramBuff32[ i ]; break;
							case 8u: value = ramBuff64[ i ]; break;
							default: value = ramBuff8[ i ]; break;
						}
						text.Printf( valueText, value );
						RG->SetCellValue( r, c, text );
						r++;
					}
					nextRAM += valSize;
					i++;
				}
			}
			ramFrom.Close();
		}
		byteFrom.Close();
		RG->AutoSizeColumns();
		RG->SetRowLabelSize( wxGRID_AUTOSIZE );
		delete [] ramBuff8;
		delete [] oldByte;
	}
}
