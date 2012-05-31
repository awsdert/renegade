#include "G.h"
G::G( wxWindow* parent )
:
cleanFRM( parent )
{
	// Initialise
	isHooked  = 0;
	editIsRecursing = 0;
	isFocus   = false;
	isEdit    = false;
	lLastText = wxT( "Last State"   );
	lOrgText  = wxT( "Organisation" );
	lPFMText  = wxT( "Platform"     );
	lBinText  = wxT( "Binary"       );
	lDBPText  = wxT( "Profile"      );
	// wxChoice filling
	lArea_CB.resize( AREA_COUNT );
	xStr  text = wxT( '0' );
	xAStr array = gGetArea();
	s32 index;
	for ( index = 0; index < AREA_COUNT; ++index )
	{
		lArea_CB[ index ] = new wxCheckBox( dbpAreaCB_P, wxID_ANY, array[ index ] );
		dbpAreaCB_LG->Add( lArea_CB[ index ], 0, wxBORDER | wxALL, 5 );
		lArea_CB[ index ]->SetValue( true );
	}
	dbp_P->Layout();
	// Find Tab
	array.Clear();
	array.SetCount( QV_COUNT );
	array[ QV_EQUAL         ] = wxT( "="  );
	array[ QV_NOT_EQUAL     ] = wxT( "!=" );
	array[ QV_MORE_THAN     ] = wxT( ">"  );
	array[ QV_MORE_OR_EQUAL ] = wxT( ">=" );
	array[ QV_LESS_THAN     ] = wxT( "<"  );
	array[ QV_LESS_OR_EQUAL ] = wxT( "<=" );
	mQVG_CB.resize(   QV_COUNT );
	mQVG_TXT.resize(  QV_COUNT );
	mQVGArray.resize( QV_COUNT );
	mQVB_CB.resize(   QV_COUNT );
	mQVB_TXT.resize(  QV_COUNT );
	mQVBArray.resize( QV_COUNT );
	wxSize size( 50, -1 );
	for ( index = 0; index < QV_COUNT; ++index )
	{
		mQVG_CB[   index ] = new wxCheckBox( good_SCROLL, goodV_ID, array[ index ] );
		mQVB_CB[   index ] = new wxCheckBox( bad_SCROLL,  badV_ID, array[ index ] );
		mQVG_TXT[  index ] = new wxTextCtrl( good_SCROLL, goodV_ID, text );
		mQVB_TXT[  index ] = new wxTextCtrl( bad_SCROLL,  badV_ID, text );
		mQVG_TXT[  index ]->SetMinSize( size );
		mQVB_TXT[  index ]->SetMinSize( size );
		mQVGArray[ index ] = 0u;
		mQVBArray[ index ] = 0u;
		goodV_L->Add( mQVG_CB[  index ], 0, wxALIGN_CENTER_VERTICAL | wxBORDER | wxALL, 5 );
		goodV_L->Add( mQVG_TXT[ index ], 0, wxEXPAND | wxBORDER | wxALL, 5 );
		badV_L->Add(  mQVB_CB[  index ], 0, wxALIGN_CENTER_VERTICAL | wxBORDER | wxALL, 5 );
		badV_L->Add(  mQVB_TXT[ index ], 0, wxEXPAND | wxBORDER | wxALL, 5 );
	}
	Connect( goodV_ID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( G::find_TXTOnChange ) );
	Connect( badV_ID,  wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( G::find_TXTOnChange ) );
	good_SCROLL->FitInside();
	bad_SCROLL->FitInside();
	// - Time
	hookAdd = 0u;
	listAdd = 0u;
	editAdd = 0u;
	array.Clear();
	array.SetCount( 9 );
	array[ 0 ] = wxT( "Never" );
	array[ 1 ] = wxT( "Every 500 Miliseconds" );
	array[ 2 ] = wxT( "Every Second" );
	array[ 3 ] = wxT( "Every 5 Seconds" );
	array[ 4 ] = wxT( "Every 30 Seconds" );
	array[ 5 ] = wxT( "Every Minute" );
	array[ 6 ] = wxT( "Every 5 Minutes" );
	array[ 7 ] = wxT( "Every 30 Minutes" );
	array[ 8 ] = wxT( "Every Hour" );
	UseHook_D->Append( array );
	ListApps_D->Append( array );
	editUpdate_D->Append( array );
	UseHook_D->Select( 0 );
	ListApps_D->Select( 0 );
	editUpdate_D->Select( 0 );
	// - Value Sizes
	array.Clear();
	array.SetCount( 4 );
	array[ 0 ] = wxT("8bit");
	array[ 1 ] = wxT("16bit");
	array[ 2 ] = wxT("32bit");
	array[ 3 ] = wxT("64bit");
	findSize_D->Append( array );
	 outSize_D->Append( array );
	editSize_D->Append( array );
	findSize_D->Select( 0 );
	 outSize_D->Select( 0 );
	editSize_D->Select( 0 );
	// - Value Modes
	array.Clear();
	array.SetCount( VAL_COUNT );
	array[ VAL_HEX ]  = wxT( "HexaDecimal"  );
	array[ VAL_SINT ] = wxT( "Signed No"    );
	array[ VAL_UINT ] = wxT( "Unsigned No"  );
	array[ VAL_SFLT ] = wxT( "Signed Float" );
	findMode_D->Clear();
	findMode_D->Append( array );
	findMode_D->Select( 0 );
	outMode_D->Clear();
	outMode_D->Append( array );
	outMode_D->Select( 0 );
	editMode_D->Clear();
	editMode_D->Append( array );
	editMode_D->Select( 0 );
	// App List
	wxListItem item;
	item.SetId( 0 );
	item.SetWidth( 60 );
	item.SetText( wxT( "ID" ) );
	ListApps_LC->InsertColumn( 0, item );
	item.SetId( 1 );
	item.SetWidth( 90 );
	item.SetText( wxT( "Name" ) );
	ListApps_LC->InsertColumn( 1, item );
	item.SetId( 2 );
	item.SetWidth( 150 );
	item.SetText( wxT( "Title" ) );
	ListApps_LC->InsertColumn( 2, item );
	// Results
	item.SetId( 0 );
	item.SetWidth( 130 );
	item.SetText( wxT( "Address" ) );
	outData_LC->InsertColumn( 0, item );
	item.SetId( 1 );
	item.SetText( wxT( "Value" ) );
	outData_LC->InsertColumn( 1, item );
	item.SetId( 2 );
	item.SetWidth( 30 );
	item.SetText( wxT( "Size" ) );
	outData_LC->InsertColumn( 2, item );
	// Code List
	item.SetId( 0 );
	item.SetWidth( 125 );
	item.SetText( wxT( "Part 1" ) );
	code_LC->InsertColumn( 0, item );
	item.SetId( 1 );
	item.SetText( wxT( "Part 2" ) );
	code_LC->InsertColumn( 1, item );
	// Load Last Session
	mLoadSession();
}
void G::GOnClose( wxCloseEvent& event )
{
	hookUntil = 0;
	listUntil = 0;
	editUntil = 0;
	Disconnect( goodV_ID, wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( G::find_TXTOnChange ) );
	Disconnect( badV_ID,  wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( G::find_TXTOnChange ) );
	ramName_D->Clear();
	ListApps_LC->DeleteAllItems();
	tree_T->DeleteAllItems();
	code_LC->DeleteAllItems();
	out_LC->DeleteAllItems();
	outData_LC->DeleteAllItems();
	event.Skip();
}
