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

#include "cleanFRM.h"

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

cleanFRM::cleanFRM( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
	
	wxBoxSizer* cleanFRM_L;
	cleanFRM_L = new wxBoxSizer( wxVERTICAL );
	
	cleanFRM_L->SetMinSize( wxSize( 480,460 ) ); 
	cleanFRM_NB = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	hook_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* hook_L;
	hook_L = new wxFlexGridSizer( 1, 2, 0, 0 );
	hook_L->AddGrowableCol( 1 );
	hook_L->AddGrowableRow( 0 );
	hook_L->SetFlexibleDirection( wxHORIZONTAL );
	hook_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	hook_SW = new wxScrolledWindow( hook_P, wxID_ANY, wxDefaultPosition, wxSize( -1,400 ), wxVSCROLL );
	hook_SW->SetScrollRate( 0, 5 );
	wxBoxSizer* bsHookScroll;
	bsHookScroll = new wxBoxSizer( wxVERTICAL );
	
	bsHookScroll->SetMinSize( wxSize( 230,-1 ) ); 
	org_P = new wxPanel( hook_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* org_L;
	org_L = new wxStaticBoxSizer( new wxStaticBox( org_P, wxID_ANY, _("Organisation") ), wxVERTICAL );
	
	mOrg_TBar = new wxToolBar( org_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	mOrg_TBar->AddTool( mListOrg_ID, _("List"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mOrg_TBar->AddTool( mLoadOrg_ID, _("Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mOrg_TBar->AddTool( mSaveOrg_ID, _("Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mOrg_TBar->AddTool( mSetOrg_ID, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mOrg_TBar->Realize(); 
	
	org_L->Add( mOrg_TBar, 0, wxEXPAND, 5 );
	
	SetOrg_P = new wxPanel( org_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* SetOrg_L;
	SetOrg_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	SetOrg_L->AddGrowableCol( 1 );
	SetOrg_L->SetFlexibleDirection( wxBOTH );
	SetOrg_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	orgName_S = new wxStaticText( SetOrg_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	orgName_S->Wrap( -1 );
	SetOrg_L->Add( orgName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	orgName_TXT = new wxTextCtrl( SetOrg_P, mOrgName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	orgName_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	SetOrg_L->Add( orgName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	orgFile_S = new wxStaticText( SetOrg_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	orgFile_S->Wrap( -1 );
	SetOrg_L->Add( orgFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	orgFile_TXT = new wxTextCtrl( SetOrg_P, mOrgFile_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	orgFile_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	SetOrg_L->Add( orgFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	SetOrg_P->SetSizer( SetOrg_L );
	SetOrg_P->Layout();
	SetOrg_L->Fit( SetOrg_P );
	org_L->Add( SetOrg_P, 0, wxEXPAND, 5 );
	
	org_P->SetSizer( org_L );
	org_P->Layout();
	org_L->Fit( org_P );
	bsHookScroll->Add( org_P, 0, wxALL|wxEXPAND, 5 );
	
	pfm_P = new wxPanel( hook_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* pfm_L;
	pfm_L = new wxStaticBoxSizer( new wxStaticBox( pfm_P, wxID_ANY, _("Platform") ), wxVERTICAL );
	
	mPFM_TBar = new wxToolBar( pfm_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	mPFM_TBar->AddTool( mListPFM_ID, _("List"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mPFM_TBar->AddTool( mLoadPFM_ID, _("Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mPFM_TBar->AddTool( mSavePFM_ID, _("Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mPFM_TBar->AddTool( mSetPFM_ID, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mPFM_TBar->Realize(); 
	
	pfm_L->Add( mPFM_TBar, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* SetPFM_L;
	SetPFM_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	SetPFM_L->AddGrowableCol( 1 );
	SetPFM_L->SetFlexibleDirection( wxBOTH );
	SetPFM_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	pfmName_S = new wxStaticText( pfm_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	pfmName_S->Wrap( -1 );
	SetPFM_L->Add( pfmName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	pfmName_TXT = new wxTextCtrl( pfm_P, mPFMName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	pfmName_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	SetPFM_L->Add( pfmName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	pfmFile_S = new wxStaticText( pfm_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	pfmFile_S->Wrap( -1 );
	SetPFM_L->Add( pfmFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	pfmFile_TXT = new wxTextCtrl( pfm_P, mPFMFile_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	pfmFile_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	SetPFM_L->Add( pfmFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	pfmEndian_S = new wxStaticText( pfm_P, wxID_ANY, _("Endian"), wxDefaultPosition, wxDefaultSize, 0 );
	pfmEndian_S->Wrap( -1 );
	SetPFM_L->Add( pfmEndian_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString pfmEndian_DChoices[] = { _("Little"), _("Big"), _("Little Big") };
	int pfmEndian_DNChoices = sizeof( pfmEndian_DChoices ) / sizeof( wxString );
	pfmEndian_D = new wxChoice( pfm_P, mPFMEndian_ID, wxDefaultPosition, wxDefaultSize, pfmEndian_DNChoices, pfmEndian_DChoices, 0 );
	pfmEndian_D->SetSelection( 0 );
	pfmEndian_D->SetMinSize( wxSize( 50,-1 ) );
	
	SetPFM_L->Add( pfmEndian_D, 0, wxALL|wxEXPAND, 5 );
	
	pfm_L->Add( SetPFM_L, 0, wxEXPAND, 5 );
	
	pfm_P->SetSizer( pfm_L );
	pfm_P->Layout();
	pfm_L->Fit( pfm_P );
	bsHookScroll->Add( pfm_P, 0, wxALL|wxEXPAND, 5 );
	
	bin_P = new wxPanel( hook_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* bin_L;
	bin_L = new wxStaticBoxSizer( new wxStaticBox( bin_P, wxID_ANY, _("Binary") ), wxVERTICAL );
	
	mBin_TBar = new wxToolBar( bin_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	mBin_TBar->AddTool( mListBin_ID, _("List"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mBin_TBar->AddTool( mLoadBin_ID, _("Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mBin_TBar->AddTool( mSaveBin_ID, _("Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mBin_TBar->AddTool( mSetBin_ID, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	mBin_TBar->Realize(); 
	
	bin_L->Add( mBin_TBar, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* binData1_L;
	binData1_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	binData1_L->AddGrowableCol( 1 );
	binData1_L->SetFlexibleDirection( wxBOTH );
	binData1_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	binName_S = new wxStaticText( bin_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	binName_S->Wrap( -1 );
	binData1_L->Add( binName_S, 0, wxALL, 5 );
	
	binName_TXT = new wxTextCtrl( bin_P, mBinName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	binName_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	binData1_L->Add( binName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	binFile_S = new wxStaticText( bin_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	binFile_S->Wrap( -1 );
	binData1_L->Add( binFile_S, 0, wxALL, 5 );
	
	binFile_TXT = new wxTextCtrl( bin_P, mBinFile_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	binFile_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	binData1_L->Add( binFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	bin_L->Add( binData1_L, 1, wxEXPAND, 5 );
	
	wxFlexGridSizer* binData2_L;
	binData2_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	binData2_L->AddGrowableCol( 1 );
	binData2_L->SetFlexibleDirection( wxBOTH );
	binData2_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	binPath_B = new wxButton( bin_P, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
	binData2_L->Add( binPath_B, 0, wxALL, 5 );
	
	binPath_TXT = new wxTextCtrl( bin_P, mBinPath_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	binPath_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	binData2_L->Add( binPath_TXT, 0, wxALL|wxEXPAND, 5 );
	
	binBind_B = new wxButton( bin_P, wxID_ANY, _("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	binData2_L->Add( binBind_B, 0, wxALL, 5 );
	
	binBind_TXT = new wxTextCtrl( bin_P, mBinBind_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	binBind_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	binData2_L->Add( binBind_TXT, 0, wxALL|wxEXPAND, 5 );
	
	bin_L->Add( binData2_L, 0, wxEXPAND, 5 );
	
	wxGridSizer* binGrid_LG;
	binGrid_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	isApp_RB = new wxRadioButton( bin_P, isApp_ID, _("Application"), wxDefaultPosition, wxDefaultSize, 0 );
	isApp_RB->SetValue( true ); 
	binGrid_LG->Add( isApp_RB, 0, wxALIGN_CENTER|wxALL, 5 );
	
	isFile_RB = new wxRadioButton( bin_P, isFile_ID, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	binGrid_LG->Add( isFile_RB, 0, wxALIGN_CENTER|wxALL, 5 );
	
	binHook_B = new wxButton( bin_P, binHook_ID, _("Hook"), wxDefaultPosition, wxDefaultSize, 0 );
	binGrid_LG->Add( binHook_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	binLaunch_B = new wxButton( bin_P, binLaunch_ID, _("Launch"), wxDefaultPosition, wxDefaultSize, 0 );
	binGrid_LG->Add( binLaunch_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bin_L->Add( binGrid_LG, 0, wxEXPAND, 5 );
	
	bin_P->SetSizer( bin_L );
	bin_P->Layout();
	bin_L->Fit( bin_P );
	bsHookScroll->Add( bin_P, 0, wxALL|wxEXPAND, 5 );
	
	ram_P = new wxPanel( hook_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* ram_L;
	ram_L = new wxStaticBoxSizer( new wxStaticBox( ram_P, wxID_ANY, _("Memory") ), wxVERTICAL );
	
	wxStaticBoxSizer* ramName_L;
	ramName_L = new wxStaticBoxSizer( new wxStaticBox( ram_P, wxID_ANY, _("Name") ), wxVERTICAL );
	
	wxArrayString ramName_DChoices;
	ramName_D = new wxChoice( ram_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, ramName_DChoices, 0 );
	ramName_D->SetSelection( 0 );
	ramName_D->SetMinSize( wxSize( 50,-1 ) );
	
	ramName_L->Add( ramName_D, 0, wxALL|wxEXPAND, 5 );
	
	ramName_TXT = new wxTextCtrl( ram_P, mRamName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	ramName_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	ramName_L->Add( ramName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	ram_L->Add( ramName_L, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* ramData_L;
	ramData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	ramData_L->AddGrowableCol( 1 );
	ramData_L->SetFlexibleDirection( wxBOTH );
	ramData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	ramPtr_S = new wxStaticText( ram_P, wxID_ANY, _("Pointer Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	ramPtr_S->Wrap( -1 );
	ramData_L->Add( ramPtr_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ramPtr_SN = new wxSpinCtrl( ram_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	ramPtr_SN->SetMinSize( wxSize( 50,-1 ) );
	
	ramData_L->Add( ramPtr_SN, 0, wxALL|wxEXPAND, 5 );
	
	ramByte_S = new wxStaticText( ram_P, wxID_ANY, _("Base Address"), wxDefaultPosition, wxDefaultSize, 0 );
	ramByte_S->Wrap( -1 );
	ramData_L->Add( ramByte_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ramByte_TXT = new wxTextCtrl( ram_P, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	ramByte_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	ramData_L->Add( ramByte_TXT, 0, wxALL|wxEXPAND, 5 );
	
	ramSize_S = new wxStaticText( ram_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	ramSize_S->Wrap( -1 );
	ramData_L->Add( ramSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ramSize_TXT = new wxTextCtrl( ram_P, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_RIGHT );
	ramSize_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	ramData_L->Add( ramSize_TXT, 0, wxALL|wxEXPAND, 5 );
	
	ram_L->Add( ramData_L, 0, wxEXPAND, 5 );
	
	wxGridSizer* ramAct_L;
	ramAct_L = new wxGridSizer( 0, 2, 0, 0 );
	
	NewRam_B = new wxButton( ram_P, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	ramAct_L->Add( NewRam_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	SetRam_B = new wxButton( ram_P, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	ramAct_L->Add( SetRam_B, 0, wxALL, 5 );
	
	ram_L->Add( ramAct_L, 0, wxEXPAND, 5 );
	
	ram_P->SetSizer( ram_L );
	ram_P->Layout();
	ram_L->Fit( ram_P );
	bsHookScroll->Add( ram_P, 1, wxALL|wxEXPAND, 5 );
	
	hook_SW->SetSizer( bsHookScroll );
	hook_SW->Layout();
	hook_L->Add( hook_SW, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* hookApps_L;
	hookApps_L = new wxFlexGridSizer( 0, 1, 0, 0 );
	hookApps_L->AddGrowableCol( 0 );
	hookApps_L->AddGrowableRow( 1 );
	hookApps_L->SetFlexibleDirection( wxBOTH );
	hookApps_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	wxFlexGridSizer* Update_L;
	Update_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	Update_L->AddGrowableCol( 1 );
	Update_L->SetFlexibleDirection( wxBOTH );
	Update_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	UseHook_S = new wxStaticText( hook_P, wxID_ANY, _("Hook App / File"), wxDefaultPosition, wxDefaultSize, 0 );
	UseHook_S->Wrap( -1 );
	Update_L->Add( UseHook_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString UseHook_DChoices;
	UseHook_D = new wxChoice( hook_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, UseHook_DChoices, 0 );
	UseHook_D->SetSelection( 0 );
	Update_L->Add( UseHook_D, 0, wxALL|wxEXPAND, 5 );
	
	ListApps_S = new wxStaticText( hook_P, wxID_ANY, _("List Applications"), wxDefaultPosition, wxDefaultSize, 0 );
	ListApps_S->Wrap( -1 );
	Update_L->Add( ListApps_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString ListApps_DChoices;
	ListApps_D = new wxChoice( hook_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, ListApps_DChoices, 0 );
	ListApps_D->SetSelection( 0 );
	Update_L->Add( ListApps_D, 0, wxALL|wxEXPAND, 5 );
	
	binUse_B = new wxButton( hook_P, wxID_ANY, _("Select"), wxDefaultPosition, wxDefaultSize, 0 );
	Update_L->Add( binUse_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	ListApps_RB = new wxRadioButton( hook_P, wxID_ANY, _("All Apps"), wxDefaultPosition, wxDefaultSize, 0 );
	Update_L->Add( ListApps_RB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	ListApps_B = new wxButton( hook_P, wxID_ANY, _("Refresh"), wxDefaultPosition, wxDefaultSize, 0 );
	Update_L->Add( ListApps_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	ListWindows_RB = new wxRadioButton( hook_P, wxID_ANY, _("Window Apps"), wxDefaultPosition, wxDefaultSize, 0 );
	ListWindows_RB->SetValue( true ); 
	Update_L->Add( ListWindows_RB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	hookApps_L->Add( Update_L, 1, wxEXPAND, 5 );
	
	ListApps_LC = new wxListCtrl( hook_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ALIGN_LEFT|wxLC_REPORT|wxLC_SINGLE_SEL );
	hookApps_L->Add( ListApps_LC, 0, wxALL|wxEXPAND, 5 );
	
	hook_L->Add( hookApps_L, 0, wxEXPAND, 5 );
	
	hook_P->SetSizer( hook_L );
	hook_P->Layout();
	hook_L->Fit( hook_P );
	cleanFRM_NB->AddPage( hook_P, _("Hook"), true );
	find_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* find_L;
	find_L = new wxFlexGridSizer( 0, 3, 0, 0 );
	find_L->AddGrowableCol( 0 );
	find_L->AddGrowableCol( 1 );
	find_L->AddGrowableCol( 2 );
	find_L->AddGrowableRow( 1 );
	find_L->SetFlexibleDirection( wxBOTH );
	find_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	good_S = new wxStaticText( find_P, wxID_ANY, _("Result is acceptable when"), wxDefaultPosition, wxDefaultSize, 0 );
	good_S->Wrap( -1 );
	find_L->Add( good_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bad_S = new wxStaticText( find_P, wxID_ANY, _("Result is not acceptable when"), wxDefaultPosition, wxDefaultSize, 0 );
	bad_S->Wrap( -1 );
	find_L->Add( bad_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	byte_PB = new wxGauge( find_P, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	find_L->Add( byte_PB, 0, wxALL|wxEXPAND, 5 );
	
	good_SCROLL = new wxScrolledWindow( find_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	good_SCROLL->SetScrollRate( 0, 5 );
	wxBoxSizer* good_L;
	good_L = new wxBoxSizer( wxVERTICAL );
	
	good_L->SetMinSize( wxSize( 150,-1 ) ); 
	wxStaticBoxSizer* goodA_LF;
	goodA_LF = new wxStaticBoxSizer( new wxStaticBox( good_SCROLL, wxID_ANY, _("Address") ), wxVERTICAL );
	
	wxFlexGridSizer* goodA_L;
	goodA_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	goodA_L->AddGrowableCol( 1 );
	goodA_L->SetFlexibleDirection( wxBOTH );
	goodA_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	goodAGT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGT_CB, 0, wxALL, 5 );
	
	goodAGT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodAGT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	goodA_L->Add( goodAGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodAGTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, _(">="), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodAGTE_CB, 0, wxALL, 5 );
	
	goodAGTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodAGTE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	goodA_L->Add( goodAGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodALT_CB = new wxCheckBox( good_SCROLL, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALT_CB, 0, wxALL, 5 );
	
	goodALT_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodALT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	goodA_L->Add( goodALT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodALTE_CB = new wxCheckBox( good_SCROLL, wxID_ANY, _("<="), wxDefaultPosition, wxDefaultSize, 0 );
	goodA_L->Add( goodALTE_CB, 0, wxALL, 5 );
	
	goodALTE_TXT = new wxTextCtrl( good_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	goodALTE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	goodA_L->Add( goodALTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	goodA_LF->Add( goodA_L, 1, wxEXPAND, 5 );
	
	good_L->Add( goodA_LF, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* goodV_FL;
	goodV_FL = new wxStaticBoxSizer( new wxStaticBox( good_SCROLL, goodV_ID, _("Value") ), wxVERTICAL );
	
	goodV_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	goodV_L->AddGrowableCol( 1 );
	goodV_L->SetFlexibleDirection( wxBOTH );
	goodV_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	goodV_FL->Add( goodV_L, 1, wxEXPAND, 5 );
	
	good_L->Add( goodV_FL, 0, wxEXPAND, 5 );
	
	good_SCROLL->SetSizer( good_L );
	good_SCROLL->Layout();
	good_L->Fit( good_SCROLL );
	find_L->Add( good_SCROLL, 1, wxEXPAND | wxALL, 5 );
	
	bad_SCROLL = new wxScrolledWindow( find_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bad_SCROLL->SetScrollRate( 0, 5 );
	wxBoxSizer* bad_L;
	bad_L = new wxBoxSizer( wxVERTICAL );
	
	bad_L->SetMinSize( wxSize( 150,-1 ) ); 
	wxStaticBoxSizer* badA_LF;
	badA_LF = new wxStaticBoxSizer( new wxStaticBox( bad_SCROLL, wxID_ANY, _("Address") ), wxVERTICAL );
	
	wxFlexGridSizer* badA_L;
	badA_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	badA_L->AddGrowableCol( 1 );
	badA_L->SetFlexibleDirection( wxBOTH );
	badA_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	badAGT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGT_CB, 0, wxALL, 5 );
	
	badAGT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badAGT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	badA_L->Add( badAGT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badAGTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, _(">="), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badAGTE_CB, 0, wxALL, 5 );
	
	badAGTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badAGTE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	badA_L->Add( badAGTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badALT_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALT_CB, 0, wxALL, 5 );
	
	badALT_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badALT_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	badA_L->Add( badALT_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badALTE_CB = new wxCheckBox( bad_SCROLL, wxID_ANY, _("<="), wxDefaultPosition, wxDefaultSize, 0 );
	badA_L->Add( badALTE_CB, 0, wxALL, 5 );
	
	badALTE_TXT = new wxTextCtrl( bad_SCROLL, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	badALTE_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	badA_L->Add( badALTE_TXT, 0, wxALL|wxEXPAND, 5 );
	
	badA_LF->Add( badA_L, 1, wxEXPAND, 5 );
	
	bad_L->Add( badA_LF, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* badV_FL;
	badV_FL = new wxStaticBoxSizer( new wxStaticBox( bad_SCROLL, badV_ID, _("Value") ), wxVERTICAL );
	
	badV_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	badV_L->AddGrowableCol( 1 );
	badV_L->SetFlexibleDirection( wxBOTH );
	badV_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	badV_FL->Add( badV_L, 1, wxEXPAND, 5 );
	
	bad_L->Add( badV_FL, 0, wxEXPAND, 5 );
	
	bad_SCROLL->SetSizer( bad_L );
	bad_SCROLL->Layout();
	bad_L->Fit( bad_SCROLL );
	find_L->Add( bad_SCROLL, 1, wxEXPAND | wxALL, 5 );
	
	findOptions_P = new wxPanel( find_P, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxFlexGridSizer* findOptions1_L;
	findOptions1_L = new wxFlexGridSizer( 0, 1, 0, 0 );
	findOptions1_L->AddGrowableCol( 0 );
	findOptions1_L->AddGrowableRow( 4 );
	findOptions1_L->SetFlexibleDirection( wxBOTH );
	findOptions1_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	out_S = new wxStaticText( findOptions_P, wxID_ANY, _("Results: 0"), wxDefaultPosition, wxDefaultSize, 0 );
	out_S->Wrap( -1 );
	findOptions1_L->Add( out_S, 0, wxALL, 5 );
	
	findOptions_LINE1 = new wxStaticLine( findOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	findOptions1_L->Add( findOptions_LINE1, 0, wxEXPAND | wxALL, 5 );
	
	wxGridSizer* findOptions_LG;
	findOptions_LG = new wxGridSizer( 0, 3, 0, 0 );
	
	findOptions_LG->SetMinSize( wxSize( -1,100 ) ); 
	dump_B = new wxButton( findOptions_P, wxID_ANY, _("D"), wxDefaultPosition, wxDefaultSize, 0 );
	dump_B->SetToolTip( _("Dump") );
	dump_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( dump_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	find_B = new wxButton( findOptions_P, wxID_ANY, _("S"), wxDefaultPosition, wxDefaultSize, 0 );
	find_B->SetDefault(); 
	find_B->SetToolTip( _("Search") );
	find_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( find_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findUndo_B = new wxButton( findOptions_P, wxID_ANY, _("U"), wxDefaultPosition, wxDefaultSize, 0 );
	findUndo_B->SetToolTip( _("Undo Search") );
	findUndo_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findUndo_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findEqual_B = new wxButton( findOptions_P, wxID_ANY, _("="), wxDefaultPosition, wxDefaultSize, 0 );
	findEqual_B->SetToolTip( _("Equal To") );
	findEqual_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findEqual_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findGTE_B = new wxButton( findOptions_P, wxID_ANY, _(">="), wxDefaultPosition, wxDefaultSize, 0 );
	findGTE_B->SetToolTip( _("More Than or Equal To") );
	findGTE_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findGTE_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findGT_B = new wxButton( findOptions_P, wxID_ANY, _(">"), wxDefaultPosition, wxDefaultSize, 0 );
	findGT_B->SetToolTip( _("More Than") );
	findGT_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findGT_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findNOTE_B = new wxButton( findOptions_P, wxID_ANY, _("!="), wxDefaultPosition, wxDefaultSize, 0 );
	findNOTE_B->SetToolTip( _("Not Equal To") );
	findNOTE_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findNOTE_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findLTE_B = new wxButton( findOptions_P, wxID_ANY, _("<="), wxDefaultPosition, wxDefaultSize, 0 );
	findLTE_B->SetToolTip( _("Less Than or Equal To") );
	findLTE_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findLTE_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findLT_B = new wxButton( findOptions_P, wxID_ANY, _("<"), wxDefaultPosition, wxDefaultSize, 0 );
	findLT_B->SetToolTip( _("Less Than") );
	findLT_B->SetMinSize( wxSize( 30,-1 ) );
	
	findOptions_LG->Add( findLT_B, 1, wxALIGN_CENTER|wxALL, 5 );
	
	findOptions1_L->Add( findOptions_LG, 0, wxEXPAND, 5 );
	
	findOptions_LINE2 = new wxStaticLine( findOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	findOptions1_L->Add( findOptions_LINE2, 0, wxEXPAND | wxALL, 5 );
	
	findOptions_SW = new wxScrolledWindow( findOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	findOptions_SW->SetScrollRate( 0, 5 );
	wxFlexGridSizer* findOptions2_L;
	findOptions2_L = new wxFlexGridSizer( 0, 1, 0, 0 );
	findOptions2_L->AddGrowableCol( 0 );
	findOptions2_L->SetFlexibleDirection( wxBOTH );
	findOptions2_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	findUse_S = new wxStaticText( findOptions_SW, wxID_ANY, _("Compare To"), wxDefaultPosition, wxDefaultSize, 0 );
	findUse_S->Wrap( -1 );
	findOptions2_L->Add( findUse_S, 0, wxALL, 5 );
	
	wxString findUse_DChoices[] = { _("Dump") };
	int findUse_DNChoices = sizeof( findUse_DChoices ) / sizeof( wxString );
	findUse_D = new wxChoice( findOptions_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, findUse_DNChoices, findUse_DChoices, 0 );
	findUse_D->SetSelection( 0 );
	findUse_D->SetMinSize( wxSize( 50,-1 ) );
	
	findOptions2_L->Add( findUse_D, 0, wxALL|wxEXPAND, 5 );
	
	findRam_S = new wxStaticText( findOptions_SW, wxID_ANY, _("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	findRam_S->Wrap( -1 );
	findOptions2_L->Add( findRam_S, 0, wxALL, 5 );
	
	wxArrayString findRam_DChoices;
	findRam_D = new wxChoice( findOptions_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, findRam_DChoices, 0 );
	findRam_D->SetSelection( 0 );
	findRam_D->SetMinSize( wxSize( 50,-1 ) );
	
	findOptions2_L->Add( findRam_D, 0, wxALL|wxEXPAND, 5 );
	
	findType_S = new wxStaticText( findOptions_SW, wxID_ANY, _("Search Type"), wxDefaultPosition, wxDefaultSize, 0 );
	findType_S->Wrap( -1 );
	findOptions2_L->Add( findType_S, 0, wxALL, 5 );
	
	wxString findType_DChoices[] = { _("Dump"), _("Equal To ( = )"), _("Not Equal To ( != )"), _("More Than ( > )"), _("More Than or Equal To ( >= )"), _("Less Than ( < )"), _("Less Than or Equal To  ( <= )") };
	int findType_DNChoices = sizeof( findType_DChoices ) / sizeof( wxString );
	findType_D = new wxChoice( findOptions_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, findType_DNChoices, findType_DChoices, 0 );
	findType_D->SetSelection( 0 );
	findType_D->SetMinSize( wxSize( 50,-1 ) );
	
	findOptions2_L->Add( findType_D, 0, wxALL|wxEXPAND, 5 );
	
	findSize_S = new wxStaticText( findOptions_SW, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	findSize_S->Wrap( -1 );
	findOptions2_L->Add( findSize_S, 0, wxALL, 5 );
	
	wxArrayString findSize_DChoices;
	findSize_D = new wxChoice( findOptions_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, findSize_DChoices, 0 );
	findSize_D->SetSelection( 0 );
	findSize_D->SetMinSize( wxSize( 50,-1 ) );
	
	findOptions2_L->Add( findSize_D, 0, wxALL|wxEXPAND, 5 );
	
	findMode_S = new wxStaticText( findOptions_SW, wxID_ANY, _("Value Type"), wxDefaultPosition, wxDefaultSize, 0 );
	findMode_S->Wrap( -1 );
	findOptions2_L->Add( findMode_S, 0, wxALL, 5 );
	
	wxArrayString findMode_DChoices;
	findMode_D = new wxChoice( findOptions_SW, wxID_ANY, wxDefaultPosition, wxDefaultSize, findMode_DChoices, 0 );
	findMode_D->SetSelection( 0 );
	findMode_D->SetMinSize( wxSize( 50,-1 ) );
	
	findOptions2_L->Add( findMode_D, 0, wxALL|wxEXPAND, 5 );
	
	findOptions_SW->SetSizer( findOptions2_L );
	findOptions_SW->Layout();
	findOptions2_L->Fit( findOptions_SW );
	findOptions1_L->Add( findOptions_SW, 0, wxEXPAND, 5 );
	
	findOptions_P->SetSizer( findOptions1_L );
	findOptions_P->Layout();
	findOptions1_L->Fit( findOptions_P );
	find_L->Add( findOptions_P, 0, wxALL|wxEXPAND, 5 );
	
	find_P->SetSizer( find_L );
	find_P->Layout();
	find_L->Fit( find_P );
	cleanFRM_NB->AddPage( find_P, _("Search"), false );
	out_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* out_L;
	out_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	out_L->AddGrowableCol( 0 );
	out_L->AddGrowableRow( 0 );
	out_L->SetFlexibleDirection( wxBOTH );
	out_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	out_LC = new wxListCtrl( out_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON|wxLC_REPORT|wxLC_SINGLE_SEL );
	out_L->Add( out_LC, 0, wxALL|wxEXPAND, 5 );
	
	outData_P = new wxPanel( out_P, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), wxTAB_TRAVERSAL );
	outData_P->SetMinSize( wxSize( 200,-1 ) );
	outData_P->SetMaxSize( wxSize( 200,-1 ) );
	
	wxFlexGridSizer* outData1_L;
	outData1_L = new wxFlexGridSizer( 0, 1, 0, 0 );
	outData1_L->AddGrowableCol( 0 );
	outData1_L->AddGrowableRow( 1 );
	outData1_L->SetFlexibleDirection( wxBOTH );
	outData1_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	outData1_L->SetMinSize( wxSize( 200,-1 ) ); 
	outEdit_CB = new wxCheckBox( outData_P, wxID_ANY, _("Use selected address in editor"), wxDefaultPosition, wxDefaultSize, 0 );
	outEdit_CB->SetValue(true); 
	outData1_L->Add( outEdit_CB, 0, wxALL, 5 );
	
	outData_LC = new wxListCtrl( outData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	outData1_L->Add( outData_LC, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* outData2_L;
	outData2_L = new wxStaticBoxSizer( new wxStaticBox( outData_P, wxID_ANY, _("Hack") ), wxVERTICAL );
	
	wxFlexGridSizer* outData3_L;
	outData3_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	outData3_L->AddGrowableCol( 1 );
	outData3_L->SetFlexibleDirection( wxBOTH );
	outData3_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	outRAM_S = new wxStaticText( outData_P, wxID_ANY, _("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	outRAM_S->Wrap( -1 );
	outData3_L->Add( outRAM_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString outRAM_DChoices;
	outRAM_D = new wxChoice( outData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, outRAM_DChoices, 0 );
	outRAM_D->SetSelection( 0 );
	outRAM_D->SetMinSize( wxSize( 50,-1 ) );
	
	outData3_L->Add( outRAM_D, 0, wxALL|wxEXPAND, 5 );
	
	outSize_S = new wxStaticText( outData_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	outSize_S->Wrap( -1 );
	outData3_L->Add( outSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString outSize_DChoices;
	outSize_D = new wxChoice( outData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, outSize_DChoices, 0 );
	outSize_D->SetSelection( 0 );
	outData3_L->Add( outSize_D, 0, wxALL|wxEXPAND, 5 );
	
	outByte_S = new wxStaticText( outData_P, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	outByte_S->Wrap( -1 );
	outData3_L->Add( outByte_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	outByte_TXT = new wxTextCtrl( outData_P, outByte_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	outByte_TXT->SetMaxLength( 16 ); 
	outData3_L->Add( outByte_TXT, 0, wxALL|wxEXPAND, 5 );
	
	outMode_S = new wxStaticText( outData_P, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	outMode_S->Wrap( -1 );
	outData3_L->Add( outMode_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString outMode_DChoices[] = { _("HexaDecimal"), _("Unsigned Integer"), _("Float"), _("Signed Integer") };
	int outMode_DNChoices = sizeof( outMode_DChoices ) / sizeof( wxString );
	outMode_D = new wxChoice( outData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, outMode_DNChoices, outMode_DChoices, 0 );
	outMode_D->SetSelection( 0 );
	outData3_L->Add( outMode_D, 0, wxALL|wxEXPAND, 5 );
	
	outValue_S = new wxStaticText( outData_P, wxID_ANY, _("Value"), wxDefaultPosition, wxDefaultSize, 0 );
	outValue_S->Wrap( -1 );
	outData3_L->Add( outValue_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	outValue_TXT = new wxTextCtrl( outData_P, outValue_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	outData3_L->Add( outValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	outData2_L->Add( outData3_L, 1, wxEXPAND, 5 );
	
	wxGridSizer* outAct_L;
	outAct_L = new wxGridSizer( 0, 2, 0, 0 );
	
	SetOut_B = new wxButton( outData_P, wxID_ANY, _("Set"), wxDefaultPosition, wxDefaultSize, 0 );
	outAct_L->Add( SetOut_B, 0, wxALIGN_CENTER, 5 );
	
	DelOut_B = new wxButton( outData_P, wxID_ANY, _("Del"), wxDefaultPosition, wxDefaultSize, 0 );
	outAct_L->Add( DelOut_B, 0, wxALIGN_CENTER, 5 );
	
	outData2_L->Add( outAct_L, 0, wxEXPAND, 5 );
	
	outData1_L->Add( outData2_L, 0, wxEXPAND|wxTOP, 5 );
	
	outData_P->SetSizer( outData1_L );
	outData_P->Layout();
	out_L->Add( outData_P, 0, wxEXPAND | wxALL, 5 );
	
	out_P->SetSizer( out_L );
	out_P->Layout();
	out_L->Fit( out_P );
	cleanFRM_NB->AddPage( out_P, _("Results"), false );
	edit_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	editShow_B = new wxButton( edit_P, wxID_ANY, _("+"), wxDefaultPosition, wxDefaultSize, 0 );
	editShow_B->SetMinSize( wxSize( 30,-1 ) );
	
	bSizer13->Add( editShow_B, 0, wxALL, 5 );
	
	editUpdate_S = new wxStaticText( edit_P, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	editUpdate_S->Wrap( -1 );
	bSizer13->Add( editUpdate_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString editUpdate_DChoices;
	editUpdate_D = new wxChoice( edit_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, editUpdate_DChoices, 0 );
	editUpdate_D->SetSelection( 0 );
	bSizer13->Add( editUpdate_D, 1, wxALL, 5 );
	
	bSizer33->Add( bSizer13, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	editOptions_P = new wxPanel( edit_P, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* editOptions_L;
	editOptions_L = new wxFlexGridSizer( 1, 2, 0, 0 );
	editOptions_L->AddGrowableCol( 1 );
	editOptions_L->SetFlexibleDirection( wxBOTH );
	editOptions_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	editOptions_L->SetMinSize( wxSize( 175,-1 ) ); 
	editRam_S = new wxStaticText( editOptions_P, wxID_ANY, _("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	editRam_S->Wrap( -1 );
	editOptions_L->Add( editRam_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString editRam_DChoices;
	editRam_D = new wxChoice( editOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, editRam_DChoices, 0 );
	editRam_D->SetSelection( 0 );
	editRam_D->SetMinSize( wxSize( 50,-1 ) );
	
	editOptions_L->Add( editRam_D, 0, wxALL|wxEXPAND, 5 );
	
	editGet_B = new wxButton( editOptions_P, editGet_ID, _("Read"), wxDefaultPosition, wxDefaultSize, 0 );
	editOptions_L->Add( editGet_B, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	editGet_TXT = new wxTextCtrl( editOptions_P, editGet_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	editGet_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	editOptions_L->Add( editGet_TXT, 0, wxALL|wxEXPAND, 5 );
	
	editSet_B = new wxButton( editOptions_P, wxID_ANY, _("Write"), wxDefaultPosition, wxDefaultSize, 0 );
	editOptions_L->Add( editSet_B, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	editSet_TXT = new wxTextCtrl( editOptions_P, editSet_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	editOptions_L->Add( editSet_TXT, 0, wxALL, 5 );
	
	bSizer29->Add( editOptions_L, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer19;
	sbSizer19 = new wxStaticBoxSizer( new wxStaticBox( editOptions_P, wxID_ANY, _("Value") ), wxVERTICAL );
	
	editValue_TXT = new wxTextCtrl( editOptions_P, editValue_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	editValue_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	sbSizer19->Add( editValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* fgSizer34;
	fgSizer34 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer34->AddGrowableCol( 1 );
	fgSizer34->SetFlexibleDirection( wxBOTH );
	fgSizer34->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	editSize_S = new wxStaticText( editOptions_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	editSize_S->Wrap( -1 );
	fgSizer34->Add( editSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString editSize_DChoices;
	editSize_D = new wxChoice( editOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, editSize_DChoices, 0 );
	editSize_D->SetSelection( 0 );
	editSize_D->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer34->Add( editSize_D, 0, wxALL|wxEXPAND, 5 );
	
	editMode_S = new wxStaticText( editOptions_P, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	editMode_S->Wrap( -1 );
	fgSizer34->Add( editMode_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString editMode_DChoices;
	editMode_D = new wxChoice( editOptions_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, editMode_DChoices, 0 );
	editMode_D->SetSelection( 0 );
	editMode_D->SetMinSize( wxSize( 50,-1 ) );
	
	fgSizer34->Add( editMode_D, 0, wxALL|wxEXPAND, 5 );
	
	sbSizer19->Add( fgSizer34, 1, wxEXPAND, 5 );
	
	bSizer29->Add( sbSizer19, 0, wxEXPAND|wxRIGHT, 5 );
	
	editOptions_P->SetSizer( bSizer29 );
	editOptions_P->Layout();
	bSizer29->Fit( editOptions_P );
	bSizer36->Add( editOptions_P, 0, wxEXPAND, 5 );
	
	edit_G = new wxGrid( edit_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	edit_G->CreateGrid( 0, 18 );
	edit_G->EnableEditing( true );
	edit_G->EnableGridLines( true );
	edit_G->EnableDragGridSize( false );
	edit_G->SetMargins( 0, 0 );
	
	// Columns
	edit_G->SetColSize( 0, 30 );
	edit_G->SetColSize( 1, 30 );
	edit_G->SetColSize( 2, 30 );
	edit_G->SetColSize( 3, 30 );
	edit_G->SetColSize( 4, 30 );
	edit_G->SetColSize( 5, 30 );
	edit_G->SetColSize( 6, 30 );
	edit_G->SetColSize( 7, 30 );
	edit_G->SetColSize( 8, 30 );
	edit_G->SetColSize( 9, 30 );
	edit_G->SetColSize( 10, 30 );
	edit_G->SetColSize( 11, 30 );
	edit_G->SetColSize( 12, 30 );
	edit_G->SetColSize( 13, 30 );
	edit_G->SetColSize( 14, 30 );
	edit_G->SetColSize( 15, 30 );
	edit_G->SetColSize( 16, 100 );
	edit_G->SetColSize( 17, 100 );
	edit_G->EnableDragColMove( false );
	edit_G->EnableDragColSize( true );
	edit_G->SetColLabelSize( 20 );
	edit_G->SetColLabelValue( 0, _("0") );
	edit_G->SetColLabelValue( 1, _("1") );
	edit_G->SetColLabelValue( 2, _("2") );
	edit_G->SetColLabelValue( 3, _("3") );
	edit_G->SetColLabelValue( 4, _("4") );
	edit_G->SetColLabelValue( 5, _("5") );
	edit_G->SetColLabelValue( 6, _("6") );
	edit_G->SetColLabelValue( 7, _("7") );
	edit_G->SetColLabelValue( 8, _("8") );
	edit_G->SetColLabelValue( 9, _("9") );
	edit_G->SetColLabelValue( 10, _("A") );
	edit_G->SetColLabelValue( 11, _("B") );
	edit_G->SetColLabelValue( 12, _("C") );
	edit_G->SetColLabelValue( 13, _("D") );
	edit_G->SetColLabelValue( 14, _("E") );
	edit_G->SetColLabelValue( 15, _("F") );
	edit_G->SetColLabelValue( 16, _("Ascii") );
	edit_G->SetColLabelValue( 17, _("Unicode") );
	edit_G->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	edit_G->EnableDragRowSize( true );
	edit_G->SetRowLabelSize( 150 );
	edit_G->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	edit_G->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer36->Add( edit_G, 1, wxEXPAND, 5 );
	
	bSizer33->Add( bSizer36, 1, wxEXPAND, 5 );
	
	edit_P->SetSizer( bSizer33 );
	edit_P->Layout();
	bSizer33->Fit( edit_P );
	cleanFRM_NB->AddPage( edit_P, _("Editor"), false );
	dbp_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* dbpArea_L;
	dbpArea_L = new wxStaticBoxSizer( new wxStaticBox( dbp_P, wxID_ANY, _("Region") ), wxVERTICAL );
	
	wxGridSizer* dbpArea_LG;
	dbpArea_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	dbpAreaAll_RB = new wxRadioButton( dbp_P, wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpAreaAll_RB->SetValue( true ); 
	dbpArea_LG->Add( dbpAreaAll_RB, 0, wxALL, 5 );
	
	dbpAreaCheck_RB = new wxRadioButton( dbp_P, wxID_ANY, _("Checked"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpArea_LG->Add( dbpAreaCheck_RB, 0, wxALL, 5 );
	
	dbpArea_L->Add( dbpArea_LG, 0, wxEXPAND, 5 );
	
	dbpAreaCB_P = new wxPanel( dbp_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	dbpAreaCB_LG = new wxGridSizer( 0, 5, 0, 0 );
	
	dbpAreaCB_P->SetSizer( dbpAreaCB_LG );
	dbpAreaCB_P->Layout();
	dbpAreaCB_LG->Fit( dbpAreaCB_P );
	dbpArea_L->Add( dbpAreaCB_P, 0, wxEXPAND, 5 );
	
	bSizer14->Add( dbpArea_L, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* dbpMain_L;
	dbpMain_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dbpMain_L->AddGrowableCol( 1 );
	dbpMain_L->SetFlexibleDirection( wxBOTH );
	dbpMain_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dbpName_S = new wxStaticText( dbp_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpName_S->Wrap( -1 );
	dbpMain_L->Add( dbpName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dbpName_TXT = new wxTextCtrl( dbp_P, dbpName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dbpMain_L->Add( dbpName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dbpFile_S = new wxStaticText( dbp_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpFile_S->Wrap( -1 );
	dbpMain_L->Add( dbpFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dbpFile_TXT = new wxTextCtrl( dbp_P, dbpFile_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dbpMain_L->Add( dbpFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dbpSID_S = new wxStaticText( dbp_P, wxID_ANY, _("Serial ID"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpSID_S->Wrap( -1 );
	dbpMain_L->Add( dbpSID_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dbpSID_TXT = new wxTextCtrl( dbp_P, dbpSID_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dbpMain_L->Add( dbpSID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dbpPID_S = new wxStaticText( dbp_P, wxID_ANY, _("App / File ID"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpPID_S->Wrap( -1 );
	dbpMain_L->Add( dbpPID_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dbpPID_TXT = new wxTextCtrl( dbp_P, dbpPID_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dbpMain_L->Add( dbpPID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	bSizer14->Add( dbpMain_L, 0, wxEXPAND, 5 );
	
	dbpNotes_S = new wxStaticText( dbp_P, wxID_ANY, _("Notes"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpNotes_S->Wrap( -1 );
	bSizer14->Add( dbpNotes_S, 0, wxALL, 5 );
	
	dbpNotes_TA = new wxTextCtrl( dbp_P, dbpNotes_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_DONTWRAP|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	bSizer14->Add( dbpNotes_TA, 1, wxALL|wxEXPAND, 5 );
	
	wxGridSizer* dbpAct_LG;
	dbpAct_LG = new wxGridSizer( 0, 4, 0, 0 );
	
	NewDBP_B = new wxButton( dbp_P, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpAct_LG->Add( NewDBP_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	SetDBP_B = new wxButton( dbp_P, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpAct_LG->Add( SetDBP_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	LoadDBP_B = new wxButton( dbp_P, wxID_ANY, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpAct_LG->Add( LoadDBP_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	SaveDBP_B = new wxButton( dbp_P, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	dbpAct_LG->Add( SaveDBP_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	bSizer14->Add( dbpAct_LG, 0, wxEXPAND, 5 );
	
	dbp_P->SetSizer( bSizer14 );
	dbp_P->Layout();
	bSizer14->Fit( dbp_P );
	cleanFRM_NB->AddPage( dbp_P, _("Profile"), false );
	tree_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	NewHack_B = new wxButton( tree_P, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( NewHack_B, 0, wxALL, 5 );
	
	NewHack_CB = new wxCheckBox( tree_P, wxID_ANY, _("Chilld"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( NewHack_CB, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxString NewHack_DChoices[] = { _("Start"), _("Before"), _("After"), _("End") };
	int NewHack_DNChoices = sizeof( NewHack_DChoices ) / sizeof( wxString );
	NewHack_D = new wxChoice( tree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, NewHack_DNChoices, NewHack_DChoices, 0 );
	NewHack_D->SetSelection( 3 );
	bSizer15->Add( NewHack_D, 1, wxALIGN_CENTER|wxLEFT|wxRIGHT, 5 );
	
	SetCode_B = new wxButton( tree_P, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( SetCode_B, 0, wxALL, 5 );
	
	DelHack_B = new wxButton( tree_P, wxID_ANY, _("Del"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	bSizer15->Add( DelHack_B, 0, wxALL, 5 );
	
	bSizer141->Add( bSizer15, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	tree_T = new wxTreeCtrl( tree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS|wxTR_SINGLE );
	tree_T->SetToolTip( _("When a Hack / Node is selected the following actions can be peformed with the CTRL key held down:\nAdd = Add Hack / Node to List (List box decides position)\nMinus = Remove Hack / Node\nArrow = Move Hack / Node in that direction") );
	
	bSizer161->Add( tree_T, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	bSizer16->SetMinSize( wxSize( 200,-1 ) ); 
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	mHackName_S = new wxStaticText( tree_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	mHackName_S->Wrap( -1 );
	bSizer17->Add( mHackName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	mHackName_TXT = new wxTextCtrl( tree_P, mHackName_ID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( mHackName_TXT, 1, wxALL, 5 );
	
	mUseHack_CB = new wxCheckBox( tree_P, wxID_ANY, _("Use"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( mUseHack_CB, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	bSizer16->Add( bSizer17, 0, wxEXPAND, 5 );
	
	mHackBreak = new wxStaticLine( tree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer16->Add( mHackBreak, 0, wxEXPAND | wxALL, 5 );
	
	mShowHack_B = new wxButton( tree_P, wxID_ANY, _("Modify Codelist"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( mShowHack_B, 0, wxALL, 5 );
	
	code_LC = new wxListCtrl( tree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer16->Add( code_LC, 1, wxALL|wxEXPAND, 5 );
	
	bSizer161->Add( bSizer16, 1, wxEXPAND, 5 );
	
	bSizer141->Add( bSizer161, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );
	
	GetHacks_B = new wxButton( tree_P, wxID_ANY, _("Load"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( GetHacks_B, 0, wxALL, 5 );
	
	SetHacks_B = new wxButton( tree_P, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( SetHacks_B, 0, wxALL, 5 );
	
	MoveHack_B = new wxButton( tree_P, wxID_ANY, _("Move"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( MoveHack_B, 0, wxALL, 5 );
	
	wxString MoveHack_DChoices[] = { _("Up"), _("Down"), _("Left"), _("Right") };
	int MoveHack_DNChoices = sizeof( MoveHack_DChoices ) / sizeof( wxString );
	MoveHack_D = new wxChoice( tree_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, MoveHack_DNChoices, MoveHack_DChoices, 0 );
	MoveHack_D->SetSelection( 0 );
	MoveHack_D->SetMinSize( wxSize( 45,-1 ) );
	
	bSizer19->Add( MoveHack_D, 1, wxALIGN_BOTTOM|wxALL, 6 );
	
	bSizer141->Add( bSizer19, 0, wxEXPAND, 5 );
	
	tree_P->SetSizer( bSizer141 );
	tree_P->Layout();
	bSizer141->Fit( tree_P );
	cleanFRM_NB->AddPage( tree_P, _("Hack"), false );
	about_P = new wxPanel( cleanFRM_NB, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText10 = new wxStaticText( about_P, wxID_ANY, _("HackerEX (Awsdert, Viper)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText10->Wrap( -1 );
	bSizer4->Add( m_staticText10, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink3 = new wxHyperlinkCtrl( about_P, wxID_ANY, _("Awsdert Blog"), wxT("http://awsdert.wordpress.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink3, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_hyperlink2 = new wxHyperlinkCtrl( about_P, wxID_ANY, _("Google Code Project"), wxT("http://code.google.com/p/renegade"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink2, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink5 = new wxHyperlinkCtrl( about_P, wxID_ANY, _("SourceForge Project"), wxT("https://sourceforge.net/projects/hackerex/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink5, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_hyperlink4 = new wxHyperlinkCtrl( about_P, wxID_ANY, _("GPLv3 Quick Guide"), wxT("http://www.gnu.org/licenses/quick-guide-gplv3.html"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink4, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText9 = new wxStaticText( about_P, wxID_ANY, _("Renegade64 / RenegadeEx (Viper)"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText9->Wrap( -1 );
	bSizer4->Add( m_staticText9, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( about_P, wxID_ANY, _("Website"), wxT("http://viper.shadowflareindustries.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	bSizer4->Add( m_hyperlink1, 0, wxALL|wxEXPAND, 5 );
	
	about_P->SetSizer( bSizer4 );
	about_P->Layout();
	bSizer4->Fit( about_P );
	cleanFRM_NB->AddPage( about_P, _("About"), false );
	
	cleanFRM_L->Add( cleanFRM_NB, 1, wxEXPAND, 0 );
	
	this->SetSizer( cleanFRM_L );
	this->Layout();
	SB = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanFRM::GOnClose ) );
	this->Connect( wxEVT_IDLE, wxIdleEventHandler( cleanFRM::GOnIdle ) );
	this->Connect( mListOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::ListOrg_BOnClick ) );
	this->Connect( mLoadOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadOrg_OnClick ) );
	this->Connect( mSaveOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSaveOrg_OnClick ) );
	this->Connect( mSetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetOrg_OnClick ) );
	orgName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	orgFile_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	this->Connect( mListPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mListPFM_OnClick ) );
	this->Connect( mLoadPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadPFM_OnClick ) );
	this->Connect( mSavePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSavePFM_OnClick ) );
	this->Connect( mSetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetPFM_OnClick ) );
	pfmName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	pfmFile_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	this->Connect( mListBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mListBin_OnClick ) );
	this->Connect( mLoadBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadBin_OnClick ) );
	this->Connect( mSaveBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSaveBin_OnClick ) );
	this->Connect( mSetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetBin_OnClick ) );
	binName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	binFile_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	binPath_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binPath_BOnClick ), NULL, this );
	binPath_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::path_TXTOnChange ), NULL, this );
	binBind_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binBind_BOnClick ), NULL, this );
	binBind_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	binHook_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binHook_BOnClick ), NULL, this );
	binLaunch_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binLaunch_BOnClick ), NULL, this );
	ramName_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::ramName_DOnChoice ), NULL, this );
	ramName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	ramByte_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	ramSize_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	NewRam_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewRam_BOnClick ), NULL, this );
	SetRam_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetRam_BOnClick ), NULL, this );
	UseHook_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::UseHook_DOnChoice ), NULL, this );
	ListApps_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::ListApps_DOnChoice ), NULL, this );
	binUse_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binUse_BOnClick ), NULL, this );
	ListApps_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::ListApps_BOnClick ), NULL, this );
	goodAGT_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodAGTE_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodALT_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodALTE_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badAGT_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badAGTE_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badALT_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badALTE_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	dump_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::dump_BOnClick ), NULL, this );
	find_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::find_BOnClick ), NULL, this );
	findUndo_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findUndo_BOnClick ), NULL, this );
	findEqual_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findEqual_BOnClick ), NULL, this );
	findGTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findGTE_BOnClick ), NULL, this );
	findGT_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findGT_BOnClick ), NULL, this );
	findNOTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findNOTE_BOnClick ), NULL, this );
	findLTE_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findLTE_BOnClick ), NULL, this );
	findLT_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findLT_BOnClick ), NULL, this );
	findUse_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::compare_DOnChoice ), NULL, this );
	findMode_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::findMode_DOnChoice ), NULL, this );
	outData_LC->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cleanFRM::outData_LCOnSelect ), NULL, this );
	outByte_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	outValue_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::out_TXTOnChange ), NULL, this );
	SetOut_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetOut_BOnClick ), NULL, this );
	DelOut_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::DelOut_BOnClick ), NULL, this );
	editShow_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editShow_BOnClick ), NULL, this );
	editUpdate_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::editUpdate_DOnChoice ), NULL, this );
	editGet_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editGet_BOnClick ), NULL, this );
	editGet_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	editSet_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editSet_BOnClick ), NULL, this );
	editSet_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	editValue_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::edit_TXTOnChange ), NULL, this );
	edit_G->Connect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( cleanFRM::edit_GOnEditEnd ), NULL, this );
	edit_G->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( cleanFRM::edit_GOnEditBegin ), NULL, this );
	edit_G->Connect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( cleanFRM::edit_GOnSelect ), NULL, this );
	edit_G->Connect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( cleanFRM::edit_GOnMouseWheel ), NULL, this );
	dbpAreaAll_RB->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanFRM::dbpArea_RBOnChange ), NULL, this );
	dbpAreaCheck_RB->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanFRM::dbpArea_RBOnChange ), NULL, this );
	dbpName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	dbpFile_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	dbpPID_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte16_TXTOnChange ), NULL, this );
	NewDBP_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewDBP_BOnClick ), NULL, this );
	SetDBP_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetDBP_BOnClick ), NULL, this );
	LoadDBP_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::LoadDBP_BOnClick ), NULL, this );
	SaveDBP_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SaveDBP_BOnClick ), NULL, this );
	NewHack_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewHack_BOnClick ), NULL, this );
	SetCode_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetCode_BOnClick ), NULL, this );
	DelHack_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::DelHack_BOnClick ), NULL, this );
	tree_T->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( cleanFRM::tree_TOnKeyDown ), NULL, this );
	tree_T->Connect( wxEVT_KEY_UP, wxKeyEventHandler( cleanFRM::tree_TOnKeyUp ), NULL, this );
	tree_T->Connect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( cleanFRM::tree_TOnBeginDrag ), NULL, this );
	tree_T->Connect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( cleanFRM::tree_TOnEndDrag ), NULL, this );
	tree_T->Connect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( cleanFRM::tree_TOnSelect ), NULL, this );
	mHackName_TXT->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	mUseHack_CB->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cleanFRM::UseHack_BOnClick ), NULL, this );
	mShowHack_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::mShowHack_OnClick ), NULL, this );
	GetHacks_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::GetHacks_BOnClick ), NULL, this );
	SetHacks_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetHacks_BOnClick ), NULL, this );
	MoveHack_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::MoveHack_BOnClick ), NULL, this );
}

cleanFRM::~cleanFRM()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanFRM::GOnClose ) );
	this->Disconnect( wxEVT_IDLE, wxIdleEventHandler( cleanFRM::GOnIdle ) );
	this->Disconnect( mListOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::ListOrg_BOnClick ) );
	this->Disconnect( mLoadOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadOrg_OnClick ) );
	this->Disconnect( mSaveOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSaveOrg_OnClick ) );
	this->Disconnect( mSetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetOrg_OnClick ) );
	orgName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	orgFile_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	this->Disconnect( mListPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mListPFM_OnClick ) );
	this->Disconnect( mLoadPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadPFM_OnClick ) );
	this->Disconnect( mSavePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSavePFM_OnClick ) );
	this->Disconnect( mSetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetPFM_OnClick ) );
	pfmName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	pfmFile_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	this->Disconnect( mListBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mListBin_OnClick ) );
	this->Disconnect( mLoadBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mLoadBin_OnClick ) );
	this->Disconnect( mSaveBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSaveBin_OnClick ) );
	this->Disconnect( mSetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanFRM::mSetBin_OnClick ) );
	binName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	binFile_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	binPath_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binPath_BOnClick ), NULL, this );
	binPath_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::path_TXTOnChange ), NULL, this );
	binBind_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binBind_BOnClick ), NULL, this );
	binBind_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	binHook_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binHook_BOnClick ), NULL, this );
	binLaunch_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binLaunch_BOnClick ), NULL, this );
	ramName_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::ramName_DOnChoice ), NULL, this );
	ramName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	ramByte_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	ramSize_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	NewRam_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewRam_BOnClick ), NULL, this );
	SetRam_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetRam_BOnClick ), NULL, this );
	UseHook_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::UseHook_DOnChoice ), NULL, this );
	ListApps_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::ListApps_DOnChoice ), NULL, this );
	binUse_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::binUse_BOnClick ), NULL, this );
	ListApps_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::ListApps_BOnClick ), NULL, this );
	goodAGT_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodAGTE_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodALT_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	goodALTE_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badAGT_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badAGTE_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badALT_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	badALTE_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	dump_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::dump_BOnClick ), NULL, this );
	find_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::find_BOnClick ), NULL, this );
	findUndo_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findUndo_BOnClick ), NULL, this );
	findEqual_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findEqual_BOnClick ), NULL, this );
	findGTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findGTE_BOnClick ), NULL, this );
	findGT_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findGT_BOnClick ), NULL, this );
	findNOTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findNOTE_BOnClick ), NULL, this );
	findLTE_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findLTE_BOnClick ), NULL, this );
	findLT_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::findLT_BOnClick ), NULL, this );
	findUse_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::compare_DOnChoice ), NULL, this );
	findMode_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::findMode_DOnChoice ), NULL, this );
	outData_LC->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cleanFRM::outData_LCOnSelect ), NULL, this );
	outByte_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	outValue_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::out_TXTOnChange ), NULL, this );
	SetOut_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetOut_BOnClick ), NULL, this );
	DelOut_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::DelOut_BOnClick ), NULL, this );
	editShow_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editShow_BOnClick ), NULL, this );
	editUpdate_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanFRM::editUpdate_DOnChoice ), NULL, this );
	editGet_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editGet_BOnClick ), NULL, this );
	editGet_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	editSet_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::editSet_BOnClick ), NULL, this );
	editSet_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte_TXTOnChange ), NULL, this );
	editValue_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::edit_TXTOnChange ), NULL, this );
	edit_G->Disconnect( wxEVT_GRID_CELL_CHANGE, wxGridEventHandler( cleanFRM::edit_GOnEditEnd ), NULL, this );
	edit_G->Disconnect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( cleanFRM::edit_GOnEditBegin ), NULL, this );
	edit_G->Disconnect( wxEVT_GRID_SELECT_CELL, wxGridEventHandler( cleanFRM::edit_GOnSelect ), NULL, this );
	edit_G->Disconnect( wxEVT_MOUSEWHEEL, wxMouseEventHandler( cleanFRM::edit_GOnMouseWheel ), NULL, this );
	dbpAreaAll_RB->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanFRM::dbpArea_RBOnChange ), NULL, this );
	dbpAreaCheck_RB->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanFRM::dbpArea_RBOnChange ), NULL, this );
	dbpName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	dbpFile_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::file_TXTOnChange ), NULL, this );
	dbpPID_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::byte16_TXTOnChange ), NULL, this );
	NewDBP_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewDBP_BOnClick ), NULL, this );
	SetDBP_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetDBP_BOnClick ), NULL, this );
	LoadDBP_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::LoadDBP_BOnClick ), NULL, this );
	SaveDBP_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SaveDBP_BOnClick ), NULL, this );
	NewHack_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::NewHack_BOnClick ), NULL, this );
	SetCode_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetCode_BOnClick ), NULL, this );
	DelHack_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::DelHack_BOnClick ), NULL, this );
	tree_T->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( cleanFRM::tree_TOnKeyDown ), NULL, this );
	tree_T->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( cleanFRM::tree_TOnKeyUp ), NULL, this );
	tree_T->Disconnect( wxEVT_COMMAND_TREE_BEGIN_DRAG, wxTreeEventHandler( cleanFRM::tree_TOnBeginDrag ), NULL, this );
	tree_T->Disconnect( wxEVT_COMMAND_TREE_END_DRAG, wxTreeEventHandler( cleanFRM::tree_TOnEndDrag ), NULL, this );
	tree_T->Disconnect( wxEVT_COMMAND_TREE_SEL_CHANGED, wxTreeEventHandler( cleanFRM::tree_TOnSelect ), NULL, this );
	mHackName_TXT->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( cleanFRM::name_TXTOnChange ), NULL, this );
	mUseHack_CB->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( cleanFRM::UseHack_BOnClick ), NULL, this );
	mShowHack_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::mShowHack_OnClick ), NULL, this );
	GetHacks_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::GetHacks_BOnClick ), NULL, this );
	SetHacks_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::SetHacks_BOnClick ), NULL, this );
	MoveHack_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanFRM::MoveHack_BOnClick ), NULL, this );
	
}

