#include "wx_pch.h"
#include "hexDB_hexIO.h"
bool xsDLL GetHexFromUI( void* to, Text  from, ui08 tSize )
{
	zxInt des, val;
	des.setPtr( to, tSize );
	val = parseInt( from );
	des.copy( val.m_data, val.m_size );
	return true;
}
Text xsDLL GetTxtFromUI( void* from, ui08 Bytes )
{
	zxInt val;
	val.setPtr( from, Bytes );
	return val.toString();
}