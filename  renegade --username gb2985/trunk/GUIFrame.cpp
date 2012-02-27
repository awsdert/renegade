///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  8 2010)
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
	
	wxFlexGridSizer* PFL2;
	PFL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	PFL2->AddGrowableCol( 0 );
	PFL2->SetFlexibleDirection( wxBOTH );
	PFL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxArrayString group_DChoices;
	group_D = new wxChoice( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, group_DChoices, 0 );
	group_D->SetSelection( 0 );
	PFL2->Add( group_D, 0, wxALL|wxEXPAND, 5 );
	
	loadGroup_B = new wxButton( wHookScroll, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL2->Add( loadGroup_B, 0, wxALL, 5 );
	
	wxString hookType_DChoices[] = { wxT("Application"), wxT("File") };
	int hookType_DNChoices = sizeof( hookType_DChoices ) / sizeof( wxString );
	hookType_D = new wxChoice( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, hookType_DNChoices, hookType_DChoices, 0 );
	hookType_D->SetSelection( 0 );
	hookType_D->Enable( false );
	
	PFL2->Add( hookType_D, 0, wxALL|wxEXPAND, 5 );
	
	saveGroup_B = new wxButton( wHookScroll, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL2->Add( saveGroup_B, 0, wxALL, 5 );
	
	wxBoxSizer* PFL3;
	PFL3 = new wxBoxSizer( wxHORIZONTAL );
	
	PFGetB = new wxButton( wHookScroll, wxID_ANY, wxT("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL3->Add( PFGetB, 0, wxALL, 5 );
	
	PFStartB = new wxButton( wHookScroll, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	PFL3->Add( PFStartB, 0, wxALL, 5 );
	
	PFL2->Add( PFL3, 1, wxEXPAND, 5 );
	
	PFL0->Add( PFL2, 1, wxEXPAND, 5 );
	
	bsHookScroll->Add( PFL0, 0, wxEXPAND|wxRIGHT, 5 );
	
	URL = new wxDirPickerCtrl( wHookScroll, wxID_ANY, wxEmptyString, wxT("Select a folder"), wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
	bsHookScroll->Add( URL, 0, wxALL|wxEXPAND, 5 );
	
	hookApp_P = new wxPanel( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* APPL0;
	APPL0 = new wxStaticBoxSizer( new wxStaticBox( hookApp_P, wxID_ANY, wxT("App") ), wxVERTICAL );
	
	appTitle_D = new wxComboBox( hookApp_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	APPL0->Add( appTitle_D, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* APPL2;
	APPL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	APPL2->AddGrowableCol( 1 );
	APPL2->SetFlexibleDirection( wxBOTH );
	APPL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	appUpdate_B = new wxButton( hookApp_P, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	APPL2->Add( appUpdate_B, 0, wxALL, 5 );
	
	appName_TXT = new wxTextCtrl( hookApp_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	APPL2->Add( appName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	APPS = new wxStaticText( hookApp_P, wxID_ANY, wxT("Check"), wxDefaultPosition, wxDefaultSize, 0 );
	APPS->Wrap( -1 );
	APPL2->Add( APPS, 0, wxALL, 5 );
	
	wxArrayString APPCheckChoices;
	APPCheck = new wxChoice( hookApp_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, APPCheckChoices, 0 );
	APPCheck->SetSelection( 0 );
	APPCheck->SetToolTip( wxT("Check if App is Active") );
	
	APPL2->Add( APPCheck, 0, wxALL|wxEXPAND, 5 );
	
	APPL0->Add( APPL2, 1, wxEXPAND, 5 );
	
	hookApp_P->SetSizer( APPL0 );
	hookApp_P->Layout();
	APPL0->Fit( hookApp_P );
	bsHookScroll->Add( hookApp_P, 0, wxEXPAND|wxRIGHT, 5 );
	
	hookFile_P = new wxPanel( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	hookFile_P->Hide();
	
	wxStaticBoxSizer* BINL0;
	BINL0 = new wxStaticBoxSizer( new wxStaticBox( hookFile_P, wxID_ANY, wxT("File") ), wxVERTICAL );
	
	wxFlexGridSizer* BINL1;
	BINL1 = new wxFlexGridSizer( 0, 1, 0, 0 );
	BINL1->AddGrowableCol( 0 );
	BINL1->SetFlexibleDirection( wxBOTH );
	BINL1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fileTitle_D = new wxComboBox( hookFile_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	BINL1->Add( fileTitle_D, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* BINL2;
	BINL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	BINL2->AddGrowableCol( 0 );
	BINL2->SetFlexibleDirection( wxBOTH );
	BINL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	fileName_TXT = new wxTextCtrl( hookFile_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	BINL2->Add( fileName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	BINB = new wxButton( hookFile_P, wxID_ANY, wxT("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	BINL2->Add( BINB, 0, wxALL, 5 );
	
	BINL1->Add( BINL2, 1, wxEXPAND, 5 );
	
	BINL0->Add( BINL1, 1, wxEXPAND, 5 );
	
	hookFile_P->SetSizer( BINL0 );
	hookFile_P->Layout();
	BINL0->Fit( hookFile_P );
	bsHookScroll->Add( hookFile_P, 0, wxEXPAND|wxRIGHT, 5 );
	
	wxStaticBoxSizer* RAML0;
	RAML0 = new wxStaticBoxSizer( new wxStaticBox( wHookScroll, wxID_ANY, wxT("Memory") ), wxVERTICAL );
	
	addRAM_B = new wxButton( wHookScroll, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	RAML0->Add( addRAM_B, 0, wxALL, 5 );
	
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
	NB->AddPage( nbHook, wxT("Hook"), true );
	QP = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* QL0;
	QL0 = new wxFlexGridSizer( 0, 1, 0, 0 );
	QL0->AddGrowableCol( 0 );
	QL0->AddGrowableRow( 2 );
	QL0->SetFlexibleDirection( wxBOTH );
	QL0->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* QL1;
	QL1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	QL1->AddGrowableCol( 1 );
	QL1->SetFlexibleDirection( wxBOTH );
	QL1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* QL2;
	QL2 = new wxFlexGridSizer( 0, 4, 0, 0 );
	QL2->SetFlexibleDirection( wxBOTH );
	QL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	QSizeS = new wxStaticText( QP, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	QSizeS->Wrap( -1 );
	QL2->Add( QSizeS, 0, wxALL, 5 );
	
	wxString searchSize_DChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int searchSize_DNChoices = sizeof( searchSize_DChoices ) / sizeof( wxString );
	searchSize_D = new wxChoice( QP, wxID_ANY, wxDefaultPosition, wxDefaultSize, searchSize_DNChoices, searchSize_DChoices, 0 );
	searchSize_D->SetSelection( 0 );
	QL2->Add( searchSize_D, 0, wxALL, 5 );
	
	QCompareS = new wxStaticText( QP, wxID_ANY, wxT("Compare To"), wxDefaultPosition, wxDefaultSize, 0 );
	QCompareS->Wrap( -1 );
	QL2->Add( QCompareS, 0, wxALL, 5 );
	
	wxString QCompareDChoices[] = { wxT("Dump") };
	int QCompareDNChoices = sizeof( QCompareDChoices ) / sizeof( wxString );
	QCompareD = new wxChoice( QP, wxID_ANY, wxDefaultPosition, wxDefaultSize, QCompareDNChoices, QCompareDChoices, 0 );
	QCompareD->SetSelection( 0 );
	QL2->Add( QCompareD, 0, wxALL, 5 );
	
	QL1->Add( QL2, 1, wxEXPAND, 5 );
	
	wxBoxSizer* QActionL;
	QActionL = new wxBoxSizer( wxHORIZONTAL );
	
	bQActD = new wxButton( QP, wxID_ANY, wxT("Dump"), wxDefaultPosition, wxDefaultSize, 0 );
	QActionL->Add( bQActD, 0, wxALL, 5 );
	
	bQActS = new wxButton( QP, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	QActionL->Add( bQActS, 0, wxALL, 5 );
	
	bQActUS = new wxButton( QP, wxID_ANY, wxT("Undo Search"), wxDefaultPosition, wxDefaultSize, 0 );
	QActionL->Add( bQActUS, 0, wxALL, 5 );
	
	pbQAct = new wxGauge( QP, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	QActionL->Add( pbQAct, 1, wxALL, 5 );
	
	QL1->Add( QActionL, 1, wxEXPAND, 5 );
	
	wxStaticBoxSizer* QTypeL0;
	QTypeL0 = new wxStaticBoxSizer( new wxStaticBox( QP, wxID_ANY, wxT("Search Type") ), wxVERTICAL );
	
	wxBoxSizer* QTypeL1;
	QTypeL1 = new wxBoxSizer( wxHORIZONTAL );
	
	bQActLT = new wxButton( QP, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	bQActLT->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActLT, 0, wxALL, 5 );
	
	bQActLTE = new wxButton( QP, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	bQActLTE->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActLTE, 0, wxALL, 5 );
	
	bQActE = new wxButton( QP, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	bQActE->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActE, 0, wxALL, 5 );
	
	bQActNE = new wxButton( QP, wxID_ANY, wxT("!="), wxDefaultPosition, wxDefaultSize, 0 );
	bQActNE->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActNE, 0, wxALL, 5 );
	
	bQActGTE = new wxButton( QP, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	bQActGTE->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActGTE, 0, wxALL, 5 );
	
	bQActGT = new wxButton( QP, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	bQActGT->SetMinSize( wxSize( 25,-1 ) );
	
	QTypeL1->Add( bQActGT, 0, wxALL, 5 );
	
	QTypeL0->Add( QTypeL1, 1, wxEXPAND, 5 );
	
	wxString useTest_DChoices[] = { wxT("Known Value"), wxT("Known Value with *"), wxT("Greater than Value 1"), wxT("Greater than by Value 1"), wxT("Greater than by a maximum of Value 1") };
	int useTest_DNChoices = sizeof( useTest_DChoices ) / sizeof( wxString );
	useTest_D = new wxChoice( QP, wxID_ANY, wxDefaultPosition, wxDefaultSize, useTest_DNChoices, useTest_DChoices, 0 );
	useTest_D->SetSelection( 0 );
	QTypeL0->Add( useTest_D, 0, wxALL, 5 );
	
	QL1->Add( QTypeL0, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* fgSizer381;
	fgSizer381 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer381->SetFlexibleDirection( wxBOTH );
	fgSizer381->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	isSigned_CB = new wxCheckBox( QP, wxID_ANY, wxT("Signed"), wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer381->Add( isSigned_CB, 0, wxALL, 5 );
	
	result_S = new wxStaticText( QP, wxID_ANY, wxT("Results: 0"), wxDefaultPosition, wxDefaultSize, 0 );
	result_S->Wrap( -1 );
	fgSizer381->Add( result_S, 0, wxALL, 5 );
	
	bSizer25->Add( fgSizer381, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer7;
	sbSizer7 = new wxStaticBoxSizer( new wxStaticBox( QP, wxID_ANY, wxT("Value") ), wxHORIZONTAL );
	
	value1_S = new wxStaticText( QP, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	value1_S->Wrap( -1 );
	sbSizer7->Add( value1_S, 0, wxALL, 5 );
	
	value1_TXT = new wxTextCtrl( QP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( value1_TXT, 1, wxALL, 5 );
	
	value2_S = new wxStaticText( QP, wxID_ANY, wxT("2"), wxDefaultPosition, wxDefaultSize, 0 );
	value2_S->Wrap( -1 );
	sbSizer7->Add( value2_S, 0, wxALL, 5 );
	
	value2_TXT = new wxTextCtrl( QP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer7->Add( value2_TXT, 1, wxALL, 5 );
	
	bSizer25->Add( sbSizer7, 1, wxEXPAND|wxLEFT|wxRIGHT, 5 );
	
	QL1->Add( bSizer25, 1, wxEXPAND, 5 );
	
	QL0->Add( QL1, 1, wxEXPAND, 5 );
	
	ignore_S = new wxStaticText( QP, wxID_ANY, wxT("Ignore result if..."), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_S->Wrap( -1 );
	QL0->Add( ignore_S, 0, wxALL, 5 );
	
	ignore_SW = new wxScrolledWindow( QP, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	ignore_SW->SetScrollRate( 0, 5 );
	wxFlexGridSizer* ignore_L;
	ignore_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	ignore_L->SetFlexibleDirection( wxBOTH );
	ignore_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ignore0_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is 0"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignore0_CB, 0, wxALL, 5 );
	
	ignoreF_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is FF"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreF_CB, 0, wxALL, 5 );
	
	ignoreValue_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is Value"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreValue_CB, 0, wxALL, 5 );
	
	ignoreValue_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreValue_TXT, 0, wxALL, 5 );
	
	ignoreInside_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreInside_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignoreInside_L;
	ignoreInside_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignoreInsideFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreInside_L->Add( ignoreInsideFrom_TXT, 0, wxALL, 5 );
	
	ignoreInside_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignoreInside_S->Wrap( -1 );
	ignoreInside_L->Add( ignoreInside_S, 0, wxALL, 5 );
	
	ignoreInsideTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreInside_L->Add( ignoreInsideTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignoreInside_L, 1, wxEXPAND, 5 );
	
	ignoreOutside_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is not between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreOutside_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignoreOutside_L;
	ignoreOutside_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignoreOutsideFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreOutside_L->Add( ignoreOutsideFrom_TXT, 0, wxALL, 5 );
	
	ignoreOutside_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignoreOutside_S->Wrap( -1 );
	ignoreOutside_L->Add( ignoreOutside_S, 0, wxALL, 5 );
	
	ignoreOutsideTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreOutside_L->Add( ignoreOutsideTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignoreOutside_L, 1, wxEXPAND, 5 );
	
	ignorePart8_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a CHAR value"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8_CB->Enable( false );
	
	ignore_L->Add( ignorePart8_CB, 0, wxALL, 5 );
	
	ignorePart8_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8_TXT->Enable( false );
	
	ignore_L->Add( ignorePart8_TXT, 0, wxALL, 5 );
	
	ignorePart16_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a WORD value"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16_CB->Enable( false );
	
	ignore_L->Add( ignorePart16_CB, 0, wxALL, 5 );
	
	ignorePart16_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16_TXT->Enable( false );
	
	ignore_L->Add( ignorePart16_TXT, 0, wxALL, 5 );
	
	ignorePart32_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a DWORD value"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32_CB->Enable( false );
	
	ignore_L->Add( ignorePart32_CB, 0, wxALL, 5 );
	
	ignorePart32_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32_TXT->Enable( false );
	
	ignore_L->Add( ignorePart32_TXT, 0, wxALL, 5 );
	
	ignorePart64_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a QWORD value"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64_CB->Enable( false );
	
	ignore_L->Add( ignorePart64_CB, 0, wxALL, 5 );
	
	ignorePart64_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64_TXT->Enable( false );
	
	ignore_L->Add( ignorePart64_TXT, 0, wxALL, 5 );
	
	ignorePart8Range_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a CHAR range between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8Range_CB->Enable( false );
	
	ignore_L->Add( ignorePart8Range_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignorePart8Range_L;
	ignorePart8Range_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignorePart8RangeFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8RangeFrom_TXT->Enable( false );
	
	ignorePart8Range_L->Add( ignorePart8RangeFrom_TXT, 0, wxALL, 5 );
	
	ignorePart8Range_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8Range_S->Wrap( -1 );
	ignorePart8Range_S->Enable( false );
	
	ignorePart8Range_L->Add( ignorePart8Range_S, 0, wxALL, 5 );
	
	ignorePart8RangeTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart8RangeTo_TXT->Enable( false );
	
	ignorePart8Range_L->Add( ignorePart8RangeTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignorePart8Range_L, 1, wxEXPAND, 5 );
	
	ignorePart16Range_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a WORD range between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16Range_CB->Enable( false );
	
	ignore_L->Add( ignorePart16Range_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignorePart16Range_L;
	ignorePart16Range_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignorePart16RangeFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16RangeFrom_TXT->Enable( false );
	
	ignorePart16Range_L->Add( ignorePart16RangeFrom_TXT, 0, wxALL, 5 );
	
	ignorePart16Range_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16Range_S->Wrap( -1 );
	ignorePart16Range_S->Enable( false );
	
	ignorePart16Range_L->Add( ignorePart16Range_S, 0, wxALL, 5 );
	
	ignorePart16RangeTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart16RangeTo_TXT->Enable( false );
	
	ignorePart16Range_L->Add( ignorePart16RangeTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignorePart16Range_L, 1, wxEXPAND, 5 );
	
	ignorePart32Range_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a DWORD range between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32Range_CB->Enable( false );
	
	ignore_L->Add( ignorePart32Range_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignorePart32Range_L;
	ignorePart32Range_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignorePart32RangeFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32RangeFrom_TXT->Enable( false );
	
	ignorePart32Range_L->Add( ignorePart32RangeFrom_TXT, 0, wxALL, 5 );
	
	ignorePart32Range_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32Range_S->Wrap( -1 );
	ignorePart32Range_S->Enable( false );
	
	ignorePart32Range_L->Add( ignorePart32Range_S, 0, wxALL, 5 );
	
	ignorePart32RangeTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart32RangeTo_TXT->Enable( false );
	
	ignorePart32Range_L->Add( ignorePart32RangeTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignorePart32Range_L, 1, wxEXPAND, 5 );
	
	ignorePart64Range_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Is part of a QWORD range between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64Range_CB->Enable( false );
	
	ignore_L->Add( ignorePart64Range_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignorePart64Range_L;
	ignorePart64Range_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignorePart64RangeFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64RangeFrom_TXT->Enable( false );
	
	ignorePart64Range_L->Add( ignorePart64RangeFrom_TXT, 0, wxALL, 5 );
	
	ignorePart64Range_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64Range_S->Wrap( -1 );
	ignorePart64Range_S->Enable( false );
	
	ignorePart64Range_L->Add( ignorePart64Range_S, 0, wxALL, 5 );
	
	ignorePart64RangeTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignorePart64RangeTo_TXT->Enable( false );
	
	ignorePart64Range_L->Add( ignorePart64RangeTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignorePart64Range_L, 1, wxEXPAND, 5 );
	
	ignoreAddressOutside_CB = new wxCheckBox( ignore_SW, wxID_ANY, wxT("Ignore if result address is not between"), wxDefaultPosition, wxDefaultSize, 0 );
	ignore_L->Add( ignoreAddressOutside_CB, 0, wxALL, 5 );
	
	wxBoxSizer* ignoreAddressOutside_L;
	ignoreAddressOutside_L = new wxBoxSizer( wxHORIZONTAL );
	
	ignoreAddressOutsideFrom_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreAddressOutsideFrom_TXT->SetMaxLength( 16 ); 
	ignoreAddressOutside_L->Add( ignoreAddressOutsideFrom_TXT, 0, wxALL, 5 );
	
	ignoreAddressOutside_S = new wxStaticText( ignore_SW, wxID_ANY, wxT("and"), wxDefaultPosition, wxDefaultSize, 0 );
	ignoreAddressOutside_S->Wrap( -1 );
	ignoreAddressOutside_L->Add( ignoreAddressOutside_S, 0, wxALL, 5 );
	
	ignoreAddressOutsideTo_TXT = new wxTextCtrl( ignore_SW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ignoreAddressOutsideTo_TXT->SetMaxLength( 16 ); 
	ignoreAddressOutside_L->Add( ignoreAddressOutsideTo_TXT, 0, wxALL, 5 );
	
	ignore_L->Add( ignoreAddressOutside_L, 1, wxEXPAND, 5 );
	
	ignore_SW->SetSizer( ignore_L );
	ignore_SW->Layout();
	ignore_L->Fit( ignore_SW );
	QL0->Add( ignore_SW, 1, wxEXPAND | wxALL, 5 );
	
	QP->SetSizer( QL0 );
	QP->Layout();
	QL0->Fit( QP );
	NB->AddPage( QP, wxT("Find"), false );
	RP = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* RL;
	RL = new wxFlexGridSizer( 0, 2, 0, 0 );
	RL->AddGrowableCol( 0 );
	RL->AddGrowableRow( 0 );
	RL->SetFlexibleDirection( wxBOTH );
	RL->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	RG = new wxGrid( RP, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	RG->CreateGrid( 0, 0 );
	RG->EnableEditing( false );
	RG->EnableGridLines( true );
	RG->EnableDragGridSize( false );
	RG->SetMargins( 0, 0 );
	
	// Columns
	RG->EnableDragColMove( false );
	RG->EnableDragColSize( true );
	RG->SetColLabelSize( 15 );
	RG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	RG->EnableDragRowSize( true );
	RG->SetRowLabelSize( 15 );
	RG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	RG->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	RL->Add( RG, 0, wxALL|wxEXPAND, 5 );
	
	RHP = new wxPanel( RP, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), wxTAB_TRAVERSAL );
	RHP->SetMinSize( wxSize( 200,-1 ) );
	RHP->SetMaxSize( wxSize( 200,-1 ) );
	
	wxFlexGridSizer* RHL0;
	RHL0 = new wxFlexGridSizer( 0, 1, 0, 0 );
	RHL0->AddGrowableRow( 1 );
	RHL0->SetFlexibleDirection( wxBOTH );
	RHL0->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	useEdit_CB = new wxCheckBox( RHP, wxID_ANY, wxT("Use selected address in editor"), wxDefaultPosition, wxDefaultSize, 0 );
	useEdit_CB->SetValue(true); 
	RHL0->Add( useEdit_CB, 0, wxALL, 5 );
	
	RHG = new wxGrid( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	RHG->CreateGrid( 0, 3 );
	RHG->EnableEditing( true );
	RHG->EnableGridLines( true );
	RHG->EnableDragGridSize( false );
	RHG->SetMargins( 0, 0 );
	
	// Columns
	RHG->EnableDragColMove( false );
	RHG->EnableDragColSize( true );
	RHG->SetColLabelSize( 15 );
	RHG->SetColLabelValue( 0, wxT("Type") );
	RHG->SetColLabelValue( 1, wxT("Address") );
	RHG->SetColLabelValue( 2, wxT("Value") );
	RHG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	RHG->EnableDragRowSize( true );
	RHG->SetRowLabelSize( 1 );
	RHG->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	RHG->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	RHL0->Add( RHG, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* RHL1;
	RHL1 = new wxStaticBoxSizer( new wxStaticBox( RHP, wxID_ANY, wxT("label") ), wxVERTICAL );
	
	wxFlexGridSizer* RHL2;
	RHL2 = new wxFlexGridSizer( 0, 2, 0, 0 );
	RHL2->AddGrowableCol( 0 );
	RHL2->SetFlexibleDirection( wxBOTH );
	RHL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	RHTS = new wxStaticText( RHP, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	RHTS->Wrap( -1 );
	RHL2->Add( RHTS, 0, wxALL, 5 );
	
	RHAdd = new wxButton( RHP, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	RHL2->Add( RHAdd, 0, 0, 5 );
	
	RHL1->Add( RHL2, 1, wxEXPAND, 5 );
	
	wxString RHTDChoices[] = { wxT("0x00 (CHAR)"), wxT("0x0000 (WORD)"), wxT("0x00000000 (DWORD)"), wxT("0x0000000000000000 (QWORD)") };
	int RHTDNChoices = sizeof( RHTDChoices ) / sizeof( wxString );
	RHTD = new wxChoice( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, RHTDNChoices, RHTDChoices, 0 );
	RHTD->SetSelection( 0 );
	RHL1->Add( RHTD, 0, wxALL|wxEXPAND, 5 );
	
	RHAS = new wxStaticText( RHP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	RHAS->Wrap( -1 );
	RHL1->Add( RHAS, 0, wxALL, 5 );
	
	resultAddress_TXT = new wxTextCtrl( RHP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resultAddress_TXT->SetMaxLength( 16 ); 
	RHL1->Add( resultAddress_TXT, 0, wxALL|wxEXPAND, 5 );
	
	RHVS = new wxStaticText( RHP, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	RHVS->Wrap( -1 );
	RHL1->Add( RHVS, 0, wxALL, 5 );
	
	resultValue_TXT = new wxTextCtrl( RHP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	RHL1->Add( resultValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	RHL0->Add( RHL1, 0, wxALL|wxEXPAND, 5 );
	
	RHP->SetSizer( RHL0 );
	RHP->Layout();
	RL->Add( RHP, 0, wxEXPAND | wxALL, 5 );
	
	RP->SetSizer( RL );
	RP->Layout();
	RL->Fit( RP );
	NB->AddPage( RP, wxT("Results"), false );
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
	
	editorAddress_TXT = new wxTextCtrl( EP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ELHead->Add( editorAddress_TXT, 0, wxALL, 5 );
	
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
	NB->AddPage( EP, wxT("Editor"), false );
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
	
	wxString codeType_DChoices[] = { wxT("Write"), wxT("Copy"), wxT("Test"), wxT("Increment"), wxT("Decrement"), wxT("List Write") };
	int codeType_DNChoices = sizeof( codeType_DChoices ) / sizeof( wxString );
	codeType_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeType_DNChoices, codeType_DChoices, 0 );
	codeType_D->SetSelection( 0 );
	HCHead->Add( codeType_D, 0, wxALL|wxEXPAND, 5 );
	
	codeRepeat_S = new wxStaticText( HCP, wxID_ANY, wxT("Repeat"), wxDefaultPosition, wxDefaultSize, 0 );
	codeRepeat_S->Wrap( -1 );
	HCHead->Add( codeRepeat_S, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	HCRAMS = new wxStaticText( HCP, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	HCRAMS->Wrap( -1 );
	HCHead->Add( HCRAMS, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeRAM_DChoices[] = { wxT("Main") };
	int codeRAM_DNChoices = sizeof( codeRAM_DChoices ) / sizeof( wxString );
	codeRAM_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeRAM_DNChoices, codeRAM_DChoices, 0 );
	codeRAM_D->SetSelection( 0 );
	HCHead->Add( codeRAM_D, 0, wxALL|wxEXPAND, 5 );
	
	codeRepeat_SN = new wxSpinCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	codeRepeat_SN->SetToolTip( wxT("Repeats on how many Addresses") );
	codeRepeat_SN->SetMinSize( wxSize( 50,-1 ) );
	
	HCHead->Add( codeRepeat_SN, 1, wxALL|wxEXPAND, 5 );
	
	sHackA = new wxStaticText( HCP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackA->Wrap( -1 );
	HCHead->Add( sHackA, 0, wxALL|wxEXPAND, 5 );
	
	codeAddress_TXT = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( codeAddress_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeFixed_DChoices[] = { wxT("Fixed"), wxT("Pointer") };
	int codeFixed_DNChoices = sizeof( codeFixed_DChoices ) / sizeof( wxString );
	codeFixed_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeFixed_DNChoices, codeFixed_DChoices, 0 );
	codeFixed_D->SetSelection( 0 );
	HCHead->Add( codeFixed_D, 0, wxALL|wxEXPAND, 5 );
	
	sHackV = new wxStaticText( HCP, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	sHackV->Wrap( -1 );
	HCHead->Add( sHackV, 0, wxALL|wxEXPAND, 5 );
	
	codeValue_TXT = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( codeValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeSize_DChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int codeSize_DNChoices = sizeof( codeSize_DChoices ) / sizeof( wxString );
	codeSize_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeSize_DNChoices, codeSize_DChoices, 0 );
	codeSize_D->SetSelection( 0 );
	HCHead->Add( codeSize_D, 0, wxALL|wxEXPAND, 5 );
	
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
	
	wxString codeTest_DChoices[] = { wxT("= Value"), wxT("!= Value"), wxT("> Value"), wxT(">= Value"), wxT("< Value"), wxT("<= Value") };
	int codeTest_DNChoices = sizeof( codeTest_DChoices ) / sizeof( wxString );
	codeTest_D = new wxChoice( HCTW, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeTest_DNChoices, codeTest_DChoices, 0 );
	codeTest_D->SetSelection( 0 );
	HCTL->Add( codeTest_D, 0, wxALL|wxEXPAND, 5 );
	
	HCTS2 = new wxStaticText( HCTW, wxID_ANY, wxT("do"), wxDefaultPosition, wxDefaultSize, 0 );
	HCTS2->Wrap( -1 );
	HCTL->Add( HCTS2, 0, wxALL, 5 );
	
	wxString codeTestLine_DChoices[] = { wxT("1 Line"), wxT("# Lines (Use repeat box)"), wxT("All Lines") };
	int codeTestLine_DNChoices = sizeof( codeTestLine_DChoices ) / sizeof( wxString );
	codeTestLine_D = new wxChoice( HCTW, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeTestLine_DNChoices, codeTestLine_DChoices, 0 );
	codeTestLine_D->SetSelection( 0 );
	HCTL->Add( codeTestLine_D, 0, wxALL|wxEXPAND, 5 );
	
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
	
	codeIncAddress_TXT = new wxTextCtrl( HCAW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCAL->Add( codeIncAddress_TXT, 0, wxALL|wxEXPAND, 5 );
	
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
	
	codeIncValue_TXT = new wxTextCtrl( HCVW, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCVL->Add( codeIncValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
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
	HCG->CreateGrid( 0, 4 );
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
	HCG->SetColLabelValue( 3, wxT("Sublines") );
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
	group_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::PFOnChange ), NULL, this );
	loadGroup_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFOnClick ), NULL, this );
	saveGroup_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::saveGroup_BOnClick ), NULL, this );
	PFGetB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFGetOnClick ), NULL, this );
	PFStartB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFStartOnClick ), NULL, this );
	appTitle_D->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appTitle_DOnBlur ), NULL, this );
	appUpdate_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appUpdate_BOnClick ), NULL, this );
	APPCheck->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	addRAM_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::addRAM_BOnClick ), NULL, this );
	RAMG->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::ram_GOnChange ), NULL, this );
	APPLIST->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	bQActS->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bQActSOnClick ), NULL, this );
	value1_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	value2_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreValue_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreInsideFrom_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreInsideTo_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreOutsideTo_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreAddressOutsideFrom_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	ignoreAddressOutsideTo_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	RG->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::result_GOnSelect ), NULL, this );
	resultAddress_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	resultValue_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	EAB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EAOnClick ), NULL, this );
	editorAddress_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	EVB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EVOnClick ), NULL, this );
	EUD->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::EUOnChange ), NULL, this );
	EG->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::EGOnChange ), NULL, this );
	EG->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( HEXFRM::editor_GOnScroll ), NULL, this );
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
	codeType_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::HCCDOnChange ), NULL, this );
	codeRepeat_SN->Connect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( HEXFRM::codeRepeat_SNOnSpin ), NULL, this );
	HCUseC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCUOnChange ), NULL, this );
	HCAddB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCAddBOnClick ), NULL, this );
	HCLoadB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCLoadOnClick ), NULL, this );
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
	group_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::PFOnChange ), NULL, this );
	loadGroup_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFOnClick ), NULL, this );
	saveGroup_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::saveGroup_BOnClick ), NULL, this );
	PFGetB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFGetOnClick ), NULL, this );
	PFStartB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::PFStartOnClick ), NULL, this );
	appTitle_D->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appTitle_DOnBlur ), NULL, this );
	appUpdate_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::appUpdate_BOnClick ), NULL, this );
	APPCheck->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	addRAM_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::addRAM_BOnClick ), NULL, this );
	RAMG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::ram_GOnChange ), NULL, this );
	APPLIST->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	bQActS->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::bQActSOnClick ), NULL, this );
	value1_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	value2_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreValue_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreInsideFrom_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreInsideTo_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreOutsideTo_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	ignoreAddressOutsideFrom_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	ignoreAddressOutsideTo_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	RG->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::result_GOnSelect ), NULL, this );
	resultAddress_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	resultValue_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::value_TXTOnKeyDown ), NULL, this );
	EAB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EAOnClick ), NULL, this );
	editorAddress_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	EVB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::EVOnClick ), NULL, this );
	EUD->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::EUOnChange ), NULL, this );
	EG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::EGOnChange ), NULL, this );
	EG->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( HEXFRM::editor_GOnScroll ), NULL, this );
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
	codeType_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::HCCDOnChange ), NULL, this );
	codeRepeat_SN->Disconnect( wxEVT_COMMAND_SPINCTRL_UPDATED, wxSpinEventHandler( HEXFRM::codeRepeat_SNOnSpin ), NULL, this );
	HCUseC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCUOnChange ), NULL, this );
	HCAddB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCAddBOnClick ), NULL, this );
	HCLoadB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCLoadOnClick ), NULL, this );
	HCDelB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCDelBOnClick ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::HCChangeD ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( HEXFRM::HCChangeR ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::HCChangeC ), NULL, this );
	
}
