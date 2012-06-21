#include "G.h"
void G::SetSearch( s16 no )
{
	xStr text;
	s16  i = 1;
	findUse_D->Clear();
	findUse_D->Append( wxT("Dump") );
	for ( ; i <= no; ++i )
	{
		text.Printf( wxT( "Search %i" ), i );
		findUse_D->Append( text );
	}
	findUse_D->Select( no );
}
u64  G::GetValue( wxTextCtrl* obj, u8 mode )
	{ return gGetValue( obj->GetValue(), mode ); }
u32  G::GetQAG( void )
{
	u32 test  = 0u;
	u8* vTEST = gGetQATest();
	for ( s32 i = 0; i < QA_COUNT; ++i )
	{
		if ( mQAG_CB[ i ]->GetValue() )
		{
			test          += vTEST[ i ];
			mQAGArray[ i ] = GetValue( mQAG_TXT[ i ], VAL_HEX );
		}
		else mQAGArray[ i ] = 0u;
	}
	return test;
}
u32  G::GetQAB( void )
{
	u32 test  = 0u;
	u8* vTEST = gGetQATest();
	for ( s32 i = 0; i < QA_COUNT; ++i )
	{
		if ( mQAB_CB[ i ]->GetValue() )
		{
			test          += vTEST[ i ];
			mQABArray[ i ] = GetValue( mQAB_TXT[ i ], VAL_HEX );
		}
		else mQABArray[ i ] = 0u;
	}
	return test;
}
u32  G::GetQVG( void )
{
	u32 test  = 0u;
	u8  mode  = findMode_D->GetSelection();
	u8* vTEST = gGetQVTest();
	for ( s32 i = 0; i < QV_COUNT; ++i )
	{
		if ( mQVG_CB[ i ]->GetValue() )
		{
			test          += vTEST[ i ];
			mQVGArray[ i ] = GetValue( mQVG_TXT[ i ], mode );
		}
		else mQVGArray[ i ] = 0u;
	}
	return test;
}
u32  G::GetQVB( void )
{
	u32 test = 0u;
	u8  mode = findMode_D->GetSelection();
	u8* vTEST = gGetQVTest();
	for ( s32 i = 0; i < QV_COUNT; ++i )
	{
		if ( mQVB_CB[ i ]->GetValue() )
		{
			test += vTEST[ i ];
			mQVBArray[ i ] = GetValue( mQVB_TXT[ i ], mode );
		}
		else mQVBArray[ i ] = 0u;
	}
	return test;
}
void G::Search( s16 no, s8 type )
{
	NewHook();
	if ( isHooked < 1 ) return;
	xStr  slash = gGetSlash();
	xStr  text, path = wxGetCwd() + slash + wxT( "ram" ) + slash, toDump, toByte;
	toDump.Printf( wxT( "dump%02i.bin" ), no );
	toByte.Printf( wxT( "byte%02i.bin" ), no );
	u8    size       = gGetUSize( findSize_D->GetSelection() );
	s8 ramNo         = findRam_D->GetSelection();
	if ( ramNo < 0 ) ramNo = 0;
	u64   address    = 0u;
	u64   nextByte   = 0u;
	u64   nextOut    = 0u;
	u64   atByte     = mGetRamByte( ramNo );
	u64   upToByte   = 0u;
	if ( hookApp )
	{
		if ( !GetAppSize( appHandle, upToByte ) )
		{
			return;
		}
	}
	else
	{
		upToByte = bin_BF.Length();
	}
	u64   endByte    = mGetRamSize( ramNo );
	if ( endByte > upToByte ) endByte = upToByte;
	u32   i, iNext   = 0u, j, k = 0u;
	u32   jCount     = ( endByte < readSize ) ? endByte : readSize;
	u64   addOut     = endByte / 10u;
	u8*   ram8       = new u8[ jCount ];
	u16*  ram16      = reinterpret_cast< u16* >( ram8 );
	u32*  ram32      = reinterpret_cast< u32* >( ram8 );
	u64*  ram64      = reinterpret_cast< u64* >( ram8 );
	u8*   old8       = new u8[ jCount ];
	u16*  old16      = reinterpret_cast< u16* >( old8 );
	u32*  old32      = reinterpret_cast< u32* >( old8 );
	u64*  old64      = reinterpret_cast< u64* >( old8 );
	bool  nowByte    = false;
	bool* theByte    = new bool[ jCount ];
	for ( j = 0u; j < jCount; ++j )
	{
		theByte[ j ] = false;
	}
	wxFile nowDump_BF, nowByte_BF, oldDump_BF, oldByte_BF;
	text = path + toDump;
	if ( wxFileExists( text ) ) { wxRemoveFile( text ); }
	nowDump_BF.Create( text );
	nowDump_BF.Open(   text, nowDump_BF.read_write );
	text = path + toByte;
	if ( wxFileExists( text ) ) { wxRemoveFile( text ); }
	nowByte_BF.Create( text );
	nowByte_BF.Open(   text, nowByte_BF.read_write );
	if ( no > 0 )
	{
		toDump.Printf( wxT( "dump%02i.bin" ), no - 1 );
		toByte.Printf( wxT( "byte%02i.bin" ), no - 1 );
		oldDump_BF.Open( path + toDump );
		oldByte_BF.Open( path + toByte );
	}
	// Get Test Modes
	u64 ramValue = 0u;
	u64 oldValue = 0u;
	u32 QAGTest  = GetQAG();
	u32 QABTest  = GetQAB();
	u32 QVGTest  = GetQVG();
	u32 QVBTest  = GetQVB();
	u64 outNo    = 0u;
	// Begin Search
	xStr outText = wxT("Results: %llu");
	out_S->SetLabel( wxT( "Results: 0" ) );
	byte_PB->SetRange( 10 );
	byte_PB->SetValue( 0 );
	s32 progress = 0;
	for
	(
		address = 0u, i = jCount;
		address < endByte;
		++address, ++i
	)
	{
		if ( i == jCount )
		{
			nextByte += jCount;
			if ( address > 0u )
			{
				nowDump_BF.Write( ram8,    jCount );
				nowByte_BF.Write( theByte, jCount );
			}
			if ( nextByte > endByte )
			{
				nextByte -= jCount;
				jCount    = endByte - nextByte;
				nextByte  = endByte;
			}
			if ( hookApp )
			{
				GetRamX( appHandle, atByte, ram8, jCount );
				atByte   += jCount;
			}
			else
			{
				bin_BF.Read( ram8, jCount );
			}
			if ( no > 0 )
			{
				oldDump_BF.Read( old8,    jCount );
				oldByte_BF.Read( theByte, jCount );
			}
			else
			{
				for ( j = 0u; j < jCount; ++j )
				{
					theByte[ j ] = true;
				}
			}
			i = 0u;
			iNext = 0u;
			k = 0u;
		}
		if ( address == nextOut )
		{
			nextOut += addOut;
			text.Printf( outText, outNo );
			++progress;
			byte_PB->SetValue( progress );
			out_S->SetLabel( text );
		}
		if ( i == iNext )
		{
			if ( theByte[ i ] )
			{
				switch ( size )
				{
					case 8u:
						ramValue = ram64[ k ];
						oldValue = old64[ k ];
						break;
					case 4u:
						ramValue = ram32[ k ];
						oldValue = old32[ k ];
						break;
					case 2u:
						ramValue = ram16[ k ];
						oldValue = old16[ k ];
						break;
					default:
						ramValue = ram8[ k ];
						oldValue = old8[ k ];
				}
				if ( no > 0 )
				{
					switch ( type )
					{
						case QD_EQUAL: nowByte = ( ramValue == oldValue ); break;
						case QD_NOT:   nowByte = ( ramValue != oldValue ); break;
						case QD_MT:    nowByte = ( ramValue >  oldValue ); break;
						case QD_MTE:   nowByte = ( ramValue >= oldValue ); break;
						case QD_LT:    nowByte = ( ramValue <  oldValue ); break;
						case QD_LTE:   nowByte = ( ramValue <= oldValue ); break;
						default:       nowByte = true;
					}
				}
				else { nowByte = true; }
				if ( QAGTest > 0u )
				{
					nowByte = ( nowByte && ( QAGTest & gTMoreT ) > 0u ) ? ( address >  mQAGArray[ QA_MT  ] ) : nowByte;
					nowByte = ( nowByte && ( QAGTest & gTMoreE ) > 0u ) ? ( address >= mQAGArray[ QA_MTE ] ) : nowByte;
					nowByte = ( nowByte && ( QAGTest & gTLessT ) > 0u ) ? ( address <  mQAGArray[ QA_LT  ] ) : nowByte;
					nowByte = ( nowByte && ( QAGTest & gTLessE ) > 0u ) ? ( address <= mQAGArray[ QA_LTE ] ) : nowByte;
				}
				if ( QABTest > 0u )
				{
					nowByte = ( nowByte && ( QABTest & gTMoreT ) > 0u ) ? ( address >  mQAGArray[ QA_MT  ] ) : nowByte;
					nowByte = ( nowByte && ( QABTest & gTMoreE ) > 0u ) ? ( address >= mQAGArray[ QA_MTE ] ) : nowByte;
					nowByte = ( nowByte && ( QABTest & gTLessT ) > 0u ) ? ( address <  mQAGArray[ QA_LT  ] ) : nowByte;
					nowByte = ( nowByte && ( QABTest & gTLessE ) > 0u ) ? ( address <= mQAGArray[ QA_LTE ] ) : nowByte;
				}
				if ( QVGTest > 0u )
				{
					nowByte = ( nowByte && ( QVGTest & gTEqual ) > 0u ) ? ( ramValue == mQVGArray[ QV_EQUAL ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTNotE  ) > 0u ) ? ( ramValue != mQVGArray[ QV_NOT   ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTMoreT ) > 0u ) ? ( ramValue >  mQVGArray[ QV_MT    ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTMoreE ) > 0u ) ? ( ramValue >= mQVGArray[ QV_MTE   ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTLessT ) > 0u ) ? ( ramValue <  mQVGArray[ QV_LT    ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTLessE ) > 0u ) ? ( ramValue <= mQVGArray[ QV_LTE   ] ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTGot   ) > 0u ) ? ( ( ramValue & mQVGArray[ QV_GOT     ] ) >  0u ) : nowByte;
					nowByte = ( nowByte && ( QVGTest & gTNotG  ) > 0u ) ? ( ( ramValue & mQVGArray[ QV_NOT_GOT ] ) == 0u ) : nowByte;
				}
				if ( QVBTest > 0u )
				{
					nowByte = ( nowByte && ( QVBTest & gTEqual ) > 0u ) ? ( ramValue == mQVBArray[ QV_EQUAL ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTNotE  ) > 0u ) ? ( ramValue != mQVBArray[ QV_NOT   ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTMoreT ) > 0u ) ? ( ramValue >  mQVBArray[ QV_MT    ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTMoreE ) > 0u ) ? ( ramValue >= mQVBArray[ QV_MTE   ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTLessT ) > 0u ) ? ( ramValue <  mQVBArray[ QV_LT    ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTLessE ) > 0u ) ? ( ramValue <= mQVBArray[ QV_LTE   ] ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTGot   ) > 0u ) ? ( ( ramValue & mQVBArray[ QV_GOT     ] ) >  0u ) : nowByte;
					nowByte = ( nowByte && ( QVBTest & gTNotG  ) > 0u ) ? ( ( ramValue & mQVBArray[ QV_NOT_GOT ] ) == 0u ) : nowByte;
				}
				if ( nowByte ) { ++outNo; }
				switch ( size )
				{
					case 8u:
						theByte[ i + 7u ] = false;
						theByte[ i + 6u ] = false;
						theByte[ i + 5u ] = false;
						theByte[ i + 4u ] = false;
					case 4u:
						theByte[ i + 3u ] = false;
						theByte[ i + 2u ] = false;
					case 2u:
						theByte[ i + 1u ] = false;
					default:
						theByte[ i ] = nowByte;
				}
			}
			iNext += size;
			++k;
		}
	}
	if ( i == jCount )
	{
		nowDump_BF.Write( ram8,    jCount );
		nowByte_BF.Write( theByte, jCount );
	}
	nowDump_BF.Close();
	nowByte_BF.Close();
	delete [] ram8;
	delete [] old8;
	delete [] theByte;
	if ( no > 0 )
	{
		oldDump_BF.Close();
		oldByte_BF.Close();
	}
	text.Printf( outText, outNo );
	out_S->SetLabel( text );
	byte_PB->SetValue( 10 );
	DelHook();
	SetSearch( no + 1 );
	ShowOut( no, size );
}
