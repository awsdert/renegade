#include "zxText.h"
// Needed for zxPrintf
zxDLL_EXP zxText zxUtoa( unsigned long long int src, ui08 base )
{
	zxText des, des2, cmp = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if ( base < 2u || base > cmp.length() )
	{
		des = "0";
		return des;
	}
	si16 j;
	unsigned long long int val = 0u;
	while ( src > 0u )
	{
		val = src;
		for ( j = 0; val >= base; ++j )
			val /= base;
		if ( val > 0u || !des.empty() )
			des += cmp[ val & 0xFFLL ];
		for ( ; j > 0; --j )
			val *= base;
		src -= val;
	}
	if ( des.empty() )
		des = "0";
	return des;
}
zxDLL_EXP zxText zxItoa( signed long long int src, ui08 base )
{
	bool neg = ( src < 0 );
	zxText txt;
	if ( src == 0 )
		txt = '0';
	else if ( neg && base == 10u )
	{
		src *= -1;
		txt = zxUtoa( src, base );
		txt.insert( 0, zxT('-') );
	}
	else
		txt = zxUtoa( src, base );
	return txt;
}