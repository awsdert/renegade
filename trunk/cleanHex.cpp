#include "cleanHex.h"
u64 GetHex( xStr text, u8 size )
{
	u64 value = 0u;
	if ( !text.IsEmpty() )
	{
		text.UpperCase();
		s32 i = 0, count = 0;
		wxChar c;
		u64 limit = UINT64_MAX;
		while ( ( c = text [ i ] ) && count < 17 )
		{
			if ( c >= c0 && c <= c9 )
			{
				if ( count < 16 )
				{
					c -= c0;
					value <<= 4u;
					value += c;
				}
				count++;
			}
			else if ( c >= cA && c <= cF )
			{
				if ( count < 16 )
				{
					c -= cA;
					value <<= 4u;
					value += ( c + 10u );
				}
				count++;
			}
			else if ( c == cSplit )
			{
				break;
			}
			i++;
		}
		switch ( size )
		{
			case 1u: limit = UINT8_MAX; break;
			case 2u: limit = UINT16_MAX; break;
			case 4u: limit = UINT32_MAX;
		}
		value = ( value > limit || count > 16 ) ? limit : value;
	}
	return value;
}
u64 GetHexFromU64( xStr text, u8 size )
{
	u64 value = 0u;
	if ( !text.IsEmpty() )
	{
		s32 index = 0, count = 0;
		wxChar c;
		u64 limit = UINT64_MAX;
		xStr tmp;
		tmp.Printf( wxT("%llu"), limit );
		s32 total = tmp.length();
		s32 total1 = total + 1;
		while ( ( c = text [ index ] ) && count < total1 )
		{
			if ( c >= c0 && c <= c9 )
			{
				if ( count < total )
				{
					c -= c0;
					value *= 10u;
					value += c;
				}
				count++;
			}
			else if ( c == cSplit )
			{
				break;
			}
			index++;
		}
		switch ( size )
		{
			case 1u: limit = UINT8_MAX; break;
			case 2u: limit = UINT16_MAX; break;
			case 4u: limit = UINT32_MAX;
		}
		value = ( value > limit || count > total ) ? limit : value;
	}
	return value;
}
u64 GetHexFromS64( xStr text, u8 size )
{
	u64 value = 0u;
	if ( !text.IsEmpty() )
	{
		bool isNeg = false;
		wxChar c;
		s32 i = 0;
		s64 v64 = 0;
		s64 limit = SINT64_MAX;
		if ( text[ 0 ] == cNeg )
		{
			i++;
			isNeg = true;
		}
		while ( ( c = text [ i ] ) && v64 >= 0 )
		{
			if ( c >= c0 && c <= c9 )
			{
				c -= c0;
				v64 *= 10u;
				v64 += c;
			}
			else if ( c == cSplit )
			{
				break;
			}
			i++;
		}
		switch ( size )
		{
			case 1u: limit = SINT8_MAX; break;
			case 2u: limit = SINT16_MAX; break;
			case 4u: limit = SINT32_MAX;
		}
		v64 = ( v64 > limit || v64 < 0 ) ? limit : v64;
		v64 = isNeg ? -v64 : v64;
		value = reinterpret_cast< u64 >( &v64 );
	}
	return value;
}
u64 GetHexFromF64( xStr text, u8 size )
{
	u64 value = 0u;
	if ( !text.IsEmpty() )
	{
		bool isNeg = false;
		bool isSplit = false;
		wxChar c;
		s32 i = 0;
		f64 v64 = 0;
		f64 limit = SFLT64_MAX;
		//u64 shift;
		if ( text[ 0 ] == cNeg )
		{
			i++;
			isNeg = true;
		}
		while ( ( c = text[ i ] ) && v64 >= 0 )
		{
			if ( c >= c0 && c <= c9 )
			{
				c -= c0;
				v64 *= 10;
				v64 += c;
			}
			else if ( c == cDot )
			{
				i++;
				isSplit = true;
				break;
			}
			else if ( c == cSplit )
			{
				break;
			}
			i++;
		}
		if ( !isSplit )
		{
			f64 tmp = 1;
			while ( ( c = text[ i ] ) && v64 >= 0 )
			{
				if ( c >= c0 && c <= c9 )
				{
					c -= c0;
					tmp /= 10;
					v64 += ( c * tmp );
				}
				else if ( c == cSplit )
				{
					break;
				}
				i++;
			}
		}
		switch ( size )
		{
			case 1u: case 2u: limit = 0; break;
			case 4u: limit = SFLT32_MAX;
		}
		v64 = ( v64 > limit || v64 < 0 ) ? limit : v64;
		v64 = isNeg ? -v64 : v64;
		if ( size == 4u )
		{
			f32 v32 = v64;
			u32 vtmp = reinterpret_cast< u32 >( &v32 );
			value = vtmp;
		}
		else
		{
			value = reinterpret_cast< u64 >( &v64 );
		}
	}
	return value;
}