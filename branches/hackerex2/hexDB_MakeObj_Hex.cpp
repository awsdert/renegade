#include "hexDB_main.h"
#define L_MO_HEX_GETPARTS \
	if ( l >= lEnd ) \
		return; \
	txt		= block[ l ]; \
	prt1	= txt.Left( 8 ); \
	prt2	= txt.Right( 8 ); \
	line	= prt1 + prt2; \
	GetHex( &hex, line, 8u ); \
	pt1 = ( hex >> 32u ); \
	pt2 = ( hex & xsF8LL ); \
	++l
void Makeobj_Hex1( Codes& data, TxtA& block, int& l, int& lEnd, int& c, int& cEnd )
{
	Text txt, line, prt1, prt2;
	ui64 hex, val, inc;
	ui32 pt1, pt2;
	ui08 dataSize, addrSize = 4u;
	Code obj;
	L_MO_HEX_GETPARTS;
	obj.type	= (( 0xF0000000 & pt1 ) >> 28u );
	dataSize	= (( 0x0F000000 & pt1 ) >> 24u );
	obj.ram		= (( 0x00F00000 & pt1 ) >> 20u );
	obj.depth	= (( 0x000F0000 & pt1 ) >> 16u );
	obj.info	= (( 0x0000FF00 & pt1 ) >>  8u );
	obj.loop	=  ( 0x000000FF & pt1 );
	obj.addr[ 1u ] = pt2;
	L_MO_HEX_GETPARTS;
	bool addrBig = false;
	bool dataBig = false;
	bool isList = ( obj.type == HEX_CT_LIST );
	bool isCopy = ( obj.type == HEX_CT_COPY );
	bool isTest = ( obj.type == HEX_CT_TEST );
	bool isInc = ( !isList && !isTest && !isCopy && obj.loop > 0u );
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
		L_MO_HEX_GETPARTS;
		val = dataBig ? hex : pt1;
	}
	else
		val = pt1;
	if ( isInc )
	{
		if ( dataBig || !addrBig )
		{
			L_MO_HEX_GETPARTS;
			inc = dataBig ? hex : pt2;
		}
		else
			inc = pt2;
		switch ( obj.bytes )
		{
			case 4u:
				val <<= 32u;
				inc <<= 32u;
				break;
			case 2u:
				val <<= 48u;
				inc <<= 48u;
				break;
			case 1u:
				val <<= 56u;
				inc <<= 56u;
				break;
		}
		*( reinterpret_cast< ui64* >( &( obj[0] ) ) ) = val;
		*( reinterpret_cast< ui64* >( &( obj[1] ) ) ) = inc;
	}
	else if ( isList )
	{
		int v = 0, vEnd = obj.info, vAdd = 1, b = 0, j;
		switch ( dataSize )
		{
			case 4u: vAdd = 2; break;
			case 2u: vAdd = 4; break;
			case 1u: vAdd = 8; break;
		}
		obj.resize( obj.info );
		do
		{
			L_MO_HEX_GETPARTS;
			*( reinterpret_cast< ui32* >( &( obj.data[ b ] ) ) ) = pt1;
			*( reinterpret_cast< ui32* >( &( obj.data[ b + 4 ] ) ) ) = pt2;
			v += vAdd;
			b += 8;
		}
		while ( v < vEnd );
	}
	else if ( isTest )
	{

	}
	if ( c < cEnd )
		data[ c ] = obj;
	else
		data.push_back( obj );
	if ( l >= lEnd )
		return;
	Makeobj_Hex1( data, block, l, lEnd, ++c, cEnd );
}
void xsDLL MakeObj_Hex1( Codes& data, TxtA& block )
{
	int l = 0, lEnd = block.GetCount(), c = 0, cEnd = data.size();
	Makeobj_Hex1( data, block, l, lEnd, c, cEnd );
}
bool xsDLL MakeHack_Hex_2( Hack& hack, TxtA& block, int& c, ui32& l, ui08& cCount )
{
// TODO(awsdert) Implement MakeHack_Hex_2()
	return false;
}