cleanGetOrg_DLG::cleanGetOrg_DLG( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	bSizer22->SetMinSize( wxSize( 480,460 ) ); 
	dGetOrg_TBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	dGetOrg_TBar->AddTool( dUseOrg_ID, _("&Close"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddTool( dLoadOrg_ID, _("&Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddTool( dSaveOrg_ID, _("&Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddSeparator(); 
	
	dGetOrg_TBar->AddTool( dNewOrg_ID, _("&New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddTool( dSetOrg_ID, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddTool( dGetOrg_ID, _("Reset"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->AddTool( dDelOrg_ID, _("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetOrg_TBar->Realize(); 
	
	bSizer22->Add( dGetOrg_TBar, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );
	
	dOrgName_LB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	bSizer23->Add( dOrgName_LB, 0, wxALL|wxEXPAND, 5 );
	
	dSetOrgData_P = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* dSetOrgData_L;
	dSetOrgData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dSetOrgData_L->AddGrowableCol( 1 );
	dSetOrgData_L->SetFlexibleDirection( wxBOTH );
	dSetOrgData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dSetOrgName_S = new wxStaticText( dSetOrgData_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetOrgName_S->Wrap( -1 );
	dSetOrgData_L->Add( dSetOrgName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dSetOrgName_TXT = new wxTextCtrl( dSetOrgData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetOrgData_L->Add( dSetOrgName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dSetOrgFile_S = new wxStaticText( dSetOrgData_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetOrgFile_S->Wrap( -1 );
	dSetOrgData_L->Add( dSetOrgFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dSetOrgFile_TXT = new wxTextCtrl( dSetOrgData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetOrgData_L->Add( dSetOrgFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dSetOrgData_P->SetSizer( dSetOrgData_L );
	dSetOrgData_P->Layout();
	dSetOrgData_L->Fit( dSetOrgData_P );
	bSizer23->Add( dSetOrgData_P, 1, wxEXPAND, 5 );
	
	bSizer22->Add( bSizer23, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer22 );
	this->Layout();
	bSizer22->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetOrg_DLG::GetOrg_DLGOnClose ) );
	this->Connect( dUseOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dUseOrg_OnClick ) );
	this->Connect( dLoadOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dLoadOrg_OnClick ) );
	this->Connect( dSaveOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dSaveOrg_OnClick ) );
	this->Connect( dNewOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dNewOrg_OnClick ) );
	this->Connect( dSetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dSetOrg_OnClick ) );
	this->Connect( dGetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dGetOrg_OnClick ) );
	this->Connect( dDelOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dDelOrg_OnClick ) );
	dOrgName_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetOrg_DLG::dOrgName_LBOnSelect ), NULL, this );
}

cleanGetOrg_DLG::~cleanGetOrg_DLG()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetOrg_DLG::GetOrg_DLGOnClose ) );
	this->Disconnect( dUseOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dUseOrg_OnClick ) );
	this->Disconnect( dLoadOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dLoadOrg_OnClick ) );
	this->Disconnect( dSaveOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dSaveOrg_OnClick ) );
	this->Disconnect( dNewOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dNewOrg_OnClick ) );
	this->Disconnect( dSetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dSetOrg_OnClick ) );
	this->Disconnect( dGetOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dGetOrg_OnClick ) );
	this->Disconnect( dDelOrg_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetOrg_DLG::dDelOrg_OnClick ) );
	dOrgName_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetOrg_DLG::dOrgName_LBOnSelect ), NULL, this );
	
}

