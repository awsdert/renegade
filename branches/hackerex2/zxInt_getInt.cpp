#include "zxInt.h"
unsigned int zxUInt::getInt( void )
{
	unsigned int val = 0u;
	if ( m_size <= sizeof( unsigned int ) )
	{
		ui08* ptr = (ui08*)&val, i = 0u;
		for ( ; i < m_size; ++i )
			ptr[ i ] = m_data[ i ];
	}
	return val;
}
unsigned int long long zxUInt::getIntLL( void )
{
	unsigned int long long val = 0u;
	if ( m_size <= sizeof( unsigned int long long ) )
	{
		ui08* ptr = (ui08*)&val, i = 0u;
		for ( ; i < m_size; ++i )
			ptr[ i ] = m_data[ i ];
	}
	return val;
}