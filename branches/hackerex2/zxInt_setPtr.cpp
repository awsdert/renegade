#include "zxInt.h"
bool zxInt::setPtr( void *source, ui08 size, bool isSigned, ui08 treatAs )
{
	clear();
	ui08 i = 0u, j = size - 1,
		*src = (ui08*)source,
		*des = src;
	if ( ( treatAs & 0xF ) == zxVar_t_copy )
	{
		treatAs &= 0xF0;
		if ( size == 0u )
			des = NULL;
		else
		{
			des = (ui08*)malloc( size );
			for ( ; i < size; ++i, --j )
				des[ i ] = src[ i ];
			treatAs |= zxVar_t_malloc;
		}
		m_ptr = NULL;
	}
	else
		m_ptr = &m_data;
	m_free	= treatAs;
	m_data	= des;
	m_size	= size;
	m_bits	= size * zxBITS_PER_BYTE;
	m_signed	= isSigned;
	m_lastByte	= size - 1;
	return ( des != NULL && size > 0u );
}
bool zxInt::grow( ui08 addBytes )
{
	if ( m_free & zxVar_t_allowGrow )
	{
		ui08 i = 0u, size = m_size + addBytes, *src;
		if ( size <= m_size )
			return false;
		ui08 isNeg = ( m_signed && m_data[ m_lastByte ] > 0x7F ) ? 0xFF : 0u;
		switch ( m_free & 0xF )
		{
		case zxVar_t_malloc:
			m_data = (ui08*)realloc( m_data, size );
			break;
#ifdef __cplusplus
		case zxVar_t_new:
			src = new ui08[ size ];
			for ( ; i < m_size; ++i )
				src[ i ] = m_data[ i ];
			delete [] m_data;
			m_data = src;
#endif
		default:
			return false;
		}
		for ( i = m_size; i < size; ++i )
			m_data[ i ] = isNeg;
		m_ptr = &m_data;
		m_size = size;
		return true;
	}
	else
		return false;
}