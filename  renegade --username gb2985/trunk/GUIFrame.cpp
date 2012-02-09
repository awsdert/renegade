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
	
	wHookScroll = new wxScrolledWindow( nbHook, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), 0 );
	wHookScroll->SetScrollRate( 0, 5 );
	wHookScroll->SetMinSize( wxSize( 300,-1 ) );
	wHookScroll->SetMaxSize( wxSize( 300,-1 ) );
	
	wxBoxSizer* bsHookScroll;
	bsHookScroll = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* PFL0;
	PFL0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("Hook") ), wxVERTICAL );
	
	wxFlexGridSizer* PFL1;
	PFL1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	PFL1->AddGrowableCol( 0 );
	PFL1->SetFlexibleDirection( wxBOTH );
	PFL1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* PFL2;
	PFL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	PFL2->AddGrowableCol( 0 );
	PFL2->SetFlexibleDirection( wxBOTH );
	PFL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxArrayString PFDChoices;
	PFD = new wxChoice( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, PFDChoices, 0 );
	PFD->SetSelection( 0 );
	PFL2->Add( PFD, 0, wxALL|wxEXPAND, 5 );
	
	PFB = new wxButton( wHookScroll, wxID_ANY, wxT("Use Group"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL2->Add( PFB, 0, wxALL, 5 );
	
	wxString PFRChoices[] = { wxT("Application"), wxT("File") };
	int PFRNChoices = sizeof( PFRChoices ) / sizeof( wxString );
	PFR = new wxRadioBox( wHookScroll, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, PFRNChoices, PFRChoices, 2, wxRA_SPECIFY_COLS );
	PFR->SetSelection( 0 );
	PFL2->Add( PFR, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* PFL3;
	PFL3 = new wxBoxSizer( wxVERTICAL );
	
	PFGetB = new wxButton( wHookScroll, wxID_ANY, wxT("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL3->Add( PFGetB, 0, wxALL, 5 );
	
	PFStartB = new wxButton( wHookScroll, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL3->Add( PFStartB, 0, wxALL, 5 );
	
	PFL2->Add( PFL3, 1, wxEXPAND, 5 );
	
	PFL1->Add( PFL2, 1, wxEXPAND, 5 );
	
	PFL0->Add( PFL1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( PFL0, 0, wxEXPAND|wxRIGHT, 5 );
	
	URL = new wxDirPickerCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bsHookScroll->Add( URL, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* APPL0;
	APPL0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("App") ), wxVERTICAL );
	
	wxFlexGridSizer* APPL1;
	APPL1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	APPL1->AddGrowableCol( 0 );
	APPL1->SetFlexibleDirection( wxBOTH );
	APPL1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	APPD = new wxBitmapComboBox( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	APPL1->Add( APPD, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* APPL2;
	APPL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	APPL2->AddGrowableCol( 1 );
	APPL2->SetFlexibleDirection( wxBOTH );
	APPL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	APPB = new wxButton( wHookScroll, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	APPL2->Add( APPB, 0, wxALL, 5 );
	
	APPT = new wxTextCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	APPL2->Add( APPT, 0, wxALL|wxEXPAND, 5 );
	
	APPS = new wxStaticText( wHookScroll, wxID_ANY, wxT("Check"), wxDefaultPosition, wxDefaultSize, 0 );
	APPS->Wrap( -1 );
	APPL2->Add( APPS, 0, wxALL, 5 );
	
	wxArrayString APPCheckChoices;
	APPCheck = new wxChoice( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, APPCheckChoices, 0 );
	APPCheck->SetSelection( 0 );
	APPCheck->SetToolTip( wxT("Check if App is Active") );
	
	APPL2->Add( APPCheck, 0, wxALL|wxEXPAND, 5 );
	
	APPL1->Add( APPL2, 1, wxEXPAND, 5 );
	
	APPL0->Add( APPL1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( APPL0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* BINL0;
	BINL0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("File") ), wxVERTICAL );
	
	wxFlexGridSizer* BINL1;
	BINL1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	BINL1->AddGrowableCol( 0 );
	BINL1->SetFlexibleDirection( wxBOTH );
	BINL1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	BINProfile = new wxComboBox( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	BINL1->Add( BINProfile, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* BINL2;
	BINL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	BINL2->AddGrowableCol( 0 );
	BINL2->SetFlexibleDirection( wxBOTH );
	BINL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	BINT = new wxTextCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	BINL2->Add( BINT, 0, wxALL|wxEXPAND, 5 );
	
	BINB = new wxButton( wHookScroll, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	BINL2->Add( BINB, 0, wxALL, 5 );
	
	BINL1->Add( BINL2, 1, wxEXPAND, 5 );
	
	BINL0->Add( BINL1, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( BINL0, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* RAML0;
	RAML0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("Memory") ), wxVERTICAL );
	
	wxFlexGridSizer* RAML1;
	RAML1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	RAML1->SetFlexibleDirection( wxBOTH );
	RAML1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	RAML0->Add( RAML1, 0, wxEXPAND, 5 );
	
	RAMG = new wxGrid( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	RAMG->CreateGrid( 0, 4 );
	RAMG->EnableEditing( true );
	RAMG->EnableGridLines( true );
	RAMG->EnableDragGridSize( false );
	RAMG->SetMargins( 0, 0 );
	
	// Columns
	RAMG->SetColSize( 0, 38 );
	RAMG->SetColSize( 1, 36 );
	RAMG->SetColSize( 2, 52 );
	RAMG->SetColSize( 3, 55 );
	RAMG->EnableDragColMove( false );
	RAMG->EnableDragColSize( true );
	RAMG->SetColLabelSize( 30 );
	RAMG->SetColLabelValue( 0, wxT("Name") );
	RAMG->SetColLabelValue( 1, wxT("Fixed") );
	RAMG->SetColLabelValue( 2, wxT("Address") );
	RAMG->SetColLabelValue( 3, wxT("Size") );
	RAMG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	RAMG->EnableDragRowSize( true );
	RAMG->SetRowLabelSize( 16 );
	RAMG->SetRowLabelValue( 0, wxT("00") );
	RAMG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	RAMG->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	RAMG->SetMinSize( wxSize( 100,100 ) );
	
	RAML0->Add( RAMG, 0, wxALL|wxEXPAND, 5 );
	
	bsHookScroll->Add( RAML0, 0, wxEXPAND|wxRIGHT, 5 );
	
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
	
	APPLIST = new wxButton( nbHook, wxID_ANY, wxT("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	bsAppList1->Add( APPLIST, 0, wxALL, 5 );
	
	APPUSE = new wxButton( nbHook, wxID_ANY, wxT("Use Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	bsAppList1->Add( APPUSE, 0, wxALL, 5 );
	
	bsAppList->Add( bsAppList1, 1, wxEXPAND, 5 );
	
	APPG = new wxGrid( nbHook, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	APPG->CreateGrid( 0, 2 );
	APPG->EnableEditing( false );
	APPG->EnableGridLines( false );
	APPG->EnableDragGridSize( false );
	APPG->SetMargins( 0, 0 );
	
	// Columns
	APPG->EnableDragColMove( false );
	APPG->EnableDragColSize( true );
	APPG->SetColLabelSize( 20 );
	APPG->SetColLabelValue( 0, wxT("App") );
	APPG->SetColLabelValue( 1, wxT("Title") );
	APPG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	APPG->EnableDragRowSize( true );
	APPG->SetRowLabelSize( 50 );
	APPG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	APPG->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bsAppList->Add( APPG, 0, wxEXPAND, 5 );
	
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
	EP = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* EL;
	EL = new wxFlexGridSizer( 0, 1, 0, 0 );
	EL->AddGrowableCol( 0 );
	EL->AddGrowableRow( 1 );
	EL->SetFlexibleDirection( wxBOTH );
	EL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* ELHead;
	ELHead = new wxFlexGridSizer( 1, 0, 0, 0 );
	ELHead->SetFlexibleDirection( wxBOTH );
	ELHead->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	EAB = new wxButton( EP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	ELHead->Add( EAB, 0, wxALL, 5 );
	
	EAT = new wxTextCtrl( EP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ELHead->Add( EAT, 0, wxALL, 5 );
	
	EVB = new wxButton( EP, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	ELHead->Add( EVB, 0, wxALL, 5 );
	
	EVT = new wxTextCtrl( EP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	EVT->SetMinSize( wxSize( 100,-1 ) );
	
	ELHead->Add( EVT, 0, wxALL, 5 );
	
	EUS = new wxStaticText( EP, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	EUS->Wrap( -1 );
	ELHead->Add( EUS, 0, wxALL, 5 );
	
	wxArrayString EUDChoices;
	EUD = new wxChoice( EP, wxID_ANY, wxDefaultPosition, wxDefaultSize, EUDChoices, 0 );
	EUD->SetSelection( 0 );
	EUD->SetMinSize( wxSize( 90,-1 ) );
	
	ELHead->Add( EUD, 0, wxALL, 5 );
	
	wxArrayString EMDChoices;
	EMD = new wxChoice( EP, wxID_ANY, wxDefaultPosition, wxDefaultSize, EMDChoices, 0 );
	EMD->SetSelection( 0 );
	EMD->SetMinSize( wxSize( 75,-1 ) );
	
	ELHead->Add( EMD, 0, wxALL, 5 );
	
	EL->Add( ELHead, 1, wxEXPAND, 5 );
	
	EG = new wxGrid( EP, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	EG->CreateGrid( 0, 19 );
	EG->EnableEditing( true );
	EG->EnableGridLines( true );
	EG->EnableDragGridSize( false );
	EG->SetMargins( 0, 0 );
	
	// Columns
	EG->EnableDragColMove( false );
	EG->EnableDragColSize( true );
	EG->SetColLabelSize( 30 );
	EG->SetColLabelValue( 0, wxT("Address") );
	EG->SetColLabelValue( 1, wxT("0") );
	EG->SetColLabelValue( 2, wxT("1") );
	EG->SetColLabelValue( 3, wxT("2") );
	EG->SetColLabelValue( 4, wxT("3") );
	EG->SetColLabelValue( 5, wxT("4") );
	EG->SetColLabelValue( 6, wxT("5") );
	EG->SetColLabelValue( 7, wxT("6") );
	EG->SetColLabelValue( 8, wxT("7") );
	EG->SetColLabelValue( 9, wxT("8") );
	EG->SetColLabelValue( 10, wxT("9") );
	EG->SetColLabelValue( 11, wxT("A") );
	EG->SetColLabelValue( 12, wxT("B") );
	EG->SetColLabelValue( 13, wxT("C") );
	EG->SetColLabelValue( 14, wxT("D") );
	EG->SetColLabelValue( 15, wxT("E") );
	EG->SetColLabelValue( 16, wxT("F") );
	EG->SetColLabelValue( 17, wxT("Ascii") );
	EG->SetColLabelValue( 18, wxT("UTF8") );
	EG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	EG->EnableDragRowSize( true );
	EG->SetRowLabelSize( 1 );
	EG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	EG->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	EL->Add( EG, 0, wxEXPAND, 5 );
	
	EP->SetSizer( EL );
	EP->Layout();
	EL->Fit( EP );
	NB->AddPage( EP, wxT("Editor"), true );
	DBP = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* lDB;
	lDB = new wxFlexGridSizer( 0, 2, 0, 0 );
	lDB->AddGrowableCol( 0 );
	lDB->AddGrowableRow( 0 );
	lDB->SetFlexibleDirection( wxBOTH );
	lDB->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* DBMain;
	DBMain = new wxFlexGridSizer( 0, 1, 0, 0 );
	DBMain->AddGrowableCol( 0 );
	DBMain->AddGrowableRow( 1 );
	DBMain->SetFlexibleDirection( wxBOTH );
	DBMain->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* DBHead;
	DBHead = new wxFlexGridSizer( 0, 4, 0, 0 );
	DBHead->AddGrowableCol( 1 );
	DBHead->SetFlexibleDirection( wxBOTH );
	DBHead->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBRS = new wxStaticText( DBP, wxID_ANY, wxT("Region"), wxDefaultPosition, wxDefaultSize, 0 );
	DBRS->Wrap( -1 );
	DBHead->Add( DBRS, 0, wxALL|wxEXPAND, 5 );
	
	wxString DBRMChoices[] = { wxT("All"), wxT("UK - United Kingdom"), wxT("US - America"), wxT("JP - Japan"), wxT("DE - Germany") };
	int DBRMNChoices = sizeof( DBRMChoices ) / sizeof( wxString );
	DBRM = new wxChoice( DBP, wxID_ANY, wxDefaultPosition, wxDefaultSize, DBRMNChoices, DBRMChoices, 0 );
	DBRM->SetSelection( 0 );
	DBRM->SetMinSize( wxSize( 75,-1 ) );
	
	DBHead->Add( DBRM, 0, wxALL|wxEXPAND, 5 );
	
	DBAddB = new wxButton( DBP, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	DBHead->Add( DBAddB, 0, wxALL, 5 );
	
	DBDelB = new wxButton( DBP, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	DBHead->Add( DBDelB, 0, wxALL, 5 );
	
	DBMain->Add( DBHead, 1, wxEXPAND, 5 );
	
	DB = new wxTreeCtrl( DBP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_EDIT_LABELS|wxTR_FULL_ROW_HIGHLIGHT|wxTR_HIDE_ROOT|wxTR_NO_BUTTONS|wxTR_NO_LINES|wxTR_SINGLE );
	DBMain->Add( DB, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* DBFoot;
	DBFoot = new wxFlexGridSizer( 0, 2, 0, 0 );
	DBFoot->SetFlexibleDirection( wxBOTH );
	DBFoot->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBLoadB = new wxButton( DBP, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	DBFoot->Add( DBLoadB, 0, wxALL, 5 );
	
	DBSaveB = new wxButton( DBP, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	DBFoot->Add( DBSaveB, 0, wxALL, 5 );
	
	DBMain->Add( DBFoot, 1, wxEXPAND, 5 );
	
	lDB->Add( DBMain, 0, wxEXPAND, 5 );
	
	DBInfoP = new wxPanel( DBP, wxID_ANY, wxDefaultPosition, wxSize( 300,-1 ), wxTAB_TRAVERSAL );
	DBInfoP->SetMinSize( wxSize( 300,-1 ) );
	DBInfoP->SetMaxSize( wxSize( 300,-1 ) );
	
	wxFlexGridSizer* DBInfoL;
	DBInfoL = new wxFlexGridSizer( 0, 1, 0, 0 );
	DBInfoL->AddGrowableCol( 0 );
	DBInfoL->AddGrowableRow( 4 );
	DBInfoL->SetFlexibleDirection( wxBOTH );
	DBInfoL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBInfoL->SetMinSize( wxSize( 300,-1 ) ); 
	wxFlexGridSizer* DBRL;
	DBRL = new wxFlexGridSizer( 0, 8, 0, 0 );
	DBRL->SetFlexibleDirection( wxBOTH );
	DBRL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBRuk = new wxCheckBox( DBInfoP, wxID_ANY, wxT("UK"), wxDefaultPosition, wxDefaultSize, 0 );
	DBRL->Add( DBRuk, 0, wxALL, 5 );
	
	DBRus = new wxCheckBox( DBInfoP, wxID_ANY, wxT("US"), wxDefaultPosition, wxDefaultSize, 0 );
	DBRL->Add( DBRus, 0, wxALL, 5 );
	
	DBRjp = new wxCheckBox( DBInfoP, wxID_ANY, wxT("JP"), wxDefaultPosition, wxDefaultSize, 0 );
	DBRL->Add( DBRjp, 0, wxALL, 5 );
	
	DBRde = new wxCheckBox( DBInfoP, wxID_ANY, wxT("DE"), wxDefaultPosition, wxDefaultSize, 0 );
	DBRL->Add( DBRde, 0, wxALL, 5 );
	
	DBInfoL->Add( DBRL, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* DBSIDL;
	DBSIDL = new wxFlexGridSizer( 0, 2, 0, 0 );
	DBSIDL->AddGrowableCol( 1 );
	DBSIDL->SetFlexibleDirection( wxBOTH );
	DBSIDL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBSIDS = new wxStaticText( DBInfoP, wxID_ANY, wxT("Serial ID"), wxDefaultPosition, wxDefaultSize, 0 );
	DBSIDS->Wrap( -1 );
	DBSIDL->Add( DBSIDS, 0, wxALL|wxEXPAND, 5 );
	
	DBSIDT = new wxTextCtrl( DBInfoP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	DBSIDL->Add( DBSIDT, 0, wxALL|wxEXPAND, 5 );
	
	DBInfoL->Add( DBSIDL, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* DBAFL;
	DBAFL = new wxFlexGridSizer( 0, 2, 0, 0 );
	DBAFL->AddGrowableCol( 1 );
	DBAFL->SetFlexibleDirection( wxBOTH );
	DBAFL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBAFS = new wxStaticText( DBInfoP, wxID_ANY, wxT("App / File ID"), wxDefaultPosition, wxDefaultSize, 0 );
	DBAFS->Wrap( -1 );
	DBAFL->Add( DBAFS, 0, wxALL, 5 );
	
	DBAFT = new wxTextCtrl( DBInfoP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	DBAFL->Add( DBAFT, 0, wxALL|wxEXPAND, 5 );
	
	DBInfoL->Add( DBAFL, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* DBFileL;
	DBFileL = new wxFlexGridSizer( 0, 2, 0, 0 );
	DBFileL->AddGrowableCol( 1 );
	DBFileL->SetFlexibleDirection( wxBOTH );
	DBFileL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	DBFileS = new wxStaticText( DBInfoP, wxID_ANY, wxT("Filename"), wxDefaultPosition, wxDefaultSize, 0 );
	DBFileS->Wrap( -1 );
	DBFileL->Add( DBFileS, 0, wxALL, 5 );
	
	DBFileT = new wxTextCtrl( DBInfoP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	DBFileL->Add( DBFileT, 0, wxALL|wxEXPAND, 5 );
	
	DBInfoL->Add( DBFileL, 1, wxEXPAND, 5 );
	
	DBNotes = new wxTextCtrl( DBInfoP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	DBInfoL->Add( DBNotes, 0, wxALL|wxEXPAND, 5 );
	
	DBInfoP->SetSizer( DBInfoL );
	DBInfoP->Layout();
	lDB->Add( DBInfoP, 0, wxALL|wxEXPAND, 5 );
	
	DBP->SetSizer( lDB );
	DBP->Layout();
	lDB->Fit( DBP );
	NB->AddPage( DBP, wxT("Database"), false );
	HTP = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* HTL;
	HTL = new wxFlexGridSizer( 0, 2, 0, 0 );
	HTL->AddGrowableCol( 0 );
	HTL->AddGrowableRow( 0 );
	HTL->SetFlexibleDirection( wxBOTH );
	HTL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* HTTL;
	HTTL = new wxFlexGridSizer( 0, 1, 0, 0 );
	HTTL->AddGrowableCol( 0 );
	HTTL->AddGrowableRow( 1 );
	HTTL->SetFlexibleDirection( wxBOTH );
	HTTL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* HTHead;
	HTHead = new wxFlexGridSizer( 0, 4, 0, 0 );
	HTHead->AddGrowableCol( 0 );
	HTHead->AddGrowableCol( 1 );
	HTHead->AddGrowableCol( 2 );
	HTHead->AddGrowableCol( 3 );
	HTHead->SetFlexibleDirection( wxBOTH );
	HTHead->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxString HTAddDChoices[] = { wxT("Start"), wxT("Before"), wxT("After"), wxT("End") };
	int HTAddDNChoices = sizeof( HTAddDChoices ) / sizeof( wxString );
	HTAddD = new wxChoice( HTP, wxID_ANY, wxDefaultPosition, wxDefaultSize, HTAddDNChoices, HTAddDChoices, 0 );
	HTAddD->SetSelection( 3 );
	HTAddD->SetMinSize( wxSize( 50,-1 ) );
	
	HTHead->Add( HTAddD, 0, wxALL|wxEXPAND, 5 );
	
	HTAddC = new wxCheckBox( HTP, wxID_ANY, wxT("Chilld"), wxDefaultPosition, wxDefaultSize, 0 );
	HTHead->Add( HTAddC, 0, wxALL|wxEXPAND, 5 );
	
	HTAddB = new wxButton( HTP, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	HTHead->Add( HTAddB, 0, wxALL|wxEXPAND, 5 );
	
	HTDelB = new wxButton( HTP, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	HTHead->Add( HTDelB, 0, wxALL|wxEXPAND, 5 );
	
	HTTL->Add( HTHead, 1, wxEXPAND, 5 );
	
	HT = new wxTreeCtrl( HTP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE|wxTR_EDIT_LABELS );
	HT->SetToolTip( wxT("When a Hack / Node is selected the following actions can be peformed with the CTRL key held down:\nAdd = Add Hack / Node to List (List box decides position)\nMinus = Remove Hack / Node\nArrow = Move Hack / Node in that direction") );
	
	HTTL->Add( HT, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* HTFoot;
	HTFoot = new wxFlexGridSizer( 0, 4, 0, 0 );
	HTFoot->SetFlexibleDirection( wxBOTH );
	HTFoot->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	bHackMove = new wxButton( HTP, wxID_ANY, wxT("Move"), wxDefaultPosition, wxDefaultSize, 0 );
	HTFoot->Add( bHackMove, 0, wxALL, 5 );
	
	wxString cbHackMoveChoices[] = { wxT("Up"), wxT("Down"), wxT("Left"), wxT("Right") };
	int cbHackMoveNChoices = sizeof( cbHackMoveChoices ) / sizeof( wxString );
	cbHackMove = new wxChoice( HTP, wxID_ANY, wxDefaultPosition, wxDefaultSize, cbHackMoveNChoices, cbHackMoveChoices, 0 );
	cbHackMove->SetSelection( 0 );
	cbHackMove->SetMinSize( wxSize( 45,-1 ) );
	
	HTFoot->Add( cbHackMove, 1, wxALL, 5 );
	
	bHTLoad = new wxButton( HTP, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	HTFoot->Add( bHTLoad, 0, wxALL, 5 );
	
	bHTSave = new wxButton( HTP, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	HTFoot->Add( bHTSave, 0, wxALL, 5 );
	
	HTTL->Add( HTFoot, 1, wxEXPAND, 5 );
	
	HTL->Add( HTTL, 1, wxEXPAND, 5 );
	
	HCP = new wxPanel( HTP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* HCL;
	HCL = new wxFlexGridSizer( 0, 1, 0, 0 );
	HCL->AddGrowableCol( 0 );
	HCL->AddGrowableRow( 2 );
	HCL->SetFlexibleDirection( wxBOTH );
	HCL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCL->SetMinSize( wxSize( 300,-1 ) ); 
	wxFlexGridSizer* HCHead;
	HCHead = new wxFlexGridSizer( 0, 3, 0, 0 );
	HCHead->AddGrowableCol( 1 );
	HCHead->SetFlexibleDirection( wxBOTH );
	HCHead->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCCS = new wxStaticText( HCP, wxID_ANY, wxT("Code Type"), wxDefaultPosition, wxDefaultSize, 0 );
	HCCS->Wrap( -1 );
	HCHead->Add( HCCS, 0, wxALL|wxEXPAND, 5 );
	
	wxString HCCDChoices[] = { wxT("Write"), wxT("Copy"), wxT("Test"), wxT("Increment"), wxT("Decrement"), wxT("List Write") };
	int HCCDNChoices = sizeof( HCCDChoices ) / sizeof( wxString );
	HCCD = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, HCCDNChoices, HCCDChoices, 0 );
	HCCD->SetSelection( 0 );
	HCHead->Add( HCCD, 0, wxALL|wxEXPAND, 5 );
	
	HCRC = new wxCheckBox( HCP, wxID_ANY, wxT("Repeats"), wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( HCRC, 1, wxALL|wxEXPAND, 5 );
	
	HCRAMS = new wxStaticText( HCP, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	HCRAMS->Wrap( -1 );
	HCHead->Add( HCRAMS, 0, wxALL|wxEXPAND, 5 );
	
	wxString HCRAMDChoices[] = { wxT("Main") };
	int HCRAMDNChoices = sizeof( HCRAMDChoices ) / sizeof( wxString );
	HCRAMD = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, HCRAMDNChoices, HCRAMDChoices, 0 );
	HCRAMD->SetSelection( 0 );
	HCHead->Add( HCRAMD, 0, wxALL|wxEXPAND, 5 );
	
	HCRN = new wxSpinCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	HCRN->SetToolTip( wxT("Repeats on how many Addresses") );
	HCRN->SetMinSize( wxSize( 50,-1 ) );
	
	HCHead->Add( HCRN, 1, wxALL|wxEXPAND, 5 );
	
	sHackA = new wxStaticText( HCP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackA->Wrap( -1 );
	HCHead->Add( sHackA, 0, wxALL|wxEXPAND, 5 );
	
	tHackA = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( tHackA, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackAChoices[] = { wxT("Fixed"), wxT("Pointer") };
	int mHackANChoices = sizeof( mHackAChoices ) / sizeof( wxString );
	mHackA = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackANChoices, mHackAChoices, 0 );
	mHackA->SetSelection( 0 );
	HCHead->Add( mHackA, 0, wxALL|wxEXPAND, 5 );
	
	sHackV = new wxStaticText( HCP, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackV->Wrap( -1 );
	HCHead->Add( sHackV, 0, wxALL|wxEXPAND, 5 );
	
	tHackV = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( tHackV, 0, wxALL|wxEXPAND, 5 );
	
	wxString mHackVChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int mHackVNChoices = sizeof( mHackVChoices ) / sizeof( wxString );
	mHackV = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, mHackVNChoices, mHackVChoices, 0 );
	mHackV->SetSelection( 0 );
	HCHead->Add( mHackV, 0, wxALL|wxEXPAND, 5 );
	
	HCL->Add( HCHead, 1, wxEXPAND, 5 );
	
	wxBoxSizer* HCMain;
	HCMain = new wxBoxSizer( wxVERTICAL );
	
	HCTW = new wxPanel( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HCTW->Hide();
	
	wxFlexGridSizer* HCTL;
	HCTL = new wxFlexGridSizer( 0, 4, 0, 0 );
	HCTL->AddGrowableCol( 1 );
	HCTL->AddGrowableCol( 3 );
	HCTL->SetFlexibleDirection( wxBOTH );
	HCTL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCTS1 = new wxStaticText( HCTW, wxID_ANY, wxT("If"), wxDefaultPosition, wxDefaultSize, 0 );
	HCTS1->Wrap( -1 );
	HCTL->Add( HCTS1, 0, wxALL, 5 );
	
	wxString HCTD1Choices[] = { wxT("Is Value"), wxT("Is Not Value") };
	int HCTD1NChoices = sizeof( HCTD1Choices ) / sizeof( wxString );
	HCTD1 = new wxChoice( HCTW, wxID_ANY, wxDefaultPosition, wxDefaultSize, HCTD1NChoices, HCTD1Choices, 0 );
	HCTD1->SetSelection( 0 );
	HCTL->Add( HCTD1, 0, wxALL|wxEXPAND, 5 );
	
	HCTS2 = new wxStaticText( HCTW, wxID_ANY, wxT("do"), wxDefaultPosition, wxDefaultSize, 0 );
	HCTS2->Wrap( -1 );
	HCTL->Add( HCTS2, 0, wxALL, 5 );
	
	wxString HCTD2Choices[] = { wxT("1 Line"), wxT("2 Lines"), wxT("All Lines") };
	int HCTD2NChoices = sizeof( HCTD2Choices ) / sizeof( wxString );
	HCTD2 = new wxChoice( HCTW, wxID_ANY, wxDefaultPosition, wxDefaultSize, HCTD2NChoices, HCTD2Choices, 0 );
	HCTD2->SetSelection( 0 );
	HCTL->Add( HCTD2, 0, wxALL|wxEXPAND, 5 );
	
	HCTW->SetSizer( HCTL );
	HCTW->Layout();
	HCTL->Fit( HCTW );
	HCMain->Add( HCTW, 1, wxEXPAND, 5 );
	
	HCAW = new wxPanel( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HCAW->Hide();
	
	wxFlexGridSizer* HCAL;
	HCAL = new wxFlexGridSizer( 0, 3, 0, 0 );
	HCAL->AddGrowableCol( 1 );
	HCAL->SetFlexibleDirection( wxBOTH );
	HCAL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCAS1 = new wxStaticText( HCAW, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	HCAS1->Wrap( -1 );
	HCAL->Add( HCAS1, 0, wxALL|wxEXPAND, 5 );
	
	HCAT = new wxTextCtrl( HCAW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCAL->Add( HCAT, 0, wxALL|wxEXPAND, 5 );
	
	HCAS2 = new wxStaticText( HCAW, wxID_ANY, wxT("x 1 (Address)"), wxDefaultPosition, wxDefaultSize, 0 );
	HCAS2->Wrap( -1 );
	HCAL->Add( HCAS2, 0, wxALL|wxEXPAND, 5 );
	
	HCAW->SetSizer( HCAL );
	HCAW->Layout();
	HCAL->Fit( HCAW );
	HCMain->Add( HCAW, 1, wxEXPAND, 5 );
	
	HCVW = new wxPanel( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	HCVW->Hide();
	
	wxFlexGridSizer* HCVL;
	HCVL = new wxFlexGridSizer( 0, 3, 0, 0 );
	HCVL->AddGrowableCol( 1 );
	HCVL->SetFlexibleDirection( wxBOTH );
	HCVL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCVS1 = new wxStaticText( HCVW, wxID_ANY, wxT("Add / Minus"), wxDefaultPosition, wxDefaultSize, 0 );
	HCVS1->Wrap( -1 );
	HCVL->Add( HCVS1, 0, wxALL|wxEXPAND, 5 );
	
	HCVT = new wxTextCtrl( HCVW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCVL->Add( HCVT, 0, wxALL|wxEXPAND, 5 );
	
	HCVS2 = new wxStaticText( HCVW, wxID_ANY, wxT("(Value)"), wxDefaultPosition, wxDefaultSize, 0 );
	HCVS2->Wrap( -1 );
	HCVL->Add( HCVS2, 0, wxALL, 5 );
	
	HCVW->SetSizer( HCVL );
	HCVW->Layout();
	HCVL->Fit( HCVW );
	HCMain->Add( HCVW, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* HCAction;
	HCAction = new wxFlexGridSizer( 0, 4, 0, 0 );
	HCAction->SetFlexibleDirection( wxBOTH );
	HCAction->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	HCUseC = new wxCheckBox( HCP, wxID_ANY, wxT("Use"), wxDefaultPosition, wxDefaultSize, 0 );
	HCAction->Add( HCUseC, 0, wxALL|wxEXPAND, 5 );
	
	HCAddB = new wxButton( HCP, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	HCAction->Add( HCAddB, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	HCLoadB = new wxButton( HCP, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	HCAction->Add( HCLoadB, 0, wxALL|wxEXPAND, 5 );
	
	HCDelB = new wxButton( HCP, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	HCAction->Add( HCDelB, 0, wxALL, 5 );
	
	HCMain->Add( HCAction, 1, wxEXPAND, 5 );
	
	HCL->Add( HCMain, 1, wxEXPAND, 5 );
	
	HCG = new wxGrid( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	
	// Grid
	HCG->CreateGrid( 0, 3 );
	HCG->EnableEditing( true );
	HCG->EnableGridLines( true );
	HCG->EnableDragGridSize( false );
	HCG->SetMargins( 0, 0 );
	
	// Columns
	HCG->SetColSize( 0, 100 );
	HCG->SetColSize( 1, 100 );
	HCG->SetColSize( 2, 50 );
	HCG->EnableDragColMove( false );
	HCG->EnableDragColSize( true );
	HCG->SetColLabelSize( 15 );
	HCG->SetColLabelValue( 0, wxT("Code / Data") );
	HCG->SetColLabelValue( 1, wxT("Data") );
	HCG->SetColLabelValue( 2, wxT("Lines") );
	HCG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	HCG->EnableDragRowSize( true );
	HCG->SetRowLabelSize( 20 );
	HCG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	HCG->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	HCL->Add( HCG, 0, wxEXPAND, 5 );
	
	HCP->SetSizer( HCL );
	HCP->Layout();
	HCL->Fit( HCP );
	HTL->Add( HCP, 1, wxEXPAND | wxALL, 5 );
	
	HTP->SetSizer( HTL );
	HTP->Layout();
	HTL->Fit( HTP );
	NB->AddPage( HTP, wxT("Hack"), false );
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
	PFD->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::PFOnChange ), NULL, this );
	PFD->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::PFDOnBlur ), NULL, this );
	PFB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFOnClick ), NULL, this );
	PFR->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( HEXFRM::PFOnSwitch ), NULL, this );
	PFGetB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFGetOnClick ), NULL, this );
	PFStartB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFStartOnClick ), NULL, this );
	APPD->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::APPDOnChange ), NULL, this );
	APPD->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	APPD->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::APPDOnEdit ), NULL, this );
	APPD->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::APPDOnEnter ), NULL, this );
	APPB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPBOnClick ), NULL, this );
	APPCheck->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	BINProfile->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	BINProfile->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	BINProfile->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	APPLIST->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	EAB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EAOnClick ), NULL, this );
	EVB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EVOnClick ), NULL, this );
	EUD->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::EUOnChange ), NULL, this );
	EG->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::EGOnChange ), NULL, this );
	DBAddB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBAddBClick ), NULL, this );
	DBDelB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBDelBOnClick ), NULL, this );
	DB->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HEXFRM::DBSelectC ), NULL, this );
	DBLoadB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBLoadBOnClick ), NULL, this );
	DBSaveB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBSaveBOnClick ), NULL, this );
	DBFileT->Connect( wxEVT_CHAR, wxKeyEventHandler( HEXFRM::DBFileTOnKeyD ), NULL, this );
	HTAddB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAddHackOnClick ), NULL, this );
	HTDelB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bDelHackOnClick ), NULL, this );
	HT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::HTOnKeyDown ), NULL, this );
	HT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::HTOnKeyUp ), NULL, this );
	HT->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HEXFRM::HTOnChangeSelT ), NULL, this );
	bHTLoad->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHTLoadOnClick ), NULL, this );
	bHTSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHTSaveOnClick ), NULL, this );
	HCCD->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::HCCDOnChange ), NULL, this );
	HCRC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCRCOnChange ), NULL, this );
	HCUseC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCUOnChange ), NULL, this );
	HCAddB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCAddBOnClick ), NULL, this );
	HCDelB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCDelBOnClick ), NULL, this );
	HCG->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::HCChangeD ), NULL, this );
	HCG->Connect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( HEXFRM::HCChangeR ), NULL, this );
	HCG->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::HCChangeC ), NULL, this );
}

