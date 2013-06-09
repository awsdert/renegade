#include "zxText.h"
zxText zxText::substr( si32 iStart, si32 iEnd )
{
	zxText txt;
	int i = iStart, j = 0;
	if ( iEnd < 0 || iEnd > m_count )
		iEnd = m_count;
	txt.resize( iEnd - i );
	for ( ; i < iEnd; ++i, ++j )
		txt.m_data[ j ] = m_data[ i ];
	return txt;
}