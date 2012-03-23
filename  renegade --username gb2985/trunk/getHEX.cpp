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
				limit = -128;
				break;
			case 0xFFFF:
				limit = -32767;
				break;
			case 0xFFFFFFFF:
				limit = -2147483647;
				break;
			default:
				limit = -3028092406290448383LL;
		}
		tmpText.Printf( wxT("%lli"), limit );
		while ( ( c = text[ i ] ) )
		{
			if ( c >= n0 && c <= n9 )
			{
				if ( value < limit || j >= ( tmpText.length() - 1 ) )
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
				limit = 127;
				break;
			case 0xFFFF:
				limit = 32767;
				break;
			case 0xFFFFFFFF:
				limit = 2147483647;
				break;
			default:
				limit = 3028092406290448383LL;
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
	return static_cast < u64 > ( value );
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
		limit = 1e+38;
		value3 = ( value3 < limit ) ? limit : value3;
	}
	return static_cast < u64 > ( value3 );
}
