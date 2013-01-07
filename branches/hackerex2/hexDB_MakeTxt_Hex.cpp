#include "wx_pch.h"
#include "hexDB_main.h"
void xsDLL Maketxt_Hex1( Code& obj, TxtA& block )
{
	TxtA vLines;
	ui64 v64 = 0u;
	int i, iEnd, j, jEnd, iAdd, b = 0;
	bool big, isTest, isList;
	Text hLine, aLine, vLine, iLine, txt;
	const wxChar* text = wxT("%08X %08X");
	ui32 val = 0u, h1 = 0u, h2 = 0u, a1 = 0u, a2 = 0u, v1 = 0u, v2 = 0u, i1 = 0u, i2 = 0u, t1 = 0u, t2 = 0u;
	// Address
	v64	= obj.addr[ 0 ];
	big	= ( v64 > xsF8LL );
	a2	= ( v64 & xsF8LL );
	a1	= ( v64 & ( xsF8LL << 32u ) );
	aLine.Printf( text, a1, a2 );
	// Part 2 of Code Header
	h2	= obj.addr[ 1 ];
	// Part 1 of Code Header
	val	= ( obj.type & 0xF );
	h1	= ( val << 28u );
	switch ( obj.bytes )
	{
		case 8u:
			iAdd = 1;
			val = 3u;
			break;
		case 4u:
			iAdd = 2;
			val = 2u;
			break;
		case 2u:
			iAdd = 3;
			val = 1u;
			break;
		default:
			iAdd = 4;
			val = 0u;
			break;
	}
	val	+= big ? 8u : 0u;
	h1	+= ( val << 24u );
	h1	+= ( obj.depth	<< 20u	);
	h1	+= ( obj.ram	<< 16u	);
	h1	+= ( obj.info	<< 8u	);
	h1	+= obj.loop;
	hLine.Printf( text, h1, h2 );
	// Value
	i	= 0;
	vLines.Clear();
	iEnd	= obj.info;
	isList	= ( obj.type == HEX_CT_LIST );
	do
	{
		txt.Printf( wxT("%08X %08X"),
					*( reinterpret_cast< ui32* >( &( obj.data[ b ] ) ) ),
					*( reinterpret_cast< ui32* >( &( obj.data[ b + 4 ] ) ) ) );
		vLines.Add( txt );
		if ( i == 0 )
		{
			v1 = t1;
			v2 = t2;
			vLine = txt;
		}
		b += 8;
		i += iAdd;
	}
	while ( isList && i < iEnd );
	// Value In/Decrement
	isTest = ( obj.type == HEX_CT_TEST );
	if ( isList || isTest )
	{
		i1 = 0u;
		i2 = 0u;
	}
	else
	{
		v64 = 0u;
		jEnd = obj.bytes;
		for ( j = 0; j < jEnd; ++j )
		{
			v64 <<= 8u;
			v64  += obj.data[ j ];
		}
		for ( ; j < 8; ++j )
			v64 <<= 8u;
		i2 = ( v64 & xsF8LL );
		i1 = ( v64 & ( xsF8LL << 32u ) );
	}
	iLine.Printf( text, i1, i2 );
	// Join the above together
	block.Add( hLine );
	if ( isList )
	{
		block.Add( aLine );
		iEnd = vLines.GetCount();
		for ( i = 0; i < iEnd; ++i )
			block.Add( vLines[ i ] );
	}
	else if ( obj.bytes == 8u )
	{
		block.Add( aLine );
		block.Add( vLine );
		if ( !isTest )
			block.Add( iLine );
	}
	else if ( big )
	{
		block.Add( aLine );
		if ( isTest )
			block.Add( vLine );
		else
		{
			v1 = v2;
			v2 = i2;
			txt.Printf( text, v1, v2 );
			block.Add( txt );
		}
	}
	else
	{
		a1 = v2;
		txt.Printf( text, a1, a2 );
		block.Add( txt );
		if ( !isTest )
			block.Add( iLine );
	}
}
void xsDLL MakeTxt_Hex1( Codes& data, TxtA& block )
{
	Code obj;
	int c = 0, cEnd = data.size();
	for ( ; c < cEnd; ++c )
	{
		obj	= data[ c ];
		if ( obj.depth > 0xF || obj.loop > 0xFF || obj.addr[ 1 ] > xsF8LL )
			return;
		Maketxt_Hex1( data[ c ], block );
	}
}
