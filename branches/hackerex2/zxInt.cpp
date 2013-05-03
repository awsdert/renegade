#include "zxInt.h"
zxInt::zxInt( void ) { m_clear(); }
zxInt::~zxInt( void ) { clear(); }
zxInt::zxInt( zxInt &value )
{
	m_clear();
	setPtr( value.m_data, value.m_size, value.m_signed, zxVar_t_copy );
}
zxInt& zxInt::operator= ( zxInt &value )
{
	setPtr( value.m_data, value.m_size, value.m_signed, zxVar_t_copy );
	return *this;
}
ui08& zxInt::operator[] ( ui08 index ) { return m_data[ index ]; }
// Unsigned
zxUInt::zxUInt( void ) { m_clear(); m_isUInt = true; }
zxUInt::~zxUInt( void ) { clear(); }
zxUInt::zxUInt( uill value )
{
	m_clear();
	m_isUInt = true;
	setPtr( &value, sizeof( uill ), false, zxVar_t_copy );
}
zxUInt::zxUInt( zxInt &value )
{
	m_clear();
	m_isUInt = true;
	setPtr( value.m_data, value.m_size, value.m_signed, zxVar_t_copy );
}
zxUInt& zxUInt::operator= ( zxUInt value )
{
	setPtr( value.m_data, value.m_size, false, zxVar_t_copy );
	return *this;
}
/* Signed */
zxSInt::zxSInt( void ) { m_clear(); m_isSInt = true; }
zxSInt::~zxSInt( void ) { clear(); }
zxSInt::zxSInt( sill value )
{
	m_clear();
	m_isSInt = true;
	setPtr( &value, sizeof( sill ), true, zxVar_t_copy );
}
zxSInt::zxSInt( zxInt &value )
{
	m_clear();
	m_isSInt = true;
	setPtr( value.m_data, value.m_size, value.m_signed, zxVar_t_copy );
}
zxSInt& zxSInt::operator= ( zxSInt value )
{
	setPtr( value.m_data, value.m_size, true );
	return *this;
}