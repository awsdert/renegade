///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

HEXFRM::HEXFRM( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,480 ), wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS|wxWS_EX_PROCESS_IDLE );
	
	SB = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* BS;
	BS = new wxBoxSizer( wxVERTICAL );
	
	NB = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	nbHook = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* bsHook;
	bsHook = new wxFlexGridSizer( 1, 2, 0, 0 );
	bsHook->AddGrowableCol( 1 );
	bsHook->AddGrowableRow( 0 );
	bsHook->SetFlexibleDirection( wxBOTH );
	bsHook->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wHookScroll = new wxScrolledWindow( nbHook, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	wHookScroll->SetScrollRate( 0, 5 );
	wHookScroll->SetMinSize( wxSize( 300,-1 ) );
	wHookScroll->SetMaxSize( wxSize( 300,-1 ) );
	
	wxBoxSizer* bsHookScroll;
	bsHookScroll = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* bsHook0;
	bsHook0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("Hook") ), wxVERTICAL );
	
	wxFlexGridSizer* bsHook1;
	bsHook1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	bsHook1->AddGrowableCol( 0 );
	bsHook1->SetFlexibleDirection( wxBOTH );
	bsHook1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* bsHook2;
	bsHook2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	bsHook2->AddGrowableCol( 0 );
	bsHook2->SetFlexibleDirection( wxBOTH );
	bsHook2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	cbGroup = new wxComboBox( wHookScroll, wxID_ANY, wxT("Playstation 2"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	cbGroup->Append( wxT("Nintendo DS") );
	cbGroup->Append( wxT("Nintendo Wii") );
	cbGroup->Append( wxT("Playstation 1") );
	cbGroup->Append( wxT("Playstation 2") );
	cbGroup->Append( wxT("PC 32") );
	cbGroup->Append( wxT("PC 64") );
	bsHook2->Add( cbGroup, 0, wxALL|wxEXPAND, 5 );
	
	bGroup = new wxButton( wHookScroll, wxID_ANY, wxT("Add Group"), wxDefaultPosition, wxDefaultSize, 0 );
	bsHook2->Add( bGroup, 0, wxALL, 5 );
	
	wxString rbHookChoices[] = { wxT("Application"), wxT("File") };
	int rbHookNChoices = sizeof( rbHookChoices ) / sizeof( wxString );
	rbHook = new wxRadioBox( wHookScroll, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, rbHookNChoices, rbHookChoices, 2, wxRA_SPECIFY_COLS );
	rbHook->SetSelection( 0 );
	bsHook2->Add( rbHook, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bsHook3;
	bsHook3 = new wxBoxSizer( wxVERTICAL );
	
	bHook = new wxButton( wHookScroll, wxID_ANY, wxT("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	bsHook3->Add( bHook, 0, wxALL, 5 );
	
	bLaunch = new wxButton( wHookScroll, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	bsHook3->Add( bLaunch, 0, wxALL, 5 );
	
	bsHook2->Add( bsHook3, 1, wxEXPAND, 5 );
	
	bsHook1->Add( bsHook2, 1, wxEXPAND, 5 );
	
	URL = new wxDirPickerCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bsHook1->Add( URL, 0, wxALL|wxEXPAND, 5 );
	
	bsHook0->Add( bsHook1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( bsHook0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* bsApp0;
	bsApp0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("App") ), wxVERTICAL );
	
	wxFlexGridSizer* bsApp1;
	bsApp1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	bsApp1->AddGrowableCol( 0 );
	bsApp1->SetFlexibleDirection( wxBOTH );
	bsApp1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	cbApp = new wxBitmapComboBox( wHookScroll, wxID_ANY, wxT("PCSX2 9.7+"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bsApp1->Add( cbApp, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* bsApp2;
	bsApp2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	bsApp2->AddGrowableCol( 1 );
	bsApp2->SetFlexibleDirection( wxBOTH );
	bsApp2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bApp = new wxButton( wHookScroll, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bsApp2->Add( bApp, 0, wxALL, 5 );
	
	tApp = new wxTextCtrl( wHookScroll, wxID_ANY, wxT("pcsx2.exe"), wxDefaultPosition, wxDefaultSize, 0 );
	bsApp2->Add( tApp, 0, wxALL|wxEXPAND, 5 );
	
	sWait = new wxStaticText( wHookScroll, wxID_ANY, wxT("Check"), wxDefaultPosition, wxDefaultSize, 0 );
	sWait->Wrap( -1 );
	bsApp2->Add( sWait, 0, wxALL, 5 );
	
	wxString mWaitChoices[] = { wxT("Never"), wxT("Every 1/2 a second"), wxT("Every Second"), wxT("Every 5 Seconds"), wxT("Every 30 Seconds"), wxT("Every Minute"), wxT("Every 5 Minutes"), wxT("Every 30 Minutes"), wxT("Every Hour") };
	int mWaitNChoices = sizeof( mWaitChoices ) / sizeof( wxString );
	mWait = new wxChoice( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, mWaitNChoices, mWaitChoices, 0 );
	mWait->SetSelection( 0 );
	mWait->SetToolTip( wxT("Check if App is Active") );
	
	bsApp2->Add( mWait, 0, wxALL|wxEXPAND, 5 );
	
	bsApp1->Add( bsApp2, 1, wxEXPAND, 5 );
	
	bsApp0->Add( bsApp1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( bsApp0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* bsFile0;
	bsFile0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("File") ), wxVERTICAL );
	
	wxFlexGridSizer* bsFile1;
	bsFile1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	bsFile1->AddGrowableCol( 0 );
	bsFile1->SetFlexibleDirection( wxBOTH );
	bsFile1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	cbFile = new wxComboBox( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bsFile1->Add( cbFile, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* bsFile2;
	bsFile2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	bsFile2->AddGrowableCol( 0 );
	bsFile2->SetFlexibleDirection( wxBOTH );
	bsFile2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	tFile = new wxTextCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bsFile2->Add( tFile, 0, wxALL|wxEXPAND, 5 );
	
	bFile = new wxButton( wHookScroll, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bsFile2->Add( bFile, 0, wxALL, 5 );
	
	bsFile1->Add( bsFile2, 1, wxEXPAND, 5 );
	
	bsFile0->Add( bsFile1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( bsFile0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* bsRAM0;
	bsRAM0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("Memory") ), wxVERTICAL );
	
	wxFlexGridSizer* bsRAM1;
	bsRAM1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	bsRAM1->AddGrowableCol( 0 );
	bsRAM1->SetFlexibleDirection( wxBOTH );
	bsRAM1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString rbRAMChoices[] = { wxT("Static"), wxT("Pointer") };
	int rbRAMNChoices = sizeof( rbRAMChoices ) / sizeof( wxString );
	rbRAM = new wxRadioBox( wHookScroll, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, rbRAMNChoices, rbRAMChoices, 2, wxRA_SPECIFY_COLS );
	rbRAM->SetSelection( 0 );
	bsRAM1->Add( rbRAM, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* bsRAM2;
	bsRAM2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	bsRAM2->AddGrowableCol( 1 );
	bsRAM2->SetFlexibleDirection( wxBOTH );
	bsRAM2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	sRAMStart = new wxStaticText( wHookScroll, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	sRAMStart->Wrap( -1 );
	bsRAM2->Add( sRAMStart, 0, wxALL, 5 );
	
	tRAMStart = new wxTextCtrl( wHookScroll, wxID_ANY, wxT("2000000"), wxDefaultPosition, wxDefaultSize, wxTE_CAPITALIZE|wxTE_RIGHT );
	bsRAM2->Add( tRAMStart, 0, wxALL|wxEXPAND, 5 );
	
	sRAMSize = new wxStaticText( wHookScroll, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	sRAMSize->Wrap( -1 );
	bsRAM2->Add( sRAMSize, 0, wxALL, 5 );
	
	tRAMSize = new wxTextCtrl( wHookScroll, wxID_ANY, wxT("1FFFFFF"), wxDefaultPosition, wxDefaultSize, wxTE_CAPITALIZE|wxTE_RIGHT );
	tRAMSize->SetToolTip( wxT("Set 0 if using until end of App / File") );
	
	bsRAM2->Add( tRAMSize, 0, wxALL|wxEXPAND, 5 );
	
	bsRAM1->Add( bsRAM2, 1, wxEXPAND, 5 );
	
	bsRAM0->Add( bsRAM1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( bsRAM0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wHookScroll->SetSizer( bsHookScroll );
	wHookScroll->Layout();
	bsHook->Add( wHookScroll, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* bsAppList;
	bsAppList = new wxFlexGridSizer( 0, 1, 0, 0 );
	bsAppList->AddGrowableCol( 0 );
	bsAppList->AddGrowableRow( 1 );
	bsAppList->SetFlexibleDirection( wxBOTH );
	bsAppList->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* bsAppList1;
	bsAppList1 = new wxFlexGridSizer( 1, 0, 0, 0 );
	bsAppList1->SetFlexibleDirection( wxBOTH );
	bsAppList1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bAppList = new wxButton( nbHook, wxID_ANY, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	bsAppList1->Add( bAppList, 0, wxALL, 5 );
	
	bAppUse = new wxButton( nbHook, wxID_ANY, wxT("Use Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	bsAppList1->Add( bAppUse, 0, wxALL, 5 );
	
	bsAppList->Add( bsAppList1, 1, wxEXPAND, 5 );
	
	gApp = new wxGrid( nbHook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	gApp->CreateGrid( 0, 2 );
	gApp->EnableEditing( false );
	gApp->EnableGridLines( false );
	gApp->EnableDragGridSize( false );
	gApp->SetMargins( 0, 0 );
	
	// Columns
	gApp->EnableDragColMove( false );
	gApp->EnableDragColSize( true );
	gApp->SetColLabelSize( 20 );
	gApp->SetColLabelValue( 0, wxT("App") );
	gApp->SetColLabelValue( 1, wxT("Title") );
	gApp->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gApp->EnableDragRowSize( true );
	gApp->SetRowLabelSize( 50 );
	gApp->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gApp->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bsAppList->Add( gApp, 0, wxEXPAND, 5 );
	
	bsHook->Add( bsAppList, 1, wxEXPAND, 5 );
	
	nbHook->SetSizer( bsHook );
	nbHook->Layout();
	bsHook->Fit( nbHook );
	NB->AddPage( nbHook, wxT("Hook"), true );
	nbFind = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbFind, wxT("Find"), false );
	nbResults = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbResults, wxT("Results"), false );
	nbEdit = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbEdit, wxT("Editor"), false );
	nbDB = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbDB, wxT("Database"), false );
	nbHack = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbHack, wxT("Hack"), false );
	nbAbout = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbAbout, wxT("About"), false );
	
	BS->Add( NB, 1, wxEXPAND, 0 );
	
	this->SetSizer( BS );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HEXFRM::OnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( HEXFRM::HEXFORMIDLE ) );
	cbGroup->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::groupOnBlur ), NULL, this );
	bGroup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::groupOnClick ), NULL, this );
	cbApp->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	bApp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	mWait->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	bFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	bAppList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppListOnClick ), NULL, this );
	bAppUse->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppUseOnClick ), NULL, this );
}

HEXFRM::~HEXFRM()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HEXFRM::OnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HEXFRM::HEXFORMIDLE ) );
	cbGroup->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::groupOnBlur ), NULL, this );
	bGroup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::groupOnClick ), NULL, this );
	cbApp->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	bApp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	mWait->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	bFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	bAppList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppListOnClick ), NULL, this );
	bAppUse->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppUseOnClick ), NULL, this );
	
}