cleanGetPFM_DLG::cleanGetPFM_DLG( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 480,480 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );
	
	dGetPFM_TBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	dGetPFM_TBar->AddTool( dUsePFM_ID, _("&Close"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddTool( dLoadPFM_ID, _("&Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddTool( dSavePFM_ID, _("&Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddSeparator(); 
	
	dGetPFM_TBar->AddTool( dNewPFM_ID, _("&New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddTool( dSetPFM_ID, _("&Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddTool( dGetPFM_ID, _("&Reset"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->AddTool( dDelPFM_ID, _("&Delete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetPFM_TBar->Realize(); 
	
	bSizer25->Add( dGetPFM_TBar, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	dPFMName_LB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	bSizer27->Add( dPFMName_LB, 0, wxALL|wxEXPAND, 5 );
	
	dSetPFMData_P = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* dSetPFMData_L;
	dSetPFMData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dSetPFMData_L->AddGrowableCol( 1 );
	dSetPFMData_L->SetFlexibleDirection( wxBOTH );
	dSetPFMData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dSetPFMName_S = new wxStaticText( dSetPFMData_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetPFMName_S->Wrap( -1 );
	dSetPFMData_L->Add( dSetPFMName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dSetPFMName_TXT = new wxTextCtrl( dSetPFMData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetPFMData_L->Add( dSetPFMName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dSetPFMFile_S = new wxStaticText( dSetPFMData_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetPFMFile_S->Wrap( -1 );
	dSetPFMData_L->Add( dSetPFMFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dSetPFMFile_TXT = new wxTextCtrl( dSetPFMData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetPFMData_L->Add( dSetPFMFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dSetPFMEndian_S = new wxStaticText( dSetPFMData_P, wxID_ANY, _("Endian"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetPFMEndian_S->Wrap( -1 );
	dSetPFMData_L->Add( dSetPFMEndian_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxString dSetPFMEndian_DChoices[] = { _("Little"), _("Big"), _("Little Big") };
	int dSetPFMEndian_DNChoices = sizeof( dSetPFMEndian_DChoices ) / sizeof( wxString );
	dSetPFMEndian_D = new wxChoice( dSetPFMData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, dSetPFMEndian_DNChoices, dSetPFMEndian_DChoices, 0 );
	dSetPFMEndian_D->SetSelection( 0 );
	dSetPFMData_L->Add( dSetPFMEndian_D, 0, wxALL|wxEXPAND, 5 );
	
	dSetPFMData_P->SetSizer( dSetPFMData_L );
	dSetPFMData_P->Layout();
	dSetPFMData_L->Fit( dSetPFMData_P );
	bSizer27->Add( dSetPFMData_P, 1, wxEXPAND, 5 );
	
	bSizer25->Add( bSizer27, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetPFM_DLG::GetPFM_DLGOnClose ) );
	this->Connect( dUsePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dUsePFM_OnClick ) );
	this->Connect( dLoadPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dLoadPFM_OnClick ) );
	this->Connect( dSavePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dSavePFM_OnClick ) );
	this->Connect( dNewPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dNewPFM_OnClick ) );
	this->Connect( dSetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dSetPFM_OnClick ) );
	this->Connect( dGetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dGetPFM_OnClick ) );
	this->Connect( dDelPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dDelPFM_OnClick ) );
	dPFMName_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetPFM_DLG::dPFMName_LBOnSelect ), NULL, this );
}

cleanGetPFM_DLG::~cleanGetPFM_DLG()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetPFM_DLG::GetPFM_DLGOnClose ) );
	this->Disconnect( dUsePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dUsePFM_OnClick ) );
	this->Disconnect( dLoadPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dLoadPFM_OnClick ) );
	this->Disconnect( dSavePFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dSavePFM_OnClick ) );
	this->Disconnect( dNewPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dNewPFM_OnClick ) );
	this->Disconnect( dSetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dSetPFM_OnClick ) );
	this->Disconnect( dGetPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dGetPFM_OnClick ) );
	this->Disconnect( dDelPFM_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetPFM_DLG::dDelPFM_OnClick ) );
	dPFMName_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetPFM_DLG::dPFMName_LBOnSelect ), NULL, this );
	
}

