#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHexFromSI( void* to, Text  from, ui08 tSize )
{
	zxInt des, val;
	des.setPtr( to, tSize );
	val = parseInt( from );
	des.copy( val.m_data, val.m_size );
	return true;
}
Text xsDLL GetTxtFromSI( void* src, ui08 size )
{
	zxInt val;
	val.setPtr( src, size );
	return val.toString();
}
