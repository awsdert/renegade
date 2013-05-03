#include "wx_pch.h"
#include "hexG_db.h"
#include "hexDB_hexIO.h"
#include <math.h>
void M_OGRID::find( void )
{
	ui16 q = ( qNo < 0 ) ? 0u : (qNo + 1), qTypes = 0u;
	Ram ram = db->bin[ db->bin.ramNo ];
	ui64 address = 0uLL, addressMax = ram.bytes, results = 0uLL;
	ui32 a = 0, aMax = ( addressMax < 0x20000000 ) ? addressMax : 0x20000000;
	ui08 *dataNow = new ui08[ aMax ], *dataOld = new ui08[ aMax ], v, vSize, vEnd;
	bool *addr = new bool[ aMax ];
	BinF dataFNow, dataFOld, addrFNow, addrFOld;
	Text txt, path = db->cwd + xsDirSep + wxT("search") + xsDirSep;
	txt.Printf( wxT("%03u"), q );
	addrFNow.Open( path + wxT("addr") + txt + wxT(".bin"), dataFNow.write );
	dataFNow.Open( path + wxT("data") + txt + wxT(".bin"), dataFNow.write );
	if ( q > 0u )
	{
		txt.Printf( wxT("search/data%03u"), q - 1u );
		addrFOld.Open( path + wxT("addr") + txt + wxT(".bin") );
		dataFOld.Open( path + wxT("data") + txt + wxT(".bin") );
	}
	txt.Clear();
	db->pb->SetRange( 100 );
	db->pb->SetValue( 0 );
	bool isValid, isAnyValid[ HEX_QCOUNT ], isAnyUsed;
	int tv, tt, iM[ HEX_QCOUNT ], iA[ HEX_QCOUNT ], iN[ HEX_QCOUNT ], iO[ HEX_QCOUNT ];
	while ( address < addressMax )
	{
		if ( q > 0u )
		{
			addrFOld.Read( addr, aMax );
			dataFOld.Read( dataOld, aMax );
		}
		else
		{
			for ( a = 0u; a < aMax; ++a )
			{
				addr[ a ] = true;
				dataOld[ a ] = 0u;
			}
		}
		for ( a = 0u; a < aMax; ++a, ++address )
		{
			isValid = addr[ a ];
			if ( isValid )
			{
				for ( vSize = 0u, vEnd = 15u; vSize < 16u; ++vSize, --vEnd )
				{
					if ( ( a + vEnd ) < aMax )
						break;
				}
				for ( tt = 0; tt < HEX_QCOUNT; ++tt )
				{
					iM[ tt ] = -1;
					iA[ tt ] = -1;
					iN[ tt ] = -1;
					iO[ tt ] = -1;
				}
				for ( tv = 0; tv < vEnd; ++tv )
				{
					v = dataNow[ a + tv ];
					for ( tt = 0; tt < HEX_QCOUNT; ++tt )
					{
						if ( iM[ tt ] < 0 && vmb[ tt ] && ( v != vm[ tt ][ tv ] ) )
							iM[ tt ] = tv;
						if ( iA[ tt ] < 0 && vab[ tt ] && ( v != va[ tt ][ tv ] ) )
							iA[ tt ] = tv;
						if ( iN[ tt ] < 0 && vnb[ tt ] && ( v != vn[ tt ][ tv ] ) )
							iN[ tt ] = tv;
						if ( q > 0u && iO[ tt ] < 0 && qType == tt && ( v != dataOld[ a + tv ] ) )
							iO[ tt ] = tv;
					}
				}
				// Contains
				tt = HEX_QDC;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & vm[ tt ][ tv ] ) == vm[ tt ][ tv ] );
				}
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & vn[ tt ][ tv ] ) != vn[ tt ][ tv ] );
				}
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & va[ tt ][ tv ] ) == va[ tt ][ tv ] );
					isAnyValid[ tt ] = isValid;
					isValid = true;
				}
				else
					isAnyValid[ tt ] = true;
				tv = iO[ tt ];
				if ( q > 0u && qType == tt && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & dataOld[ tv ] ) == dataOld[ tv ] );
				}
				// Doesn't Contain
				tt = HEX_QNC;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & vm[ tt ][ tv ] ) != vm[ tt ][ tv ] );
				}
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & vn[ tt ][ tv ] ) == vn[ tt ][ tv ] );
				}
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & va[ tt ][ tv ] ) != va[ tt ][ tv ] );
					isAnyValid[ tt ] = isValid;
					isValid = true;
				}
				else
					isAnyValid[ tt ] = true;
				tv = iO[ tt ];
				if ( q > 0u && qType == tt && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( ( dataNow[ a + tv ] & dataOld[ tv ] ) != dataOld[ tv ] );
				}
				// Equals
				tt = HEX_QEQ;
				if ( vmb[ tt ] )
					isValid = ( isValid && iM[ tt ] < 0 );
				if ( vnb[ tt ] && tv >= 0 )
					isValid = ( isValid && iN[ tt ] >= 0 );
				if ( vab[ tt ] && tv >= 0 )
					isAnyValid[ tt ] = ( isValid && iA[ tt ] < 0 );
				else
					isAnyValid[ tt ] = true;
				tv = iO[ tt ];
				if ( q > 0u && qType == tt && tv >= 0 )
				{
					for ( ; ( tv <= vEnd && isValid ); ++tv )
						isValid = ( dataNow[ a + tv ] == dataOld[ tv ] );
				}
				// Not Equal
				tt = HEX_QNE;
				if ( vmb[ tt ] )
					isValid = ( isValid && iM[ tt ] >= 0 );
				if ( vnb[ tt ] )
					isValid = ( isValid && iN[ tt ] < 0 );
				if ( vab[ tt ] )
					isAnyValid[ tt ] = ( isValid && iA[ tt ] >= 0 );
				else
					isAnyValid[ tt ] = true;
				if ( q > 0u && qType == tt )
					isValid = ( isValid && iO[ tt ] >= 0 );
				// More Than
				tt = HEX_QMT;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] > vm[ tt ][ tv ] );
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] <= vn[ tt ][ tv ] );
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
					isAnyValid[ tt ] = ( isValid && dataNow[ a + tv ] > va[ tt ][ tv ] );
				else
					isAnyValid[ tt ] = true;
				// More Than or Equal
				tt = HEX_QME;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] >= vm[ tt ][ tv ] );
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] < vn[ tt ][ tv ] );
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
					isAnyValid[ tt ] = ( isValid && dataNow[ a + tv ] >= va[ tt ][ tv ] );
				else
					isAnyValid[ tt ] = true;
				// Less Than
				tt = HEX_QLT;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] < vm[ tt ][ tv ] );
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] >= vn[ tt ][ tv ] );
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
					isAnyValid[ tt ] = ( isValid && dataNow[ a + tv ] < va[ tt ][ tv ] );
				else
					isAnyValid[ tt ] = true;
				// Less Than or Equal
				tt = HEX_QLE;
				tv = iM[ tt ];
				if ( vmb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] <= vm[ tt ][ tv ] );
				tv = iN[ tt ];
				if ( vnb[ tt ] && tv >= 0 )
					isValid = ( isValid && dataNow[ a + tv ] > vn[ tt ][ tv ] );
				tv = iA[ tt ];
				if ( vab[ tt ] && tv >= 0 )
					isAnyValid[ tt ] = ( isValid && dataNow[ a + tv ] <= va[ tt ][ tv ] );
				else
					isAnyValid[ tt ] = true;
				// Check if any of the ANY values were used and if they resulted in true
				if ( isValid )
				{
					isValid = false;
					isAnyUsed = false;
					for ( tt = HEX_QDC; tt < HEX_QCOUNT; ++tt )
					{
						isAnyUsed = ( isAnyUsed || vab[ tt ] );
						if ( vab[ tt ] && isAnyValid[ tt ] )
						{
							isValid = true;
							break;
						}
					}
					if ( !isAnyUsed )
						isValid = true;
				}
			}
			addr[ a ] = isValid;
			if ( isValid )
				++results;
		}
		addrFNow.Write( addr, aMax );
		dataFNow.Write( dataNow, aMax );
		db->pb->SetValue( floor( (double)( address / addressMax ) * 100.0 ) );
	}
	db->pb->SetValue( 100 );
	dataFNow.Close();
	if ( q > 0u )
		dataFOld.Close();
	out( 0u, 0x30 );
}