cleanGetBin_DLG::cleanGetBin_DLG( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxVERTICAL );
	
	bSizer34->SetMinSize( wxSize( 480,460 ) ); 
	dGetBin_TBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	dGetBin_TBar->AddTool( dUseBin_ID, _("&Close"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddTool( dLoadBin_ID, _("&Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddTool( dSaveBin_ID, _("&Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddSeparator(); 
	
	dGetBin_TBar->AddTool( dNewBin_ID, _("&New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddTool( dSetBin_ID, _("&Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddTool( dGetBin_ID, _("&Reset"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->AddTool( dDelBin_ID, _("&Delete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetBin_TBar->Realize(); 
	
	bSizer34->Add( dGetBin_TBar, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	dBinName_LB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	bSizer35->Add( dBinName_LB, 0, wxALL|wxEXPAND, 5 );
	
	dSetBinData_P = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxFlexGridSizer* dSetBinData_L;
	dSetBinData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dSetBinData_L->AddGrowableCol( 1 );
	dSetBinData_L->SetFlexibleDirection( wxBOTH );
	dSetBinData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dBinName_S = new wxStaticText( dSetBinData_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	dBinName_S->Wrap( -1 );
	dSetBinData_L->Add( dBinName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dBinName_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetBinData_L->Add( dBinName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dBinFile_S = new wxStaticText( dSetBinData_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dBinFile_S->Wrap( -1 );
	dSetBinData_L->Add( dBinFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dBinFile_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetBinData_L->Add( dBinFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dBinPath_B = new wxButton( dSetBinData_P, wxID_ANY, _("Path"), wxDefaultPosition, wxDefaultSize, 0 );
	dBinPath_B->SetMinSize( wxSize( 50,-1 ) );
	
	dSetBinData_L->Add( dBinPath_B, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	dBinPath_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetBinData_L->Add( dBinPath_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dBinBind_B = new wxButton( dSetBinData_P, wxID_ANY, _("Bind"), wxDefaultPosition, wxDefaultSize, 0 );
	dBinBind_B->SetMinSize( wxSize( 50,-1 ) );
	
	dSetBinData_L->Add( dBinBind_B, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	dBinBind_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dSetBinData_L->Add( dBinBind_TXT, 0, wxALL|wxEXPAND, 5 );
	
	bSizer9->Add( dSetBinData_L, 0, wxEXPAND, 5 );
	
	wxGridSizer* dBinType_LG;
	dBinType_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	dIsApp_RB = new wxRadioButton( dSetBinData_P, wxID_ANY, _("Application"), wxDefaultPosition, wxDefaultSize, 0 );
	dIsApp_RB->SetValue( true ); 
	dBinType_LG->Add( dIsApp_RB, 0, wxALIGN_RIGHT|wxALL, 5 );
	
	dIsFile_RB = new wxRadioButton( dSetBinData_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dIsFile_RB->Enable( false );
	
	dBinType_LG->Add( dIsFile_RB, 0, wxALL, 5 );
	
	bSizer9->Add( dBinType_LG, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* dRam_LF;
	dRam_LF = new wxStaticBoxSizer( new wxStaticBox( dSetBinData_P, wxID_ANY, _("Memory") ), wxVERTICAL );
	
	wxStaticBoxSizer* dRamName_LF;
	dRamName_LF = new wxStaticBoxSizer( new wxStaticBox( dSetBinData_P, wxID_ANY, _("Name") ), wxVERTICAL );
	
	wxArrayString dRamName_DChoices;
	dRamName_D = new wxChoice( dSetBinData_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, dRamName_DChoices, 0 );
	dRamName_D->SetSelection( 0 );
	dRamName_LF->Add( dRamName_D, 0, wxALL|wxEXPAND, 5 );
	
	dRamName_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dRamName_LF->Add( dRamName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dRam_LF->Add( dRamName_LF, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* dRamData_L;
	dRamData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dRamData_L->AddGrowableCol( 1 );
	dRamData_L->SetFlexibleDirection( wxBOTH );
	dRamData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dRamDepth_S = new wxStaticText( dSetBinData_P, wxID_ANY, _("Pointer Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	dRamDepth_S->Wrap( -1 );
	dRamData_L->Add( dRamDepth_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dRamDepth_SL = new wxSlider( dSetBinData_P, wxID_ANY, 0, 0, 15, wxDefaultPosition, wxDefaultSize, wxSL_AUTOTICKS|wxSL_HORIZONTAL|wxSL_LABELS );
	dRamData_L->Add( dRamDepth_SL, 0, wxALL|wxEXPAND, 5 );
	
	dRamBase_S = new wxStaticText( dSetBinData_P, wxID_ANY, _("Base Address"), wxDefaultPosition, wxDefaultSize, 0 );
	dRamBase_S->Wrap( -1 );
	dRamData_L->Add( dRamBase_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dRamBase_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dRamData_L->Add( dRamBase_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dRamSize_S = new wxStaticText( dSetBinData_P, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	dRamSize_S->Wrap( -1 );
	dRamData_L->Add( dRamSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dRamSize_TXT = new wxTextCtrl( dSetBinData_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dRamData_L->Add( dRamSize_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dRam_LF->Add( dRamData_L, 1, wxEXPAND, 5 );
	
	wxGridSizer* dSetRam_LG;
	dSetRam_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	dNewRam_B = new wxButton( dSetBinData_P, wxID_ANY, _("New"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetRam_LG->Add( dNewRam_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	dSetRam_B = new wxButton( dSetBinData_P, wxID_ANY, _("Update"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetRam_LG->Add( dSetRam_B, 0, wxALIGN_CENTER|wxALL, 5 );
	
	dRam_LF->Add( dSetRam_LG, 0, wxEXPAND, 5 );
	
	bSizer9->Add( dRam_LF, 1, wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );
	
	dSetBinData_P->SetSizer( bSizer9 );
	dSetBinData_P->Layout();
	bSizer9->Fit( dSetBinData_P );
	bSizer35->Add( dSetBinData_P, 1, wxEXPAND, 5 );
	
	bSizer34->Add( bSizer35, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer34 );
	this->Layout();
	bSizer34->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetBin_DLG::GetBin_DLGOnClose ) );
	this->Connect( dUseBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dUseBin_OnClick ) );
	this->Connect( dLoadBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dLoadBin_OnClick ) );
	this->Connect( dSaveBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSaveBin_OnClick ) );
	this->Connect( dNewBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dNewBin_OnClick ) );
	this->Connect( dSetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSetBin_OnClick ) );
	this->Connect( dGetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dGetBin_OnClick ) );
	this->Connect( dDelBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dDelBin_OnClick ) );
	dBinName_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetBin_DLG::dOrgName_LBOnSelect ), NULL, this );
	dBinPath_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dBinPath_BOnClick ), NULL, this );
	dBinBind_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dBinBind_BOnClick ), NULL, this );
	dRamName_D->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanGetBin_DLG::dRanName_DOnSelect ), NULL, this );
	dNewRam_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dNewRam_BOnClick ), NULL, this );
	dSetRam_B->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSetRam_BOnClick ), NULL, this );
}

cleanGetBin_DLG::~cleanGetBin_DLG()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetBin_DLG::GetBin_DLGOnClose ) );
	this->Disconnect( dUseBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dUseBin_OnClick ) );
	this->Disconnect( dLoadBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dLoadBin_OnClick ) );
	this->Disconnect( dSaveBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSaveBin_OnClick ) );
	this->Disconnect( dNewBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dNewBin_OnClick ) );
	this->Disconnect( dSetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSetBin_OnClick ) );
	this->Disconnect( dGetBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dGetBin_OnClick ) );
	this->Disconnect( dDelBin_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dDelBin_OnClick ) );
	dBinName_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetBin_DLG::dOrgName_LBOnSelect ), NULL, this );
	dBinPath_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dBinPath_BOnClick ), NULL, this );
	dBinBind_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dBinBind_BOnClick ), NULL, this );
	dRamName_D->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( cleanGetBin_DLG::dRanName_DOnSelect ), NULL, this );
	dNewRam_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dNewRam_BOnClick ), NULL, this );
	dSetRam_B->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( cleanGetBin_DLG::dSetRam_BOnClick ), NULL, this );
	
}