HEXFRM::~HEXFRM()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( HEXFRM::HEXFORMCLOSE ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( HEXFRM::HEXFORMIDLE ) );
	PFD->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::PFOnChange ), NULL, this );
	PFD->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::PFDOnBlur ), NULL, this );
	PFB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFOnClick ), NULL, this );
	PFR->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( HEXFRM::PFOnSwitch ), NULL, this );
	PFGetB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFGetOnClick ), NULL, this );
	PFStartB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFStartOnClick ), NULL, this );
	APPD->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::APPDOnChange ), NULL, this );
	APPD->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appOnBlur ), NULL, this );
	APPD->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::APPDOnEdit ), NULL, this );
	APPD->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::APPDOnEnter ), NULL, this );
	APPB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPBOnClick ), NULL, this );
	APPCheck->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	BINProfile->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	BINProfile->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	BINProfile->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	APPLIST->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	EAB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EAOnClick ), NULL, this );
	EVB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EVOnClick ), NULL, this );
	EUD->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::EUOnChange ), NULL, this );
	EG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::EGOnChange ), NULL, this );
	DBAddB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBAddBClick ), NULL, this );
	DBDelB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBDelBOnClick ), NULL, this );
	DB->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HEXFRM::DBSelectC ), NULL, this );
	DBLoadB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBLoadBOnClick ), NULL, this );
	DBSaveB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::DBSaveBOnClick ), NULL, this );
	DBFileT->Disconnect( wxEVT_CHAR, wxKeyEventHandler( HEXFRM::DBFileTOnKeyD ), NULL, this );
	HTAddB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bAddHackOnClick ), NULL, this );
	HTDelB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bDelHackOnClick ), NULL, this );
	HT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::HTOnKeyDown ), NULL, this );
	HT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::HTOnKeyUp ), NULL, this );
	HT->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( HEXFRM::HTOnChangeSelT ), NULL, this );
	bHTLoad->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHTLoadOnClick ), NULL, this );
	bHTSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bHTSaveOnClick ), NULL, this );
	HCCD->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::HCCDOnChange ), NULL, this );
	HCRC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCRCOnChange ), NULL, this );
	HCUseC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCUOnChange ), NULL, this );
	HCAddB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCAddBOnClick ), NULL, this );
	HCDelB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCDelBOnClick ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::HCChangeD ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( HEXFRM::HCChangeR ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::HCChangeC ), NULL, this );
	
}
