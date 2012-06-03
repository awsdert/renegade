#include "SetHack_DLG.h"
CODE SetHack_DLG::dGetCode( void )
{
	CODE  code;
	u64   value;
	u8*   vTEST    = gGetQVTest();
	code.type      = dCodeType_D->GetSelection();
	code.ptrDepth  = dCodePtr_SN->GetValue();
	code.size      = gGetUSize( dCodeSize_D->GetSelection() );
	code.ram       = dCodeRam_D->GetSelection();
	code.byte      = GetHex( dCodeByte_TXT->GetValue() );
	code.loop      = dCodeLoop_SN->GetValue();
	code.increment = GetHex( dCodeInc_TXT->GetValue() );
	code.slide     = GetHex( dCodeSum_TXT->GetValue() );
	xStr  text     = dCodeValue_TXT->GetValue();
	xAStr tmp      = wxSplit( text, wxT( ',' ) );
	code[ 0 ]      = GetHex( tmp[ 0 ], code.size );
	if ( code.type == CT_LIST )
	{
		s32 iCount = tmp.GetCount();
		for ( s32 i = 1; i < iCount; ++i )
			code.NewItem( GetHex( tmp[ i ], code.size ) );
		code.test = code.GetCount();
	}
	else if ( code.type == CT_TEST )
	{
		value = vTEST[ dCodeTest_D->GetSelection() ];
		code.test = value;
		switch ( dCodeTestThen_D->GetSelection() )
		{
			case 0: code.loop = 1u; break;
			case 1: code.loop = 2u; break;
			case 3: code.loop = 0u; break;
		}
	}
	return code;
}
void SetHack_DLG::dDelCode( s16 index )
{
	dHack.DelCode( index );
	dShowHack();
}
void SetHack_DLG::dGetHack(  void )
{
	HACK* hack  = gGetHack();
	s16   count = hack->GetCount();
	dHack.SetCount( count );
	for ( s16 i = 0; i < count; ++i ) dHack[ i ] = ( *hack )[ i ];
	dModified   = false;
	dShowHack();
}
void SetHack_DLG::dSetHack(  void )
{
	HACK* hack  = gGetHack();
	s16   count = dHack.GetCount();
	hack->SetCount( count );
	for ( s16 i = 0; i < count; ++i ) ( *hack )[ i ] = dHack[ i ];
	dModified   = false;
}
void SetHack_DLG::dShowHack( void )
{
	dCode_LC->DeleteAllItems();
	wxListItem cid;
	s8  iCount = dHack.GetCount();
	s16 j, jCount, k = 0;
	xAStr array;
	xStr text;
	for ( s8 i = 0; i < iCount; ++i )
	{
		array = BuildCode( dHack[ i ] );
		jCount = array.GetCount();
		for ( j = 0; j < jCount; ++j, ++k )
		{
			text = array[ j ];
			cid.SetId( k );
			cid.SetColumn( 0 );
			cid.SetText( text.Left( 8 ) );
			dCode_LC->InsertItem( cid );
			cid.SetColumn( 1 );
			cid.SetText( text.Right( 8 ) );
			dCode_LC->SetItem( cid );
			dCode_LC->SetItemData( k, i );
		}
	}
	dIndex = -1;
	dShowCode();
}
void SetHack_DLG::dShowCode( void )
{
	if ( dIndex < 0 )
	{
		CODE code;
		dShowCode( code );
		return;
	}
	dShowCode( dHack[ dIndex ] );
}
void SetHack_DLG::dShowCode( CODE code )
{
	dCodeType_D->Select( code.type );
	dCodeSize_D->Select( gGetSSize( code.size ) );
	dCodeRam_D->Select( code.ram );
	dCodeLoop_SN->SetValue( code.loop );
	if ( code.type == CT_TEST )
	{
		s8 then;
		switch ( code.loop )
		{
			case 0u: then = 3; break;
			case 1u: then = 0; break;
			case 2u: then = 1; break;
			default: then = 2;
		}
		dCodeTestThen_D->Select( then );
	}
	else
	{
		dCodeTestThen_D->Select( 0 );
	}
	xStr text, tmp;
	text.Printf( hexVLL, code.byte );
	dCodeByte_TXT->ChangeValue( text );
	text.Printf( hexV, code.increment );
	dCodePtr_SN->SetValue( code.ptrDepth );
	dCodeInc_TXT->ChangeValue( text );
	text.Printf( hexVLL, code[ 0 ] );
	u8   count = code.GetCount();
	for ( u8 i = 1u; i < count; ++i )
	{
		tmp.Printf( wxT( ", %01llX" ), code[ i ] );
		text += tmp;
	}
	dCodeValue_TXT->ChangeValue( text );
	text.Printf( hexVLL, code.slide );
	dCodeSum_TXT->ChangeValue( text );
}