cleanGetDBP_DLG::cleanGetDBP_DLG( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxVERTICAL );
	
	bSizer29->SetMinSize( wxSize( 480,460 ) ); 
	dGetDBP_TBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NODIVIDER|wxTB_NOICONS ); 
	dGetDBP_TBar->AddTool( dUseDBP_ID, _("Use"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddTool( dLoadDBP_ID, _("Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddTool( dSaveDBP_ID, _("Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddSeparator(); 
	
	dGetDBP_TBar->AddTool( dNewDBP_ID, _("New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddTool( dSetDBP_ID, _("Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddTool( dGetDBP_ID, _("Reset"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->AddTool( dDelDBP_ID, _("Delete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dGetDBP_TBar->Realize(); 
	
	bSizer29->Add( dGetDBP_TBar, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* dGetArea_LF;
	dGetArea_LF = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Region") ), wxVERTICAL );
	
	wxGridSizer* dGetAreaRB_LG;
	dGetAreaRB_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	dGetAreaAll_RB = new wxRadioButton( this, wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	dGetAreaRB_LG->Add( dGetAreaAll_RB, 0, wxALL, 5 );
	
	dGetAreaSel_RB = new wxRadioButton( this, wxID_ANY, _("Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	dGetAreaSel_RB->SetValue( true ); 
	dGetAreaRB_LG->Add( dGetAreaSel_RB, 0, wxALL, 5 );
	
	dGetArea_LF->Add( dGetAreaRB_LG, 0, wxEXPAND, 5 );
	
	dGetAreaCB_P = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	dGetAreaCB_LG = new wxGridSizer( 0, 3, 0, 0 );
	
	dGetAreaCB_P->SetSizer( dGetAreaCB_LG );
	dGetAreaCB_P->Layout();
	dGetAreaCB_LG->Fit( dGetAreaCB_P );
	dGetArea_LF->Add( dGetAreaCB_P, 0, wxEXPAND, 5 );
	
	bSizer31->Add( dGetArea_LF, 0, wxALL|wxEXPAND, 5 );
	
	dDBPName_LB = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE|wxLB_SORT ); 
	dDBPName_LB->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer31->Add( dDBPName_LB, 1, wxALL|wxEXPAND, 5 );
	
	bSizer30->Add( bSizer31, 1, wxEXPAND, 5 );
	
	dSetDBP_P = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* dSetDBP_LV;
	dSetDBP_LV = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* dSetArea_LF;
	dSetArea_LF = new wxStaticBoxSizer( new wxStaticBox( dSetDBP_P, wxID_ANY, _("Region") ), wxVERTICAL );
	
	wxGridSizer* dSetAreaRB_LG;
	dSetAreaRB_LG = new wxGridSizer( 0, 2, 0, 0 );
	
	dSetAreaAll_RB = new wxRadioButton( dSetDBP_P, wxID_ANY, _("All"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetAreaRB_LG->Add( dSetAreaAll_RB, 0, wxALL, 5 );
	
	dSetAreaSel_RB = new wxRadioButton( dSetDBP_P, wxID_ANY, _("Selected"), wxDefaultPosition, wxDefaultSize, 0 );
	dSetAreaSel_RB->SetValue( true ); 
	dSetAreaRB_LG->Add( dSetAreaSel_RB, 0, wxALL, 5 );
	
	dSetArea_LF->Add( dSetAreaRB_LG, 0, wxEXPAND, 5 );
	
	dSetAreaCB_P = new wxPanel( dSetDBP_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	dSetAreaCB_LG = new wxGridSizer( 0, 4, 0, 0 );
	
	dSetAreaCB_P->SetSizer( dSetAreaCB_LG );
	dSetAreaCB_P->Layout();
	dSetAreaCB_LG->Fit( dSetAreaCB_P );
	dSetArea_LF->Add( dSetAreaCB_P, 0, wxEXPAND, 5 );
	
	dSetDBP_LV->Add( dSetArea_LF, 0, wxEXPAND, 5 );
	
	wxFlexGridSizer* dDBPData_L;
	dDBPData_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dDBPData_L->AddGrowableCol( 1 );
	dDBPData_L->SetFlexibleDirection( wxBOTH );
	dDBPData_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dDBPName_S = new wxStaticText( dSetDBP_P, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	dDBPName_S->Wrap( -1 );
	dDBPData_L->Add( dDBPName_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dDBPName_TXT = new wxTextCtrl( dSetDBP_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dDBPData_L->Add( dDBPName_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dDBPFile_S = new wxStaticText( dSetDBP_P, wxID_ANY, _("File"), wxDefaultPosition, wxDefaultSize, 0 );
	dDBPFile_S->Wrap( -1 );
	dDBPData_L->Add( dDBPFile_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dDBPFile_TXT = new wxTextCtrl( dSetDBP_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dDBPData_L->Add( dDBPFile_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dDBPPID_S = new wxStaticText( dSetDBP_P, wxID_ANY, _("Profile ID"), wxDefaultPosition, wxDefaultSize, 0 );
	dDBPPID_S->Wrap( -1 );
	dDBPData_L->Add( dDBPPID_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dDBPPID_TXT = new wxTextCtrl( dSetDBP_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dDBPData_L->Add( dDBPPID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dDBPSID_S = new wxStaticText( dSetDBP_P, wxID_ANY, _("Serial ID"), wxDefaultPosition, wxDefaultSize, 0 );
	dDBPSID_S->Wrap( -1 );
	dDBPData_L->Add( dDBPSID_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dDBPSID_TXT = new wxTextCtrl( dSetDBP_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dDBPData_L->Add( dDBPSID_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dSetDBP_LV->Add( dDBPData_L, 0, wxEXPAND, 5 );
	
	dDBPNotes_S = new wxStaticText( dSetDBP_P, wxID_ANY, _("Notes"), wxDefaultPosition, wxDefaultSize, 0 );
	dDBPNotes_S->Wrap( -1 );
	dSetDBP_LV->Add( dDBPNotes_S, 0, wxALL, 5 );
	
	dDBPNotes_TA = new wxTextCtrl( dSetDBP_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_LEFT|wxTE_MULTILINE|wxTE_PROCESS_TAB );
	dSetDBP_LV->Add( dDBPNotes_TA, 1, wxEXPAND, 5 );
	
	dSetDBP_P->SetSizer( dSetDBP_LV );
	dSetDBP_P->Layout();
	dSetDBP_LV->Fit( dSetDBP_P );
	bSizer30->Add( dSetDBP_P, 1, wxEXPAND | wxALL, 5 );
	
	bSizer29->Add( bSizer30, 1, wxEXPAND, 5 );
	
	this->SetSizer( bSizer29 );
	this->Layout();
	bSizer29->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetDBP_DLG::GetDBP_DLGOnClose ) );
	this->Connect( dUseDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dUseDBP_OnClick ) );
	this->Connect( dLoadDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dLoadDBP_OnClick ) );
	this->Connect( dSaveDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dSaveDBP_OnClick ) );
	this->Connect( dNewDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dNewDBP_OnClick ) );
	this->Connect( dSetDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dSetDBP_OnClick ) );
	this->Connect( dGetDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dGetDBP_OnClick ) );
	this->Connect( dDelDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dDelDBP_OnClick ) );
	dDBPName_LB->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dDBPName_LBOnSelect ), NULL, this );
	dSetAreaAll_RB->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dSetArea_RBOnClick ), NULL, this );
	dSetAreaSel_RB->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dSetArea_RBOnClick ), NULL, this );
}

cleanGetDBP_DLG::~cleanGetDBP_DLG()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( cleanGetDBP_DLG::GetDBP_DLGOnClose ) );
	this->Disconnect( dUseDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dUseDBP_OnClick ) );
	this->Disconnect( dLoadDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dLoadDBP_OnClick ) );
	this->Disconnect( dSaveDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dSaveDBP_OnClick ) );
	this->Disconnect( dNewDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dNewDBP_OnClick ) );
	this->Disconnect( dSetDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dSetDBP_OnClick ) );
	this->Disconnect( dGetDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dGetDBP_OnClick ) );
	this->Disconnect( dDelDBP_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanGetDBP_DLG::dDelDBP_OnClick ) );
	dDBPName_LB->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dDBPName_LBOnSelect ), NULL, this );
	dSetAreaAll_RB->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dSetArea_RBOnClick ), NULL, this );
	dSetAreaSel_RB->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( cleanGetDBP_DLG::dSetArea_RBOnClick ), NULL, this );
	
}

