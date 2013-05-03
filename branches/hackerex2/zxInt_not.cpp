#include "zxInt.h"
void zxInt::m_not( zxInt& source )
{
	ui08 i = 0u,
		size = source.m_size,
		*src = source.m_data;
	for ( ; i < size; ++i )
		src[ i ] = ~src[ i ];
}
zxInt	zxInt::operator~	( void )
{
	zxInt obj( *this );
	m_not( obj );
	return obj;
}