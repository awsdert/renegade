#include "SetHack_DLG.h"

SetHack_DLG::SetHack_DLG( wxWindow* parent )
:
cleanSetHack_DLG( parent )
{
	xAStr array;
	dIndex = -1;
	// Set Code Types
	array.SetCount( CT_COUNT );
	array[ CT_WRITE     ] = wxT( "Write"     );
	array[ CT_COPY      ] = wxT( "Copy"      );
	array[ CT_INCREMENT ] = wxT( "Increment" );
	array[ CT_DECREMENT ] = wxT( "Decrement" );
	array[ CT_TEST      ] = wxT( "Test"      );
	array[ CT_LIST      ] = wxT( "List"      );
	dCodeType_D->Append( array );
	dCodeType_D->Select( 0 );
	// Set Sizes
	dCodeSize_D->Append( gGetSizes() );
	dCodeSize_D->Select( 0 );
	// Set Ram
	BIN bin   = gGetBin();
	dRamCount = bin.GetCount();
	array.Clear();
	array.SetCount( dRamCount );
	for ( s8 i = 0; i < dRamCount; ++i )
	{
		array[ i ] = bin[ i ].name;
	}
	dCodeRam_D->Append( array );
	dCodeRam_D->Select( 0 );
	// Set Tests
	array = gGetTests();
	dCodeTest_D->Append( array );
	dCodeTest_D->Select( 0 );
	// Set Columns
	wxListItem item;
	item.SetId( 0 );
	item.SetColumn( 0 );
	item.SetText( wxT("Part 1") );
	dCode_LC->InsertColumn( 0, item );
	item.SetId( 1 );
	item.SetColumn( 1 );
	item.SetText( wxT("Part 2") );
	dCode_LC->InsertColumn( 1, item );
	// Get and Display Selected Hack
	dGetHack();
}
void SetHack_DLG::dSetHack_OnClick(  wxCommandEvent& event )
{
	if ( dModified )
	{
		u32 mode = MB( wxT( "Do you wish to save the codelist?" ),
				wxT( "Codelist Modified" ), wxYES_NO | wxCANCEL );
		if ( mode == wxCANCEL ) return;
		if ( mode == wxYES ) dSetHack();
	}
	gClose( this );
}
void SetHack_DLG::dLoadHack_OnClick( wxCommandEvent& event ) { dGetHack(); }
void SetHack_DLG::dSaveHack_OnClick( wxCommandEvent& event ) { dSetHack(); }
void SetHack_DLG::dNewCode_OnClick(  wxCommandEvent& event )
{
	dHack.NewCode( dGetCode() );
	dModified = true;
	dShowHack();
}
void SetHack_DLG::dSetCode_OnClick(  wxCommandEvent& event )
{
	if ( dIndex < 0 ) return;
	dHack[ dIndex ] = dGetCode();
	dModified = true;
	dShowHack();
}

void SetHack_DLG::dGetCode_OnClick(  wxCommandEvent& event ) { dShowCode(); }

void SetHack_DLG::dDelCode_OnClick(  wxCommandEvent& event )
{
	if ( dIndex < 0 ) return;
	dHack.DelCode( dIndex );
	dModified  = true;
	dIndex     = -1;
	dShowHack();
}
void SetHack_DLG::dCode_LCOnSelect(  wxListEvent&    event )
{
	dIndex = event.GetIndex();
	dIndex = dCode_LC->GetItemData( dIndex );
	dShowCode();
}
