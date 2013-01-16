#include "wx_pch.h"
#include "hexDB_main.h"
void xsDLL Maketxt_Hex1( Code& obj, TxtA& block )
{
	TxtA vLines;
	ui64 v64 = 0u;
	int i, iEnd, iAdd, b = 0;
	bool big,
		isTest = ( obj.type == HEX_CT_TEST ),
		isList = ( obj.type == HEX_CT_LIST ),
		isCopy = ( obj.type == HEX_CT_COPY ),
		isInc  = ( !isList && !isTest && !isCopy && obj.loop > 0u );
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
	h2	= ( obj.addr[ 1 ] & xsF8LL );
	// Part 1 of Code Header
	val	= ( obj.type & 0xF );
	h1	= ( val << 28u );
	switch ( obj.bytes )
	{
		case 8u: val = 3u; break;
		case 4u: val = 2u; break;
		case 2u: val = 1u; break;
		default: val = 0u; break;
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
	iAdd	= isList ? ( 8 / obj.bytes ) : 1;
	iEnd	= isList ? obj.info : 1;
	do
	{
		v64 = obj[ b ];
		t1 = ( v64 >> 32u );
		t2 = ( v64 & xsF8LL );
		txt.Printf( text, t1, t2 );
		vLines.Add( txt );
		if ( i == 0 )
		{
			v1 = t1;
			v2 = t2;
			vLine = txt;
		}
		else if ( i == 1 )
		{
			i1 = t1;
			i2 = t2;
			iLine = txt;
		}
		++b;
		i += iAdd;
	}
	while ( i <= iEnd );
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
		if ( isInc )
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
		txt.Printf( text, v2, a2 );
		block.Add( txt );
		if ( isInc )
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
