#include "hexMain.h"
#include <wx/defs.h>
u64 ME::getHEX( xStr s, u64 limit )
{
	u32 i = 0u;
	s32 j = 0;
	u64 value = 0u;
	u64 tmp = 0u;
	s = s.Upper();
	wxChar c;
	const wxChar n0 = wxT('0');
	const wxChar n9 = wxT('9');
	const wxChar nA = wxT('A');
	const wxChar nF = wxT('F');
	limit = ( limit > 0u ) ? limit : 0xFFFFFFFFFFFFFFFFLL;
	while ( ( c = s[ i ] ) )
	{
		if ( c >= n0 && c <= n9 )
		{
			value <<= 4u;
			tmp = value + ( c - n0 );
			j++;
		}
		else if ( c >= nA && c <= nF )
		{
			value <<= 4u;
			tmp = value + ( ( c - nA ) + 10u );
			j++;
		}
		else
		{
			tmp = value;
		}
		if ( tmp > limit || j > 16 )
		{
			value = limit;
			break;
		}
		value = tmp;
		i++;
	}
	return value;
}
u64 ME::getHEXFromDecimal( xStr text, u64 uSize )
{
	u32 i = 0u;
	u32 j = 0u;
	xStr tmpText;
	u64 value = 0u;
	u64 limit = 0xFFFFFFFFFFFFFFFFLL;
	wxChar c;
	const wxChar n0 = wxT('0');
	const wxChar n9 = wxT('9');
	if ( uSize > 0u )
	{
		limit = uSize;
	}
	tmpText.Printf( wxT("%lli"), limit );
	while ( ( c = text[ i ] ) )
	{
		if ( c >= n0 && c <= n9 )
		{
			if ( value > limit || j >= tmpText.length() )
			{
				value = limit;
				break;
			}
			value *= 10u;
			value += ( c - n0 );
			j++;
		}
		i++;
	}
	return value;
}
u64 ME::getHEXFromSignedDecimal( xStr text, u64 uSize )
{
	u32 i = 0u;
	u32 j = 0u;
	xStr tmpText;
	s64 value = 0;
	s64 limit = 0;
	wxChar c;
	const wxChar n0 = wxT('0');
	const wxChar n9 = wxT('9');
	if ( text[0] == wxT('-') )
	{
		switch ( uSize )
		{
			case 0xFF:
				limit = SINT8_MIN;
				break;
			case 0xFFFF:
				limit = SINT16_MIN;
				break;
			case 0xFFFFFFFF:
				limit = SINT32_MIN;
				break;
			default:
				limit = SINT64_MIN;
		}
		tmpText.Printf( wxT("%lli"), limit ); j++; i++;
		while ( ( c = text[ i ] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				if ( value < limit || j >= tmpText.length() )
				{
					value = limit;
					break;
				}
				value *= 10;
				value -= ( c - n0 );
				j++;
			}
			i++;
		}
	}
	else
	{
		switch ( uSize )
		{
			case 0xFF:
				limit = SINT8_MAX;
				break;
			case 0xFFFF:
				limit = SINT16_MAX;
				break;
			case 0xFFFFFFFF:
				limit = SINT32_MAX;
				break;
			default:
				limit = SINT64_MAX;
		}
		tmpText.Printf( wxT("%lli"), limit );
		while ( ( c = text[ i ] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				if ( value > limit || j >= tmpText.length() )
				{
					value = limit;
					break;
				}
				value *= 10;
				value += ( c - n0 );
				j++;
			}
			i++;
		}
	}
	u64 is = 0u;
	u32 shiftBy = 0u;
	u32 bitLimit = 0u;
	u8 v8 = 0u;
	u16 v16 = 0u;
	u32 v32 = 0u;
	switch ( uSize )
	{
		case 0xFF: bitLimit = 8u; break;
		case 0xFFFF: bitLimit = 16u; break;
		case 0xFFFFFFFF: bitLimit = 32u; break;
		default: bitLimit = 0u;
	}
	for ( i = 0u; i < bitLimit; i++ )
	{
		shiftBy = 1u;
		shiftBy <<= i;
		if ( i < 8u )
		{
			v8 = v8 | ( value & shiftBy );
		}
		if ( i < 16u )
		{
			v16 = v16 | ( value & shiftBy );
		}
		v32 = v32 | ( value & shiftBy );
	}
	switch ( bitLimit )
	{
		case 8u: is = 0u | v8; break;
		case 16u: is = 0u | v16; break;
		case 32u: is = 0u | v32; break;
		default: is = 0u | value;
	}
	return is;
}
u64 ME::getHEXFromFloat( xStr text, u64 uSize )
{
	u32 i = 0u;
	xStr s;
	xStrT st;
	f64 value1 = 0;
	f64 value2 = 0;
	f64 value3;
	f64 limit;
	wxChar c;
	const wxChar n0 = wxT('0');
	const wxChar n9 = wxT('9');
	st.SetString( text, wxT('.') );
	s = st.GetNextToken();
	if ( s[0] == wxT('-') )
	{
		while ( ( c = s[i] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				value1 *= 10;
				value1 -= ( c - n0 );
			}
			i++;
		}
		s = st.GetNextToken();
		i = 0;
		while ( ( c = s[i] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				value3 = ( c - n0 );
				value2 -= ( value3 / pow( 10, value3 ) );
			}
			i++;
		}
		value3 = value1 + value2;
		limit = 1e-37;
		value3 = ( value3 < limit ) ? limit : value3;
	}
	else
	{
		while ( ( c = s[i] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				value1 *= 10;
				value1 += ( c - n0 );
			}
			i++;
		}
		s = st.GetNextToken();
		i = 0;
		while ( ( c = s[i] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				value3 = ( c - n0 );
				value2 += ( value3 / pow( 10, value3 ) );
			}
			i++;
		}
		value3 = value1 + value2;
		limit = 1e+37;
		value3 = ( value3 > limit ) ? limit : value3;
	}
	u64 is = 0u;
	u32 v32 = 0x0;
	u64 shiftBy = 0x0;
	u64 valueU = *(&value3);
	switch ( uSize )
	{
		case 0xFF:
		case 0xFFFF:
			is = 0u;
			break;
		case 0xFFFFFFFF:
			for ( i = 63u; i > 56u; i-- )
			{
				shiftBy = 0x1;
				shiftBy <<= i;
				v32 = v32 | ( ( valueU & shiftBy ) >> 32u );
			}
			for ( i = 0u; i < 26u; i++ )
			{
				shiftBy = 0x1;
				shiftBy <<= i;
				v32 = v32 | ( valueU & shiftBy );
			}
			is = 0u | v32;
			break;
		default:
			is = valueU;
	}
	return is;
}
