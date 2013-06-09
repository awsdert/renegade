#include "zxText.h"

void zxText::append( zxText text )
{
	int i = m_count, j = 0u;
	resize( i + text.m_count );
	for ( ; i < m_count; ++i, ++j )
		m_data[ i ] = text[ j ];
}
void zxText::insertBefore( zxText text, si32 pos )
{
	int end = m_count;
	// FIXME: THIS NOT COMPLETE
	resize( end + text.m_count );
}