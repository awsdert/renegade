#include "zxText.h"

void zxText::m_printf( zxText fmt, ... )
{
	va_list args;
	va_start( args, fmt );
	unsigned long long int uVal;
	signed long long int sVal;
	bool bVal;
	ui08 size = 0u, base = 10u;
	zxText txt, out, tmp, padb;
	ui32 i = 0u, len = fmt.length(), j, jend;
	bool app = false, pad = false, check = false, isSigned = false;
	TCHAR c, padc;
	for ( ; i < len; ++i )
	{
		c = fmt[ i ];
		if ( app )
		{
			if ( pad )
			{
				jend = atoi( padb.data() ) - txt.length();
				if ( isSigned )
				{
					out += txt[ 0 ];
					txt = txt.substr( 1, txt.length() );
				}
				for ( j = 0u; j < jend; ++j )
					out += txt;
				pad = false;
			}
			out += txt;
			txt.clear();
			app = false;
			isSigned = false;
			size = 0u;
		}
		if ( check )
		{
			app = true;
			switch ( c )
			{
			case zxT(' '):
			case zxT('0'):
				padc = c;
				for ( j = i; j < len; ++j, ++i )
				{
					c = fmt[ i ];
					if ( c >= 48 && c <= 57 )
						padb += c;
					else
						break;
				}
				--i;
				pad = true;
				app = false;
				break;
			case zxT('l'):
				size += ( size < 2u ) ? 1u : 0u;
				app = false;
				break;
			case zxT('d'):
			case zxT('i'):
			{
				switch ( size )
				{
					case 2u:
						sVal = va_arg( args, signed long long int );
						break;
					case 1u:
						sVal = va_arg( args, signed long int );
						break;
					default:
						sVal = va_arg( args, signed int );
						break;
				}
				txt = zxItoa( sVal );
				isSigned = ( txt[ 0 ] == zxT('-') );
				break;
			}
			case zxT('x'):
			case zxT('X'):
			case zxT('u'):
			case zxT('B'):
			{
				switch ( size )
				{
					case 2u:
						uVal = va_arg( args, unsigned long long int );
						break;
					case 1u:
						uVal = va_arg( args, unsigned long int );
						break;
					default:
						uVal = va_arg( args, unsigned int );
						break;
				}
				switch ( c )
				{
					case zxT('u'): txt = zxUtoa( uVal ); break;
					case zxT('x'): txt = zxUtoa( uVal, 16u ); txt.toLowerCase(); break;
					case zxT('X'): txt = zxUtoa( uVal, 16u ); break;
					case zxT('B'): txt = zxUtoa( uVal, 2u ); break;
				}
				break;
			}
			case zxT('b'):
				bVal = va_arg( args, bool );
				txt = bVal ? "true" : "false";
				break;
			case zxT('s'):
				txt = va_arg( args, char* );
				break;
			}
		}
		else if ( c == zxT('%') )
		{
			if ( i + 1 < len && fmt[ i + 1 ] != zxT('%') )
				check = true;
			else
			{
				out += c;
				++i;
			}
		}
		else
			out += c;
	}
	va_end( args );
	resize( 0u );
	append( out );
}
zxDLL_EXP zxText zxPrintf( zxText fmt, ... )
{
	zxText val;
	va_list args;
	va_start( args, fmt );
	val.m_printf( fmt, args );
	va_end( args );
	return val;
}