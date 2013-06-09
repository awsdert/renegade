#include "main.h"
#define L_MO_HEX_GETPARTS \
	if ( l >= lEnd ) \
		return; \
	txt		= block[ l ]; \
	hex = zxGetHex( txt.data() ).getIntLL(); \
	pt1 = ( hex >> 32u ); \
	pt2 = ( hex & zxF8LL ); \
	++l
void fmtGetCode( Code& obj, TxtA& block, int& l, int& lEnd )
{
	Text txt;
	ui64 hex;
	ui32 pt1, pt2;
	ui08 dataSize;
	L_MO_HEX_GETPARTS;
	obj.type	= (( 0xF0000000 & pt1 ) >> 28u );
	dataSize	= (( 0x0F000000 & pt1 ) >> 24u );
	obj.ram		= (( 0x00F00000 & pt1 ) >> 20u );
	obj.depth	= (( 0x000F0000 & pt1 ) >> 16u );
	obj.info	= (( 0x0000FF00 & pt1 ) >>  8u );
	obj.loop	=  ( 0x000000FF & pt1 );
	obj.addr[ 1u ] = pt2;
	bool isList = ( obj.type == CODE_LIST );
	bool isCopy = ( obj.type == CODE_COPY );
	bool isTest = ( obj.type == CODE_TEST );
	bool isInc = ( !isList && !isTest && !isCopy && obj.loop > 0u );
	bool dataBig = false;
	bool addrBig = ( isList || ( dataSize & 0x8 ) == 0x8 );
	if ( isCopy )
		dataBig = addrBig;
	if ( isInc && ( dataSize & 0x4 ) == 0x4 )
		isInc = false;
	dataSize &= 0x3;
	switch ( dataSize )
	{
		case 3u:
			dataSize = 8u;
			dataBig = true;
			addrBig = true;
			break;
		case 2u: dataSize = 4u; break;
		case 1u: dataSize = 2u; break;
		default: dataSize = 1u;
	}
	obj.bytes = dataSize;
	L_MO_HEX_GETPARTS;
	obj.resize( 2, 0u );
	if ( isList )
	{
		obj.addr[ 0 ] = hex;
		int v = 0, vEnd = obj.info, vAdd = (8u / dataSize), b = 0;
		while ( v < vEnd )
		{
			v += vAdd;
			++b;
		}
		obj.resize( b, 0uLL );
		v = 0; b = 0;
		while ( v < vEnd )
		{
			L_MO_HEX_GETPARTS;
			obj[b] = hex;
			v += vAdd;
			++b;
		}
	}
	else if ( dataBig )
	{
		obj.addr[ 0 ] = hex;
		L_MO_HEX_GETPARTS;
		obj[ 0 ] = hex;
		if ( isInc )
		{
			L_MO_HEX_GETPARTS;
			obj[1] = hex;
		}
	}
	else if ( addrBig )
	{
		obj.addr[ 0 ] = hex;
		L_MO_HEX_GETPARTS;
		obj[0] = pt1;
		obj[1] = pt2;
	}
	else
	{
		obj.addr[ 0 ] = pt2;
		obj[0] = pt1;
		if ( isInc )
		{
			L_MO_HEX_GETPARTS;
			obj[1] = pt2;
		}
	}
}