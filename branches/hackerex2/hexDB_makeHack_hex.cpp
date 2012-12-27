#include "hexDB_main.h"
void L_MO_HEX_GETPARTS( TxtA& block, TxtT& tzr, Text& txt, Text& line, Text& prt1, Text& prt2, ui64& hex, ui32& pt1, ui32& pt2, int& l, int& lEnd )
{
	if ( l >= lEnd )
		return;
	txt		= block[ l ];
	tzr.SetString( txt, cSemC );
	line	= tzr.GetNextToken();
	prt1	= line.Left( 8 );
	prt2	= line.Right( 8 );
	GetHex( &pt1, prt1, 4u );
	GetHex( &pt2, prt2, 4u );
	hex	= pt1;
	hex <<= 32u;
	hex += pt2;
	++l;
}
void FillData( void* data, void* fillWith, ui08 dataSize, ui08 fillSize )
{
	ui08* dat = reinterpret_cast< ui08* >( data );
	ui08* val = reinterpret_cast< ui08* >( fillWith );
	ui08 b = 0u, f = ( dataSize > fillSize ) ? 0u : fillSize - dataSize;
	for ( ; ( b < dataSize ); ++b, ++f )
		dat[ b ] = ( f < fillSize ) ? val[ f ] : 0u;
}
void xsDLL MakeTxt_Hex1( Codes& data, TxtA& block )
{
	Text txt;
	Code obj;
	int c = 0, cEnd = data.size();
	ui32 pt1, pt2, val, a1, a2, v1, v2;
	ui64 v64, inc;
	bool big;
	const wxChar* printLine = wxT("%08X %08X");
	ui08 vSize;
	for ( ; c < cEnd; ++c )
	{
		obj	= data[ c ];
		if ( obj.depth > 0xF || obj.loop > 0xFF || obj.addr[ 1 ] > xsF8LL )
			return;
		// Part 1 of Code Header
		val	= ( obj.type & 0xF );
		pt1	= ( val << 28u );
		v64	= obj.addr[ 0 ];
		big	= ( v64 > xsF8LL );
		a1	= GETHEX( v64, xsF8LL, 32u );
		a2	= ( v64 & xsF8LL );
		switch ( obj.bytes )
		{
			case 8u:
				val = 3u;
				v64 = *( reinterpret_cast< ui64* >( &( obj[0] ) ) );
				inc = *( reinterpret_cast< ui64* >( &( obj[1] ) ) );
				break;
			case 4u:
				val = 2u;
				v64 = *( reinterpret_cast< ui32* >( &( obj[0] ) ) );
				inc = *( reinterpret_cast< ui32* >( &( obj[1] ) ) );
				break;
			case 2u:
				val = 1u;
				v64 = *( reinterpret_cast< ui16* >( &( obj[0] ) ) );
				inc = *( reinterpret_cast< ui16* >( &( obj[1] ) ) );
				break;
			default:
				val = 0u;
				v64 = obj[0];
				inc = obj[1];
				break;
		}
		v1 = GETHEX( v64, xsF8LL, 32u );
		v2 = ( v64 & xsF8LL );
		if ( big )
			val += 8u;
		pt1 += ( val << 24u );
		val = obj.depth;
		pt1 += ( val << 20u );
		val = obj.ram;
		pt1 += ( val << 16u );
		val = ( obj.info & 0xFF );
		pt1 += ( val << 8u );
		pt1 += obj.loop;
		// Part 2 of Code Header
		pt2 = obj.addr[ 1 ];
		// Add Header to block
		txt.Printf( printLine, pt1, pt2 );
		block.Add( txt );
		// Get addr/value
		if ( big )
			pt1 = a1;
		else
			pt1 = 0u;
		pt2 = a2;
		if ( obj.type != HEX_CT_LIST )
		{
			a1	= GETHEX( inc, xsF8LL, 32u );
			a2	= ( inc & xsF8LL );
			if ( !big && obj.bytes != 8u )
				pt1 = v2;
			txt.Printf( printLine, pt1, pt2 );
			block.Add( txt );
			if ( obj.bytes == 8u )
			{
				txt.Printf( printLine, v1, v2 );
				block.Add( txt );
			}
			else if ( big )
				a1 = v2;
			else
				a1 = 0u;
			if ( obj.type != HEX_CT_TEST )
			{
				txt.Printf( printLine, a1, a2 );
				block.Add( txt );
			}
		}
		else
		{
			txt.Printf( printLine, pt1, pt2 );
			block.Add( txt );
			vSize = obj.bytes;
			int i = 0, iEnd = obj.size();
			switch ( vSize )
			{
			case 1u: iEnd /= 8; break;
			case 2u: iEnd /= 4; break;
			case 4u: iEnd /= 2; break;
			}
			obj.bytes = 8u;
			for ( ; i < iEnd; ++i )
			{
				v64	= *( reinterpret_cast< ui64* >( &( obj[i] ) ) );
				v1	= GETHEX( inc, xsF8LL, 32u );
				v2	= ( inc & xsF8LL );
				txt.Printf( printLine, v1, v2 );
				block.Add( txt );
			}
			obj.bytes = vSize;
		}
	}
}
void xsDLL MakeObj_Hex1( Codes& data, TxtA& block, int& l, int& lEnd )
{
	Text txt, line, prt1, prt2;
	TxtT tzr;
	ui64 hex, val, inc;
	ui32 pt1, pt2;
	ui08 dataSize, addrSize = 4u;
	Code obj;
	L_MO_HEX_GETPARTS( block, tzr, txt, line, prt1, prt2, hex, pt1, pt2, l, lEnd );
	obj.type	= (( 0xF0000000 & pt1 ) >> 28u );
	dataSize	= (( 0x0F000000 & pt1 ) >> 24u );
	obj.ram	= (( 0x00F00000 & pt1 ) >> 20u );
	obj.depth	= (( 0x000F0000 & pt1 ) >> 16u );
	obj.info	= (( 0x0000FF00 & pt1 ) >>  8u );
	obj.loop	=  ( 0x000000FF & pt1 );
	obj.addr[ 1u ] = pt2;
	L_MO_HEX_GETPARTS( block, tzr, txt, line, prt1, prt2, hex, pt1, pt2, l, lEnd );
	bool addrBig = false;
	bool dataBig = false;
	bool isList = ( obj.type == HEX_CT_LIST );
	bool isCopy = ( obj.type == HEX_CT_COPY );
	bool isTest = ( obj.type == HEX_CT_TEST );
	bool isInc = ( !isList && !isTest && !isCopy );
	if ( dataSize & 0x8 )
	{
		dataSize -= 0x8;
		obj.addr[ 0u ] = hex;
		addrSize = 8u;
		addrBig = true;
	}
	else
		obj.addr[ 0u ] = pt2;
	if ( dataSize & 0x4 )
		dataSize -= 0x4;
	if ( isCopy )
		dataSize = addrSize;
	else
	{
		switch ( dataSize )
		{
			case 3u: dataSize = 8u; break;
			case 2u: dataSize = 4u; break;
			case 1u: dataSize = 2u; break;
			default: dataSize = 1u;
		}
	}
	obj.bytes = dataSize;
	dataBig = ( dataSize > 4u );
	if ( addrBig || dataBig )
	{
		L_MO_HEX_GETPARTS( block, tzr, txt, line, prt1, prt2, hex, pt1, pt2, l, lEnd );
		val = dataBig ? hex : pt1;
	}
	else
		val = pt1;
	if ( isInc )
	{
		if ( dataBig || !addrBig )
		{
			L_MO_HEX_GETPARTS( block, tzr, txt, line, prt1, prt2, hex, pt1, pt2, l, lEnd );
			inc = dataBig ? hex : pt2;
		}
		else
			inc = pt2;
	}
	else if ( isList )
	{
		int v = 0, vEnd = obj.info;
		switch ( dataSize )
		{
			case 1u: vEnd /= 8; break;
			case 2u: vEnd /= 4; break;
			case 4u: vEnd /= 2; break;
		}
		obj.resize( obj.info );
		obj.bytes = 8u;
		for ( ; ( v < vEnd && l < lEnd ); ++v )
		{
			L_MO_HEX_GETPARTS( block, tzr, txt, line, prt1, prt2, hex, pt1, pt2, l, lEnd );
			*( reinterpret_cast< ui64* >( &(obj[v] ) ) ) = hex;
		}
		obj.bytes = dataSize;
	}
	data.push_back( obj );
	MakeObj_Hex1( data, block, l, lEnd );
}

bool xsDLL MakeHack_Hex_2( Hack& hack, TxtA& block, int& c, ui32& l, ui08& cCount )
{
// TODO(awsdert) Implement MakeHack_Hex_2()
	return false;
}
