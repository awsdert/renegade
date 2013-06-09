#include "zxInt.h"
void showHex( void* value, ui08 size )
{
	ui08 *val = (ui08*)value;
	for ( ui08 i = size - 1u; size > 0u; --i, --size )
		printf( "%02X", val[ i ] );
}
zxInt parseInt( zxText src, ui08 base )
{
	zxText cmp = zxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
	zxUInt des = 0u;
	if ( src.empty() )
		return des;
	if ( base < 2u || base > cmp.length() )
		return des;
	ui08 j, size = des.m_size;
	ui32 i = 0u, end = src.length();
	for ( ; i < end; ++i )
	{
		for ( j = 0u; j < base; ++j )
		{
			if ( src[ i ] == cmp[ j ] )
			{
				des *= base;
				des += j;
				break;
			}
		}
	}
	if ( src[ 0 ] == '-' )
		des = ~des;
	des.m_signed = ( src[ 0 ] == '-' || src[ 0 ] == '+' );
	return des;
}
zxText zxInt::toString( ui08 base )
{
	zxText des, des2, cmp = zxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
	if ( m_data == NULL || m_size == 0u || base < 2u || base > cmp.length() )
	{
		des = "0";
		return des;
	}
	si16 j;
	ui08 last = m_size - 1u;
	zxUInt src = *this, val = 0u;
	if ( m_signed && src[ last ] > 0x7F )
		src *= -1;
	while ( src > 0u )
	{
		val = src;
		for ( j = 0; val >= base; ++j )
			val /= base;
		if ( val > 0u || !des.empty() )
			des += cmp[ val[ 0u ] ];
		for ( ; j > 0; --j )
			val *= base;
		src -= val;
	}
	if ( des.empty() )
		des = "0";
	if ( m_signed && m_data[ last ] > 0x7F )
		des.insert( '-', 0 );
	return des;
}