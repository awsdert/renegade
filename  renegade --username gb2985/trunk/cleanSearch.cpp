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
	findUse_D->Select( i - 1 );
}
u64  G::GetValue( wxTextCtrl* obj, u8 mode )
{
	u64 value = 0u;
	xStr text = obj->GetValue();
	switch ( mode )
	{
		case VAL_HEX: value = GetHex( text ); break;
		case VAL_UINT: value = GetHexFromU64( text ); break;
		case VAL_SINT: value = GetHexFromS64( text ); break;
		case VAL_SFLT: value = GetHexFromF64( text ); break;
	}
	return value;
}
u32  G::GetGood( void )
{
	u32 test  = 0u;
	u8  mode  = findMode_D->GetSelection();
	u8* vTEST = gGetQTests();
	for ( s32 i = 0; i < QV_COUNT; ++i )
	{
		if ( mQVG_CB[ i ]->GetValue() )
		{
			test += vTEST[ i ];
			mQVGArray[ i ] = GetValue( mQVG_TXT[ i ], mode );
		}
		else mQVGArray[ i ] = 0u;
	}
	return test;
}
u32  G::GetGoodByte( void )
{
	u32 test = 0u;
	u8  mode = findMode_D->GetSelection();
	gAGT     = 0u;
	gAGTE    = 0u;
	gALT     = 0u;
	gALTE    = 0u;
	u8* vTEST = gGetQTests();
	if ( goodAGT_CB->GetValue() )
	{
		test  += vTEST[ QV_MORE_THAN ];
		gAGT   = GetValue( goodAGT_TXT, mode );
	}
	if ( goodAGTE_CB->GetValue() )
	{
		test  += vTEST[ QV_MORE_OR_EQUAL ];
		gAGTE  = GetValue( goodAGTE_TXT, mode );
	}
	if ( goodALT_CB->GetValue() )
	{
		test  += vTEST[ QV_LESS_THAN ];
		gALT   = GetValue( goodALT_TXT, mode );
	}
	if ( goodALTE_CB->GetValue() )
	{
		test  += vTEST[ QV_LESS_OR_EQUAL ];
		gALTE  = GetValue( goodALTE_TXT, mode );
	}
	return test;
}
u32  G::GetBad( void )
{
	u32 test = 0u;
	u8  mode = findMode_D->GetSelection();
	u8* vTEST = gGetQTests();
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
u32  G::GetBadByte( void )
{
	u32 test = 0u;
	u8  mode = findMode_D->GetSelection();
	bAGT     = 0u;
	bAGTE    = 0u;
	bALT     = 0u;
	bALTE    = 0u;
	u8* vTEST = gGetQTests();
	if ( badAGT_CB->GetValue() )
	{
		test  += vTEST[ QV_MORE_THAN ];
		bAGT   = GetValue( badAGT_TXT, mode );
	}
	if ( badAGTE_CB->GetValue() )
	{
		test  += vTEST[ QV_MORE_OR_EQUAL ];
		bAGTE  = GetValue( badAGTE_TXT, mode );
	}
	if ( badALT_CB->GetValue() )
	{
		test  += vTEST[ QV_LESS_THAN ];
		bALT   = GetValue( badALT_TXT, mode );
	}
	if ( badALTE_CB->GetValue() )
	{
		test  += vTEST[ QV_LESS_OR_EQUAL ];
		bALTE  = GetValue( badALTE_TXT, mode );
	}
	return test;
}
void G::Search( s16 no, s8 type )
{
	NewHook();
	u8* vTEST   = gGetQTests();
	xStr  slash = gGetSlash();
	xStr  text, path = wxGetCwd() + slash + wxT( "ram" ) + slash, toDump, toByte;
	toDump.Printf( wxT( "dump%02i.bin" ), no );
	toByte.Printf( wxT( "byte%02i.bin" ), no );
	s8    theSize    = findSize_D->GetSelection();
	u8    size       = 1u;
	switch ( theSize )
	{
		case 1: size = 2u; break;
		case 2: size = 4u; break;
		case 3: size = 8u;
	}
	s8 ramNo         = findRam_D->GetSelection();
	if ( ramNo < 0 ) ramNo = 0;
	u64   address    = 0u;
	u32   i          = 0u, j = 0u, k = 0u;
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
		bin_BF.Length();
	}
	u64   endByte    = mGetRamSize( ramNo );
	if ( endByte > upToByte ) endByte = upToByte;
	u32   addByte    = ( endByte < readSize ) ? endByte : readSize;
	u64   addOut     = endByte / 10u;
	u8*   ram8       = new u8[ addByte ];
	u16*  ram16      = reinterpret_cast< u16* >( ram8 );
	u32*  ram32      = reinterpret_cast< u32* >( ram8 );
	u64*  ram64      = reinterpret_cast< u64* >( ram8 );
	u8*   old8       = new u8[ addByte ];
	u16*  old16      = reinterpret_cast< u16* >( old8 );
	u32*  old32      = reinterpret_cast< u32* >( old8 );
	u64*  old64      = reinterpret_cast< u64* >( old8 );
	bool  nowByte    = false;
	bool* theByte    = new bool[ addByte ];
	wxFile nowDump_BF, nowByte_BF, oldDump_BF, oldByte_BF;
	nowDump_BF.Create( path + toDump, true );
	nowDump_BF.Open(   path + toDump, bin_BF.write );
	nowByte_BF.Create( path + toByte, true );
	nowByte_BF.Open(   path + toByte, bin_BF.write );
	if ( no > 0 )
	{
		toDump.Printf( wxT( "dump%02i.bin" ), no - 1 );
		toByte.Printf( wxT( "byte%02i.bin" ), no - 1 );
		oldDump_BF.Open( path + toDump, bin_BF.read );
		oldByte_BF.Open( path + toByte, bin_BF.read );
	}
	// Get Test Modes
	u64 ramValue = 0u;
	u64 oldValue = 0u;
	u64 ramByte  = 0u;
	u32 gTest    = GetGood();
	u32 gATest   = GetGoodByte();
	u32 bTest    = GetBad();
	u32 bATest   = GetBadByte();
	u64 outNo    = 0u;
	// Begin Search
	xStr outText = wxT("Results: %llu");
	out_S->SetLabel( wxT( "Results: 0" ) );
	byte_PB->SetRange( 10 );
	byte_PB->SetValue( 0 );
	s32 progress = 0;
	for ( address = 0u, i = 0u; address < endByte; ++address, ++i )
	{
		if ( address == nextByte )
		{
			nextByte += addByte;
			nowDump_BF.Write( ram8, addByte );
			nowByte_BF.Write( theByte, addByte );
			if ( nextByte > endByte )
			{
				nextByte -= addByte;
				addByte   = endByte - nextByte;
				nextByte  = endByte;
			}
			if ( hookApp )
			{
				GetRamX( appHandle, atByte, ram8, addByte );
				atByte   += addByte;
			}
			else
			{
				bin_BF.Read( ram8, addByte );
			}
			if ( no > 0 )
			{
				oldDump_BF.Read( old8, addByte );
				oldByte_BF.Read( theByte, addByte );
			}
			else
			{
				for ( j = 0u; j < addByte; ++j )
				{
					theByte[ j ] = true;
				}
			}
			i = 0u;
			k = 0u;
		}
		if ( address == nextOut )
		{
			nextOut += addOut;
			text.Printf( outText, outNo );
			progress++;
			byte_PB->SetValue( progress );
			out_S->SetLabel( text );
		}
		if ( address == ramByte )
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
				nowByte = true;
				if ( gTest > 0u )
				{
					if ( ( gTest & TEST_BIN ) > 0u )
					{
						nowByte = ( ( ramValue & mQVGArray[ QV_EQUAL ] ) > 0u );
					}
					else
					{
						nowByte = (            ( gTest & vTEST[ QV_EQUAL         ] ) > 0u ) ? ( ramValue == mQVGArray[ QV_EQUAL         ] ) : true;
						nowByte = ( nowByte && ( gTest & vTEST[ QV_NOT_EQUAL     ] ) > 0u ) ? ( ramValue != mQVGArray[ QV_NOT_EQUAL     ] ) : nowByte;
						nowByte = ( nowByte && ( gTest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( ramValue >  mQVGArray[ QV_MORE_THAN     ] ) : nowByte;
						nowByte = ( nowByte && ( gTest & vTEST[ QV_MORE_OR_EQUAL ] ) > 0u ) ? ( ramValue >= mQVGArray[ QV_MORE_OR_EQUAL ] ) : nowByte;
						nowByte = ( nowByte && ( gTest & vTEST[ QV_LESS_THAN     ] ) > 0u ) ? ( ramValue <  mQVGArray[ QV_LESS_THAN     ] ) : nowByte;
						nowByte = ( nowByte && ( gTest & vTEST[ QV_LESS_OR_EQUAL ] ) > 0u ) ? ( ramValue <= mQVGArray[ QV_LESS_OR_EQUAL ] ) : nowByte;
					}
				}
				if ( gATest > 0u )
				{
					nowByte = ( nowByte && ( gATest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( address >  gAGT   ) : nowByte;
					nowByte = ( nowByte && ( gATest & vTEST[ QV_MORE_OR_EQUAL ] ) > 0u ) ? ( address >= gAGTE  ) : nowByte;
					nowByte = ( nowByte && ( gATest & vTEST[ QV_LESS_THAN     ] ) > 0u ) ? ( address <  gALT   ) : nowByte;
					nowByte = ( nowByte && ( gATest & vTEST[ QV_LESS_OR_EQUAL ] ) > 0u ) ? ( address <= gALTE  ) : nowByte;
				}
				if ( bTest > 0u )
				{
					if ( ( bTest & TEST_BIN ) > 0u )
					{
						nowByte = ( nowByte && ( ramValue & mQVBArray[ QV_EQUAL ] ) > 0u );
					}
					else
					{
						nowByte = ( nowByte && ( bTest & vTEST[ QV_EQUAL         ] ) > 0u ) ? ( ramValue == mQVBArray[ QV_EQUAL         ] ) : true;
						nowByte = ( nowByte && ( bTest & vTEST[ QV_NOT_EQUAL     ] ) > 0u ) ? ( ramValue != mQVBArray[ QV_NOT_EQUAL     ] ) : nowByte;
						nowByte = ( nowByte && ( bTest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( ramValue >  mQVBArray[ QV_MORE_THAN     ] ) : nowByte;
						nowByte = ( nowByte && ( bTest & vTEST[ QV_MORE_OR_EQUAL ] ) > 0u ) ? ( ramValue >= mQVBArray[ QV_MORE_OR_EQUAL ] ) : nowByte;
						nowByte = ( nowByte && ( bTest & vTEST[ QV_LESS_THAN     ] ) > 0u ) ? ( ramValue <  mQVBArray[ QV_LESS_THAN     ] ) : nowByte;
						nowByte = ( nowByte && ( bTest & vTEST[ QV_LESS_OR_EQUAL ] ) > 0u ) ? ( ramValue <= mQVBArray[ QV_LESS_OR_EQUAL ] ) : nowByte;
					}
				}
				if ( bATest > 0u )
				{
					nowByte = ( nowByte && ( bATest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( address  >  bAGT    ) : nowByte;
					nowByte = ( nowByte && ( bATest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( address  >= bAGTE   ) : nowByte;
					nowByte = ( nowByte && ( bATest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( address  <  bALT    ) : nowByte;
					nowByte = ( nowByte && ( bATest & vTEST[ QV_MORE_THAN     ] ) > 0u ) ? ( address  <= bALTE   ) : nowByte;
				}
				outNo       += nowByte ? 1u : 0u;
				switch ( size )
				{
					case 8u:
						theByte[ i + 7u ] = theByte;
						theByte[ i + 6u ] = theByte;
						theByte[ i + 5u ] = theByte;
						theByte[ i + 4u ] = theByte;
					case 4u:
						theByte[ i + 3u ] = theByte;
						theByte[ i + 2u ] = theByte;
					case 2u:
						theByte[ i + 1u ] = theByte;
					default:
						theByte[ i ] = nowByte;
				}
			}
			ramByte += size;
			k++;
		}
	}
	delete [] old8;
	nowDump_BF.Write( ram8, addByte );
	nowDump_BF.Close();
	delete [] ram8;
	nowByte_BF.Write( theByte, addByte );
	nowByte_BF.Close();
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
