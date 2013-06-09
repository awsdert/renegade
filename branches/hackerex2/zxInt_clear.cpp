#include "zxInt.h"
void zxInt::m_clear( void )
{
	m_ptr	= NULL;
	m_data	= NULL;
	m_size	= 0u;
	m_bits	= 0u;
	m_free	= 0u;
	m_isUInt = false;
	m_isSInt = false;
	m_signed = false;
	m_ignoreSign = false;
}
void zxInt::clear( void )
{
	switch ( m_free & 0xF )
	{
	case zxVar_t_malloc: free( m_data ); break;
#ifdef __cplusplus
	case zxVar_t_new: delete [] m_data; break;
#endif
	}
	m_ptr	= NULL;
	m_data	= NULL;
	m_free	= 0u;
	m_bits	= 0u;
	m_size	= 0u;
	m_signed = false;
	m_ignoreSign = false;
}