cleanSetHack_DLG::cleanSetHack_DLG( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	this->SetExtraStyle( wxWS_EX_BLOCK_EVENTS );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* dSetHack_LV;
	dSetHack_LV = new wxBoxSizer( wxVERTICAL );
	
	dSetHack_LV->SetMinSize( wxSize( 480,460 ) ); 
	dSetHack_TBar = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORZ_TEXT|wxTB_NOICONS ); 
	dSetHack_TBar->AddTool( dSetHack_ID, _("&Close"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddTool( dLoadHack_ID, _("&Load"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddTool( dSaveHack_ID, _("&Save"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddSeparator(); 
	
	dSetHack_TBar->AddTool( dNewCode_ID, _("&New"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddTool( dSetCode_ID, _("&Update"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddTool( dGetCode_Tool, _("&Reset"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->AddTool( dDelCode_ID, _("&Delete"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString, NULL ); 
	
	dSetHack_TBar->Realize(); 
	
	dSetHack_LV->Add( dSetHack_TBar, 0, wxEXPAND, 5 );
	
	wxBoxSizer* dSetHack_LH;
	dSetHack_LH = new wxBoxSizer( wxHORIZONTAL );
	
	m_scrolledWindow5 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), wxHSCROLL|wxVSCROLL );
	m_scrolledWindow5->SetScrollRate( 0, 5 );
	m_scrolledWindow5->SetMinSize( wxSize( 200,-1 ) );
	
	wxBoxSizer* dSetCode_LV;
	dSetCode_LV = new wxBoxSizer( wxVERTICAL );
	
	dSetCode_LV->SetMinSize( wxSize( 200,-1 ) ); 
	wxFlexGridSizer* dSetHead_L;
	dSetHead_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dSetHead_L->AddGrowableCol( 1 );
	dSetHead_L->SetFlexibleDirection( wxBOTH );
	dSetHead_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dCodeType_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Type"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeType_S->Wrap( -1 );
	dSetHead_L->Add( dCodeType_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString dCodeType_DChoices;
	dCodeType_D = new wxChoice( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeType_DChoices, 0 );
	dCodeType_D->SetSelection( 0 );
	dCodeType_D->SetMinSize( wxSize( 50,-1 ) );
	
	dSetHead_L->Add( dCodeType_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeSize_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Size"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeSize_S->Wrap( -1 );
	dSetHead_L->Add( dCodeSize_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString dCodeSize_DChoices;
	dCodeSize_D = new wxChoice( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeSize_DChoices, 0 );
	dCodeSize_D->SetSelection( 0 );
	dCodeSize_D->SetMinSize( wxSize( 50,-1 ) );
	
	dSetHead_L->Add( dCodeSize_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeRam_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Memory"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeRam_S->Wrap( -1 );
	dSetHead_L->Add( dCodeRam_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString dCodeRam_DChoices;
	dCodeRam_D = new wxChoice( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeRam_DChoices, 0 );
	dCodeRam_D->SetSelection( 0 );
	dCodeRam_D->SetMinSize( wxSize( 50,-1 ) );
	
	dSetHead_L->Add( dCodeRam_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeLoop_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Loop"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeLoop_S->Wrap( -1 );
	dSetHead_L->Add( dCodeLoop_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dCodeLoop_SN = new wxSpinCtrl( m_scrolledWindow5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 255, 0 );
	dCodeLoop_SN->SetMinSize( wxSize( 50,-1 ) );
	
	dSetHead_L->Add( dCodeLoop_SN, 0, wxALL|wxEXPAND, 5 );
	
	dSetCode_LV->Add( dSetHead_L, 0, wxEXPAND, 5 );
	
	wxStaticBoxSizer* dSetByte_LF;
	dSetByte_LF = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow5, wxID_ANY, _("Address") ), wxVERTICAL );
	
	dCodeByte_TXT = new wxTextCtrl( m_scrolledWindow5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dCodeByte_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	dSetByte_LF->Add( dCodeByte_TXT, 0, wxALL|wxEXPAND, 5 );
	
	wxFlexGridSizer* dCodePtr_L;
	dCodePtr_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dCodePtr_L->AddGrowableCol( 1 );
	dCodePtr_L->SetFlexibleDirection( wxBOTH );
	dCodePtr_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dCodePtr_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Pointer Depth"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodePtr_S->Wrap( -1 );
	dCodePtr_L->Add( dCodePtr_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dCodePtr_SN = new wxSpinCtrl( m_scrolledWindow5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 15, 0 );
	dCodePtr_SN->SetMinSize( wxSize( 50,-1 ) );
	
	dCodePtr_L->Add( dCodePtr_SN, 0, wxALL|wxEXPAND, 5 );
	
	dSetByte_LF->Add( dCodePtr_L, 1, wxEXPAND, 5 );
	
	dCodeInc_P = new wxPanel( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* dCodeInc_L;
	dCodeInc_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dCodeInc_L->AddGrowableCol( 1 );
	dCodeInc_L->SetFlexibleDirection( wxBOTH );
	dCodeInc_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dCodeInc_S = new wxStaticText( dCodeInc_P, wxID_ANY, _("Increment"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeInc_S->Wrap( -1 );
	dCodeInc_L->Add( dCodeInc_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dCodeInc_TXT = new wxTextCtrl( dCodeInc_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dCodeInc_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeInc_L->Add( dCodeInc_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dCodeInc_P->SetSizer( dCodeInc_L );
	dCodeInc_P->Layout();
	dCodeInc_L->Fit( dCodeInc_P );
	dSetByte_LF->Add( dCodeInc_P, 0, wxEXPAND, 5 );
	
	dSetCode_LV->Add( dSetByte_LF, 0, wxALL|wxEXPAND, 5 );
	
	wxStaticBoxSizer* dCodeValue_LF;
	dCodeValue_LF = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow5, wxID_ANY, _("Value") ), wxVERTICAL );
	
	wxFlexGridSizer* dCodeMode_L;
	dCodeMode_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dCodeMode_L->AddGrowableCol( 1 );
	dCodeMode_L->SetFlexibleDirection( wxBOTH );
	dCodeMode_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dCodeMode_S = new wxStaticText( m_scrolledWindow5, wxID_ANY, _("Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeMode_S->Wrap( -1 );
	dCodeMode_L->Add( dCodeMode_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	wxArrayString dCodeMode_DChoices;
	dCodeMode_D = new wxChoice( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeMode_DChoices, 0 );
	dCodeMode_D->SetSelection( 0 );
	dCodeMode_D->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeMode_L->Add( dCodeMode_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeValue_LF->Add( dCodeMode_L, 0, wxEXPAND, 5 );
	
	dCodeValue_TXT = new wxTextCtrl( m_scrolledWindow5, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dCodeValue_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeValue_LF->Add( dCodeValue_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dCodeSum_P = new wxPanel( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* dCodeSum_L;
	dCodeSum_L = new wxFlexGridSizer( 0, 2, 0, 0 );
	dCodeSum_L->AddGrowableCol( 1 );
	dCodeSum_L->SetFlexibleDirection( wxBOTH );
	dCodeSum_L->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	dCodeSum_S = new wxStaticText( dCodeSum_P, wxID_ANY, _("Increment"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeSum_S->Wrap( -1 );
	dCodeSum_L->Add( dCodeSum_S, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	dCodeSum_TXT = new wxTextCtrl( dCodeSum_P, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	dCodeSum_TXT->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeSum_L->Add( dCodeSum_TXT, 0, wxALL|wxEXPAND, 5 );
	
	dCodeSum_P->SetSizer( dCodeSum_L );
	dCodeSum_P->Layout();
	dCodeSum_L->Fit( dCodeSum_P );
	dCodeValue_LF->Add( dCodeSum_P, 0, wxEXPAND, 5 );
	
	dSetCode_LV->Add( dCodeValue_LF, 0, wxALL|wxEXPAND, 5 );
	
	dCodeTest_P = new wxPanel( m_scrolledWindow5, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* dCodeTest_LF;
	dCodeTest_LF = new wxStaticBoxSizer( new wxStaticBox( dCodeTest_P, wxID_ANY, _("Test") ), wxVERTICAL );
	
	dCodeTest_S = new wxStaticText( dCodeTest_P, wxID_ANY, _("If value at address is"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeTest_S->Wrap( -1 );
	dCodeTest_LF->Add( dCodeTest_S, 0, wxALL, 5 );
	
	wxArrayString dCodeTest_DChoices;
	dCodeTest_D = new wxChoice( dCodeTest_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeTest_DChoices, 0 );
	dCodeTest_D->SetSelection( 0 );
	dCodeTest_D->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeTest_LF->Add( dCodeTest_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeTestThen_S = new wxStaticText( dCodeTest_P, wxID_ANY, _("Then do"), wxDefaultPosition, wxDefaultSize, 0 );
	dCodeTestThen_S->Wrap( -1 );
	dCodeTest_LF->Add( dCodeTestThen_S, 0, wxALL, 5 );
	
	wxString dCodeTestThen_DChoices[] = { _("Next Code"), _("Next 2 Codes"), _("Next [LOOP] Codes"), _("No more Codes of Test / Hack") };
	int dCodeTestThen_DNChoices = sizeof( dCodeTestThen_DChoices ) / sizeof( wxString );
	dCodeTestThen_D = new wxChoice( dCodeTest_P, wxID_ANY, wxDefaultPosition, wxDefaultSize, dCodeTestThen_DNChoices, dCodeTestThen_DChoices, 0 );
	dCodeTestThen_D->SetSelection( 0 );
	dCodeTestThen_D->SetMinSize( wxSize( 50,-1 ) );
	
	dCodeTest_LF->Add( dCodeTestThen_D, 0, wxALL|wxEXPAND, 5 );
	
	dCodeTest_P->SetSizer( dCodeTest_LF );
	dCodeTest_P->Layout();
	dCodeTest_LF->Fit( dCodeTest_P );
	dSetCode_LV->Add( dCodeTest_P, 0, wxALL|wxEXPAND, 5 );
	
	m_scrolledWindow5->SetSizer( dSetCode_LV );
	m_scrolledWindow5->Layout();
	dSetHack_LH->Add( m_scrolledWindow5, 0, wxEXPAND, 5 );
	
	dCode_LC = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_ICON|wxLC_REPORT|wxLC_SINGLE_SEL );
	dSetHack_LH->Add( dCode_LC, 1, wxALL|wxEXPAND, 5 );
	
	dSetHack_LV->Add( dSetHack_LH, 1, wxEXPAND, 5 );
	
	this->SetSizer( dSetHack_LV );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( dSetHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSetHack_OnClick ) );
	this->Connect( dLoadHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dLoadHack_OnClick ) );
	this->Connect( dSaveHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSaveHack_OnClick ) );
	this->Connect( dNewCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dNewCode_OnClick ) );
	this->Connect( dSetCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSetCode_OnClick ) );
	this->Connect( dGetCode_Tool, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dGetCode_OnClick ) );
	this->Connect( dDelCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dDelCode_OnClick ) );
	dCode_LC->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cleanSetHack_DLG::dCode_LCOnSelect ), NULL, this );
}

cleanSetHack_DLG::~cleanSetHack_DLG()
{
	// Disconnect Events
	this->Disconnect( dSetHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSetHack_OnClick ) );
	this->Disconnect( dLoadHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dLoadHack_OnClick ) );
	this->Disconnect( dSaveHack_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSaveHack_OnClick ) );
	this->Disconnect( dNewCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dNewCode_OnClick ) );
	this->Disconnect( dSetCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dSetCode_OnClick ) );
	this->Disconnect( dGetCode_Tool, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dGetCode_OnClick ) );
	this->Disconnect( dDelCode_ID, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( cleanSetHack_DLG::dDelCode_OnClick ) );
	dCode_LC->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( cleanSetHack_DLG::dCode_LCOnSelect ), NULL, this );
	
}
