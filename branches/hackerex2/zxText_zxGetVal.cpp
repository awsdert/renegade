#include "zxText.h"
// Hex
zxDLL_EXP zxText zxGetHex( uill source )
{
	return zxUtoa( source, 16u );
}
zxDLL_EXP uill zxGetHex( zxText source )
{
	return zxAtou( source, 16u );
}
// Unsigned
zxDLL_EXP zxText zxGetUI( uill source )
{
	return zxUtoa( source );
}
zxDLL_EXP uill zxGetUI( zxText source )
{
	return zxAtou( source );
}
// Signed
zxDLL_EXP zxText zxGetSI( sill source )
{
	return zxItoa( source );
}
zxDLL_EXP sill zxGetSI( zxText source )
{
	return zxAtoi( source );
}