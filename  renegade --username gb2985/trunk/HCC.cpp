#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__
#include "hexMain.h"
#include <math.h>
// Analyse the code string/s
CL ME::HCSet( HACK* hack, u32 line )
{
	CL code;
	if ( hack->GetLen() > 0 )
	{
		xStr text;
		// Line
		u32 line1 = line + 1;
		u32 line2 = line + 2;
		u32 line3 = line + 3;
		u32 stop = hack->cLines[ line ];
		u32 endLine = hack->GetLen();
		// Code pieces
		u32 xType = 0;
		u32 xSize = 0;
		xStr cPart_blank  = wxT( "00000000" );
		xStr cPart_1 = hack->cPart1[ line ];
		xStr cPart_2 = hack->cPart2[ line ];
		xStr cPart_3 = hack->cPart1[ line1 ];
		xStr cPart_4 = hack->cPart2[ line1 ];
		xStr cPart_5 = cPart_blank, cPart_6 = cPart_blank,
			cPart_7 = cPart_blank, cPart_8 = cPart_blank, c;
		// Address
		u64 xAddress = 0;
		// Increment Value
		u64 xValue = 0;
		u64 xIncrement;
		// Code
		if ( stop > 2 && endLine >= line2 )
		{
			cPart_5 = hack->cPart1[ line2 ];
			cPart_6 = hack->cPart2[ line2 ];
			if ( stop > 3 && endLine >= line3 )
			{
				cPart_7 = hack->cPart1[ line3 ];
				cPart_8 = hack->cPart2[ line3 ];
			}
		}
		code.reiterate = getHEX( cPart_1.SubString( 6, 7 ) );
		code.test = getHEX( cPart_1.SubString( 4, 5 ) );
		code.inc_address = getHEX( cPart_2 );
		xType = getHEX( cPart_1.GetChar( 0 ) );
		xSize = getHEX( cPart_1.GetChar( 1 ) );
		code.addressSize = getHEX( cPart_1.GetChar( 2 ) );
		code.ram = getHEX( cPart_1.GetChar( 3 ) );
		// Setup
		if ( xSize >= 0xC || code.addressSize )
		{
			xAddress = getHEX( cPart_3 + cPart_4 );
			if ( xSize >=0xC )
			{
				xValue = getHEX( cPart_5 + cPart_6 );
				xIncrement = getHEX( cPart_7 + cPart_8 );
				xSize = 0x8;
			}
			else
			{
				xValue = getHEX( cPart_5 );
				xIncrement = getHEX( cPart_6 );
				if ( xSize >= 0x8 )
				{
					xSize = 0x4;
				}
				else if ( xSize >= 0x4 )
				{
					xSize = 0x2;
				}
				else
				{
					xSize = 0x1;
				}
			}
		}
		else
		{
			xAddress = getHEX( cPart_3 );
			xValue = getHEX( cPart_4 );
			xIncrement = getHEX( cPart_6 );
			if ( xSize >= 0x8 )
			{
				xSize = 0x4;
			}
			else if ( xSize >= 0x4 )
			{
				xSize = 0x2;
			}
			else
			{
				xSize = 0x1;
			}
		}
		code.address = xAddress;
		code.value = xValue;
		code.inc_value = xIncrement;
		code.size = xSize;
		switch ( xType )
		{
			case 0x1: // Write
			case 0x3: // Copy
			case 0x5: // Test
			case 0x7: // Increment
			case 0x9: // Decrement
			case 0xB: // List Write
				code.fixed = true;
			default:
				code.codeType = floor(xType / 2);
		}
		// List Values
		for ( u64 i = 1; i < stop; i++ )
		{
			code.valueArray.Add( hack->cPart1[ line + i ] );
			code.valueArray.Add( hack->cPart2[ line + i ] );
		}
	}
	return code;
}
// Build the code string/s
void ME::BuildCode(HACK* hack, CL code, s32 line)
{
	xAStr linePart1;
	xAStr linePart2;
	u32 lineLength = 0;
	xStr codeText;
	u32 xSize;
	const wxChar* hex32 = wxT("%08X");
	const wxChar* hex32Long = wxT("%08llX");
	const wxChar* hex64 = wxT("%016llX");
	switch ( code.size )
	{
		case 0x2: xSize = 0x4; break;
		case 0x4: xSize = 0x8; break;
		case 0x8: xSize = 0xC; break;
		default: xSize = 0x0;
	}
	if (code.reiterate > 0x0)
	{
		xSize += 0x2;
	}
	codeText.Printf( wxT("%X%X%X%X%02X%02X"), (code.codeType * 2) + code.fixed, xSize,
		code.addressSize, code.ram, code.test, code.reiterate );
	linePart1.Add( codeText );
	codeText.Printf( hex32, code.inc_address );
	linePart2.Add( codeText );
	lineLength++;
	if ( code.addressSize || code.size > 0x4 )
	{
		codeText.Printf( hex64, code.address );
		linePart1.Add( codeText.SubString( 0, 7 ) );
		linePart2.Add( codeText.SubString( 8, 15 ) );
		lineLength++;
		if ( code.size > 0x4 )
		{
			codeText.Printf( hex64, code.value );
			linePart1.Add( codeText.SubString( 0, 7 ) );
			linePart2.Add( codeText.SubString( 8, 15 ) );
			lineLength++;
			if ( code.reiterate > 0x0 && code.codeType != 0x5 )
			{
				codeText.Printf( hex64, code.inc_value );
				linePart1.Add( codeText.SubString( 0, 7 ) );
				linePart2.Add( codeText.SubString( 8, 15 ) );
				lineLength++;
			}
		}
		else
		{
			codeText.Printf( hex32Long, code.inc_value );
			linePart1.Add( codeText );
			codeText.Printf( hex32Long, code.value );
			linePart2.Add( codeText );
			lineLength++;
		}
	}
	else
	{
		codeText.Printf( hex32Long, code.address );
		linePart1.Add( codeText );
		codeText.Printf( hex32Long, code.value );
		linePart2.Add( codeText );
		lineLength++;
		if ( code.reiterate > 0x0 && code.codeType != 0x5 )
		{
			codeText.Printf( hex64, code.inc_value );
			linePart1.Add( codeText.SubString( 0, 7 ) );
			linePart2.Add( codeText.SubString( 8, 15 ) );
			lineLength++;
		}
	}
	u32 i = 0;
	if ( line < 0 )
	{
		line = hack->GetLen();
		for ( i = 0; i < lineLength; i++ )
		{
			if ( i > 0 )
			{
				hack->cLines.Add( 0 );
				hack->sLines.Add( 0 );
			}
			else
			{
				hack->cLines.Add( lineLength );
				if ( code.codeType == 0x2 )
				{
					hack->sLines.Add( code.reiterate );
				}
				else
				{
					hack->sLines.Add( 0 );
				}
			}
			hack->cPart1.Add( linePart1[ i ] );
			hack->cPart2.Add( linePart2[ i ] );
		}
	}
	else
	{
		for ( i = 0; i < lineLength; i++ )
		{
			hack->cPart1.Insert( linePart1[ i ], line );
			hack->cPart2.Insert( linePart2[ i ], line );
			line++;
		}
	}
}
void ME::HCAddBOnClick(wxCommandEvent& event) {
	ti = HT->GetSelection();
	xStr text, txt;
	HACK* hack = getIH(ti);
	CL code;
	bool useRepeat = true;
	code.address = getHEX( codeAddress_TXT->GetValue() );
	if ( code.address > 0xFFFFFFFF )
	{
		code.addressSize = 0x1;
	}
	code.codeType = codeType_D->GetSelection();
	code.fixed = ( codeFixed_D->GetSelection() > 0 ) ? false : true;
	code.ram = codeRAM_D->GetSelection();
	switch ( codeSize_D->GetSelection() )
	{
		case 1: code.size = 0x2; break;
		case 2: code.size = 0x4; break;
		case 3: code.size = 0x8; break;
		default: code.size = 0x1;
	}
	xStrT st( codeValue_TXT->GetValue(), wxT( "|" ) );
	txt = st.GetNextToken();
	if ( code.codeType == 0x5 )
	{
		code.valueArray.Add( txt );
		while ( st.HasMoreTokens() )
		{
			text = st.GetNextToken();
			code.valueArray.Add( text );
		}
	}
	else
	{
		code.value = getHEX( txt );
		if ( code.codeType == 0x2)
		{
			switch ( codeTest_D->GetSelection() )
			{
				case 1: code.test = TM_NOTE; break;
				case 2: code.test = TM_GT; break;
				case 3: code.test = TM_GTE; break;
				case 4: code.test = TM_LT; break;
				case 5: code.test = TM_LTE; break;
				default: code.test = TM_EQUAL;
			}
			int testLines = codeTestLine_D->GetSelection();
			if ( testLines != 1 )
			{
				if ( testLines == 0)
				{
					code.reiterate = 1;
				}
				useRepeat = false;
			}
		}
	}
	if ( useRepeat )
	{
		code.reiterate = codeRepeat_SN->GetValue();
		code.inc_address = getHEX( codeIncAddress_TXT->GetValue() );
	}
	code.inc_value = getHEX( codeIncValue_TXT->GetValue() );
	BuildCode(hack, code);
	HTChange();
	setIH(ti, hack);
}
