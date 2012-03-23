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
	
	wHookScroll = new wxScrolledWindow( nbHook, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	wHookScroll->SetScrollRate( 0, 5 );
	wxBoxSizer* bsHookScroll;
	bsHookScroll = new wxBoxSizer( wxVERTICAL );
	
	hookPlatform = new wxPanel( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* hookPlatform_L;
	hookPlatform_L = new wxStaticBoxSizer( new wxStaticBox( hookPlatform, wxID_ANY, wxT("Hook") ), wxVERTICAL );
	
	hookPlatform_L->SetMinSize( wxSize( 250,-1 ) ); 
	wxArrayString group_DChoices;
	group_D = new wxChoice( hookPlatform, wxID_ANY, wxDefaultPosition, wxDefaultSize, group_DChoices, 0 );
	group_D->SetSelection( 0 );
	hookPlatform_L->Add( group_D, 0, wxALL|wxEXPAND, 5 );
	
	wxString hookType_DChoices[] = { wxT("Application"), wxT("File") };
	int hookType_DNChoices = sizeof( hookType_DChoices ) / sizeof( wxString );
	hookType_D = new wxChoice( hookPlatform, wxID_ANY, wxDefaultPosition, wxDefaultSize, hookType_DNChoices, hookType_DChoices, 0 );
	hookType_D->SetSelection( 0 );
	hookType_D->Enable( false );
	
	hookPlatform_L->Add( hookType_D, 0, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* hookPlatformButtons_L;
	hookPlatformButtons_L = new wxGridSizer( 0, 2, 0, 0 );
	
	loadGroup_B = new wxButton( hookPlatform, wxID_ANY, wxT("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	hookPlatformButtons_L->Add( loadGroup_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	saveGroup_B = new wxButton( hookPlatform, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	hookPlatformButtons_L->Add( saveGroup_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	PFGetB = new wxButton( hookPlatform, wxID_ANY, wxT("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	hookPlatformButtons_L->Add( PFGetB, 0, wxALIGN_CENTER|wxALL, 5 );
	
	PFStartB = new wxButton( hookPlatform, wxID_ANY, wxT("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	hookPlatformButtons_L->Add( PFStartB, 0, wxALIGN_CENTER|wxALL, 5 );
	
	hookPlatform_L->Add( hookPlatformButtons_L, 1, wxEXPAND, 5 );
	
	hookPlatform->SetSizer( hookPlatform_L );
	hookPlatform->Layout();
	hookPlatform_L->Fit( hookPlatform );
	bsHookScroll->Add( hookPlatform, 0, wxEXPAND, 5 );
	
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
	
	hookRAM_P = new wxPanel( wHookScroll, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* hookRAM_L;
	hookRAM_L = new wxStaticBoxSizer( new wxStaticBox( hookRAM_P, wxID_ANY, wxT("Memory") ), wxVERTICAL );
	
	addRAM_B = new wxButton( hookRAM_P, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	hookRAM_L->Add( addRAM_B, 0, wxALL, 5 );
	
	RAMG = new wxGrid( hookRAM_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
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
	
	hookRAM_L->Add( RAMG, 0, wxALL|wxEXPAND, 5 );
	
	hookRAM_P->SetSizer( hookRAM_L );
	hookRAM_P->Layout();
	hookRAM_L->Fit( hookRAM_P );
	bsHookScroll->Add( hookRAM_P, 0, wxEXPAND, 5 );
	
	wHookScroll->SetSizer( bsHookScroll );
	wHookScroll->Layout();
	bsHookScroll->Fit( wHookScroll );
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
	search_P = new wxPanel( NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* search_L;
	search_L = new wxFlexGridSizer( 0, 3, 0, 0 );
	search_L->AddGrowableCol( 0 );
	search_L->AddGrowableCol( 1 );
	search_L->AddGrowableCol( 2 );
	search_L->AddGrowableRow( 1 );
	search_L->SetFlexibleDirection( wxBOTH );
	search_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	good_S = new wxStaticText( search_P, wxID_ANY, wxT("Result is acceptable when"), wxDefaultPosition, wxDefaultSize, 0 );
	good_S->Wrap( -1 );
	search_L->Add( good_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bad_S = new wxStaticText( search_P, wxID_ANY, wxT("Result is not acceptable when"), wxDefaultPosition, wxDefaultSize, 0 );
	bad_S->Wrap( -1 );
	search_L->Add( bad_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	byte_PB = new wxGauge( search_P, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	search_L->Add( byte_PB, 0, wxALL|wxEXPAND, 5 );
	
	good_SCROLL = new wxScrolledWindow( search_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	good_SCROLL->SetScrollRate( 5, 5 );
	good_SCROLL->SetMinSize( wxSize( 185,-1 ) );
	
	wxBoxSizer* good_L;
	good_L = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* goodA_LF;
	goodA_LF = new wxStaticBoxSizer( new wxStaticBox( good_SCROLL, wxID_ANY, wxT("Address") ), wxVERTICAL );
	
	wxFlexGridSizer* goodA_L;
	goodA_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	goodA_L->AddGrowableCol( 1 );
	goodA_L->SetFlexibleDirection( wxBOTH );
	goodA_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	goodAGT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGT_CB, 0, wxALL, 5 );
	
	goodAGT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodAGTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGTE_CB, 0, wxALL, 5 );
	
	goodAGTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodALT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALT_CB, 0, wxALL, 5 );
	
	goodALT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodALTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALTE_CB, 0, wxALL, 5 );
	
	goodALTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodA_LF->Add( goodA_L, 1, wxEXPAND, 5 );
	
	good_L->Add( goodA_LF, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* goodV_FL;
	goodV_FL = new wxStaticBoxSizer( new wxStaticBox( good_SCROLL, wxID_ANY, wxT("Value") ), wxVERTICAL );
	
	wxFlexGridSizer* goodV_L;
	goodV_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	goodV_L->AddGrowableCol( 1 );
	goodV_L->SetFlexibleDirection( wxBOTH );
	goodV_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	goodVEqual_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVEqual_CB, 0, wxALL, 5 );
	
	goodVEqual_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVEqual_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodVNOTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("!="), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVNOTE_CB, 0, wxALL, 5 );
	
	goodVNOTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVNOTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodVGT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVGT_CB, 0, wxALL, 5 );
	
	goodVGT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodVGTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVGTE_CB, 0, wxALL, 5 );
	
	goodVGTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodVLT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVLT_CB, 0, wxALL, 5 );
	
	goodVLT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVLT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodVLTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVLTE_CB, 0, wxALL, 5 );
	
	goodVLTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodV_L->Add( goodVLTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodV_FL->Add( goodV_L, 1, wxEXPAND, 5 );
	
	good_L->Add( goodV_FL, 0, wxEXPAND, 5 );
	
	good_SCROLL->SetSizer( good_L );
	good_SCROLL->Layout();
	good_L->Fit( good_SCROLL );
	search_L->Add( good_SCROLL, 1, wxEXPAND | wxALL, 5 );
	
	bad_SCROLL = new wxScrolledWindow( search_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	bad_SCROLL->SetScrollRate( 5, 5 );
	bad_SCROLL->SetMinSize( wxSize( 185,-1 ) );
	
	wxBoxSizer* bad_L;
	bad_L = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* badA_LF;
	badA_LF = new wxStaticBoxSizer( new wxStaticBox( bad_SCROLL, wxID_ANY, wxT("Address") ), wxVERTICAL );
	
	wxFlexGridSizer* badA_L;
	badA_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	badA_L->AddGrowableCol( 1 );
	badA_L->SetFlexibleDirection( wxBOTH );
	badA_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	badAGT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGT_CB, 0, wxALL, 5 );
	
	badAGT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badAGTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGTE_CB, 0, wxALL, 5 );
	
	badAGTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badALT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALT_CB, 0, wxALL, 5 );
	
	badALT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badALTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALTE_CB, 0, wxALL, 5 );
	
	badALTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badA_LF->Add( badA_L, 1, wxEXPAND, 5 );
	
	bad_L->Add( badA_LF, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* badV_FL;
	badV_FL = new wxStaticBoxSizer( new wxStaticBox( bad_SCROLL, wxID_ANY, wxT("Value") ), wxVERTICAL );
	
	wxFlexGridSizer* badV_L;
	badV_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	badV_L->AddGrowableCol( 1 );
	badV_L->SetFlexibleDirection( wxBOTH );
	badV_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	badVEqual_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVEqual_CB, 0, wxALL, 5 );
	
	badVEqual_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVEqual_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badVNOTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("!="), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVNOTE_CB, 0, wxALL, 5 );
	
	badVNOTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVNOTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badVGT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVGT_CB, 0, wxALL, 5 );
	
	badVGT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badVGTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVGTE_CB, 0, wxALL, 5 );
	
	badVGTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badVLT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVLT_CB, 0, wxALL, 5 );
	
	badVLT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVLT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badVLTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVLTE_CB, 0, wxALL, 5 );
	
	badVLTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badV_L->Add( badVLTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badV_FL->Add( badV_L, 1, wxEXPAND, 5 );
	
	bad_L->Add( badV_FL, 0, wxEXPAND, 5 );
	
	bad_SCROLL->SetSizer( bad_L );
	bad_SCROLL->Layout();
	bad_L->Fit( bad_SCROLL );
	search_L->Add( bad_SCROLL, 1, wxEXPAND | wxALL, 5 );
	
	searchOptions_P = new wxPanel( search_P, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	searchOptions_P->SetMaxSize( wxSize( 300,-1 ) );
	
	wxBoxSizer* searchOptions_LV;
	searchOptions_LV = new wxBoxSizer( wxVERTICAL );
	
	total_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Results: 0"), wxDefaultPosition, wxDefaultSize, 0 );
	total_S->Wrap( -1 );
	searchOptions_LV->Add( total_S, 0, wxALL, 5 );
	
	searchOptions_LINE1 = new wxStaticLine( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	searchOptions_LV->Add( searchOptions_LINE1, 0, wxEXPAND | wxALL, 5 );
	
	wxFlexGridSizer* searchOptions_L;
	searchOptions_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	searchOptions_L->AddGrowableCol( 1 );
	searchOptions_L->SetFlexibleDirection( wxBOTH );
	searchOptions_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	compare_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Compare To"), wxDefaultPosition, wxDefaultSize, 0 );
	compare_S->Wrap( -1 );
	searchOptions_L->Add( compare_S, 0, wxALL, 5 );
	
	wxString compare_DChoices[] = { wxT("Dump") };
	int compare_DNChoices = sizeof( compare_DChoices ) / sizeof( wxString );
	compare_D = new wxChoice( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, compare_DNChoices, compare_DChoices, 0 );
	compare_D->SetSelection( 0 );
	searchOptions_L->Add( compare_D, 0, wxALL|wxEXPAND, 5 );
	
	searchRAM_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	searchRAM_S->Wrap( -1 );
	searchOptions_L->Add( searchRAM_S, 0, wxALL, 5 );
	
	wxArrayString searchRAM_DChoices;
	searchRAM_D = new wxChoice( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, searchRAM_DChoices, 0 );
	searchRAM_D->SetSelection( 0 );
	searchOptions_L->Add( searchRAM_D, 0, wxALL|wxEXPAND, 5 );
	
	searchType_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Search Type"), wxDefaultPosition, wxDefaultSize, 0 );
	searchType_S->Wrap( -1 );
	searchOptions_L->Add( searchType_S, 0, wxALL, 5 );
	
	wxString searchType_DChoices[] = { wxT("Dump"), wxT("Equal To ( = )"), wxT("Not Equal To ( != )"), wxT("More Than ( > )"), wxT("More Than or Equal To ( >= )"), wxT("Less Than ( < )"), wxT("Less Than or Equal To  ( <= )") };
	int searchType_DNChoices = sizeof( searchType_DChoices ) / sizeof( wxString );
	searchType_D = new wxChoice( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, searchType_DNChoices, searchType_DChoices, 0 );
	searchType_D->SetSelection( 0 );
	searchOptions_L->Add( searchType_D, 0, wxALL|wxEXPAND, 5 );
	
	searchSize_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	searchSize_S->Wrap( -1 );
	searchOptions_L->Add( searchSize_S, 0, wxALL, 5 );
	
	wxString searchSize_DChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int searchSize_DNChoices = sizeof( searchSize_DChoices ) / sizeof( wxString );
	searchSize_D = new wxChoice( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, searchSize_DNChoices, searchSize_DChoices, 0 );
	searchSize_D->SetSelection( 0 );
	searchOptions_L->Add( searchSize_D, 0, wxALL|wxEXPAND, 5 );
	
	searchValueType_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("Value Type"), wxDefaultPosition, wxDefaultSize, 0 );
	searchValueType_S->Wrap( -1 );
	searchOptions_L->Add( searchValueType_S, 0, wxALL, 5 );
	
	wxString searchValueType_DChoices[] = { wxT("HexaDecimal"), wxT("Integer"), wxT("Float") };
	int searchValueType_DNChoices = sizeof( searchValueType_DChoices ) / sizeof( wxString );
	searchValueType_D = new wxChoice( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, searchValueType_DNChoices, searchValueType_DChoices, 0 );
	searchValueType_D->SetSelection( 0 );
	searchOptions_L->Add( searchValueType_D, 0, wxALL|wxEXPAND, 5 );
	
	searchIsSigned_CB = new wxCheckBox( searchOptions_P, wxID_ANY, wxT("Is Signed"), wxDefaultPosition, wxDefaultSize, 0 );
	searchIsSigned_CB->Enable( false );
	
	searchOptions_L->Add( searchIsSigned_CB, 0, wxALL, 5 );
	
	searchIsSigned_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("( Goes below 0 )"), wxDefaultPosition, wxDefaultSize, 0 );
	searchIsSigned_S->Wrap( -1 );
	searchOptions_L->Add( searchIsSigned_S, 0, wxALL, 5 );
	
	searchIsBinary_CB = new wxCheckBox( searchOptions_P, wxID_ANY, wxT("Treat as Binary"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_L->Add( searchIsBinary_CB, 0, wxALL, 5 );
	
	searchIsBinary_S = new wxStaticText( searchOptions_P, wxID_ANY, wxT("( Use '&&' in tests )"), wxDefaultPosition, wxDefaultSize, 0 );
	searchIsBinary_S->Wrap( -1 );
	searchOptions_L->Add( searchIsBinary_S, 0, wxALL, 5 );
	
	searchOptions_LV->Add( searchOptions_L, 1, wxEXPAND, 5 );
	
	searchOptions_LINE2 = new wxStaticLine( searchOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	searchOptions_LV->Add( searchOptions_LINE2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* searchOptions_LH1;
	searchOptions_LH1 = new wxBoxSizer( wxHORIZONTAL );
	
	dump_B = new wxButton( searchOptions_P, wxID_ANY, wxT("Dump"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH1->Add( dump_B, 1, wxALL, 5 );
	
	search_B = new wxButton( searchOptions_P, wxID_ANY, wxT("Search"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH1->Add( search_B, 1, wxALL, 5 );
	
	searchUndo_B = new wxButton( searchOptions_P, wxID_ANY, wxT("Undo"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH1->Add( searchUndo_B, 1, wxALL, 5 );
	
	searchOptions_LV->Add( searchOptions_LH1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* searchOptions_LH2;
	searchOptions_LH2 = new wxBoxSizer( wxHORIZONTAL );
	
	searchLT_B = new wxButton( searchOptions_P, wxID_ANY, wxT("<"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchLT_B, 1, wxALL, 5 );
	
	searchLTE_B = new wxButton( searchOptions_P, wxID_ANY, wxT("<="), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchLTE_B, 1, wxALL, 5 );
	
	searchEqual_B = new wxButton( searchOptions_P, wxID_ANY, wxT("="), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchEqual_B, 1, wxALL, 5 );
	
	searchNOTE_B = new wxButton( searchOptions_P, wxID_ANY, wxT("!="), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchNOTE_B, 1, wxALL, 5 );
	
	searchGTE_B = new wxButton( searchOptions_P, wxID_ANY, wxT(">="), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchGTE_B, 1, wxALL, 5 );
	
	searchGT_B = new wxButton( searchOptions_P, wxID_ANY, wxT(">"), wxDefaultPosition, wxDefaultSize, 0 );
	searchOptions_LH2->Add( searchGT_B, 1, wxALL, 5 );
	
	searchOptions_LV->Add( searchOptions_LH2, 0, wxEXPAND, 5 );
	
	searchOptions_P->SetSizer( searchOptions_LV );
	searchOptions_P->Layout();
	searchOptions_LV->Fit( searchOptions_P );
	search_L->Add( searchOptions_P, 1, wxALL|wxEXPAND, 5 );
	
	search_P->SetSizer( search_L );
	search_P->Layout();
	search_L->Fit( search_P );
	NB->AddPage( search_P, wxT("Search"), false );
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
	
	resultHack_G = new wxGrid( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	resultHack_G->CreateGrid( 0, 4 );
	resultHack_G->EnableEditing( true );
	resultHack_G->EnableGridLines( true );
	resultHack_G->EnableDragGridSize( false );
	resultHack_G->SetMargins( 0, 0 );
	
	// Columns
	resultHack_G->EnableDragColMove( false );
	resultHack_G->EnableDragColSize( true );
	resultHack_G->SetColLabelSize( 15 );
	resultHack_G->SetColLabelValue( 0, wxT("Memory") );
	resultHack_G->SetColLabelValue( 1, wxT("Address") );
	resultHack_G->SetColLabelValue( 2, wxT("Value") );
	resultHack_G->SetColLabelValue( 3, wxT("Bytes") );
	resultHack_G->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	resultHack_G->EnableDragRowSize( true );
	resultHack_G->SetRowLabelSize( 1 );
	resultHack_G->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	resultHack_G->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	RHL0->Add( resultHack_G, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* RHL1;
	RHL1 = new wxStaticBoxSizer( new wxStaticBox( RHP, wxID_ANY, wxT("label") ), wxVERTICAL );
	
	wxFlexGridSizer* RHL2;
	RHL2 = new wxFlexGridSizer( 0, 0, 0, 0 );
	RHL2->AddGrowableCol( 0 );
	RHL2->SetFlexibleDirection( wxBOTH );
	RHL2->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	resultHackAdd_B = new wxButton( RHP, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	RHL2->Add( resultHackAdd_B, 0, 0, 5 );
	
	resultHackDel_B = new wxButton( RHP, wxID_ANY, wxT("Del"), wxDefaultPosition, wxDefaultSize, 0 );
	RHL2->Add( resultHackDel_B, 0, 0, 5 );
	
	RHL1->Add( RHL2, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer37;
	fgSizer37 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer37->AddGrowableCol( 1 );
	fgSizer37->SetFlexibleDirection( wxBOTH );
	fgSizer37->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	resultHackRAM_S = new wxStaticText( RHP, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	resultHackRAM_S->Wrap( -1 );
	fgSizer37->Add( resultHackRAM_S, 0, wxALL, 5 );
	
	wxArrayString resultHackRAM_DChoices;
	resultHackRAM_D = new wxChoice( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, resultHackRAM_DChoices, 0 );
	resultHackRAM_D->SetSelection( 0 );
	resultHackRAM_D->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer37->Add( resultHackRAM_D, 0, wxALL|wxEXPAND, 5 );
	
	resultHackSize_S = new wxStaticText( RHP, wxID_ANY, wxT("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	resultHackSize_S->Wrap( -1 );
	fgSizer37->Add( resultHackSize_S, 0, wxALL, 5 );
	
	wxString resultHackSize_DChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int resultHackSize_DNChoices = sizeof( resultHackSize_DChoices ) / sizeof( wxString );
	resultHackSize_D = new wxChoice( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, resultHackSize_DNChoices, resultHackSize_DChoices, 0 );
	resultHackSize_D->SetSelection( 0 );
	fgSizer37->Add( resultHackSize_D, 0, wxALL|wxEXPAND, 5 );
	
	resultHackAddress_S = new wxStaticText( RHP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	resultHackAddress_S->Wrap( -1 );
	fgSizer37->Add( resultHackAddress_S, 0, wxALL, 5 );
	
	resultHackAddress_TXT = new wxTextCtrl( RHP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	resultHackAddress_TXT->SetMaxLength( 16 ); 
	fgSizer37->Add( resultHackAddress_TXT, 0, wxALL|wxEXPAND, 5 );
	
	resultHackMode_S = new wxStaticText( RHP, wxID_ANY, wxT("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	resultHackMode_S->Wrap( -1 );
	fgSizer37->Add( resultHackMode_S, 0, wxALL, 5 );
	
	wxString resultHackMode_DChoices[] = { wxT("HexaDecimal"), wxT("Unsigned Integer"), wxT("Float"), wxT("Signed Integer") };
	int resultHackMode_DNChoices = sizeof( resultHackMode_DChoices ) / sizeof( wxString );
	resultHackMode_D = new wxChoice( RHP, wxID_ANY, wxDefaultPosition, wxDefaultSize, resultHackMode_DNChoices, resultHackMode_DChoices, 0 );
	resultHackMode_D->SetSelection( 0 );
	fgSizer37->Add( resultHackMode_D, 0, wxALL, 5 );
	
	resultHackValue_S = new wxStaticText( RHP, wxID_ANY, wxT("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	resultHackValue_S->Wrap( -1 );
	fgSizer37->Add( resultHackValue_S, 0, wxALL, 5 );
	
	resultHackValue_TXT = new wxTextCtrl( RHP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fgSizer37->Add( resultHackValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	RHL1->Add( fgSizer37, 1, wxEXPAND, 5 );
	
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
	EG->CreateGrid( 0, 18 );
	EG->EnableEditing( true );
	EG->EnableGridLines( true );
	EG->EnableDragGridSize( false );
	EG->SetMargins( 0, 0 );
	
	// Columns
	EG->EnableDragColMove( false );
	EG->EnableDragColSize( true );
	EG->SetColLabelSize( 30 );
	EG->SetColLabelValue( 0, wxT("0") );
	EG->SetColLabelValue( 1, wxT("1") );
	EG->SetColLabelValue( 2, wxT("2") );
	EG->SetColLabelValue( 3, wxT("3") );
	EG->SetColLabelValue( 4, wxT("4") );
	EG->SetColLabelValue( 5, wxT("5") );
	EG->SetColLabelValue( 6, wxT("6") );
	EG->SetColLabelValue( 7, wxT("7") );
	EG->SetColLabelValue( 8, wxT("8") );
	EG->SetColLabelValue( 9, wxT("9") );
	EG->SetColLabelValue( 10, wxT("A") );
	EG->SetColLabelValue( 11, wxT("B") );
	EG->SetColLabelValue( 12, wxT("C") );
	EG->SetColLabelValue( 13, wxT("D") );
	EG->SetColLabelValue( 14, wxT("E") );
	EG->SetColLabelValue( 15, wxT("F") );
	EG->SetColLabelValue( 16, wxT("Ascii") );
	EG->SetColLabelValue( 17, wxT("UTF8") );
	EG->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	EG->EnableDragRowSize( true );
	EG->SetRowLabelSize( 100 );
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
	
	codeType_S = new wxStaticText( HCP, wxID_ANY, wxT("Code Type"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	codeType_S->Wrap( -1 );
	HCHead->Add( codeType_S, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeType_DChoices[] = { wxT("Write"), wxT("Copy"), wxT("Test"), wxT("Increment"), wxT("Decrement"), wxT("List Write") };
	int codeType_DNChoices = sizeof( codeType_DChoices ) / sizeof( wxString );
	codeType_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeType_DNChoices, codeType_DChoices, 0 );
	codeType_D->SetSelection( 0 );
	HCHead->Add( codeType_D, 0, wxALL|wxEXPAND, 5 );
	
	codeRepeat_S = new wxStaticText( HCP, wxID_ANY, wxT("Repeat"), wxDefaultPosition, wxDefaultSize, 0 );
	codeRepeat_S->Wrap( -1 );
	HCHead->Add( codeRepeat_S, 0, wxALIGN_BOTTOM|wxALL, 5 );
	
	codeRAM_S = new wxStaticText( HCP, wxID_ANY, wxT("Memory"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	codeRAM_S->Wrap( -1 );
	HCHead->Add( codeRAM_S, 0, wxALL|wxEXPAND, 5 );
	
	wxArrayString codeRAM_DChoices;
	codeRAM_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeRAM_DChoices, 0 );
	codeRAM_D->SetSelection( 0 );
	HCHead->Add( codeRAM_D, 0, wxALL|wxEXPAND, 5 );
	
	codeRepeat_SN = new wxSpinCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	codeRepeat_SN->SetToolTip( wxT("Repeats on how many Addresses") );
	codeRepeat_SN->SetMinSize( wxSize( 50,-1 ) );
	
	HCHead->Add( codeRepeat_SN, 1, wxALL|wxEXPAND, 5 );
	
	codeAddress_S = new wxStaticText( HCP, wxID_ANY, wxT("Address"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	codeAddress_S->Wrap( -1 );
	HCHead->Add( codeAddress_S, 0, wxALL|wxEXPAND, 5 );
	
	codeAddress_TXT = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( codeAddress_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeFixed_DChoices[] = { wxT("Fixed"), wxT("Pointer") };
	int codeFixed_DNChoices = sizeof( codeFixed_DChoices ) / sizeof( wxString );
	codeFixed_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeFixed_DNChoices, codeFixed_DChoices, 0 );
	codeFixed_D->SetSelection( 0 );
	HCHead->Add( codeFixed_D, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeSize_DChoices[] = { wxT("CHAR"), wxT("WORD"), wxT("DWORD"), wxT("QWORD") };
	int codeSize_DNChoices = sizeof( codeSize_DChoices ) / sizeof( wxString );
	codeSize_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeSize_DNChoices, codeSize_DChoices, 0 );
	codeSize_D->SetSelection( 0 );
	codeSize_D->SetMinSize( wxSize( 50,-1 ) );
	
	HCHead->Add( codeSize_D, 0, wxALL|wxEXPAND, 5 );
	
	codeValue_TXT = new wxTextCtrl( HCP, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	HCHead->Add( codeValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxString codeMode_DChoices[] = { wxT("HexaDecimal"), wxT("Unsigned Integer"), wxT("Float"), wxT("Signed Integer") };
	int codeMode_DNChoices = sizeof( codeMode_DChoices ) / sizeof( wxString );
	codeMode_D = new wxChoice( HCP, wxID_ANY, wxDefaultPosition, wxDefaultSize, codeMode_DNChoices, codeMode_DChoices, 0 );
	codeMode_D->SetSelection( 0 );
	codeMode_D->SetMinSize( wxSize( 50,-1 ) );
	
	HCHead->Add( codeMode_D, 0, wxALL|wxEXPAND, 5 );
	
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
	appName_TXT->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appName_TXTOnBlur ), NULL, this );
	APPCheck->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	fileTitle_D->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	addRAM_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::addRAM_BOnClick ), NULL, this );
	RAMG->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::ram_GOnChange ), NULL, this );
	APPLIST->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	goodAGT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodAGT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodAGTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodAGTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodALT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodALT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodALTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodALTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodVEqual_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVEqual_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVNOTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVNOTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVGT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVGT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVGTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVGTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVLT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVLT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVLTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVLTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badAGT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badAGT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badAGTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badAGTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badALT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badALT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badALTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badALTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badVEqual_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVEqual_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVNOTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVNOTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVGT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVGT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVGTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVGTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVLT_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVLT_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVLTE_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVLTE_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	compare_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::compare_DOnChoice ), NULL, this );
	searchValueType_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::searchValueType_DOnChoice ), NULL, this );
	dump_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::dump_BOnClick ), NULL, this );
	search_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::search_BOnClick ), NULL, this );
	searchUndo_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchUndo_BOnClick ), NULL, this );
	searchLT_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchLT_BOnClick ), NULL, this );
	searchLTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchLTE_BOnClick ), NULL, this );
	searchEqual_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchEqual_BOnClick ), NULL, this );
	searchNOTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchNOTE_BOnClick ), NULL, this );
	searchGTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchGTE_BOnClick ), NULL, this );
	searchGT_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchGT_BOnClick ), NULL, this );
	RG->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::result_GOnSelect ), NULL, this );
	resultHack_G->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::resultHack_GOnSelectCell ), NULL, this );
	resultHackAdd_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::resultHackAdd_BOnClick ), NULL, this );
	resultHackDel_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::resultHackDel_BOnClick ), NULL, this );
	resultHackAddress_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	resultHackAddress_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::address_TXTOnKeyUp ), NULL, this );
	resultHackValue_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::resultValue_TXTOnKeyDown ), NULL, this );
	resultHackValue_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::resultValue_TXTOnKeyUp ), NULL, this );
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
	codeAddress_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	codeAddress_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::address_TXTOnKeyUp ), NULL, this );
	codeValue_TXT->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::codeValue_TXTOnKeyDown ), NULL, this );
	codeValue_TXT->Connect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::codeValue_TXTOnKeyUp ), NULL, this );
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
	appName_TXT->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( HEXFRM::appName_TXTOnBlur ), NULL, this );
	APPCheck->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::mWaitOnChange ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( HEXFRM::BINDOnChange ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( HEXFRM::BINDOnEdit ), NULL, this );
	fileTitle_D->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( HEXFRM::BINDOnEnter ), NULL, this );
	BINB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::BINBOnClick ), NULL, this );
	addRAM_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::addRAM_BOnClick ), NULL, this );
	RAMG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::ram_GOnChange ), NULL, this );
	APPLIST->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPLISTOnClick ), NULL, this );
	APPUSE->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::APPUSEOnClick ), NULL, this );
	goodAGT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodAGT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodAGTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodAGTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodALT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodALT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodALTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	goodALTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	goodVEqual_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVEqual_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVNOTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVNOTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVGT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVGT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVGTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVGTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVLT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVLT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	goodVLTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	goodVLTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badAGT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badAGT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badAGTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badAGTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badALT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badALT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badALTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyDown ), NULL, this );
	badALTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::byte_TXTOnKeyUp ), NULL, this );
	badVEqual_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVEqual_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVNOTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVNOTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVGT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVGT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVGTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVGTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVLT_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVLT_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	badVLTE_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::search_TXTOnKeyDown ), NULL, this );
	badVLTE_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::search_TXTOnKeyUp ), NULL, this );
	compare_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::compare_DOnChoice ), NULL, this );
	searchValueType_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( HEXFRM::searchValueType_DOnChoice ), NULL, this );
	dump_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::dump_BOnClick ), NULL, this );
	search_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::search_BOnClick ), NULL, this );
	searchUndo_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchUndo_BOnClick ), NULL, this );
	searchLT_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchLT_BOnClick ), NULL, this );
	searchLTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchLTE_BOnClick ), NULL, this );
	searchEqual_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchEqual_BOnClick ), NULL, this );
	searchNOTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchNOTE_BOnClick ), NULL, this );
	searchGTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchGTE_BOnClick ), NULL, this );
	searchGT_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::searchGT_BOnClick ), NULL, this );
	RG->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::result_GOnSelect ), NULL, this );
	resultHack_G->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::resultHack_GOnSelectCell ), NULL, this );
	resultHackAdd_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::resultHackAdd_BOnClick ), NULL, this );
	resultHackDel_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::resultHackDel_BOnClick ), NULL, this );
	resultHackAddress_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	resultHackAddress_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::address_TXTOnKeyUp ), NULL, this );
	resultHackValue_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::resultValue_TXTOnKeyDown ), NULL, this );
	resultHackValue_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::resultValue_TXTOnKeyUp ), NULL, this );
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
	codeAddress_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::address_TXTOnKeyDown ), NULL, this );
	codeAddress_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::address_TXTOnKeyUp ), NULL, this );
	codeValue_TXT->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( HEXFRM::codeValue_TXTOnKeyDown ), NULL, this );
	codeValue_TXT->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( HEXFRM::codeValue_TXTOnKeyUp ), NULL, this );
	HCUseC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( HEXFRM::HCUOnChange ), NULL, this );
	HCAddB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCAddBOnClick ), NULL, this );
	HCLoadB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCLoadOnClick ), NULL, this );
	HCDelB->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( HEXFRM::HCDelBOnClick ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( HEXFRM::HCChangeD ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_RANGE_SELECT, wxGridRangeSelectEventHandler( HEXFRM::HCChangeR ), NULL, this );
	HCG->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( HEXFRM::HCChangeC ), NULL, this );
	
}
