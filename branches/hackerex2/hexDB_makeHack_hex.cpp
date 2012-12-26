#include "hexDB_main.h"
bool L_MH_HEX_GETPARTS( TxtA& block, TxtT& tknz, Text& text, Text& line, Text& part1, Text& part2, ui64& hex, ui32& pt1, ui32& pt2, ui32& l )
{
	if ( l >= block.GetCount() )
		return false;
	text	= block[ l ];
	tknz.SetString( text, cSemC );
	line	= tknz.GetNextToken();
	part1	= line.Left( 8 );
	part2	= line.Right( 8 );
	GetHex( &pt1, part1, 4u );
	GetHex( &pt2, part2, 4u );
	hex = pt1;
	hex <<= 32u;
	hex += pt2;
	++l;
	return true;
}
void FillData( void* data, void* fillWith, ui08 dataSize, ui08 fillSize )
{
	ui08* dat = reinterpret_cast< ui08* >( data );
	ui08* val = reinterpret_cast< ui08* >( &fillWith );
	ui08 b = 0u, f = ( dataSize > fillSize ) ? 0u : fillSize - dataSize;
	for ( ; ( b < dataSize ); ++b, ++f )
		dat[ b ] = ( f < fillSize ) ? val[ f ] : 0u;
}
bool xsDLL MakeHack_Hex_1( Hack& hack, TxtA& block, int& c, ui32& l )
{
// TODO(awsdert) Implement MakeHack_Hex_1()
	Text text, line, part1, part2;
	TxtT tknz;
	ui64 hex, data;
	ui32 pt1, pt2;
	ui08 dataSize, addrSize = 4u;
	Code  code;
	L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
	code.type	= (( 0xF0000000 & pt1 ) >> 28u );
	dataSize	= (( 0x0F000000 & pt1 ) >> 24u );
	code.ram	= (( 0x00F00000 & pt1 ) >> 20u );
	code.depth	= (( 0x000F0000 & pt1 ) >> 16u );
	code.info	= (( 0x0000FF00 & pt1 ) >>  8u );
	code.loop	=  ( 0x000000FF & pt1 );
	code.addr[ 1u ] = pt2;
	L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
	bool addrBig = false;
	bool dataBig = false;
	bool isCopy = ( code.type == HEX_CT_COPY );
	bool isTest = ( code.type == HEX_CT_TEST );
	ui08 vectSize = ( isCopy || isTest ) ? 1u : 2u;
	if ( dataSize & 0x8 )
	{
		dataSize -= 0x8;
		code.addr[ 0u ] = hex;
		addrSize = 8u;
		addrBig = true;
	}
	else
		code.addr[ 0u ] = pt1;
	if ( dataSize & 0x4 )
		dataSize -= 0x4;
	if ( isCopy )
		dataSize = addrSize;
	else
	{
		switch ( dataSize )
		{
			case 1u: dataSize = 2u; break;
			case 2u: dataSize = 4u; break;
			case 3u: dataSize = 8u; break;
			default: dataSize = 1u;
		}
	}
	code.bytes = dataSize;
	dataBig = ( dataSize > 4u );
	if ( addrBig || dataBig )
	{
		L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
		data = dataBig ? hex : pt2;
	}
	else
		data = pt2;
	if ( code.type != HEX_CT_LIST )
	{
		code.resize( dataSize * vectSize );
		FillData( &( code[ 0u ] ), &data, dataSize, 8u );
		if ( !isTest && !isCopy )
		{
			if ( dataBig )
			{
				L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
				data = hex;
			}
			else
			{
				if ( !addrBig )
					L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
				data = pt1;
			}
			FillData( &( code[ dataSize ] ), &data, dataSize, 8u );
		}
	}
	else
	{
		ui16 i = 0u, iCount = code.info, iAdd;
		ui32 b = 0u, bCount = iCount * dataSize, bNext;
		code.resize( iCount );
		if ( !dataBig )
		{
			FillData( &( code[ 0u ] ), &data, dataSize, 8u );
			switch ( dataSize )
			{
				case 4u: i = 1u; break;
				case 2u: i = 2u; break;
				default: i = 4u;
			}
		}
		switch ( dataSize )
		{
			case 8u: iAdd = 1u; break;
			case 4u: iAdd = 2u; break;
			case 2u: iAdd = 4u; break;
			default: iAdd = 8u;
		}
		bNext = 8u;
		for ( ; i < iCount; i += iAdd, b += 8u, bNext += 8u )
		{
			L_MH_HEX_GETPARTS( block, tknz, text, line, part1, part2, hex, pt1, pt2, l );
			if ( bNext < bCount )
				FillData( &( code[ b ] ), &hex, 8u, 8u );
			else
			{
				FillData( &( code[ b ] ), &hex, dataSize, 8u );
			}
		}
	}
	//hack[ c ] = code;
	++c;
	MakeHack_Hex_1( hack, block, c, l );
	return true;
}

bool xsDLL MakeHack_Hex_2( Hack& hack, TxtA& block, int& c, ui32& l, ui08& cCount )
{
// TODO(awsdert) Implement MakeHack_Hex_2()
	return false;
}
