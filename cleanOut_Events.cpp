#include "G.h"
s32 outDataId = -1;
void G::SetOut_BOnClick( wxCommandEvent& event )
{
	xStr text;
	s32  i      = outDataId;
	s32  iCount = outData_LC->GetItemCount();
	u64  value  = GetHex( outByte_TXT->GetValue() );
	u8   size   = gGetUSize( outSize_D->GetSelection() );
	wxListItem item;
	OUTDATA    data;
	item.SetColumn( 0 );
	item.SetMask( wxLIST_MASK_TEXT );
	bool makeItem = false;
	if ( i < 0 ) makeItem = true;
	else
	{
		item.SetId( i );
		if ( value != mOutArray[ i ].address )
			makeItem = true;
	}
	if ( makeItem )
	{
		i         = iCount;
		outDataId = iCount;
		text.Printf( hex64, value );
		item.SetId( i );
		item.SetText( text );
		outData_LC->InsertItem( item );
		mOutArray.push_back( data );
		mOutArray[ i ].address = value;
	}
	value = GetHex( outValue_TXT->GetValue(), size );
	switch ( size )
	{
		case 1u: text.Printf( hex8LL,  value ); break;
		case 2u: text.Printf( hex16LL, value ); break;
		case 4u: text.Printf( hex32LL, value ); break;
		case 8u: text.Printf( hex64,   value ); break;
		default: text.Printf( hexVLL,  value );
	}
	item.SetColumn( 1 );
	item.SetText( text );
	outData_LC->SetItem( item );
	mOutArray[ i ].value = value;
	text.Printf( hex8, size );
	item.SetColumn( 2 );
	item.SetText( text );
	outData_LC->SetItem( item );
	mOutArray[ i ].size  = size;
}
void G::DelOut_BOnClick( wxCommandEvent& event )
{
	if ( outDataId < 0 ) return;
	outData_LC->DeleteItem( outDataId );
	mOutArray.erase( mOutArray.begin() + outDataId );
	outDataId = -1;
}
void G::outData_LCOnSelect( wxListEvent& event )
{
	wxListItem item = event.GetItem();
	s32 i = item.GetId();
	outDataId = i;
	xStr text;
	text.Printf( hexVLL, mOutArray[ i ].address );
	outByte_TXT->ChangeValue( text );
	outSize_D->Select( gGetSSize( mOutArray[ i ].size ) );
	text.Printf( hexVLL, mOutArray[ i ].value );
	outValue_TXT->ChangeValue( text );
}
void G::out_LCOnSelect( wxListEvent& event )
{
	wxListItem item = event.GetItem();
	xStr text;
	item.SetColumn( 0 );
	out_LC->GetItem( item );
	u64  value = GetHex( item.GetText() );
	text.Printf( hexVLL, value );
	outByte_TXT->ChangeValue( text );
	if ( outEdit_CB->GetValue() )
	{
		editGet_TXT->ChangeValue( text );
	}
	item.SetColumn( 1 );
	out_LC->GetItem( item );
	value = GetHex( item.GetText() );
	outValue_TXT->ChangeValue( text );
}
