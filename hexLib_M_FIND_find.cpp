#include "wx_pch.h"
#include "hexLib_main.h"
void M_FIND::find( void )
{
	Bin
		*bin = &( m_lib->m__bin.m_now );
	ui08
		r = bin->ramNo,
		q = 0u,
		t = 0u,
		v = 0u,
		vMax = 0u;
	ui64
		address = 0u,
		addrMax = bin->at( r ).bytes,
		addrTmp;
	ui32
		a = 0u,
		aTmp,
		aMax = ( addrMax > 0x10000 ) ? 0x10000 : addrMax,
		stop = aMax - vMax;
	ui08
		*addr = ( ui08* )malloc( aMax ),
		*nowD = ( ui08* )malloc( aMax ),
		*oldD = null;
	bool
		test = false,
		testA = false,
		testV = false;
	for ( t = 0u; ( !testA && t < hexA_COUNT ); ++t )
		testA = m_ab[ HEX_QA ][ t ];
	for ( t = 0u; ( !testV && t < hexT_COUNT ); ++t )
		testV = m_vb[ HEX_QA ][ t ];
	BinF file,
		vNowF,
		vOldF,
		aNowF,
		aOldF;
	Text
		txt,
		path = m_lib->getTmpWd() + wxT("search") + xsDirSep,
		tData = wxT("data"),
		tAddr = wxT("addr");
	txt.Printf( wxT("%04X.bin"), m_cmp );
	// Ready file/app being searched
	if ( bin->type == 0u )
	{
		if ( !file.Open( bin->path + bin->bind ) )
			return;
	}
	// Ready new dump files
	vNowF.Create( path + tData + txt, true );
	vNowF.Open( path + tData + txt, vNowF.write );
	aNowF.Create( path + tAddr + txt, true );
	aNowF.Open( path + tAddr + txt, vNowF.write );
	// Ready old dump files
	if ( m_cmp >= 0 )
	{
		oldD = ( ui08* )malloc( aMax );
		txt.Printf( wxT("%04X.bin"), m_cmp - 1 );
		vOldF.Open( path + tData + txt );
		aOldF.Open( path + tAddr + txt );
	}
	zxInt nowV, oldV, cmpV;
	find_pb->SetValue( 0 );
	find_pb->SetRange( 100 );
	while ( address < addrMax )
	{
		addrTmp = ( addrMax - address );
		if ( addrTmp <= aMax )
		{
			aMax = addrTmp;
			stop = aMax;
		}
		if ( bin->type == 0u )
		{
			file.Seek( vMax, wxFromCurrent );
			file.Read( nowD, aMax );
		}
		if ( m_cmp > 0 )
		{
			aOldF.Read( addr, aMax );
			vOldF.Read( oldD, aMax );
		}
		for ( a = 0u; a < stop; ++a, ++address )
		{
			aTmp = aMax - a;
			test = ( addr[ a ] > 0u );
			for ( q = HEX_QM; ( test && q < HEX_QA ); ++q )
			{
				for ( t = hexA_MT; ( test && t < hexA_COUNT ); ++t )
				{
					if ( m_ab[ q ][ t ] )
					{
						switch ( t )
						{
							case hexA_MT: test = ( test && address >  m_a[ q ][ t ] ); break;
							case hexA_ME: test = ( test && address >= m_a[ q ][ t ] ); break;
							case hexA_LT: test = ( test && address <  m_a[ q ][ t ] ); break;
							case hexA_LE: test = ( test && address <= m_a[ q ][ t ] ); break;
						}
						if ( q == HEX_QN )
							test = !test;
					}
				}
			}
			if ( test )
			{
				if ( ( aMax - a ) < vMax )
					vMax = ( aMax - a );
				nowV.setPtr( &nowD[ v ], vMax );
				oldV.setPtr( &oldD[ v ], vMax );
				for ( q = HEX_QM; ( test && q < HEX_QA ); ++q )
				{
					for ( t = 0u; ( test && t < hexT_COUNT ); ++t )
					{
						if ( m_v[ q ][ t ] )
						{
							cmpV.setPtr( m_v[ q ][ t ], 16u );
							switch ( t )
							{
								case hexT_DE: test = nowV == cmpV; break;
								case hexT_NE: test = nowV != cmpV; break;
								case hexT_MT: test = nowV >  cmpV; break;
								case hexT_ME: test = nowV >= cmpV; break;
								case hexT_LT: test = nowV <  cmpV; break;
								case hexT_LE: test = nowV <= cmpV; break;
							}
							if ( q == HEX_QN )
								test = !test;
						}
					}
				}
			}
			if ( test &&  ( testA || testV ) )
			{
				q =	HEX_QA;
				test = false;
				if ( testA )
				{
					test = ( m_ab[ q ][ hexA_MT ] && address > m_a[ q ][ hexA_MT ] );
					test = ( test || ( m_ab[ q ][ hexA_ME ] && address >= m_a[ q ][ hexA_ME ] ) );
					test = ( test || ( m_ab[ q ][ hexA_LT ] && address <  m_a[ q ][ hexA_LT ] ) );
					test = ( test || ( m_ab[ q ][ hexA_LE ] && address <= m_a[ q ][ hexA_LE ] ) );
				}
				if ( !test && testV )
				{
					q = HEX_QA;
					test = false;
					for ( t = hexT_COUNT; ( !test && t < hexT_COUNT ); ++t )
					{
						if ( m_vb[ q ][ t ] )
						{
							cmpV.setPtr( m_v[ q ][ t ], 16u );
							switch ( t )
							{
								case hexT_DE: test = nowV == cmpV; break;
								case hexT_NE: test = nowV != cmpV; break;
								case hexT_MT: test = nowV >  cmpV; break;
								case hexT_ME: test = nowV >= cmpV; break;
								case hexT_LT: test = nowV <  cmpV; break;
								case hexT_LE: test = nowV <= cmpV; break;
							}
						}
					}
				}
			}
			addr[ a ] = test ? 1u : 0u;
		}
		aNowF.Write( addr, stop );
		vNowF.Write( nowD, stop );
		find_pb->SetValue( ( addrMax / address ) * 100 );
	}
	aNowF.Close();
	vNowF.Close();
	free( addr );
	free( nowD );
	if ( m_cmp >= 0 )
	{
		aOldF.Close();
		vOldF.Close();
		free( oldD );
	}
}