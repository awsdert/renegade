#include "zxInt.h"
si08 zxInt::m_cmp( zxInt& value, bool *isSameType )
{
	si16 i = m_lastByte, j = value.m_lastByte;
	ui08
		*src = m_data,
		*val = value.m_data;
	bool sameType = ( m_signed == value.m_signed ), isNeg = false, vNeg = false;
	if ( isSameType != NULL )
		*isSameType = sameType;
	if ( !m_ignoreSign && !value.m_ignoreSign && !sameType )
		return -1;
	if ( m_signed || value.m_signed )
	{
		vNeg = ( value.m_signed && val[ j ] > 0x7F );
		if ( m_signed )
		{
			isNeg = ( src[ i ] > 0x7F );
			if ( isNeg && !vNeg )
				return -1;
			isNeg = ( isNeg || vNeg );
		}
		else
		{
			isNeg = vNeg;
			if ( vNeg )
				return 1;
		}
	}
	if ( isNeg )
	{
		for ( ; i > j; --i )
		{
			if ( src[ i ] != 0xFF )
				return -1;
		}
		for ( ; j > i; --j )
		{
			if ( val[ j ] != 0xFF )
				return 1;
		}
	}
	else
	{
		for ( ; i > j; --i )
		{
			if ( src[ i ] != 0u )
				return 1;
		}
		for ( ; j > i; --j )
		{
			if ( val[ j ] != 0u )
				return -1;
		}
	}
	for ( ; i >= 0; --i )
	{
		if ( src[ i ] != val[ i ] )
			return ( src[ i ] > val[ i ] ) ? 1 : -1;
	}
	return 0;
}
bool zxInt::operator==	( zxInt& obj ) { return ( m_cmp( obj ) ==	0 ); }
bool zxInt::operator!=	( zxInt& obj ) { return ( m_cmp( obj ) !=	0 ); }
bool zxInt::operator>	( zxInt& obj )
{
	bool isSameType = false;
	return ( m_cmp( obj, &isSameType ) >	0 && isSameType );
}
bool zxInt::operator>=	( zxInt& obj )
{
	bool isSameType = false;
	return ( m_cmp( obj, &isSameType ) >=	0 && isSameType );
}
bool zxInt::operator<	( zxInt& obj )
{
	bool isSameType = false;
	return ( m_cmp( obj, &isSameType ) <	0 && isSameType );
}
bool zxInt::operator<=	( zxInt& obj )
{
	bool isSameType = false;
	return ( m_cmp( obj, &isSameType ) <=	0 && isSameType );
}
/* Unsigned */
bool zxUInt::operator==	( zxUInt value ) { return ( m_cmp( value ) ==	0 ); }
bool zxUInt::operator!=	( zxUInt value ) { return ( m_cmp( value ) !=	0 ); }
bool zxUInt::operator>	( zxUInt value )
{
	bool isSameType = false;
	return ( m_cmp( value, &isSameType ) >	0 && isSameType );
}
bool zxUInt::operator>=	( zxUInt value )
{
	bool isSameType = false;
	return ( m_cmp( value, &isSameType ) >=	0 && isSameType );
}
bool zxUInt::operator<	( zxUInt value )
{
	bool isSameType = false;
	return ( m_cmp( value, &isSameType ) <	0 && isSameType );
}
bool zxUInt::operator<=	( zxUInt value )
{
	bool isSameType = false;
	return ( m_cmp( value, &isSameType ) <=	0 && isSameType );
}