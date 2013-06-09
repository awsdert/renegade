#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHex( void* to, Text  from, ui08 bytes, ui08 tType )
{
	zxUInt src, val;
	src.setPtr( to, bytes );
	if ( bytes > 32u )
	{
		src = 0u;
		return false;
	}
	switch ( tType )
	{
	case HEX_TYPE_HEX:	val = parseInt( from, 16u ); break;
	case HEX_TYPE_UI:
	case HEX_TYPE_SI:   val = parseInt( from ); break;
	default:
		src = 0u;
		return false;
	}
	src.copy( val.m_data, val.m_size );
	return true;
}
Text xsDLL GetTxt( void* from, ui08 bytes, ui08 fType )
{
	zxInt val;
	val.setPtr( from, bytes );
	switch ( fType )
	{
	case HEX_TYPE_HEX:
		return val.toString( 16u );
	case HEX_TYPE_SI:
		val.m_signed = true;
	case HEX_TYPE_UI:
		return val.toString();
	default:
		return wxT('0');
	}
}