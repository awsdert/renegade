#include "zxText.h"
zxDLL_EXP uill zxAtou( zxText src, ui08 base )
{
	zxText cmp = zxT( "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" );
	if ( src.empty() || base < 2u || base > cmp.length() )
		return 0u;
	uill des = 0u;
	ui08 j;
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
	return des;
}
zxDLL_EXP sill zxAtoi( zxText src, ui08 base )
{
	sill val = 0;
	if ( !src.empty() )
	{
		bool neg = ( src[ 0 ] == '-' );
		if ( neg )
			src = src.substr( 1, src.length() - 1 );
		if ( neg && base == 10u )
		{
			val = zxAtou( src, base );
			val *= -1;
		}
		else
			val = zxAtou( src, base );
	}
	return val;
}