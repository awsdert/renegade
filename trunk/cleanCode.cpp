#include "cleanAll.h"
#define BuildCode_Add() \
part1.Printf( hex32, p1 ); \
part2.Printf( hex32, p2 ); \
array.Add( part1 + wxT(" ") + part2 )
xAStr BuildCode( CODE& code )
{
	u64   tmp   = code.type;
	u32   p1    = tmp << 28u, p2 = code.increment;
	xStr  part1, part2;
	xAStr array( 0 );
	s8 tmpV = gGetSSize( code.size );
	tmp = ( tmpV >= 0 ) ? tmpV : 0u;
	if ( code.byte > UINT32_MAX ) tmp += 8u;
	p1 += tmp << 24u;
	p1 += BitLeft( u32, code.ptrDepth, 20u );
	p1 += BitLeft( u32, code.ram, 16u );
	p1 += BitLeft( u32, code.test, 8u );
	p1 += code.loop;
	BuildCode_Add();
	if ( code.type == CT_LIST )
	{
		p1 = code.byte >> 32u;
		p2 = code.byte << 32u >> 32u;
		BuildCode_Add();
		xStr text, txt, vText, kText;
		s8 k, kCount, vCount = code.GetCount();
		switch ( code.size )
		{
			case 1u:
				kCount = 8;
				vText = hex8LL;
				kText = wxT( "00" );
				break;
			case 2u:
				kCount = 4;
				vText = hex16LL;
				kText = wxT( "0000" );
				break;
			case 4u:
				kCount = 2;
				vText = hex32LL;
				kText = hex0;
				break;
			default:
				kCount = 1;
				vText = hex64;
				kText = hex0 + hex0;
		}
		if ( vCount > code.test ) vCount = code.test;
		for ( s8 v = 0; v < vCount; )
		{
			text.Clear();
			for ( k = 0; ( k < kCount && v < vCount ); ++k, ++v )
			{
				txt.Printf( vText, code[ v ] );
				text += txt;
			}
			for ( ; k < kCount; ++k ) text += kText;
			p1 = GetHex( text.Mid( 0, 8 ), 4u );
			p2 = GetHex( text.Mid( 8, 8 ), 4u );
			BuildCode_Add();
		}
	}
	else
	{
		p2 = ( code.byte & UINT32_MAX );
		if ( !( code.byte > UINT32_MAX ) && code.size > 4u ) tmp += 8u;
		if ( ( tmp & 8u ) > 0u )
		{
			p1 = ( code.byte >> 32u );
			BuildCode_Add();
			p1 = ( code[ 0 ] >> 32u );
			p2 = ( code[ 0 ] & UINT32_MAX );
			BuildCode_Add();
			if ( code.type != CT_COPY && code.loop > 0u )
			{
				p1 = ( code.slide >> 32u );
				p2 = ( code.slide & UINT32_MAX );
				BuildCode_Add();
			}
		}
		else
		{
			p1 = ( code[ 0 ] & UINT32_MAX );
			BuildCode_Add();
			if ( code.type != CT_COPY && code.loop > 0u )
			{
				p1 = 0u;
				p2 = ( code.slide & UINT32_MAX );
				BuildCode_Add();
			}
		}
	}
	return array;
}
#define BuildCode_Inc() ++index; \
if ( index < count ) st.SetString( array[ index ], wxT( " " ) ); \
else st.SetString( hex0 + wxT( " " ) + hex0, wxT( " " ) ); \
part1 = st.GetNextToken(); \
part2 = st.GetNextToken()
void BuildCode( CODE& code, s32 &index, xAStr &array )
{
	code.Clear();
	s32 count = array.GetCount();
	if ( index < 0 || index >= count || count == 0 ) return;
	xStr  text, part1, part2, bText, vText, iText;
	xStrT st;
	st.SetString( array[ index ], wxT( ";" ) );
	text      = st.GetNextToken();
	st.SetString( text, wxT( " " ) );
	part1     = st.GetNextToken();
	part2     = st.GetNextToken();
	code.type = GetHex( part1[ 0 ], 1u );
	u64 value = GetHex( part1[ 1 ], 1u );
	if ( value > 8u )
	{
		value         -= 8u;
		code.isBigByte = true;
	}
	code.size      = gGetUSize( ( s8 )value );
	code.ptrDepth  = GetHex( part1[ 2 ], 1u );
	code.ram       = GetHex( part1[ 3 ], 1u );
	code.test      = GetHex( part1.Mid( 4, 2 ), 1u );
	code.loop      = GetHex( part1.Mid( 6, 2 ), 1u );
	code.increment = GetHex( part2, 4u );
	BuildCode_Inc();
	if ( code.type == CT_LIST )
	{
		u8 j     = 0u;
		u8 nowC  = 0u;
		u8 nextC = 0u;
		if ( code.isBigByte ) bText = part1 + part2;
		else bText = part2;
		code.SetCount( code.test );
		for  ( ; ( index < count && j < code.test ); )
		{
			BuildCode_Inc();
			nowC  = 0u;
			nextC = code.size * 2u;
			text  = part1 + part2;
			vText.Clear();
			for ( ; ( nextC <= 16u && j < code.test ); ++nowC )
			{
				if ( nowC == nextC )
				{
					nextC += code.size * 2u;
					code[ j ] = GetHex( vText );
					vText.Clear();
					++j;
				}
				vText += text[ nowC ];
			}
		}
	}
	else
	{
		if ( code.isBigByte || code.size > 4u )
		{
			bText = part1 + part2;
			BuildCode_Inc();
			if ( code.size > 4u )
			{
				vText = part1 + part2;
				if ( code.loop > 0u && code.type != CT_COPY )
				{
					BuildCode_Inc();
					iText = part1 + part2;
				}
			}
			else
			{
				vText = part1;
				iText = part2;
			}
		}
		else
		{
			vText = part1;
			bText = part2;
			if ( code.loop > 0u && code.type != CT_COPY )
			{
				BuildCode_Inc();
				iText = part2;
			}
		}
		code.SetCount( 1 );
		code[ 0 ] = GetHex( vText );
	}
	code.byte  = GetHex( bText );
	code.slide = GetHex( iText );
	++index;
}
