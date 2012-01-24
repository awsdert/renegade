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

// Using the construction of a static object to ensure that the help provider is set
class wxFBContextSensitiveHelpSetter
{
public:
wxFBContextSensitiveHelpSetter()
{
wxHelpProvider::Set( new wxHelpControllerHelpProvider );
}
};

static wxFBContextSensitiveHelpSetter s_wxFBSetTheHelpProvider;
///////////////////////////////////////////////////////////////////////////

HEXFRM::HEXFRM( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 640,480 ), wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
	
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
	
	wHookScroll = new wxScrolledWindow( nbHook, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxVSCROLL );
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
	NB->AddPage( nbHook, wxT("Hook"), false );
	nbFind = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	NB->AddPage( nbFind, wxT("Find"), false );
	nbResults = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer12;
	fgSizer12 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer12->AddGrowableCol( 0 );
	fgSizer12->AddGrowableRow( 0 );
	fgSizer12->SetFlexibleDirection( wxBOTH );
	fgSizer12->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_grid2 = new wxGrid( nbResults, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid2->CreateGrid( 0, 0 );
	m_grid2->EnableEditing( false );
	m_grid2->EnableGridLines( true );
	m_grid2->EnableDragGridSize( false );
	m_grid2->SetMargins( 0, 0 );
	
	// Columns
	m_grid2->EnableDragColMove( false );
	m_grid2->EnableDragColSize( true );
	m_grid2->SetColLabelSize( 15 );
	m_grid2->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid2->EnableDragRowSize( true );
	m_grid2->SetRowLabelSize( 15 );
	m_grid2->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid2->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer12->Add( m_grid2, 0, wxALL|wxEXPAND, 5 );
	
	m_panel8 = new wxPanel( nbResults, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), wxTAB_TRAVERSAL );
	m_panel8->SetMinSize( wxSize( 200,-1 ) );
	m_panel8->SetMaxSize( wxSize( 200,-1 ) );
	
	wxFlexGridSizer* fgSizer13;
	fgSizer13 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer13->AddGrowableRow( 0 );
	fgSizer13->SetFlexibleDirection( wxBOTH );
	fgSizer13->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_grid3 = new wxGrid( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid3->CreateGrid( 0, 3 );
	m_grid3->EnableEditing( true );
	m_grid3->EnableGridLines( true );
	m_grid3->EnableDragGridSize( false );
	m_grid3->SetMargins( 0, 0 );
	
	// Columns
	m_grid3->EnableDragColMove( false );
	m_grid3->EnableDragColSize( true );
	m_grid3->SetColLabelSize( 15 );
	m_grid3->SetColLabelValue( 0, wxT("Type") );
	m_grid3->SetColLabelValue( 1, wxT("Address") );
	m_grid3->SetColLabelValue( 2, wxT("Value") );
	m_grid3->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid3->EnableDragRowSize( true );
	m_grid3->SetRowLabelSize( 1 );
	m_grid3->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid3->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer13->Add( m_grid3, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_panel8, wxID_ANY, wxT("label") ), wxVERTICAL );
	
	wxFlexGridSizer* fgSizer17;
	fgSizer17 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer17->AddGrowableCol( 0 );
	fgSizer17->SetFlexibleDirection( wxBOTH );
	fgSizer17->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText4 = new wxStaticText( m_panel8, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	fgSizer17->Add( m_staticText4, 0, wxALL, 5 );
	
	m_button8 = new wxButton( m_panel8, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer17->Add( m_button8, 0, 0, 5 );
	
	sbSizer5->Add( fgSizer17, 1, wxEXPAND, 5 );
	
	wxString m_choice2Choices[] = { wxT("0x00 (CHAR)"), wxT("0x0000 (WORD)"), wxT("0x00000000 (DWORD)"), wxT("0x0000000000000000 (QWORD)") };
	int m_choice2NChoices = sizeof( m_choice2Choices ) / sizeof( wxString );
	m_choice2 = new wxChoice( m_panel8, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choice2NChoices, m_choice2Choices, 0 );
	m_choice2->SetSelection( 0 );
	sbSizer5->Add( m_choice2, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText5 = new wxStaticText( m_panel8, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	sbSizer5->Add( m_staticText5, 0, wxALL, 5 );
	
	m_textCtrl5 = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_textCtrl5, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText6 = new wxStaticText( m_panel8, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	sbSizer5->Add( m_staticText6, 0, wxALL, 5 );
	
	m_textCtrl6 = new wxTextCtrl( m_panel8, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer5->Add( m_textCtrl6, 0, wxALL|wxEXPAND, 5 );
	
	fgSizer13->Add( sbSizer5, 0, wxALL|wxEXPAND, 5 );
	
	m_panel8->SetSizer( fgSizer13 );
	m_panel8->Layout();
	fgSizer12->Add( m_panel8, 0, wxEXPAND | wxALL, 5 );
	
	nbResults->SetSizer( fgSizer12 );
	nbResults->Layout();
	fgSizer12->Fit( nbResults );
	NB->AddPage( nbResults, wxT("Results"), false );
	nbEdit = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer16;
	fgSizer16 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer16->AddGrowableCol( 0 );
	fgSizer16->AddGrowableRow( 1 );
	fgSizer16->SetFlexibleDirection( wxBOTH );
	fgSizer16->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer24;
	fgSizer24 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer24->SetFlexibleDirection( wxBOTH );
	fgSizer24->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_button9 = new wxButton( nbEdit, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24->Add( m_button9, 0, wxALL, 5 );
	
	m_textCtrl10 = new wxTextCtrl( nbEdit, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24->Add( m_textCtrl10, 0, wxALL, 5 );
	
	m_button10 = new wxButton( nbEdit, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24->Add( m_button10, 0, wxALL, 5 );
	
	m_textCtrl11 = new wxTextCtrl( nbEdit, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer24->Add( m_textCtrl11, 0, wxALL, 5 );
	
	fgSizer16->Add( fgSizer24, 1, wxEXPAND, 5 );
	
	m_grid4 = new wxGrid( nbEdit, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid4->CreateGrid( 0, 10 );
	m_grid4->EnableEditing( true );
	m_grid4->EnableGridLines( true );
	m_grid4->EnableDragGridSize( false );
	m_grid4->SetMargins( 0, 0 );
	
	// Columns
	m_grid4->EnableDragColMove( false );
	m_grid4->EnableDragColSize( true );
	m_grid4->SetColLabelSize( 30 );
	m_grid4->SetColLabelValue( 0, wxT("Address") );
	m_grid4->SetColLabelValue( 1, wxT("0-1") );
	m_grid4->SetColLabelValue( 2, wxT("2-3") );
	m_grid4->SetColLabelValue( 3, wxT("4-5") );
	m_grid4->SetColLabelValue( 4, wxT("6-7") );
	m_grid4->SetColLabelValue( 5, wxT("8-9") );
	m_grid4->SetColLabelValue( 6, wxT("A-B") );
	m_grid4->SetColLabelValue( 7, wxT("C-D") );
	m_grid4->SetColLabelValue( 8, wxT("E-F") );
	m_grid4->SetColLabelValue( 9, wxT("Text") );
	m_grid4->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid4->EnableDragRowSize( true );
	m_grid4->SetRowLabelSize( 1 );
	m_grid4->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid4->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	fgSizer16->Add( m_grid4, 0, wxEXPAND, 5 );
	
	nbEdit->SetSizer( fgSizer16 );
	nbEdit->Layout();
	fgSizer16->Fit( nbEdit );
	NB->AddPage( nbEdit, wxT("Editor"), false );
	nbDB = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer18;
	fgSizer18 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer18->AddGrowableCol( 0 );
	fgSizer18->AddGrowableRow( 0 );
	fgSizer18->SetFlexibleDirection( wxBOTH );
	fgSizer18->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* fgSizer19;
	fgSizer19 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer19->AddGrowableCol( 0 );
	fgSizer19->AddGrowableRow( 1 );
	fgSizer19->SetFlexibleDirection( wxBOTH );
	fgSizer19->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( nbDB, wxID_ANY, wxT("Region") ), wxVERTICAL );
	
	sbSizer6->SetMinSize( wxSize( -1,50 ) ); 
	m_scrolledWindow3 = new wxScrolledWindow( nbDB, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_scrolledWindow3->SetScrollRate( 5, 0 );
	wxFlexGridSizer* fgSizer20;
	fgSizer20 = new wxFlexGridSizer( 1, 0, 0, 0 );
	fgSizer20->AddGrowableRow( 0 );
	fgSizer20->SetFlexibleDirection( wxVERTICAL );
	fgSizer20->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_ALL );
	
	m_radioBtn1 = new wxRadioButton( m_scrolledWindow3, wxID_ANY, wxT("UK"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_radioBtn1, 0, wxALL|wxEXPAND, 5 );
	
	m_radioBtn11 = new wxRadioButton( m_scrolledWindow3, wxID_ANY, wxT("US"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_radioBtn11, 0, wxALL|wxEXPAND, 5 );
	
	m_radioBtn5 = new wxRadioButton( m_scrolledWindow3, wxID_ANY, wxT("Germany"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_radioBtn5, 0, wxALL|wxEXPAND, 5 );
	
	m_radioBtn6 = new wxRadioButton( m_scrolledWindow3, wxID_ANY, wxT("Japan"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_radioBtn6, 0, wxALL|wxEXPAND, 5 );
	
	m_radioBtn7 = new wxRadioButton( m_scrolledWindow3, wxID_ANY, wxT("Canadia"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer20->Add( m_radioBtn7, 0, wxALL|wxEXPAND, 5 );
	
	m_scrolledWindow3->SetSizer( fgSizer20 );
	m_scrolledWindow3->Layout();
	fgSizer20->Fit( m_scrolledWindow3 );
	sbSizer6->Add( m_scrolledWindow3, 1, wxEXPAND, 5 );
	
	fgSizer19->Add( sbSizer6, 0, wxALL|wxEXPAND, 5 );
	
	m_listBox1 = new wxListBox( nbDB, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	fgSizer19->Add( m_listBox1, 0, wxALL|wxEXPAND, 5 );
	
	fgSizer18->Add( fgSizer19, 0, wxEXPAND, 5 );
	
	m_panel9 = new wxPanel( nbDB, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxTAB_TRAVERSAL );
	m_panel9->SetMinSize( wxSize( 300,-1 ) );
	m_panel9->SetMaxSize( wxSize( 300,-1 ) );
	
	wxFlexGridSizer* fgSizer22;
	fgSizer22 = new wxFlexGridSizer( 0, 1, 0, 0 );
	fgSizer22->AddGrowableCol( 0 );
	fgSizer22->AddGrowableRow( 2 );
	fgSizer22->SetFlexibleDirection( wxBOTH );
	fgSizer22->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fgSizer22->SetMinSize( wxSize( 300,-1 ) ); 
	wxFlexGridSizer* fgSizer191;
	fgSizer191 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer191->AddGrowableCol( 1 );
	fgSizer191->SetFlexibleDirection( wxBOTH );
	fgSizer191->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText7 = new wxStaticText( m_panel9, wxID_ANY, wxT("Serial ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	fgSizer191->Add( m_staticText7, 0, wxALL, 5 );
	
	m_textCtrl7 = new wxTextCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer191->Add( m_textCtrl7, 0, wxALL|wxEXPAND, 5 );
	
	fgSizer22->Add( fgSizer191, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer21;
	fgSizer21 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer21->AddGrowableCol( 1 );
	fgSizer21->SetFlexibleDirection( wxBOTH );
	fgSizer21->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText8 = new wxStaticText( m_panel9, wxID_ANY, wxT("App / File ID"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	fgSizer21->Add( m_staticText8, 0, wxALL, 5 );
	
	m_textCtrl8 = new wxTextCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer21->Add( m_textCtrl8, 0, wxALL|wxEXPAND, 5 );
	
	fgSizer22->Add( fgSizer21, 0, wxEXPAND, 5 );
	
	m_textCtrl9 = new wxTextCtrl( m_panel9, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	fgSizer22->Add( m_textCtrl9, 0, wxALL|wxEXPAND, 5 );
	
	m_panel9->SetSizer( fgSizer22 );
	m_panel9->Layout();
	fgSizer18->Add( m_panel9, 0, wxALL|wxEXPAND, 5 );
	
	nbDB->SetSizer( fgSizer18 );
	nbDB->Layout();
	fgSizer18->Fit( nbDB );
	NB->AddPage( nbDB, wxT("Database"), false );
	nbHack = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* lHack;
	lHack = new wxFlexGridSizer( 0, 2, 0, 0 );
	lHack->AddGrowableCol( 0 );
	lHack->AddGrowableRow( 0 );
	lHack->SetFlexibleDirection( wxBOTH );
	lHack->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* lHackTree;
	lHackTree = new wxFlexGridSizer( 0, 1, 0, 0 );
	lHackTree->AddGrowableCol( 0 );
	lHackTree->AddGrowableRow( 1 );
	lHackTree->SetFlexibleDirection( wxBOTH );
	lHackTree->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* lHackAddDel;
	lHackAddDel = new wxFlexGridSizer( 0, 4, 0, 0 );
	lHackAddDel->AddGrowableCol( 0 );
	lHackAddDel->AddGrowableCol( 1 );
	lHackAddDel->AddGrowableCol( 2 );
	lHackAddDel->AddGrowableCol( 3 );
	lHackAddDel->SetFlexibleDirection( wxBOTH );
	lHackAddDel->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString cbAddHackChoices[] = { wxT("Start"), wxT("Before"), wxT("After"), wxT("End") };
	int cbAddHackNChoices = sizeof( cbAddHackChoices ) / sizeof( wxString );
	cbAddHack = new wxChoice( nbHack, wxID_ANY, wxDefaultPosition, wxDefaultSize, cbAddHackNChoices, cbAddHackChoices, 0 );
	cbAddHack->SetSelection( 3 );
	cbAddHack->SetMinSize( wxSize( 50,-1 ) );
	
	lHackAddDel->Add( cbAddHack, 0, wxALL|wxEXPAND, 5 );
	
	cAddHack = new wxCheckBox( nbHack, wxID_ANY, wxT("Chilld"), wxDefaultPosition, wxDefaultSize, 0 );
	lHackAddDel->Add( cAddHack, 0, wxALL|wxEXPAND, 5 );
	
	bAddHack = new wxButton( nbHack, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	lHackAddDel->Add( bAddHack, 0, wxALL|wxEXPAND, 5 );
	
	bDelHack = new wxButton( nbHack, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	lHackAddDel->Add( bDelHack, 0, wxALL|wxEXPAND, 5 );
	
	lHackTree->Add( lHackAddDel, 1, wxEXPAND, 5 );
	
	treeHack = new wxTreeCtrl( nbHack, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_EDIT_LABELS|wxTR_HIDE_ROOT );
	treeHack->SetToolTip( wxT("When a Hack / Node is selected the following actions can be peformed with the CTRL key held down:\nAdd = Add Hack / Node to List (List box decides position)\nMinus = Remove Hack / Node\nArrow = Move Hack / Node in that direction") );
	
	lHackTree->Add( treeHack, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* lHackMove;
	lHackMove = new wxFlexGridSizer( 0, 2, 0, 0 );
	lHackMove->SetFlexibleDirection( wxBOTH );
	lHackMove->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bHackMove = new wxButton( nbHack, wxID_ANY, wxT("Move"), wxDefaultPosition, wxDefaultSize, 0 );
	lHackMove->Add( bHackMove, 0, wxALL, 5 );
	
	wxString cbHackMoveChoices[] = { wxT("Up"), wxT("Down"), wxT("Left"), wxT("Right") };
	int cbHackMoveNChoices = sizeof( cbHackMoveChoices ) / sizeof( wxString );
	cbHackMove = new wxChoice( nbHack, wxID_ANY, wxDefaultPosition, wxDefaultSize, cbHackMoveNChoices, cbHackMoveChoices, 0 );
	cbHackMove->SetSelection( 0 );
	lHackMove->Add( cbHackMove, 0, wxALL, 5 );
	
	lHackTree->Add( lHackMove, 1, wxEXPAND, 5 );
	
	lHack->Add( lHackTree, 1, wxEXPAND, 5 );
	
	wHackScroll = new wxScrolledWindow( nbHack, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxHSCROLL|wxVSCROLL );
	wHackScroll->SetScrollRate( 0, 5 );
	wHackScroll->SetMinSize( wxSize( 300,-1 ) );
	wHackScroll->SetMaxSize( wxSize( 300,-1 ) );
	
	wxFlexGridSizer* lHackCodes;
	lHackCodes = new wxFlexGridSizer( 0, 1, 0, 0 );
	lHackCodes->AddGrowableCol( 0 );
	lHackCodes->AddGrowableRow( 1 );
	lHackCodes->SetFlexibleDirection( wxBOTH );
	lHackCodes->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	lHackCodes->SetMinSize( wxSize( 300,-1 ) ); 
	wxFlexGridSizer* fgSizer30;
	fgSizer30 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer30->AddGrowableCol( 1 );
	fgSizer30->SetFlexibleDirection( wxBOTH );
	fgSizer30->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	sHackType = new wxStaticText( wHackScroll, wxID_ANY, wxT("Code Type"), wxDefaultPosition, wxDefaultSize, 0 );
	sHackType->Wrap( -1 );
	fgSizer30->Add( sHackType, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackTypeChoices[] = { wxT("Write"), wxT("Copy"), wxT("Test"), wxT("Increment"), wxT("Decrement"), wxT("List Write") };
	int mHackTypeNChoices = sizeof( mHackTypeChoices ) / sizeof( wxString );
	mHackType = new wxChoice( wHackScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackTypeNChoices, mHackTypeChoices, 0 );
	mHackType->SetSelection( 0 );
	fgSizer30->Add( mHackType, 0, wxALL|wxEXPAND, 5 );
	
	cHackR = new wxCheckBox( wHackScroll, wxID_ANY, wxT("Repeats"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( cHackR, 1, wxALL|wxEXPAND, 5 );
	
	sHackRAM = new wxStaticText( wHackScroll, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackRAM->Wrap( -1 );
	fgSizer30->Add( sHackRAM, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackRAMChoices[] = { wxT("Main") };
	int mHackRAMNChoices = sizeof( mHackRAMChoices ) / sizeof( wxString );
	mHackRAM = new wxChoice( wHackScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackRAMNChoices, mHackRAMChoices, 0 );
	mHackRAM->SetSelection( 0 );
	fgSizer30->Add( mHackRAM, 0, wxALL|wxEXPAND, 5 );
	
	nHackR = new wxSpinCtrl( wHackScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	nHackR->SetToolTip( wxT("Repeats on how many Addresses") );
	nHackR->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer30->Add( nHackR, 1, wxALL|wxEXPAND, 5 );
	
	sHackA = new wxStaticText( wHackScroll, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackA->Wrap( -1 );
	fgSizer30->Add( sHackA, 0, wxALL|wxEXPAND, 5 );
	
	tHackA = new wxTextCtrl( wHackScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( tHackA, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackAChoices[] = { wxT("Fixed"), wxT("Pointer") };
	int mHackANChoices = sizeof( mHackAChoices ) / sizeof( wxString );
	mHackA = new wxChoice( wHackScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackANChoices, mHackAChoices, 0 );
	mHackA->SetSelection( 0 );
	fgSizer30->Add( mHackA, 0, wxALL|wxEXPAND, 5 );
	
	sHackV = new wxStaticText( wHackScroll, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackV->Wrap( -1 );
	fgSizer30->Add( sHackV, 0, wxALL|wxEXPAND, 5 );
	
	tHackV = new wxTextCtrl( wHackScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( tHackV, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackVChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int mHackVNChoices = sizeof( mHackVChoices ) / sizeof( wxString );
	mHackV = new wxChoice( wHackScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackVNChoices, mHackVChoices, 0 );
	mHackV->SetSelection( 0 );
	fgSizer30->Add( mHackV, 0, wxALL|wxEXPAND, 5 );
	
	sHackADI = new wxStaticText( wHackScroll, wxID_ANY, wxT("Add / Minus"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackADI->Wrap( -1 );
	fgSizer30->Add( sHackADI, 0, wxALL|wxEXPAND, 5 );
	
	tHachADI = new wxTextCtrl( wHackScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( tHachADI, 0, wxALL|wxEXPAND, 5 );
	
	noteHackADI = new wxStaticText( wHackScroll, wxID_ANY, wxT("x 1 (Address)"), wxDefaultPosition, wxDefaultSize, 0 );
	noteHackADI->Wrap( -1 );
	fgSizer30->Add( noteHackADI, 0, wxALL|wxEXPAND, 5 );
	
	sHackVDI = new wxStaticText( wHackScroll, wxID_ANY, wxT("Add / Minus"), wxDefaultPosition, wxDefaultSize, 0 );
	sHackVDI->Wrap( -1 );
	fgSizer30->Add( sHackVDI, 0, wxALL|wxEXPAND, 5 );
	
	tHackVDI = new wxTextCtrl( wHackScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( tHackVDI, 0, wxALL|wxEXPAND, 5 );
	
	noteHackVDI = new wxStaticText( wHackScroll, wxID_ANY, wxT("(Value)"), wxDefaultPosition, wxDefaultSize, 0 );
	noteHackVDI->Wrap( -1 );
	fgSizer30->Add( noteHackVDI, 0, wxALL, 5 );
	
	bHackLoad = new wxButton( wHackScroll, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bHackLoad->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer30->Add( bHackLoad, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer29;
	fgSizer29 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer29->AddGrowableCol( 1 );
	fgSizer29->SetFlexibleDirection( wxBOTH );
	fgSizer29->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	cHackUse = new wxCheckBox( wHackScroll, wxID_ANY, wxT("Use"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer29->Add( cHackUse, 0, wxALL|wxEXPAND, 5 );
	
	bHackCAdd = new wxButton( wHackScroll, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer29->Add( bHackCAdd, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	fgSizer30->Add( fgSizer29, 1, wxEXPAND, 5 );
	
	bHackCDel = new wxButton( wHackScroll, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer30->Add( bHackCDel, 0, wxALL, 5 );
	
	lHackCodes->Add( fgSizer30, 1, wxEXPAND, 5 );
	
	gCodelist = new wxGrid( wHackScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	
	// Grid
	gCodelist->CreateGrid( 0, 2 );
	gCodelist->EnableEditing( true );
	gCodelist->EnableGridLines( true );
	gCodelist->EnableDragGridSize( false );
	gCodelist->SetMargins( 0, 0 );
	
	// Columns
	gCodelist->SetColSize( 0, 140 );
	gCodelist->SetColSize( 1, 140 );
	gCodelist->EnableDragColMove( false );
	gCodelist->EnableDragColSize( true );
	gCodelist->SetColLabelSize( 15 );
	gCodelist->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	gCodelist->EnableDragRowSize( true );
	gCodelist->SetRowLabelSize( 20 );
	gCodelist->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	gCodelist->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	lHackCodes->Add( gCodelist, 0, wxEXPAND, 5 );
	
	wHackScroll->SetSizer( lHackCodes );
	wHackScroll->Layout();
	lHack->Add( wHackScroll, 1, wxEXPAND | wxALL, 5 );
	
	nbHack->SetSizer( lHack );
	nbHack->Layout();
	lHack->Fit( nbHack );
	NB->AddPage( nbHack, wxT("Hack"), true );
	nbAbout = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( nbAbout, wxID_ANY, wxT("HackerEX (Awsdert, Viper)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText10->Wrap( -1 );
	bSizer4->Add( m_staticText10, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink2 = new wxHyperlinkCtrl( nbAbout, wxID_ANY, wxT("Google Code Project"), wxT("http://code.google.com/p/renegade"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink2, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText9 = new wxStaticText( nbAbout, wxID_ANY, wxT("Renegade64 / RenegadeEx (Viper)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText9->Wrap( -1 );
	bSizer4->Add( m_staticText9, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( nbAbout, wxID_ANY, wxT("Website"), wxT("http://viper.shadowflareindustries.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink1, 0, wxALL|wxEXPAND, 5 );
	
	nbAbout->SetSizer( bSizer4 );
	nbAbout->Layout();
	bSizer4->Fit( nbAbout );
	NB->AddPage( nbAbout, wxT("About"), false );
	
	BS->Add( NB, 1, wxEXPAND, 0 );
	
	this->SetSizer( BS );
	this->Layout();
	SB = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HEXFRM::HEXFORMCLOSE ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( HEXFRM::HEXFORMIDLE ) );
	cbGroup->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::groupOnBlur ), NULL, this );
	bGroup->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::groupOnClick ), NULL, this );
	cbApp->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	bApp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	mWait->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	bFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	bAppList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppListOnClick ), NULL, this );
	bAppUse->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppUseOnClick ), NULL, this );
	bAddHack->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAddHackOnClick ), NULL, this );
	bDelHack->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bDelHackOnClick ), NULL, this );
	treeHack->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::treeHackOnKeyDown ), NULL, this );
	bHackCAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHackCAddOnClick ), NULL, this );
	bHackCDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHackCDelOnClick ), NULL, this );
}

HEXFRM::~HEXFRM()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HEXFRM::HEXFORMCLOSE ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HEXFRM::HEXFORMIDLE ) );
	cbGroup->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::groupOnBlur ), NULL, this );
	bGroup->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::groupOnClick ), NULL, this );
	cbApp->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	bApp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	mWait->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	bFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appOnClick ), NULL, this );
	bAppList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppListOnClick ), NULL, this );
	bAppUse->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAppUseOnClick ), NULL, this );
	bAddHack->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAddHackOnClick ), NULL, this );
	bDelHack->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bDelHackOnClick ), NULL, this );
	treeHack->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::treeHackOnKeyDown ), NULL, this );
	bHackCAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHackCAddOnClick ), NULL, this );
	bHackCDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHackCDelOnClick ), NULL, this );
	
}
